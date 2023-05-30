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

typedef enum 
{
 boot,
 going,



 
} stages;




void setSpeeds(int16 left, int16 right){ /*BEGINNING OF FUNCTION_____________________________________________________________________________________________*/
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
    
    
    int16 w=20;     //the width of the car
    int16 vl=speed-turnrad*w/2; //speed of left wheels
    int16 vr=speed+turnrad*w/2;      //speed of right wheels
setSpeeds(vl,vr);
/*END OF FUNCTION_______________________________________________________________________________________________________*/
};

states setState(int16 left, int16 right){  /*BEGINNING OF STATE SETTING FUNCTION_________________________________________*/

        
        {if ((left==0 && right==0) ){
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
        else return LineNo;
        }
        

/*END OF FUNCTION_______________________________________________________________________________________________________*/
};

events setEvent(states curState, states prevState){/*BEGINNING OF EVENT SETTING FUNCTION___________________________________________________________________________________*/
    
        if ((curState==LineNo )   &&(prevState==LineAtLeft || prevState==LineAtRight)    ) {
                     return go_straight;   
                }
        if (curState==LineAtLeft ){
                     return turn_left;   
                }
        if (curState==LineAtRight ){
                     return turn_right;   
                }
        if (curState==LineOn ){
                     return turn_right;   
                }
        if (curState==idle ){
                     return none;   
                }
        
        
        
        
        
    /*    if ((curState==LineNo )       &&!(prevState==LineAtLeft || prevState==LineAtRight)             ) {
                     return seek_line;
        }
      */        

else return go_straight;
/*END OF FUNCTION_______________________________________________________________________________________________________*/
};

void execute (events event,int16 speed){
  switch (event) {       
    case go_straight:
        calSpeed(speed,0); 
        break;
    case turn_left:
        calSpeed(speed,-20);  
        break;
    case turn_right:
        calSpeed(speed,20);        
        break;
    case seek_line:
       calSpeed(speed,30);
        break;
    case none:
       setSpeeds(0,0);
        break;
    default:
        setSpeeds(0,0);



};
};

    
    

uint32_t lasttime=0; //needed for timer
uint8_t ismytimer(){
    
        uint32_t now = CySysTickGetValue();
        if(now-lasttime > 100){
            return 1;
        }
        return 0;
    
}

uint8_t ismytimer2(){
    
        uint32_t now = CySysTickGetValue();
        if(now-lasttime > 5000){
            return 1;
        }
        return 0;
    
}




int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    Left_Motor_PWM_Start();
    Right_Motor_PWM_Start();
    setSpeeds(0,0);
    CySysTickStart(); 
    
    int16 Is_Going=0;
    uint16 result=0;
    uint16 prev_result=0;
    
    
    
    
    states curState=idle;
    states prevState=idle;
    
    events event=none;
    
    int speed=100;
    
    
    ADC_SAR_1_Start();
    LCD_Char_1_Start();
    LCD_Char_1_PrintString("Hello");
    
    for(;;)
    {
     /*START OF FOR LOOP_________________________________________________________________________________________________*/
         if(ismytimer()){
       
    if (BTN_Read()) {Is_Going++;};
    prevState=curState;                         // *set previous and current states
    curState=setState(IRL_Read(),IRR_Read());  // *
    event=setEvent(curState,prevState);         //set event based on current and previous states

   
    
execute(event, speed);        
 
};

         if(ismytimer2()){
    prev_result=result;
    ADC_SAR_1_StartConvert();
    result=ADC_SAR_1_GetResult16();
    ADC_SAR_1_StopConvert();
    
    if((prev_result+1<result) || (prev_result-1>result)){
    
        LCD_Char_1_ClearDisplay();
    LCD_Char_1_PrintString("ADC result: ");
    LCD_Char_1_PrintNumber(result);}
    
    speed=result/20;
    };
        
        
        
        
        
    
    /*END OF FOR LOOP________________________________________________________________________________________________*/
    };
    
    
   
    
    
    
    /*END OF MAIN FUNCTION*/
    };


/* [] END OF FILE */