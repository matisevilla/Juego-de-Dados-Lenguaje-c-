#ifndef MODOS_H_INCLUDED
#define MODOS_H_INCLUDED

void unJugador(string &maximoNombre, int &maximoPuntaje, bool modoSimulado);
void dosJugadores(string &maximoNombre, int &maximoPuntaje, bool modoSimulado);
void modoSimuladoF(bool &modoSimulado);
void cargarNombre(string &nombre);
void cargarNombre2jugadores(string nombres[]);
void cargarRondas (int &rondasPredefinidas);
void highscore(string maximoNombre, int maximoPuntaje);

void unJugador(string &maximoNombre, int &maximoPuntaje, bool modoSimulado) {
    int puntosTotal = 0;
    string nombre;
    int ronda = 0;
    int maxPuntajeRonda;
    int puntosLanzamiento = 0;
    int dados[6]{};

    cargarNombre(nombre);

    /// While que corta cuando el jugador llega a 100 y para contar las rondas
    while (puntosTotal < 100) {
        int lanzamiento = 1;
        ronda++;
        maxPuntajeRonda = 0;
        bool sexteto6 = false;

        /// While de 3 para los tres lanzamientos de cada ronda
        while (lanzamiento <= 3 && !sexteto6){
            system("cls");
            tirarDados(dados, modoSimulado);
            acumularDados(dados, puntosLanzamiento);
            maxPuntajeRondaF(maxPuntajeRonda, puntosLanzamiento);

            if(sextetoF(dados, puntosLanzamiento)){
                if(dados[0] == 6){
                    maxPuntajeRonda = 0;
                    puntosTotal = 0;
                    sexteto6 = true;
                } else {
                    maxPuntajeRondaF(maxPuntajeRonda, puntosLanzamiento);
                }
            }

            cout << "---------------------* Un jugador *------------------------" << endl;
            cout << "Turno de: " << nombre << " | " << "Ronda numero: " << ronda << " | " << "Puntaje total: " << puntosTotal << " | " << endl;
            cout << "-----------------------------------------------------------" << endl;
            cout << "Maximo puntaje de la ronda: " << maxPuntajeRonda << endl;
            cout << endl;
            cout << "Lanzamiento N-" << lanzamiento << endl;
            cout << "-----------------------------------------------------------" << endl;
            cout << endl;
            cout << "\t";

            //mostrarDados(dados);
            dibujarDados(dados);
            cout << endl;

            if(esEscalera(dados)){
                puntosTotal += 100;
                if(puntosTotal > maximoPuntaje){
                    maximoNombre = nombre;
                    maximoPuntaje = puntosTotal;
                }
                rlutil::locate(1, 13);
                cout << "Es escalera, ganaste!" << endl;
                cout << endl;
                system("pause");

                system("cls");
                cout << "-----------------------------------------------------------" << endl;
                cout << "\t\t\tJUEGO TERMINADO" << endl;
                cout << "-----------------------------------------------------------" << endl;
                cout << endl;
                cout << nombre << " Ganaste con Escalera!" << endl;
                cout << "Ganaste en " << ronda << " rondas" << endl;
                cout << endl;
                system("pause");
                return;
            }

            if(sextetoF(dados, puntosLanzamiento)){
                if(dados[0] == 6){
                    puntosLanzamiento = 0;
                    rlutil::locate(1, 13);
                    cout << "Sexteto de 6, Resetea el puntaje total a 0!" << endl;
                } else {
                    rlutil::locate(1, 13);
                    cout << "Sexteto de " << dados[0] << ", Se multiplica por 10!" << endl;
                }
            } else {
                rlutil::locate(1, 13);
                cout << "Suma de dados!" << endl;
            }

            cout << endl;
            rlutil::locate(1, 14);
            cout << "Puntos: " << puntosLanzamiento << endl;
            cout << endl;
            system ("pause");
            lanzamiento++;
        }

        puntosTotal += maxPuntajeRonda;

        system("cls");
        cout << "RONDA N " << ronda << endl;
        cout << "JUGADOR " << nombre << endl;
        cout << "PUNTAJE " << puntosTotal << endl;
        system("pause");
    }

    if(puntosTotal > maximoPuntaje){
        maximoNombre = nombre;
        maximoPuntaje = puntosTotal;
    }

    system("cls");
    cout << "-----------------------------------------------------------" << endl;
    cout << "\t\t\tJUEGO TERMINADO" << endl;
    cout << "-----------------------------------------------------------" << endl;
    cout << endl;
    cout << nombre << " Ganaste!" << " Obtuviste " << puntosTotal << " puntos" << endl;
    cout << "Ganaste en " << ronda << " rondas" << endl;
    cout << endl;
    system("pause");
    return;
}

