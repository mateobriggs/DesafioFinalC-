#pragma once
#include "PrendaHerencias.h"
#include "Vista.h"

class Presentador {
	Vista* vista;
public:
	Presentador() {}
	Presentador(Vista* vista);
	Tienda tienda;
	Vendedor vendedor;
	void mostrarPasos();
	void crearTienda();
	void crearVendedor();
};
