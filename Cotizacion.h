#pragma once
#include "Vendedor.h"

/*AÑADIR PRECIO*/

class Cotizacion {
	string id, fechaHora, codigoVendedor, prenda;
	int cantidadUnidades, resultado;
public:
	Cotizacion(string id, string fechaHora, string codigoVendedor, string prenda, int cantidadUnidades, int resultado) :
		id(id), fechaHora(fechaHora), codigoVendedor(codigoVendedor), prenda(prenda), cantidadUnidades(cantidadUnidades),
		resultado(resultado) {}
	void imprmirCotizacion();
};
