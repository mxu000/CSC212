//Mingzhi Xu
#include <iostream>
#include <cassert>
#include "rec_fun.h"
using namespace std;

namespace recur_functions
{
    void binary_print(ostream& outs, unsigned int n)
    {
        if(n < 2)
        {
            outs << n;
            return;
        }
        else
        {
            binary_print(outs, n/2);
            outs << n % 2;
        }
    }
    void triangle(ostream& outs, unsigned int m, unsigned int n)
    {
        assert(m <= n);
        if(m == n)
        {
            for(unsigned int i = 0; i < m; i++) outs << "*";
            outs << endl;
            for(unsigned int i = 0; i < m; i++) outs << "*";
            outs << endl;
        }
        else
        {
            for(unsigned int i = 0; i < m; i++) outs << "*";
            outs << endl;
            triangle(outs,m+1,n);
            for(unsigned int i = 0; i < m; i++) outs << "*";
            outs << endl;
        }
    }
    double pow(double x, int n)
    {
        if(x == 0) assert(n > 0 && "If x is 0 then n must be > 0");
        else if(n == 0) return 1;
        else if(n < 0) return 1/pow(x,-n);
        else return x * pow(x,n-1);
    }
    void indented_sentences(size_t m, size_t n)
    {
        assert(m <= n);
        if(m == n) return;
        else
        {
            string indent = "";
            for(size_t i = m; i > 1; i--) indent += " ";
            cout << indent << "This was written by calling number " << m << "." << endl;
            indented_sentences(m+1,n);
            cout << indent << "This was ALSO written by calling number " << m << "." << endl;
        }
    }
}
