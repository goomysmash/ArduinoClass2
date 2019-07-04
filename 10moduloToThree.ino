int counter = 0; //declaring the integer variable 'counter' and setting it to 0
bool buttonState = true; //declaring the boolean variable buttonState and setting it to true
bool prevButtonState = true; //declaring the boolean variable for the previous button state and setting it to true

void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600); //set the Baud rate to 9600hz. You can change this in the bottom right corner of the serial monitor
  pinMode(3, INPUT_PULLUP); //set pin D3 to be an input with a pullup resistor

  //The following is copied from Module 1:
  //////////////////////////////////////////////////////////////////////////////
  pinMode(13, OUTPUT); //set pin 13 (the built in LED) to be an output  

  //set up the 3 LEDs to be outputs
  pinMode(5, OUTPUT); //LED 1
  pinMode(8, OUTPUT); //LED 2
  pinMode(11, OUTPUT); //LED 3

  //set up the 3 ground pins for the LEDs
  pinMode(4, OUTPUT); //Ground for LED 1
  pinMode(7, OUTPUT); //Ground for LED 2
  pinMode(10, OUTPUT); //Ground for LED 3

  //set up the ground pins for the 3 LEDs
  digitalWrite(4, LOW); //Ground for LED 1 gets set low
  digitalWrite(7, LOW); //Ground for LED 2 gets set low
  digitalWrite(10, LOW); //Ground for LED 3 gets set low
  ///////////////////////////////////////////////////////////////////////////////
}

void loop() 
{
  // put your main code here, to run repeatedly:
  //Serial.println(counter); //print the value of the variable 'counter'

  prevButtonState = buttonState; //update the prevButtonState
//  Serial.print("prevButtonState: "); //so in the serial monitor we know what we're looking at
//  Serial.println(prevButtonState); //print the value of prevButtonState (1 or 0 because it's a boolean)

  buttonState = digitalRead(3); //read pin 3 then store the value in buttonState
//  Serial.print("buttonState: "); //so in the serial monitor we know what we're looking at
//  Serial.println(buttonState); //print the value of buttonState (1 or 0 because it's a boolean)

  if(prevButtonState == 1 && buttonState == 0) //if the previous state was a 1/HIGH/5v AND the current state is a 0/LOW/0v, a falling edge happened
  { //if the statement is true, do what is in these curly brackets
    counter = counter + 1; //increment the counter variable
    counter = counter % 3; //modulo operator, counter can only count to 3
    Serial.print("counter: "); //print out this so we know what we're looking at
    Serial.println(counter, BIN); //print the value of the counter variable in binary

    //if the counter is at 1, turn on LED 1 (pin 5)
    if (counter == 1)
    {
      digitalWrite(5, HIGH);
    }
    else
    {
      digitalWrite(5, LOW);
    }
    
    //if the counter is at 2, turn on LED 2 (pin 8)
    if (counter == 2)
    {
      digitalWrite(8, HIGH);
    }
    else
    {
      digitalWrite(8, LOW);
    }

    //if the counter is at 3, turn on LED 3 (pin 11)
    if (counter == 3)
    {
      digitalWrite(11, HIGH);
    }
    else
    {
      digitalWrite(11, LOW);
    }


  }
}
