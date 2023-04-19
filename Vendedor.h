#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Vendedor {
	int cantidad;
	vector<Cotizacion> listaCotizaciones;
public:
	string nombre, apellido, id;
	int calcularResultadoCotizacion(int precio, Prenda* prendaACotizar);
	void crearCotizacion();
	void establecerPrenda();
};
