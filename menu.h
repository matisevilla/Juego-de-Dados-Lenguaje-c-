#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

void menu();

void menu() {

    int opcion;
    bool modoSimulado = false;
    string maximoNombre;
    int maximoPuntaje = 0;

    while (true) {

        rlutil::setBackgroundColor(12);
        rlutil::setColor(rlutil::BLACK);
        rlutil::saveDefaultColor();
        system("cls");
        /// Mostramos un cout u otro dependiendo de si la variable modoSimulado esta en true o false
        if (modoSimulado) {
            cout << "------* Menu Modo Simulado *------" << endl << endl;
        } else {
            cout << "--------* Menu Principal *--------" << endl << endl;
        }
        cout << "1) Un jugador" << endl << endl;
        cout << "2) Dos jugadores" << endl << endl;
        cout << "3) Puntuacion mas alta" << endl << endl;
        /// Mostramos un cout u otro dependiendo de si la variable modoSimulado esta en true o false
        if (modoSimulado == false) {
            cout << "4) Modo Simulado" << endl << endl;
        }else{
            cout << "4) Salir Modo Simulado" << endl << endl;
        }
        cout << "----------------------------------" << endl << endl;
        cout << "0) Salir" << endl << endl;

        /// INGRESO DE OPCION
        opcion = rlutil::getkey();

        switch (opcion) {
            case '1':
                system("cls");
                unJugador(maximoNombre, maximoPuntaje, modoSimulado);
                cout << endl;
                break;
            case '2':
                system("cls");
                dosJugadores(maximoNombre, maximoPuntaje, modoSimulado);
                cout << endl;
                break;
            case '3':
                system("cls");
                highscore(maximoNombre, maximoPuntaje);
                system("pause");
                cout << endl;
                break;
            case '4':
                modoSimuladoF(modoSimulado);
                break;
            case '0':
                return;
                break;
            default:
                /// Default en caso de introducir un numero no listado
                cout << "Error, numero incorrecto." << endl;
                system("pause");
                break;
        }
    }
}

#endif // MENU_H_INCLUDED

