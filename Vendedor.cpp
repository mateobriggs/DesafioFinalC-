#include "Tienda.h"

void Vendedor::crearCotizacion(string input1, string input2a, string input2b, string input2, string input3, int input4, int input5) {

	string idCotizacion;
	idCotizacion = "00" + to_string(listaCotizaciones.size() + 1);

	string fechaHora = "10/2/2023 15:50:04";
	/*auto horaActual = chrono::system_clock::now();
	time_t horaAcutal_h = chrono::system_clock::to_time_t(horaActual);
	tm* momentoCotizacion = gmtime_s(&horaAcutal_h);
	string dia = to_string(momentoCotizacion->tm_wday + 1);
	string mes = to_string(momentoCotizacion->tm_mon + 1);
	string ano = to_string(momentoCotizacion->tm_year + 1900);
	string hora = to_string(momentoCotizacion->tm_hour);
	string minuto = to_string(momentoCotizacion->tm_min);
	string segundo = to_string(momentoCotizacion->tm_sec);
	fechaHora = dia + "/" + mes + "/" + ano + " " + hora + ":" + minuto + ":" + segundo;*/

	string codigoVendedor = id;

	int precio = input4;
	double resultado;
	int cantidadUnidades = input5;

	if (input1 == "1") {
		Camisa prendaACotizar = establecerCamisa(input1, input2a, input2b, input3, input4);
		resultado = calcularResultadoCotizacion(precio, prendaACotizar) * cantidadUnidades;
		Cotizacion nuevaCotizacion = Cotizacion(idCotizacion, fechaHora, codigoVendedor, prendaACotizar, cantidadUnidades, resultado, precio);
		listaCotizaciones.push_back(nuevaCotizacion);
	}
	else {
		Pantalon prendaACotizar = establecerPantalon(input1, input2, input3, input4);
		resultado = calcularResultadoCotizacion(precio, prendaACotizar) * cantidadUnidades;
		Cotizacion nuevaCotizacion = Cotizacion(idCotizacion, fechaHora, codigoVendedor, prendaACotizar, cantidadUnidades, resultado, precio);
		listaCotizaciones.push_back(nuevaCotizacion);
	}

	
}

double Vendedor::calcularResultadoCotizacion(int precio, Pantalon pantalonACotizar) {

	double modificadorPrecio = 1;
	if (pantalonACotizar.estilo == CHUPIN) {
		modificadorPrecio = (modificadorPrecio - 0.12);
	}

	if (pantalonACotizar.calidad == PREMIUM) {
		modificadorPrecio = (modificadorPrecio + 0.3);
	}
	
	return (precio * modificadorPrecio);
}

double Vendedor::calcularResultadoCotizacion(int precio, Camisa camisaACotizar) {

	double modificadorPrecio = 1;

	if (camisaACotizar.manga == CORTA) {
		modificadorPrecio = (modificadorPrecio - 0.9);
	}

	if (camisaACotizar.cuello == MAO) {
		modificadorPrecio = (modificadorPrecio + 0.03);
	}

	if (camisaACotizar.calidad == PREMIUM) {
		modificadorPrecio = (modificadorPrecio + 0.3);
	}

	return (precio * modificadorPrecio);
}

Camisa Vendedor::establecerCamisa(string input1, string input2a, string input2b, string input3, int precio) {

		string nombre;
		Manga manga;
		Cuello cuello;
		Calidad calidad;

		nombre = "Camisa";
		manga = (input2a == "1") ? CORTA : LARGA;
		cuello = (input2b == "1") ? MAO : COMUN;
		calidad = (input3 == "1") ? PREMIUM : STANDARD;

		Camisa camisa = Camisa(nombre, cuello, manga, precio, calidad);

		return camisa;

}

Pantalon Vendedor::establecerPantalon(string input1,string input2, string input3, int precio) {

	string nombre;
	Estilo estilo;
	Calidad calidad;

	nombre = "Camisa";
	estilo = (input2 == "1") ? CHUPIN : SUELTO;
	calidad = (input3 == "1") ? PREMIUM : STANDARD;

	Pantalon pantalon = Pantalon(nombre, estilo, precio, calidad);

	return pantalon;

}

void Vendedor::mostrarUltimaCotizacion() {
	listaCotizaciones[listaCotizaciones.size() - 1].imprmirCotizacion();
}

void Vendedor::mostrarListaCotizaciones() {
	for (Cotizacion cotizacion : listaCotizaciones) {
		cotizacion.imprmirCotizacion();
	}
}

