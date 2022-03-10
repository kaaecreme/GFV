#include "project.h"

uint8_t ByteRecieved; // Gemmer modtaget byte
uint8_t emptyData = 0x00; // Send ingenting
uint8_t onData = 0x45; // Nu skal LED tænde
uint8_t offData = 0x12; // Nu skal LED slukke
uint8_t buttonData = 0x02;  // Send tryk registrering

int main(void)
{
    SPIS_1_Start(); // Start SPI
    
    for(;;)
    {
        ByteRecieved = SPIS_1_ReadRxData(); // Læs modtaget data
        SPIS_1_WriteTxData(emptyData); // Skriv ingenting tilbage (Nødvendigt)
        
        if (ByteRecieved == onData) // Tænd LED
        {
            Pin_1_LED_Write(1);    
        }
        
        else if (ByteRecieved == offData) // Sluk LED
        {
            Pin_1_LED_Write(0);
        }
        
        if (Pin_2_Button_Read() == 0) // Knappen er blevet trykket på
        {
            SPIS_1_ReadRxData(); // Vi er nødt til at læse for at kunne sende
            SPIS_1_WriteTxData(buttonData);  // Send signal afsted om den tryk
        }
    }
}
