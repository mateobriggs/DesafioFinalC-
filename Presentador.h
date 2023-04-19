#pragma once
#include "PrendaHerencias.h"
#include "Vista.h"
class Presentador {
	Vista vista;
public:
	Tienda tienda;
	Vendedor vendedor;
	void mostrarPasos();
};

