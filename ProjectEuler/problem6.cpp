//
//  problem6.cpp
//  ProjectEuler
//
//  Created by Dibyaranjan Sathua on 19/08/19.
//  Copyright © 2019 Dibyaranjan Sathua. All rights reserved.
//

#include "problem6.hpp"

// FInd the sum of n number from 1 to n
long P6::findSumN(long n) {
    return (n * (n + 1)) / 2;
}

// Find the sum of n2 for n = 1 to n
long P6::findSumNSquare(long n) {
    return (n * (n + 1) * (2 * n + 1)) / 6;
}


long P6::findSolution6(long n) {
    long sumN = findSumN(n);
    return sumN * sumN - findSumNSquare(n);
}
