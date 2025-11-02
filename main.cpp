#include <iostream>
#include <string>
using namespace std;

float pedirDatoPositivo(string texto) {
    float valor;
    do {
        cout << texto;
        cin >> valor;
        if (valor < 0) {
            cout << "El valor no puede ser negativo. Intente nuevamente." << endl;
        }
    } while (valor < 0);
    return valor;
}

float calcularTotal(float distancias[], float precios[], int cantidadViajes) {
    float total = 0;
    for (int i = 0; i < cantidadViajes; i++) {
        total += distancias[i] * precios[i];
    }
    return total;
}

float promedioDistancia(float distancias[], int cantidadViajes) {
    float suma = 0;
    for (int i = 0; i < cantidadViajes; i++) {
        suma += distancias[i];
    }
    if (cantidadViajes > 0) {
        return suma / cantidadViajes;
    } else {
        return 0;
    }
}

int main() {
    int limiteConductores = 10;
    int limiteViajes = 10;
    int numConductores;

    cout << "Ingrese la cantidad de conductores (maximo " << limiteConductores << "): ";
    cin >> numConductores;

    while (numConductores <= 0 || numConductores > limiteConductores) {
        cout << "Error: cantidad no valida. Intente nuevamente: ";
        cin >> numConductores;
    }

    string nombres[10];
    float totales[10];
    float promedios[10];
    float mayorTotal = 0;
    string mejorConductor;

    for (int i = 0; i < numConductores; i++) {
        cout << "=== Conductor " << i + 1 << " ===" << endl;
        cout << "Nombre: ";
        cin >> nombres[i];

        int numViajes;
        cout << "Ingrese el numero de viajes (maximo " << limiteViajes << "): ";
        cin >> numViajes;

        while (numViajes <= 0 || numViajes > limiteViajes) {
            cout << "Cantidad no valida. Intente nuevamente: ";
            cin >> numViajes;
        }

        float distancias[10];
        float precios[10];

        for (int j = 0; j < numViajes; j++) {
            cout << "--- Viaje " << j + 1 << " ---" << endl;
            distancias[j] = pedirDatoPositivo("Distancia (km): ");
            precios[j] = pedirDatoPositivo("Costo por km: ");
        }

        totales[i] = calcularTotal(distancias, precios, numViajes);
        promedios[i] = promedioDistancia(distancias, numViajes);

        if (totales[i] > mayorTotal) {
            mayorTotal = totales[i];
            mejorConductor = nombres[i];
        }
    }

    cout << "====================================" << endl;
    cout << "      RESULTADOS FINALES" << endl;
    cout << "====================================" << endl;

    for (int i = 0; i < numConductores; i++) {
        cout << "Conductor: " << nombres[i] << endl;
        cout << "Total ganado: $" << totales[i] << endl;
        cout << "Promedio de distancia: " << promedios[i] << " km" << endl;
    }

    cout << "====================================" << endl;
    cout << "El conductor con mayor ingreso fue: " << mejorConductor << endl;
    cout << "Total ganado: $" << mayorTotal << endl;

    return 0;
}