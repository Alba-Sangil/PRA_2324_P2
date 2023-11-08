#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Estructura para representar un objeto con peso y beneficio
struct Objeto {
    int peso;
    int beneficio;
};

// Función para resolver el problema de la mochila
int mochila(int num_objetos, vector<Objeto> objetos, int peso_maximo) {
    vector<vector<int>> dp(num_objetos + 1, vector<int>(peso_maximo + 1, 0));

    for (int i = 1; i <= num_objetos; i++) {
        for (int j = 0; j <= peso_maximo; j++) {
            if (objetos[i - 1].peso <= j) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - objetos[i - 1].peso] + objetos[i - 1].beneficio);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[num_objetos][peso_maximo];
}

int main() {
    int num_objetos = 3;
    vector<Objeto> objetos = {{9, 38}, {6, 40}, {5, 24}};
    int peso_maximo = 15;

    int max_beneficio = mochila(num_objetos, objetos, peso_maximo);
    cout << "Máximo beneficio: " << max_beneficio << endl;

    return 0;
}

