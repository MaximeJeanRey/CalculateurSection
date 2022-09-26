#ifndef ONGLETCALCUL_H
#define ONGLETCALCUL_H

#include <QWidget>

namespace Ui {
class OngletCalcul;
}

class OngletCalcul : public QWidget
{
    Q_OBJECT

public:
    explicit OngletCalcul(QWidget *parent = nullptr);
    int getIMethod();
    ~OngletCalcul();

private slots:
    void on_callResult_clicked();

    void on_comboBox_currentIndexChanged(int index);


private:
    Ui::OngletCalcul *ui;
};

#endif // ONGLETCALCUL_H
