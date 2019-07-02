//
//  main.cpp
//  ProjectEuler
//
//  Created by Dibyaranjan Sathua on 26/06/19.
//  Copyright © 2019 Dibyaranjan Sathua. All rights reserved.
//

#include <iostream>
#include <string>
#include "problem236.hpp"
#include "problem1.hpp"
#include "problem2.hpp"
#include "problem3.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    
    ////////////////////////// Problem 236 ////////////////////////////////
//    int n = 3;
//    vector<int> a{10, 8, 6}, b{2, 9, 9};
//    P236::findSolution236(n, a, b);
    
//    int n = 5;
//    vector<int> a{5248, 1312, 2624, 5760, 3936}, b{640, 1888, 3776, 3776, 5664};
//    P236::findSolution236(n, a, b);
    
    
    /////////////////////////  Problem 1 //////////////////////////////////
//    cout << P1::findSolution1(1000) << endl;
    
    
    /////////////////////////  Problem 2 ///////////////////////////////////
//    cout << P2::findSolution2(4000000) << endl;
    
    
    ////////////////////////  Problem 3 ///////////////////////////////////
    cout << P3::findSolution3(600851475143) << endl;
    
    
    return 0;
}


vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });
    
    input_string.erase(new_end, input_string.end());
    
    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }
    
    vector<string> splits;
    char delimiter = ' ';
    
    size_t i = 0;
    size_t pos = input_string.find(delimiter);
    
    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));
        
        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }
    
    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));
    
    return splits;
}


string ltrim(const string &str) {
    string s(str);
    
    s.erase(
            s.begin(),
            find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
            );
    
    return s;
}

string rtrim(const string &str) {
    string s(str);
    
    s.erase(
            find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
            s.end()
            );
    
    return s;
}

//vector<string> split(const string &str) {
//    vector<string> tokens;
//    
//    string::size_type start = 0;
//    string::size_type end = 0;
//    
//    while ((end = str.find(" ", start)) != string::npos) {
//        tokens.push_back(str.substr(start, end - start));
//        
//        start = end + 1;
//    }
//    
//    tokens.push_back(str.substr(start));
//    
//    return tokens;
//}
