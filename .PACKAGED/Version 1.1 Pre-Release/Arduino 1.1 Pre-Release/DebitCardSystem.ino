/*
This program is used along with the Unreal Engine app available at  https://ssz.ca/projectzero  to create a dedit card system
*/

#include <MFRC522.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SPI.h>


Adafruit_SSD1306 display(4);

MFRC522 rfid(10, 9);
MFRC522::MIFARE_Key key; 

String UUIDString;

void setup() 
{
  Serial.begin(9600);
  SPI.begin();
  rfid.PCD_Init(); 
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  SetHomeScreen();
}

void loop() 
{
  if(  rfid.PICC_IsNewCardPresent())
  {
      ReadRFID();
  }
  delay(100);
}

void ReadRFID()
{
  rfid.PICC_ReadCardSerial();
  MFRC522::PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak);
  PrintDec(rfid.uid.uidByte, rfid.uid.size);
  UUIDString = String(rfid.uid.uidByte[0])+" "+String(rfid.uid.uidByte[1])+" "+String(rfid.uid.uidByte[2])+ " "+String(rfid.uid.uidByte[3]);
  PrintUID();
  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();
}

void PrintDec(byte *buffer, byte bufferSize) 
{
  for (byte i = 0; i < bufferSize; i++) 
  {
    Serial.print(buffer[i] < 0x10 ? " 0" : " ");
    Serial.print(buffer[i], DEC);
  }
}

void PrintUID()
{
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.setCursor(30,10); 
  display.print(UUIDString);
  display.setCursor(10,20); 
  display.print("CARD WAS SCANNED");
  display.display();
  delay(2000);
  SetHomeScreen();
}

void SetHomeScreen()
{
  display.clearDisplay();
  display.display();
  display.setTextColor(WHITE);
  display.setTextSize(2);
  display.setCursor(10,5); 
  display.print("SCAN CARD");
  display.display();
}
