#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btn_delete2_clicked();

    void on_ListeDesCodes2_currentRowChanged(int currentRow);

    void on_BtnSauvearder2_clicked();

private:
    Ui::MainWindow *ui;
    int currentpos = -1;
};
#endif // MAINWINDOW_H
