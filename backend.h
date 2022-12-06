#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>
#include <QString>
#include <qqml.h>

class Backend : public QObject
{
    Q_OBJECT
public:
    Backend();


signals:

public slots:
    void setInstallation(QString choix);
    QString getInstallation();

    void setCableElementType(QString choix);
    QString getCableElementType();

    void setCablePhaseType(QString choix);
    QString getCablePhaseType();

    void setLongueurCable(int choix);
    int getLongueurCable();

    void setValeur(int choix);
    int getValeur();

    void setTensionRelativeMax(float choix);
    float getTensionRelativeMax();

    void setTensionReele(float choix);
    float getTensionReele();

    void setSection(int choix);
    int getSection();

    void test();
private:
    QString installationType;
    QString cableElementType;
    QString cablePhaseType;
    int longueurCable;
    int valeur;
    float tensionRelativeMax;
    float chuteReele;
    int section;
};

#endif // BACKEND_H
