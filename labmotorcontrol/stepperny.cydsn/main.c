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
#include "project.h"

CY_ISR_PROTO(ISR_UART_rx_handler);
void handleByteReceived(uint8_t byteReceived);

void decreaseSpeed(void);
void increaseSpeed(void);
void driveForwards(void);
void driveBackwards(void);
void stop(void);

// States
void driveForwardsHalf(void);
void driveForwardsFull(void);
void driveForwardsWave(void);

void driveBackwardsHalf(void);
void driveBackwardsFull(void);
void driveBackwardsWave(void);

void runOnceForward(void);
void runOnceBackwards(void);

uint16_t speedDelay = 20; // Used to set Stepper motor speed (delay) 
uint8_t state = 1; // Used to change switch between 1/A = Full, 2/S = Half, 3/D = Wave
uint8_t direction = 0; // Used to save direction. 0 = Stopped, 1 = Forwards, 2 = Backwards

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
        switch(direction) {
            
            // Forwards
            case 1 :
            {
                switch(state) {
                    
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
            
            // Backwards
            case 2 :
            {
                switch(state) {
                    
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
    switch(byteReceived)
    {
        case 'q' :
        {
            decreaseSpeed();
        }
        break;
        case 'w' :
        {
            increaseSpeed();
        }
        break;
        
        case 'e' :
        {
            runOnceForward();
        }
        break;
        
        case 'r' :
        {
            runOnceBackwards();
        }
        break;
        
        case '1' :
        {
            driveForwards();
        }
        break;
        
        case '2' :
        {
            driveBackwards();
        }
        break;
        
        case '0' :
        {
            stop();
        }
        break;
        
        // Change to full step
        case 'a' :
        {
            
            state = 1;
        }
        break;
        
        // Change to half step
        case 's' :
        {
            state = 2;
        }
        break;
        
        // Change to wave-drive
        case 'd' :
        {
            state = 3;
        }
        break;
        default :
        {
            // nothing
        }
        break;
    }
}

void decreaseSpeed()
{
    if(speedDelay < 100) {
        speedDelay += 2;   
    } else {
        UART_1_PutString("Motor cannot go slower\r\n");
    }
}

void increaseSpeed()
{
    if(speedDelay > 2) {
        speedDelay -= 2;   
    } else {
        UART_1_PutString("Motor cannot go faster\r\n");
    }
}

void driveForwards()
{
    direction = 1;
}

void driveBackwards()
{
    direction = 2;
}

void stop()
{
    direction = 0;
    A1_Green_Write(0);
    A2_Orange_Write(0);
    B1_Purple_Write(0);
    B2_White_Write(0);
}

void driveForwardsHalf() {
    A1_Green_Write(1);
    A2_Orange_Write(0);
    B1_Purple_Write(1);
    B2_White_Write(0);
    CyDelay(speedDelay);
                
    A1_Green_Write(0);
    A2_Orange_Write(1);
    B1_Purple_Write(0);
    B2_White_Write(0);
    CyDelay(speedDelay);
                
    A1_Green_Write(0);
    A2_Orange_Write(1);
    B1_Purple_Write(1);
    B2_White_Write(0);
    CyDelay(speedDelay);
                
    A1_Green_Write(0);
    A2_Orange_Write(1);
    B1_Purple_Write(0);
    B2_White_Write(0); 
    CyDelay(speedDelay); 
    
    A1_Green_Write(0);
    A2_Orange_Write(1);
    B1_Purple_Write(0);
    B2_White_Write(1); 
    CyDelay(speedDelay); 
    
    A1_Green_Write(0);
    A2_Orange_Write(0);
    B1_Purple_Write(0);
    B2_White_Write(1); 
    CyDelay(speedDelay);
    
    A1_Green_Write(1);
    A2_Orange_Write(0);
    B1_Purple_Write(0);
    B2_White_Write(1); 
    CyDelay(speedDelay); 
    
    A1_Green_Write(1);
    A2_Orange_Write(0);
    B1_Purple_Write(0);
    B2_White_Write(0); 
    CyDelay(speedDelay);  
    
}
void driveForwardsFull() {
    A1_Green_Write(1);
    A2_Orange_Write(0);
    B1_Purple_Write(1);
    B2_White_Write(0);
    CyDelay(speedDelay);
    
    A1_Green_Write(0);
    A2_Orange_Write(1);
    B1_Purple_Write(1);
    B2_White_Write(0);
    CyDelay(speedDelay);
    
    A1_Green_Write(0);
    A2_Orange_Write(1);
    B1_Purple_Write(0);
    B2_White_Write(1);
    CyDelay(speedDelay);
    
    A1_Green_Write(1);
    A2_Orange_Write(0);
    B1_Purple_Write(0);
    B2_White_Write(1);
    CyDelay(speedDelay);

}
void driveForwardsWave() {
    A1_Green_Write(1);
    A2_Orange_Write(0);
    B1_Purple_Write(0);
    B2_White_Write(0);
    CyDelay(speedDelay);
    
    A1_Green_Write(0);
    A2_Orange_Write(0);
    B1_Purple_Write(1);
    B2_White_Write(0);
    CyDelay(speedDelay);
    
    A1_Green_Write(0);
    A2_Orange_Write(1);
    B1_Purple_Write(0);
    B2_White_Write(0);
    CyDelay(speedDelay);
    
    A1_Green_Write(0);
    A2_Orange_Write(0);
    B1_Purple_Write(0);
    B2_White_Write(1);
    CyDelay(speedDelay);
}

void driveBackwardsHalf() {
    A1_Green_Write(1);
    A2_Orange_Write(0);
    B1_Purple_Write(0);
    B2_White_Write(0); 
    CyDelay(speedDelay);  
    
    A1_Green_Write(1);
    A2_Orange_Write(0);
    B1_Purple_Write(0);
    B2_White_Write(1); 
    CyDelay(speedDelay);
    
    A1_Green_Write(0);
    A2_Orange_Write(0);
    B1_Purple_Write(0);
    B2_White_Write(1); 
    CyDelay(speedDelay);
    
    A1_Green_Write(0);
    A2_Orange_Write(1);
    B1_Purple_Write(0);
    B2_White_Write(1); 
    CyDelay(speedDelay); 
    
    A1_Green_Write(0);
    A2_Orange_Write(1);
    B1_Purple_Write(0);
    B2_White_Write(0); 
    CyDelay(speedDelay); 
    
    A1_Green_Write(0);
    A2_Orange_Write(1);
    B1_Purple_Write(1);
    B2_White_Write(0);
    CyDelay(speedDelay);
    
    A1_Green_Write(0);
    A2_Orange_Write(1);
    B1_Purple_Write(0);
    B2_White_Write(0);
    CyDelay(speedDelay);
    
    A1_Green_Write(1);
    A2_Orange_Write(0);
    B1_Purple_Write(1);
    B2_White_Write(0);
    CyDelay(speedDelay);
}
void driveBackwardsFull() {
    A1_Green_Write(1);
    A2_Orange_Write(0);
    B1_Purple_Write(0);
    B2_White_Write(1);
    CyDelay(speedDelay);
    
    A1_Green_Write(0);
    A2_Orange_Write(1);
    B1_Purple_Write(0);
    B2_White_Write(1);
    CyDelay(speedDelay);
    
    A1_Green_Write(0);
    A2_Orange_Write(1);
    B1_Purple_Write(1);
    B2_White_Write(0);
    CyDelay(speedDelay);
    
    A1_Green_Write(1);
    A2_Orange_Write(0);
    B1_Purple_Write(1);
    B2_White_Write(0);
    CyDelay(speedDelay);
   
}
void driveBackwardsWave() {

    A1_Green_Write(0);
    A2_Orange_Write(0);
    B1_Purple_Write(0);
    B2_White_Write(1);
    CyDelay(speedDelay);
     
    A1_Green_Write(0);
    A2_Orange_Write(1);
    B1_Purple_Write(0);
    B2_White_Write(0);
    CyDelay(speedDelay);

    A1_Green_Write(0);
    A2_Orange_Write(0);
    B1_Purple_Write(1);
    B2_White_Write(0);
    CyDelay(speedDelay);
    
    A1_Green_Write(1);
    A2_Orange_Write(0);
    B1_Purple_Write(0);
    B2_White_Write(0);
    CyDelay(speedDelay);

}

void runOnceForward() {
    
    for (uint32_t i = 0; i < 12; i++){
        switch(state) {
            
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
    
    
    direction = 0; // Stop
}
void runOnceBackwards() {
    
    for (uint32_t i = 0; i < 12; i++){
        switch(state) {
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
                //Nothing
            }
            break;
        }     
    }
    direction = 0; // Stop    
    
}

/* [] END OF FILE */
