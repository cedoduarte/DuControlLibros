#include "basedatos.h"
#include <QSqlQuery>

// Statements:
#define CREATE_BOOK_TABLE "CREATE TABLE IF NOT EXISTS libro" \
    " (id INTEGER PRIMARY KEY AUTOINCREMENT, titulo VARCHAR(255)," \
    " autor VARCHAR(255), editorial VARCHAR(255))"

#define ADD_BOOK(L) QString("INSERT INTO libro (titulo, autor, " \
    "editorial) VALUES ('%1', '%2', '%3')").arg(L.titulo). \
    arg(L.autor).arg(L.editorial)

#define DELETE_BOOK(L) QString("DELETE FROM libro WHERE titulo LIKE '%1' " \
    "AND autor LIKE '%2' AND editorial LIKE '%3'").arg(L.titulo). \
    arg(L.autor).arg(L.editorial)
// End

BaseDatos::BaseDatos(const QString &nombre) {
    db = QSqlDatabase::addDatabase("QSQLITE");
    name = nombre;
}

bool BaseDatos::abre() {
    db.setDatabaseName(name);
    return db.open();
}

void BaseDatos::configura() {
    QSqlQuery qry;
    qry.exec(CREATE_BOOK_TABLE);
}

void BaseDatos::addBook(const EntidadLibro &L) {
    QSqlQuery qry;
    qry.exec(ADD_BOOK(L));
}

void BaseDatos::deleteBook(const EntidadLibro &L) {
    QSqlQuery qry;
    qry.exec(DELETE_BOOK(L));
}
