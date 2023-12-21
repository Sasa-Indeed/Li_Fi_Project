/* // include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 8, en = 9, d4 = 10, d5 = 11, d6 = 12, d7 = 13;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


void LCD_Init(void){
  // Set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("hello, world!");
}

/*
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print(millis() / 1000);
*/ 


/*
//Buzzers

// include the library code:
/* #include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 8, en = 9, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

  int i = 0;

#define FIRE_BUZZER     10
#define DOOR_BUZZER     11
#define ULTRA_BUZZER    12

#define FIRE_FREQ       300
#define DOOR_FREQ       2000
#define ULTRA_FREQ      20
 
void setup(){  
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(FIRE_BUZZER, OUTPUT);
  pinMode(DOOR_BUZZER, OUTPUT);
  pinMode(ULTRA_BUZZER, OUTPUT);

  // Set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Hello!");
  delay(4000);
  lcd.clear();
}
 
void loop(){

  if(i == 0){
    lcd.clear();
    lcd.print("FIRE !!!");
    Serial.println("Fire");
    tone(FIRE_BUZZER, FIRE_FREQ);
    delay(2000);
    noTone(FIRE_BUZZER);
    delay(2000);
    i++;
  }else if(i == 1){
    lcd.clear();
    lcd.print("DOOR OPENED!!!");
    Serial.println("Door");
    tone(DOOR_BUZZER, DOOR_FREQ);
    delay(2000);
    noTone(DOOR_BUZZER);
    delay(2000);
    i++;
  }else if(i == 2){
    lcd.clear();
    lcd.print("Someone is Near!!!");
    Serial.println("Ultra");
    tone(ULTRA_BUZZER, ULTRA_FREQ);
    delay(2000);
    noTone(ULTRA_BUZZER);
    delay(2000);
    i++;
  }else{
    i = 0;
  }

} */


/*  #define MQ2pin 8

int sensorValue;  //variable to store sensor value

void setup() {
	Serial.begin(9600); // sets the serial port to 9600
	Serial.println("MQ2 warming up!");
	//delay(20000); // allow the MQ2 to warm up
  pinMode(MQ2pin, INPUT_PULLUP);
}

void loop() {
	sensorValue = digitalRead(MQ2pin); // read digital output pin
	Serial.print("Digital Output: ");
	Serial.print(sensorValue);
	
	// Determine the status
	if (sensorValue) {
		Serial.println(" | Door : Opened!");
	} else {
		Serial.println(" | Door : Closed!");
	}
	
	delay(2000); // wait 2s for next reading
} */


/* int i = 0;

char Incoming_value = 0;
void setup() {
  // put your setup code   here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

void   loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()   > 0){
      Incoming_value = Serial.read();
      Serial.print(Incoming_value);
       Serial.print("\n");
      
      if (Incoming_value == '1'){
        digitalWrite(LED_BUILTIN, HIGH);
      }else if(Incoming_value == '0'){
        digitalWrite(LED_BUILTIN, LOW); 
      }else{
       Serial.print(Incoming_value);
      }
    }else{
      if(i == 0){
        Serial.println("System Alarm: \nSMOKE DETECTED! ");
        i++;
      }else if(i == 1){
        Serial.println("System Alarm:\nDOOR WAS OPENED! ");
        i++;
      }else if(i == 2){
        Serial.println("System Alarm:\nPROXIMITY ALERT! ");
        i++;
      }else{
        i = 0;
      }
    }

    delay(3000);
} 

*/