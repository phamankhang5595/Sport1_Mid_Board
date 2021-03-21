#include "keypad.h"
#include "common.h"
#include "exercise_mode.h"
void exerciseMode(run_mechine_data_t *mechineData)
{
    char key;
    /* Show screen */
    key =KEYPAD_ScanKey();
    /* key != stop, runkey */
    while((key!= '1') & (key != 'G'))
    {
        key =KEYPAD_ScanKey();
        /* key == + or up */
        if(key == '2' || key == '3')
        {
            mechineData->runTime += 1;
            /* Show Ex screen */
        }
        /* key == ex */
        else if(key == '4')
        {
            mechineData->runEx +=1;
        }
    }

}