#include <iostream>
#include <math.h>

using namespace std;

bool solveDiag(double* A, double* B, double*X, int sz){
    for(int i=0; i<sz; i++){
        if(A[i]==0) return false;
        X[i]=B[i]/A[i];
    }
    return true;
}

bool solveL(double** L, double* B, double* X, int sz){
    if(L[0][0]==0)return false;
    X[0]=B[0]/L[0][0];
    for(int i=1; i<sz; i++){
        if(L[i]==0) return false;
        X[i]=B[i];
        for(int j=0; j<i; j++){
            double aux=L[i][j]*X[j];
            X[i]-=aux;
        }
        X[i]/=L[i][i];
    }
    return true;
}

bool solveU(double** U, double* B, double* X, int sz){
    sz--;
    if(U[sz][sz]==0) return false;
    X[sz]=B[sz]/U[sz][sz];
    for(int i=sz-1; i>=0; i--){
        if(U[i]==0) return false;
        X[i]=B[i];
        double aux=0;
        for(int j=sz; j>i; j--){
            aux+=U[i][j]*X[j];
        }
        X[i]-=aux;
        X[i]/=U[i][i];
    }
    return true;
}


