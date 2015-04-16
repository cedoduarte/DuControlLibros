#include "editadialog.h"
#include "ui_editadialog.h"
#include <QSqlTableModel>

EditaDialog::EditaDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditaDialog)
{
    ui->setupUi(this);
    QSqlTableModel *model = new QSqlTableModel(this);
    model->setTable("libro");
    model->select(); // Loads the books
    ui->libros->setModel(model);
}

EditaDialog::~EditaDialog() {
    delete ui;
}

void EditaDialog::on_ok_clicked() {
    accept();
}
