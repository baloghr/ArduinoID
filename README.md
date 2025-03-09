Code in this repository is for reading (more or less documented) ID bytes from the special section of the AVR chip memory. 
Based on the the 'speters' code and improved to read the whole part of the memory, including the Wafer ID and chip location 
on the wafer. Seems to be useful for identification of fake ATmega328 chips, where those bytes are usually intact (i.e. unprogrammed, 0xFF).

If you are interested on results of small experiment, here it is: https://senzor.robotika.sk/sensorwiki/index.php/Fake_AVR_chips

This is the result for the original and genuine Arduino Nano by Arduino S.r.l. (Italy)
```
           00  01  02  03  04  05  06  07  08  09  0A  0B  0C  0D  0E  0F
   0x0000: 1E  A9  95  FF  0F  BA  00  26  FF  06  FF  17  FF  FF  57  30  
   0x0010: 31  30  30  36  FF  0C  19  27  17  05  12  09  13  09  FF  FF  
   
   Signature: 1E 95 0F  (ATmega328P)
              Lot: 0W0160  Wafer: 12  X: 39  Y: 25 (Decimal)
       Fuses: Low: 0xFF  High: 0xDA  Ext: 0xFD  Lock: 0xCF
``` 

Output for the counterfeit chip is similar to this one (note 0xFF on the Wafer ID an X, Y location bytes):
```
         00  01  02  03  04  05  06  07  08  09  0A  0B  0C  0D  0E  0F
 0x0000: 1E  AD  95  FF  0F  FF  FF  26  FF  FF  FF  FF  FF  FF  58  FF  
 0x0010: EF  FF  EF  FF  FF  FF  FF  FF  FF  FF  FF  FF  FF  FF  FF  FF  
 
 Signature: 1E 95 0F  (ATmega328P)
            Lot: ⸮X⸮⸮⸮⸮  Wafer: 255  X: 255  Y: 255 (Decimal)
     Fuses: Low: 0xFF  High: 0xDA  Ext: 0xFD  Lock: 0xCF
```

For more information, see the paper: 

Balogh, R.: Recognition of the Counterfeit Arduino Chips, Proceedings of the K&I'25 conference. 

