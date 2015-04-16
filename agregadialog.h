#ifndef AGREGADIALOG_H
#define AGREGADIALOG_H

#include <QDialog>
#include "entidadlibro.h"

namespace Ui {
class AgregaDialog;
}

/**
 * @brief The AgregaDialog class
 */
class AgregaDialog : public QDialog {
    Q_OBJECT
public:
    /**
     * @brief AgregaDialog
     * @param parent
     */
    explicit AgregaDialog(QWidget *parent = 0);

    /**
      * @brief Destructor
      */
    ~AgregaDialog();

    /**
     * @brief getLibro
     * @return libro
     */
    EntidadLibro getLibro() const {
        return libro;
    }
private slots:
    void on_aceptar_clicked();
    void on_cancelar_clicked();
private:
    Ui::AgregaDialog *ui;
    EntidadLibro libro;
};

#endif // AGREGADIALOG_H
