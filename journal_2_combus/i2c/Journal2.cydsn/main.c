#include "project.h"
#include "functions.h"

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    //Slave adresser:
    uint8 slave1 = 0b1001000;
    uint8 slave2 = 0b1001111;
    
    UART_1_Start();
    I2C_1_Start(); /*I2C komponentet initialiseres. I2C interrupts enables */ 
    
    UART_1_PutString("Application started\r\n"); 

    for(;;)
    {

        
    UART_1_PutString("Slave1 aflaeses \r\n"); 
    readAndPrint(slave1);
    CyDelay(500);
    UART_1_PutString("Slave2 aflaeses \r\n"); 
    readAndPrint(slave2);
    CyDelay(500);
    }
}