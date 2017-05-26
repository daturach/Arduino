//Schmitt trigger
// Updated 9 août 2016, added output for Wemos board
// Updated 1 november 2016: changed upper and lower voltage
//#define ON 1
//#define OFF 0
//#define OBEREGRENZE 361  // set upper level voltage (1.8V) 
//#define UNTEREGRENZE 321 //set lower level voltage (1.6V)
#define OBEREGRENZE 450  // set upper level voltage (2.2V) 
#define UNTEREGRENZE 409 //set lower level voltage (2.0V)

int sensorPin = A0;
int sensorValue = 0;
int triggerPin = 2;
int triggerPinWemos = 3;
int LEDPin = 13;

void setup() {
    pinMode (triggerPin, OUTPUT);
    pinMode (triggerPinWemos, OUTPUT);
    digitalWrite(triggerPinWemos, LOW);
    pinMode (LEDPin, OUTPUT);
}

void loop() {
    //int status = ON;
    digitalWrite(triggerPin, HIGH);
    digitalWrite(LEDPin, LOW);
 //   sensorValue = analogRead(sensorPin);
    while (true) {
        sensorValue = analogRead(sensorPin);
        delay(1);        // delay in between reads for stability
        if (sensorValue > OBEREGRENZE)
        {
           digitalWrite(triggerPin, LOW);
           digitalWrite(triggerPinWemos, HIGH); //Wemos will be resetted
           delay(1);
           digitalWrite(LEDPin, HIGH);
           delay(50);
           //status = OFF;
        }
        if (sensorValue < UNTEREGRENZE)
        {
           digitalWrite(triggerPin, HIGH);
           digitalWrite(triggerPinWemos, LOW); //data will be sent to server because reset is released
           delay(1);
           digitalWrite(LEDPin, LOW);
           delay(50);
           //status = ON;
        }
     }
}
