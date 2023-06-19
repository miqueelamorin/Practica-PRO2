/** @file Cjt_Jugadores.hh
    @brief Especificación de la clase Cjt_Jugadores
*/

#ifndef _CJT_JUGADORES_HH_
#define _CJT_JUGADORES_HH_

#include "Jugador.hh"
#ifndef NO_DIAGRAM
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
#endif
using namespace std;

/** @class Cjt_Jugadores
      @brief Representa un conjunto de jugadores
   
 *     Consta de un ranking donde se almacenan los jugadores ordenados por sus puntos acumulados. Ofrece operaciones como añadir o eliminar un jugador, además de poder listarlos de diferentes maneras.
 */
class Cjt_Jugadores
{
    
public:
    //Constructoras 
    
    /** @brief Creadora por defecto. 
     *      Se ejecuta automáticamente al declarar un conjunto de jugadores.
     *      \pre <em>cierto</em>.
     *      \post El resultado es un conjunto de jugadores sin inicializar.
     */  
    Cjt_Jugadores();
    
    //Modificadoras
    
    /** @brief Actualiza las estadísticas de un partido para un jugador.
     *      \pre Todos los parámetros de entrada son válidos.
     *      \post Se modifican las estadisticas del jugador con nombre "jug".
     */
    void actualizar_estadisticas(string jug, int t, int sg, int sp, int jg, int jp, int pg, int pp);
    
    /** @brief Añade un jugador al conjunto.
     *      \pre "nombre" es un nombre válido para un jugador.
     *      \post El parámetro implícito pasa a tener un jugador más con nombre "nombre" y última posición en el ranking.
     */
    void anadir_jugador(string nombre);
    
    /** @brief Da de baja un jugador del conjunto.
     *      \pre El parámetro implícito esta inicializado y el jugador con nombre "nombre" existe en éste.
     *      \post El parámetro implícito contiene su carga original menos el jugador con nombre "nombre" y el ranking se reordena.
     */
    void eliminar_jugador(string nombre);
    
    /** @brief Suma los puntos indicados al jugador con nombre "nombre".
     *      \pre El parámetro implícito esta inicializado, el jugador con nombre "nombre" existe en el p.i.
     *      \post El jugador con nombre "nombre" tiene sus puntos originales más los nuevos.
     */
    void sumar_puntos(string nombre, int pts);
    
    /** @brief Ordena el ranking de jugadores.
     *      \pre <em>cierto</em>.
     *      \post El raking pasa a estar ordenado según los puntos de cada jugador.
     */
    void ordenar_ranking();
    
    // Lectura y escritura
    
    /** @brief Operación de lectura.
     *      \pre <em>cierto</em>.
     *      \post Se leen por el canal estándar de entrada el numero de jugadores seguido de un conjunto de sus nombres. El parámetro implícito pasa a tener los valores leídos en el canal de entrada.
     */
    void leer();
    
    /** @brief Operación de escritura del ranking.
     *      \pre El parámetro implícito está inicializado.
     *      \post Escribe la posición, nombre y puntos de todos los jugadores del ránking por el canal estándar de salida ordenados por puntos.
     */
    void listar_ranking() const;
    
    /** @brief Operación de escritura de todos los jugadores y sus estadísticas.
     *      \pre El parámetro implícito está inicializado.
     *      \post Escribe la posición, nombre, puntos y estadísticas de todos los jugadores del ránking por el canal estándar de salida ordenados por nombre.
     */
    void listar_jugadores() const;
    
    /** @brief Operación de escritura de un jugador y sus estadísticas.
     *      \pre El parámetro implícito está inicializado y el jugador con nombre "nombre" pertenece al p.i.
     *      \post Escribe la posición, nombre, puntos y estadísticas del jugador con nombre "nombre".
     */
    void listar_jugador(string nombre) const;
    
    //Consultoras
    
    /** @brief Indica si existe el jugador con nombre "nombre".
     *      \pre "nombre" es un nombre de un jugador y el p.i. esta inicializado.
     *      \post Indica la existencia del jugador con nombre "nombre" en el parámetro implícito.
     */
    bool existe(string nombre) const;
    
    /** @brief Indica el número de jugadores.
     *      \pre <em>cierto</em>.
     *      \post Retorna el número de jugadores del conjunto.
     */
    int numero_jugadores() const;
    
    /** @brief Localiza el nombre del jugador con posición "n" en el ranking.
     *      \pre 0 <= n <= numero_jugadores.
     *      \post Retorna el nombre del jugador con posición "n" en el ranking.
     */
    string buscar_jugador(int n) const;
    
    /** @brief Operación para consultar los puntos de un jugador.
     *      \pre El jugador con nombre "nombre" existe en el conjunto de jugadores.
     *      \post Retorna el nombre del jugador con posición 'n' en el ranking.
     */
    int consultar_puntos(string nombre) const;
    
    
private:
    /** @struct jrank
        @brief Representa un jugador en el ranking

        Definido por su nombre, puntos y posición anterior.
    */
    struct jrank{
        /** @brief String que representa el nombre del jugador */
        string nombre;

        /** @brief Entero que representa los puntos del jugador */
        int puntos;

        /** @brief Entero que representa la posición anterior en el ranking */
        int pos_ant;
    };
    
    /** @brief Diccionario que almacena jugadores con índice asociado por nombre */
    map<string, Jugador> cjt;
    
    /** @brief Vector que representa el ranking de jugadores (jrank) */
    vector<jrank> ranking;
    
    /** @brief Operación de comparación de dos elementos del struct jrank según sus puntos y posición anterior en el ranking.
     *      \pre j1 y j2 son dos elementos del struct jrank
     *      \post Retorna true si el elemento j1 tiene más puntos que j2. En caso de empate, retorna true si el valor de la posición anterior de j1 es inferior al de j2. Retorna false en otro caso.
     */
    static bool comp(const jrank& j1, const jrank& j2);
};
#endif
