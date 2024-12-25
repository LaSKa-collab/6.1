#include <iostream>  
using namespace std;

int main()
{
    setlocale(0, "");
    int n, k, p;
    float** arr;
    float* vector;
    float* answervector;
    cout << "Введите количество строк матрицы" << endl;
    cin >> n;
    cout << "Введите количество столбцов матрицы" << endl;
    cin >> k;
    try
    {
        arr = new float* [n];
        for (float** i = arr; i < arr + n; ++i)
        {
            *i = new float[k];
            cout << "Введите элементы " << i - arr + 1 << " строки через пробел" << endl;
            for (float* j = *i; j < *i + k; ++j)
            {
                cin >> *j;
            }
        }
        cout << "Введите размер вектора" << endl;
        cin >> p;
        vector = new float[p];
        cout << "Введите элементы вектора через пробел" << endl;
        for (float* i = vector; i < vector + p; ++i)
        {
            cin >> *i;
        }
        answervector = new float[n];
        for (float* i = answervector; i < answervector + n; i++)
        {
            *i = 0;
            float** t = arr;
            for (float* j = *t; j < *t + k; j++)
            {
                float* r = vector;
                *i = *i + *j * *r;
                r++;
            }
        }

        for (int i = 0; i < n; ++i)
        {
            cout << answervector[i] << " ";
        }
    }
    catch (...)
    {
        cout << "Ошибка выполнения. Попробуйте перезапустить приложение и изменить входные данные" << endl;
        return 0;
    }
    delete[] arr;
    delete[] vector;
    delete[] answervector;
}