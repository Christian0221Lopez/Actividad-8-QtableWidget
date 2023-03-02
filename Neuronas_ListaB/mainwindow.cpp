#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "clista.h"
#include<QFileDialog>
#include<QMessageBox>
#include <QStringList>
#include <QtCore/QString>
#include <QtGlobal>
#include<iostream>
#include<fstream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QStringList Titulos;
    setWindowTitle("Seminario de Algoritmia");
    ui->tableWidget->setColumnCount(7);
    Titulos << "ID" << "Voltaje" << "X" << "Y" << "R" << "G" << "B";
    ui->tableWidget->setHorizontalHeaderLabels(Titulos);
}

MainWindow::~MainWindow()
{
    delete ui;
}

Clista* neurona = new Clista;

void MainWindow::on_pushButton_clicked()
{
    int ID = 0;
    float Volt = 0;
    int x = 0;
    int y = 0;
    int r = 0;
    int v = 0;
    int a = 0;

    QString id = ui->datoN->text();
     ID = id.toInt();
     QString voltaje = ui->datoN_2->text();
     Volt = voltaje.toFloat();
     QString pos_X = ui->datoN_3->text();
     x = pos_X.toInt();
     QString pos_Y = ui->datoN_4->text();
     y = pos_Y.toInt();
     QString rojo = ui->datoN_5->text();
     r = rojo.toInt();
     QString verde = ui->datoN_6->text();
     v = verde.toInt();
     QString azul = ui->datoN_7->text();
     a = azul.toInt();

     neurona->InsertarInicio(ID,Volt,x,y,r,v,a);


}


void MainWindow::on_pushButton_7_clicked()
{

    ui->TextEdit->insertPlainText(neurona->Set());

}


void MainWindow::on_pushButton_2_clicked()
{
    int ID = 0;
    float Volt = 0;
    int x = 0;
    int y = 0;
    int r = 0;
    int v = 0;
    int a = 0;

    QString id = ui->datoN->text();
     ID = id.toInt();
     QString voltaje = ui->datoN_2->text();
     Volt = voltaje.toFloat();
     QString pos_X = ui->datoN_3->text();
     x = pos_X.toInt();
     QString pos_Y = ui->datoN_4->text();
     y = pos_Y.toInt();
     QString rojo = ui->datoN_5->text();
     r = rojo.toInt();
     QString verde = ui->datoN_6->text();
     v = verde.toInt();
     QString azul = ui->datoN_7->text();
     a = azul.toInt();


     neurona->InsertarFinal(ID,Volt,x,y,r,v,a);


}


void MainWindow::on_Open_File_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,tr("Open File"),"C:/Users/USER/Documents/UdeG/Seminario de Algoritmia/ACT_4/Neuronas_Lista","All files (*.*);;Text File (*.txt)");

    ui->TextoD->insertPlainText(filename);

   neurona->Save(filename);

}

void MainWindow::on_Open_File_2_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,tr("Open File"),"C://","All files (*.*);;Text File (*.txt)");

    ui->TextoD->insertPlainText(filename);

    neurona->Recover(filename);
}


void MainWindow::on_EliminarInicioB_clicked()
{
    neurona->EliminarInicio();
}


void MainWindow::on_EliminarFinalB_clicked()
{
    neurona->EliminarFinal();
}



void MainWindow::on_pushButton_8_clicked()
{
    int fila;
    QString label;
    int ID = 0;
    float Volt = 0;
    int x = 0;
    int y = 0;
    int r = 0;
    int g = 0;
    int b = 0;

    fila = ui->tableWidget->rowCount() -1;

    ui->tableWidget->insertRow(ui->tableWidget->rowCount());

    label = ui->datoN_8->text();

    neurona->BusquedaL(label,ID,Volt,x,y,r,g,b);


    ui->tableWidget->setItem(fila, 0, new QTableWidgetItem(QString::number(ID)));
    ui->tableWidget->setItem(fila, 1, new QTableWidgetItem(QString::number(Volt)));
    ui->tableWidget->setItem(fila, 2, new QTableWidgetItem(QString::number(x)));
    ui->tableWidget->setItem(fila, 3, new QTableWidgetItem(QString::number(y)));
    ui->tableWidget->setItem(fila, 4, new QTableWidgetItem(QString::number(r)));
    ui->tableWidget->setItem(fila, 5, new QTableWidgetItem(QString::number(g)));
    ui->tableWidget->setItem(fila, 6, new QTableWidgetItem(QString::number(b)));


}


