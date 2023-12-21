/*
#define MQ2pin 8

int sensorValue;  //variable to store sensor value

void setup() {
	Serial.begin(9600); // sets the serial port to 9600
	Serial.println("LDR warming up!");
	delay(20000); // allow the MQ2 to warm up
}

void loop() {
	sensorValue = digitalRead(MQ2pin); // read digital output pin
	Serial.print("Digital Output: ");
	Serial.print(sensorValue);
	
	// Determine the status
	if (sensorValue) {
		Serial.println("  |  Light: -");
	} else {
		Serial.println("  |  Light: Detected!");
	}
	
	delay(1000); // wait 2s for next reading
}


*/