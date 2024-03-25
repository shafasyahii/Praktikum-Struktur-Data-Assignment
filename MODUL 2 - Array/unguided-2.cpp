#include <iostream>
using namespace std;

// PROGRAM INPUT ARRAY 3 DIMENSI
int main()
{
    // Inputkan jumlah dimensi pertama dan kedua
    int dim1, dim2, dim3;
    cout << "Masukkan jumlah elemen dimensi pertama: ";
    cin >> dim1;
    cout << "Masukkan jumlah elemen dimensi kedua: ";
    cin >> dim2;
    cout << "Masukkan jumlah elemen dimensi ketiga: ";
    cin >> dim3;

    // Deklarasi array dengan ukuran yang diinputkan
    int arr[dim1][dim2][dim3];

    // Input elemen
    for (int x = 0; x < dim1; x++)
    {
        for (int y = 0; y < dim2; y++)
        {
            for (int z = 0; z < dim3; z++)
            {
                cout << "Input Array[" << x << "][" << y << "][" << z << "] = ";
                cin >> arr[x][y][z];
            }
        }
        cout << endl;
    }

    // Output Array
    for (int x = 0; x < dim1; x++)
    {
        for (int y = 0; y < dim2; y++)
        {
            for (int z = 0; z < dim3; z++)
            {
                cout << "Data Array[" << x << "][" << y << "][" << z << "] = " << arr[x][y][z] << endl;
            }
        }
    }
    cout << endl;

    // Tampilan array
    for (int x = 0; x < dim1; x++)
    {
        for (int y = 0; y < dim2; y++)
        {
            for (int z = 0; z < dim3; z++)
            {
                cout << arr[x][y][z] << ends;
            }
            cout << endl;
        }
        cout << endl;
    }
}