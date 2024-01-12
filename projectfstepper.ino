#include <Stepper.h>
char command;
int setspeed=10;
float acc=2048;
Stepper stepper(acc,8,10,9,11);
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
stepper.setSpeed(setspeed);
}

void loop() {
  // put your main code here, to run repeatedly:
  float ab=0.0;
  float ac=0.0;
  float ad=0.0;
  float ae=0.0;
  float af=0.0;
  float ag=0.0;
 if(Serial.available()) {
  
  command = Serial.read();  
 }
    if(command=='1'){
       ab=(acc*30)/360;
      stepper.step(ab);
    }
  
     else if(command=='2'){
       ac=(acc*60)/360;
      stepper.step(ac);
    }
    
    else if(command=='3'){
       ad=(acc*90)/360;
      stepper.step(ad);
    }
  
      else if(command=='4'){
       ae=(acc*120)/360;
      stepper.step(ae);
    }
 
     else if(command=='5'){
       af=(acc*150)/360;
      stepper.step(af);
    }
  
    else if(command=='6'){
     ag=(acc*180)/360;
      stepper.step(ag);
    }
    else{
      stepper.step(0);
    }
   
 
}
