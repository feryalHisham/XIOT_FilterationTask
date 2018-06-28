#Building the app:
After Reading the task,I did some search to remember how use an interrupt and read a temperature sensor.
I started with the switch and led part:
  I need first to define the pins I will use.
  In the setup, state the pin modes and attach interupt to pin 2.
  Since I will use the serial monitor, I have to start the serial connection in the setup.
  Finally I need to write a function which is the routine called when the interrupt happens.
  This function toggles the Led state.
  Since Serial.print() doesn't work inside the interrupt, I need to call it from the loop() so I defined a boolean
  to be set false by default and set to true when the routine is called.
  
Then the temperature sensor part:
  First read the sensor reading using analogRead()
  Apply the formulas to first convert the reading to voltage.
  Since the sensor reading will be in the range of 0 to 1023 and since the max voltage is 5V.
  Then we multiply by 5 and divide by 1024 to get the reading in voltage.
  Then we want to convert the voltage to temperature this somehow depends on the sensor 
  so I assumed using a sensor that represents each degree change with 10mv change.
  To achieve that the above procedure happens once every 3 seconds, I used millis(), keeping a prevoius time of last reading and        continously asking for the current time if the difference exceeds 3 seconds then read the temperature as above 
  
  
#Language and framework experience 
I used Arduino c. I worked with Arduino on a previous microcontroller project.
It was a team project, we used Arduino as a microcontroller and stepper motors, IR sensor and LCD to make a basketball game.  
