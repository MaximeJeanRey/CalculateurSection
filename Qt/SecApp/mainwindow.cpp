#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QTimer>
#include "cable.h"
#include "ongletcalcul.h"
#include <QListView>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

   // ui->tabWidget->insertTab(ui->tabWidget->count()-1, new OngletCalcul(), QIcon(QString("")), "1");
    ui->tabWidget->removeTab(0);
    ui->tabWidget->setCurrentIndex(ui->tabWidget->count()-2);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_tabWidget_tabCloseRequested(int index)
{
    if (index != ui->tabWidget->count()){
        ui->tabWidget->removeTab(index);
        if(ui->tabWidget->currentIndex() == ui->tabWidget->count()-1){
           ui->tabWidget->setCurrentIndex(ui->tabWidget->count()-2);
        }
        this->renameTab();
    }
}

void MainWindow::on_tabWidget_currentChanged(int index)
{
   if(index == ui->tabWidget->count()-1){
        ui->tabWidget->setCurrentIndex(ui->tabWidget->count()-2);
     }


   if (ui->tabWidget->count() <= 6 && index == ui->tabWidget->count()-1){

        ui->tabWidget->insertTab(ui->tabWidget->count()-1, new OngletCalcul(), QIcon(QString("")),QString::number(index));
        ui->tabWidget->setCurrentIndex(ui->tabWidget->count()-2);
        this->renameTab();

    }
}

void MainWindow::renameTab(){
    for (int i = 0; i <= ui->tabWidget->count()-2; i++){
        ui->tabWidget->setTabText(i, QString::number(i+1) + "  ");
    }
}



