/*Test with hygrometer*/

//Analog pin assignments
#define MOISTURE_PIN 2 //A2

int moistureSensorValue;

void setup() {
Serial.begin(9600);
}


void loop() {
moistureSensorValue = analogRead(MOISTURE_PIN);
            //moistureSensorValue = 650;  //for testing
            if(moistureSensorValue >= 700){ //Dry
              //j = 0;
              Serial.println("Dry");
            }
            if((moistureSensorValue < 700) && (moistureSensorValue >= 300)){ //Moist
              //j = 1;
              Serial.println("Moist");
            }
            if(moistureSensorValue < 300){ //Soggy
              //j = 2;
              Serial.println("Soggy");
            }

Serial.println(moistureSensorValue);
Serial.print("\n");
delay(10000); 
}
