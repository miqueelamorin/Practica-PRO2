/** @file Circuito.cc
    @brief Implementación de la clase Circuito
*/  

#include "Circuito.hh"

Circuito::Circuito(){}
 
void Circuito::eliminar_torneo(string nombre, Cjt_Jugadores& conj)
{
    circuito[nombre].restar_puntos_ranking(conj, true);
    circuito.erase(nombre);
    conj.ordenar_ranking();
}
  
void Circuito::anadir_torneo(string nombre, int cat)
{
    Torneo T(cat);
    circuito[nombre] = T;
}
    
void Circuito::iniciar_torneo(string nombre, const Cjt_Jugadores& conj)
{
    circuito[nombre].leer_inscritos(conj);
    circuito[nombre].cuadro_emparejamientos();
}
    
void Circuito::finalizar_torneo(string nombre, Cjt_Jugadores& conj, const Categorias& cat)
{
    circuito[nombre].cuadro_resultados(cat, conj);
    circuito[nombre].restar_puntos_ranking(conj, false);
    circuito[nombre].actualizar_puntos_torneos_escribir(conj);
    conj.ordenar_ranking();
}
  
void Circuito::listar_torneos(const Categorias& cat) const
{
    cout << numero_torneos() << endl;
    for (map<string, Torneo>::const_iterator it = circuito.begin(); it != circuito.end(); ++it) {
        cout << it->first << ' ';
        (it->second).escribir(cat);
    }
}

bool Circuito::existe(string nombre) const
{
    map<string, Torneo>::const_iterator it = circuito.find(nombre);
    return (it != circuito.end());
}

int Circuito::numero_torneos() const
{
    return circuito.size();
}

void Circuito::leer()
{
    int ntorn;
    cin >> ntorn;
    for (int i = 0; i < ntorn; ++i){
      string nombre;
      cin >> nombre;
      int cat;
      cin >> cat;
      Torneo T(cat);
      circuito[nombre] = T;
    }
}
