#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

void setup() {
  Serial.begin(9600);
  Serial.println(" System Ready ");
  mySwitch.enableTransmit(10); // Transmitter is connected to Arduino Pin #10 
  mySwitch.enableReceive(0);  // Receiver on inerrupt 0 => that is pin #2
  mySwitch.setPulseLength(186);  // Optional set pulse length
  
  // Optional set protocol (default is 1, will work for most outlets)
  // mySwitch.setProtocol(2);
  
  // Optional set number of transmission repetitions.
  // mySwitch.setRepeatTransmit(15);
}
void loop() {
    while (Serial.available()) {
        char msg = Serial.read();
        Serial.println(msg);

        switch(msg) {
            case 'a':
                Serial.println(" A On ");
                mySwitch.send("000100000000000000110011");
                break;

            case 'b':
                Serial.println(" A Off ");
                mySwitch.send("000100000000000000111100");
                break;
          
            case 'c':
                Serial.println(" B On ");
                mySwitch.send("000110100000000111000011");
                break;

            case 'd':
                Serial.println(" B Off ");
                mySwitch.send("000110100000000111001100");
                break;
                
            case 'e':
                Serial.println(" C On ");
                mySwitch.send("000110100001011100000011");
                break;

            case 'f':
                Serial.println(" C Off ");
                mySwitch.send("000110100001011100001100");
                break;
            case 'g':
                Serial.println(" D On ");
                mySwitch.send("000110100001110100000011");
                break;

            case 'h':
                Serial.println(" D Off ");
                mySwitch.send("000110100001110100001100");
                break;
          
            case 'i':
                Serial.println(" E On ");
                mySwitch.send("000110110110000100000011");
                break;

            case 'j':
                Serial.println(" E Off ");
                mySwitch.send("000110110110000100001100");
                break; 
                
//blinds start
                case 'k':
                Serial.println(" F On ");
                mySwitch.send("000110100001011111110111");
                break;

            case 'l':
                Serial.println(" F Off ");
                mySwitch.send("000110100001011100001100");
                break;
            case 'm':
                Serial.println(" G On ");
                mySwitch.send("000110100001110111110111");
                break;

            case 'n':
                Serial.println(" G Off ");
                mySwitch.send("000110100001110100001100");
                break;
          
            case 'o':
                Serial.println(" H On ");
                mySwitch.send("000110110110000111110111");
                break;

            case 'p':
                Serial.println(" H Off ");
                mySwitch.send("000110110110000100001100");
                break; 
                
                
        }
        
//    }
//    if (mySwitch.available()) {
//    
//    int value = mySwitch.getReceivedValue();
//    
//    if (value == 0) {
//      Serial.print("Unknown encoding");
//    } else {
//      Serial.print("Received ");
//      Serial.print( mySwitch.getReceivedValue() );
//      Serial.print(" / ");
//      Serial.print( mySwitch.getReceivedBitlength() );
//      Serial.print("bit ");
//      Serial.print("Protocol: ");
//      Serial.print( mySwitch.getReceivedProtocol() );
//    }

    mySwitch.resetAvailable();
  }    
}
