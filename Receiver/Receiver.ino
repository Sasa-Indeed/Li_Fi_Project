//LCD
#include <LiquidCrystal.h>
const int rs = 4, en = 7, d4 = 8, d5 = 9, d6 = 10, d7 = 11;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//LDR
#define LDRPIN        12
#define MUTEBUTTONPIN 2
int startTime;
int endTime;
int time ;
bool systemOnFlag = false;
bool offlineCall = true;
bool onlineCall = false;




//Buzzers
#define FIRE_BUZZER         6
#define DOOR_BUZZER         5
#define PROXIMITY_BUZZER    3

#define FIRE_FREQ           255
#define DOOR_FREQ           127
#define PROXIMITY_FREQ      200

//Functions APIs
void LCD_Message_Normal(void);
void LCD_Message_Smoke_Alarm(void);
void LCD_Message_Door_Alarm(void);
void LCD_Message_Proximity_Alarm(void);
void LCD_Message_Offline(void);
void Buzzer_Skmoke_Alarm_On(void);
void Buzzer_Door_Alarm_On(void);
void Buzzer_Proximity_Alarm_On(void);
void Buzzer_Skmoke_Alarm_Off(void);
void Buzzer_Door_Alarm_Off(void);
void Buzzer_Proximity_Alarm_Off(void);
void Buzzer_Turn_Off_All(void);


void setup() {
	Serial.begin(9600); // sets the serial port to 9600
  //Initializing the LDR
	Serial.println("LDR warming up!");
  pinMode(LDRPIN, INPUT_PULLUP);

  //Initializing the LCD
  lcd.begin(16,2);
  LCD_Message_Offline();

  //Initializing the buzzers
  pinMode(FIRE_BUZZER, OUTPUT);
  pinMode(DOOR_BUZZER, OUTPUT);
  pinMode(PROXIMITY_BUZZER, OUTPUT);

  //Initializing the mute button
  pinMode(MUTEBUTTONPIN, INPUT_PULLUP);
  attachInterrupt(0, Buzzer_Turn_Off_All, FALLING);
  
}

void loop() {
	
	// Determine the status
  if(!digitalRead(LDRPIN)){
    startTime = millis();
    while(!digitalRead(LDRPIN));
    endTime = millis();
    time = endTime - startTime;
  }else{
    time = 0;
  }
   
  if(!systemOnFlag){
    if(offlineCall){
      Buzzer_Turn_Off_All2();
      LCD_Message_Offline();
      offlineCall = false;
    }

    if(time >= 8000 && time <= 9100){ // Checking if system is turned on
      offlineCall = true;
      systemOnFlag = true;
      onlineCall = true;
    }

    if(onlineCall){
      LCD_Message_Normal();
    }
  }else{
    Serial.print("Reading is : ");
    if (time >= 2000 && time <= 3100){ //For ultra sonic
      Serial.println("Ultra");
      LCD_Message_Proximity_Alarm();
      Buzzer_Proximity_Alarm_On();
    }else if (time >= 4000 && time <= 5100){ //For door
      Serial.println("Door");
      LCD_Message_Door_Alarm();
      Buzzer_Door_Alarm_On();
    }else if (time >= 12000 && time <= 14100 || time >= 6000 && time <= 7100){ //For Fire
      Serial.println("Fire");
      LCD_Message_Smoke_Alarm();
      Buzzer_Smoke_Alarm_On();
    }else if (time >= 10000 && time <= 11100){ //For shutting down the system
      systemOnFlag = false;
      onlineCall = false;
    }else{
      Serial.println(time);
    } 

  }

  	
}

void LCD_Message_Normal(void){
  lcd.clear();
  lcd.setCursor(0, 0); // Top left
  lcd.print("   System is");
  lcd.setCursor(0, 1); // Bottom left
  lcd.print("     Online");
}

void LCD_Message_Smoke_Alarm(void){
  lcd.clear();
  lcd.setCursor(0, 0); // Top left
  lcd.print("  System Alarm");
  lcd.setCursor(0, 1); // Bottom left
  lcd.print("SMOKE DETECTED!");
}

void LCD_Message_Door_Alarm(void){
  lcd.clear();
  lcd.setCursor(0, 0); // Top left
  lcd.print("  System Alarm");
  lcd.setCursor(0, 1); // Bottom left
  lcd.print("DOOR WAS OPENED!");
}

void LCD_Message_Proximity_Alarm(void){
  lcd.clear();
  lcd.setCursor(0, 0); // Top left
  lcd.print("  System Alarm");
  lcd.setCursor(0, 1); // Bottom left
  lcd.print("PROXIMITY ALERT!");
}

void LCD_Message_Offline(void){
  lcd.clear();
  lcd.setCursor(0, 0); // Top left
  lcd.print("   System is");
  lcd.setCursor(0, 1); // Bottom left
  lcd.print("    Offline");
}

void Buzzer_Smoke_Alarm_On(void){
  analogWrite(FIRE_BUZZER, FIRE_FREQ);
}


void Buzzer_Door_Alarm_On(void){
  analogWrite(DOOR_BUZZER, DOOR_FREQ);
}


void Buzzer_Proximity_Alarm_On(void){
  analogWrite(PROXIMITY_BUZZER, PROXIMITY_FREQ);
}


void Buzzer_Skmoke_Alarm_Off(void){
  analogWrite(FIRE_BUZZER, 0);
}


void Buzzer_Door_Alarm_Off(void){
  analogWrite(DOOR_BUZZER, 0);
}


void Buzzer_Proximity_Alarm_Off(void){
  analogWrite(PROXIMITY_BUZZER, 0);
}



void Buzzer_Turn_Off_All(void){
  delay(5000);
  Buzzer_Skmoke_Alarm_Off();
  Buzzer_Door_Alarm_Off();
  Buzzer_Proximity_Alarm_Off();
  LCD_Message_Normal();  
}

