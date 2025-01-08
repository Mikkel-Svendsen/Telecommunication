
/*
  7a.
    An RGB value represents a color.
    It contains the values of the amount of red, green and blue the color contains.
    0 is the minimal amout of a specific color and 255 is the maximum amount of a color.

  7b.
    Serial.parInt() looks for the next integer in a incoming serial.
*/

int red = 0;
int green = 0;
int blue = 0;

void setup() {
  //Initialize pins
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(6, OUTPUT);

  //Initialize Serial communicaiton
  Serial.begin(9600);
}

void loop() {
  //7c.
  //Read the color values
  if (Serial.available() > 0) {
    red = Serial.parseInt();
    green = Serial.parseInt();
    blue = Serial.parseInt();
  }

  //7d. - Image names in the folder shows the RGB values sent in the serial monitor.
  //Output color values to LED
  analogWrite(11, blue);
  analogWrite(10, green);
  analogWrite(6, red);
}
