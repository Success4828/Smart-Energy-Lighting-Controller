/* * PROJECT: Smart Energy Lighting Controller
 * GROUP: 10 - Computer Engineering
 * DESCRIPTION: Automated lux-level monitoring for energy optimization.
 */

// Pin Definitions
const int SENSOR_INPUT = A0;  // LDR connected to Analog Pin 0
const int LOAD_SWITCH = 8;    // Relay connected to Digital Pin 8

// Configuration
int luxThreshold = 480;       // Calibrated light intensity limit
int currentReading = 0;

void setup() {
  pinMode(LOAD_SWITCH, OUTPUT);
  Serial.begin(9600);
  Serial.println("--- System Initializing: Smart Energy Controller ---");
}

void loop() {
  // Read atmospheric light level
  currentReading = analogRead(SENSOR_INPUT);
  
  // Display data for calibration
  Serial.print("Ambient Light Intensity: ");
  Serial.println(currentReading);

  // Logic: Activate load only when visibility is low
  if (currentReading < luxThreshold) {
    digitalWrite(LOAD_SWITCH, HIGH); // Turn Light ON
    Serial.println("STATUS: Night Mode Detected - Lamp ACTIVE");
  } 
  else {
    digitalWrite(LOAD_SWITCH, LOW);  // Turn Light OFF
    Serial.println("STATUS: Sufficient Sunlight - Lamp INACTIVE");
  }

  delay(1000); // 1-second sample rate for stability
}