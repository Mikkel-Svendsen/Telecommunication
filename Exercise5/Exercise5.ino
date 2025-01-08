int incomingByte = 0;

void setup() {
  //Initialize the serial communication
  Serial.begin(9600);

}

void loop() {
  //The if statement checks wether a byte is available to read
  if (Serial.available() > 0) {
    //When a byte is available to be read, it is read and put into incomingbyte
    incomingByte = Serial.read();

    //It prints the recieved byte.
    Serial.print("I received: ");
    //Serial.println(incomingByte, DEC);
    Serial.println((char)incomingByte);
  }
}

// 5d. The recieved values are ASCII codes.
// 5e. When sending a line ending, the ASCII code for the line ending is also sent.
// 5f. The ASCII values are shown as their proper symbols.