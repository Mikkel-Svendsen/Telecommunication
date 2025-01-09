
// note that we use an arduino mega

/*
Exercise 11
Questions:

 * 11a:
   I2C is a protocol for data transfer. It uses 4 pins to send data, of which are 2 data pins and the other two are VCC and gnd, 
   and is a half duplex protocol. The cool thing about I2C, is that it can have a lot of devices on the same wires. So technically,
   you can have n amount of slaves for 1 master.

 * 11b:
   It takes a lot of computational power for the arduino to write and clear the display, and it is propotional with the amount of pixels
   that has to be written/cleared. This means, that to save computational power, only the pixels that needs to be changed should.
   However, for the scope of this exercise, we won't care for that.

 * 11c:
   See video.

*/

#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const uint8_t tempPin = 54;  // A0


void setup() {
  // put your setup code here, to run once:
  pinMode(tempPin, INPUT);
  Serial.begin(115200);
  lcd.begin(16, 2);
  lcd.print("Temperature: "); // save a little computational power.

}

void loop() {
  // put your main code here, to run repeatedly:

  int degree = 176;
  float voltage = analogRead(tempPin) * 5 / 1023.0;
  float celcius = voltage * 100;
  Serial.print("Voltage: ");
  Serial.print(voltage, 3);
  Serial.println("V");

  Serial.print("Degrees: ");
  Serial.print(celcius);
  Serial.write(degree);
  Serial.println("C\n");
  
  lcd.setCursor(0, 1); // allows writing on the same spot.
  lcd.print(celcius);

  delay(100);
}
