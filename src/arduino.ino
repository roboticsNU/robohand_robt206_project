#include <medianFilter.h>
#include <Servo.h>

medianFilter Filter1, Filter2, Filter3;

// Constants:
const int flexPin1 = A0; //pin A0 to read analog inputasd
const int flexPin2 = A1; //pin A1 to read analog inputasd
const int flexPin3 = A2; //pin A2 to read analog inputasd
Servo myservo1, myservo2,myservo3;  // create servo objects to control a servo
// Variables:
int value1 = 0, value2 = 0, value3 = 0; //save analog value
  
void setup(){
  Serial.begin(9600);//Begin serial communication
  // Start filtering instances
  Filter1.begin();
  Filter2.begin();
  Filter3.begin();
  myservo1.attach(7);
  myservo2.attach(8);
  myservo3.attach(9);
}
void loop(){
  /* Read and save analog values from flex sensors */
  value1 = analogRead(flexPin1);
  value2 = analogRead(flexPin2);         
  value3 = analogRead(flexPin3);
  /* Process values through filters */
  value1 = Filter1.run(value1);
  value2 = Filter2.run(value2);
  value3 = Filter3.run(value3);
  //Serial.println(value1);
  //Serial.println(value2);
  
  /* Map sensor values so that they could move servos */
  int val1 = map(value1, 800, 960, 0, 180);
  val1 = constrain(val1, 0, 180);
  int val2 =  map(value2, 680, 800,0, 180);
  val2 = constrain(val2, 0, 180);
  int val3 =  map(value3, 880, 920, 0, 180);
  val3 = constrain(val3, 0, 180);
  /* 
    Print data to the serial in the proper format, 
    so that we could read data to Blender
  */
  Serial.print(val1);
  Serial.print(" ");
  Serial.print(val2);
  Serial.print(" ");
  Serial.print(val3);
  Serial.print("\n");
  /* Tell servos to move */
  myservo3.write(val3);
  myservo2.write(val2);
  myservo1.write(val1);
  delay(100); //Small delay
}

