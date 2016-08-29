/*

 Roughly Created by Kenny Ma

 */
#include <Process.h>


int sensorPin = A4;    // select the input pin for the potentiometer
int sensorValue = 0;  // variable to store the value coming from the sensor

void setup() {
  Bridge.begin();
  Serial.begin(9600);
  delay(2000); // Wait for usb serial port to initialize
  // declare the ledPin as an OUTPUT:

}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  // turn the ledPin on
  Serial.println(sensorValue);
  String curlCmd; // Where we'll put our curl command
  Serial.println("hey"); // Print command for debug
  //Don't post anything if we don't have any sound
  if (sensorValue>0){
  Process postProcess; 
  String first="curl -d \"noise=";
  first+=sensorValue;
  first+="\" http://52.88.42.135:8081";
  Serial.println(first);
  postProcess.runShellCommandAsynchronously(first); // Send command through Shell 
  // stop the program for <sensorValue> milliseconds:
  while (postProcess.available() > 0)
  {
    char c = postProcess.read();
    Serial.print(c);
  }
  Serial.flush();

  }else{
  //do nothing
  }
  delay(3000);
}



void postData()
{

}
