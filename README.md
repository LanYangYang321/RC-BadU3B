Below is a fully English, polished version of your `README.md`, with an added link to the Chinese version:

---

# RC-BadU3B

[🔗 中文说明 (README\_ch.md)](https://github.com/LanYangYang321/RC-BadU3B/blob/main/README_ch.md)

A remote-controlled BadUSB project built around an ESP32 and a WCH USB-to-UART chip.

[![Bilibili Followers](https://img.shields.io/badge/dynamic/json?color=blue\&label=BiliBili\&labelColor=white\&query=\$.data.follower\&url=https://api.bilibili.com/x/relation/stat?vmid=1084866085\&logo=bilibili\&style=flat-square)](https://space.bilibili.com/1084866085)
[![YouTube Channel](https://img.shields.io/badge/YouTube-white?logo=youtube\&logoColor=FF0000\&style=flat-square)](https://www.youtube.com/@lyyontop)
[![Last Commit](https://img.shields.io/github/last-commit/LanYangYang321/RC-BadU3B?color=yellow\&logo=github&labelColor=black&label=Latest&style=flat-square)](https://github.com/LanYangYang321/RC-BadU3B)

---

## ⚠️ Disclaimer

This project is intended **solely** for cybersecurity education, technical research, and **authorized** testing.
All code, tools, and demonstrations here are for **learning purposes only**. Any unauthorized use—such as real-world intrusion or control of devices without consent—is **illegal**.

* **Legal Risks**

  * Remote access functionality used for illicit device control, data theft, or damage is unlawful.
  * Users who deploy this project for illegal activities (e.g., hacking systems, spreading malware) **bear full responsibility**; the author assumes **no liability** for misuse.

---

## 🔍 Before You Replicate

This repository contains **two subprojects**:

1. **Remote-Controlled BadUSB**

   * Consists of an ultra-compact USB receiver and an ESP32-based transmitter.
   * 👉 See [RMTbadusb](https://github.com/LanYangYang321/RC-BadU3B/tree/main/RMTbadusb) for details.

2. **Local BadUSB**

   * Features an SD-card module for storing and executing payloads locally.
   * 👉 See [localBadUSB](https://github.com/LanYangYang321/RC-BadU3B/tree/main/localBadUSB) for details.

> **Note:** Reproducing this project requires **PCB soldering expertise**, especially QFN-package soldering on the Remote-Controlled BadUSB—a challenging task for beginners.

---

## 🛠 Hardware

* **References:**

  * USB-stick-style BadUSB on the OSHWHub community:
    [https://oshwhub.com/Albireo/Upan-ban-BADUSB](https://oshwhub.com/Albireo/Upan-ban-BADUSB)
  * Ultra-small USB-to-Bluetooth adapter:
    [https://oshwhub.com/lightandelectricity/bplug-ch](https://oshwhub.com/lightandelectricity/bplug-ch)

* **PCB Files:**
  All Gerber files are in the [PCBGerber](https://github.com/LanYangYang321/RC-BadU3B/tree/main/PCBGerber) folder—ready for fabrication.

---

## 💻 Software

* **Development Environment:** Arduino IDE
* **Structure:**

  * Two folders, one per subproject.
  * The remote-trojan code leverages my own open-source RAT, [tetrojan](https://github.com/LanYangYang321/tetrojan).

> **Usage:** Simply flash the corresponding `.ino` file to your ESP32 via the Arduino IDE.

---

## 🤝 Community & Support

If you have any questions, feel free to join our QQ group:
**1006709313**

![主图](https://github.com/user-attachments/assets/9be879b9-e1c0-42a5-885c-f4c2dc13a077)


