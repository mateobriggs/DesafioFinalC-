#pragma once
#include "Cotizacion.h"

class Vendedor {
	vector<Cotizacion> listaCotizaciones;
public:
	Vendedor() {}
	Vendedor(string nombre, string apellido, string id) : nombre(nombre), apellido(apellido), id(id) {}
	string nombre, apellido, id;
	double calcularResultadoCotizacion(int precio, Prenda* prendaACotizar);
	void crearCotizacion(string input1, string input2a, string input2b, string input2, string input3, string input4, string input5);
	void mostrarListaCotizaciones();
	Prenda establecerPrenda(string input1, string input2a, string input2b, string input2, string input3);
	void mostrarUltimaCotizacion();
};

