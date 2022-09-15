#include "cable.h"
#include <cstdlib>
cable::cable(bool phase)
{
    this->phase = phase;
}

float cable::searchNearest(float key)
{
    float value = 0;
    float previousValue;
    int num = 0;

    if (key < 0){
        return -1;
    }
    for(int x = 0; x<16; x++)
    {
        value = key - this->SecTab[x];
        if(value < 0)
        {
           return this->SecTab[x];
        }
   }
   return -1;
}
