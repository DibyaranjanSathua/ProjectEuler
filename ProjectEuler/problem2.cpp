//
//  problem2.cpp
//  ProjectEuler
//
//  Created by Dibyaranjan Sathua on 28/06/19.
//  Copyright © 2019 Dibyaranjan Sathua. All rights reserved.
//

#include "problem2.hpp"

long P2::findNthFibo(long n) {
    long result;
    double goldenRatio = 1.61803399;
    double root5 = 2.23606798;
    double nthvalue = pow(goldenRatio, n) / root5;
    result = (long) round(nthvalue);
    return result;
}


long P2::findSolution2(long n) {
    long sum = 0;
//    int count = 3;
//    long nthvalue;
//    do {
//        nthvalue = P2::findNthFibo(count);
//        count += 3;
//        if (nthvalue <= n) {
//            sum += nthvalue;
//        }
//    } while (nthvalue <= n);
    long first = 1, second = 2, third;
    sum = second;
    third = first + second;
    while (third < n) {
        if (!(third & 1)) {
            sum += third;
        }
        first = second;
        second = third;
        third = first + second;
    }
    
    return sum;
}
