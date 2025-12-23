#include <Wire.h>
#include <TM1650.h>
#define reddot 2
#define greendot 0
#define semicol 1
TM1650 d;

unsigned long previousMillis = 0;  // will store last time LED was updated
const long interval = 300;         // interval at which to blink (milliseconds)

bool st = true;

//int ignoredKeys[] = {15, 47, 23, 55, 31, 7, 39};
//int arraySize = sizeof(targetKeys) / sizeof(targetKeys[0]);

void Turndevice() {
  if (st) {



    char line[] = "on  ";
    d.displayString(line);
    d.setDot(reddot, true);
    d.setDot(greendot, true);


  } else {

    char line[] = "off ";
    d.displayString(line);
    d.setDot(reddot, true);
    d.setDot(greendot, false);
  }
}




void setup() {
  Wire.begin();  //Join the bus as master

  Serial.begin(9600);  //Start serial communication at 9600 for debug statements
  Serial.println("TM1650 Example Code");
  d.init();
  d.displayOff();
  d.displayOn();
  d.setBrightness(TM1650_MAX_BRIGHT);
  d.displayString("____");
  st = true;
  Turndevice();
}
uint8_t oldkey = 0;
void loop() {


  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    uint8_t key = d.readButtons();

    if (key != oldkey) {
      switch (key) {
        case 79:
          // statements
          Serial.print("Button Data Received: ");
          Serial.println("Power");
          st = !st;
          Turndevice();
          break;
        case 111:
          // statements
          Serial.print("Button Data Received: ");
          Serial.println("C-");
          break;
        case 87:
          // statements
          Serial.print("Button Data Received: ");
          Serial.println("c+");
          break;
        case 119:
          // statements
          Serial.print("Button Data Received: ");
          Serial.println("V-");
          break;
        case 95:
          // statements
          Serial.print("Button Data Received: ");
          Serial.println("V+");
          break;
        case 71:
          // statements
          Serial.print("Button Data Received: ");
          Serial.println("Menu");
          break;
        case 103:
          // statements
          Serial.print("Button Data Received: ");
          Serial.println("OK");
          break;
      }
      oldkey = key;
    }
  }
}
