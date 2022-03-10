/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "Functions.h"

float calculateTemp(uint8_t byte1, uint8_t byte2)
{
    uint8_t temp1, temp2;
    uint8_t least;
    uint8_t most;
    float combinedByte;
    
    most = temp1>>7;
    temp1 = byte2 >> 7;
    temp2 = byte1 << 1;
    least = temp1 + temp2;
    
    if (most == 0)
    {
        combinedByte = (float)least/2;
    }
    else if (most == 1)
    {
        least = ~least;
        least = least + 0b00000001;
        combinedByte = -((float)least)/2;
    }
    else
    {
        UART_1_PutString("There is an error in the conversion");
        return 0;
    }
    return combinedByte;
}


void writeTempToUART(float temp)
{
    char outputBuffer[256];
    
    snprintf(outputBuffer, sizeof(outputBuffer), "\r\n\nTemp: %f \r\n\n", temp);
    
    UART_1_PutString(outputBuffer);
}
    
void writeTempToUART1(uint8_t bin)
{
    char outputBuffer[256];
    
    snprintf(outputBuffer, sizeof(outputBuffer), "Bin: %d \r\n", bin);
    
    UART_1_PutString(outputBuffer);
}






/* [] END OF FILE */
