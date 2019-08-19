//
//  problem5.cpp
//  ProjectEuler
//
//  Created by Dibyaranjan Sathua on 16/07/19.
//  Copyright © 2019 Dibyaranjan Sathua. All rights reserved.
//

#include "problem5.hpp"

long P5::findLCM(int N) {
    vector<int> numbers, factors;
    long lcm = 1;
    bool isPrime, hasFactor;
    for (int i = 1; i <= N; i++) {
        numbers.push_back(i);
    }
    
    for (int i = 2; i <= N; i++) {
        isPrime = true;
        for (int j = 2; j < i; j++) {
            if (i % j == 0) {
                isPrime = false;
            }
        }
        
        // Check if the number is prime
        if (isPrime) {
            do {
                hasFactor = false;
                for (auto &x : numbers) {
                    if (x % i == 0) {
                        hasFactor = true;
                        x /= i;
                    }
                }
                
                if (hasFactor) {
                    factors.push_back(i);
                }
                
            } while (hasFactor);
        }
    }
    
//    cout << "Factors: ";
    for (auto &x : factors) {
//        cout << x << " ";
        lcm *= x;
    }
//    cout << endl;
    
    return lcm;
}


long P5::findSolution5(int N) {
    return findLCM(N);
}
