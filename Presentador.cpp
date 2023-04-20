#include "Presentador.h"
using namespace std;
Presentador::Presentador(Vista* vista) {
	this->vista = vista;
	crearVendedor();
	crearTienda();
	system("cls");
}

void Presentador::realizarPasos() {
	string input = "";
	void(Vista:: * ptrFuncion)();
	vector<string> volver;
	bool volviendo = false;
	do {
		if (volviendo) {
			input = "2";
		}
		if(!volviendo) {
			ptrFuncion = &Vista::mostrarPaginaPrincipal;
			input = realizarPasoPagPrincipal(ptrFuncion);
		}

		if (input == "1") {

			vendedor.mostrarListaCotizaciones();
			cin.get();
			system("cls");

		}

		if (input == "2") {
			string input1, input2a, input2b, input2, input3;
			int input4, input5, paso = 0;
			bool volverAlMenu = false;
			if (volviendo) {
				input1 = volver[paso];
			}
			if (!volviendo) {
				ptrFuncion = &Vista::mostrarSeleccionarPrenda;
				input1 = realizarPaso(ptrFuncion);
				volver.push_back(input1);
			}
			
			if (input1 == "1") {
				paso++;
				if (volviendo) {
					input2a = volver[paso];

				}
				if (!volviendo) {
					ptrFuncion = &Vista::mostrarSeleccionarManga;
					input2a = realizarPaso(ptrFuncion);
				}
				
				volverAlMenu = input2a == "Menu Principal" ? true : false;

				if (!volverAlMenu) {

					volver.push_back(input2a);

					if (volviendo) {
						input2b = volver[paso];

					}
					if (!volviendo) {
						ptrFuncion = &Vista::mostrarSeleccionarCuello;
						input2b = realizarPaso(ptrFuncion);
						volver.push_back(input2b);
					}
					
					volverAlMenu = input2b == "Menu Principal" ? true : false;

				}
				
			}
			else {

				if (input1 == "2") {
					if (volviendo) {
						input2 = volver[paso];

					}
					if (!volviendo) {
						ptrFuncion = &Vista::mostrarSeleccionarPantalon;
						input2 = realizarPaso(ptrFuncion);
						volver.push_back(input2);
					}
					
					volverAlMenu = input2 == "Menu Principal" ? true : false;

				}
				else {

					if (input1 == "Menu Principal") {

						volverAlMenu = true;

					}

				}

			}

			if (!volverAlMenu) {
			
				ptrFuncion = &Vista::mostrarSeleccionarCalidad;
				input3 = realizarPaso(ptrFuncion);
				volver.push_back(input3);
				for (int i = 0; i < volver.size(); i++) {
					cout << volver[i] << " ";
				}
				cout << endl;
				if (input3 != "Menu Principal") {

					volver.clear();

					ptrFuncion = &Vista::mostrarIngresarPrecio;
					input4 = realizarPasoCantidadPrecio(ptrFuncion);

					if (input4 > 0) {

						ptrFuncion = &Vista::mostrarIngresarCantidad;
						input5 = realizarPasoCantidadPrecio(ptrFuncion);

						if (input5 > 0) {
							
							vendedor.crearCotizacion(input1, input2a, input2b, input2, input3, input4, input5);

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
				vista->mostrarMensajeError();
				vista->mostrarMensajeContinuar();
				cin.get();
				system("cls");
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

int Presentador::realizarPasoCantidadPrecio(void (Vista::* funcionVista)()) {
	string input;
	bool inputCorrecto;
	int devolucion;
	do {
		vista->mostrarHeader();
		inputCorrecto = true;
		(vista->*funcionVista)();
		getline(cin, input);
		system("cls");
		try {
			devolucion = stoi(input);
		}
		catch (exception) {

			if (input != "X") {

				inputCorrecto = false;
				vista->mostrarMensajeError();
				vista->mostrarMensajeContinuar();
				cin.get();
				system("cls");

			}

			else devolucion = -1;
			
		}

	} while (!inputCorrecto);

	return devolucion;
}