void dosJugadores(string &maximoNombre, int &maximoPuntaje, bool modoSimulado){
    string nombres[2];
    string nombreFinal;
    int puntajeFinal = 0;
    int puntosTotal[2]{};
    int ronda = 0;
    int maxPuntajeRonda;
    int maxPuntajeLanzamiento[2]{};
    int puntosLanzamiento = 0;
    int dados[6]{};
    int rondasPredefinidas;

    cargarNombre2jugadores(nombres);
    cargarRondas(rondasPredefinidas);

    while(ronda != rondasPredefinidas){
        ronda++;

        for(int i = 0; i < 2; i++ ){
            int lanzamiento = 1;
            maxPuntajeRonda = 0;
            bool sexteto6 = false;

            while (lanzamiento <= 3 && !sexteto6){
                system("cls");
                tirarDados(dados, modoSimulado);
                acumularDados(dados, puntosLanzamiento);
                maxPuntajeRonda2Jugadores(maxPuntajeRonda, puntosLanzamiento, maxPuntajeLanzamiento, lanzamiento, i);

                if(sextetoF(dados, puntosLanzamiento)){
                    if(dados[0] == 6){
                        maxPuntajeRonda = 0;
                        puntosTotal[i] = 0;
                        sexteto6 = true;
                    } else {
                        maxPuntajeRonda2Jugadores(maxPuntajeRonda, puntosLanzamiento, maxPuntajeLanzamiento, lanzamiento, i);
                    }
                }

                cout << "---------------------* Dos jugadores *------------------------" << endl;
                cout << "Turno de: " << nombres[i] << " | " << "Ronda numero: " << ronda << " | " << "Puntaje total: " << puntosTotal[i] << " | " << endl;
                cout << "-----------------------------------------------------------" << endl;
                cout << "Maximo puntaje de la ronda: " << maxPuntajeRonda << endl;
                cout << endl;
                cout << "Lanzamiento N-" << lanzamiento << endl;
                cout << "-----------------------------------------------------------" << endl;
                cout << endl;
                cout << "\t";

                //mostrarDados(dados);
                dibujarDados(dados);
                cout << endl;

                if(esEscalera(dados)){
                    ///Esta en +=100 pero podria ser =100 o podria ser un return directo.
                    puntosTotal[i] += 100;
                    if(puntosTotal[i] > maximoPuntaje){
                        maximoNombre = nombres[i];
                        maximoPuntaje = puntosTotal[i];
                    }
                    rlutil::locate(1, 13);
                    cout << "Es escalera, ganaste!" << endl;
                    cout << endl;
                    system("pause");

                    system("cls");
                    cout << "-----------------------------------------------------------" << endl;
                    cout << "\t\t\tJUEGO TERMINADO" << endl;
                    cout << "-----------------------------------------------------------" << endl;
                    cout << endl;
                    cout << nombres[i] << " Ganaste con Escalera!" << endl;
                    cout << "Ganaste en " << ronda << " rondas" << endl;
                    cout << endl;
                    system("pause");
                    return;
                }

                if(sextetoF(dados, puntosLanzamiento)){
                    if(dados[0] == 6){
                        puntosLanzamiento = 0;
                        rlutil::locate(1, 13);
                        cout << "Sexteto de 6, Resetea el puntaje total a 0!" << endl;
                    } else {
                        rlutil::locate(1, 13);
                        cout << "Sexteto de " << dados[0] << ", Se multiplica por 10!" << endl;
                    }
                } else {
                    rlutil::locate(1, 13);
                    cout << "Suma de dados!" << endl;
                }

                cout << endl;
                rlutil::locate(1, 14);
                cout << "Puntos: " << puntosLanzamiento << endl;
                cout << endl;
                system ("pause");
                lanzamiento++;

            }

            puntosTotal[i] += maxPuntajeRonda;

            system("cls");
            cout << "RONDA N " << ronda << endl;
            cout << endl;
            if(i == 1){
                cout << "PROXIMO TURNO: " << nombres[0] << endl;
            }else{
                cout << "PROXIMO TURNO: " << nombres[1] << endl;
            }
            cout << endl;
            cout << "PUNTAJE "<<nombres[0] <<": "<< puntosTotal[0] << endl;
            cout << "PUNTAJE "<<nombres[1] <<": "<< puntosTotal[1] << endl;
            system("pause");

        }

        ///Calculo deseempate
        if(puntosTotal[0] >= 100 && puntosTotal[1] >= 100){
            if(maxPuntajeLanzamiento[0] < maxPuntajeLanzamiento[1]){
                nombreFinal = nombres[0];
                puntajeFinal = puntosTotal[0];
                break;
            } else {
                nombreFinal = nombres[1];
                puntajeFinal = puntosTotal[1];
                break;
            }
        }

        ///Asigna mayor puntaje
        if(puntosTotal[0] > puntosTotal[1]){
            nombreFinal = nombres[0];
            puntajeFinal = puntosTotal[0];
        }else {
            nombreFinal = nombres[1];
            puntajeFinal = puntosTotal[1];
        }
        if(puntosTotal[0] >= 100 || puntosTotal[1] >= 100){
            break;
        }
    }

    system("cls");
    cout << "-----------------------------------------------------------" << endl;
    cout << "\t\t\tJUEGO TERMINADO" << endl;
    cout << "-----------------------------------------------------------" << endl;
    cout << endl;
    cout << nombreFinal << " Ganaste!" << " Obtuviste " << puntajeFinal << " puntos" << endl;
    cout << "Ganaste en " << ronda << " rondas" << endl;
    cout << endl;
    if(puntajeFinal > maximoPuntaje){
        maximoNombre = nombreFinal;
        maximoPuntaje = puntajeFinal;
    }
    system("pause");
    return;
}

