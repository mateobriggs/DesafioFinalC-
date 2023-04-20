#pragma once
#include "PrendaHerencias.h"

/*AÑADIR PRECIO*/

class Cotizacion {
	string id, fechaHora, codigoVendedor;
	int cantidadUnidades, precio;
	double resultado;
	Pantalon* pantalon;
	Camisa* camisa;
public:
	Cotizacion(string id, string fechaHora, string codigoVendedor, Pantalon pantalon, int cantidadUnidades, double resultado, int precio) :
		id(id), fechaHora(fechaHora), codigoVendedor(codigoVendedor), pantalon(&pantalon), cantidadUnidades(cantidadUnidades),
		resultado(resultado), precio(precio), camisa(nullptr) {}
	Cotizacion(string id, string fechaHora, string codigoVendedor, Camisa camisa, int cantidadUnidades, double resultado, int precio) :
		id(id), fechaHora(fechaHora), codigoVendedor(codigoVendedor), camisa(&camisa), cantidadUnidades(cantidadUnidades),
		resultado(resultado), precio(precio), pantalon(nullptr) {}
	void imprmirCotizacion();
	string definirDetallesPrenda();
};
