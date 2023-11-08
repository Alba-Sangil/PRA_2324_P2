#include <iostream>
#include<algorithm>
using namespace std;

int mochila(int b[], int p[], int N, int M,int x[N]){
	int** matriz = new int*[N];
	for(int i = 0; i < N; i++){
		x[i] = 0;
	}
	for(int i=0; i<=N; i++){
		matriz[i] = new int[M + 1];
		for(int j = 0; j<=M; j++){
			matriz[i][j] = 0;
		}
	}
	for(int i=0; i<=N; i++){
		for(int j = 0; j<=M; j++){
			if( i == 0){
				matriz[i][j] = 0;
			}
			else if(j == 0){
				matriz[i][j] = 0;
			}
			else if (i == 1 && p[i] < j){
				matriz[i][j] = b[i];
				x[i] = 1;
			}
					
			else if( p[i] > j){
			 	matriz[i][j] = matriz[i - 1][j];
			} 
		   
			else {
				if (max(matriz[i - 1][j], matriz[i - 1][j - p[i]] + b[i])==matriz[i - 1][j - p[i]] + b[i]){
					x[i] = 1;
				}
				matriz[i][j] = max(matriz[i - 1][j], matriz[i - 1][j - p[i]] + b[i]);
	
			} 
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << matriz[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
int main(){
    int b[] = { 38, 40, 24 };
    int p[] = { 9, 6, 5 };
    int M = 15;
    int N = 3;
    int x[N]
    int valor_mochila = mochila(p, b,N , M,x);
    cout << "El valor de la mochila es: " << valor_mochila <<endl;
    return 0;
}
