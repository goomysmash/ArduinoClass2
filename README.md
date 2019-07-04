## Class 2: Programming a clicker counter
### 1. Attach serial monitor and counter variables
- New code lines:
  - `int counter = 0;`
  - `Serial.begin(9600);`
  - `Serial.println(counter);`
- (Upload and watch serial monitor)
### 2. Attach button, buttonState variable, read and print button state
- New code lines:
  - `bool buttonState = true;`
  - `pinMode(3, INPUT_PULLUP);`
  - `buttonState = digitalRead(3);`
  - `Serial.println(buttonState);`
- (Upload and watch serial monitor, click button)
### 3. Make previous button state variable, print both the previous and current button state
- New code lines:
  - `bool prevButtonState = true;`
  - `Serial.print("buttonState: ");`
  - `prevButtonState = buttonState;`
  - `Serial.print("prevButtonState: ");`
  - `Serial.println(prevButtonState);`
- (Upload and watch serial monitor, click button)
### 4. Make an if statement for a falling edge (previous state = 1 and current state = 0) that increments and prints a counter
- New code lines:
  - `if(prevButtonState==1 && buttonState==0)`
  - `{counter = counter+1;`
  - `Serial.print("counter: ");`
  - `Serial.println(counter);}`
- (Upload and watch serial monitor and click button)
- (counter doesn't increment in Serial monitor like it should, time to debug)
### 5. Debug why the counter isn't working. Switch the order of the code.
- Switch the order of the lines of code so they go in the order:
  1. `prevButtonState = buttonState;`
  2. `buttonState = digitalRead(3);`
- (Upload and watch serial monitor and click button)
- (Serial monitor properly increments now)
### 6. Attach output LEDs
- New code lines:
  - `pinMode(13, OUTPUT); //set pin 13 (the built in LED) to be an output`
  - `pinMode(5, OUTPUT); //LED 1`
  - `pinMode(8, OUTPUT); //LED 2`
  - `pinMode(11, OUTPUT); //LED 3`
  - `pinMode(4, OUTPUT); //Ground for LED 1`
  - `pinMode(7, OUTPUT); //Ground for LED 2`
  - `pinMode(10, OUTPUT); //Ground for LED 3`
  - `digitalWrite(4, LOW); //Ground for LED 1 gets set low`
  - `digitalWrite(7, LOW); //Ground for LED 2 gets set low`
  - `digitalWrite(10, LOW); //Ground for LED 3 gets set low`
### 7. Use the modulo operator to only count to 16
- New code lines:
  - `counter = counter % 16;`
- (Upload and watch serial monitor, click past 16)
### 8. Serial print the counter in binary
- New code lines:
  - `Serial.println(counter, BIN);`
- (Upload and watch serial monitor, click past 16)
- counter is now represented in binary instead of decimal
### 9. Add if statements to turn on LEDs (can only count to 3, simple version)
- New code lines:
  - `if (counter == 1){digitalWrite(5, HIGH);}`
  - `else{digitalWrite(5, LOW);}`
  - `if (counter == 2){digitalWrite(8, HIGH);}`
  - `else{digitalWrite(8, LOW);}`
  - `if (counter == 3){digitalWrite(11, HIGH);}`
  - `else{digitalWrite(11, LOW);}`
- (Upload and watch LEDs, click a few times)
- 16 is too high of a number since we're only counting to 3
### 10. Change the modulo operator to 3
- Modify this line and change it to %3 instead of %16
  - `counter = counter % 3;`
- (Upload and watch LEDs, click a few times)
- The 3rd LED doesn't light up
- Always remember computers like to count from 0, not 1
### 11. Debug why it doesn't work (counted from 1 instead of from 0)
- Modify the the if conditionals to the following
  - `if (counter == 0){digitalWrite(5, HIGH);}`
  - `else{digitalWrite(5, LOW);}`
  - `if (counter == 1){digitalWrite(8, HIGH);}`
  - `else{digitalWrite(8, LOW);}`
  - `if (counter == 2){digitalWrite(11, HIGH);}`
  - `else{digitalWrite(11, LOW);}`
- (Upload and watch LEDs, click a few times)
- It works, but can only count to 3. We can count to 8 if we use binary
### 12. Add bit read, change modulo to 8, print each bit
- Modify this line and change it to %8 instead of %3
  - `counter = counter % 8;`
- New code lines:
  - `Serial.print("bitRead(counter, 0): ");`
  - `Serial.println(bitRead(counter, 0));`
  - `Serial.print("bitRead(counter, 1): ");`
  - `Serial.println(bitRead(counter, 1));`
  - `Serial.print("bitRead(counter, 2): ");`
  - `Serial.println(bitRead(counter, 2));`
- (Upload and watch serial monitor, click a few times)
- Notce how the bitRead matches the binary print of the counter variable
### 13. Uncomment and add if statements to turn on LEDs based on each bit to count to 8
- New code lines:
  - `if(bitRead(counter, 0) == 1){digitalWrite(5, HIGH);}`
  - `else{digitalWrite(5, LOW);}`
  - `if(bitRead(counter, 1) == 1){digitalWrite(8, HIGH);}`
  - `else{digitalWrite(8, LOW);}`
  - `if(bitRead(counter, 2) == 1){digitalWrite(11, HIGH);}`
  - `else{digitalWrite(11, LOW);}`
- (Upload and watch LEDs, click past 8)
- Now our clicker can count up to 8 with only 3 LEDs

### Problems:
- Push button bounces which causes skips sometimes
- We will debounce the push button in a future class
