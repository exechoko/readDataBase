#include "login.h"
#include "ui_login.h"


login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);

    QMovie *movie = new QMovie(":/new/prefix1/loading.gif");
    ui->label_gif->setMovie(movie);
    movie->start();
}

login::~login()
{
    delete ui;
}

void login::on_pushButton_clicked()
{

    QString username = ui->username->text();
    QString password = ui->password->text();

    if (username == "usuario" && password == "usuario") {
        //QMessageBox::information(this, "Inicio de sesión", "Usuario y contraseña correctos");

        hide(); //para ocultar el login cuando inicia sesion
        mw = new MainWindow (this);
        mw->show();
    } else {
        QMessageBox::warning(this, "Inicio de sesión", "Usuario o contraseña incorrectos");
    }
}
