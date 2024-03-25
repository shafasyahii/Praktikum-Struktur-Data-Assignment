#include <iostream>
using namespace std;

int main()
{
    // Masukkan Array oleh user
    int n, i, valor;
    cout << "Masukkan panjang array: ";
    cin >> n;
    int array[n];

    cout << "Masukkan " << n << " angka:\n";
    for (i = 0; i < n; i++)
    {
        cout << "Angka ke-" << (i + 1) << ": ";
        cin >> array[i];
    }

    // Menentukan nilai maksimum, minimum, dan lokasi
    int max = array[0];
    int min = array[0];
    int max_loc = 0;
    int min_loc = 0;
    for (i = 0; i < n; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
            max_loc = i;
        }
        if (array[i] < min)
        {
            min = array[i];
            min_loc = i;
        }
    }
    cout << "Nilai maksimum adalah " << max << " berada di index " << max_loc << endl;
    cout << "Nilai minimum adalah " << min << " berada di index " << min_loc << endl;

    // Menentukan nilai rata-rata
    int sum = 0;
    for (i = 0; i < n; i++)
    {
        sum += array[i];
    }
    double avg = (double)sum / n;
    cout << "Nilai rata-rata adalah " << avg << endl;

    return 0;
}