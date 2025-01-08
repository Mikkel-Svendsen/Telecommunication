/*
  Questions:
  6a.
    A char is a datatype that uses 1 byte (8 bits)

  6b.
    The different characters has associated ASCII values that can be added up as shown:
    '4' = 52
    '0' = 48
    val = 52-48 = 4
    'A' = 65
    mychar = 4+65-1 = 68 = 'D'
    The resulting charactor in mychar is D
  
  6c.
*/

char incomingByte = 0;

void setup() {
  //Initialize pins
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);

  //Initialize Serial communicaiton
  Serial.begin(9600);
}

void loop() {
  //Read incoming bytes
  if (Serial.available() > 0) {
    incomingByte = Serial.read();
  }

  //Turn on/off LEDs based on character sent to Arduino
  switch (incomingByte){
    case 'a':
      digitalWrite(7, 1);
    break;

    case 'b':
      digitalWrite(6, 1);
    break;

    case 'c':
      digitalWrite(5, 1);
    break;

    case 'd':
      digitalWrite(4, 1);
    break;

    case 'e':
      digitalWrite(3, 1);
    break;

    default:
      digitalWrite(7, 0);
      digitalWrite(6, 0);
      digitalWrite(5, 0);
      digitalWrite(4, 0);
      digitalWrite(3, 0);
  }
}
