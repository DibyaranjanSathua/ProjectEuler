//
//  problem7.hpp
//  ProjectEuler
//
//  Created by Dibyaranjan Sathua on 21/09/19.
//  Copyright © 2019 Dibyaranjan Sathua. All rights reserved.
//

#ifndef problem7_hpp
#define problem7_hpp

#include <iostream>
#include <vector>

using namespace std;

namespace P7 {
    int getAllPrimes(vector<int> &primes, int max_value);
    int findNPrimes(int n, vector<long> &primes);
    long findSolution7(int n, vector<long> &primes);
}

#endif /* problem7_hpp */
