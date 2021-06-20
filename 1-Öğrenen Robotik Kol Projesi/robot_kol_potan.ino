
#include <Servo.h>

Servo servo1; 
Servo servo2;
Servo servo3;
Servo servo4;

const int pot1 = A0; 
const int pot2 = A1; 
const int pot3 = A2;
const int pot4 = A3;

int pot1deger; 
int pot2deger;
int pot3deger;
int pot4deger;

int pot1aci;
int pot2aci;
int pot3aci;
int pot4aci;


void setup() {
  servo1.attach(3); 
  servo2.attach(5);
  servo3.attach(6);
  servo4.attach(9);
}

void loop() {
  pot1deger = analogRead(pot1); 
  pot1aci = map(pot1deger, 0, 1023, 0, 180);
  pot2deger = analogRead(pot2); 
  pot2aci = map(pot2deger, 0, 1023, 0, 180);
  pot3deger = analogRead(pot3);
  pot3aci = map(pot3deger, 0, 1023, 0, 180);
  pot4deger = analogRead(pot4);
  pot4aci = map(pot4deger, 0, 1023, 0, 180);
   
  servo1.write(pot1aci); 
  servo2.write(pot2aci);
  servo3.write(pot3aci);
  servo4.write(pot4aci);
}
