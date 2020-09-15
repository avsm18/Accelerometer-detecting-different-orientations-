const int groundpin = 14; // A0           
const int powerpin = 18;  // A4            
const int xpin = A3;                  // x-axis of the accelerometer
const int ypin = A2;                  // y-axis
const int zpin = A1;        // z-axis (only on 3-axis models)
int x , y , z;

void setup() {
  // initialize the serial communications:
  Serial.begin(9600);

  // Provide ground and power by using the analog inputs as normal digital pins.
  // This makes it possible to directly connect the breakout board to the
  // Arduino. If you use the normal 5V and GND pins on the Arduino,
  // you can remove these lines.
  pinMode(groundpin, OUTPUT);
  pinMode(powerpin, OUTPUT);
  digitalWrite(groundpin, LOW);
  digitalWrite(powerpin, HIGH);
}

void loop() {

 // print the sensor values:
  x = analogRead(A3);  // so from here we are getting x , y and z values
  y = analogRead(A2);
  z = analogRead(A1);
  if ((x > 365 && x < 400 ) && (y > 375 && y < 390) && (z > 460 && z < 470)) {

  Serial.println("I am horizontal.");
  
 }
 else if ((x > 365 && x < 380) && (y > 370 && y < 390) && (z > 305 && z < 320)) {
    Serial.println("I am flipped.");
    
 }
 else if ((x > 365 && x < 375) && (y > 290 && y < 305) && (z > 370 && z < 385)) 
  {
 Serial.println("I am resting on short header");
 }

  else if ((x > 375 && x < 385) && (y > 440 && y < 455) && (z > 370 && z < 385)) 
  {
 Serial.println("I am resting on long header");
 }
 
  else if ((x > 305 && x < 320) && (y > 385 && y < 400) && (z > 395 && z < 415)) 
  {
 Serial.println("USB port pointing up ");
 }
  else if ((x > 460 && x < 475) && (y > 385 && y < 400) && (z > 395 && z < 415)) 
  {
 Serial.println("USB port pointing down ");
 }
 
  delay(100);

  
  

}
