#pragma once
#include "Vendedor.h"

class Tienda {
public:
	Tienda() {}
	Tienda(string nombre, string direccion) : nombre(nombre), direccion(direccion) {}
	string nombre, direccion;
	vector<Prenda> listaDePrendas;
};