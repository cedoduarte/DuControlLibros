#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "entidadlibro.h"
#include "basedatos.h"

// Database name
/**
  * @brief Database name
  */
#define DBNAME "data.db"

// Options of the menu
#define AGREGA  0
#define BUSCA   1
#define ELIMINA 2
#define EDITA   3

namespace Ui {
class MainWindow;
}

/**
 * @brief The MainWindow class
 */
class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    /**
     * @brief MainWindow
     * @param parent
     */
    explicit MainWindow(QWidget *parent = 0);

    /**
      * @brief Destructor
      */
    ~MainWindow();
private slots:
    void on_listWidget_clicked(const QModelIndex &index);
    void on_actionQuitar_triggered();
private:
// Options of the menu:
    void Agrega();  // 0
    void Busca();   // 1
    void Elimina(); // 2
    void Edita();   // 3

    Ui::MainWindow *ui;
    BaseDatos db;
};

#endif // MAINWINDOW_H
