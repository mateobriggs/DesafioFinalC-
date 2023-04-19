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
	void crearCotizacion(string input1, string input2a, string input2b, string input2, string input3, string input4, string input5);
	void mostrarListaCotizaciones();
	Prenda establecerPrenda(string input1, string input2a, string input2b, string input2, string input3);
	void mostrarUltimaCotizacion();
};
