#include "eliminadialog.h"
#include "ui_eliminadialog.h"
#include <QCheckBox>
#include <QSqlQuery>

// Columns:
#define COL_ELIMINA   0
#define COL_TITULO    1
#define COL_AUTOR     2
#define COL_EDITORIAL 3

EliminaDialog::EliminaDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EliminaDialog)
{
    ui->setupUi(this);
    // Loads books
    QSqlQuery qry;
    qry.exec("SELECT titulo, autor, editorial FROM libro");
    int i = 0;
    while (qry.next()) {
        EntidadLibro L = {
            qry.value(0).toString(),
            qry.value(1).toString(),
            qry.value(2).toString()
        };
        const int ultima_fila = ui->libros->rowCount();
        ui->libros->insertRow(ultima_fila);
        QCheckBox *check = new QCheckBox(this);
        checks.append(check);
        ui->libros->setCellWidget(i, COL_ELIMINA, check);
        ui->libros->setItem(i, COL_TITULO, new QTableWidgetItem(L.titulo));
        ui->libros->setItem(i, COL_AUTOR, new QTableWidgetItem(L.autor));
        ui->libros->setItem(i, COL_EDITORIAL,new QTableWidgetItem(L.editorial));
        ++i;
    }
}

EliminaDialog::~EliminaDialog() {
    delete ui;
}

void EliminaDialog::on_selecciona_clicked() {
    // Selects all
    for (int i = 0; i < checks.size(); ++i) {
        checks.at(i)->setChecked(true);
    }
}

void EliminaDialog::on_deselecciona_clicked() {
    // Deselects all
    for (int i = 0; i < checks.size(); ++i) {
        checks.at(i)->setChecked(false);
    }
}

void EliminaDialog::on_ok_clicked() {
    for (int i = 0; i < checks.size(); ++i) {
        if (checks.at(i)->isChecked()) {
            EntidadLibro L = {
                ui->libros->item(i, COL_TITULO)->text(),
                ui->libros->item(i, COL_AUTOR)->text(),
                ui->libros->item(i, COL_EDITORIAL)->text()
            };
            libros.append(L);
        }
    }
    accept();
}

void EliminaDialog::on_cancelar_clicked() {
    reject();
}


