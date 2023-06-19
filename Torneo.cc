/** @file Torneo.cc
    @brief Implementación de la clase Torneo
*/

#include "Torneo.hh"

Torneo::Torneo()
{
    categoria = 0;
}

Torneo::Torneo(int cat)
{
    categoria = cat;
}

void Torneo::leer_inscritos(const Cjt_Jugadores& conj)
{
    int nins;
    cin >> nins;
    ed_anterior = ed_actual;
    ed_actual = vector<pair<string,int>>(nins);
    for (int i = 0; i < nins; ++i){
        int pos;
        cin >> pos;
        ed_actual[i].first = conj.buscar_jugador(pos);
        ed_actual[i].second = 0;
    }
}

void Torneo::escribir(const Categorias& cat) const
{
    cout << cat.nombre_categoria(categoria) << endl;
}

void Torneo::cuadro_emparejamientos()
{
    emparejar(arbol, 2, ceil(log2(ed_actual.size()) + 1), 1, ed_actual.size(), 1);
    imprimir_emparejamientos(arbol, ed_actual);
    cout << endl;
}

void Torneo::emparejar(BinTree<pair<int, string>>& a, int h, int H, int padre, int ninscritos, int potencia_ant)
{
    int potencia_act = potencia_ant * 2;
    int b = (potencia_act + 1 - padre);
    if (h > H or b > ninscritos) a = BinTree<pair<int, string>> (make_pair(padre,"0"));
    else {
        BinTree<pair<int, string>> l;
        BinTree<pair<int, string>> r;
        emparejar(l, h+1, H, padre, ninscritos, potencia_act);
        emparejar(r, h+1, H, b, ninscritos, potencia_act);
        a = BinTree<pair<int, string>> (make_pair(padre,"0"), l , r);
    }
}

void Torneo::imprimir_emparejamientos(const BinTree<pair<int, string>>& a, const vector<pair<string, int>>& ed_actual)
{
    BinTree<pair<int, string>> l = a.left();
	BinTree<pair<int, string>> r = a.right();
    if(l.empty() or r.empty()) cout << a.value().first << '.' << ed_actual[(a.value().first)-1].first;
    else {
        cout << '(';
        imprimir_emparejamientos(l, ed_actual);
        cout << ' ';
        imprimir_emparejamientos(r, ed_actual);
        cout << ')';
    }
}

void Torneo::cuadro_resultados(const Categorias& cat, Cjt_Jugadores& conj)
{
    resultados(arbol, ed_actual, 1, cat, categoria, conj);
    imprimir_resultados(arbol, ed_actual);
    cout << endl;
}

void Torneo::resultados(BinTree<pair<int, string>>& a, vector<pair<string,int>>& ed_actual,
                        int nivel, const Categorias& cat, int categoria, Cjt_Jugadores& conj)
{
    string result;
    cin >> result;
    int winner;
    if (result != "0") {
        BinTree<pair<int, string>> l = a.left();
        BinTree<pair<int, string>> r = a.right();
        resultados(l, ed_actual, nivel+1, cat, categoria, conj);
        resultados(r, ed_actual, nivel+1, cat, categoria, conj);
        if (calcular_actualizar_estadisticas(result, ed_actual[(l.value().first)-1].first,
            ed_actual[(r.value().first)-1].first, conj)) winner = l.value().first;
        else winner = r.value().first;
        a = BinTree<pair<int, string>>(make_pair(winner,result), l, r);
    }
    ed_actual[(a.value().first)-1].second = cat.consultar_puntos(categoria, nivel);
}

bool Torneo::calcular_actualizar_estadisticas(string result, string jug1, string jug2, Cjt_Jugadores& conj)
{
    int sets1, sets2, juegos1, juegos2, partidos1, partidos2;
    sets1 = sets2 = juegos1 = juegos2 = partidos1 = partidos2 = 0;

    if (result != "1-0" and result != "0-1"){
        for(int i = 0; i < result.length()-2; i+=4){
            if(result[i] > result[i+2]) ++sets1;
            else ++sets2;
            juegos1 += result[i] - '0';
            juegos2 += result[i+2] - '0';
        }
        if (sets1 > sets2) partidos1 = 1;
        else partidos2 = 1;
    }
    else{
        if (result[0] > result[2]) partidos1 = 1;
        else partidos2 = 1;
    }
    conj.actualizar_estadisticas(jug1, 0, sets1, sets2, juegos1, juegos2, partidos1, partidos2);
        conj.actualizar_estadisticas(jug2, 0, sets2, sets1, juegos2, juegos1, partidos2, partidos1);
    return (partidos1 > partidos2);
}

void Torneo::imprimir_resultados (const BinTree<pair<int, string>>& a, vector<pair<string,int>>& ed_actual)
{
    BinTree<pair<int, string>> l = a.left();
 	BinTree<pair<int, string>> r = a.right();
    if (not l.empty() or not r.empty()) {
        cout << '(';
        cout << l.value().first << '.' << ed_actual[(l.value().first)-1].first;
        cout << " vs ";
        cout << r.value().first << '.' << ed_actual[(r.value().first)-1].first;
        cout << ' ' << a.value().second;

        imprimir_resultados(l, ed_actual);
        imprimir_resultados(r, ed_actual);
        cout << ')';
    }
}

void Torneo::actualizar_puntos_torneos_escribir(Cjt_Jugadores& conj)
{
    for (int i = 0; i < ed_actual.size(); ++i){
        if (conj.existe(ed_actual[i].first)){
            conj.sumar_puntos(ed_actual[i].first,ed_actual[i].second);
            conj.actualizar_estadisticas(ed_actual[i].first, 1, 0, 0, 0, 0, 0, 0);
        }

        if (ed_actual[i].second != 0) cout << i+1 << '.' << ed_actual[i].first << ' ' << ed_actual[i].second << endl;
    }
}

void Torneo::restar_puntos_ranking(Cjt_Jugadores& conj, bool edicion_act)
{
    if (edicion_act){
        for (int i = 0; i < ed_actual.size(); ++i){
            if (conj.existe(ed_actual[i].first)) conj.sumar_puntos(ed_actual[i].first, (ed_actual[i].second*-1));
        }
    }
    else {
        for (int i = 0; i < ed_anterior.size(); ++i){
            if (conj.existe(ed_anterior[i].first) and conj.consultar_puntos(ed_anterior[i].first) != 0){
                conj.sumar_puntos(ed_anterior[i].first, (ed_anterior[i].second*-1));
            }
        }
    }
}
