#include "functions.h"

CY_ISR_PROTO(ISR_UART_rx_handler);
void handleByteReceived(uint8_t byteReceived);

int main(void)
{
    CyGlobalIntEnable; // Tænder for globale interrupts
 
    isr_uart_rx_StartEx(ISR_UART_rx_handler);
    UART_1_Start(); // Starter UARTen
 
    // Printer de forskellige muligheder i terminalen
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
        // Første switch finder ud af hvilken retning der skal køres
        // Anden switch finder ud af hvilken slags kørsel der skal laves (Full, Half eller Wave)
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
            
<<<<<<< HEAD
            // Bagl�ns
=======
            // Bagud
>>>>>>> 7732126a72d51834f12cb5dd2bb041f56f542d8e
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
                // Nothing
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
        
        handleByteReceived(byteReceived); // Sender svaret videre
        
        bytesToRead--;
    }
}

void handleByteReceived(uint8_t byteReceived)
{
    run(byteReceived); // Kalder den respektive funktion ud fra hvad der er blevet sendt i UARTen
}
