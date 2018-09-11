#include <LiquidCrystal.h>
#include <SoftwareSerial.h>
LiquidCrystal lcd(12,11,5,4,3,2);
SoftwareSerial SIM900(9,8 );
int inByte=0;
void setup()
{
 Serial.begin(19200); // for serial monitor display
SIM900.begin(19200); // for GSM shield start serial programming
lcd.begin(16, 2);
lcd.print("      ATTENTION");
lcd.setCursor(0, 1);
lcd.print("READ THE MESSAGE");
delay(2000); // give time to manually power ON the GSM Shield andconnect to the network
lcd.clear();
SIM900.print("AT+CMGF=1\r"); // set SMS mode to text
delay(100);
SIM900.print("AT+CNMI=2,2,0,0,0\r"); // Configuration to extract content of the received message.Display it on Arduino Serial Monitor
delay(100);
// Now we simply display any text that the GSM shield sends out on the serial monitor
do
   {
       while ( !SIM900.available() );   
   } while ( '"' != SIM900.read() );
 
   do
   {
       while ( !SIM900.available() );   
   } while ( '"' != SIM900.read() );
 
   do
   {
       while ( !SIM900.available() );   
   } while ( '"' != SIM900.read() );
 
   do
   {
       while ( !SIM900.available() );   
   } while ( '"' != SIM900.read() );
    do
   {
       while ( !SIM900.available() );   
   } while ( '"' != SIM900.read() );
 
   do
   {
       while ( !SIM900.available() );   
   } while ( '"' != SIM900.read() );
 
 
   while ( !SIM900.available() );
   inByte = SIM900.read();   
   while ( !SIM900.available() );
   inByte = SIM900.read();
   lcd.clear();
   while(1)
   {
       while ( !SIM900.available() );
       inByte = SIM900.read();
     
       if ( inByte == '\r' )
         break;
       else;
      Serial.write(inByte);
       lcd.write ( inByte );
   }
}
void loop()
{
  for (int positionCounter = 0; positionCounter < 13; positionCounter++) {
    // scroll one position left:
    lcd.scrollDisplayLeft();
    // wait a bit:
    delay(150);
  
  }
}
