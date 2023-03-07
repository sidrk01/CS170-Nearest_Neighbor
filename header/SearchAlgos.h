//
// Created by sidha on 2/24/2023.
//

#ifndef UNTITLED_SEARCHALGOS_H
#define UNTITLED_SEARCHALGOS_H
#include <utility>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>

using namespace std;

class SearchAlgos {
private:
    vector<vector<double>> data_set;
    vector<double> feature_set;
public:
    SearchAlgos(vector<vector<double>> user);
    double accuracy (vector<int> data_set);
    void forward_selection();

    void backward_selection();

};


#endif //UNTITLED_SEARCHALGOS_H
