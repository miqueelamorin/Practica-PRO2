/** @file Jugador.hh
 *    @brief Especificación de la clase Jugador
 */

#ifndef _JUGADOR_HH_
#define _JUGADOR_HH_
#ifndef NO_DIAGRAM
#include <iostream>
#endif
using namespace std;

/** @class Jugador
 *    @brief Representa un jugador con atributos puntos y estadísticas diversas
 * 
 *    Un Jugador dispone de unos puntos ganados además de unas estadísticas que incluyen los torneos jugados; partidos, sets y juegos tanto ganados como perdidos.
 */
class Jugador
{
public:
    //Constructoras 
    
    /** @brief Creadora por defecto. 
     *      Se ejecuta automáticamente al declarar un jugador.
     *      \pre <em>cierto</em>.
     *      \post El resultado es jugador con puntos y estadísticas a cero.
     */   
    Jugador();
    
    //Escritura
    
    /** @brief Escribe las estadisticas del jugador.
     *      \pre <em>cierto</em>.
     *      \post Escribe por el canal estándar de salida el contenido del parámetro implícito.
     */
    void escribir() const;
    
    //Modificadoras
    
    /** @brief Actualiza las estadisticas de un jugador.
     *      \pre Todos los parámetros enteros son válidos.
     *      \post El resultado es el parámetro implícito con las estadísticas modificadas.
     */
    void actualizar_estadisticas(int tj, int pg, int pp, int sg, int sp, int jg, int jp);
    
    /** @brief Actualiza la posición del ranking del jugador.
     *      \pre "p" es un parámetro entero válido.
     *      \post El resultado es el parámetro implícito con la nueva posición.
     */
    void actualizar_posicion(int p);
    
    //Consultoras
    
    /** @brief Retorna la posición en el ranking del jugador.
     *      \pre <em>cierto</em>
     *      \post El resultado es la posición del parámetro implícito en el ranking.
     */
    int consultar_posicion() const;
    
    
private:
    /** @brief Entero que representa la posición en el raking del jugador */
    int pos;
    
    /** @brief Entero que representa los torneos jugados */
    int tj;
    
    /** @brief Entero que representa los partidos ganados */
    int pg;
    
    /** @brief Entero que representa los partidos perdidos */
    int pp;

    /** @brief Entero que representa los sets ganados */
    int sg;

    /** @brief Entero que representa los sets perdidos */
    int sp;
    
    /** @brief Entero que representa los juegos ganados */
    int jg;

    /** @brief Entero que representa los juegos perdidos */
    int jp;
};

#endif
