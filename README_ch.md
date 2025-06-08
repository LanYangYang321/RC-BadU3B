---

# RC-BadU3B

[🔗 English version (README.md)](https://github.com/LanYangYang321/RC-BadU3B/blob/main/README.md)

基于 ESP32 与 WCH 芯片的远程 BadUSB 项目。

[![Bilibili 粉丝](https://img.shields.io/badge/dynamic/json?color=blue\&label=BiliBili\&labelColor=white\&query=\$.data.follower\&url=https://api.bilibili.com/x/relation/stat?vmid=1084866085\&logo=bilibili\&style=flat-square)](https://space.bilibili.com/1084866085)
[![YouTube 频道](https://img.shields.io/badge/YouTube-white?logo=youtube\&logoColor=FF0000\&style=flat-square)](https://www.youtube.com/@lyyontop)
[![最新提交](https://img.shields.io/github/last-commit/LanYangYang321/RC-BadU3B?color=yellow\&logo=github\&label=Latest\&style=flat-square)](https://github.com/LanYangYang321/RC-BadU3B)

---

## ⚠️ 免责声明

本项目仅用于 **网络安全教育**、**技术研究** 与 **合法授权测试**。
所有代码、工具与演示仅供 **学习参考**，严禁用于未授权的实战入侵或设备控制。

* **法律风险**

  * 如将远程访问功能用于非法设备控制、信息窃取或数据破坏，即属违法。
  * 若任何用户擅自将本项目用于黑客攻击、散布恶意程序等非法行为，其产生的一切后果由其本人承担，作者概不负责。

---

## 🔍 复刻前必看

本仓库包含 **两个子项目**：

1. **遥控 BadUSB**

   * 由超小型 USB 接收器与 ESP32 通信组成的远程 HID 收发器。
   * 👉 详情请见 [RMTbadusb](https://github.com/LanYangYang321/RC-BadU3B/tree/main/RMTbadusb)

2. **本地 BadUSB**

   * 集成 SD 卡存储模块，可本地部署并执行自定义载荷。
   * 👉 详情请见 [localBadUSB](https://github.com/LanYangYang321/RC-BadU3B/tree/main/localBadUSB)

> **注意：** 复刻本项目需具备 **PCB 焊接** 技术，尤其是 QFN 封装芯片的焊接，对新手而言具有一定挑战。

---

## 🛠 硬件部分

* **参考资源：**

  * U 盘版 BadUSB（立创开源社区）：
    [https://oshwhub.com/Albireo/Upan-ban-BADUSB](https://oshwhub.com/Albireo/Upan-ban-BADUSB)
  * 超小 USB 转蓝牙接头：
    [https://oshwhub.com/lightandelectricity/bplug-ch](https://oshwhub.com/lightandelectricity/bplug-ch)

* **PCB 制板文件：**
  所有 Gerber 文件已上传至 [PCBGerber](https://github.com/LanYangYang321/RC-BadU3B/tree/main/PCBGerber)，可直接下载并打样。

---

## 💻 软件部分

* **开发环境：** Arduino IDE
* **项目结构：**

  * 两个子文件夹分别存放各自的 `.ino` 源码。
  * 远控木马部分基于作者开源项目 [tetrojan](https://github.com/LanYangYang321/tetrojan)。

> **使用方式：** 通过 Arduino IDE 将对应 `.ino` 烧录至 ESP32，即可启动相应功能。

---

## 🤝 交流与支持

如有任何疑问，欢迎加入 QQ 群：
**1006709313**

---

![主示意图](https://github.com/user-attachments/assets/5b41c8c0-5ea8-431e-9fa9-dd67ad85dcf0)
