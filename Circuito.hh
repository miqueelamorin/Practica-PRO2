/** @file Circuito.hh
 *    @brief Especificación de la clase Circuito
 */

#ifndef _CIRCUITO_HH_
#define _CIRCUITO_HH_

#include "Torneo.hh"
#include "Cjt_Jugadores.hh"
#include "Categorias.hh"

#ifndef NO_DIAGRAM
#include <map>
#include <iostream>
#endif
using namespace std;

/** @class Circuito
 *    @brief Representa un circuito de torneos
 * 
 *    Almacena todos los torneos añadidos al circuito. Ofrece operaciones para dar de baja un torneo, iniciarlo o finalizarlo.
 */
class Circuito
{
    
public:
    //Constructoras 
    
    /** @brief Creadora por defecto. 
            Se ejecuta automáticamente al declarar un circuito.
     *      \pre <em>cierto</em>.
     *      \post El resultado es un circuito vacío.
     */  
    Circuito();
    
    //Modificadoras
    
    /** @brief Elimina un torneo del circuito.
     *      \pre El parámetro implícito está inicializado y el torneo llamado "nombre" existe en el p.i. "conj" es un conjunto de jugadores.
     *      \post El parámetro implícito contiene su carga original menos el torneo con nombre "nombre" y al conjunto de jugadores se le restan los puntos de la última edición de éste.
     */
    void eliminar_torneo(string nombre, Cjt_Jugadores& conj);
    
    /** @brief Añade un torneo al circuito.
     *      \pre "nombre" es el nombre del torneo y "cat" es su categoría, ambos válidos.
     *      \post El parámetro implícito contiene su carga original más un torneo.
     */
    void anadir_torneo(string nombre, int cat);
    
    /** @brief Inicia un torneo del circuito.
     *      \pre "nombre" es el nombre del torneo y éste existe en el parámetro implicito. "conj" es un conjunto de jugadores.
     *      \post Se inicia el torneo, se leen los inscritos y se confecciona e imprime el cuadro de emparejamientos.
     */
    void iniciar_torneo(string nombre, const Cjt_Jugadores& conj);
    
    /** @brief Finaliza un torneo del circuito.
     *        \pre nombre es el nombre del torneo y éste existe en el parámetro implicito. "conj" es un conjunto de jugadores y "cat" es un conjunto de categorías.
     *        \post Se finaliza el torneo, se confecciona e imprime el cuadro de resultados, se restan los puntos de la edición anterior, se suman los puntos al ránking de jugadores y se actualizan las estadisticas de sus inscritos.
     */
    void finalizar_torneo(string nombre, Cjt_Jugadores& conj, const Categorias& cat);
    
    //Lectura y escritura
    
    /** @brief Operación de lectura.
             \pre <em>cierto</em>.
     *        \post Se leen por el canal estándar de entrada un numero de torneos con sus nombres y categorías. El parámetro implícito pasa a tener los atributos leídos en el canal estándar de entrada.
     */
    void leer();
    
    /** @brief Operación de escritura.
     *        \pre "cat" es un conjunto de categorías.
     *      \post Escribe por el canal estándar de salida el nombre y categoria de los torneos del parámetro implícito.
     */
    void listar_torneos(const Categorias& cat) const;
    
    //Consultoras
    
    /** @brief Indica si el torneo con nombre "nombre" existe en el circuito.
     *      \pre "nombre" es el nombre del torneo.
     *      \post Indica la existencia del torneo con nombre "nombre" en el circuito.
     */
    bool existe(string nombre) const;
    
    /** @brief Indica el número de torneos del circuito.
     *      \pre <em>cierto</em>.
     *      \post Retorna el número de torneos del circuito.
     */
    int numero_torneos() const;
    
private:
    /** @brief Diccionario que almacena torneos con índice asociado por nombre */
    map<string,Torneo> circuito;
};
#endif
