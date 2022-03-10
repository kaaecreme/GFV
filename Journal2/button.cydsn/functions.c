#include "functions.h"

uint8_t emptyData = 0x00; // Send ingenting
uint8_t onData = 0x45; // Nu skal LED tænde
uint8_t offData = 0x12; // Nu skal LED slukke
uint8_t buttonData = 0x02; // Nu er der registreret et tryk på knap
uint8_t recievedData; // Gemmer modtaget værdi fra slaven

void handleByteReceived(uint8_t byteReceived) // Håndterer hvert tryk på tastatur igennem UART
{
    switch(byteReceived)
    {
        case '1' : // Tænd LED
        {
            UART_1_PutString("Turning LED on\r\n");
            SPIM_1_WriteTxData(onData); // Send onData til Slaven
            SPIM_1_ReadRxData();
        }
        break;
        case '2' : // Sluk LED
        {
            UART_1_PutString("Turning LED off\r\n");
            SPIM_1_WriteTxData(offData); // Send offData til Slaven
            SPIM_1_ReadRxData();
        }
        break;
        
        default :
        {
            // Gør ingenting
        }
        break;
    }
}