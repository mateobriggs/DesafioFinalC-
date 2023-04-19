#include "Presentador.h"

Presentador::Presentador(Vista* vista) {
	this->vista = vista;
	crearVendedor();
	crearTienda();
}

void Presentador::mostrarPasos() {
	string input = "";
	do {
		vista->mostrarPaginaPrincipal();
		getline(cin, input);
		system("cls");
		if (input == "1") {
			vendedor.mostrarListaCotizaciones();
			cin.get();
		}
		if (input == "2") {
			vista->mostrarHeader();
			string input1, input2a, input2b, input2, input3, input4, input5;
			bool respuestaCorrecta = false;
			vista->mostrarSeleccionarPrenda();
			getline(cin, input1);
			system("cls");
			if (input1 == "1") {
				vista->mostrarHeader();
				respuestaCorrecta = true;
				vista->mostrarSeleccionarManga();
				getline(cin, input2a);
				system("cls");
				if (input2a == "1") {
					vista->mostrarHeader();
					vista->mostrarSeleccionarCuello();
					getline(cin, input2b);
					system("cls");
				}
			}
			else {
				if (input1 == "2") {
					vista->mostrarHeader();
					respuestaCorrecta = true;
					string input2 = "";
					vista->mostrarSeleccionarPantalon();
					getline(cin, input2);
				}
				else {
					/*OPCION POR SI SE EQUIVOCA*/
				}
			}

			if (respuestaCorrecta) {
				vista->mostrarHeader();
				vista->mostrarSeleccionarCalidad();
				getline(cin, input3);
				system("cls");
				vista->mostrarHeader();
				vista->mostrarIngresarPrecio();
				getline(cin, input4);
				system("cls");
				vista->mostrarHeader();
				vista->mostrarIngresarCantidad();
				getline(cin, input5);
				system("cls");
				vendedor.crearCotizacion(input1, input2a, input2b, input2, input3, input4, input5);
			}
			vista->mostrarCotizacion();
		}
		if (input == "3") {
			input = "0";
		}
	} while (input != "0");
}

void Presentador::crearVendedor() {

	string nombreVendedor, apellidoVendedor, idVendedor;

	vista->mostrarCrearVendedorNombre();
	getline(cin, nombreVendedor);
	vista->mostrarCrearVendedorApellido();
	getline(cin, apellidoVendedor);
	vista->mostrarCrearVendedorId();
	getline(cin, idVendedor);
	vendedor = Vendedor(nombreVendedor, apellidoVendedor, idVendedor);
}

void Presentador::crearTienda() {

	string nombreTienda, direccionTienda;

	vista->mostrarCrearTiendaNombre();
	getline(cin, nombreTienda);
	vista->mostrarCrearTiendaDireccion();
	getline(cin, direccionTienda);
	tienda = Tienda(nombreTienda, direccionTienda);
}