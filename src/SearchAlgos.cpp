//
// Created by sidha on 2/24/2023.
//

#include "../header/SearchAlgos.h"


SearchAlgos::SearchAlgos(vector<vector<double>> user) {
    for (unsigned i = 0; i < user.size(); i++){
        data_set.push_back(user.at(i));
    }
}

void SearchAlgos::backward_selection() {
}

void SearchAlgos::forward_selection() {
    vector<vector<double>> data_temp;

    vector<int> best_features;
    vector<int> curr_best;
    vector<int> temp;
    vector<int> current_features;
    double ac;
    double max;
    double local_max;

    cout << "Using no features and 'random' evaluation, I get an accuracy of ";
    ac = accuracy(data_temp);
    cout << setprecision(4)<< ac << "%\n\n";
    cout << "Beginning search.\n\n";

    data_temp.push_back(data_set.at(0));

    for(unsigned i = 1; i < data_set.size(); i++) {
        local_max = 0.0;
        for (unsigned j = 1; j < data_set.size(); j++) {
            current_features = curr_best;


            for (unsigned k = 0; k < current_features.size(); k++) {
                data_temp.push_back(data_set.at(current_features.at(k)));
            }

            if (find(current_features.begin(), current_features.end(), j) == current_features.end()){
                data_temp.push_back(data_set.at(j));
                current_features.push_back(j);
                cout << "Using feature(s) {";

                for (int l = 0; l < current_features.size(); l++){
                    if (l == current_features.size() - 1)
                        cout << current_features.at(l);
                    else
                    cout << current_features.at(l) << ",";
                }
                cout << "}";
                ac = accuracy(data_temp);
                cout << " accuracy is " << setprecision(4 ) << ac << "%" << endl;

                if (ac > local_max){
                    local_max = ac;
                    temp = current_features;
                }
            }
            data_temp.erase(data_temp.begin() + 1, data_temp.end());
            current_features.clear();
        }
        curr_best = temp;
        cout << "Feature set {";
        for (unsigned j = 0; j < curr_best.size(); j++) {
            if (j == curr_best.size() - 1)
                cout << curr_best.at(j);
            else
            cout << curr_best.at(j) << ",";
        }
        cout << "} was best, accuracy is " << setprecision(4) << local_max << "%\n\n";

        if (local_max > max){
            best_features = curr_best;
            max = local_max;
        } else if (local_max < max){
            cout << "(Warning, Accuracy has decreased!)\n";
        }
        temp.clear();
    }

    cout << "Finished search!! The best feature subset is {";
    for (unsigned j = 0; j < best_features.size(); j++){
        if (j == best_features.size() - 1)
        cout << best_features.at(j);
        else
        cout << best_features.at(j) << ",";
    }
    cout << "} which has an accuracy of " << setprecision(4) << max << "%" << endl;
}

double SearchAlgos::accuracy(vector<vector<double>> data_set) {
    double num1 = (rand() % 100);
    double num2 = (float) rand()/RAND_MAX;
    return (double) num1 + num2;
}

