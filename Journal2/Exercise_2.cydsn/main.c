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

#include "project.h"
#include "Functions.h"


int main(void)
{
  CyGlobalIntEnable;
  UART_1_Start();
  I2C_master_Start();
  uint8_t byte1;
  uint8_t byte2;
  UART_1_PutString("It has started\n\r");

    for(;;)
    {
        uint8_t status = I2C_master_MasterSendStart(0x48, 1);
        if (status == I2C_master_MSTR_NO_ERROR)
        {
            byte1 = I2C_master_MasterReadByte(I2C_master_ACK_DATA);
            byte2 = I2C_master_MasterReadByte(I2C_master_NAK_DATA);
           
            float temperature = calculateTemp(byte1,byte2);
            writeTempToUART(temperature);
            I2C_master_MasterSendStop();
        }
        else 
        {
            UART_1_PutString("There is an error\n\r");
            I2C_master_MasterSendStop();
        }
        CyDelay(300); //aflæst fra datablad
    }
}
/* [] END OF FILE */
