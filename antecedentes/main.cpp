#include "login.h"
#include <QApplication>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    login l;
    l.show();

    return a.exec();
}
