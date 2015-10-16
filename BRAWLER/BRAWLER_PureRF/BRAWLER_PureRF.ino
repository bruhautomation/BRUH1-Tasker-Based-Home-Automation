#include <RCSwitch.h>

#include <Servo.h>
RCSwitch mySwitch = RCSwitch();

//pin configuration
int servoPin = 9;

//interger varibles for program

Servo myservo;  // create servo object t control 
int state = 0; //keeps state to not over spin 
int prevstate = 0; //Keeps history of prior state
int dirc = 0;   // continuous servo direction 
int time = 0;  //time to spin that direction
int rxcode;




//main loop
void setup(void) 
{
  Serial.begin(9600);   //Debug via Serial
  mySwitch.enableReceive(0); // Reciever on interrupt 0, that is pin 2
  Serial.println("RF System Ready");

}


void loop(void) {
     if (mySwitch.available()) {
        rxcode = mySwitch.getReceivedValue();
  
  
      if ( rxcode==12345 ) {
      Serial.println("  433MHZ OPEN COMMAND RECEIVED");
      dirc=180; // direction for servo to run
      time=3600; //time for servo to run in, change this variable if you need your servo to rotate longer or shorter
      state=1; //sets state
      }
     else if ( rxcode==54321 ) {
      Serial.println("  433MHZ CLOSE COMMAND RECEIVED");
      dirc=0; // direction for servo to run
      time=3000; //time for servo to run in, change this variable if you need your servo to rotate longer or shorter 
      state=2; //sets state
      }
     else {
       Serial.println(rxcode);      
     }
      mySwitch.resetAvailable();
     }
  
    if (state != prevstate){ //IF state is different from last loop then execute servo controls
      Serial.println("State change!");
      ldr_press();
    } 
      prevstate = state;

}

void ldr_press() { //executes after state change 
  Serial.println("State Change. Rotating Servo");
  myservo.attach(servoPin);
  myservo.write(dirc);
  delay(time);
  myservo.detach();
  
  Serial.println("Returning to main loop");
  return;
 }

