#ifndef __common_H__
#define __COMMON_H__
#include "stdint.h"
/*******************************************************************************
 * Definition
 ******************************************************************************/

typedef struct
{
    uint8_t runEx;
    uint8_t runSpeed;
    uint8_t runTime;
    uint8_t dis;
    uint8_t clo;
    uint8_t incl;
} run_mechine_data_t;

#endif