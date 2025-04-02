#ifndef ACTIONS_H_
#define ACTIONS_H_

#include <stdio.h>
#include <assert.h>

// CLAY includes
#include "clay.h"

void ClayLogAction(Clay_ElementId elementId, Clay_PointerData pointerInfo, intptr_t userData)
{
    assert(userData == (intptr_t) 0 && "Some DATA are passed to ClayLogAction function\n");
    
    if (pointerInfo.state == CLAY_POINTER_DATA_PRESSED_THIS_FRAME)
    {
        LOG("CLICK: '%s'\n", elementId.stringId.chars);
    }
}

#endif // ACTIONS_H_
