#ifndef CABLE_H
#define CABLE_H


class cable
{
public:
    cable(bool phase);

    float searchNearest(float key, float tabToSearch[]);
    int getIndex(float element, float arr[16]);
    float chuteReele(float L, float i, float S, bool tri, bool mat);


    float p = 0.00;


    float scui = 4; //section du cable cuivre en mm²
    float salu = 6; //section du cable alu en mm²

    float cosPhi = 0.8;

    float sinPhi = 0.0013;

    float X = 0.08;

    float V = 230;
    float I = 0;

    float ChuteV = 7; //%

    float pcui = 0.023;
    float palu = 0.037;



    int phase =0; //0 = mono   1 = tri
    int matiere = 0;//0 = cuivre 1 = alu

    float SecTab[16] = {1.5,2.5,4,6,10,16,25,35,50,70,95,120,150,185,240,300};

    float izMonoCuivreTab[16] =
    {26.4,36.3,48.6,62.6,86.1,115.3,148.8,184.9,255.2,289.4,352.5,409.9,473.4,542.1,641.4,740.9};
    float izTriCuivreTab[16] =
    {22.9,31.5,42.2,54.4,74.7,100.1,127.4,157.9,191.8,245.6,298.3,346.2,399,456.1,538.3,620.5};
    float izMonoAluTab[16] =
    {20.6,28.4,38.1,49,67.5,90.5,108.2,134.6,164.2,211.1,257.4,299.6,346.2,396.7,469.7,542.9};
    float izTriAluTab[16] =
    {17.6,24.2,32.5,41.8,57.5,77.1,97.3,120.5,146.2,187.1,227.11,263.4,303.5,346.8,409.1,471.3};
};

#endif // CABLE_H
