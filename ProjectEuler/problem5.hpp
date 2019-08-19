//
//  problem5.hpp
//  ProjectEuler
//
//  Created by Dibyaranjan Sathua on 16/07/19.
//  Copyright © 2019 Dibyaranjan Sathua. All rights reserved.
//
/*
 2520 is the smallest number that can be divided by each of the numbers from  to  without any remainder.
 What is the smallest positive number that is evenly divisible(divisible with no remainder) by all of the numbers from 1 to N ?
 */

#ifndef problem5_hpp
#define problem5_hpp

#include <iostream>
#include <vector>

using namespace std;

namespace P5 {
    long findLCM(int N);
    long findSolution5(int N);
}

#endif /* problem5_hpp */
