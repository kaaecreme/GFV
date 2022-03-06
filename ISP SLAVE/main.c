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
//CY_ISR_PROTO(ISR_1_handler);
uint8_t ByteRecieved;
uint8_t ButtonPressed = 0x02; 

int main(void)
{
    CyGlobalIntEnable; // Enable global interrupts.
    
    SPIS_1_Start();
    //isr_1_StartEx(ISR_1_handler);
    
    
    uint8_t data = 0xFF;
    
    for(;;)
    {
        ByteRecieved = SPIS_1_ReadRxData();
        SPIS_1_WriteTxData(data); 
        
         if (ByteRecieved == 0x45)
        {
            Pin_1_LED_Write(1);    
            
        }
        
        else if (ByteRecieved == 0x12)
        {
            Pin_1_LED_Write(0);
        }
        
        if (Pin_2_Button_Read() == 0) //Button has been pressed
        {
            SPIS_1_WriteTxData(ButtonPressed); 
        }
        
        
    }
}

  // CY_ISR(ISR_1_handler)
   



/* [] END OF FILE */
