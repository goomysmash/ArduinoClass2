int counter = 0; //declaring the integer variable 'counter' and setting it to 0
bool buttonState = true; //declaring the boolean variable buttonState and setting it to true

void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600); //set the Baud rate to 9600hz. You can change this in the bottom right corner of the serial monitor
  pinMode(3, INPUT_PULLUP); //set pin D3 to be an input with a pullup resistor
}

void loop() 
{
  // put your main code here, to run repeatedly:
  //Serial.println(counter); //print the value of the variable 'counter'
  buttonState = digitalRead(3); //read pin 3 then store the value in buttonState
  Serial.println(buttonState); //print the value of buttonState (1 or 0 because it's a boolean)
}
