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


    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Driver={MySQL ODBC 8.0 Unicode Driver};DATABASE=edt1;");
      db.setHostName("localhost");
    //  db.setDatabaseName("edt1");
      db.setUserName("utilisateur1");
      db.setPassword("utilisateur1");
      bool ok = db.open();


      QSqlQuery q("SELECT * FROM cours");
         while (q.next()) {
             QString text = q.value(1).toString();

         }
int i = 0 ;

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



