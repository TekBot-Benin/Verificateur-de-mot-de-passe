include <Key.h>
#include <Keypad.h>
#include <Keypad_I2C.h>

#define I2CADDR 0x23
#define led_red 5
#define led_green 6
#define led_blue 9

char keys[4][4] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins [4] = {0, 1, 2, 3};
byte colPins [4] = {4, 5, 6, 7};
Keypad_I2C keypad (makeKeymap (keys), rowPins, colPins, 4, 4, I2CADDR, PCF8574);

void setup(){
   pinMode(led_red , OUTPUT);
   pinMode(led_green , OUTPUT);
   pinMode(led_blue , OUTPUT);
   Wire .begin ();
   keypad.begin (makeKeymap (keys));
   Serial.begin(9600);
}

void loop () {
 char mdp[] = "1234";
 char key[5];
 int i = 0;
 //list.vide();
 for (i = 0; i < 4 || !key[i];) {
    key[i] = keypad.getKey();
    if (key[i])
      i++;
 }
 for (i = 0; key[i] == mdp[i] && i < 4; i++);
 if (i == 4)
    digitalWrite(led_green, HIGH);
 else
    digitalWrite(led_red, HIGH);
 delay(2000);
 digitalWrite(led_green, LOW);
 digitalWrite(led_red, LOW);
}
