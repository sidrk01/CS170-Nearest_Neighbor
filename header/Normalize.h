//
// Created by sidha on 3/7/2023.
//

#ifndef UNTITLED_NORMALIZE_H
#define UNTITLED_NORMALIZE_H
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;


class Normalize {
private:
    vector<vector<double>> data_cpy;
    vector<vector<double>> normal_vct;

    //helper function
    vector<double> eval_mean();
    double eval_dev(int, int, double);
public:
    Normalize(vector<vector<double>>);
    vector<vector<double>> normalize_data();
};


#endif //UNTITLED_NORMALIZE_H
