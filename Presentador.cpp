#include "Presentador.h"

Presentador::Presentador(Vista* vista) {
	this->vista = vista;
	crearTienda();
	crearVendedor();
	system("cls");
}

void Presentador::realizarPasos() {

	string input = "";
	void(Vista:: * ptrFuncion)();

	do {
		

		
		ptrFuncion = &Vista::mostrarPaginaPrincipal;
		input = realizarPasoPagPrincipal(ptrFuncion);
		

		if (input == "1") {

			tienda.vendedor.mostrarListaCotizaciones();
			cin.get();
			system("cls");

		}

		if (input == "2") {

			string input1, input2a, input2b, input2, input3;
			int input4, input5, paso = 0;
			bool volverAlMenu = false;

			ptrFuncion = &Vista::mostrarSeleccionarPrenda;
			input1 = realizarPaso(ptrFuncion);
			
			if (input1 == "1") {
				
				ptrFuncion = &Vista::mostrarSeleccionarManga;
				input2a = realizarPaso(ptrFuncion);
				
				volverAlMenu = input2a == "Menu Principal" ? true : false;

				if (!volverAlMenu) {

					ptrFuncion = &Vista::mostrarSeleccionarCuello;
					input2b = realizarPaso(ptrFuncion);
					
					volverAlMenu = input2b == "Menu Principal" ? true : false;

				}
				
			}

			else {

				if (input1 == "2") {

					ptrFuncion = &Vista::mostrarSeleccionarPantalon;
					input2 = realizarPaso(ptrFuncion);

					volverAlMenu = input2 == "Menu Principal" ? true : false;

				}

				else {

						volverAlMenu = true;

				}

			}

			if (!volverAlMenu) {

				ptrFuncion = &Vista::mostrarSeleccionarCalidad;
				input3 = realizarPaso(ptrFuncion);
		
				if (input3 != "Menu Principal") {

					int cantidadEnStock = input1 == "1" ? tienda.controladorDeStockCamisas(input2a, input2b, input3) : tienda.controladorDeStockPantalones(input2, input3);
					bool definiendoCantidad = false;

					ptrFuncion = &Vista::mostrarIngresarPrecio;
					input4 = realizarPasoCantidadPrecio(ptrFuncion, definiendoCantidad, cantidadEnStock);

					if (input4 > 0) {
						definiendoCantidad = true;
						ptrFuncion = &Vista::mostrarIngresarCantidad;
						input5 = realizarPasoCantidadPrecio(ptrFuncion, definiendoCantidad, cantidadEnStock);

						if (input5 > 0) {
							
							tienda.vendedor.crearCotizacion(input1, input2a, input2b, input2, input3, input4, input5);

							vista->mostrarCotizacion();
							cout << endl;
							vista->mostrarMensajeContinuar();
							
							cin.get();
							system("cls");

						}

					}

				}

			}

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
	tienda.vendedor = Vendedor(nombreVendedor, apellidoVendedor, idVendedor);
}

void Presentador::crearTienda() {

	string nombreTienda, direccionTienda;

	vista->mostrarCrearTiendaNombre();
	getline(cin, nombreTienda);
	vista->mostrarCrearTiendaDireccion();
	getline(cin, direccionTienda);
	tienda = Tienda(nombreTienda, direccionTienda);
}

string Presentador::realizarPaso(void (Vista::* funcionVista)()) {
	string input;
	bool inputCorrecto = false;
	do {
		vista->mostrarHeader();
		(vista->*funcionVista)();
		getline(cin, input);
		system("cls");
		if (input == "1" || input == "2") {
			inputCorrecto = true;
		}
		else {
			if (input == "X") {
				inputCorrecto = true;
				input = "Menu Principal";
			}
			else {
				if (input == "B") {
					inputCorrecto = true;
					input = "Volver";
				}
				else {
					vista->mostrarMensajeError();
					vista->mostrarMensajeContinuar();
					cin.get();
					system("cls");
				}
				
			}
		}
	} while (!inputCorrecto);
	
	return input;
}

string Presentador::realizarPasoPagPrincipal(void (Vista::* funcionVista)()) {
	string input;
	bool inputCorrecto = false;
	do {
		(vista->*funcionVista)();
		getline(cin, input);
		system("cls");
		if (input == "1" || input == "2" || input == "3") {
			inputCorrecto = true;
		}
		else {
			vista->mostrarMensajeError();
			vista->mostrarMensajeContinuar();
			cin.get();
			system("cls");
		}
	} while (!inputCorrecto);

	return input;
}

int Presentador::realizarPasoCantidadPrecio(void (Vista::* funcionVista)(), bool definiendoCantidad, int cantidadStock) {
	string input;
	bool inputCorrecto;
	int devolucion;
	do {
		vista->mostrarHeader();
		inputCorrecto = true;
		if (definiendoCantidad) {
			cout << "INFORMACION: " << endl
				<< "EXISTE " << cantidadStock << " CANTIDAD DE UNIDADES EN STOCK DE ESTA PRENDA" << endl;
		}
		(vista->*funcionVista)();
		getline(cin, input);
		system("cls");
		try {
			devolucion = stoi(input);
		}
		catch (exception) {

			if (input != "X") {

				inputCorrecto = false;
				
			}

			else devolucion = -1;
			
		}
		if (definiendoCantidad) {
			if (devolucion > cantidadStock) {
				inputCorrecto = false;
			}
		}
		if (!inputCorrecto) {
			vista->mostrarMensajeError();
			vista->mostrarMensajeContinuar();
			cin.get();
			system("cls");
		}
		

	} while (!inputCorrecto);

	

	return devolucion;
}