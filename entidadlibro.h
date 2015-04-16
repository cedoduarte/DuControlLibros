#ifndef ENTIDADLIBRO_H
#define ENTIDADLIBRO_H

#include <QString>

/**
 * @brief The EntidadLibro struct
 */
struct EntidadLibro {
    /**
     * @brief titulo
     */
    QString titulo;

    /**
     * @brief autor
     */
    QString autor;

    /**
     * @brief editorial
     */
    QString editorial;

    /**
     * @brief validate: Validates the book's data
     * @return true/false
     */
    bool validate() const {
        return !titulo.isEmpty() &&
               !autor.isEmpty()  &&
               !editorial.isEmpty();
    }
};

#endif // ENTIDADLIBRO_H
