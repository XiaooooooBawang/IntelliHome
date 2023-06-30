#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>
#include <string>

// See the following for generating UUIDs:
// https://www.uuidgenerator.net/

#define SERVICE_UUID        "4fafc201-1fb5-459e-8fcc-c5c9c331914b"
#define CHARACTERISTIC_UUID "beb5483e-36e1-4688-b7f5-ea07361b26a8"

bool deviceConnected = false;
bool oldDeviceConnected = false;

BLEServer* pServer = NULL;
BLECharacteristic* pCharacteristic = NULL;

char op = 'x';
char statu = 'x';
unsigned int recvData = 0;
unsigned int r = 0;
unsigned int g = 0;
unsigned int b = 0;



//蓝牙服务的回调函数
class MyServerCallbacks: public BLEServerCallbacks {
    void onConnect(BLEServer* pServer) {
      deviceConnected = true;
      Serial.println("有设备接入");
    };

    void onDisconnect(BLEServer* pServer) {
      deviceConnected = false;
      Serial.println("有设备断开连接");
    };
};

//特征的回调函数
class myCharateristic:public BLECharacteristicCallbacks{
  void onWrite(BLECharacteristic* pCharacteristic){
      std::string receiveValue =pCharacteristic->getValue();
      op = receiveValue[0];
      statu = receiveValue[1];
      // Serial.println(receiveValue.c_str());

    }
};

void setup() {
  Serial.begin(115200);  // 监视器
  Serial2.begin(115200);  //pynq

  BLEDevice::init("ESP32");   // BLE 名称
  BLEServer *pServer = BLEDevice::createServer();
  pServer->setCallbacks(new MyServerCallbacks());   //绑定服务的回调函数
  BLEService *pService = pServer->createService(SERVICE_UUID);
  pCharacteristic = pService->createCharacteristic(
                                         CHARACTERISTIC_UUID,
                                         BLECharacteristic::PROPERTY_READ |
                                         BLECharacteristic::PROPERTY_WRITE |
                                         BLECharacteristic::PROPERTY_NOTIFY
                                       );

  pCharacteristic->setCallbacks(new myCharateristic());    //绑定特征的回调函数
  pService->start();
  // BLEAdvertising *pAdvertising = pServer->getAdvertising();  // this still is working for backward compatibility
  BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
  pAdvertising->addServiceUUID(SERVICE_UUID);
  pAdvertising->setScanResponse(true);
  pAdvertising->setMinPreferred(0x06);  // functions that help with iPhone connections issue
  pAdvertising->setMinPreferred(0x12);
  BLEDevice::startAdvertising();
  Serial.println("Characteristic defined! Now you can read it in your phone!");
  Serial2.write(0); // 唤醒pynq
}

void loop() {
  //如果断开了连接就重新广播
  if (!deviceConnected && oldDeviceConnected) {
      delay(500); 
      pServer->startAdvertising(); // restart advertising
      Serial.println("start advertising");
      oldDeviceConnected = deviceConnected;
  }
  // connecting
  if (deviceConnected && !oldDeviceConnected) {
      oldDeviceConnected = deviceConnected;
  }
  if (Serial2.available() > 0)
  {
    recvData = Serial2.read();
    if (recvData != 0) {
      Serial.print("recv: ");
      Serial.println(recvData);
      if (deviceConnected) {
        if (recvData == 10) {
          pCharacteristic->setValue("gas");
          pCharacteristic->notify();
          Serial.println("send gas");
        } else if (recvData == 11) {
          pCharacteristic->setValue("invasion");
          pCharacteristic->notify();
          Serial.println("send invasion");
        } else if (recvData == 12) {
          r = Serial2.read();
          g = Serial2.read();
          b = Serial2.read();
          String r_s =  String(r);
          String g_s =  String(g);
          String b_s =  String(b);
          String colorString = r_s + ";" + g_s + ";" +b_s;
          pCharacteristic->setValue(colorString.c_str());
          pCharacteristic->notify();
          Serial.println(colorString.c_str());
        }

      }
    }
  }

  if (op == 'l') {
    if (statu == '0') {  //"led=0"
      Serial2.write(1);
      delay(100);
      Serial.println("led=0");
    } else if (statu == '1') {  //"led=1"
      Serial2.write(2);
      delay(100);
      Serial.println("led=1");
    }
    op = 'x';
    statu = 'x';
  } else if (op == 'd') {
    if (statu == '0') {  //"door=0"
      Serial2.write(3);
      delay(100);
      Serial.println("door=0");
    } else if (statu == '1') {  //"door=1"
      Serial2.write(4);
      delay(100);
      Serial.println("door=1");
    }
    op = 'x';
    statu = 'x';
  } else if (op == 'w') {
    if (statu == '0') {  //"window=0"
      Serial2.write(5);
      delay(100);
      Serial.println("window=0");
    } else if (statu == '1') {  //"window=1"
      Serial2.write(6);
      delay(100);
      Serial.println("window=1");
    }
    op = 'x';
    statu = 'x';
  } else if (op == 'a') {
    if (statu == '0') {  //"auto_led=0"
      Serial2.write(7);
      delay(100);
      Serial.println("auto_led=0");
    } else if (statu == '1') {  //"auto_led=1"
      Serial2.write(8);
      delay(100);
      Serial.println("auto_led=1");
    }
    op = 'x';
    statu = 'x';
  } else if (op == 'o') {
    if (statu == '0') {  //"outside=0"
      Serial2.write(9);
      delay(100);
      Serial.println("outside=0");
    } else if (statu == '1') {  //"outside=1"
      Serial2.write(10);
      delay(100);
      Serial.println("outside=1");
    }
    op = 'x';
    statu = 'x';
  }  else if (op == 'k') {
    if (statu == 'g') {  //"know_gas"
      Serial2.write(11);
      delay(100);
      Serial.println("know_gas");
    } else if (statu == 'i') {  //"know_invasion"
      Serial2.write(12);
      delay(100);
      Serial.println("know_invasion");
    }
    op = 'x';
    statu = 'x';
  }  else if (op == 'c') {
    if (statu == '0') {  //"color = 0"
      Serial2.write(13);
      delay(100);
      Serial.println("color = 0");
    } else if (statu == '1') {  //"color = 1"
      Serial2.write(14);
      delay(100);
      Serial.println("color = 1");
    }
    op = 'x';
    statu = 'x';
  } 
  
  delay(300);
}

