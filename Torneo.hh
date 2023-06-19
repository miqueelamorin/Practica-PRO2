/** @file Torneo.hh
 *    @brief Especificación de la clase Torneo
 */

#ifndef _TORNEO_HH_
#define _TORNEO_HH_
#include "Cjt_Jugadores.hh"
#include "Categorias.hh"
#ifndef NO_DIAGRAM
#include "BinTree.hh"
#include <cmath>
#include <string>
#include <iostream>
#endif
using namespace std;

/** @class Torneo
 *    @brief Representa un torneo.
 * 
 *    Un torneo consta de una categoría, un cuadro de emparejamientos y resultados además de un conjunto de jugadores inscritos.
 */
class Torneo
{
public:
    //Constructoras 
    
    /** @brief Creadora por defecto. 
     *      Se ejecuta automáticamente al declarar un torneo.
     *      \pre <em>cierto</em>.
     *      \post El resultado es un torneo vacío.
     */   
    Torneo();
    
    /** @brief Creadora por parámetro.
     *      \pre "cat" es válido.
     *      \post El resultado es un torneo con categoría "cat".
     */
    Torneo(int cat);
    
    //Lectura y escritura
    
    /** @brief Lee los jugadores inscritos en el torneo.
     *      \pre "conj" es un conjunto de jugadores.
     *      \post Se lee por el canal estándar de entrada un numero de inscritos y sus posiciones en el ranking. El resultado es el parámetro implícito original con sus jugadores inscritos.
     */
    void leer_inscritos(const Cjt_Jugadores& conj);
    
    /** @brief Escribe la categoría del torneo.
     *      \pre "cat" es un conjunto de categorías.
     *      \post Escribe por el canal estándar de salida la categoria del parámetro implícito.
     */
    void escribir(const Categorias& cat) const;
    
    //Modificadoras
    
    /** @brief Confecciona e imprime el cuadro de emparejamientos.
     *      \pre <em>cierto</em>.
     *      \post El resultado es el parámetro implícito con el cuadro de emparejamientos confeccionado y escrito por el canal estándar de salida.
     */
    void cuadro_emparejamientos();
    
    /** @brief Confecciona e imprime el cuadro de resultados, actualiza las estadísticas y los puntos de los jugadores inscritos.
     *      \pre "cat" es un conjunto de categorías, "conj" es un conjunto de jugadores.
     *      \post El resultado es el parámetro implícito con el cuadro de resultados confeccionado y escrito por el canal estándar de salida. Además se actualizan las estadísticas de los jugadores y se suman los puntos ganados en el torneo.
     */
    void cuadro_resultados(const Categorias& cat, Cjt_Jugadores& conj);
    
    /** @brief Actualiza los puntos del conjunto de inscritos en el ranking, los torneos jugados y escribe el ranking local del torneo.
     *      \pre "conj" es un conjunto de jugadores.
     *      \post Al conjunto de jugadores se le suman los puntos de la edición actual del torneo, se actualizan los torneos jugados y se imprime por orden de inscripción el ranking local del torneo.
     */
    void actualizar_puntos_torneos_escribir(Cjt_Jugadores& conj);
    
    /** @brief Resta los puntos obtenidos en una de las dos ediciones al ranking.
     *      \pre "conj" es un conjunto de jugadores, "edicion" indica si se restan los puntos de la edición actual (true) o la anterior (false).
     *      \post El conjunto de jugadores queda actualizado convenientemente.
     */
    void restar_puntos_ranking(Cjt_Jugadores& conj, bool edicion_act);
    
    
private:
    /** @brief Entero que representa la categoría del torneo */
    int categoria;
    
    /** @brief Árbol de emparejamientos y resultados */
    BinTree<pair<int, string>> arbol;
    
    /** @brief Vector de jugadores inscritos en la edición actual */
    vector<pair<string, int>> ed_actual;
    
    /** @brief Vector de jugadores inscritos en la edición anterior */
    vector<pair<string, int>> ed_anterior;
    
    /** @brief Operación de confeccionado de un árbol de emparejamiento de jugadores.
     *      \pre “a” es un árbol binario formado por un par (entero, string), “h” es la altura del nodo actual, “H” es la altura maxima del árbol, “padre” es el valor del nodo padre, “ninscritos” es el numero de inscritos actuales del torneo, potencia_ant = 2^(h-1).
     *      \post “a” pasa a tener los emparejamientos de los jugadores de ese torneo en sus hojas.
     */
    static void emparejar(BinTree<pair<int, string>>& a, int h, int H, int padre, int ninscritos, int potencia_ant);
    
    /** @brief Operación de escritura de un árbol de emparejamientos.
     *      \pre “a” es un árbol de emparejamientos, “ed_actual” es el vector de los jugadores inscritos actuales.
     *      \post Se escribe por el canal estándar de salida los emparejamientos del árbol “a” con los nombres de los jugadores correspondientes.
     */
    static void imprimir_emparejamientos(const BinTree<pair<int, string>>& a, const vector<pair<string, int>>& ed_actual);
    
    /** @brief Operación de confeccionado del cuadro de resultados, actualización de estadística y cálculo de puntos de cada jugador.
     *      \pre “a” es un árbol de emparejamientos, “ed_actual” es el vector de los jugadores inscritos, “nivel” es la altura actual en el árbol, “cat” es un conjunto de categorías, “categoria” es la categoría del torneo, “conj” es un conjunto de jugadores
     *      \post “a” pasa a tener los resultados del partido jugado por sus dos hijos. Se cambia el valor del nodo padre dependiendo de que hijo gana. Se actualizan las estadísticas de cada jugador y se calculan sus puntos.
     */
    static void resultados(BinTree<pair<int, string>>& a, vector<pair<string,int>>& ed_actual, int nivel, const Categorias& cat, int categoria, Cjt_Jugadores& conj);
    
    /** @brief Operación de escritura de un árbol de resultados.
     *      \pre “a” es un árbol de resultados, “ed_actual” es el vector de los jugadores incritos en la edición actual.
     *      \post Se escribe por el canal estándar de salida los resultados del árbol “a” con los nombres de los jugadores correspondientes y los resultados de los partidos jugados.
     */
    static void imprimir_resultados(const BinTree<pair<int, string>>& a, vector<pair<string,int>>& ed_actual);
    
    /** @brief Operación de interpretación de un resultado y actualización de estadísticas.
     *      \pre “result” es el resultado del partido jugado por “jug1” y “jug2”. “conj” es un conjunto de jugadores.
     *      \post Devuelve true si gana el jugador1, falso en otro caso y actualiza las estadísticas de los dos jugadores en función del resultado.
     */
    static bool calcular_actualizar_estadisticas(string result, string jug1, string jug2, Cjt_Jugadores& conj);
};

#endif
