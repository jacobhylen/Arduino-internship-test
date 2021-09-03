/* Analog Read to LED
 * ------------------ 
 *
 * turns on and off a light emitting diode(LED) connected to digital  
 * pin 13. The amount of time the LED will be on and off depends on
 * the value obtained by analogRead(). In the easiest case we connect
 * a potentiometer to analog pin 2.
 *
 * Created 1 December 2005
 * copyleft 2005 DojoDave <http://www.0j0.org>
 * http://arduino.berlios.de
 *
 */

int potPin = A3;    // select the input pin for the potentiometer
int potPin2 = A2;

int ledPin = 13;   // select the pin for the LED
int ledPin2 = 11;

int val = 0;       // variable to store the value coming from the sensor
int val2 = 0;

int lightLevel = 0;
int lightLevel2 = 0;

void setup() {
}

void loop() {
  val = analogRead(potPin);
  val = map(val, 0, 900, 0, 255);

  val2 = analogRead(potPin2);
  val2 = map(val2, 0, 900, 0, 255);

  Serial.println(val2);
  
  lightLevel = val - val2;
  if(lightLevel < 0){
    lightLevel = 0;
  }

  lightLevel2 = val2 - val;
  if(lightLevel2 < 0){
    lightLevel2 = 0;
  }
  
  analogWrite(ledPin, lightLevel);  // turn the ledPin on
  analogWrite(ledPin2, lightLevel2);
  //Serial.println(lightLevel);
  //Serial.println(val2);

}
