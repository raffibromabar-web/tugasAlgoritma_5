#include <iostream>
using namespace std;

int arr[20], B[20];

int n;

void input()
{
    while (true)
    {
        cout << "Masukkan Panjang element array : ";
        cin >> n;

        if (n <= 20)
        {
            break;
        }
        else
        {
            cout << "\nMaksimal panjang array adalah 20";
        }
    }
    cout << "\n---------------------------" << endl;
    cout << "\nInputkan Isi element array" << endl;
    cout << "\n---------------------------" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << "Array index ke- " << i << " : ";
        cin >> arr[i];
    }
}

void mergeSort(int low, int high)
{
    if (low >= high)
    {
        return; 
    }

    int mid = (low + high) / 2;

    mergeSort(low, mid);
    mergeSort(mid + 1, high);

    int i = low; 
    int j = mid + 1;
    int k = low;

    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j])
        {
            B[k] = arr[i];
            i++;
        }
        else
        {
            B[k] = arr[j];
            j++;
        }
        k++;
    }

    while (j <= high) // step 4.e
    {
        B[k] = arr[j]; // step 4.e.i
        j++;           // step 4.e.ii
        k = k + 1;     // step 4.e.iii
    }

     while (i <= mid) // step 4.f
    {
        B[k] = arr[i]; // step 4.f.i
        i++;           // step 4.f.ii
        k++;           // step 4.f.iii
    }

}