#pragma once
#include "Cotizacion.h"

class Vendedor {
	vector<Cotizacion> listaCotizaciones;
public:
	Vendedor() {}
	Vendedor(string nombre, string apellido, string id) : nombre(nombre), apellido(apellido), id(id) {}
	string nombre, apellido, id;
	double calcularResultadoCotizacion(int precio, Pantalon prendaACotizar);
	double calcularResultadoCotizacion(int precio, Camisa prendaACotizar);
	void crearCotizacion(string input1, string input2a, string input2b, string input2, string input3, int input4, int input5);
	void mostrarListaCotizaciones();
	Camisa establecerCamisa(string input1, string input2a, string input2b, string input3, int precio);
	Pantalon establecerPantalon(string input1, string input2, string input3, int precio);
	void mostrarUltimaCotizacion();
};

