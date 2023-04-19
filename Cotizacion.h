#pragma once
#include "Prenda.h"

/*AÑADIR PRECIO*/

class Cotizacion {
	string id, fechaHora, codigoVendedor;
	int cantidadUnidades;
	double resultado;
	Prenda prenda;
public:
	Cotizacion(string id, string fechaHora, string codigoVendedor, Prenda prenda, int cantidadUnidades, double resultado) :
		id(id), fechaHora(fechaHora), codigoVendedor(codigoVendedor), prenda(prenda), cantidadUnidades(cantidadUnidades),
		resultado(resultado) {}
	void imprmirCotizacion();
};
