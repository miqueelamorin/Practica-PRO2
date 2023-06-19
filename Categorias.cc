/** @file Categorias.cc
    @brief Implementación de la clase Categorias
*/

#include "Categorias.hh"

Categorias::Categorias(){}

int Categorias::categoria_max() const
{
    return C;
}

int Categorias::consultar_puntos(int categ, int nivel) const
{
    return tabla_puntos[categ-1][nivel-1];
}

void Categorias::leer()
{
    int K;
    cin >> C >> K;
    categorias = vector<string>(C);
    for (int i = 0; i < C; ++i){
        cin >> categorias[i];
    }
    tabla_puntos = vector < vector <int> >(C,vector<int>(K));
    for (int i = 0; i < C; ++i){
        for (int j = 0; j < K; ++j){
            cin >> tabla_puntos[i][j];
        }
    }
}

void Categorias::listar_categorias() const
{
    int K = tabla_puntos[0].size();
    cout << C << ' ' << K << endl;
    for (int i = 0; i < C; ++i){
        cout << categorias[i];
        for (int j = 0; j < K; ++j){
             cout << ' ' << tabla_puntos[i][j];
        }
        cout << endl;
    }
}

string Categorias::nombre_categoria(int categ) const
{
    return categorias[categ-1];
}
