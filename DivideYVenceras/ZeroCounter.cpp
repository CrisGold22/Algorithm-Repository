#include <iostream>
#include <cmath>

using namespace std;

void findNumber(int *array, int left, int right, int &contador){
    int mid;

    if(left >=right){
        return;
    }

    mid = (left + right-1)/2;

    if(array[mid] == 1){
        contador++;
    }

    //recursion para dividir el algoritmo original en en dos mitades
    findNumber(array, left, mid, contador);
    findNumber(array, mid + 1, right, contador);
}

int main(){
    // problema de cuentaceros y cuentaunos
    int array[7] = {1, 1, 1, 1, 1, 0, 0};
    int cantidad = 7;
    int contador = 0;
    findNumber(array, 0, cantidad, contador);
    cout<<contador<<endl;
    return 0;
}