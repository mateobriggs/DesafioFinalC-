#include "Tienda.h"

void Vendedor::crearCotizacion(string input1, string input2a, string input2b, string input2, string input3, int input4, int input5) {

	string idCotizacion;
	idCotizacion = "00" + to_string(listaCotizaciones.size() + 1);

	string fechaHora;
	time_t ahora = time(0);
	tm fechaYHora;
	localtime_s(&fechaYHora, &ahora);
	int dia = fechaYHora.tm_mday;
	int mes = fechaYHora.tm_mon + 1;
	int ano = fechaYHora.tm_year + 1900;
	int hora = fechaYHora.tm_hour;
	int minuto = fechaYHora.tm_min;
	int segundo = fechaYHora.tm_sec;

	fechaHora = to_string(dia) + "/" + to_string(mes) + "/" + to_string(ano) + " " + to_string(hora) + ":" + to_string(minuto) + ":" + to_string(segundo);

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

	double devolucion = precio;

	if (pantalonACotizar.estilo == CHUPIN) {
		devolucion = devolucion * (1 - 0.12);
	}

	if (pantalonACotizar.calidad == PREMIUM) {
		devolucion = devolucion * (1 + 0.3);
	}
	
	return devolucion;
}

double Vendedor::calcularResultadoCotizacion(int precio, Camisa camisaACotizar) {

	double devolucion = precio;

	if (camisaACotizar.manga == CORTA) {
		devolucion = devolucion * (1 - 0.1);
	}

	if (camisaACotizar.cuello == MAO) {
		devolucion = devolucion * (1 + 0.03);
	}

	if (camisaACotizar.calidad == PREMIUM) {
			devolucion = devolucion * (1 + 0.3);
	}

	return devolucion;
	
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

	nombre = "Pantalon";
	estilo = (input2 == "1") ? CHUPIN : SUELTO;
	calidad = (input3 == "1") ? PREMIUM : STANDARD;

	Pantalon pantalon = Pantalon(nombre, estilo, precio, calidad);

	return pantalon;

}

void Vendedor::mostrarUltimaCotizacion() {
	listaCotizaciones[listaCotizaciones.size() - 1].imprmirCotizacion();
}

void Vendedor::mostrarListaCotizaciones() {
	cout << "Historial de cotizaciones de " << nombre << " " << apellido << endl << endl;
	for (Cotizacion cotizacion : listaCotizaciones) {
		cotizacion.imprmirCotizacion();
	}
}

