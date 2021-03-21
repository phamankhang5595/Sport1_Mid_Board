/*
 * Copyright (c) 2021
 * Lumi, JSC.
 * All Rights Reserved
 *
 *
 * Description:
 *
 * Author: Truongvv
 *
 * Last Changed By:  $Author: Truongvv $
 * Revision:         $Revision: xxx $
 * Last Changed:     $Date: xxx $
 */
#include "keypad.h"
#include "stdint.h"
#include "exercise_mode.h"
#include "common.h"
char a;
int main(void)
{
    run_mechine_data_t mechineData;
    mechineData.runEx = 1;
    mechineData.runSpeed = 1;
    mechineData.runTime = 0;
    mechineData.dis = 0;
    mechineData.incl = 0;
    char key;
    KEYPAD_Init();
    SYSTICK_Init();
    /* INIT */
	while(1)
    {
        key = KEYPAD_ScanKey();
        a=key;
        if(key == '6')
            exerciseMode();
            /* Run mode */
/*      if(key == Exkey)
            Ex mode
        if(key == Setupkey)
            Setup mode  
            */
	}
}