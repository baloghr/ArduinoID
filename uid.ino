#include <avr/boot.h>

void print_val(char *msg, uint8_t val)
{
    Serial.print(msg);
    Serial.println(val, HEX);
}

void setup(void)
{

    Serial.begin(9600);
    while (!Serial) ;
#define SIGRD 5
#if defined(SIGRD) || defined(RSIG)
    Serial.print("Signature : ");
    for (uint8_t i = 0; i < 5; i += 2) {
        Serial.print(" 0x");
        Serial.print(boot_signature_byte_get(i), HEX);
    }
    Serial.println();

    Serial.print("Serial Number : ");
    for (uint8_t i = 14; i < 24; i += 1) {
        Serial.print(" 0x");
        Serial.print(boot_signature_byte_get(i), HEX);
    }
    Serial.println();
#endif
} 
