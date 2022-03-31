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
#include <stdio.h>
#include "I2C.h"
#include "PIDControl.h"


CY_ISR(ISR_UART_rx_handler);
void handleByteReceived(uint8_t byteReceived);

static char outputBuffer[256];
float setPoint = 30;

#define SAMPLES_PER_SECOND 1
static uint16_t sampleWaitTimeInMilliseconds = 1000 / SAMPLES_PER_SECOND;

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    
    //Slave adresser:
    uint8 slave1 = 0b1001000; 
    
    UART_1_Start();
    isr_1_StartEx(ISR_UART_rx_handler);
    PWM_Start();
    I2C_1_Start(); /*I2C komponentet initialiseres. I2C interrupts enables */ 
    
    float Kp = 4.0f;
    float Ki = 4.0f/30.0f;
    float Kd = 0.0f;
    float integralMax = 1000;
    float integralMin = -1000;
    float temp = 0;
    float controlSignal = 0;
    

    float dt = ((float)sampleWaitTimeInMilliseconds) / 1000; // dt is measured in seconds
    PIDControl_init(Kp, Ki, Kd, integralMax, integralMin, dt);
    PIDControl_changeSetPoint(setPoint);

    UART_1_PutString("Temperature control application started\r\n");

    for(;;)
    {

        

        
        
        //Aflæs temperatur
        temp = readAndReturn(slave1);
        
        
        
        //Beregn controlSignal
        float error = setPoint - temp;
        float proportionalPart = 0;
        float integralPart = 0;
        float derivativePart = 0;
        controlSignal = PIDControl_doStep(temp, &proportionalPart, &integralPart, &derivativePart);  
        
        //Juster PWM
        if (controlSignal > 100)
            controlSignal = 100;    
        else if (controlSignal < 0)
            controlSignal = 0;
        
        
        PWM_WriteCompare(controlSignal);
        
        
        //Print relevante data til UART
        snprintf(outputBuffer, sizeof(outputBuffer), "%f, %f, %f, %f, %f, %f, %f, %f, %f, %f \r\n", 
                                                      setPoint, temp, error, controlSignal, Kp, Ki, Kd, 
                                                      proportionalPart, integralPart, derivativePart);
        UART_1_PutString(outputBuffer);

        
        //Vent inden næste måling
        CyDelay(sampleWaitTimeInMilliseconds);
        
        
        
        
    }
}


        


 CY_ISR(ISR_UART_rx_handler)
{
    uint8_t bytesToRead = UART_1_GetRxBufferSize();
    while (bytesToRead > 0)
    {
        uint8_t byteReceived = UART_1_ReadRxData();
        UART_1_WriteTxData(byteReceived);
        
        // Sender den modtaget værdi videre
        handleByteReceived(byteReceived);
        
        bytesToRead--;
    }
}

// Modtager værdien sendt fra UARTen
void handleByteReceived(uint8_t byteReceived)
{
    switch(byteReceived)
    {
        case '2' :
        {
            setPoint = 40;
            PIDControl_changeSetPoint(setPoint);
            
        }
        break;
        case '3' :
        {
            setPoint = 50;
            PIDControl_changeSetPoint(setPoint);
        }
        break;
        case '1' :
        {
            setPoint = 30;
            PIDControl_changeSetPoint(setPoint);
        }
        break;
        default :
        {
            // nothing
        }
        break;
    }
}
    
/* [] END OF FILE */
