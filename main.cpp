#include <iostream>
#include <iomanip>
using namespace  std;

int * * dimensionar(int filas, int col);
void imprimir( int  **pMatriz, int filas, int col );
int  hallaElMenor(int ** pM, int filas, int col);
int sumarLosElementosDeLaDiagonal(int **pM, int filas);
int  sumarPorEncimaDeLaDiagonal(int ** pM, int filas, int col);

int main()
{
    int *  *pMat=nullptr;

    srand(time(nullptr));
    pMat = dimensionar(8,8);
   //---- llenamos con datos aleatoris a la matriz
   for(int f=0; f<8; f++)
       for(int c=0; c<8;c++)
           pMat[f][c]= rand() % 99 +1;
   imprimir(pMat,8,8);
   int elmenor = hallaElMenor(pMat,8,8);
   cout << "\nEl dato mas chiquito de la matriz es: " << elmenor << "\n";
   int suma= sumarLosElementosDeLaDiagonal(pMat,8);
   cout << "\nLa suma de los elementos de la diagonal es: " << suma << "\n";
   int suma2 = sumarPorEncimaDeLaDiagonal(pMat, 8, 8);
   cout << "La suma de los elementos que estan por encima de la diagonal es:" << suma2;
   //-----eliminamos el espacio de memoria
   for(int f=0; f<8;f++)
       delete []pMat[f];
   delete []pMat;
   pMat=nullptr;
    return 0;
}

int  sumarPorEncimaDeLaDiagonal(int ** pM, int filas, int col)
{
    int suma=0;
    for(int f=0; f<filas-1; f++)
        for(int c = f+1; c<col;c++ )
            suma = suma +pM[f][c];
    return suma;
}

int sumarLosElementosDeLaDiagonal(int **pM, int filas)
{
  int suma=0;
  for(int f=0; f<filas; f++)
      suma = suma + pM[f][f];
  return suma;
}


int  hallaElMenor(int ** pM, int filas, int col)
{
    int menor = pM[0][0];
    for(int f=0; f<filas; f++)
        for(int c=0; c<col;c++)
            if(pM[f][c] <menor)
                menor = pM[f][c];
    return menor;
}


int * * dimensionar(int filas, int col)
{
  int* * p = new int*[filas];
  for(int f=0; f<filas;f++)
      p[f]= new int[col];
  return p;
}


void imprimir( int  **pMatriz, int filas, int col)
{
    for(int f=0; f<filas; f++)
    {
        for(int c=0; c<col; c++)
            cout << setw(5) << pMatriz[f][c];
        cout << "\n";
    }
}