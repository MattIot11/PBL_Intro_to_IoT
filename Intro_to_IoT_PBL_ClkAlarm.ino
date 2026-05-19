// Class: Intro to Iot 
// Project Name: Arduino Clock/Alarm 
// Author: Matthew Iulianella 
// Date of demo: 19/05/2026 
// Submitted to: prof. Daphne Saju 
// Including the LiquidCrystal library to use the lcd 

#include <LiquidCrystal.h> 

const int rs = 12, en = 11, switchPin4 = 10, switchPin3 = 9,buzzerPin = 8, switchPin1 = 7, switchPin2 = 6, d4 = 5, d5 = 4, d6 = 3, d7 = 2; // Declaring global variables 

LiquidCrystal lcd(rs, en, d4, d5, d6, d7); // Creating library object 


void alrmBuzz() { // Function for alarm 
    
    // Variables needed to read the state of the switches 
    int switch1 = digitalRead(switchPin1); 

    // if and else statements which set a different alarm based on switch combination 

    if (switch1 == HIGH) 
    { 
        lcd.clear(); 
        lcd.print("1 min alarm"); 
        delay(60000); 

        tone(buzzerPin,1000); // Gives a tone to the passive buzzer 
        digitalWrite(buzzerPin,HIGH); 
        delay(1000); 

        noTone(buzzerPin); // Removes sound from passive buzzer 

    } 

    else 
    { 
        lcd.clear(); 
        lcd.print("2 min alarm"); 
        delay(120000); 

        tone(buzzerPin, 1000); 
        digitalWrite(buzzerPin, HIGH); 
        delay(1000); 

        noTone(buzzerPin); 
        digitalWrite(buzzerPin,LOW); 
    } 

} 
void minHrs () { // Function for clock 

    int hrs; 
    int min1; 
    int min2; 

  // Nested for loops which increment variables at the sane time the digits in a clock change 
  for(hrs = 0; hrs < 24; hrs++) { 
   for(min1 =0; min1 < 5; min1++) { 
    for (min2 = 0; min2 < 9; min2++) {   

     // If switch2 is high then go to end of loops   
     if (digitalRead(switchPin2) == HIGH)  { 

       goto end;  

      }    

    lcd.clear(); 
    lcd.print("Time:"); 
    lcd.setCursor(0,1);                               

    lcd.print(hrs); 
    Serial.println(hrs); 

    lcd.print(":"); 
    Serial.print(":"); 

    lcd.print(min1); 
    Serial.print(min1); 

    lcd.print(min2); 
    Serial.print(min2);    

    delay(60000); // Delay equivalent to 1 minute 

        } 

       }  

      } 

    // Print nothing at end of loops, needed to use goto 
    end:  
    Serial.print(""); 
 } 

void setup() { 

  // Declaring the outputs and inputs of the project 
  pinMode(buzzerPin,OUTPUT);  
  pinMode(switchPin1,INPUT_PULLUP); 
  pinMode(switchPin2,INPUT_PULLUP); 

  // Setting up the LCD's number of columns and rows with lcd.begin 
  lcd.begin(16,2); 

  Serial.begin(9600);  
  // Setting up the serial monitor with a baud rate of 9600 

} 

void loop() { 

    // Read the state of switch 2 to know if it is high or low 

    int switch2 = digitalRead(switchPin2);  

    // Instructions stating what the switches do 

    lcd.clear();  
    lcd.print("Switch:Mode"); 
    delay(1500); 

    lcd.clear(); 
    lcd.print("0:Clock"); 
    delay(1500); 

    lcd.clear(); 
    lcd.print("1:No function"); 
    delay(1500); 

    lcd.clear(); 
    lcd.print("1,2: 1 min alarm"); 
    delay(1500); 

    lcd.clear(); 
    lcd.print("2:2 min alrm"); 
    delay(1500); 


    if (switch2 == HIGH) { // Evaluate if switch2 is HIGH 

       alrmBuzz(); // Calling the alrmBuzz function, if switch2 is on 

        } 

     else { // Evaluate if switch2 is LOW 

        minHrs(); // Calling the minHrs function, if switch 2 is off 

        } 

} 