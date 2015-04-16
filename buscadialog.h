#ifndef BUSCADIALOG_H
#define BUSCADIALOG_H

#include <QDialog>

namespace Ui {
class BuscaDialog;
}

class QSqlQueryModel;

/**
 * @brief The BuscaDialog class
 */
class BuscaDialog : public QDialog {
    Q_OBJECT
public:
    /**
     * @brief BuscaDialog
     * @param parent
     */
    explicit BuscaDialog(QWidget *parent = 0);

    /**
      * @brief Destructor
      */
    ~BuscaDialog();
private slots:
    void on_ok_clicked();
    void on_buscador_textEdited(const QString &arg1);
private:
    Ui::BuscaDialog *ui;
    QSqlQueryModel *model;
};

#endif // BUSCADIALOG_H