void cargarNombre(string &nombre) {
    cout << "--- INGRESA TU NOMBRE --- : " << endl;
    getline(cin, nombre);
    return;
}

void cargarNombre2jugadores(string nombres[]){
    cout << "--- INGRESEN SUS NOMBRES --- : " << endl;
    for(int i = 0; i < 2; i++){
        getline(cin, nombres[i]);
    }
    return;
}

void cargarRondas (int &rondasPredefinidas) {
    cout << "Desea jugar con rondas predefinidas?" << endl;
    cout << "1) SI" << "\n2) NO" << endl;
    cin >> rondasPredefinidas;
    if (rondasPredefinidas == 1) {
        cout << "Ingrese la cantidad de rondas que desea jugar" << endl;
        cin >> rondasPredefinidas;
        return;
    }
    rondasPredefinidas = -1;
    return;
}

/// Funcion para activar o desactivar el Modo Simulado
void modoSimuladoF(bool &modoSimulado) {
    system("cls");

    if(modoSimulado == false){
        modoSimulado = true;
    } else {
        modoSimulado = false;
    }
    return;
}

void highscore(string maximoNombre, int maximoPuntaje) {
    if(maximoPuntaje == 0){
        cout << "-----------------------* HIGHSCORE *-----------------------" << endl;
        cout << "\n\t\t NO SE JUGO NINGUNA PARTIDA\n" << endl;
        cout << "-----------------------------------------------------------" << endl;
        return;
    }
    cout << "-----------------------* HIGHSCORE *-----------------------" << endl;
    cout << "\n\t\t\t" << maximoNombre << " " << maximoPuntaje << "\n" << endl;
    cout << "-----------------------------------------------------------" << endl;
}

#endif // MODOS_H_INCLUDED
