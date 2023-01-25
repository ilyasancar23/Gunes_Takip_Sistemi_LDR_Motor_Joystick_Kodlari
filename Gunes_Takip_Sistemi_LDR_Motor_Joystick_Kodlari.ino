#include <Stepper.h>

const int stepsPerRevolution = 200;
const int StepsPerRevolution = 64;

Stepper motor1 = Stepper(stepsPerRevolution, 8, 9, 10, 11);
Stepper motor2 = Stepper(stepsPerRevolution, 2, 3, 4, 5);
Stepper small_stepper(StepsPerRevolution, 8, 9, 10, 11);  
Stepper small_stepper2(StepsPerRevolution, 2, 3, 4, 5); 

int LDR1 = A0;
int LDR2 = A1;
int LDR3 = A2;
int LDR4 = A3;

int deger1, deger2, deger3, deger4; 

int yukari, asagi, sag, sol;     
int tolerans = 20;

void setup() {
  // put your setup code here, to run once:
  pinMode(LDR1, INPUT);      // LDR resistors
  pinMode(LDR2, INPUT);
  pinMode(LDR3, INPUT);
  pinMode(LDR4, INPUT); 

  Serial.begin(9600);
  motor1.setSpeed(50);
  motor2.setSpeed(50);

  small_stepper.setSpeed(500000);    // set first stepper speed
  small_stepper2.setSpeed(50000);   // set second stepper speed
}

void loop() {
  // put your main code here, to run repeatedly:
  
  
  deger1 = analogRead(LDR1);
  deger2 = analogRead(LDR2);
  deger3 = analogRead(LDR3);
  deger4 = analogRead(LDR4);

  yukari = (deger1 + deger2)/2;
  asagi = (deger3 + deger4)/2;
  sag = (deger1 + deger4)/2;
  sol = (deger2 + deger3)/2;

  Serial.print("Deger1: ");
  Serial.println(deger1);
  Serial.print("Deger2: ");
  Serial.println(deger2);
  Serial.print("Deger3: ");
  Serial.println(deger3);
  Serial.print("Deger4: ");
  Serial.println(deger4);
  Serial.println();
  Serial.print("Yukarı: ");
  Serial.println(yukari);
  Serial.print("Aşağı: ");
  Serial.println(asagi);
  delay(0);
  //*************** yatay motor **********************
  if(sag == sol) {
     motor1.step(0);
  }
    
  if(sag > sol && (sag-sol) > tolerans) {
    motor1.step(35);
  }
   
  if(sol > sag && (sol-sag) > tolerans) {
    motor1.step(-35);
  }
  
  delay(50);
  
  //************* dikey motor ************************

  if(yukari == asagi) {
     motor2.step(0);
  }
    
  if(yukari > asagi && (yukari-asagi) > tolerans) {
      motor2.step(35);
  }
   
  if(asagi > yukari && (asagi-yukari) > tolerans) {
      motor2.step(-35);
  }
  delay(0);

//**************Joystick Kod*****************
int sensorReading = analogRead(A4); // read value from joystick X-axis

  if (sensorReading < 350) { small_stepper.step(1); }   // step left
  if (sensorReading > 575) { small_stepper.step(-1); }  // step right
 
  int sensorReading2 = analogRead(A5); // read value from joystick Y-axis

  if (sensorReading2 < 350) { small_stepper2.step(1); } // step forward
  if (sensorReading2 > 575) { small_stepper2.step(-1); } // step backward
    

}
