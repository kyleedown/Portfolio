int Pin0 = 11;
int Pin1 = 10;
int Pin2 = 9;
int Pin3 = 8;

#include <LiquidCrystal.h>
int lightPin=A0;

  int lightReading =0;

LiquidCrystal lcd(2,3,4,5,6,7);

int _step = 512;
int _speed = 1;

void setup() {
  pinMode(Pin0, OUTPUT);
  pinMode(Pin1, OUTPUT);
  pinMode(Pin2, OUTPUT);
  pinMode(Pin3, OUTPUT);
  // put your setup code here, to run once:
  lcd.begin(16,2);
  Serial.begin(9600);
  

}
int isOn;

void loop() {
  
  int lightReading =0;
  lightReading = analogRead(lightPin);
  Serial.println(lightReading);
  delay(2);
  if (lightReading > 265) {
    if (isOn != 1) {
      isOn = 1;
    lcd.setCursor(0,0);
    lcd.print("Good Morning! ");
    Speed(15);
    Step(512);
    delay(2000);
    }
  }
  else {
    if (isOn != 0) {
      isOn = 0;
    lcd.clear();
    lcd.print("Good Night! ");
    Speed(15);
    Step(-512);
    delay(2000);
    }
  }


  

}

void Speed(int stepperspeed){
  _speed = 15 - stepperspeed;
  if(_speed<1){
    _speed=1;
  }
  if(_speed>15){
    _speed = 15;
  }
}

void Step(int _step){
  if(_step>=0){
    for(int i=0;i<_step;i++){
      setStep(1,0,0,1);
      delay(_speed);
      setStep(1,0,0,0);
      delay(_speed);
      setStep(1,1,0,0);
      delay(_speed);
      setStep(0,1,0,1);
      delay(_speed);
      setStep(0,1,1,0);
      delay(_speed);
      setStep(0,0,1,0);
      delay(_speed);
      setStep(0,0,1,1);
      delay(_speed);
      setStep(0,0,0,1);
      delay(_speed);
    }
  }
  else{
    for(int i=_step;i<0;i++){
      setStep(0,0,0,1);
      delay(_speed);
      setStep(0,0,1,1);
      delay(_speed);
      setStep(0,0,1,0);
      delay(_speed);
      setStep(0,1,1,0);
      delay(_speed);
      setStep(0,1,0,0);
      delay(_speed);
      setStep(1,1,0,0);
      delay(_speed);
      setStep(1,0,0,0);
      delay(_speed);
      setStep(1,0,0,1);
      delay(_speed);
    }
  }
}

void setStep(int a, int b, int c, int d){
  digitalWrite(Pin0, a);
  digitalWrite(Pin1, b);
  digitalWrite(Pin2, c);
  digitalWrite(Pin3, d);
}