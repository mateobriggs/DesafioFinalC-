#pragma once
#include "Tienda.h"
#include "Vista.h"

class Presentador {
	Vista* vista;
public:
	Presentador(Vista* vista);
	Tienda tienda;
	void realizarPasos();
	void crearTienda();
	void crearVendedor();
	string realizarPaso(void (Vista:: *funcionVista)());
	string realizarPasoPagPrincipal(void (Vista:: *funcionVista)());
	int realizarPasoCantidadPrecio(void (Vista:: *funcionVista)(), bool definiendoCantidad, int cantidadStock);
};
