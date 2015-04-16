#ifndef BASEDATOS_H
#define BASEDATOS_H

#include <QSqlDatabase>
#include "entidadlibro.h"

/**
 * @brief The BaseDatos class
 */
class BaseDatos {
public:
    /**
     * @brief BaseDatos
     * @param nombre
     */
    BaseDatos(const QString &nombre);

    /**
     * @brief abre
     * @return true/false
     */
    bool abre();

    /**
     * @brief configura
     */
    void configura();

    /**
     * @brief addBook
     * @param L
     */
    void addBook(const EntidadLibro &L);

    /**
     * @brief deleteBook
     * @param L
     */
    void deleteBook(const EntidadLibro &L);
private:
    QSqlDatabase db;
    QString name;
};

#endif // BASEDATOS_H
