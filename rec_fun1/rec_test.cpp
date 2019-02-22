#include <iostream>
#include <cassert>
#include <cstring>
#include "rec_fun.h"
using namespace recur_functions;
using namespace std;

int main()
{
    cout << "Testing One Binary Number Function" << endl;
    binary_print(cout << "n= 0" << " Output:", 0);
    cout << endl;
    binary_print(cout << "n= 4" << " Output:", 4);
    cout << endl;
    binary_print(cout << "n= 27" << " Output:", 27);
    cout << endl;
    cout << "Testing Triangle Pattern Function" << endl;
    triangle(cout, 3, 5);
    cout << "Testing Pow Function" << endl;
    cout << pow(0, 2) << endl;
    //cout << pow(0, -2) << endl;
    cout << pow(2, 2) << endl;
    cout << pow(2, -2) << endl;
    cout << pow(-2, 2) << endl;
    cout << pow(2, -2) << endl;
    cout << "Testing Repeated and Indented Sentences Function" << endl;
    indented_sentences(1, 5);
}
