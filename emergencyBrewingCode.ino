
/*
  WriteMultipleFields
  
  Description: Writes values to fields 1,2,3,4 and status in a single ThingSpeak update every 20 seconds.
  
  Hardware: ESP8266 based boards
  
  !!! IMPORTANT - Modify the secrets.h file for this project with your network connection and ThingSpeak channel details. !!!
  
  Note:
  - Requires ESP8266WiFi library and ESP8622 board add-on. See https://github.com/esp8266/Arduino for details.
  - Select the target hardware from the Tools->Board menu
  - This example is written for a network using WPA encryption. For WEP or WPA, change the WiFi.begin() call accordingly.
  
  ThingSpeak ( https://www.thingspeak.com ) is an analytic IoT platform service that allows you to aggregate, visualize, and 
  analyze live data streams in the cloud. Visit https://www.thingspeak.com to sign up for a free account and create a channel.  
  
  Documentation for the ThingSpeak Communication Library for Arduino is in the README.md folder where the library was installed.
  See https://www.mathworks.com/help/thingspeak/index.html for the full ThingSpeak documentation.
  
  For licensing information, see the accompanying license file.
  
  Copyright 2018, The MathWorks, Inc.
*/

#include "ThingSpeak.h"
#include "secrets.h"
#include <ESP8266WiFi.h>

// Sensor DS18B20
#include <OneWire.h>
#include <DallasTemperature.h>
#include <SoftwareSerial.h>


// DS18B20 en PIN 6 Digital
#define ONE_WIRE_BUS 4  //D2

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

//Dirección para cada sensor (Se deben sacar)
DeviceAddress sensor1 = {0x28, 0xFF, 0x31, 0x26, 0xA2, 0x17, 0x05, 0x7C};
DeviceAddress sensor2 = {0x28, 0xFF, 0x5F, 0x26, 0xA2, 0x17, 0x05, 0xCF};





float sensorData;
float ppmRead = A0;

char ssid[] = SECRET_SSID;   // your network SSID (name) 
char pass[] = SECRET_PASS;   // your network password
int keyIndex = 0;            // your network key Index number (needed only for WEP)
WiFiClient  client;

unsigned long myChannelNumber = SECRET_CH_ID;
const char * myWriteAPIKey = SECRET_WRITE_APIKEY;

int number = 0;

void setup() {
  Serial.begin(115200);  // Initialize serial

  WiFi.mode(WIFI_STA); 
  ThingSpeak.begin(client);  // Initialize ThingSpeak

  //Establecemos resolución de sensores

  /************************************************
   * Resolution     Increment            Time
   * 9  bit         0.5    degrees C     93.75 mSec
   * 10 bit         0.25   degrees C     187.5 mSec
   * 11 bit         0.125  degrees C     375 mSec
   * 12 bit         0.0625 degrees C     750 mSec  
  *************************************************/

 sensors.setResolution(sensor1, 12);
 sensors.setResolution(sensor2, 12);
}

// Particulas por millon gas function
float getPpm(void) {
  float sensorData= analogRead(ppmRead);
  float percentLecture = map(sensorData, 300, 1023, 0, 100);
  return percentLecture;
}


void loop() {

  // Connect or reconnect to WiFi
  if(WiFi.status() != WL_CONNECTED){
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(SECRET_SSID);
    while(WiFi.status() != WL_CONNECTED){
      WiFi.begin(ssid, pass);  // Connect to WPA/WPA2 network. Change this line if using open or WEP network
      Serial.print(".");
      delay(5000);     
    } 
    Serial.println("\nConnected.");
  }

  float lecturaSensor = getPpm();
  // Sensor de temperatura DS18B20
  
  sensors.requestTemperatures();
  
  float dataTemp2 = sensors.getTempC(sensor2);
  float dataTemp1 = sensors.getTempC(sensor1);
  Serial.print("Sensor 1: ");
  Serial.println(dataTemp1);
  Serial.print("Sensor 2: ");
  Serial.println(dataTemp2);

  // set the fields with the values
  ThingSpeak.setField(1, lecturaSensor);
  ThingSpeak.setField(2, dataTemp2); // Sensor DS18B20 olla superior
  ThingSpeak.setField(3, dataTemp1); // Usar para enfriamiento
  //ThingSpeak.setField(4, number4);


  
  // Write to ThingSpeak. There are up to 8 fields in a channel, allowing you to store up to 8 different
  // pieces of information in a channel.  Here, we write to field 1.
 // int x = ThingSpeak.writeField(myChannelNumber, 2, lecturaSensor, myWriteAPIKey);
  int x = ThingSpeak.writeFields(myChannelNumber,myWriteAPIKey);
  if(x == 200){
    Serial.println("Channel update successful.");
    /*Serial.print("ppm Monoxido %: ");
    Serial.print(lecturaSensor,2);
    Serial.println("%"); */
  }
  else{
    Serial.println("Problem updating channel. HTTP error code " + String(x));
  }

  /* change the value
  number++;
  if(number > 99){
    number = 0;
  }*/
  
  delay(20000); // Wait 20 seconds to update the channel again
}
