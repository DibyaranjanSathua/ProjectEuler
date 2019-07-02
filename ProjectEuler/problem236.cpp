//
//  problem236.cpp
//  ProjectEuler
//
//  Created by Dibyaranjan Sathua on 26/06/19.
//  Copyright © 2019 Dibyaranjan Sathua. All rights reserved.
//

#include "problem236.hpp"

long P236::Fraction::gcd(long a, long b) {
    if (a == 0) {
        return b;
    }
    
    return gcd(b % a, a);
}


P236::Fraction::Fraction() {
    this->numerator = 0;
    this->denominator = 1;
}


P236::Fraction::Fraction(long num, long deno) {
    if (deno == 0) {
        exit(0);
    }
    else if (num == 0) {
        this->numerator = 0;
        this->denominator = 1;
    }
    else {
        long commonFactor = gcd(num, deno);
        this->numerator = num / commonFactor;
        this->denominator = deno / commonFactor;
    }
}


P236::Fraction P236::Fraction::operator*(const P236::Fraction &obj) {
    Fraction result(this->numerator * obj.numerator, this->denominator * obj.denominator);
    return result;
}


P236::Fraction P236::Fraction::operator/(const P236::Fraction &obj) {
    Fraction result(this->numerator * obj.denominator, this->denominator * obj.numerator);
    return result;
}


bool P236::Fraction::operator==(const P236::Fraction &obj) {
    if (this->numerator == obj.numerator && this->denominator == obj.denominator) {
        return true;
    }
    return false;
}


ostream& P236::operator<<(ostream &output, const P236::Fraction &obj) {
    if (obj.denominator == 1) {
        output << obj.numerator;
    }
    else {
        output << obj.numerator << "/" << obj.denominator;
    }
    return output;
}


long P236::Fraction::getNumerator() {
    return this->numerator;
}


long P236::Fraction::getDenominator() {
    return this->denominator;
}


int P236::findSolution236(int n, vector<int> aProducts, vector<int> bProducts) {
    vector<P236::Fraction> productsRatio, spoilProductsRatio;
    P236::Fraction mFactor, temp, totalSpoilageRate;
    vector<int> aSpoilProducts, bSpoilProducts, multiplicationFactor;
    int aSumProducts = 0, bSumProducts = 0;
    int aSumSpoilProducts = 0, bSumSpoilProducts = 0;
    bool wrongMFactor;
    for (int i = 0; i < n; i++) {
        // productRatio is the ratio of number of products of B to number of products of A for each product
        productsRatio.push_back(P236::Fraction(bProducts[i], aProducts[i]));
        aSumProducts += aProducts[i];
        bSumProducts += bProducts[i];
    }
    
    for (int i = 1; i <= aProducts[0]; i++) {
        for (int j = 1; j <= bProducts[0]; j++) {
//            cout << "Iterations " << (i*bProducts[0]) + j + 1 << " i: " << i << " j: " << j << endl;
            aSpoilProducts.clear();
            bSpoilProducts.clear();
            mFactor = P236::Fraction(j, i) / productsRatio[0];
            // mFactor > 1. Check for this condition.
            if (mFactor.getNumerator() <= mFactor.getDenominator()) {
                continue;
            }
            
            wrongMFactor = false;
            // spoilProductsRatio is the ratio of spoil products of B to spoil products of A
            spoilProductsRatio.clear();
            spoilProductsRatio.push_back(Fraction(j, i));
            for (int k = 1; k < n; k++) {
                // Ratio of no spoil products of B and no of spoil products of A
                temp = mFactor * productsRatio[k];
                // Spoil products can not be more than the total number of products
                if (temp.getNumerator() > bProducts[k] || temp.getDenominator() > aProducts[k]) {
                    wrongMFactor = true;
                    break;
                }
                
                spoilProductsRatio.push_back(temp);
            }
            
            if (wrongMFactor) {
                continue;
            }
            
            multiplicationFactor.clear();
            multiplicationFactor.assign(n, 1);
            while (true) {
//                cout << "Multiplication Factor : ";
//                for (auto &x : multiplicationFactor) {
//                    cout << x << " ";
//                }
//                cout << endl;
                for (int k = n-1; k > 0; k--) {
                    if (spoilProductsRatio[k].getDenominator() * multiplicationFactor[k] > aProducts[k] || spoilProductsRatio[k].getNumerator() * multiplicationFactor[k] > bProducts[k]) {
                        multiplicationFactor[k] = 1;
                        multiplicationFactor[k-1]++;
                    }
                }
                
                if (spoilProductsRatio[0].getDenominator() * multiplicationFactor[0] > aProducts[0] || spoilProductsRatio[0].getNumerator() * multiplicationFactor[0] > bProducts[0]) {
                    break;
                }
                
                aSumSpoilProducts = 0;
                bSumSpoilProducts = 0;
                for (int k = 0; k < n; k++) {
                    aSumSpoilProducts += spoilProductsRatio[k].getDenominator() * multiplicationFactor[k];
                    bSumSpoilProducts += spoilProductsRatio[k].getNumerator() * multiplicationFactor[k];
                }
                
                totalSpoilageRate = P236::Fraction(aSumSpoilProducts, aSumProducts) / P236::Fraction(bSumSpoilProducts, bSumProducts);
                if (mFactor == totalSpoilageRate) {
                    cout << "mFactor found: " << mFactor << endl;
                    //break;
                    return 0;
                }
                
                multiplicationFactor[n-1]++;
            }
            
        }
    }
    return 0;
}
