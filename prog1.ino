#include <SoftwareSerial.h>
#include "ThingSpeak.h"
#include <ESP8266WiFi.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_ADXL345_U.h>

WiFiClient client;

Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified(12345);
// repace your wifi username and password
const char* ssid     = "GURUKRUPA";
const char* password = "123@kaja";
unsigned long myChannelNumber = 1483349;
const char * myWriteAPIKey = "GRRY49FU30KV4KBI"; //x-axis of the Accelerometer 

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(112500);
 WiFi.begin(ssid, password);
   Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.print("Netmask: ");
  Serial.println(WiFi.subnetMask());
  Serial.print("Gateway: ");
  Serial.println(WiFi.gatewayIP());
  ThingSpeak.begin(client);

  if(!accel.begin())
  {
    Serial.println("no ADXL345 detected ... Check your wiring!");
    while(1);
  }
  accel.setRange(ADXL345_RANGE_4_G);
}
void loop() 
{
  float x,y,z;
  sensors_event_t event; 
  accel.getEvent(&event);
 
  Serial.print((event.acceleration.x)/9.8); Serial.print(",");
  Serial.print((event.acceleration.y)/9.8); Serial.print(",");
  Serial.println((event.acceleration.z)/9.8);
  x = (event.acceleration.x)/9.8;
  y = (event.acceleration.y)/9.8;
  z = (event.acceleration.x)/9.8;
  ThingSpeak.writeField(myChannelNumber, 2,x*y*z*100, myWriteAPIKey);
  Serial.println(x*y*z*100);
  delay(5000);
}
