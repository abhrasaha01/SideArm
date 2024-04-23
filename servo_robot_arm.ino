#include <Adafruit_PWMServoDriver.h>
#include <Wire.h>

#define BLYNK_TEMPLATE_ID "TMPL3FHDCFeml"
#define BLYNK_TEMPLATE_NAME "Servo Control"
#define BLYNK_AUTH_TOKEN "JzzuJvHyy6FcLlF6SmXRZS2pL-BNRvnb"

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define hardmin 600
#define hardmax 2600

Adafruit_PWMServoDriver driver = Adafruit_PWMServoDriver(0x40);

char ssid[] = "****"; // Change your Wifi/ Hotspot Name
char pass[] = "****"; // Change your Wifi/ Hotspot Password

int s00, s11, s22, s33, s44 = 0;

int angleToPulse(int angle){
  int digit = map(angle,0,180,hardmin,hardmax);       // degree to digital
  int pulse = int(float(digit)/1000000*50*4096);      // pulse in accordance to servo
  Serial.print("\n Angle:");Serial.print(angle);
  Serial.print("\n pulse:");Serial.print(pulse);
  return pulse;
}

BLYNK_WRITE(V0)
{
  int s0 = param.asInt();                   //input received from blynk interface
  Blynk.virtualWrite(V1, s0);
  if(s00 < s0){                             //if prev < current increase angle
    while(s00 < s0){
      driver.setPWM(0, 0, angleToPulse(s00-30));  //changes angle by 1 degree at a time
      delay(1);
      s00++;
    }
  }
  else{                                     //if prev > current decrease angle
    while(s00 > s0){
      driver.setPWM(0, 0, angleToPulse(s00-30));
      delay(1);
      s00--;
    }
  }
}

BLYNK_WRITE(V2)
{
  int s1 = param.asInt();
  Blynk.virtualWrite(V3, s1);                   //input received from blynk interface
  if(s11 < s1){                             //if prev < current increase angle
    while(s11 < s1){
      driver.setPWM(1, 0, angleToPulse(s11));  //changes angle by 1 degree at a time
      delay(1);
      s11++;
    }
  }
  else{                                     //if prev > current decrease angle
    while(s11 > s1){
      driver.setPWM(1, 0, angleToPulse(s11));
      delay(1);
      s11--;
    }
  }
}

BLYNK_WRITE(V4)
{
  int s2 = param.asInt();
  Blynk.virtualWrite(V5, s2);                   //input received from blynk interface
  if(s22 < s2){                             //if prev < current increase angle
    while(s22 < s2){
      driver.setPWM(2, 0, angleToPulse(s22));  //changes angle by 1 degree at a time
      delay(1);
      s22++;
    }
  }
  else{                                     //if prev > current decrease angle
    while(s22 > s2){
      driver.setPWM(2, 0, angleToPulse(s22));
      delay(1);
      s22--;
    }
  }
}
BLYNK_WRITE(V6)
{
  int s3 = param.asInt();
  Blynk.virtualWrite(V7, s3);                   //input received from blynk interface
  if(s33 < s3){                             //if prev < current increase angle
    while(s33 < s3){
      driver.setPWM(3, 0, angleToPulse(s33));  //changes angle by 1 degree at a time
      delay(1);
      s33++;
    }
  }
  else{                                     //if prev > current decrease angle
    while(s33 > s3){
      driver.setPWM(3, 0, angleToPulse(s33));
      delay(1);
      s33--;
    }
  }
}
BLYNK_WRITE(V8)
{
  int s4 = param.asInt();
  Blynk.virtualWrite(V9, s4);                   //input received from blynk interface
  if(s44 < s4){                             //if prev < current increase angle
    while(s44 < s4){
      driver.setPWM(4, 0, angleToPulse(s44));  //changes angle by 1 degree at a time
      delay(1);
      s44++;
    }
  }
  else{                                     //if prev > current decrease angle
    while(s44 > s4){
      driver.setPWM(4, 0, angleToPulse(s44));
      delay(1);
      s44--;
    }
  }
}

void setup()
{
  Serial.begin(9600);
  driver.begin();
  driver.setPWMFreq(50);
  
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);//Splash screen delay 
}

void loop() 
{
  Blynk.run();

}


