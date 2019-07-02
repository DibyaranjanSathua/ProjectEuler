//
//  problem3.cpp
//  ProjectEuler
//
//  Created by Dibyaranjan Sathua on 28/06/19.
//  Copyright © 2019 Dibyaranjan Sathua. All rights reserved.
//

#include "problem3.hpp"

long P3::findSolution3(long n) {
    vector<long> primeFactors;
    while (n % 2 == 0) {
        primeFactors.push_back(2);
        n /= 2;
    }
    
    // n must be odd at this point. So we can skip
    // one element (Note i = i +2)
    for (long i = 3; i <= sqrt(n); i+=2) {
        while (n % i == 0) {
            primeFactors.push_back(i);
            n /= i;
        }
    }
    
    // This condition is to handle the case when n
    // is a prime number greater than 2
    if (n > 2) {
        primeFactors.push_back(n);
    }
    
    return primeFactors.back();
}
