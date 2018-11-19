//
//  main.c
//  cs220proj2
//
//  Created by Mehmet Alican Görk on 18/03/16.
//  Copyright © 2016 Mehmet Alican Görk. All rights reserved.
//

#include "slots.h"
#include <stdio.h>
#define forEachSlot(X) for(X=0;X<NUMSLOTS;X++)

int allSlotsAreFull(int *slots);


int main(int argc, char ** argv) {
    
    int bin;
    int slotOccasions[4] = {0,};
    int filledSlots[4] = {0,};
    int i, minimumOccuredSlot = 0;;
    
    initSlots();
    while(1==scanf("%d",&bin))
    {
        for( i = 0 ; i < NUMSLOTS -1 ;i++)           //------------------------------------------------
        {
            if( slotOccasions[i] > slotOccasions[i+1])
            {                                        //DETERMINE MAX OCCURED SLOT
                minimumOccuredSlot = i+1;
            }
        }                                            //----------------------------------------------
        
        forEachSlot(i)
        {
            if(filledSlots[i] == 0 && findSlot(bin) == -1)
            {
                getBin(bin, i);
                filledSlots[i] = 1;
                slotOccasions[i]++;
            }
            else
            {
                slotOccasions[i]++;
            }
        }
        
        if(allSlotsAreFull(filledSlots) && findSlot(bin) == -1)
        {
            getBin(bin, minimumOccuredSlot);
            slotOccasions[minimumOccuredSlot] = 0;
        }
        
        printf("MIN SLOT = %d\n", minimumOccuredSlot);
        getWidget(bin);
    }
    printEarnings();
    return 0;
}


int allSlotsAreFull(int *slots)
{
    int i;
    forEachSlot(i)
    {
        if (slots[i] == 0)
        {
            return 0;
        }
    }
    return 1;
}

