/*
 11-14-2013
 SparkFun Electronics 2013
 Shawn Hymel

 This code is public domain but you buy me a beer if you use this 
 and we meet someday (Beerware license).

 Description:

 This sketch shows how to use the SparkFun INA169 Breakout
 Board. As current passes through the shunt resistor (Rs), a
 voltage is generated at the Vout pin. Use an analog read and
 some math to determine the current. The current value is
 displayed through the Serial Monitor.

 Hardware connections:

 Uno Pin    INA169 Board    Function

 +5V        VCC             Power supply
 GND        GND             Ground
 A0         VOUT            Analog voltage measurement

 VIN+ and VIN- need to be connected inline with the positive
 DC power rail of a load (e.g. an Arduino, an LED, etc.).

 */

// Constants
const int SENSOR_PIN = A0;  // Input pin for measuring Vout
const float RS = 0.10;          // Shunt resistor value (in ohms)
const float VOLTAGE_REF = 3.3;  // Reference voltage for analog read

// Global Variables
float sensorValue;   // Variable to store value from analog read
float current;       // Calculated current value
float normalizedSensorValue;
float calcedDenominator;

void setup() {

  // Initialize serial monitor
  Serial.begin(9600);
  //analogReference(INTERNAL);

}

void loop() {

  calcedDenominator = 10.0 * RS;
  //Serial.print(calcedDenominator, 10);
  //Serial.println(" denominator");
  
  // Read a value from the INA169 board
  sensorValue = analogRead(SENSOR_PIN);

  Serial.print(sensorValue, 10);
  Serial.println(" raw");

  // Remap the ADC value into a voltage number: 5, 3V3, or 1V1
  normalizedSensorValue = (sensorValue * VOLTAGE_REF) / 1023;
  //Serial.print(normalizedSensorValue, 10);
  //Serial.println(" normalized");

  current = normalizedSensorValue / calcedDenominator;

  // Output value (in amps) to the serial monitor to 10 decimal
  // places
  Serial.print(current, 10);
  Serial.println(" A");

  // Delay program for a few milliseconds
  delay(500);

}
