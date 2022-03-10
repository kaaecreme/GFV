#include "functions.h"

CY_ISR_PROTO(ISR_2_handler); // Interrupt

int main(void)
{
    CyGlobalIntEnable; // Start global interruupts
    UART_1_Start(); // Start UART
    SPIM_1_Start(); // Start Master / Slave
    isr_2_StartEx(ISR_2_handler); // Knytter UART interrupts til funktionen ISR_2_handler
    
    for(;;)
    {
        // Gør ingenting
    }
}

CY_ISR(ISR_2_handler) // Håndterer tryk fra UART
{
    uint8_t bytesToRead = UART_1_GetRxBufferSize();
    while (bytesToRead > 0)
    {
        uint8_t byteReceived = UART_1_ReadRxData();
        UART_1_WriteTxData(byteReceived); // Udskriv tryk
        handleByteReceived(byteReceived); // Send videre
        
        bytesToRead--;
    }
}

