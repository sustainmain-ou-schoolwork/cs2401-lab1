/**
 *   @file: MyTime_Main.cc
 * @author: Josh Marusek
 *   @date: 2022-01-18
 *  @brief: Uses a class with overloaded operators to manipulate times.
 */

#include <iostream>
#include <string>
#include <cstdlib>
#include "MyTime.h"

using namespace std;

int main(int argc, char const *argv[]) {
    // initialize variables
    MyTime time1;
    MyTime time2;
    int k;
    
    // get input
    cout << "Enter time 1: ";
    cin >> time1;
    cout << "Enter time 2: ";
    cin >> time2;
    cout << "Enter scalar: ";
    cin >> k;

    // print results
    cout << endl;
    cout << "Addition:\t\t" << time1 + time2 << endl;
    cout << "Subtraction:\t\t" << time1 - time2 << endl;
    cout << "Multiplication:\t\t" << time1 * k << endl;
    cout << "Division:\t\t" << time1 / k << endl;
    cout << "Time 1 == time 2:\t" << (time1 == time2 ? "true" : "false") << endl;
    cout << "Time 1 < time 2:\t" << (time1 < time2 ? "true" : "false") << endl;
    cout << "Time 1 <= time 2:\t" << (time1 <= time2 ? "true" : "false") << endl;
}