#pragma once
#include<iostream>
#include<vector>
#include<fstream>
#include<cassert>
inline void printsolution(const std::vector<double>& a) {
    std::cout << "solution:" << '\n';
    for (size_t i = 0; i < a.size(); i++) {
        std::cout << a[i] << '\n';
    }
}
inline void printmatrix(const std::vector<std::vector< double>>& a, const std::vector< double>& b) {
    std::cout << "A:\n";
    for (size_t i = 0; i < a.size(); i++) {
        for (size_t j = 0; j < a[i].size(); j++) {
            std::cout << a[i][j] << " ";
        }
        std::cout << '\n';
    }
    std::cout << "f:\n";
    for (size_t i = 0; i < b.size(); i++) {
        std::cout << b[i] << '\n';
    }

    return;
}
inline void verification(const std::vector<std::vector<double>>a, const std::vector<double>b) {
    std::cout << "verification:\n";
    for (int i = 0; i < a.size(); i++) {
        double s = 0;
        for (int j = 0; j < a.size(); j++) {
            s += a[i][j] * b[j];
        }
        std::cout << s << '\n';
    }
    return;
}
inline void gauss(std::vector<std::vector< double>>& a, std::vector< double>& b) {
    //forward substitution
    std::vector<std::vector< double>>u = a;
    for (size_t k = 0; k < a.size(); k++) {
        size_t row1 = k;
        size_t row2 = k;
        double max = std::abs(a[k][k]);

        for (size_t i = k + 1; i < a.size(); i++) {
            if (std::abs(a[i][k]) > max) {
                max = std::abs(a[i][k]);
                row2 = i;
            }
        }
        if (max == 0) {
            std::cout << "error\n";
            std::exit(EXIT_FAILURE);

        }

        {
            std::vector<double>c = std::move(a[row1]);
            a[row1] = std::move(a[row2]);
            a[row2] = std::move(c);
        }
       
        double temp = b[row1];
        b[row1] = b[row2];
        b[row2] = temp;
        for (size_t i = k + 1; i < a.size(); i++) {
            double kati = a[i][k] / a[k][k];

            for (size_t j = k; j < a.size(); j++) {

                a[i][j] = a[i][j] - kati * a[k][j];

            }
            b[i] = b[i] - kati * b[k];
        }

    }
    if (a[a.size() - 1][a.size() - 1] == 0) {
        std::cout << "error\n";
        std::exit(EXIT_FAILURE);
    }
    //backwards substitution
    std::vector < double>x(b.size());
    for (size_t k = a.size() - 1; k > 0; k--) {

        x[k] = b[k];
        for (size_t j = k + 1; j < a.size(); j++) {
            x[k] = (x[k] - a[k][j] * x[j]);
        }
        x[k] = x[k] / a[k][k];


    }
    size_t k = 0;
    while (k == 0) {
        x[k] = b[k];
        for (size_t j = k + 1; j < a.size(); j++) {
            x[k] = (x[k] - a[k][j] * x[j]);
        }
        x[k] = x[k] / a[k][k];
        break;
    }
    printsolution(x);//solution
    verification(u, x);//verification

}

