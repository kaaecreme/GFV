/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================s
*/
#include "project.h"

void handleByteReceived(uint8_t byteReceived);
CY_ISR_PROTO(ISR_2_handler);
CY_ISR_PROTO(ISR_1_handler);
uint8_t emptyData = 0x00; // Send ingenting
uint8_t onData = 0x45; // Nu skal LED tænde
uint8_t offData = 0x12; // Nu skal LED slukke
uint8_t buttonData = 0x02; // Nu er der registreret et tryk på knap
uint8_t recievedData; // Gemmer modtaget værdi fra slaven

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    UART_1_Start();
    SPIM_1_Start();
    isr_2_StartEx(ISR_2_handler);
    isr_1_StartEx(ISR_1_handler);
    
    
    for(;;)
    {
            SPIM_1_WriteTxData(emptyData);
            recievedData = SPIM_1_ReadRxData();
    }
}

void handleByteReceived(uint8_t byteReceived)
{
    switch(byteReceived)
    {
        case '1' :
        {
            UART_1_PutString("Turning LED on    \r\n");
            SPIM_1_WriteTxData(onData);
            SPIM_1_ReadRxData();
        }
        break;
        case '2' :
        {
            UART_1_PutString("Turning LED off   \r\n");
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

CY_ISR(ISR_2_handler)
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

CY_ISR(ISR_1_handler)
{
    if (recievedData == buttonData)
            {
                UART_1_PutString("The button has been pushed\r\n");
            }
}

