#include <iostream>

#define infi 100000

using namespace std;

struct casilla {
    int iMenor;
    int iMayor;
};

int main() {
    // Variables
    int iRenglon;
    int iColumna;
    int iMat[30][30];
    casilla cArrRenglones[30];
    casilla cArrColumnas[30];

    // Pedir datos
    cout << "Numero de renglones: " << endl;
    cin >> iRenglon;
    cout << "Numero de columnas: " << endl;
    cin >> iColumna;

    // Leer matriz
    for(int i = 0; i < iRenglon; i++) {
        for(int j = 0; j < iColumna; j++) {
            cin >> iMat[i][j];
        }
    }
    int iMin, iMax;
    for(int i = 0; i<iRenglon; i++) {
        iMin = 100000000;
        iMax = -100000000;
        for(int j=0; j<iColumna; j++){
            
            if(iMat[i][j] < iMin) {
                iMin = iMat[i][j];
            }
            if(iMat[i][j] > iMax) {
                iMax = iMat[i][j];
            }
        }
        cArrRenglones[i].iMenor = iMin;
        cArrRenglones[i].iMayor = iMax;
    }

    for(int i = 0; i < iColumna; i++){
        iMax = 100000000;
        iMin = -100000000;

        for(int j = 0; j < iRenglon; j++){

            if (iMat[i][j] < iMin){
                iMin = iMat[i][j];
            }

              if (iMat[i][j] > iMax) {
                iMax = iMat[i][j];
            }
            cArrColumnas[i].iMenor = iMin;
            cArrRenglones[i].iMayor = iMax;
        }
    }

    for(int i = 0; i < iRenglon; i++) {
        for(int j = 0; i < iColumna; j++) {
            
        }
    }

    
    return 0;
}