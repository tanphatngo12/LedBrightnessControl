const int button1Pin = 12;
const int button2Pin = 13;
const int ledPin = 25;
const int buzzerPin = 26;

int brightness = 0;
int fadeAmount = 5;

void setup() {
  pinMode(button1Pin, INPUT_PULLUP);
  pinMode(button2Pin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  int button1State = digitalRead(button1Pin);
  int button2State = digitalRead(button2Pin);

  if (button1State == LOW) {
    brightness += fadeAmount;
    brightness = constrain(brightness, 0, 255);
    if (brightness == 255) {
      tone(buzzerPin, 1000, 100);
    }
  }

  if (button2State == LOW) {
    brightness -= fadeAmount;
    brightness = constrain(brightness, 0, 255);
    if (brightness == 0) {
      tone(buzzerPin, 500, 100);
    }
  }

  analogWrite(ledPin, brightness);
  delay(100);
}

void tone(int pin, int frequency, int duration) {
  unsigned long period = 1000000 / frequency;
  unsigned long startTime = millis();
  while (millis() - startTime < duration) {
    digitalWrite(pin, HIGH);
    delayMicroseconds(period / 2);
    digitalWrite(pin, LOW);
    delayMicroseconds(period / 2);
  }
}
