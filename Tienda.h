#pragma once
#include "Vendedor.h"

class Tienda {
public:
	Tienda() {}
	Tienda(string nombre, string direccion) : nombre(nombre), direccion(direccion) { iniciarCantidades(); }
	Vendedor vendedor;
	string nombre, direccion;
	vector<Prenda> listaDePrendas;
	int controladorDeStockCamisas(string input2a, string input2b, string input3);
	int controladorDeStockPantalones(string input2, string input3);
	void iniciarCantidades();
	int cantidades[12];
};