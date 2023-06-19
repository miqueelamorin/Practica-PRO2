/** @file Cjt_Jugadores.cc
    @brief Implementación de la clase Cjt_Jugadores
*/

#include "Cjt_Jugadores.hh"

Cjt_Jugadores::Cjt_Jugadores(){}

void Cjt_Jugadores::anadir_jugador(string nombre)
{
    Jugador J;
    J.actualizar_posicion(ranking.size());
    cjt[nombre] = J;
    
    jrank jug;
    jug.nombre = nombre;
    jug.puntos = 0;
    jug.pos_ant = ranking.size();
    ranking.push_back(jug);
}

void Cjt_Jugadores::eliminar_jugador(string nombre)
{
    int pos = (*cjt.find(nombre)).second.consultar_posicion();
    cjt.erase(nombre);

    for (int i = pos; i < numero_jugadores(); ++i){
        ranking[i] = ranking[i+1];
        cjt[ranking[i].nombre].actualizar_posicion(i);
        --ranking[i].pos_ant;
    }
    ranking.pop_back();
}

void Cjt_Jugadores::sumar_puntos(string nombre, int pts)
{
    int pos = (*cjt.find(nombre)).second.consultar_posicion();
    ranking[pos].puntos += pts;
}

int Cjt_Jugadores::consultar_puntos(string nombre) const
{
    int pos = (*cjt.find(nombre)).second.consultar_posicion();
    return ranking[pos].puntos;
}

bool Cjt_Jugadores::comp(const jrank& j1, const jrank& j2)
{
   if (j1.puntos != j2.puntos) return (j1.puntos > j2.puntos);
   return (j1.pos_ant < j2.pos_ant);
}

void Cjt_Jugadores::ordenar_ranking()
{
    sort(ranking.begin(),ranking.end(),comp);
    for (int i = 0; i < numero_jugadores(); ++i){
        cjt[ranking[i].nombre].actualizar_posicion(i);
        ranking[i].pos_ant = i;
    }
}

void Cjt_Jugadores::listar_ranking() const
{
    for (int i = 0; i < numero_jugadores(); ++i){
        cout << i+1 << ' ' << ranking[i].nombre << ' ' << ranking[i].puntos << endl;
    }
}

void Cjt_Jugadores::listar_jugadores() const
{
    cout << numero_jugadores() << endl;
    for (map<string, Jugador>::const_iterator it = cjt.begin(); it != cjt.end(); ++it) {
        int pos = (it->second).consultar_posicion();
        cout << it->first << " Rk:" << pos+1 << " Ps:" << ranking[pos].puntos << ' ';
        (it->second).escribir();
    }
}

void Cjt_Jugadores::listar_jugador(string nombre) const
{
    map<string, Jugador>::const_iterator it = cjt.find(nombre);
    int pos = (it->second).consultar_posicion();
    cout << nombre << " Rk:" << pos+1 << " Ps:" << ranking[pos].puntos << ' ';
    (it->second).escribir();
}

bool Cjt_Jugadores::existe(string nombre) const
{
    map<string, Jugador>::const_iterator it = cjt.find(nombre);
    return (it != cjt.end());
}
  
int Cjt_Jugadores::numero_jugadores() const
{
    return cjt.size();
}

string Cjt_Jugadores::buscar_jugador(int n) const
{
    return ranking[n-1].nombre;
}

void Cjt_Jugadores::leer()
{
    int njug;
    cin >> njug;
    ranking = vector<jrank>(njug);
    for (int i = 0; i < njug; ++i){
        string nombre;
        cin >> nombre;
        Jugador J;
        J.actualizar_posicion(i);
        cjt[nombre] = J;

        ranking[i].nombre = nombre;
        ranking[i].puntos = 0;
        ranking[i].pos_ant = i;
    }
}

void Cjt_Jugadores::actualizar_estadisticas(string jug, int t, int sg, int sp, int jg, int jp, int pg, int pp)
{
    if (existe(jug)) cjt[jug].actualizar_estadisticas(t, pg, pp, sg, sp, jg, jp);
}


