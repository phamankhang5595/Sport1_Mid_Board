#ifndef __COMMON_H__
#define __COMMON_H__
#include "stdint.h"
/*******************************************************************************
 * Definition
 ******************************************************************************/
/* program states */
typedef enum
{
    START,
    RUN,
    EXERCISE_SET,
    USER_SET,
    STOP,
    IDLE
} program_state_t;

/* program data for display */
typedef struct
{
    uint32_t second;
    uint32_t minute;
}Time_data_t;

typedef struct
{
    float dataSpeed;
    float dis;
    float clo;
    uint8_t runEx;
    Time_data_t runTime;
    uint8_t incline;
} run_mechine_data_t;

#endif /* common.h */