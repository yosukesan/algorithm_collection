
#include <iostream>
#include <vector>
#include <numeric>
#include <complex>

using namespace std; 

using Matrix = vector<vector<double>>;
using Vector = vector<double>;

void printv(const Vector& v){
    cout << "\nvector = " << endl;
    for (size_t i=0; i<v.size(); i++)
        cout << v[i] << endl;
}

void printm(const Matrix& m){
    cout << "\nmatrix = " << endl;
    for (size_t i=0; i<m.size(); i++){
        for (size_t j=0; j<m[0].size(); j++){
            cout << " " << m[i][j];
        }
        cout << endl;
    }
}

Vector operator*(const Matrix& m, const Vector& v)
{
    size_t n(m.size());
    Vector ans(n); 
    
    for (size_t i=0; i<n; ++i) 
        for (size_t j=0; j<n; ++j) 
            ans[i] += m[i][j] * v[j];

    return ans;
}  

Vector operator-(const Vector& v1, const Vector& v2)
{
    size_t n(v1.size());
    Vector ans(n); 

    for (size_t i=0; i<n; ++i) 
        ans[i] =  v1[i] - v2[i];

    return ans;
}

Vector operator+(const Vector& v1, const Vector&& v2)
{
    size_t n(v1.size());
    Vector ans(n); 

    for (size_t i=0; i<n; ++i) 
        ans[i] =  v1[i] + v2[i];

    return ans;
}

double operator*(const Vector& v1, const Vector& v2)
{
    return inner_product(v1.begin(), v1.end(), v2.begin(), 0.0);
}

Vector operator*(const double& a, Vector v)
{
    size_t n(v.size());
    
    for (size_t i=0; i<n; ++i) 
        v[i] = a*v[i];

    return v;
}

template<typename T>
T norm(Vector& v)
{
    return static_cast<T>(sqrt(v * v));
}

bool operator==(const Vector& v1, const Vector& v2){
    constexpr double EPS(10e-6);

    if (v1.size() != v2.size())
        return false;

    Vector v(v1- v2);
    if (norm<double>(v) > EPS)
        return false;

    return true; 
}

template <typename T>
void CG(const Matrix& A, Vector& x, const Vector& b)
{
    size_t n (b.size());
    constexpr T EPS(10e-6);

    Vector r(n);
    Vector p(n);
    T alpha, beta;

    r = b - A*x;
    p = r;

    alpha = 1.0;
    beta = 0.0; 

    for (size_t i=0; i<n; ++i)
    {
        alpha = (r*r)*(1.0/(p*(A*p))); 
        x = x + (alpha * p);         
        r = r - (alpha * (A*p));

        if (norm<double>(r)<EPS)
            return;

        beta = (r*r)*(1.0/(p*p));
        p = r + beta * p;
        printv(p);
    }
}

int main ()
{
    size_t n;

    cin >> n;

    Matrix A(n);
    Vector b(n);
    Vector x(n);

    double a;
    for (size_t i=0; i<n; ++i)
        for (size_t j=0; j<n; ++j)
            cin >> a, A[i].emplace_back(a);

    for (size_t i=0; i<n; ++i)
        cin >> b[i];

    x[0]=2, x[1] = 1;

    printm(A);
    printv(b);

    CG<double>(A, x, b);

    if (A*x == b)
        cout << "OK" << endl;

    return 0;
}
