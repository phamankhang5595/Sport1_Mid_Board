#include "setup_mode.h"
#include "keypad.h"
#include "systick.h"
#include "screen.h"
/*******************************************************************************
 * Variables
 ******************************************************************************/
uint8_t modeState;
uint8_t IsDataChanged;
/*******************************************************************************
 * Definition
 ******************************************************************************/
#define NO      1
#define YES     0
/*******************************************************************************
 * Private func
 ******************************************************************************/
/*!
 * @brief 
 *
 * @param 
 * @param 
 */
static void increase_val(run_mechine_data_t *mechineData)
{
    if(modeState == 0)
        mechineData->runTime.minute += 1;
    else if(modeState == 1)
        mechineData->dis += 1;
    else if(modeState == 2)
        mechineData->clo += 1;
}


/*!
 * @brief 
 *
 * @param 
 * @param 
 */
static void decrease_val(run_mechine_data_t *mechineData)
{
    if(modeState == 0)
        mechineData->runTime.minute -= 1;
    else if(modeState == 1)
        mechineData->dis -= 1;
    else if(modeState == 2)
        mechineData->clo -= 1;
}
/*******************************************************************************
 * Code
 ******************************************************************************/
/*!
 * @brief 
 *
 * @param 
 * @param 
 */
program_state_t setup_mode(run_mechine_data_t *mechineData)
{
    program_state_t stateReturn;
    char key = NO_KEY;
    
    /* Show screen */
    if(IsDataChanged == YES)
    {
        updateCalo(mechineData->clo);
        updateDistance(mechineData->dis);
        //updateSpeed(mechineData->dataSpeed);
        //updateIncline(mechineData->incline);
        updateTime(mechineData->runTime.minute);
    }
    IsDataChanged = NO;    
    /* Scan key */
    key = KEYPAD_ScanKey();
    switch(key)
    {
        case '9':
            SYSTICK_Delay_ms(200);
                modeState += 1;
            stateReturn = USER_SET;
            break;
        case '4':
            increase_val(mechineData);
            IsDataChanged = YES;
            stateReturn = USER_SET;
            break;
        case '5':
            decrease_val(mechineData);
            IsDataChanged = YES;
            stateReturn = USER_SET;
            break;
        case 'A':
            increase_val(mechineData);
            IsDataChanged = YES;
            stateReturn = USER_SET;
            break;
        case 'B':
            decrease_val(mechineData);
            IsDataChanged = YES;
            stateReturn = USER_SET;
            break;
        case '7':
            IsDataChanged = YES;
            stateReturn = RUN;
            break;
        case '8':
            IsDataChanged = YES;
            stateReturn = START;
            break;
        default:
            stateReturn = USER_SET;
    }
    if(modeState > 2)
    {
        modeState = 0;
        IsDataChanged = YES;
        stateReturn = START;
        SYSTICK_Delay_ms(30);
    }
    return (stateReturn);
}
/*******************************************************************************
 * EOF
 ******************************************************************************/
