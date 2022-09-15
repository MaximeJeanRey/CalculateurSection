#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QTimer>
#include "cable.h"
#include "ongletcalcul.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->tabWidget->insertTab(ui->tabWidget->count()-1, new OngletCalcul(), QIcon(QString("")), "Etage 1");
    ui->tabWidget->removeTab(0);
    ui->tabWidget->setCurrentIndex(ui->tabWidget->count()-2);
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_pushButton_clicked()
{

}

void MainWindow::on_pushButton_pressed()
{
    //Ajouter une sécurité au nombre d'onglets
    ui->tabWidget->insertTab(ui->tabWidget->count()-1, new OngletCalcul(), QIcon(QString("")), "Etage " );
    ui->tabWidget->setCurrentIndex(ui->tabWidget->count()-2);
}



void MainWindow::on_tabWidget_tabCloseRequested(int index)
{
    if (index != ui->tabWidget->count()-1){
        ui->tabWidget->removeTab(index);
    }

//   if (index != ui->tabWidget->count()){
//        ui->tabWidget->removeTab(index);
//   }
}


void MainWindow::on_tabWidget_tabBarClicked(int index)
{
    if (index != ui->tabWidget->count()){
        ui->tabWidget->setCurrentIndex(ui->tabWidget->count()-2);
    }
}



