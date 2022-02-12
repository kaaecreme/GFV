#include "functions.h"

//Variables
uint16_t speedDelay = 20; // Used to set Stepper motor speed (delay) 
uint8_t state = 1; // Used to change switch between 1/A = Full, 2/S = Half, 3/D = Wave
uint8_t direction = 0; // Used to save direction. 0 = Stopped, 1 = Forwards, 2 = Backwards

uint16_t getDirection(void) {
    return direction;
}

uint8_t getState(void) {
    return state;    
}

void run(char byte) {
    switch(byte)
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
            changeState(1);
        }
        break;
        
        // Change to half step
        case 's' :
        {
            changeState(2);
        }
        break;
        
        // Change to wave-drive
        case 'd' :
        {
            changeState(3);
        }
        break;
        default :
        {
            // nothing
        }
        break;
    }
}

void changeState(int stateNumb) {
    state = stateNumb;
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
