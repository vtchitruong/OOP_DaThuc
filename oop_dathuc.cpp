#include <iostream>
using namespace std;

class Polynomial
{
private:
    int n; // bậc của đa thức
    double *a; // trỏ tới vùng nhớ chứa các hệ số của đa thức

public:
    Polynomial();
    Polynomial(int  n1);

    friend ostream& operator<< (ostream& os, const Polynomial &p);
    friend istream& operator>> (istream& is, Polynomial &p);

    double operator[](int i);
    Polynomial operator-();
    Polynomial operator+(const Polynomial &p2);
    Polynomial operator-(Polynomial p2);
    Polynomial operator*(const Polynomial &p2);
    
    double operator^(const double &x); // tính giá trị đa thức

};

//------------------------------------
Polynomial::Polynomial()
{
    this->n = 0;
    this->a = NULL;
}

Polynomial::Polynomial(int n1)
{
    this->n = n1;
    this->a = new double[n1 + 1];
}

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

//---------------------------
istream& operator>>(istream& is, Polynomial &p)
{
    cout << "Input the degree: ";
    cin >> p.n;

    p.a = new double[p.n + 1];

    cout << "Input the coefficients: ";
    for (int i = p.n; i >= 0; --i)
    {
        cout << "The " << i << " degree coefficient: ";
        is >> p.a[i];
    }

    return is;
}

//---------------------------------
ostream& operator<<(ostream& os, const Polynomial &p)
{
    os << "The coefficients: ";
    for (int i = p.n; i >= 0; --i)
    {
        os << p.a[i] << " ";
    }
    cout << endl;
    return os;
}

//----------------------
Polynomial Polynomial::operator-()
{
    Polynomial p;
    p.n = n;
    p.a = new double[n + 1];
    
    for (int i = 0; i <= n; ++i)
    {
        p.a[i] = a[i];
    }
    return p;
}

Polynomial Polynomial::operator-(Polynomial p2)
{
    return (*this + (-p2));
}

Polynomial Polynomial::operator+(const Polynomial &p2)
{
    Polynomial res;

    int d; // bậc của đa thức tổng
    d = n > p2.n ? n : p2.n;

    res.a = new double[d + 1];
    for (int i = 0; i <= n; ++i)
    {
        if (i <= n && i <= p2.n)
        {
            res.a[i] = a[i] + p2.a[i];
        }
        else
        {
            if (i <= n)
            {
                res.a[i] = a[i];
            }
            {
                res.a[i] = p2.a[i];
            }

        }
    }

    // trường hợp các đơn thức bậc cao cộng lại và bị triệt tiêu
    int i  = d;
    while (i > 0 && res.a[i] == 0.0)
        --i;
    res.n = i;
    return res;
}

// nhân 2 đa thức
Polynomial Polynomial::operator*(const Polynomial &p2)
{
    Polynomial res;

    int d;
    d = res.n = n + p2.n;

    res.a = new double[d + 1];
    
    // khởi tạo bậc cho các đơn thức
    for (int i = 0; i <= d; ++i)
    {
        res.a[i] = 0;
    }

    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= p2.n; ++j)
        {
            res.a[i + j] += a[i] * p2.a[j];
        }
    }

    return res;
}

// toán tử tính giá trị của đa thức
double Polynomial::operator^(const double &x)
{
    double res = 0.0;
    double t = 1.0;

    for (int i = 0; i <= n; ++i)
    {
        res += a[i] * t;
        t *= x;
    }

    return res;
}

int main()
{
    Polynomial p, q;

    cout << "Input polynomial P: ";
    cin >> p;

    cout << "Input polynomial Q: ";
    cin >> q;

    Polynomial PolySum;
    PolySum = p + q;
    cout << "The sum: " << PolySum;

    double x;
    cout << "Input x: ";
    cin >> x;

    double res1, res2;
    res1 = PolySum^x;
    res2 = f(PolySum, x);

    cout << "Calculate with operator ^: " << res1 << endl;
    cout << "Calculate with f fucntion: " << res2 << endl;


    return 0;
}