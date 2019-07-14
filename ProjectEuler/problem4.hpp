//
//  problem4.hpp
//  ProjectEuler
//
//  Created by Dibyaranjan Sathua on 14/07/19.
//  Copyright © 2019 Dibyaranjan Sathua. All rights reserved.
//

/*
 A palindromic number reads the same both ways. The smallest 6 digit palindrome made from the product of two 3-digit numbers is 101101 = 143 X 707.
 
 Find the largest palindrome made from the product of two 3-digit numbers which is less than N.
 
*/

#ifndef problem4_hpp
#define problem4_hpp

#include <iostream>

using namespace std;

namespace P4 {
    int getNearestPalindrome(int n);
    int findSolution4(int n);
    bool checkFactorProduct(int n);         // Check if palindrome made from the product of two 3-digit numbers
}

#endif /* problem4_hpp */
