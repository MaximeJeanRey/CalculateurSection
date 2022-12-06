#include "backend.h"
#include <QDebug>
Backend::Backend()
{

}

void Backend::test()
{
    qDebug() << "Appelé";
}

void Backend::setInstallation(QString choix){
    this->installationType = choix;
}

QString Backend::getInstallation(){
    return this->installationType;
}

void Backend::setCableElementType(QString choix){
    this->cableElementType = choix;
}

QString Backend::getCableElementType(){
    return this->cableElementType;
}

void Backend::setCablePhaseType(QString choix){
    this->cablePhaseType = choix;
}

QString Backend::getCablePhaseType(){
    return this->cablePhaseType;
}

void Backend::setLongueurCable(int choix){
    this->longueurCable = choix;
}

int Backend::getLongueurCable(){
    return this->longueurCable;
}

void Backend::setValeur(int choix){
    this->valeur = choix;
}

int Backend::getValeur(){
    return this->valeur;
}

void Backend::setTensionRelativeMax(float choix){
    this->valeur = choix;
}

float Backend::getTensionRelativeMax(){
    return this->tensionRelativeMax;
}

void Backend::setTensionReele(float choix){
    this->valeur = choix;
}

float Backend::getTensionReele(){
    return this->chuteReele;
}

void Backend::setSection(int choix){
    this->valeur = choix;
}

int Backend::getSection(){
    return this->section;
}
