#include <ctime>
#include <iostream>
#include <cmath>

void DoArray(int* array, unsigned len);
void PrintArray(int array[], unsigned len);
void DoVArray(float* array, unsigned len);
void PrintVArray(float array[], unsigned len);
float ProChet(float array[], unsigned len);
int Sum(int array[], unsigned len);
void Men(float array[], unsigned len);
float Poisk(float array[], unsigned len, float x);
void Sort(float array[], unsigned len);
bool chet(float num);
void SortChet(float array[], unsigned len);
void QuickSort(int array[], unsigned len);
int BinPoisk(int array[], unsigned len, int x);

using namespace std;
int main() {
    srand(time(0));
    unsigned n;
    cin >> n;

    float* array = new float[n];
    //int* array = new int[n];

    //1
    /*DoArray(array, n);
    PrintArray(array, n);
    delete[] array;
    */
    //2
    /*DoVArray(array, n);
    PrintVArray(array, n);
    delete[] array;
    */
    //3
    /*DoVArray(array, n);
    PrintVArray(array, n);
    cout << ProChet(array, n) << endl;
    delete[] array;
    */
    //4
    /*DoArray(array, n);
    PrintArray(array, n);
    int S = Sum(array, n);
    if (S == 0)
        cout << "no sum" << endl;
    else
        cout << S << endl;
    delete[] array;
    */
    //5
    /*DoVArray(array, n);
    PrintVArray(array, n);
    Men(array, n);
    PrintVArray(array, n);
    delete[] array;
    */
    //6
    /*DoVArray(array, n);
    PrintVArray(array, n);
    float x, p;
    cout << "Vvedite X: ";
    cin >> x;
    p = Poisk(array, n, x);
    if (p != -1)
        cout << "Nomer: " << p << endl;
    else
        cout << "No element" << endl;
    delete[] array;
    */
    //7
    /*DoVArray(array, n);
    PrintVArray(array, n);
    Sort(array, n);
    PrintVArray(array, n);
    delete[] array;
    */
    //8
    /*DoVArray(array, n);
    PrintVArray(array, n);
    SortChet(array, n);
    PrintVArray(array, n);
    delete[] array;
    */
    //9
    /*DoArray(array, n);
    PrintArray(array, n);
    QuickSort(array, n);
    PrintArray(array, n);
    delete[] array;
    */
    //10
    /*DoArray(array, n);
    QuickSort(array, n);
    PrintArray(array, n);
    int x,p;
    cout << "Vvedite X: ";
    cin >> x;
    p = BinPoisk(array, n, x);
    if (p != -1)
        cout << "Nomer " << p << endl;
    else
        cout << "No element" << endl;
    */

}

void DoArray(int *array, unsigned len) {
    for (unsigned i = 0; i < len; i++)
        array[i] = rand() - RAND_MAX / 2;
}
void PrintArray(int array[], unsigned len) {
    for (unsigned i = 0; i < len; i++)
        cout << i << ". " << array[i] << endl;
}
void DoVArray(float *array, unsigned len) {
    for (unsigned i = 0; i < len; i++)
        array[i] = rand() - RAND_MAX / 2 + ((float)rand() / (float)rand());
}
void PrintVArray(float array[], unsigned len) {
    for (unsigned i = 0; i < len; i++)
        cout << i << ". " << array[i] << endl;
}
float ProChet(float array[], unsigned len) {
    float P = 1;
    for (unsigned i = 0; i < len; i += 2)
        P *= array[i];
    return P;
}
int Sum(int array[], unsigned len) {
    int n1 = -1;
    int n2 = -1;
    for (unsigned i = 0; i < len; i++)
        if (array[i] < 0)
            if (n1 == -1)
                n1 = i;
            else
                n2 = i;

    if (n1 == -1 || n2 == -1) {
        return 0;
    }
    int S = 0;
    for (unsigned i = n1 + 1; i < n2; i++)
        S += array[i];
    return S;
}
void Men(float array[], unsigned len) {
    for (unsigned i = 0; i < len; i++)
        if (array[i] > 0)
            array[i] = -rand() - ((float)rand() / (float)rand());
}
float Poisk(float array[], unsigned len, float x) {
    for (unsigned i = 0; i < len; i++) {
        float eps = 0.1;
        if (fabs(array[i] - x) <= eps)
            return i;
    }
    return -1;
}
void Sort(float array[], unsigned len) {
    for (unsigned i = 0; i < len; i++) {
        int n1 = i;
        for (unsigned j = i + 1; j < len; j++) {
            if (array[j] < array[n1]) {
                n1 = j;
            }
        }
        if (n1 != i) {
            float buf = array[i];
            array[i] = array[n1];
            array[n1] = buf;
        }
    }
}
bool chet(float num) {
    return (int)num % 2 == 0;
}
void SortChet(float array[], unsigned len) {
    for (unsigned i = 0; i < len; i++) {
        if (chet(array[i])) continue;
        for (unsigned j = i + 1; j < len; j++) {
            if (chet(array[j])) {
                float buf = array[i];
                array[i] = array[j];
                array[j] = buf;
            }
        }
    }
}
void QuickSort(int array[], unsigned len) {
    int i = 0, j = len - 1;
    int buf, p;
    p = array[len >> 1];

    do {
        while (array[i] < p)
            i++;
        while (array[j] > p)
            j--;

        if (i <= j) {
            buf = array[i];
            array[i] = array[j];
            array[j] = buf;
            i++;
            j--;
        }
    } while (i <= j);

    if (j > 0)
        QuickSort(array, j + 1);
    if (len > i)
        QuickSort(&array[i], len - i);
}
int BinPoisk(int array[], unsigned len, int x) {
    int n1 = 0, n2 = len, mid;
    while (n1 <= n2) {
        mid = (n1 + n2) / 2;
        if (array[mid] == x)
            return mid;
        if (array[mid] > x)
            n2 = mid - 1;
        if (array[mid] < x)
            n1 = mid + 1;
    }
    return -1;
}