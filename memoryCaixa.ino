#include <LiquidCrystal.h>
#include <Keypad.h>
#include <SoftwareSerial.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {13, A2, A1, A0};
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
SoftwareSerial BTserial(10, 11); // RX | TX

void setup() {
  lcd.begin(16, 2);
  lcd.print("TABUADA ALEATORIA");
  BTserial.begin(9600);
  randomSeed(analogRead(0));
}

void loop() {
  int num1 = random(1, 11);
  int num2 = random(1, 11);
  int answer = num1 * num2;
  int userAnswer = getAnswer(num1, num2);
  if (userAnswer == answer) {
    lcd.clear();
    lcd.print("Acertou! :)");
    BTserial.write('1');
    delay(1000);
  } else {
    lcd.clear();
    lcd.print("Errou! :(");
    delay(1000);
  }
}

int getAnswer(int num1, int num2) {
  lcd.clear();
  lcd.print(num1);
  lcd.print(" x ");
  lcd.print(num2);
  lcd.print(" = ?");
  int userAnswer = 0;
  while (userAnswer == 0) {
    char key = keypad.getKey();
    if (key >= '0' && key <= '9') {
      lcd.setCursor(0, 1);
      lcd.print(key);
      userAnswer = key - '0';
    }
  }
  return userAnswer;
}
