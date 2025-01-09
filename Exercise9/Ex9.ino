
// note that we use an arduino mega

/*
Exercise 1
Questions:
 * 9a:
   Each degree celcius corrosponds to 10mV.

 * 9b:
   0*, 2*, 4* and 6* (with * being the degree sign)
   
 * 9c:
   The difference between write and print, is that write sends out binary data, and print sends characters. The code therefore should
   send 0*, 2*, 4* and 6* (with * being the degree sign), however, the arduino IDE sends a [?] sign instead for some reason.

 * 9d:
   The voltage from A0 is read as 50 or in this case 0.244V, which from the datasheet corrosponds to 24,4 *C.

 * 9e:
   We convert the voltage by multiplying it 100.

 * 9f:
   See video.

*/

const uint8_t tempPin = 54;  // A0


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(tempPin, INPUT);
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
  

  delay(100);
}
