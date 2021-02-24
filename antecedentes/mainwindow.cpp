#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <fstream>
#include <iostream>
#include <string>
#include <QString>
#include <QMessageBox>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
using namespace std;

struct antecedentes{
    int cant;
    long dni;
    QString nombre;
    QString dom;
    QString ant;
};

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_buscar_clicked()
{
    ifstream archi;
    antecedentes per[1000];
    int c = 0;
    QMessageBox mensaje;

    /*archi.open("./ident.txt");
    if (archi.fail()){
        mensaje.setText("Error en la apertura del archivo");
        mensaje.exec();
    } else {
        archi >> per[cuantos].dni;
        while ( !archi.eof() ) {
            getline(archi,per[cuantos].nombre);
            getline(archi,per[cuantos].dom);
            getline(archi,per[cuantos].ant);
            cuantos++;
            archi >> per[cuantos].dni;
        }
    }

    for (int i = 0; i < cuantos; i++) {
        mensaje.setText(per[i].nombre);
        mensaje.exec();
        /*cout << "DNI: " << per[i].dni << "NOMBRE: " << per[i].nombre << "DOMICILIO: " << per[i].dom << "ANTECEDENTE: " << per[i].ant << endl;*/
    /*}
    archi.close();*/


    if (!QSqlDatabase::isDriverAvailable("QSQLITE")){
        mensaje.setText("Error: QSQLITE no esta disponible");
        mensaje.exec();
        //qDebug() << "Error: QSQLITE no esta disponible";
        //return -1;
    }
    QSqlDatabase bd = QSqlDatabase::addDatabase("QSQLITE");
    bd.setDatabaseName("/home/exequiel/Escritorio/ident.db");
    if (!bd.open()) {
        mensaje.setText("Error en la apertura del archivo");
        mensaje.exec();
        //qDebug() << bd.lastError().text();
        //return -2;
    }
    QSqlQuery q; //variable de consulta siempre va despues de abrir la base de dat
    if (!q.exec("CREATE TABLE IF NOT EXISTS persona (id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,"
           " nombre VARCHAR(255) NOT NULL, "
           " dni INTEGER NOT NULL, "
           " domicilio VARCHAR(255) NOT NULL, "
           " antecedente VARCHAR(255) )")){
        mensaje.setText("Error");
        mensaje.exec();
        //qDebug() << q.lastError().text();
        //return -3;
     }

    q.exec("SELECT * FROM persona");

    while (q.next()){
        per[c].cant = q.value("id").toInt();
        per[c].nombre = q.value("nombre").toString();
        per[c].dni = q.value("dni").toInt();
        per[c].dom = q.value("domicilio").toString();
        per[c].ant = q.value("antecedente").toString();
        c++;
    }
    bd.close();


    QString dni = ui->dni->text();

    long _dni = dni.toLong();
    QString _ant, _nom;

    for (int i = 0; i < c; i++) {
        if (_dni == per[i].dni){
            _ant = per[i].ant;
            _nom = per[i].nombre;
            ui->nombre->setText(_nom);
             ui->contenido->setPlainText(_ant);
             break;
        } else {
            ui->nombre->setText("NO HAY REGISTRO");
            ui->contenido->setPlainText("NO HAY REGISTRO");
        }
    }
    //ui->contenido->setPlainText(_ant);*/

}



void MainWindow::on_limpiar_clicked()
{
    ui->dni->setText("");
    ui->nombre->setText("");
    ui->contenido->setPlainText("");
}
