#include "project.h"
#include "functions.h"

CY_ISR_PROTO(ISR_2_handler); // Interrupt UART
CY_ISR_PROTO(ISR_1_handler); // Interrupt SPIM

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    UART_1_Start(); // Start UART
    SPIM_1_Start(); // Start Master / Slave
    isr_2_StartEx(ISR_2_handler); // Knytter UART interrupts til funktionen ISR_2_handler
    isr_1_StartEx(ISR_1_handler); // Knytter SPIM interrupts til funktionen ISR_1_handler
    
    for(;;) // Send og læs kontinuerligt
    {
            SPIM_1_WriteTxData(emptyData);
            recievedData = SPIM_1_ReadRxData(); // Gem modtaget værdi
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


CY_ISR(ISR_1_handler) // Håndterer data modtaget fra Slaven
{
    if (recievedData == buttonData) // Hvis knappen er blevet trykket
       {
           UART_1_PutString("The button has been pushed\r\n");
       }
}

