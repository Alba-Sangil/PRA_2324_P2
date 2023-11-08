#include <iostream>
#include <algorithm>

using namespace std;

// Función para resolver el problema de la mochila
int mochila(int num_objetos, int pesos[], int beneficios[], int peso_maximo) {
    int dp[num_objetos + 1][peso_maximo + 1] = {0};
    int decision[num_objetos + 1][peso_maximo + 1] = {0};

    for (int i = 1; i <= num_objetos; i++) {
        for (int j = 0; j <= peso_maximo; j++) {
            if (pesos[i - 1] <= j) {
                int sin_objeto = dp[i - 1][j];
                int con_objeto = dp[i - 1][j - pesos[i - 1]] + beneficios[i - 1];

                if (con_objeto > sin_objeto) {
                    dp[i][j] = con_objeto;
                    decision[i][j] = 1;  // Tomar el objeto
                } else {
                    dp[i][j] = sin_objeto;
                    decision[i][j] = 0;  // Descartar el objeto
                }
            } else {
                dp[i][j] = dp[i - 1][j];
                decision[i][j] = 0;  // Descartar el objeto
            }
        }
    }

    // Reconstruir la solución (array de decisiones)
    int solucion[num_objetos];
    int i = num_objetos, j = peso_maximo;
    for (int k = num_objetos - 1; k >= 0; k--) {
        solucion[k] = decision[i][j];
        if (decision[i][j] == 1) {
            j -= pesos[i - 1];
        }
        i--;
    }

    // Imprimir la solución
    cout << "Solución: ";
    for (int k = 0; k < num_objetos; k++) {
        cout << solucion[k] << " ";
    }
    cout << endl;

    return dp[num_objetos][peso_maximo];
}

int main() {
    int num_objetos = 3;
    int pesos[] = {9, 6, 5};
    int beneficios[] = {38, 40, 24};
    int peso_maximo = 15;

    int max_beneficio = mochila(num_objetos, pesos, beneficios, peso_maximo);
    cout << "Máximo beneficio: " << max_beneficio << endl;

    return 0;
}

