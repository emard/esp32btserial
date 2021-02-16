#include "BluetoothSerial.h"
// set Board->ESP32 Arduino->ESP32 Dev Module

#define LED_BUILTIN 2

BluetoothSerial SerialBT;

uint8_t address[6] = {0x10, 0xC6, 0xFC, 0x84, 0x35, 0x2E};
String name = "Garmin GLO #4352e";
char *pin = "1234"; //<- standard pin would be provided by default
bool connected = false;

void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, 0);
  SerialBT.begin("ESP32", true);
  SerialBT.setPin(pin);
  Serial.println("Bluetooth master started");
}

void reconnect()
{
  // connect(address) is fast (upto 10 secs max), connect(name) is slow (upto 30 secs max) as it needs
  // to resolve name to address first, but it allows to connect to different devices with the same name.
  // Set CoreDebugLevel to Info to view devices bluetooth address and device names
  
  //connected = SerialBT.connect(name); // slow
  connected = SerialBT.connect(address); // fast

  // return value "connected" doesn't mean much
  // it is sometimes true even if not connected.
}

void loop()
{
  static uint16_t tprev, t;
  t = millis();
  int16_t tms = (int16_t)(t-tprev);

  if (connected && SerialBT.available())
  {
    // read returns char or -1 if unavailable
    char b = SerialBT.read();
    Serial.print(b);
    digitalWrite(LED_BUILTIN,1);
    tprev=t;
  }
  else
  {
    if(tms > 4000) // 4 seconds of serial silence
    {
      digitalWrite(LED_BUILTIN,0);
      reconnect();
      tprev = millis();
    }
  }
}
