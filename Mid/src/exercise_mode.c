#include "exercise_mode.h"
/*******************************************************************************
 * Variable
 ******************************************************************************/
static uint8_t change;
/*******************************************************************************
 * Code
 ******************************************************************************/

program_state_t exercise_mode(run_mechine_data_t *mechineData)
{
    program_state_t stateReturn;
    char key;
    /* Show screen */
    if(change == 0)
    {
        updateCalo(mechineData->clo);
        updateDistance(mechineData->dis);
        updateSpeed(mechineData->dataSpeed);
        updateIncline(mechineData->incline);
        updateTime(mechineData->runTime.minute);
    }
    change = 1;    
    /* Scan key */
    key = KEYPAD_ScanKey();
    switch (key)
    {
        /* ex key */
        case '6':
            mechineData->runEx += 1;
            if(mechineData->runEx > 15)
                mechineData->runEx = 1;
            change = 0;
            stateReturn = EXERCISE_SET;
            break;
        /* + key */
        case '4':
            mechineData->runTime.minute += 1;
            if(mechineData->runTime.minute > 120)
                mechineData->runTime.minute = 120;
            change = 0;
            stateReturn = EXERCISE_SET;
            break;
        /* - key */
        case '5':
            mechineData->runTime.minute -= 1;
            if(mechineData->runTime.minute < 1)
                mechineData->runTime.minute = 0;
            change = 0;
            stateReturn = EXERCISE_SET;
            break;
        /* up key */
        case 'A':
            mechineData->runTime.minute += 1;
            if(mechineData->runTime.minute > 120)
                mechineData->runTime.minute = 120;
            change = 0;
            stateReturn = EXERCISE_SET;
            break;
        /* down key */
        case 'B':
            mechineData->runTime.minute -= 1;
            if(mechineData->runTime.minute < 0)
                mechineData->runTime.minute = 0;
            change = 0;
            stateReturn = EXERCISE_SET;
            break;
        /* stop key */
        case '8':
            mechineData->runTime.minute += 1;
            if(mechineData->runTime.minute > 120)
                mechineData->runTime.minute = 120;
            change = 0;
            stateReturn = START;
            break;
        /* run key */
        case '7':
            change = 0;
            stateReturn = RUN;
            break;
        default:
            change = 0;
            stateReturn = EXERCISE_SET;
            break;
    }
    return (stateReturn);
}
/*******************************************************************************
 * EOF
 ******************************************************************************/
