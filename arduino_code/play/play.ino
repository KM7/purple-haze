/*
  Analog Input
 Demonstrates analog input by reading an analog sensor on analog pin 0 and
 turning on and off a light emitting diode(LED)  connected to digital pin 13.
 The amount of time the LED will be on and off depends on
 the value obtained by analogRead().

 The circuit:
 * Potentiometer attached to analog input 0
 * center pin of the potentiometer to the analog pin
 * one side pin (either one) to ground
 * the other side pin to +5V
 * LED anode (long leg) attached to digital output 13
 * LED cathode (short leg) attached to ground

 * Note: because most Arduinos have a built-in LED attached
 to pin 13 on the board, the LED is optional.


 Created by David Cuartielles
 modified 30 Aug 2011
 By Tom Igoe

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/AnalogInput

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
  
  delay(3000);
}



void postData()
{

}
