#include "agregadialog.h"
#include "ui_agregadialog.h"

AgregaDialog::AgregaDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AgregaDialog)
{
    ui->setupUi(this);
}

AgregaDialog::~AgregaDialog() {
    delete ui;
}

void AgregaDialog::on_aceptar_clicked() {
    // Book's data
    libro.titulo = ui->titulo->text();
    libro.autor = ui->autor->text();
    libro.editorial = ui->editorial->text();
    accept();
}

void AgregaDialog::on_cancelar_clicked() {
    reject();
}
