//
//  problem7.cpp
//  ProjectEuler
//
//  Created by Dibyaranjan Sathua on 21/09/19.
//  Copyright © 2019 Dibyaranjan Sathua. All rights reserved.
//

#include "problem7.hpp"

int P7::getAllPrimes(vector<int> &primes, int max_value) {
    vector<bool> marked;
    marked.assign(max_value, false);
    
    for (int i = 2; i * i <= max_value; i++) {
        if (!marked[i]) {
            // Update all multiples of p greater than or equal to the square of it numbers
            // which are multiple of p and are less than p^2 are already been marked.
            
            for (int j = i * i; j <= max_value; j += i) {
                marked[j] = true;
            }
        }
    }
    
    primes.clear();
    for (int i = 2; i <= max_value; i++) {
        if (!marked[i]) {
            primes.push_back(i);
        }
    }
    
    return 0;
}


int P7::findNPrimes(int n, vector<long> &primes) {
    primes.clear();
    primes.push_back(2);
    int count = 1;
    long num = 3;
    while (count < n) {
        for (auto &x : primes) {
            if (x > num / 2) {
                primes.push_back(num);
                count++;
                break;
            }
            else if (num % x == 0) {
                break;
            }
        }
        num += 2;
    }
    
    return 0;
}

long P7::findSolution7(int n, vector<long> &primes) {
    return primes[n];
}
