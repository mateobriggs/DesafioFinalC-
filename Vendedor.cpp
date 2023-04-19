#include "PrendaHerencias.h"
#include <chrono>
#include <ctime>

void Vendedor::crearCotizacion(string input1, string input2a, string input2b, string input2, string input3, string input4, string input5) {

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

	Prenda prendaACotizar = establecerPrenda(input1, input2a, input2b, input2, input3);

	int cantidadUnidades = stoi(input5);

	int resultado, precio;
	precio = stoi(input4);
	resultado = calcularResultadoCotizacion(precio, &prendaACotizar) * cantidadUnidades;

	Cotizacion nuevaCotizacion = Cotizacion(id, fechaHora, codigoVendedor, prendaACotizar, cantidadUnidades, resultado);
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

	if (prendaACotizar->calidad == PREMIUM) {
		modificadorPrecio = (modificadorPrecio + 0.3);
	}

	return (precio * modificadorPrecio);
}

void Vendedor::mostrarListaCotizaciones() {
	for (Cotizacion cotizacion : listaCotizaciones) {
		cotizacion.imprmirCotizacion();
	}
}

Prenda Vendedor::establecerPrenda(string input1, string input2a, string input2b, string input2, string input3) {

	if (input1 == "1") {
		Camisa camisa;
		camisa.nombre = "Camisa";

		camisa.manga = (input2a == "1") ? CORTA : LARGA;
		camisa.cuello = (input2b == "1") ? MAO : COMUN;
		camisa.calidad = (input3 == "1") ? PREMIUM : STANDARD;
		return camisa;
	}

	else{
		Pantalon pantalon;
		pantalon.nombre = "Pantalon";

		pantalon.estilo = (input2 == "1") ? CHUPIN : SUELTO;
		pantalon.calidad = (input3 == "1") ? PREMIUM : STANDARD;
		return pantalon;

	}


}

void Vendedor::mostrarUltimaCotizacion() {
	listaCotizaciones[listaCotizaciones.size() - 1].imprmirCotizacion();
}