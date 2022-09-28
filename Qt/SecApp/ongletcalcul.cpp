#include "ongletcalcul.h"
#include "ui_ongletcalcul.h"
#include "cable.h"
#include <iostream>
#include <algorithm>
#include <QListView>
#include <QPrinter>
#include <QPainter>


cable tableauTab(0);

OngletCalcul::OngletCalcul(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OngletCalcul)
{
    ui->setupUi(this);
    ui->comboBox->setView(new QListView());
}

OngletCalcul::~OngletCalcul()
{
    delete ui;
}

int OngletCalcul::getIMethod(){ //varFunc 0 = puissance, 1 = puissance relative, 2 = intensité
    int retVal = 99;
    if (ui->radioButton_2->isChecked() == 1){
        retVal = 2;
    }
    if (ui->radioButton->isChecked() == 1){
        retVal = 1;
    }
    if (ui->radioButton_3->isChecked() == 1){
        retVal = 3;
    }

    return retVal;
}

float getI(cable* tableau, float P, float S, float I, int varFunc, bool tri){ //varFunc 1 = puissance, 3 = puissance relative, 2 = intensité
    if (varFunc == 2){
    }
    else if(varFunc == 3){        //Puissance relative
        if (tableau->phase == 0){
            I = S/tableau->V;
        }
        else{
            I = S/(1.732*tableau->V);
        }
    }
    else if(varFunc == 1){       //Puissance
        if (tableau->phase == 0){
            I = P/(tableau->V*tableau->cosPhi);
        }
        else{
            I = P/(tableau->V*1.732*tableau->cosPhi);
        }
    }
    return I;
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
    tableauTab.I = getI(&tableauTab, ui->vCourant->value(), ui->vCourant->value(), ui->vCourant->value(), getIMethod(), tableauTab.phase);
    tableauTab.ChuteV = ui->vChuteV->value();
    //tableauTab.phase = ui->rTriphase->isChecked();

    UprimeMax = (tableauTab.V*tableauTab.ChuteV);   //calcul
    step1 = ((2*ui->vLongueur->value()*tableauTab.I)*100);
    step2 = (UprimeMax/step1)-tableauTab.X*tableauTab.sinPhi;
    step2 = step2/tableauTab.cosPhi;
    step2 = (tableauTab.p/step2)/(tableauTab.phase+1);


    FinalResult = tableauTab.searchNearest(step2, tableauTab.SecTab);


    sectionIndex = tableauTab.getIndex(FinalResult, tableauTab.SecTab); //Récupération de l'index de l'actuelle section calculée


/****************************************  Vérification du courant max  **************************************************/

    if(tableauTab.matiere == 0 &&  tableauTab.phase == 0){ //Ctype = cuivre / alu
        formerIz = tableauTab.izMonoCuivreTab[sectionIndex];
        actualIz = tableauTab.searchNearest(tableauTab.I, tableauTab.izMonoCuivreTab);
        sectionIndex = tableauTab.getIndex(actualIz, tableauTab.izMonoCuivreTab);
    }
    else if(tableauTab.matiere == 0 &&  tableauTab.phase == 1){
        formerIz = tableauTab.izTriCuivreTab[sectionIndex];
        actualIz = tableauTab.searchNearest(tableauTab.I, tableauTab.izTriCuivreTab);
        sectionIndex = tableauTab.getIndex(actualIz, tableauTab.izTriCuivreTab);
    }
    else if(tableauTab.matiere == 1 &&  tableauTab.phase == 0){
        formerIz = tableauTab.izMonoAluTab[sectionIndex];
        actualIz = tableauTab.searchNearest(tableauTab.I, tableauTab.izMonoAluTab);
        sectionIndex = tableauTab.getIndex(actualIz, tableauTab.izMonoAluTab);
    }
    else if(tableauTab.matiere == 1 &&  tableauTab.phase == 1){
        formerIz = tableauTab.izTriAluTab[sectionIndex];
        actualIz = tableauTab.searchNearest(tableauTab.I, tableauTab.izTriAluTab);
        sectionIndex = tableauTab.getIndex(actualIz, tableauTab.izTriAluTab);
    }
    else
    {
        actualIz = 999999;
        FinalResult = 999999; //simple sécurité
    }
/***********************************************************************************************************************/

    if (formerIz < tableauTab.I){

        FinalResult = tableauTab.SecTab[sectionIndex];
    }

    if(tableauTab.p == palu && FinalResult < 16){
        FinalResult = 16;
    }

    ui->dvResult->setValue(FinalResult);
    ui->doubleSpinBox->setValue(tableauTab.chuteReele(ui->vLongueur->value(),tableauTab.I, FinalResult, tableauTab.phase, tableauTab.matiere));



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


void OngletCalcul::on_pushButton_clicked()
{
   QPrinter printer;
   printer.setOutputFormat(QPrinter::PdfFormat);
   printer.setOutputFileName("/foobar/nonwritable.pdf");
   QPainter painter;
   if (! painter.begin(&printer)) { // failed to open file
       qWarning("failed to open file, is it writable?");
   }
   painter.drawText(10, 10, "Test");
   if (! printer.newPage()) {
       qWarning("failed in flushing page to disk, disk full?");
   }
   painter.drawText(10, 10, "Test 2");
   painter.end();
}

