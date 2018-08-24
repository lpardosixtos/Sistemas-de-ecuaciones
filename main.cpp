#include <iostream>
#include <fstream>
#include "casostriviales.h"

using namespace std;

int main(){

    int sz;
    cout << "Ingrese el numero del caso a evaluar (4, 100, 500)" <<"\n";
    string casesN;
    cin >> casesN;
    string fileNames="TAREA2_MATRICES//DIAG_MAT";
    fileNames.append(casesN);
    fileNames.append(".txt");
    ifstream in_file;
    in_file.open(fileNames);
    in_file >> sz;
    in_file >> sz;
    double A[sz];
    for(int i=0; i<sz; i++) in_file >> A[i];
    fileNames[22]='V';
    fileNames[23]='E';
    fileNames[24]='C';
    in_file.close();
    in_file.clear();
    in_file.open(fileNames);
    
    double B[sz];
    in_file >> sz;
    for(int i=0; i<sz; i++) in_file>>B[i]; 
    double X[sz];
    solveDiag(A, B, X, sz);
    cout << X[0] << " ";
    for(int i=1; i<sz; i++) cout << " " << X[i];
    cout << "\n";
    return 0;
}
