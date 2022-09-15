#include "ongletcalcul.h"
#include "ui_ongletcalcul.h"
#include "cable.h"

cable tableauTab(0);

OngletCalcul::OngletCalcul(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OngletCalcul)
{
    ui->setupUi(this);
}

OngletCalcul::~OngletCalcul()
{
    delete ui;
}

void OngletCalcul::on_callResult_clicked()
{
    float pcui = 0.023;
    float palu = 0.037;

    float UprimeMax = 0;
    float step1 = 0;
    float step2 = 0;


    if (ui->cType->currentIndex() == 0){
        tableauTab.p = pcui;
    }
    else {
        tableauTab.p = palu;
    }
    if (ui->cPhase->currentIndex() == 0){
        tableauTab.phase = 0;
    }
    else if (ui->cPhase->currentIndex() == 1){
        tableauTab.phase = 1;
    }

    tableauTab.ChuteV = ui->vChuteV->value();
    //tableauTab.phase = ui->rTriphase->isChecked();

    UprimeMax = (tableauTab.V*tableauTab.ChuteV);   //calcul
    step1 = ((2*ui->vLongueur->value()*ui->vCourant->value())*100);
    step2 = (UprimeMax/step1)-tableauTab.X*tableauTab.sinPhi;
    step2 = step2/tableauTab.cosPhi;
    step2 = (tableauTab.p/step2)/(tableauTab.phase+1);


    ui->dvResult->setValue(tableauTab.searchNearest(step2));
}


void OngletCalcul::on_comboBox_currentIndexChanged(int index)
{
    switch (index){
        case 0:
            ui->vChuteV->setValue(1);
            break;
        case 1:
            ui->vChuteV->setValue(2);
            break;
        case 2:
            ui->vChuteV->setValue(5);
            break;
   }
}

