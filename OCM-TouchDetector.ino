#include <Mouse.h>

#define NO_TOUCH 200
#define FSR_RIGHT_PIN A0
#define FSR_LEFT_PIN A1


int fsrReadingLeft;
int fsrReadingRight;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Mouse.begin();
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(6, OUTPUT);


}

void loop() {
  // put your main code here, to run repeatedly:
  fsrReadingLeft = analogRead(FSR_LEFT_PIN);
  fsrReadingRight = analogRead(FSR_RIGHT_PIN);
  /*Serial.print("Analog Left Value = ");
  Serial.println(fsrReadingLeft);
  Serial.print("Analog Right Value = ");
  Serial.println(fsrReadingRight);*/

  bool flag = true;
  if(fsrReadingLeft > NO_TOUCH)
  {
      Mouse.press();
      digitalWrite(LED_BUILTIN, HIGH);
      digitalWrite(6, HIGH);
      Serial.print("Analog Left Value = ");
      Serial.println(fsrReadingLeft);
      delay(50);
      while(fsrReadingLeft > NO_TOUCH)
      {
          fsrReadingLeft = analogRead(FSR_LEFT_PIN);
       }
       Mouse.release();
       digitalWrite(LED_BUILTIN, LOW);
       digitalWrite(6, LOW);
      
  }
   if (fsrReadingRight > NO_TOUCH)
  {
    Mouse.click(MOUSE_RIGHT);//Single Right Click
    digitalWrite(6, HIGH);
    delay(50);
    digitalWrite(6, LOW);
  }
  
  
}
