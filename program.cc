/** @mainpage

    El propósito de esta práctica es el diseño y construcción de un programa modular que representa un circuito de torneos de tenis con diversas opciones para gestionarlo.

    El programa principal se encuentra en el módulo program.cc.

    Además, necesitaremos un conjunto de módulos para cumplir los requisitos del enunciado entre los que destacan: Circuito donde se desarrollarán los Torneos, Cjt_Jugadores que representa el Conjunto de Jugadores y Categorias que representa las Categorías de los torneos. Además de Torneo y Jugador.

*/

/** @file program.cc

    @brief Programa principal

    De forma resumida, este módulo ejecuta toda la lista de lecturas iniciales y, a partir de ahí, ejecuta los diferentes comandos que simulan el funcionamiento del circuito.
    En algunos casos hay que comprobar la validez de los datos introducidos antes de ejecutar algunas acciones.
*/

#ifndef NO_DIAGRAM
#include <iostream>
#include "BinTree.hh"
#endif
#include "Categorias.hh"
#include "Circuito.hh"
#include "Cjt_Jugadores.hh"
using namespace std;


int main ()
{
Categorias cat;
cat.leer();
Circuito circ;
circ.leer();
Cjt_Jugadores conj;
conj.leer();

string comando;
cin >> comando;
while (comando != "fin") {
    cout << '#' << comando;
    if (comando == "nuevo_jugador" or comando == "nj"){
        string p;
        cin >> p;
        cout << ' ' << p << endl;
        if (conj.existe(p)) cout << "error: ya existe un jugador con ese nombre" << endl;
        else {
            conj.anadir_jugador(p);
            cout << conj.numero_jugadores() << endl;
        }
    }

    else if (comando == "nuevo_torneo" or comando == "nt"){
        string t;
        int c;
        cin >> t >> c;
        cout << ' ' << t << ' ' << c << endl;
        if (c > cat.categoria_max() or c < 1) cout << "error: la categoria no existe" << endl;
        else if (circ.existe(t)) cout << "error: ya existe un torneo con ese nombre" << endl;
        else {
            circ.anadir_torneo(t,c);
            cout << circ.numero_torneos() << endl;
        }
    }

    else if (comando == "baja_jugador" or comando == "bj"){
        string p;
        cin >> p;
        cout << ' ' << p << endl;
        if (conj.existe(p)) {
            conj.eliminar_jugador(p);
            cout << conj.numero_jugadores() << endl;
        }
        else cout << "error: el jugador no existe" << endl;
    }

    else if (comando == "baja_torneo" or comando == "bt"){
        string t;
        cin >> t;
        cout << ' ' << t << endl;
        if (circ.existe(t)){
            circ.eliminar_torneo(t, conj);
            cout << circ.numero_torneos() << endl;
        }
        else cout << "error: el torneo no existe" << endl;
    }

    else if (comando == "iniciar_torneo" or comando == "it"){
        string t;
        cin >> t;
        cout << ' ' << t << endl;
        circ.iniciar_torneo(t, conj);
    }

    else if (comando == "finalizar_torneo" or comando == "ft"){
        string t;
        cin >> t;
        cout << ' ' << t << endl;
        circ.finalizar_torneo(t, conj, cat);
    }

    else if (comando == "listar_ranking" or comando == "lr"){
        cout << endl;
        conj.listar_ranking();
    }

    else if (comando == "listar_jugadores" or comando == "lj"){
        cout << endl;
        conj.listar_jugadores();
    }

    else if (comando == "consultar_jugador" or comando == "cj"){
        string p;
        cin >> p;
        cout << ' ' << p << endl;
        if (conj.existe(p)) conj.listar_jugador(p);
        else cout << "error: el jugador no existe" << endl;
    }

    else if (comando == "listar_torneos" or comando == "lt"){
        cout << endl;
        circ.listar_torneos(cat);
    }

    else if (comando == "listar_categorias" or comando == "lc"){
        cout << endl;
        cat.listar_categorias();
    }

    cin >> comando;
}
}
