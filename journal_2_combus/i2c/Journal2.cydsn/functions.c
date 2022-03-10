#include "functions.h"

void readAndPrint(uint8 adress)
{
    uint8 errorMSG, byte1, byte2;
    float temperature;
    /*Send start til slave 1. Gem error MSG */
    errorMSG = I2C_1_MasterSendStart(adress,1); 
        if(errorMSG != I2C_1_MSTR_NO_ERROR) 
        UART_1_PutString("START NOT ACKNOWLEDGED");
        
    //Læs første byte. MSB kommer først. Send ACK efter
    byte1 = I2C_1_MasterReadByte(I2C_1_ACK_DATA); 
    
    //Læs andet byte. Kun LSB her. Send NACK, så den ikke sender mere.
    byte2 = I2C_1_MasterReadByte(I2C_1_NAK_DATA); 
   
    //Bed den om at stoppe
    I2C_1_MasterSendStop(); 
    
    //Konverter fra 2's complement til float
    temperature = convertMeasurement(byte1, byte2); 
    //Udskriv float i UART
    writeTempToUART(temperature); 
}

void writeTempToUART(float temp)
{
    char outputbuffer[256];
    
    snprintf(outputbuffer, sizeof(outputbuffer),"Temperature: %f \r\n", temp);
    UART_1_PutString(outputbuffer);
}



float convertMeasurement(uint8 byte1, uint8 byte2)
{
    //temporary variable til bitshifting
    uint8 temp1, temp2; 
    //Det ene most significant bit bliver gemt her til sidst. (BIT 8)
    uint8 msb;
    //De 8 LSBs bliver gemt her. Bit 0:7
    uint8 lsb; 
    float temperature;
    
    msb = byte1>>7; // Fortegn ligger her. MSB 
    temp1 = byte2>>7;
    temp2 = byte1<<1;
    lsb = temp1 + temp2; /* Temperatur ligger her */
    
    if(msb == 0)
    {
        temperature = (float)lsb/2;
    }
    else if(msb == 1)
    {
        lsb = ~lsb + 0b00000001;
        temperature = -((float)lsb)/2;
    }
    else
    {
        UART_1_PutString("SOMETHING WENT WRONG IN MEASUREMENT CONVERSION");
    }
   
    return temperature;
}