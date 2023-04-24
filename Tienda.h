#pragma once
#include "Vendedor.h"

class Tienda {
	void iniciarCantidades();
public:
	Tienda() { for (int i = 0; i < 12; i++) cantidades[i] = 0; }
	Tienda(string nombre, string direccion) : nombre(nombre), direccion(direccion) { iniciarCantidades(); }
	Vendedor vendedor;
	string nombre, direccion;
	int controladorDeStockCamisas(string input2a, string input2b, string input3);
	int controladorDeStockPantalones(string input2, string input3);
	int cantidades[12];
};