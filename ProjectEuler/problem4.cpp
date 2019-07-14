//
//  problem4.cpp
//  ProjectEuler
//
//  Created by Dibyaranjan Sathua on 14/07/19.
//  Copyright © 2019 Dibyaranjan Sathua. All rights reserved.
//

#include "problem4.hpp"

int P4::getNearestPalindrome(int n) {
    int firstThreeDigits = n / 1000;
    int temp = firstThreeDigits;
    int thirdDigit = temp % 10;
    temp /= 10;
    int secondDigit = temp % 10;
    temp /= 10;
    int firstDigit = temp;
    int lastThreeDigits = thirdDigit * 100 + secondDigit * 10 + firstDigit;
//    cout << firstThreeDigits << " " << lastThreeDigits << endl;
    return firstThreeDigits * 1000 + lastThreeDigits;
}


bool P4::checkFactorProduct(int n) {
    int i;
    if (n % 2 == 0) {
        i = 100;
    }
    else {
        i = 101;
    }
    for (; i < 1000; i+=2) {
        if (n % i == 0) {
            int secondFactor = n / i;
            if (secondFactor >= 100 && secondFactor <= 999) {
//                cout << i << " " << secondFactor << endl;
                return true;
            }
        }
    }
    return false;
}


int P4::findSolution4(int n) {
    int startingNum = getNearestPalindrome(n);
    while (startingNum >= 100001) {
//        cout << startingNum << endl;
        if (startingNum < n && checkFactorProduct(startingNum)) {
            return startingNum;
        }
        
        int firstThreeDigits = startingNum / 1000;
        int secondThirdDigit = firstThreeDigits % 100;
        if (secondThirdDigit == 0) {
            startingNum -= 11;
        }
        else if (secondThirdDigit % 10 == 0) {
            startingNum -= 110;
        }
        else {
            startingNum -= 1100;
        }
    }
    
    return 0;
}
