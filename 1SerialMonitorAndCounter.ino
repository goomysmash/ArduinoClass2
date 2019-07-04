int counter = 0; //declaring the integer variable 'counter' and setting it to 0

void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600); //set the Baud rate to 9600hz. You can change this in the bottom right corner of the serial monitor
}

void loop() 
{
  // put your main code here, to run repeatedly:
  Serial.println(counter); //print the value of the variable 'counter'
}
