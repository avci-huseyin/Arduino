#include <Servo.h>
 
Servo servo1; 
Servo servo2;
Servo servo3;
Servo servo4;
 
 
const int button1 = 12; 
const int button2 = 13;
 
int button1deger = 0; 
boolean button2deger = false;
 
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
 
int servo1Poskayit[] = {1,1,1,1,1}; 
int servo2Poskayit[] = {1,1,1,1,1};
int servo3Poskayit[] = {1,1,1,1,1};
int servo4Poskayit[] = {1,1,1,1,1};
 
void setup() {
  servo1.attach(3); 
  servo2.attach(5);
  servo3.attach(6);
  servo4.attach(9);
   
 
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
 
  Serial.begin(9600);
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
   
  if(digitalRead(button1) == HIGH){ 
    button1deger++;
    switch(button1deger){
      case 1:
        servo1Poskayit[0] = pot1aci;
        servo2Poskayit[0] = pot2aci;
        servo3Poskayit[0] = pot3aci;
        servo4Poskayit[0] = pot4aci;
        
        Serial.println("Birinci kayıt yapıldı");
        break;
      case 2:
         servo1Poskayit[1] = pot1aci;
         servo2Poskayit[1] = pot2aci;
         servo3Poskayit[1] = pot3aci;
         servo4Poskayit[1] = pot4aci;
         
         Serial.println("İkinci kayıt yapıldı");
         break;
      case 3:
         servo1Poskayit[2] = pot1aci;
         servo2Poskayit[2] = pot2aci;
         servo3Poskayit[2] = pot3aci;
         servo4Poskayit[2] = pot4aci;
         Serial.println("Üçüncü kayıt yapıldı");
         break;
       case 4:
         servo1Poskayit[3] = pot1aci;
         servo2Poskayit[3] = pot2aci;
         servo3Poskayit[3] = pot3aci;
         servo4Poskayit[3] = pot4aci;
         Serial.println("Dördüncü kayıt yapıldı");
         break;
       case 5:
         servo1Poskayit[4] = pot1aci;
         servo2Poskayit[4] = pot2aci;
         servo3Poskayit[4] = pot3aci;
         servo4Poskayit[4] = pot4aci;
         Serial.println("Beşinci kayıt yapıldı");
         break;
    }
  }
 
  if(digitalRead(button2) == HIGH){
    button2deger = true;
    Serial.println("SON BUTONA BASILDI");
  }
   
  if(button2deger){ 
    for(int i = 0; i < 5; i++){
        servo1.write(servo1Poskayit[i]);
        servo2.write(servo2Poskayit[i]);
        servo3.write(servo3Poskayit[i]);
        servo4.write(servo4Poskayit[i]);
        Serial.println(" Potansiyometre acilari: ");
        Serial.println(servo1Poskayit[i]);
        Serial.println(servo2Poskayit[i]);
        Serial.println(servo3Poskayit[i]);
        Serial.println(servo4Poskayit[i]);
        delay(1000);
      }
  }
  delay(300);
} 
