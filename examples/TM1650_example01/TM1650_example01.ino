#include <Wire.h>
#include <TM1650.h>
#define reddot 2
#define greendot 0
#define semicol 1
TM1650 d;
unsigned long previousMillis = 0;  // will store last time LED was updated

// constants won't change:
const long interval = 300;  // interval at which to blink (milliseconds)
void setup() {
  Wire.begin();  //Join the bus as master

  Serial.begin(9600);  //Start serial communication at 9600 for debug statements
  Serial.println("TM1650 Example Code");
  d.init();
  d.displayOff();
  d.displayOn();
  d.displayString("____");
  d.setBrightness(TM1650_MAX_BRIGHT);
  delay(100);
  char line[] = "on  ";
  d.displayString(line);
  d.setDot(reddot, true);
}

void loop() {


  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    uint8_t key = d.readButtons();

    if (key != 0) {

      switch (key) {

        case 79:
          // statements
          Serial.print("Button Data Received: ");
          Serial.println("Power");
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

      delay(200);
    }
  }
}
