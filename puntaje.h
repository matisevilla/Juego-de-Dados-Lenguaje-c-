#ifndef PUNTAJE_H_INCLUDED
#define PUNTAJE_H_INCLUDED

/// CAMBIAR EL INT DE LA FUNCION "tirarDados" A VOID PORQUE NO RETORNA NADA?
int tirarDados(int dados[], bool modoSimulado);
void mostrarDados(int dados[]);
void acumularDados(int dados[], int &puntosLanzamiento);
void maxPuntajeRondaF(int &maxPuntajeRonda, int puntosLanzamiento);
void maxPuntajeRonda2Jugadores(int &maxPuntajeRonda, int puntosLanzamiento, int maxPuntajeLanzamiento[], int lanzamiento, int i);
bool sextetoF(int dados[], int &puntosLanzamiento);
bool esEscalera(int dados[]);
void dibujarDados(int dados[]);

int tirarDados(int dados[], bool modoSimulado){
    for (int i = 0; i < 6 ; i++){
        /// if para cargar el vector de 6 de manera aleatoria o manual dependiendo de si la variable modoSimulado esta en true o false
        if (modoSimulado) {
            rlutil::locate((i * 10) + 1, 10);
            cin >> dados[i];
        } else {
            dados[i] = (rand() % 6) + 1;
        }
    }
    rlutil::locate(1, 1);
}

void mostrarDados(int dados[]){
    for (int i = 0; i < 6; i++) {
        cout << dados[i];
        cout << "\t";
    }
    cout << endl;
}

void acumularDados(int dados[], int &puntosLanzamiento){
    puntosLanzamiento = 0;
    for(int i = 0; i < 6; i++){
        puntosLanzamiento += dados[i];
    }
}

void maxPuntajeRondaF(int &maxPuntajeRonda, int puntosLanzamiento){
    if(puntosLanzamiento > maxPuntajeRonda){
        maxPuntajeRonda = puntosLanzamiento;
    }
}
void maxPuntajeRonda2Jugadores(int &maxPuntajeRonda, int puntosLanzamiento, int maxPuntajeLanzamiento[], int lanzamiento, int i){
    if(puntosLanzamiento > maxPuntajeRonda){
        maxPuntajeRonda = puntosLanzamiento;
        maxPuntajeLanzamiento[i] = lanzamiento;
    }
}
bool esEscalera(int dados[]){
    int contador[6]{};

    for (int x = 0; x < 6; x++) {
        for (int i = 0; i < 6; i++) {
            if (x + 1 == dados[i]) {
                contador[x]++;
            }
        }
    }
    for (int x = 0; x < 6; x++) {
        if (contador[x] != 1) {
            return false;
        }
    }
    return true;
}

bool sextetoF(int dados[], int &puntosLanzamiento){
    int cont = 0;

    for(int m = 0; m < 6 ;m++){
        cont = 0;
        for(int i = 0; i < 6; i++){
            if(dados[i] == m + 1) {
                cont++;
            }
        }
        if(cont == 6){
            puntosLanzamiento = dados[1] * 10;
            return true;
        }
    }
    return false;
}

void dibujarDados(int dados[]){
    for (int i = 0; i < 6; i++){
        int posX = (i * 10) + 3;
        int posY = 9;
        for (int x = posX; x < posX + 7; x++) {
            for (int y = posY; y < posY + 3; y++) {
                rlutil::locate(x, y);
                cout << (char) 219;
            }
        }

        rlutil::setBackgroundColor(rlutil::BLACK);
        rlutil::setColor(rlutil::WHITE);
        switch (dados[i]) {
            case 1:
                rlutil::locate(posX + 3, posY + 1);
                cout << (char) 254;
                break;
            case 2:
                rlutil::locate(posX + 1, posY);
                cout << (char) 220;
                rlutil::locate(posX + 5, posY + 2);
                cout << (char) 223;
                break;
            case 3:
                rlutil::locate(posX + 3, posY + 1);
                cout << (char) 254;
                rlutil::locate(posX + 1, posY);
                cout << (char) 220;
                rlutil::locate(posX + 5, posY + 2);
                cout << (char) 223;
                break;
            case 4:
                rlutil::locate(posX + 1, posY);
                cout << (char) 220;
                rlutil::locate(posX + 5, posY);
                cout << (char) 220;
                rlutil::locate(posX + 1, posY + 2);
                cout << (char) 223;
                rlutil::locate(posX + 5, posY + 2);
                cout << (char) 223;
                break;
            case 5:
                rlutil::locate(posX + 1, posY);
                cout << (char) 220;
                rlutil::locate(posX + 5, posY);
                cout << (char) 220;
                rlutil::locate(posX + 3, posY + 1);
                cout << (char) 254;
                rlutil::locate(posX + 1, posY + 2);
                cout << (char) 223;
                rlutil::locate(posX + 5, posY + 2);
                cout << (char) 223;
                break;
            case 6:
                rlutil::locate(posX + 1, posY);
                cout << (char) 220;
                rlutil::locate(posX + 3, posY);
                cout << (char) 220;
                rlutil::locate(posX + 5, posY);
                cout << (char) 220;
                rlutil::locate(posX + 1, posY + 2);
                cout << (char) 223;
                rlutil::locate(posX + 3, posY + 2);
                cout << (char) 223;
                rlutil::locate(posX + 5, posY + 2);
                cout << (char) 223;
                break;
        }
        rlutil::resetColor();
    }

}

#endif // PUNTAJE_H_INCLUDED
