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

void handleByteReceived(uint8_t byteReceived);
CY_ISR_PROTO(ISR_2_handler);
uint8_t onData = 0x45;
uint8_t offData = 0x12;
uint8_t emptyData = 0x00;

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    UART_1_Start();
    SPIM_1_Start();
    isr_2_StartEx(ISR_2_handler);
    
    for(;;)
    {
    }
}

void handleByteReceived(uint8_t byteReceived)
{
    switch(byteReceived)
    {
        case '1' :
        {
            UART_1_PutString("Turning LED on\r\n");
            SPIM_1_WriteTxData(onData);
            SPIM_1_ReadRxData();
        }
        break;
        case '2' :
        {
            UART_1_PutString("Turning LED off\r\n");
            SPIM_1_WriteTxData(offData);
            SPIM_1_ReadRxData();
        }
        break;
        
        default :
        {
            // nothing
        }
        break;
    }
}

CY_ISR(ISR_2_handler) // Håndterer tryk fra UART
{
    uint8_t bytesToRead = UART_1_GetRxBufferSize();
    while (bytesToRead > 0)
    {
        uint8_t byteReceived = UART_1_ReadRxData();
        
        UART_1_WriteTxData(byteReceived); // echo back
        handleByteReceived(byteReceived);
        
        bytesToRead--;
    }
}

