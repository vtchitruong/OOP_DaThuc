#include <iostream>
using namespace std;

class Polynomial
{
private:
    int n; // bậc của đa thức
    double *a; // trỏ tới vùng nhớ chứa các hệ số của đa thức

public:
    friend ostream& operator<< (ostream& os, const Polynomial &p);
    friend istream& operator>> (istream& is, Polynomial &p);

    double operator[](int i);
    Polynomial operator-();
    Polynomial operator+(const Polynomial &p2);
    Polynomial operator-(Polynomial p2);
    Polynomial operator*(const Polynomial &p2);

    double operator^(const double &x); // tính giá trị đa thức

};

double Polynomial::operator[](int i)
{
    if (i < 0)
        return double(n);
    else
        return a[i];
}



//------------------------
// Hàm tính giá trị của đa thức
double f(Polynomial p, double x)
{
    double res = 0.0;
    double t = 1.0;
    int n;

    n = int(p[-1]);

    for (int i = 0; i <=n; ++i)
    {
        res += p[i] * t;
        t *= x;
    }

    return res;
}

int main()
{
    
    return 0;
}