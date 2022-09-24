#include "ongletcalcul.h"
#include "ui_ongletcalcul.h"
#include "cable.h"
#include <iostream>
#include <algorithm>

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
    float FinalResult = 0;
    float actualIz = 0;
    float formerIz = 0;
    int sectionIndex = 0;

    float pcui = 0.023;
    float palu = 0.037;

    float UprimeMax = 0;
    float step1 = 0;
    float step2 = 0;


    if (ui->cType->currentIndex() == 0){
        tableauTab.p = pcui;
        tableauTab.matiere = 0;
    }
    else {
        tableauTab.p = palu;
        tableauTab.matiere = 1;
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


    FinalResult = tableauTab.searchNearest(step2, tableauTab.SecTab);


    sectionIndex = tableauTab.getIndex(FinalResult, tableauTab.SecTab); //Récupération de l'index de l'actuelle section calculée


    if(tableauTab.matiere == 0 &&  tableauTab.phase == 0){ //Ctype = cuivre / alu
        formerIz = tableauTab.izMonoCuivreTab[sectionIndex];
        actualIz = tableauTab.searchNearest(ui->vCourant->value(), tableauTab.izMonoCuivreTab);
        sectionIndex = tableauTab.getIndex(actualIz, tableauTab.izMonoCuivreTab);
    }
    else if(tableauTab.matiere == 0 &&  tableauTab.phase == 1){
        formerIz = tableauTab.izTriCuivreTab[sectionIndex];
        actualIz = tableauTab.searchNearest(ui->vCourant->value(), tableauTab.izTriCuivreTab);
        sectionIndex = tableauTab.getIndex(actualIz, tableauTab.izTriCuivreTab);
    }
    else if(tableauTab.matiere == 1 &&  tableauTab.phase == 0){
        formerIz = tableauTab.izMonoAluTab[sectionIndex];
        actualIz = tableauTab.searchNearest(ui->vCourant->value(), tableauTab.izMonoAluTab);
        sectionIndex = tableauTab.getIndex(actualIz, tableauTab.izMonoAluTab);
    }
    else if(tableauTab.matiere == 1 &&  tableauTab.phase == 1){
        formerIz = tableauTab.izTriAluTab[sectionIndex];
        actualIz = tableauTab.searchNearest(ui->vCourant->value(), tableauTab.izTriAluTab);
        sectionIndex = tableauTab.getIndex(actualIz, tableauTab.izTriAluTab);
    }
    else
    {
        actualIz = 999999;
        FinalResult = 999999; //simple sécurité
    }

    if (formerIz < ui->vCourant->value()){

        FinalResult = tableauTab.SecTab[sectionIndex];
    }

    if(tableauTab.p == palu && FinalResult < 16){
        FinalResult = 16;
    }

    ui->dvResult->setValue(FinalResult);
    ui->doubleSpinBox->setValue(tableauTab.chuteReele(ui->vLongueur->value(),ui->vCourant->value(), FinalResult, tableauTab.phase, tableauTab.matiere));



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

