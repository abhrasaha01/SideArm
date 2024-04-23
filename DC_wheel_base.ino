#include <AFMotor.h>   //Download and Install AFMotor.h Library
#include <SoftwareSerial.h>

SoftwareSerial mySerial(9,10);      //bluetooth serial;
/*9 is RX, servo 2
10 is TX, servo 1
also remember that during code upload remove the rx pin or pin 9 also power jumper*/

AF_DCMotor motor1(1); //Front Left Wheel
AF_DCMotor motor2(2); //Back Left Wheel
AF_DCMotor motor3(3); //Back Right Wheel
AF_DCMotor motor4(4); //Front Right Wheel

String readString;

void setup() {
  mySerial.begin(9600);
  motor1.setSpeed(150);   //Set Motor Speed
  motor2.setSpeed(180);
  motor3.setSpeed(165);
  motor4.setSpeed(165);

}

void loop() {
  while(mySerial.available()){
    delay(50);
    char c=mySerial.read();
    readString+=c;
  }
  if(readString.length()>0){
    Serial.println(readString);
    
    if (readString =="FORWARD")      // MOVE FORWARD
    forward();
    
    if (readString =="BACKWARD")     // MOVE BACKWARD
    backward();
    
    if (readString =="LEFT")     // MOVE LEFT SIDE
    left();
    
    if (readString =="RIGHT")     // MOVE RIGHT SIDE
    right();
    
    if (readString =="FORWARDLEFT")     // MOVE FORWARD LEFT
    forwardLeft();
    
    if (readString =="FORWARDRIGHT")     // MOVE FORWARD RIGHT
    forwardRight();
    
    if (readString =="BACKWARDLEFT")     // MOVE BACKWARD LEFT
    backwardLeft();
 
    if (readString =="BACKWARDRIGHT")     // MOVE BACKWARD RIGHT
    backwardRight();
    
    if (readString =="ROTATELEFT")     // ROTATE LEFT SIDE
    rotateLeft();
    
    if (readString =="ROTATERIGHT")     // ROTATE RIGHT SIDE
    rotateRight();
    
    if (readString =="STOP"){     // STOP
    stop();
    }

    readString="";
  }
}


void forward(void){
  motor4.run(FORWARD);
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
}

void backward(void){

  motor4.run(BACKWARD);
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
}

void right(void){

  motor4.run(FORWARD);
  motor1.run(BACKWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);

}

void left(void){

  motor4.run(BACKWARD);
  motor1.run(FORWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  
}

void forwardRight(void){

  motor4.run(FORWARD);
  motor1.run(RELEASE);
  motor2.run(FORWARD);
  motor3.run(RELEASE);
  
}

void forwardLeft(void){

  motor4.run(RELEASE);
  motor1.run(FORWARD);
  motor2.run(RELEASE);
  motor3.run(FORWARD);
  
}

void backwardLeft(void){

  motor4.run(BACKWARD);
  motor1.run(RELEASE);
  motor2.run(BACKWARD);
  motor3.run(RELEASE);
  
}

void backwardRight(void){

  motor4.run(RELEASE);
  motor1.run(BACKWARD);
  motor2.run(RELEASE);
  motor3.run(BACKWARD);

}

void rotateRight(void){
    
  motor4.run (FORWARD);
  motor1.run (BACKWARD);
  motor2.run (BACKWARD);
  motor3.run (FORWARD);

}

void rotateLeft(void){

  motor4.run (BACKWARD);
  motor1.run (FORWARD);
  motor2.run (FORWARD);
  motor3.run (BACKWARD);

}

void stop(void){
  
  motor4.run (RELEASE);
  motor1.run (RELEASE);
  motor2.run (RELEASE);
  motor3.run (RELEASE);

}