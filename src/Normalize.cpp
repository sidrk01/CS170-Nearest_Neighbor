//
// Created by sidha on 3/7/2023.
//

#include "../header/Normalize.h"

Normalize::Normalize(vector<vector<double>> user_input) {
   data_cpy = user_input;
   normal_vct = data_cpy;
}

vector<vector<double>> Normalize::normalize_data() {
    vector<double> mean_vector;
    mean_vector = eval_mean();

    double dev = 0.0;
    double normal = 0.0;

    for(unsigned i = 1; i < data_cpy.size(); i++ ){
        dev = eval_dev(data_cpy.at(i).size(), i - 1, mean_vector.at(i-1));
        for (unsigned j = 0; j < data_cpy.at(i).size(); j++){
            normal_vct.at(i).at(j) =  (data_cpy.at(i).at(j) - mean_vector.at(i-1)) / dev; // x - µ/σ
        }
    }
    return normal_vct;
}

vector<double> Normalize::eval_mean() {
    vector<double> mean_calc;
    double mean_eval = 0.0; //holds individual means for features
    for (unsigned i = 1; i < data_cpy.size(); i++){
        for (double j : data_cpy.at(i)){
            mean_eval +=  j;
        }
        mean_eval /= static_cast<double>(data_cpy.at(i).size());
        mean_calc.push_back(mean_eval);
        mean_eval = 0.0;
    }
    return mean_calc;
}

double Normalize::eval_dev(int n, int feature_index, double mean) {
   double standard_dev = 0.0;
   double var = 0.0;

   for (unsigned i = 0; i < n; i++){
      var +=  pow((data_cpy.at(feature_index).at(i) - mean), 2);
   }
   standard_dev = sqrt(var/(n-1));
    return standard_dev;
}
