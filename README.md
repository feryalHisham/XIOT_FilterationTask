# XIOT_FiltrationTask
#to assemble the ciruit we can use arduino Uno board, a temperature sensor and a switch:
connect the temperature sensor output pin to analog in pin 0 on arduino board and connect its ground and VCC pin to GND pin and 5V pin respectively.
connect the switch with the same approach as the temperature sensor such that all grounds and VCC are the same, the switch aoutput is connected to pin 2 (one of the interrupt pins).
In the code I used pin 13 to use Arduino board's LED, so we don't need any further components.

#Assumptions:
I assumed that printing "pressed" is done in case of any change in the switch, I was confused whether "pressed" means that the switch is toggled to force the LED ON or any toggle.

