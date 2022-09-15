#ifndef CABLE_H
#define CABLE_H


class cable
{
public:
    cable(bool phase);
    float searchNearest(float key);

    float p = 0.00;


    float scui = 4; //section du cable cuivre en mm²
    float salu = 6; //section du cable alu en mm²

    float cosPhi = 0.8;

    float sinPhi = 0.0013;

    float X = 0.08;

    float V = 230;

    float ChuteV = 7; //%


    int phase =0; //0 = mono   1 = tri

    float SecTab[16] = {1.5,2.5,4,6,10,16,25,35,50,70,95,120,150,185,240,300};

};

#endif // CABLE_H
