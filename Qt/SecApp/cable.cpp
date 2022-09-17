#include "cable.h"
#include <cstdlib>
cable::cable(bool phase)
{
    this->phase = phase;
}

float cable::searchNearest(float key, float tabToSearch[])
{
    float value = 0;
    float previousValue;
    int num = 0;

    if (key < 0){
        return -1;
    }
    for(int x = 0; x<16; x++)
    {
        value = key - tabToSearch[x];
        if(value < 0)
        {
           return tabToSearch[x];
        }
   }
    return -1;
}

int cable::getIndex(float element, float arr[16])
{
    float result= 0;

    for (int i = 0; i <= 16; i++){
        result  = arr[i]/element;
        if (result == 1){
            return i;
        }
    }
    return 0;
}

float cable::chuteReele(float L,float i, float S, bool tri)
{
    float x = (2*i*L*((this->pcui/S)*this->cosPhi+this->X*(this->sinPhi)))/this->V;
    x = x/(tri+1); // si tri = 0 alors on change pas, sinon on divise par deux
    return x*100;
}
