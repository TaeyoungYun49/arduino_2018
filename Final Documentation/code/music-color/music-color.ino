#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"
#include "Wire.h"
#include "Adafruit_TCS34725.h"

Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_1X);
bool flag = true;
SoftwareSerial mySoftwareSerial(10, 11); // RX, TX
DFRobotDFPlayerMini myDFPlayer;

unsigned long previousMillis = 0;
const long interval = 20000;
void printDetail(uint8_t type, int value);

void setup() {
  //color
  Serial.begin(9600);

  //mp3
  mySoftwareSerial.begin(9600);
  Serial.begin(115200);      

  Serial.println();
  Serial.println(F("DFRobot DFPlayer Mini Demo"));
  Serial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));

  if (!myDFPlayer.begin(mySoftwareSerial)) {  //Use softwareSerial to communicate with mp3.
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
    while (true);
  }
  Serial.println(F("DFPlayer Mini online."));

  myDFPlayer.setTimeOut(500); //Set serial communictaion time out 500ms

  //----Set volume----
  myDFPlayer.volume(25);  //Set volume value (0~30).
  //----Set different EQ----
  myDFPlayer.EQ(DFPLAYER_EQ_NORMAL);
 
  //----Set device, use SD as default----
  myDFPlayer.outputDevice(DFPLAYER_DEVICE_SD);
}

void loop() {

  unsigned long currentMillis = millis();

  // Der Sensor liefert Werte für R, G, B und einen Clear-Wert zurück
  uint16_t clearcol, red, green, blue;
  float average, r, g, b;
  delay(500); 
  tcs.getRawData(&red, &green, &blue, &clearcol);

 // color values ​​by average, 
 // all values ​​now move around 1 
  average = (red + green + blue) / 3;
  r = red / average;
  g = green / average;
  b = blue / average;

 // output the clear value and r, g, b serially for control 
 // r, g and b should be between approx. 0.5 and 1.5 
 //. If the sensor looks red, then r should be well above 1.0 
 //, g and b between 0.5 and 1.0, and so on  
  Serial.print("\tClear:"); Serial.print(clearcol);
  Serial.print("\tRed:"); Serial.print(r);
  Serial.print("\tGreen:"); Serial.print(g);
  Serial.print("\tBlue:"); Serial.print(b);

  if  ((r > 1.8) && (g < 0.6) && (b < 0.6)) {
    if (flag) {
      flag = false;
      Serial.print("\tred");
      myDFPlayer.playMp3Folder(1); //play specific mp3 in SD:/MP3/0001.mp3
    }
  }

  else if ((r < 0.95) && (g > 1.3) && (b < 0.85)) {
    if (flag) {
      flag = false;
      Serial.print("\tgreen");
      myDFPlayer.playMp3Folder(2); //play specific mp3 in SD:/MP3/0002.mp3
    }
  }

  else if ((r < 0.8) && (g < 1) && (b > 1.4)) {
    if (flag) {
      flag = false;
      Serial.print("\tblue");
      myDFPlayer.playMp3Folder(3); //play specific mp3 in SD:/MP3/0003.mp3
    }
  }
  else if ((r > 1.1) && (g > 1.1) && (b < 0.75)) {
    if (flag) {
      flag = false;
      Serial.print("\tyellow");
      myDFPlayer.playMp3Folder(4); //play specific mp3 in SD:/MP3/0004.mp3
    }
  }
  else {
    flag = true;
    if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;
      myDFPlayer.pause();  //pause the mp3
    }
  }

  // Zeilenwechsel ausgeben
  Serial.println("");
  // Wartezeit anpassen für serielles Debugging
  delay(100);

}
