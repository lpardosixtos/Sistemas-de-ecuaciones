#include <iostream>
#include "casostriviales.h"

using namespace std;

//esto es algo nuevo

int main(){

    char tipo;
    cout << "De que tipo es tu matriz?\nD para diagonal, L para triangular inferior y U para triangular superior\n";
    cin >> tipo;
    cout << "¿Que dimension tiene tu matriz?\n";
    int sz;
    cin >> sz;
    cout << "Escribe los valores de b\n";
    double B[sz];
    double X[sz];
    for(int i=0; i<sz; i++) cin >> B[i];
    bool ind;
    if(tipo=='D'){
        cout << "Escribe los elementos de la diagonal\n";
        double D[sz];
        for(int i=0; i<sz; i++) cin >> D[i];
        ind=solveDiag(D, B, X, sz);
    }
    else{
        if(tipo=='L'){
            cout << "Escribe los valores renglon por renglon parando en la diagonal \n";
            double **L;
            L=new double* [sz];
            for(int i=0; i<sz; i++) L[i]=new double[sz];
            for(int i=0; i<sz; i++){
                for(int j=0; j<=i; j++) cin >> L[i][j];
            }
            ind=solveL(L, B, X, sz);
        }
        else{
            cout << "Escribe los valores renglon por renglon empezando en la diagonal \n";
            double** U;
            U=new double* [sz];
            for(int i=0; i<sz; i++) U[i]=new double[sz];
            for(int i=0; i<sz; i++){
                for(int j=i; j<sz; j++) cin >> U[i][j];
            }
            ind=solveU(U, B, X, sz);
        }
    }
    if(!ind) cout << "El sistema no tiene solucion unica\n";
    else{
        cout << "La solucion es:\n";
        cout << X[0];
        for(int i=1; i<sz; i++) cout << " " << X[i];
        cout << "\n";
    }

    return 0;
}
