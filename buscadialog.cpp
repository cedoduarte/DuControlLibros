#include "buscadialog.h"
#include "ui_buscadialog.h"
#include <QSqlQueryModel>

// Searching options
#define OPC_TITULO    0
#define OPC_AUTOR     1
#define OPC_EDITORIAL 2

BuscaDialog::BuscaDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BuscaDialog)
{
    ui->setupUi(this);
    model = new QSqlQueryModel(this);
    model->setQuery("SELECT * FROM libro");
    ui->resultado->setModel(model);
}

BuscaDialog::~BuscaDialog() {
    delete ui;
}

void BuscaDialog::on_ok_clicked() {
    accept();
}

void BuscaDialog::on_buscador_textEdited(const QString &txt) {
    if (txt.isEmpty()) {
        model->setQuery("SELECT * FROM libro");
        return;
    }
    // Filter
    const int opc = ui->comboBox->currentIndex();
    QString busqueda = "SELECT * FROM libro WHERE ";
    switch (opc) {
    case OPC_TITULO:
        busqueda += QString("titulo LIKE '%") + txt + "%'";
        break;
    case OPC_AUTOR:
        busqueda += QString("autor LIKE '%") + txt + "%'";
        break;
    case OPC_EDITORIAL:
        busqueda += QString("editorial LIKE '%") + txt + "%'";
        break;
    }
    model->setQuery(busqueda);
}
