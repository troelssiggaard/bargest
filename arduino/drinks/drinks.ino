  /* Includes */
//#include <Adafruit_NeoPixel.h>

//#define LED_PIN 48
//Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, LED_PIN, NEO_GRB + NEO_KHZ800);

/* Define inputs & outputs */
int suckingFactor = 110;
int mL = 20;
boolean testMotors = false;

// Drink motors defined from left to right (looking at the bar-robot)
int motor1 = 42;
int motor2 = 40;
int motor3 = 38;
int motor4 = 36;
int motor5 = 34;
int motor6 = 32;
int motor7 = 30;
int motor8 = 28;
int motor9 = 26;
int motor10 = 24;
int motor11 = 22;

// Stepper1 might be back & Stepper2 might be forward
int stepperDir = 2; //yellow wire
int stepperStep = 3; //white wire
int distance = 0;



void setup() {
  
  /* Stepper motor */ 
  pinMode(stepperDir, OUTPUT);
  pinMode(stepperStep, OUTPUT);
  digitalWrite(stepperDir, LOW);
  digitalWrite(stepperStep, LOW);
  
  /* Define Drink Motors as output */
  pinMode(motor1,OUTPUT);
  pinMode(motor2,OUTPUT);
  pinMode(motor3,OUTPUT);
  pinMode(motor4,OUTPUT);
  pinMode(motor5,OUTPUT);
  pinMode(motor6,OUTPUT);
  pinMode(motor7,OUTPUT);
  pinMode(motor8,OUTPUT);
  pinMode(motor9,OUTPUT);
  pinMode(motor10,OUTPUT);
  pinMode(motor11,OUTPUT);

  /* LED Strip 
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
*/
}


void loop(){ 

  //rainbowCycle(20);  // Test the LED strip showing all 'rainbow' colors
  
  //startDrinkMotors();  // Test method to test all drink motors

  startStepperMotor();  // Test stepper motor (check if the 12V adapter can deliver at least 2Amp)
  
}


/* Drink motors test method */
void startDrinkMotors() {
      
    // Drink Motor 1
    digitalWrite(motor1, HIGH);
    delay(mL * suckingFactor);  // 2 CL delay time
    digitalWrite(motor1, LOW);
    delay(1000);
    
    // Drink Motor 2
    digitalWrite(motor2, HIGH);
    delay(mL * suckingFactor);  // 2 CL delay time
    digitalWrite(motor2, LOW);
    delay(1000);
    
    // Drink Motor 3
    digitalWrite(motor3, HIGH);
    delay(mL * suckingFactor);  // 2 CL delay time
    digitalWrite(motor3, LOW);
    delay(1000);
    
    // Drink Motor 4
    digitalWrite(motor4, HIGH);
    delay(mL * suckingFactor);  // 2 CL delay time
    digitalWrite(motor4, LOW);
    delay(1000);
    
    // Drink Motor 5
    digitalWrite(motor5, HIGH);
    delay(mL * suckingFactor);  // 2 CL delay time
    digitalWrite(motor5, LOW);
    delay(1000);
    
    // Drink Motor 6
    digitalWrite(motor6, HIGH);
    delay(mL * suckingFactor);  // 2 CL delay time
    digitalWrite(motor6, LOW);
    delay(1000);
    
    // Drink Motor 7
    digitalWrite(motor7, HIGH);
    delay(mL * suckingFactor);  // 2 CL delay time
    digitalWrite(motor7, LOW);
    delay(1000);
    
    // Drink Motor 8
    digitalWrite(motor8, HIGH);
    delay(mL * suckingFactor);  // 2 CL delay time
    digitalWrite(motor8, LOW);
    delay(1000);
    
    // Drink Motor 9
    digitalWrite(motor9, HIGH);
    delay(mL * suckingFactor);  // 2 CL delay time
    digitalWrite(motor9, LOW);
    delay(1000);
    
    // Drink Motor 10
    digitalWrite(motor10, HIGH);
    delay(mL * suckingFactor);  // 2 CL delay time
    digitalWrite(motor10, LOW);
    delay(1000);
    
    // Drink Motor 11
    digitalWrite(motor11, HIGH);
    delay(mL * suckingFactor);  // 2 CL delay time
    digitalWrite(motor11, LOW);
    delay(1000);
}
  
void startStepperMotor() {

  /* Stepper motor */ 
  digitalWrite(stepperStep, HIGH);
  delayMicroseconds(200);
  digitalWrite(stepperStep, LOW);
  delayMicroseconds(200);
  distance++;
  if (distance = 2000) {
    if(digitalRead(stepperDir) == LOW) {
      digitalWrite(stepperDir, HIGH);
    } else {
      digitalWrite(stepperDir, LOW);
    }
    distance = 0;
    delay(500);
  }
  
}



/* LED: Rainbow cycle method */
/*
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}
*/

/* 
// LED Helper method, used in rainbowCycle() or
// input a value 0 to 255 to get a color value.
*//*
uint32_t Wheel(byte WheelPos) {
  if(WheelPos < 85) {
   return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } else if(WheelPos < 170) {
   WheelPos -= 85;
   return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else {
   WheelPos -= 170;
   return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}
*/

