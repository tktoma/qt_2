#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <string.h>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->DernierCodeSaisi2->setText("Pas de code saisi !!");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_BtnSauvearder2_clicked()
{
    if(ui->Code2->text() == "")
    {
        QMessageBox msgBox;
        msgBox.setText("entrer un code!");
        msgBox.setInformativeText("nulos!!");
        msgBox.setStandardButtons(QMessageBox::Ok);
        int ret = msgBox.exec();
    }
    else
    {
        ui->ListeDesCodes2->addItem(ui->Code2->text());
       ui->DernierCodeSaisi2->setText (ui->Code2->text());
    }

}


void MainWindow::on_ListeDesCodes2_currentRowChanged(int currentRow)
{
     currentpos = currentRow ;
}



void MainWindow::on_btn_delete2_clicked()
{
    if (currentpos != -1)
    {
        QListWidgetItem *it = ui->ListeDesCodes2->takeItem(currentpos);
        QString o = it->text();
         ui->Code2->setText(o) ;
        delete it;
        ui->ListeDesCodes2->setCurrentRow(-1);
    }

}



