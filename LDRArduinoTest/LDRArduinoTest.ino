int LDRPin = A3;    // select the input pins for your LDRs
int LDRPin2 = A2;

int ledPin = 10;   // select the pins for the LEDs
int ledPin2 = 11;

int val = 0;       // variable to store the value coming from the sensor before treatment
int val2 = 0;

int lightLevel = 0; // variables to store treated values
int lightLevel2 = 0;

void setup() {
}

void loop() {
  val = analogRead(LDRPin);     // read values from sensors, and remap
  val = map(val, 0, 900, 0, 255);

  val2 = analogRead(LDRPin2);
  val2 = map(val2, 0, 900, 0, 255);

  
  lightLevel = val - val2;      // treat the values
  if(lightLevel < 0){
    lightLevel = 0;
  }

  lightLevel2 = val2 - val;
  if(lightLevel2 < 0){
    lightLevel2 = 0;
  }
  
  analogWrite(ledPin, lightLevel);  // write values to the LED pins
  analogWrite(ledPin2, lightLevel2);
  
}
