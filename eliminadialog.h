#ifndef ELIMINADIALOG_H
#define ELIMINADIALOG_H

#include <QDialog>
#include "entidadlibro.h"

namespace Ui {
class EliminaDialog;
}

class QCheckBox;

/**
 * @brief The EliminaDialog class
 */
class EliminaDialog : public QDialog {
    Q_OBJECT
public:
    /**
     * @brief EliminaDialog
     * @param parent
     */
    explicit EliminaDialog(QWidget *parent = 0);

    /**
      * @brief Destructor
      */
    ~EliminaDialog();

    /**
     * @brief getLibros
     * @return lista de libros
     */
    QList<EntidadLibro> getLibros() const {
        return libros;
    }
private slots:
    void on_selecciona_clicked();
    void on_ok_clicked();
    void on_cancelar_clicked();
    void on_deselecciona_clicked();
private:
    Ui::EliminaDialog *ui;
    QList<QCheckBox *> checks;
    QList<EntidadLibro> libros;
};

#endif // ELIMINADIALOG_H
