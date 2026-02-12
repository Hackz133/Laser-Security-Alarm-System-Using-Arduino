void setup() { 
pinMode(laserPin, OUTPUT);   // Configure laser pin as output 
pinMode(buzzerPin, OUTPUT);  // Configure buzzer pin as output 
pinMode(sensorPin, INPUT_PULLUP); // Use internal pull-up resistor for the LDR pin 
Serial.begin(9600);       
   // Start serial communication 
} 
boolean alarmState = false; 
void loop() { 
if (!alarmState) { 
delay(1000);                
  // Wait for a second before checking 
digitalWrite(laserPin, HIGH); // Turn on the laser 
delay(10);                    
// Stabilization delay 
unsigned long startTime = millis(); 
while (millis() - startTime < 1000) { // Check for 1 second 
int sensorValue = analogRead(sensorPin); // Read analog value from LDR 
Serial.println(sensorValue);           // Print the value to Serial Monitor 
if (sensorValue > laserThreshold) {  // Detect interruption based on threshold 
alarmState = true; 
break; 
} 
delay(10);  // Short delay to avoid rapid re-checks 
} 
digitalWrite(laserPin, LOW); // Turn off the laser 
} else { 
tone(buzzerPin, 400);       // Sound the buzzer at 400 Hz 
delay(1000);                
// Keep the buzzer on for 1 second 
alarmState = false;      
noTone(buzzerPin);    
   // Reset the alarm state 
      //
 Stop the buzzer  }             
} 
