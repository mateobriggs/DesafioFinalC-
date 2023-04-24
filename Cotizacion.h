#pragma once
#include "PrendaHerencias.h"

/*A�ADIR PRECIO*/

class Cotizacion {
	string id, fechaHora, codigoVendedor;
	int cantidadUnidades, precio;
	double resultado;
	Pantalon* pantalon;
	Camisa* camisa;
	string detallesPrenda;
public:
	Cotizacion(string id, string fechaHora, string codigoVendedor, Pantalon pantalon, int cantidadUnidades, double resultado, int precio) :
		id(id), fechaHora(fechaHora), codigoVendedor(codigoVendedor), pantalon(&pantalon), cantidadUnidades(cantidadUnidades),
		resultado(resultado), precio(precio), camisa(nullptr), detallesPrenda("") { definirDetallesPrenda(); }
	Cotizacion(string id, string fechaHora, string codigoVendedor, Camisa camisa, int cantidadUnidades, double resultado, int precio) :
		id(id), fechaHora(fechaHora), codigoVendedor(codigoVendedor), camisa(&camisa), cantidadUnidades(cantidadUnidades),
		resultado(resultado), precio(precio), pantalon(nullptr), detallesPrenda("") { definirDetallesPrenda(); }
	void imprmirCotizacion();
	void definirDetallesPrenda();
};
