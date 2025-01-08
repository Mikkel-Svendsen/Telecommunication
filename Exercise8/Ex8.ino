
// note that we use an arduino mega

/*
Exercise 1
Questions:
 * 8a:
   My potentiometer goes from 0 to 679 with analogRead, which makes sense, as the analogRead function utulizes the inbuild ADC
   and therefore outputs a number from 0-1023, with 0 being equal to 0V and 1023 being equal to 5V.
   Taking ( 5V/1023 ) * 679 = 3.3V

 * 8b:
   As I said in the above answer, the maximum voltage is 5V.
   
 * 8c:
   Theoretically 3.3V should be over the poteniometer when it is turned to 679, but, my multimeter said 3V. It should be stated, however, 
   that my multimeter is very old.

 * 8d:
   It then uses the onboard LED.

 * 8e:
   See video

*/

const uint8_t potPin = 54; //e.g. D6
const uint8_t RPin = 2;
const uint8_t GPin = 3;
const uint8_t BPin = 4;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(potPin, INPUT);
  pinMode(RPin, OUTPUT);
  pinMode(GPin, OUTPUT);
  pinMode(BPin, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:

  float voltage = analogRead(potPin) * (5 / 1023.0);

  int pinVal = map(analogRead(potPin), 0, 679, 0, 255); // map it from 0-255 instead of 0-1023
  Serial.println(pinVal);
  analogWrite(RPin, 255);
  analogWrite(GPin, 0);
  analogWrite(BPin, pinVal);
  
  delay(10);

}
