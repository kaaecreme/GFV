#include "functions.h"
#include <stdint.h>

uint8_t CURR_PWM = 0; // Gemmer PWM signalets værdi for at holde styr på dens nuværende værdi
uint8_t MAX_PWM = 100; // Sætter en øvre begrænsning på PWM signalet
uint8_t MIN_PWM = 0; // Sætter en nedre begrænsning på PWM signalet

void decreaseSpeed()
{
    UART_1_PutString("Decreasing speed\r\n");
    
    if (CURR_PWM > MIN_PWM)
    {
        CURR_PWM -= 10; // Duty cyclen falder
        PWM_1_WriteCompare(CURR_PWM); // Sender værdien ud
    }
}

void increaseSpeed()
{
    UART_1_PutString("Increasing speed\r\n");   

    if (CURR_PWM < MAX_PWM)
    {
        CURR_PWM += 10; // Duty cyclen stiger
        PWM_1_WriteCompare(CURR_PWM); // Sender værdien ud
    }
}

void driveForwards()
{
    UART_1_PutString("Set direction: forwards\r\n");
    Pin1_Write(1); // Skriver til Pin1
    Pin2_Write(0); // Skriver til Pin2
}

void driveBackwards()
{
    UART_1_PutString("Set direction: backwards\r\n");
    Pin1_Write(0); // Skriver til Pin1 
    Pin2_Write(1); // Skriver til Pin2
}

void stop()
{
    UART_1_PutString("Stop\r\n");
    CURR_PWM = 0;
    PWM_1_WriteCompare(CURR_PWM); // Når duty cyclen bliver 0, så stopper motoren
}