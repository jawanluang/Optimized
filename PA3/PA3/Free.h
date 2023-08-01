//-----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#ifndef FREE_H
#define FREE_H

#include "Type.h"

class Used;

class Free
{
public:
    // ---------------------------------------------------------
    // Do not reorder, change or add data fields
    //     --> any changes to the data... 0 given to the assignment
    // You can add methods if you wish
    // ---------------------------------------------------------

    Type       mType;         // Type type 
    bool       bAboveFree;    // Type above is free (T/F)
    uint16_t   mDataSize;     // size of Type (16 bit)
    Free       *pNext;        // next free Type
    Free       *pPrev;        // prev free Type                              
    
    //helper functions
    Free(uint32_t BlockSize);
    uint32_t TotalDataSize();
};

#endif 

// ---  End of File ---
