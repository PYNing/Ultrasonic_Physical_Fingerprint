# 基于超声波物理指纹（声纹）的安全防护装置
利用超声波探头通频带的差异，设计一套具有移动侦测和抗伪造攻击能力的安全防护装置。本项目曾获电子科技大学2015年“银杏黄”创新创业基金支持，并获优秀结项。
## 基本原理
![image](https://github.com/PYNing/Ultrasonic-Physical-Fingerprint/blob/master/img/Principle2.png)
## 硬件结构
![image](https://github.com/PYNing/Ultrasonic-Physical-Fingerprint/blob/master/img/Hardwear.png)
## 算法逻辑
![image](https://github.com/PYNing/Ultrasonic-Physical-Fingerprint/blob/master/img/Softwear.png)

注：代码中使用的匹配检验算法为欧式距离
## 代码结构
目录 | 项目 | 功能 | MCU
---|---|---|---
TX | 发射机 | 对设计频点波形进行DA转换 | STM32F103ZET6
RX | 接收机 | AD采样，信号处理与执行核心算法 | STM32F429ZI
IR(TX)| 发射机辅助| 用以通过遥控控制继电器切换超声波发射探头 | STM32F103C8T6
IR(RX)| 接收机辅助 | 用以通过遥控控制继电器切换超声波接收探头|STM32F103C8T6

注：因GitHub上传代码出现异常（Something went wrong and we can't sign you in right now. Please try again later.），暂将代码保存于

[https://pan.baidu.com/s/1PDO3QTnw1j5BTiNeZnEHIg](https://pan.baidu.com/s/1PDO3QTnw1j5BTiNeZnEHIg)
## 项目特色
1. 于2015年尝试验证了利用超声波探头物理特征差异作为鉴别手段的可行性
2. 基于超声波的防护手段相对于基于可闻声波、红外线的防护手段具有更高的隐蔽性
3. 接收机（基于STM32F429ZI）软件设计上采用了乒乓缓冲存储设计，以及使用了硬件FPU和DSP库加速FFT算法和特征检验算法，以保证数据的无缝缓冲处理

## 团队成员
指导老师：陈大江

团队学生：

陈东子（队长，组织协调，文档撰写）

宁培阳（系统设计与实现，文档撰写）

刘子涵（项目答辩，文档撰写）

万本钰（demo演示，文档撰写）
## Demo展示
### 演示视频
[https://pan.baidu.com/s/1LMDQT-pB9tu_gPPwt5CRXQ](https://pan.baidu.com/s/1LMDQT-pB9tu_gPPwt5CRXQ)

![image](https://github.com/PYNing/Ultrasonic_Physical_Fingerprint/blob/master/img/Demo_Review.png)

### 发射机硬件
![image](https://github.com/PYNing/Ultrasonic-Physical-Fingerprint/blob/master/img/Demo.png)

