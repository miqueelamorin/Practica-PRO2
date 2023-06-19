/** @file Jugador.cc
 *    @brief Implementación de la clase Jugador
 */

#include "Jugador.hh"

Jugador::Jugador()
{
  pos = tj = pg = pp = sg = sp = jg = jp = 0;
}

void Jugador::escribir() const
{
  cout << "Ts:" << tj;
  cout << " WM:" << pg;
  cout << " LM:" << pp;
  cout << " WS:" << sg;
  cout << " LS:" << sp;
  cout << " WG:" << jg;
  cout << " LG:" << jp << endl;
}

void Jugador::actualizar_estadisticas(int tj, int pg, int pp, int sg, int sp, int jg, int jp)
{
  this->pg += pg;
  this->pp += pp;
  this->sg += sg;
  this->sp += sp;
  this->jg += jg;
  this->jp += jp;
  this->tj += tj;
}

void Jugador::actualizar_posicion(int p)
{
  pos = p;
}

int Jugador::consultar_posicion() const
{
  return pos;
}
