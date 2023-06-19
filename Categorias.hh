/** @file Categorias.hh
    @brief Especificación de la clase Categorias
*/

#ifndef _CATEGORIAS_HH_
#define _CATEGORIAS_HH_

#ifndef NO_DIAGRAM
#include <vector>
#include <iostream>
#endif
using namespace std;

/** @class Categorias
    @brief Representa un conjunto de categorías.

    Las categorías están definidas por un identificador entero y un nombre. Además, en cada una de ellas se especifican los puntos asociados a cada nivel.
*/
class Categorias
{
public:
    //Constructoras

    /** @brief Creadora por defecto. 

        Se ejecuta automáticamente al declarar un conjunto de categorías.
        \pre <em>cierto</em>.
        \post El resultado es un conjunto de categorías vacío.
    */  
    Categorias();

    //Consultoras

    /** @brief Indica el número máximo de categorías de la clase.

        \pre <em>cierto</em>.
        \post El resultado es el número de categorías máximo.
    */
    int categoria_max() const;

    /** @brief Indica el número de puntos que tiene asociada una categoría y un nivel.

        \pre "categ" y "nivel" son válidos.
        \post El resultado son los puntos de la categoría y nivel indicados.
    */
    int consultar_puntos(int categ, int nivel) const;
  
    /** @brief Indica el nombre de la categoría segun su identificador.

        \pre "categ" es un entero válido.
        \post El resultado es el nombre de la categoría con identificador "categ".
    */
    string nombre_categoria(int categ) const;

    //Lectura y escritura

    /** @brief Lee un conjunto de categorías.
        \pre <em>cierto</em>.
        \post Se leen por el canal estándar de entrada un conjunto de nombres de categorias seguido de sus puntos por nivel. El resultado es un conjunto de categorías y sus puntos por nivel.
    */
    void leer();

    /** @brief Escribe el conjunto de categorías.
        \pre <em>cierto</em>.
        \post Escribe por el canal estándar de salida el conjunto de categorías por orden creciente de identificador y sus puntos por nivel.
    */
    void listar_categorias() const;

private:
    /** @brief Entero que representa la categoría máxima */
    int C;
    
    /** @brief Vector de categorías de tamaño C */
    vector<string> categorias;
    
    /** @brief Matriz de C*K puntos por nivel de jugador y categoría */
    vector < vector <int> > tabla_puntos;
};
#endif
