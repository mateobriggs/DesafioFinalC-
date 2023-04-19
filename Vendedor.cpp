#include "PrendaHerencias.h"
#include <chrono>
#include <ctime>

void Vendedor::crearCotizacion() {

	string idCotizacion;
	idCotizacion = listaCotizaciones.size();

	string fechaHora;
	auto horaActual = chrono::system_clock::now();
	time_t horaAcutal_h = chrono::system_clock::to_time_t(horaActual);
	tm* momentoCotizacion = gmtime(&horaAcutal_h);
	string dia = to_string(momentoCotizacion->tm_wday + 1);
	string mes = to_string(momentoCotizacion->tm_mon + 1);
	string ano = to_string(momentoCotizacion->tm_year + 1900);
	string hora = to_string(momentoCotizacion->tm_hour);
	string minuto = to_string(momentoCotizacion->tm_min);
	string segundo = to_string(momentoCotizacion->tm_sec);
	fechaHora = dia + "/" + mes + "/" + ano + " " + hora + ":" + minuto + ":" + segundo;

	string codigoVendedor = id;

	string prenda;
	Prenda prendaACotizar;
	prenda = prendaACotizar.nombre;

	int cantidadUnidades;

	int resultado, precio;
	resultado = calcularResultadoCotizacion(precio, &prendaACotizar) * cantidadUnidades;

	Cotizacion nuevaCotizacion = Cotizacion(id, fechaHora, codigoVendedor, prenda, cantidadUnidades, resultado);
	listaCotizaciones.push_back(nuevaCotizacion);
}

int Vendedor::calcularResultadoCotizacion(int precio, Prenda* prendaACotizar) {

	int modificadorPrecio = 1;

	if (prendaACotizar->nombre == "Pantalon") {
		Pantalon* pantalon = static_cast<Pantalon*>(prendaACotizar);
		if (pantalon->estilo == CHUPIN) {
			modificadorPrecio = (modificadorPrecio - 0.12);
		}
	}

	if(prendaACotizar->nombre == "Camisa") {
		Camisa* camisa = static_cast<Camisa*>(prendaACotizar);
		if (camisa->manga == CORTA) {
			modificadorPrecio = (1 - 0.1);
		}
		if (camisa->cuello == MAO) {
			modificadorPrecio = (modificadorPrecio + 0.03);
		}
	}

	if (prendaACotizar->calidad == "Premium") {
		modificadorPrecio = (modificadorPrecio + 0.3);
	}

	return (precio * modificadorPrecio);
}