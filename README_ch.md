# RC-BadU3B
A remote BadUSB project, using esp32 and WCH chip.

[![Bilibili 粉丝](https://img.shields.io/badge/dynamic/json?color=blue&label=BiliBili&labelColor=white&query=$.data.follower&url=https://api.bilibili.com/x/relation/stat?vmid=1084866085&logo=bilibili&style=flat-square)](https://space.bilibili.com/1084866085)
[![YouTube](https://img.shields.io/badge/YouTube-white?logo=youtube&logoColor=FF0000&style=flat-square)](https://www.youtube.com/@lyyontop)
[![GitHub last commit](https://img.shields.io/github/last-commit/LanYangYang321/RC-BadU3B?color=yellow&logo=github&labelColor=black&label=Latest&style=flat-square)](https://github.com/LanYangYang321/RC-BadU3B)

# 免责声明:

本项目仅用于网络安全教育、技术研究与合法授权的测试用途。
本项目中的所有代码、工具和演示内容，仅供学习参考，禁止将其用于任何未获授权的实际入侵或控制行为。

请注意以下法律风险与责任：

本项目所涉及的远程访问功能，如被用于非法控制他人设备、窃取信息、破坏数据等行为，均属违法。

任何使用者擅自将本项目用于非法目的（如入侵他人计算机系统、传播恶意程序等），其行为所产生的一切后果由其本人承担，作者不对任何违法使用行为承担责任。

# 复刻前必看
本项目中包含**2个子项目**：
- 遥控BadUSB，即包含**超小接收器**和**esp32**通讯构成的遥控HID收发器。如需复刻此项目请看详情 [RMTbadusb](https://github.com/LanYangYang321/RC-BadU3B/tree/main/RMTbadusb)
- 本地BadUSB，即包含SD存储卡模块，可内置需要执行的载荷。如需复刻此项目请看详情 [localBadUSB](https://github.com/LanYangYang321/RC-BadU3B/tree/main/localBadUSB)
复刻本项目需要掌握**PCB焊接技术**，特别是*遥控BadUSB*中，需要焊接QFN封装的芯片，新手操作较为复杂。

# 硬件部分
硬件部分分别参考[立创开源社区](https://oshwhub.com/)的[U盘版BadUSB](https://oshwhub.com/Albireo/Upan-ban-BADUSB)和[超小USB转蓝牙接头](https://oshwhub.com/lightandelectricity/bplug-ch)

PCB的相关Gerber制板文件我放在了[制板文件](https://github.com/LanYangYang321/RC-BadU3B/tree/main/PCBGerber)
可以自行获取并打样。

# 软件部分
软件部分采用arduino开发环境进行开发。两个子文件的代码分别放在了两个文件夹中，其中关于“远控木马”的部分采用的是我之前自行编写的一个开源远控软件[tetrojan](https://github.com/LanYangYang321/tetrojan)
实际使用使用时直接烧录arduino文件即可

# 交流
如有任何问题欢迎加入qq交流群：
1006709313

![主图](https://github.com/user-attachments/assets/5b41c8c0-5ea8-431e-9fa9-dd67ad85dcf0)

