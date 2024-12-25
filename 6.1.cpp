#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

class Figure
{
    float square()
    {

    }
    float perimeter()
    {

    }
    void type()
    {
    }
    void Plot()
    {
    }
};

class Rectangle : Figure
{
public:
    float a, b;

    Rectangle(float a_p, float b_p)
    {
        a = a_p;
        b = b_p;
    }
    float square(float a, float b)
    {
        return a * b;
    }
    float perimeter(float a, float b)
    {
        return 2 * a + 2 * b;
    }
    string typep()
    {
        float tip;
        tip = 1;
        vector<float> type = { tip, a, b };
        string str = "Rectangle (" + to_string(a) + ", " + to_string(b) + ")";
        return str;
    }
    void Plot()
    {
        for (int i = 0; i <= a; i++)
        {
            for (int j = 0; j <= b; j++)
            {
                cout << "*";
            }
            cout << endl;
        }
    }
};

class Circle : Figure
{
public:
    float r;
    Circle(float r_p) 
    {
        r = r_p;
    }
    float square(float r)
    {
        return r * r * 3.14;
    }
    float perimeter(float r)
    {
        return 2 * 3.14 * r;
    }
    string typep()
    {
        float tip;
        tip = 2;
        vector<float> type = { tip, r };
        string str = "Circle (" + to_string(r) + ")";
        return str;
    }
    void Plot()
    {
        for (int i = 0; i <= 2 * r; i++)
        {
            for (int j = 0; j <= 2 * r; j++)
            {
                if (pow(i + r, 2) + pow(j - r, 2) <= r * r)
                {
                    cout << "*";
                }
                else
                {
                    cout << " ";
                }
            }
            cout << endl;
        }
    }
};
class Triangle : Figure
{
public:
    float a, b, c;
    Triangle(float a_p, float b_p, float c_p)
    {
        a = a_p;
        b = b_p;
        c = c_p;
    }
    float square(float a, float b, float c)
    {
        float p = (a + b + c) / 2;
        return sqrt(p*(p-a)*(p-b)*(p-c));
    }
    float perimeter(float a, float b, float c)
    {
        return a + b + c;
    }
    string typep()
    {

        float tip;
        tip = 3;
        vector<float> type = { tip, a, b, c };
        string str = "Triangle (" + to_string(a) + ", " + to_string(b) + ", " + to_string(c) + ")";
        return str;
    }
    void Plot()
    {
        int k, c_p;
        int osn = a;
        int h = b;
        if (c < osn)
        {
            k = c_p;
            c_p = osn;
            osn = k;
        }
        else if (c < h)
        {
            k = c_p;
            c_p = h;
            h = k;
        }
        else if (osn < h)
        {
            k = osn;
            osn = h;
            h = k;
        }
        float f = osn / h;
        for(int i = 0; i <= h; i++)
        {
            int g = 0;
            for(int j = 0; j <= i; j++)
            {
                g = g + f;
            }
            string s;
            for(int j = 0; j <= g; j++)
            {
                s = s + '*';
            }
            cout << s << endl;
        }
    }
};

int main()
{
    setlocale(0, "");
    Rectangle rect{2, 3};
    Circle circ{ 10 };
    Triangle tri{ 3, 4, 4 };
    cout << rect.square(2, 3) << " " << rect.perimeter(2, 3) << endl;
    rect.typep();
    rect.Plot();
    cout << circ.square(4) << " " << circ.perimeter(4) << endl;
    circ.typep();
    circ.Plot();
    cout << tri.square(3, 4, 5) << " " << tri.perimeter(1, 2, 2) << endl;
    tri.typep();
    tri.Plot();
}