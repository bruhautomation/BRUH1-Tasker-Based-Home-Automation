#include <RCSwitch.h>

#include <Servo.h>
RCSwitch mySwitch = RCSwitch();

//pin configuration
int servoPin = 9;
int photocellPin = A0; //in analog pin 
const int button1_pin = 4;
const int button2_pin = 3;

//interger varibles for program

Servo myservo;  // create servo object t control 
int photocellReading; // the analog reading from light depended resistor
int button1_value;  //high or low button values
int button2_value; //high or low button value
int state; //keeps state to not over spin 
int prevstate = 0; //Keeps history of prior state
int sensorValue = 0;  // stores LDR value
int dirc = 0;   // continuous servo direction 
int time = 0;  //time to spin that direction
int blindstatus;
int rxcode;




//main loop
void setup(void) 
{
  Serial.begin(9600);   //Debug via Serial
  mySwitch.enableReceive(0); // Reciever on interrupt 0, that is pin 2
  Serial.println("Start Up ");
  myservo.attach(servoPin);   // Attach servo to servoPin
  pinMode(button1_pin, INPUT);  //sets button 1 pin as input
  pinMode(button2_pin, INPUT);  //sets button 2 pin as input
  //pinMode(killswitch, INPUT);   //sets kill swtich as input
}


void loop(void) {
  button1_value = digitalRead(button1_pin);  //reads value of button1_pin
  button2_value = digitalRead(button2_pin);  //reads value of button2_pin
  photocellReading = analogRead(photocellPin); //Query LDR
    Serial.println("Light Reading :");  
    Serial.println(photocellReading); // Prints raw analog reading from LDR
    Serial.println("State:  ");
    Serial.println(state); // prints the the current state

    //Define modes based on bightness and set corresponding servo direction and time
    if (mySwitch.available()) {
        rxcode = mySwitch.getReceivedValue();
    }
    if (rxcode==12345) {
      Serial.println("  433MHZ TEMP OPEN COMMAND RECEIVED");
      dirc=180; // direction for servo to run
      time=3600; //time for servo to run in, change this variable if you need your servo to rotate longer or shorter
      state=1; //sets state
      Serial.println( "Setting blindstatus to 1, opened" );
      blindstatus = 1;
      rxcode = 0;
      }
    else if (rxcode==54321) {
      Serial.println("  433MHZ TEMP CLOSE COMMAND RECEIVED");
      dirc=0; // direction for servo to run
      time=3000; //time for servo to run in, change this variable if you need your servo to rotate longer or shorter 
      state=2; //sets state
      Serial.println( "Setting blindstatus to 2, closed" );
      blindstatus = 2;
      rxcode = 0;
      }      
    else if (button1_value==HIGH) {
      Serial.println("  DAY button 1 pushed");
      dirc=180; // direction for servo to run
      time=3600; //time for servo to run in, change this variable if you need your servo to rotate longer or shorter
      state=1; //sets state
      }
    else if (button2_value==HIGH) {
      Serial.println("  NIGHT button 2 pushed");
      dirc=0; // direction for servo to run
      time=3000; //time for servo to run in, change this variable if you need your servo to rotate longer or shorter 
      state=2; //sets state
  }
      else if (photocellReading > 500) {
      Serial.println("DAY Light Sensor");
      dirc=180; // direction for servo to run
      time=3600; //time for servo to run in, , change this variable if you need your servo to rotate longer or shorter 
      state=1; //sets state
    } 
    else if (photocellReading < 500) {
      Serial.println("NIGHT Light Sensor");
      dirc=0; // direction for servo to run
      time=3000; //time for servo to run in, , change this variable if you need your servo to rotate longer or shorter 
      state=2; //sets state;
    }
  else {
    Serial.println("Buttons are not pushed and photocell not working. This shouldn't be happening.");
    return;
  } 
  

  if (state != prevstate){ //IF the photocell reading is different from last sample then execute servo controls
    ldr_press();
    }
  mySwitch.resetAvailable();  
  prevstate = state;

}

void ldr_press() { //executes after photocell reads
  Serial.println("State Change. Rotating Servo");
  myservo.attach(servoPin);
  myservo.write(dirc);
  delay(time);
  myservo.detach();
  Serial.println("starting main delay");
  delay(300000);  //change this to 900000 if you want 15 minutes between cycle
  
  while(blindstatus == 1 || blindstatus == 2){
    Serial.println("Waiting for RF command ");
    if (mySwitch.available()) {
       rxcode = mySwitch.getReceivedValue();
    }
    if(blindstatus == 1 && rxcode==12345) {
      blindstatus = 0;
      rxcode = 0;
      Serial.println("waiting for a second");
      delay(1000);
      Serial.println("blind status = 0 reason a ");
    }
    else if(blindstatus == 2 && rxcode==54321) {
      blindstatus = 0;
      rxcode = 0;
      Serial.println("waiting for a second");
      delay(1000);
      Serial.println("blind status = 0 because reason b ");
    }
    else {
      Serial.println("blindstatus is not zero. Waiting in while loop. "); 
    }
  }
  
return;
 }

