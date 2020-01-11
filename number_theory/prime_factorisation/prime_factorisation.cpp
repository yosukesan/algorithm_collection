
#include <prime_factorisation.hpp>
#include <iostream>

set<int> prime (int n)
{
    set<int> p;
    for (int i=2; i*i<n; ++i)
    {
        while (n%i==0)
            p.insert(i), n /= i;
    }

    if (n != 1) p.insert(n);

    return p;
}
