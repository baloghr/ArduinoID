// Source code based on the https://gist.github.com/speters/f889faec42b510052a6ab4be437d38ca

// Purpose is to simply run a memory check on ATMEGA238P to test for counterfeit parts
// Usually fake chip has only FF on the last line 

#include <avr/boot.h>
#define SIGRD 5

void setup() 
{
  Serial.begin(9600);
  Serial.println("");
  Serial.println("boot sig dump");
  int newLineIndex = 0;
  char buffer[40];
  
  Serial.println("\n    00  01  02  03  04  05  06  07  08  09  0A  0B  0C  0D  0E  0F");
  

  sprintf(buffer, "00: ");
  Serial.print(buffer);
  for (uint8_t i = 0x00; i <= 0x0F; i += 1) 
  {
   sprintf(buffer, "%02X  ",boot_signature_byte_get(i));
   Serial.print(buffer);
  }
   Serial.println();
   
  sprintf(buffer, "10: ");
  Serial.print(buffer);
  for (uint8_t i = 0x10; i <= 0x1F; i += 1) 
  {
   sprintf(buffer, "%02X  ",boot_signature_byte_get(i));
   Serial.print(buffer);
  }
   Serial.println();
   Serial.println();


   sprintf(buffer, "Signature: %02X %02X %02X ",boot_signature_byte_get(0x00),boot_signature_byte_get(0x02),boot_signature_byte_get(0x04));
   Serial.print(buffer);

   if (boot_signature_byte_get(0x00) == 0x1E) 
     if (boot_signature_byte_get(0x02) == 0x95) 
        if (boot_signature_byte_get(0x04) == 0x0F)
          Serial.println(" (ATmega328P)");      
        else if (boot_signature_byte_get(0x04) == 0x16)
          Serial.println(" (ATmega328PB)");      
        else
          Serial.println(" (---)");
      else
          Serial.println(" (---)");
    else
          Serial.println(" (---)");


  Serial.print("           Lot: ");
  Serial.write(boot_signature_byte_get(0x0F));
  Serial.write(boot_signature_byte_get(0x0E));
  Serial.write(boot_signature_byte_get(0x11));
  Serial.write(boot_signature_byte_get(0x10));
  Serial.write(boot_signature_byte_get(0x13));
  Serial.write(boot_signature_byte_get(0x12));
  Serial.print("  Wafer: ");
  Serial.print(boot_signature_byte_get(0x15),DEC);
  Serial.print("  X: ");
  Serial.print(boot_signature_byte_get(0x17),DEC);
  Serial.print("  Y: ");  
  Serial.print(boot_signature_byte_get(0x16),DEC);
  Serial.println(" (Decimal)");
  //Serial.println();

  cli();
    uint8_t lowBits      = boot_lock_fuse_bits_get(GET_LOW_FUSE_BITS);
    uint8_t highBits     = boot_lock_fuse_bits_get(GET_HIGH_FUSE_BITS);
    uint8_t extendedBits = boot_lock_fuse_bits_get(GET_EXTENDED_FUSE_BITS);
    uint8_t lockBits     = boot_lock_fuse_bits_get(GET_LOCK_BITS);
  sei();

    Serial.print("    Fuses: Low: 0x");
    Serial.print(lowBits, HEX);
    Serial.print("  High: 0x");
    Serial.print(highBits, HEX);
    Serial.print("  Ext: 0x");
    Serial.print(extendedBits, HEX);
    Serial.print("  Lock: 0x");
    Serial.println(lockBits, HEX);

}

void loop() 
{ /* do nothing here */  }
