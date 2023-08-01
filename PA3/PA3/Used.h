//-----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#ifndef USED_H
#define USED_H

#include "Type.h"

class Free;

class Used
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
    Used       *pNext;        // next free Type
    Used       *pPrev;        // prev free Type  

    // helper functions
    Used(uint32_t BlockSize);
    uint32_t TotalDataSize();
};

#endif 

// ---  End of File ---

