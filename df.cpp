#include <iostream>
#include <vector>
using namespace std;

int f(float x)
{
    if(x < 0)
    {
        return x*x + 1;
    }
    else
    {
        return -x + 1;
    }
}

int main() {
    int n;
	cout << "Введите размер массива" << endl;
	cin >> n;
	vector<float> arr(n);
	cout << "Введите значения массива через пробел" << endl;
	for(int i = 0; i < n; i++)
	{
	    cin >> arr[i];
	}
	float min, max;
	min = f(arr[0]);
	max = f(arr[0]);
    for(int i = 0; i < n; i++)
	{
	    float k = f(arr[i]);
	    if(k > max)
	    {
	        max = k;
	    }
	    else if(k < min)
	    {
	        min = k;
	    }
	}
	cout << (max + min) / 2;
}
