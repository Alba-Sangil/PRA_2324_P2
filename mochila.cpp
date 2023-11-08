#include <iostream>
#include<algorithm>
using namespace std;


int mochila(int N, int *p ,int *b , int M){
	int** matrix = new int*[N];	

	for(int i=0; i<=N; i++){
		matrix[i] = new int[M + 1];
		for(int j = 0; j<=M; j++){
			matrix[i][j] = 0;
		}
	}

	for(int i=0; i<=N; i++){
                 for(int j = 0; j<=M; j++){
			if( i == 0){
				matrix[i][j] = 0;
			}
			else if(j == 0){
				matrix[i][j] = 0;
			}
			else if (i == 1 && p[i] < j){
				matrix[i][j] = b[i];
			}
					
			else if( p[i] > j){
			 	matrix[i][j] = matrix[i - 1][j];
			} 
		   
			else {
				matrix[i][j] = std::max(matrix[i - 1][j], matrix[i - 1][j - p[i]] + b[i]);
	
			} 
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

	return matrix[N-1][M];
}
int main(){
    int b[4] = {0, 38, 40, 24 };
    int p[4] = {0, 9, 6, 5 };
    int M = 15;
    int N = 3;
    int valor_mochila = mochila(N, p, b, M);
    cout << "El valor de la mochila es: " << valor_mochila <<endl;
    return 0;
}
