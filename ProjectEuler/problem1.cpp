//
//  problem1.cpp
//  ProjectEuler
//
//  Created by Dibyaranjan Sathua on 27/06/19.
//  Copyright © 2019 Dibyaranjan Sathua. All rights reserved.
//

#include "problem1.hpp"

long P1::sumOfN(long n) {
    return (n * (n+1)) / 2;
}


long P1::findSolution1(long n) {
    long divisibleBy3 = 0, divisibleBy5 = 0, divisibleBy15 = 0;
    int count = 0;
    for (long i = n-1; i >= 3; i--) {
        if (i % 3 == 0 && divisibleBy3 == 0) {
            divisibleBy3 = i;
            count++;
        }
        
        if (i % 5 == 0 && divisibleBy5 == 0) {
            divisibleBy5 = i;
            count++;
        }
        
        if (i % 15 == 0 && divisibleBy15 == 0) {
            divisibleBy15 = i;
            count++;
        }
        
        if (count == 3) {
            break;
        }
    }
    
    long sum = 3 * P1::sumOfN(divisibleBy3 / 3) + 5 * P1::sumOfN(divisibleBy5 / 5) - 15 * P1::sumOfN(divisibleBy15 / 15);
    return sum;
}
