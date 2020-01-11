
#include <iostream>
#include <prime_factorisation.hpp>

using namespace std;

int main ()
{
    int n;
    cin >> n; 

    for (auto l: prime(n))
        cout << l << endl;
}
