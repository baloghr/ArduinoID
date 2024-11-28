Code in this repository is for reading more or less documented ID bytes from the special section of the AVR chip memory. 
Based on the the speters code and impreved to read the whole part of the memory, including the Wafer ID and chip location 
on the wafer. Seems to be useful for identification of fake ATmega328 chips, where those bytes are usually intact (i.e. unprogrammed, 0xFF).

