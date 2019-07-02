//
//  problem236.hpp
//  ProjectEuler
//
//  Created by Dibyaranjan Sathua on 26/06/19.
//  Copyright © 2019 Dibyaranjan Sathua. All rights reserved.
//

#ifndef problem236_hpp
#define problem236_hpp

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

namespace P236 {
    int findSolution236(int n, vector<int> aProducts, vector<int> bProducts);
    
    class Fraction {
    private:
        long numerator, denominator;
        long gcd(long a, long b);
        
    public:
        Fraction();
        Fraction(long num, long deno);
        long getNumerator();
        long getDenominator();
        Fraction operator*(const Fraction &obj);
        Fraction operator/(const Fraction &obj);
        bool operator==(const Fraction &obj);
        friend ostream& operator<<(ostream &output, const Fraction &obj);
    };
}

#endif /* problem236_hpp */
