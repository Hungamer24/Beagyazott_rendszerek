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
 LineNo,
 LineOn,
 LineAtRight,
 LineAtLeft,
 idle
} states; 

typedef enum 
{
 go_straight,
 turn_left,
 turn_right,
 seek_line,
 none
 
} events; 


void setSpeeds(int16 left, int16 right){ 
/*BEGINNING OF FUNCTION_____________________________________________________________________________________________*/
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



 /*END OF FUNCTION_______________________________________________________________________________________________________*/
};

void calSpeed(int16 speed,int16 turnrad){/*BEGINNING OF FUNCTION_________________________________________________________*/
    /*======================================================
     *   !!!!!!!REQUIRES SETSPEEDS FUNCTION TO WORK!!!!!!!!!
     *======================================================
    */
    
    
    int16 l=20;     //the width of the car
    int16 v2=((((2*turnrad-l)/(2*turnrad+l))^2*speed^2)/(((2*turnrad-l)/(2*turnrad+l))^2+1))^(1/2); //speed of left wheels
    int16 v1=((speed^2)+(v2^2))^(1/2);      //speed of right wheels
setSpeeds(v1,v2);
/*END OF FUNCTION_______________________________________________________________________________________________________*/
};

states setState(int16 left, int16 right){  //BEGINNING OF STATE SETTING FUNCTION___________________________________________

        if ((left==0 && right==0) ){
             return LineNo;   
        }
        if ((left==1 && right==1) ){
             return LineOn;   
        }
        if (left==0 && right==1){
            return LineAtRight;
        }
        if (left==1 && right==0){
            return LineAtLeft;
        } 
else return idle;
//END OF FUNCTION_________________________________________________________________________________________________________
};

events setEvent(states curState, states prevState){
/*BEGINNING OF EVENT SETTING FUNCTION___________________________________________________________________________________*/
    
        if (curState==LineNo && (prevState==LineAtLeft || prevState==LineAtRight) ){
                     return go_straight;   
                }
        if (curState==LineAtLeft ){
                     return turn_right;   
                }
        if (curState==LineAtRight ){
                     return turn_left;   
                }
        if (curState==LineOn ){
                     return turn_right;   
                }


else return none;
/*END OF FUNCTION_______________________________________________________________________________________________________*/
};

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    Left_Motor_PWM_Start();
    Right_Motor_PWM_Start();
    setSpeeds(0,0);
    
    int sensorLeft=IRL_Read();
    int sensorRight=IRR_Read();
    
    states curState=idle;
    states prevState=idle;
    
    events event=none;
    
    
    for(;;)
    {
    /*START OF FOR LOOP_________________________________________________________________________________________________*/
       
    prevState=curState;                         // *set previous and current states
    curState=setState(sensorLeft,sensorRight);  // *

    event=setEvent(curState,prevState);         //set event based on current and previous states
    
    /*
        switch (event) {        //old switch thingy for setting the event, used before setEvent function [TO BE REMOVED IF PROGRAM WORKS]
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
        };
      */
    
    /*END OF FOR LOOP________________________________________________________________________________________________*/
    };
    
    
    
    
    /*END OF MAIN FUNCTION*/
    }


/* [] END OF FILE */
