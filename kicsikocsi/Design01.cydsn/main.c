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


typedef enum 
{
 go_straight,
 turn_left,
 turn_right,
 seek_line,
 none
} states; 




void setSpeeds(int16 left, int16 right){ 
//start of function_________________________________________________________________________________________
int8 killControl=0;    
    
if (left<0){
    Left_Motor_PWM_WriteCompare(-1*left);
    Left_Motor_DIR_Write(1);
}else{
    Left_Motor_PWM_WriteCompare(left);
    Left_Motor_DIR_Write(0);
    }


if (right<0){
    Right_Motor_PWM_WriteCompare(-1*right);
    Right_Motor_DIR_Write(1);
}else{
    Right_Motor_PWM_WriteCompare(right);
    Right_Motor_DIR_Write(0);
    }


if (left==0){
    killControl=1;
    }
    
if (right==0){
   
     killControl=killControl+2;
    }
    
    Reg_PWM_Enable_Write(killControl);



 // end of function_________________________________________________________________________________________
};




int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    Left_Motor_PWM_Start();
    Right_Motor_PWM_Start();
    setSpeeds(0,0);
    
 states state = go_straight;
    
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    
    for(;;)
    {
    /* Place your application code here. */
       
        
        
        if ((IRL_Read()==0 && IRR_Read()==0) || (IRL_Read()==1 && IRR_Read()==1)){
             state=seek_line;   
        }
        if (IRL_Read()==0 && IRR_Read()==1){
            state=turn_left;
        }
        if (IRL_Read()==1 && IRR_Read()==0){
            state=turn_right;
        } 
           
        switch (state) {
    case go_straight:
        setSpeeds(100,150);
        break;
    case turn_left:
        setSpeeds(30,150);
        break;
    case turn_right:
        setSpeeds(150,30);
        break;
    case seek_line:
       setSpeeds(150,50);
        break;
    default:
        setSpeeds(0,0);
        
        
        
        
        
        
        
        }
        
    
    };
    
    
    
    
    
    
    
    
    
    
    
    
    
        
        
    }


/* [] END OF FILE */
