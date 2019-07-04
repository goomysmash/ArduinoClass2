# Module 2: Programming a clicker counter
## 1. Attach serial monitor and counter variables
- New code lines:
  - `int counter = 0;`
  - `Serial.begin(9600);`
  - `Serial.println(counter);`
- (Upload and watch serial monitor)
## 2. Attach button, buttonState variable, read and print button state
- New code lines:
  - `bool buttonState = true;`
  - `pinMode(3, INPUT_PULLUP);`
  - `buttonState = digitalRead(3);`
  - `Serial.println(buttonState);`
- (Upload and watch serial monitor)
## 3. Make previous button state variable, print both the previous and current button state
- New code lines:
  - `bool prevButtonState = true;`
  - `Serial.print("buttonState: ");`
  - `prevButtonState = buttonState;`
  - `Serial.print("prevButtonState: ");`
  - `Serial.println(prevButtonState);`
- (Upload and watch serial monitor)
## 4. Make an if statement for a falling edge (previous state = 1 and current state = 0) that increments and prints a counter
## 5. Debug why the counter isn't working. Switch the order of the code.
## 6. Attach output LEDs
## 7. Use the modulo operator to only count to 16
## 8. Serial print the counter in binary
## 9. Add if statements to turn on LEDs (only count to 3, simple version)
## 10. Change the modulo operator to 3
## 11. Debug why it doesn't work (counted from 1 instead of from 0)
## 12. Add bit read, change modulo to 8, print each bit
## 13. Add if statements to turn on LEDs based on each bit to count to 8
## Problems:
- push button bounces
