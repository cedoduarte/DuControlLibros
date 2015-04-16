#ifndef EDITADIALOG_H
#define EDITADIALOG_H

#include <QDialog>

namespace Ui {
class EditaDialog;
}

/**
 * @brief The EditaDialog class
 */
class EditaDialog : public QDialog {
    Q_OBJECT
public:
    /**
     * @brief EditaDialog
     * @param parent
     */
    explicit EditaDialog(QWidget *parent = 0);

    /**
      * @brief Destructor
      */
    ~EditaDialog();
private slots:
    void on_ok_clicked();
private:
    Ui::EditaDialog *ui;
};

#endif // EDITADIALOG_H
