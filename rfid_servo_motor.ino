#define SS_PIN  10 //D2
#define RST_PIN 5 //D1
#include <SPI.h>
#include <MFRC522.h>
MFRC522 mfrc522(SS_PIN, RST_PIN);   
int variable = 0;
#include <Servo.h>

Servo myservo;  /

int pos = 0;    // variable to store the servo position

void setup() {
  myservo.attach(6);
  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
   Serial.println("Show your card:");
}
void loop()
{
  
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent())
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial())
  {
    return;
  }
  //Show UID on serial monitor
  Serial.println();
 
  Serial.print(" UID tag :");
  String content = "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++)
  {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
    content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
    content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  content.toUpperCase();
  if (content.substring(1) == "49 DC 65 D5") //change UID of the card that you want to give access
  {
    Serial.println();
    Serial.println(" unlock ");
    Serial.println(" Welcome vicky");    
    Serial.println(" enjoy your day ");
    Serial.println(" thank you ");
    Serial.println("Show your card:");
    for (pos = 0; pos <= 110; pos += 1) 
    if(pos==110)
    {
     for (pos = 110; pos >= 0; pos -= 1) { 
    myservo.write(pos);              
    delay(15);                       
  }
  for (pos = 0; pos <= 110; pos += 1) { 
    myservo.write(pos);              
    delay(15);                       
  }}
    
    delay(1000);
    
  }
  
}
