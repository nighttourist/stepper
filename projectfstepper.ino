#include <Stepper.h>
char command;
int setspeed=15;
float acc=2048;
Stepper stepper(acc,8,10,9,11);
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
stepper.setSpeed(setspeed);
}

void loop() {
  // put your main code here, to run repeatedly:

 while(Serial.available()) {
    float ab=0.0;
  float ac=0.0;
  float ad=0.0;
  float ae=0.0;
  float af=0.0;
  float ag=0.0;
  command = Serial.read();  
 
    if(command=='1'){
       ab=(acc*30)/720;
      stepper.step(ab);
    }
  
     else if(command=='2'){
       ac=(acc*60)/720;
      stepper.step(ac);
    }
    
    else if(command=='3'){
       ad=(acc*90)/720;
      stepper.step(ad);
    }
  
      else if(command=='4'){
       ae=(acc*120)/720;
      stepper.step(ae);
    }
 
     else if(command=='5'){
       af=(acc*150)/720;
      stepper.step(af);
    }
  
    else if(command=='6'){
     ag=(acc*180)/720;
      stepper.step(ag);
    }
    else{
      stepper.step(0);
    }
   
 }
}

  

//   float ab=(acc*30)/360;
//  stepper.step(ab);
//  delay(1000);
// float ac=(acc*60)/360;
//  stepper.step(ac);
//  delay(1000);
// float ad=(acc*90)/360;
//  stepper.step(ad);
//  delay(1000);
//  float ae=(acc*120)/360;
//  stepper.step(ae);
//  delay(1000);
//  float af=(acc*150)/360;
//  stepper.step(af);
//  delay(1000);
//   float ag=(acc*180)/360;
//  stepper.step(ag);
//  delay(1000);
