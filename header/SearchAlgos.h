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
#include <cfloat>
#include <cmath>

using namespace std;

class SearchAlgos {
private:
    vector<vector<double>> data_set;
    vector<double> feature_set;
    static double nearest_neighbor(vector<double>, vector<vector<double>>);
public:
    explicit SearchAlgos(vector<vector<double>> user);
    static double accuracy(vector<vector<double>> set_data);
    void forward_selection();
    void backward_selection();

};


#endif //UNTITLED_SEARCHALGOS_H
