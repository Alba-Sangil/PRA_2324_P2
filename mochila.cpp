#include <iostream>
#include <climits>
using namespace std;

int mochila(int v[], int w[], int n, int W)
{
    if (W < 0) {
        return INT_MIN;
    }
 
    if (n < 0 || W == 0) {
        return 0;
    }
 
    int include = v[n] + mochila(v, w, n - 1, W - w[n]);
 
    int exclude = mochila(v, w, n - 1, W);
 
    return max(include, exclude);
}
 
int main(){
    int v[] = { 38, 40, 24 };
    int w[] = { 9, 6, 5 };
 
    int W = 15;
 
    int n = sizeof(v) / sizeof(v[0]);
 
    cout << "El valor de la mochila es: " << mochila(v, w, n - 1, W)<<endl;
 
    return 0;
}
