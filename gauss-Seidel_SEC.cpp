#include <iostream>
using namespace std;

int main()
{
    const int n= 3;
    long double A[n][n], L[n][n], DU[n][n], D[n][n];
    long double b[n];
    long double x0[n], x1[n];
    long double aux[n], aux1[n], aux2[n], aux3[n], sum;
    bool seguir;

    A[0][0]= 4;
    A[0][1]= 1;
    A[0][2]= -1;
    A[1][0]= -1;
    A[1][1]= 3;
    A[1][2]= 1;
    A[2][0]= 2;
    A[2][1]= 2;
    A[2][2]= 5;  

    D[0][0]= 4;
    D[0][1]= 0;
    D[0][2]= 0;
    D[1][0]= 0;
    D[1][1]= 3;
    D[1][2]= 0;
    D[2][0]= 0;
    D[2][1]= 0;
    D[2][2]= 5;  

    L[0][0]= 0;
    L[0][1]= 0;
    L[0][2]= 0;
    L[1][0]= -1;
    L[1][1]= 0;
    L[1][2]= 0;
    L[2][0]= 2;
    L[2][1]= 2;
    L[2][2]= 0;  

    DU[0][0]= 4;
    DU[0][1]= 1;
    DU[0][2]= -1;
    DU[1][0]= 0;
    DU[1][1]= 3;
    DU[1][2]= 1;
    DU[2][0]= 0;
    DU[2][1]= 0;
    DU[2][2]= 5;  

    b[0]= 12;
    b[1]= -8;
    b[2]= 14;

    x0[0]= 0;
    x0[1]= 0;
    x0[2]= 0;

    x1[0]= 0;
    x1[1]= 0;
    x1[2]= 0;

    for(int it=0; it<10; it++)
    {
        for(int k=0; k<n; k++)
        {
            //aux1= DU*x0
            for(int i=0; i<n; i++)
            {
                sum= 0;
                for(int j=0; j<n; j++)
                    sum+= DU[i][j]*x0[j];
                aux1[i]= sum;
            }

            //aux2= L*x1
            for(int i=0; i<n; i++)
            {
                sum= 0;
                for(int j=0; j<n; j++)
                    sum+= L[i][j]*x1[j];
                aux2[i]= sum;
            }

            //aux3= b - aux2 - aux1
            for(int i=0; i<n; i++)
                aux3[i]= b[i] - aux2[i] - aux1[i];

            //aux= D^-1*(aux3)
            for(int i=0; i<n; i++)
                aux[i]= (1.0/A[i][i])*aux3[i];            

            //cout << endl << "x0[" << k << "]= " << x0[k] << endl;
            //cout << endl << "aux[" << k << "]= " << aux[k] << endl;
            x1[k]= x0[k] + aux[k];
        }
            
        cout << endl;
        for(int i=0; i<n; i++)
        {
            x0[i]= x1[i];
           cout << x1[i] << " ";
        }
        cout << endl;
    }
}