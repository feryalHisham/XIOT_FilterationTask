
const byte ledPin = 13;    // to use Arduino's LED
const byte interruptPin = 2;  // any of the interrupt pins will work (I choose 2)
volatile byte ledState = LOW; // at the begining of the run the led is OFF
bool calledISR= false;  //switch to true when switchLedISR function is called then set to false again when printing (needed for correct printing)


const byte temperaturePin = 0; // 0 Analog IN pin
long previousMillis = 0;        // saves last time temperarure sensor was read
long interval = 3000;           // 3 seconds interval from temperature reading to another


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);  //Start the serial connection with the computer
  
  // setting the pin mode for the ledPin and interruptPin
  pinMode(ledPin, OUTPUT);
  pinMode(interruptPin, INPUT);
  
  // attachInterupt to specify which function to be called (switchLedISR) and when(CHANGE in the state of the interruptPin)
  attachInterrupt(digitalPinToInterrupt(interruptPin), switchLedISR, CHANGE);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  digitalWrite(ledPin, ledState);
  
  //if the switch is pressed then an interrupt has happened and switchLedISR function is called
  if(calledISR == true){
    calledISR = false; // to print only one time
    printLedState();
    
  }
  
  //get current time using millis()
  unsigned long currentMillis = millis();
  
 // read the temperature sensor every 3 seconds 
  if(currentMillis - previousMillis > interval) {
    // save the last time the sensor was read 
    previousMillis = currentMillis; 
    
    readTemp();
  
  }

}

void switchLedISR(){
  
  calledISR = true; 
  ledState = !ledState; // toggle the led state
  
}


// reads from the sensor, converts the reading to voltage and calculates the corresponding temperature to print it
void readTemp(){
  
  
   //getting the voltage reading from the temperature sensor
   int tempSensorReading = analogRead(temperaturePin);  
 
   // converting that reading to voltage, for using a 5V Arduino with 10-bit analog reading
   float voltage = tempSensorReading * 5.0;
   voltage /= 1024.0; 
 
   // print out the temperature
   float temperatureC = (voltage - 0.5) * 100 ;  //converting from 10 mv per degree to degrees ((voltage) times 100)
   
   Serial.print(temperatureC); 
   Serial.println(" degrees C");
}

//prints that the switch was pressed and the LED state
void printLedState(){
  
  Serial.println("Switch Pressed");
    
    Serial.print("Led is ");
    if (ledState == LOW)
    Serial.println("OFF");
    else 
    Serial.println("ON");
  
}

