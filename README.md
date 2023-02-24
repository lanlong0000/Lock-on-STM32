# Lock-on-STM32
![image](https://user-images.githubusercontent.com/84573792/221171372-c9ced138-e31f-4443-9cbe-367978cb3d7e.png)
![image](https://user-images.githubusercontent.com/84573792/221171402-f5de202c-8211-4562-bc2e-9e892b625702.png)
#### 实现流程

![image](https://user-images.githubusercontent.com/84573792/221171436-85368097-e6ce-4fcf-b557-b19c8a7fe3ef.png)

因疫情缘故，没能完成实物搭建，使用 proteus 仿真时因软件优化原因，费了很大周章在调试。proteus 对 stm32 系列产品优化并不好，频频闪退。在对 msp430，stm32 学习后对寄存器，定时器，中断有了更深的感悟，也体验了很多工具类似stm32cube，keil，也尝试过用 vscode 作为 ide 环境，但最后还是选择 keil，工欲善其事必先利其器，也对其存在的一些不美观，不方便的问题调整成一个趁手的 ide。在对于中断研究中，我尝试过直接在 proteus 中使用矩阵键盘中断的方式，可惜未果，其中原因可能没有那么多中断 io 口供外部中断使用，配置完中断函数 proteus 便频频报错。之后通过扫描方式来使用矩阵键盘，因为扫描次数和频率的上升，由于电脑和软件优化问题，一点点改动和调试都变得尤为困难。也是体验了一把纯粹的“纸上谈兵”，如果能够有设备，仿真器，这些问题都将轻而易举的迎刃而解。也能想象过去的单片机开发者在设备落后，也没有太多渠道获得信息资源。
