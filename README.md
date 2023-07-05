# IntelliHome 智能家居系统
## 技术栈

- Pynq-z2/Zynq7000
- Esp32
- Android APP

## 功能

- 通过APP使用蓝牙来操作系统。
- 智能门锁：通过App远程控制入户门锁。
- 智能照明：通过App控制室内照明的开关，也可以开启亮度检测模式在天黑时自动开灯并关窗帘。
- 智能窗户、窗帘：通过App控制窗户和窗帘的开合。
- 颜色检测：在App上显示检测到的颜色。
- 气体安全检测：在厨房检测到可燃气体泄漏时联动开启窗户和抽风扇并通知用户。
- 智能安防：一键离家模式，自动关闭所有门窗，开启红外距离监测，侵入报警、通知用户。

## Hardware/Zynq

- PL实现PWM，封装成RTL供PS调用。
- GPIO都使用PS的GPIO EMIO。
- 使用PS的IIC0和IIC1来分别驱动距离传感器和颜色传感器。
- 使用PS的UART1与ESP32通信，注意两者RX/TX的连线。UART0用于本地调试串口。

## SDK

PS使用SDK来开发，相应代码在Software/Zynq文件夹中。

## ESP32

- 使用ESP32的BLE与手机建立蓝牙连接。
- 使用ESP32的UART2与Zynq通信，UART0用作本地调试串口。
- SERVICE_UUID与CHARACTERISTIC_UUID要与APP Inventor中的一样。

## Android

- APP使用 APP Inventor 图形化编程工具开发。
- 具体的逻辑见Software/Android/blocks.png图片。
- 因为ESP32使用的是BLE低功耗蓝牙，APP Inventor原生的蓝牙组件不支持BLE，所以需要使用BluetoothLE的Extension，在https://iot.appinventor.mit.edu/#/bluetoothle/bluetoothleintro中下载添加到Extension中，组件设计中都要使用它。

