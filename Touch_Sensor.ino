const int TOUCH_SENSOR_PIN0  = 3;// Arduino pin connected to touch sensor's pin
const int TOUCH_SENSOR_PIN1  = 4;
const int TOUCH_SENSOR_PIN2  = 5;
const int TOUCH_SENSOR_PIN3  = 6;
const int LED_PIN           = 7;// Arduino pin connected to LED's pin
const int RELAY_PIN0         = 8;
const int RELAY_PIN1         = 9;
const int RELAY_PIN2         = 10;
const int RELAY_PIN3         = 11;

// variables will change:
int ledState = LOW;    // the current state of LED
int lastTouchState;    // the previous state of touch sensor
int currentTouchState; // the current state of touch sensor

void setup() {
  Serial.begin(9600);               // initialize serial
  pinMode(TOUCH_SENSOR_PIN0, INPUT); // set arduino pin to input mode
  pinMode(LED_PIN, OUTPUT);         // set arduino pin to output mode

  currentTouchState = digitalRead(TOUCH_SENSOR_PIN);
}

void loop() {
  lastTouchState    = currentTouchState;             // save the last state
  currentTouchState = digitalRead(TOUCH_SENSOR_PIN); // read new state

  if(lastTouchState == LOW && currentTouchState == HIGH) {
    Serial.println("The sensor is touched");

    // toggle state of LED
    ledState = !ledState;

    // control LED arccoding to the toggled state
    digitalWrite(LED_PIN, ledState);
  }
}
