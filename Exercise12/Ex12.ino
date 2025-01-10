
// note that we use an arduino mega

/*
Exercise 12
Questions:

 * 12a:
   See video

 * 12b:
   Yes, the timing is fine :)

 * 12c:
   The pattern implemented is all the LEDs flashing.

 * 12d:
   See final video.

 * 12e:
   See final video.

*/

#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const uint8_t rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const uint8_t buttonPin = 54;  // A0
const uint8_t R1Pin = 10;
const uint8_t R2Pin = 6;
const uint8_t Y1Pin = 9;
const uint8_t Y2Pin = 7;
const uint8_t GPin = 8;

int buttonState = 0;
int lastButtonState = 0;
int hitCounter = 0;
int missCounter = 0;
int counter = 0;
int randomNumber = 0;

unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers
unsigned long timeBetweenLEDs = 100;




// prototype functions:
void turnOfLEDs();
void flashingLEDs();
void miss();
void hit();
void updateHits(int counter);
void winnerWinnerChickenDinner();


void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin, INPUT);
  pinMode(R1Pin, OUTPUT);
  pinMode(R2Pin, OUTPUT);
  pinMode(Y1Pin, OUTPUT);
  pinMode(Y1Pin, OUTPUT);
  pinMode(GPin, OUTPUT);

  Serial.begin(115200);
  lcd.begin(16, 2);
  lcd.print("LED hit:  0  0"); // save a little computational power.
  randomNumber = random(0, 5); // get initial random number.


}

void loop() {

  // reset hitFlag
  bool hitFlag = false;

  // read button
  int reading = digitalRead(buttonPin);

  // do debounce
  if (buttonState != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != buttonState) {
      buttonState = reading;

    }
  }


  // turn all LED's off (reduce redundant code)
  turnOfLEDs();

  ////////////////////// Normal leds ////////////////////////
  if (hitCounter < 8) {

    // reset counter every 5*timeBetweenLEDs seconds.
    if (counter >= 5*timeBetweenLEDs){
      counter = 0;
    }

    // check what LED should be on:
    if (counter > 0 && counter <= timeBetweenLEDs) {
      // turn on left red led
      digitalWrite(R1Pin, HIGH);
      if (buttonState == HIGH) {
        lcd.setCursor(0, 1);
        lcd.print("Left red    "); // added spaces to clear display
        miss();
      }

    } else if (counter > timeBetweenLEDs && counter <= 2*timeBetweenLEDs) {
      // turn on left yellow led
      digitalWrite(Y1Pin, HIGH);
      if (buttonState == HIGH) {
        lcd.setCursor(0, 1);
        lcd.print("Left yellow ");
        miss();
      }

    } else if (counter > 2*timeBetweenLEDs && counter <= 3*timeBetweenLEDs) {
      // turn on green led
      digitalWrite(GPin, HIGH);
      if (buttonState == HIGH) {
        lcd.setCursor(0, 1);
        lcd.print("GREEEEEEEEEN");
        hit();
        hitFlag = true;
      }

    } else if (counter > 3*timeBetweenLEDs && counter <= 4*timeBetweenLEDs) {
      // turn on right yellow led
      digitalWrite(Y2Pin, HIGH);
      if (buttonState == HIGH) {
        lcd.setCursor(0, 1);
        lcd.print("right yellow");
        miss();
      }

    } else if (counter > 4*timeBetweenLEDs && counter <= 5*timeBetweenLEDs) {
      // turn on right red led
      digitalWrite(R2Pin, HIGH);
      if (buttonState == HIGH) {
        lcd.setCursor(0, 1);
        lcd.print("right red   ");
        miss();
      }
    }

  ////////////////////// Random leds ////////////////////////
  } else {
    
    if (counter >= timeBetweenLEDs){
      randomNumber = random(0, 5);
      counter = 0;
    }

    if (randomNumber == 0) {
      // turn on left red led
      digitalWrite(R1Pin, HIGH);
      if (buttonState == HIGH) {
        lcd.setCursor(0, 1);
        lcd.print("Left red    "); // added spaces to clear display
        miss();
      }

    } else if (randomNumber == 1) {
      // turn on left yellow led
      digitalWrite(Y1Pin, HIGH);
      if (buttonState == HIGH) {
        lcd.setCursor(0, 1);
        lcd.print("Left yellow ");
        miss();
      }

    } else if (randomNumber == 2) {
      digitalWrite(GPin, HIGH);
      if (buttonState == HIGH) {
        lcd.setCursor(0, 1);
        lcd.print("GREEEEEEEEEN");
        hit();
        hitFlag = true;
      }

    } else if (randomNumber == 3) {
      // turn on right yellow led
      digitalWrite(Y2Pin, HIGH);
      if (buttonState == HIGH) {
        lcd.setCursor(0, 1);
        lcd.print("right yellow");
        miss();
      }

    } else if (randomNumber == 4) {
      digitalWrite(R2Pin, HIGH);
      if (buttonState == HIGH) {
        lcd.setCursor(0, 1);
        lcd.print("right red   ");
        miss();
      }
    }
  }

  // make the game harder if the player hit the green LED
  if (hitFlag) {
    timeBetweenLEDs = timeBetweenLEDs - 5;
  }

  if (hitCounter >= 10) {
    winnerWinnerChickenDinner();
  }

  lastButtonState = reading;
  counter += 10;
  delay(10);

}


void turnOfLEDs() {
  digitalWrite(R1Pin, LOW);
  digitalWrite(R2Pin, LOW);
  digitalWrite(Y1Pin, LOW);
  digitalWrite(Y2Pin, LOW);
  digitalWrite(GPin, LOW);
}

void flashingLEDs() {
  for (int i = 0; i < 5; i++) {
    digitalWrite(R1Pin, HIGH);
    digitalWrite(R2Pin, HIGH);
    digitalWrite(Y1Pin, HIGH);
    digitalWrite(Y2Pin, HIGH);
    digitalWrite(GPin, HIGH);
    delay(100);
    digitalWrite(R1Pin, LOW);
    digitalWrite(R2Pin, LOW);
    digitalWrite(Y1Pin, LOW);
    digitalWrite(Y2Pin, LOW);
    digitalWrite(GPin, LOW);
    delay(100);
  }
}

void miss() {
  turnOfLEDs();
  missCounter++;
  updateHits(missCounter, 13);
  delay(1000);
}

void hit() {
  flashingLEDs();
  hitCounter++;
  updateHits(hitCounter, 10);

}

void updateHits(int counter, int location) {
  lcd.setCursor(location, 0);
  lcd.print(counter);
}

void winnerWinnerChickenDinner() {
    for (int i = 0; i < 3; i++){
      flashingLEDs();
    }
    delay(1000);
    // reset everything
    hitCounter = 0;
    missCounter = 0;
    counter = 0;
    updateHits(hitCounter, 10);
    updateHits(missCounter, 13);
    timeBetweenLEDs = 100;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Winner winner");
    lcd.setCursor(0, 1);
    lcd.print("Cicken dinner");

    delay(1000000); // get stuck here
}