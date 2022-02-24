#include "functions.h"

CY_ISR_PROTO(ISR_UART_rx_handler);
void handleByteReceived(uint8_t byteReceived);

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    isr_uart_rx_StartEx(ISR_UART_rx_handler);
    UART_1_Start();
    
    // White = 1
    // Blue = 2
    // Red = 3
    // Yellow = 4
    // Black = 5
    // Brown = 6
    
    UART_1_PutString("ServoMotor application started\r\n");
    UART_1_PutString("0: Stop\r\n");
    UART_1_PutString("1: Drive forwards\r\n");
    UART_1_PutString("2: Drive backwards\r\n");
    UART_1_PutString("q: Decrease speed\r\n");
    UART_1_PutString("w: Increase speed\r\n");
    UART_1_PutString("e: Run once forwards\r\n");
    UART_1_PutString("r: Run once backwards\r\n");
    
    UART_1_PutString("\r\nChose state:\r\n");
    UART_1_PutString("a: Full step\r\n");
    UART_1_PutString("s: Half step\r\n");
    UART_1_PutString("d: Wave-drive\r\n");

    for(;;)
    {
        switch(getDirection()) {
            
            // Fremad
            case 1 :
            {
                switch(getState()) {
                    
                    // Full step
                    case 1 : 
                    {
                        driveForwardsFull(); 
                    }
                    break;
                    
                    // Half step
                    case 2 : 
                    {
                        driveForwardsHalf();
                    }
                    break;
                    
                    // Wave step
                    case 3 : 
                    {
                        driveForwardsWave();
                    }
                    break;
                    
                    default : 
                    {
                        //Nothing
                    }
                    break;
                }
            }
            break;
            
            // Baglæns
            case 2 :
            {
                switch(getState()) {
                    
                    // Full step
                    case 1 : 
                    {
                        driveBackwardsFull();
                    }
                    break;
                    
                    // Half step
                    case 2 : 
                    {
                        driveBackwardsHalf();
                    }
                    break;
                    
                    // Wave step
                    case 3 : 
                    {
                        driveBackwardsWave();
                    }
                    break;
                    
                    default : 
                    {
                        // Nothing
                    }
                }
                
            }
            break;
            
            
            default : 
            {
            }
            break;
        }
    }
}

CY_ISR(ISR_UART_rx_handler)
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

void handleByteReceived(uint8_t byteReceived)
{
    run(byteReceived);
}
