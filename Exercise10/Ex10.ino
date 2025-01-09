
// note that we use an arduino mega

/*
Exercise 10   

*/

const uint8_t tempPin = 54;  // A0
const uint8_t RPin = 2;
const uint8_t YPin = 3;
const uint8_t GPin = 4;



void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(tempPin, INPUT);
  pinMode(RPin, OUTPUT);
  pinMode(YPin, OUTPUT);
  pinMode(GPin, OUTPUT);

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
  

  if (celcius < 28){
    digitalWrite(GPin, HIGH);
    digitalWrite(YPin, LOW);
    digitalWrite(RPin, LOW);

  } else if (celcius >= 28 && celcius < 30) {
    digitalWrite(GPin, LOW);
    digitalWrite(YPin, HIGH);
    digitalWrite(RPin, LOW);
  
  } else if (celcius >= 30) {
    digitalWrite(GPin, LOW);
    digitalWrite(YPin, LOW);
    digitalWrite(RPin, HIGH);
  
  }

  delay(100);
}
