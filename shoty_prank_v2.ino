#include <Servo.h>
const int trig =10;
const int echo =9;
const int inc = 4;
const int dec =5;
const int delBut=7;
long duration;
int distance;
int var =50;

const int light=LED_BUILTIN;
boolean del=false;

Servo shot;
void setup() {
  // put your setup code here, to run once:
pinMode(trig,OUTPUT);
pinMode(echo,INPUT);

Serial.begin(9600);
shot.attach(3);
pinMode(inc, INPUT);
pinMode(dec, INPUT);
pinMode(light,OUTPUT);
pinMode(delBut,INPUT);

}

void loop() {
shot.write(0);
if(digitalRead(inc)==HIGH){

  if(var<500){
  var=var+10;
 delay(100);
  }
}
if(digitalRead(dec)==HIGH){

  if(var>10){
     var=var-10;
  delay(100);
 
  }
    
}
if(digitalRead(delBut)==HIGH){
  Serial.println("started");
  delay(5000);
 
  del=true;
}
if(digitalRead(dec)==LOW&& digitalRead(inc)==LOW){
  var=var+0;
}
digitalWrite(trig,LOW);
delayMicroseconds(2);
digitalWrite(trig,HIGH);
delayMicroseconds(10);

digitalWrite(trig,LOW);

duration=pulseIn(echo,HIGH);
distance=duration*0.034/2;
Serial.println(distance);
if(distance<=var){
shoty();
digitalWrite(light,HIGH);
}else{
  digitalWrite(light,LOW);

}



}
void shoty(){
  if(del==true){
del=false;
      delay(500);
  shot.write(45);
  delay(500);
   shot.write(0);
 Serial.print("work" );
 

  }
}
