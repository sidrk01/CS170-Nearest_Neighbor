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
    vector<vector<double>> data_temp;

    vector<int> curr_best;
    vector<int> temp;
    vector<int> current_features;
    double ac;
    double max;
    double local_max;
    int removed_feature;

    //prexisting accuracy without features
    cout << "Using no features and 'random' evaluation, I get an accuracy of ";
    ac = accuracy(data_temp);
    cout << setprecision(4)<< ac << "%\n\n";
    cout << "Beginning search.\n\n";

    vector<int> best_features(data_set.size() - 1); //includes all possible features
    for (unsigned i = 0; i < best_features.size(); i++){
        best_features[i] = i +1; //adding all features to be tracked
    }
    curr_best = best_features;

    for (unsigned i = 1; i < data_set.size(); i++){
        local_max = 0.0;
        for (unsigned j = 1; j < data_set.size(); j++){
            current_features = curr_best; //include all features to be tested

            for (unsigned k = 0; k < current_features.size();k++){
                data_temp.push_back(data_set.at(current_features.at(k))); //adds subsequent feature to temp_data from preselect features
            }

            if (find(current_features.begin(), current_features.end(), j) != current_features.end()){ //finds features to eliminate
                removed_feature = (find(current_features.begin(), current_features.end(), j)) -  current_features.begin() + 1; //holds value of removed feature
                data_temp.erase(data_set.begin() + removed_feature); //eliminates unnecessary value
                current_features.erase(find(current_features.begin(), current_features.end(), j));
                cout << "Using feature(s) {";
                //remaining features
                for (unsigned l = 0; l < current_features.size(); l++){
                    if (l == current_features.size() - 1)
                        cout << current_features.at(l); //proper formatting
                    else
                        cout << current_features.at(l) << ",";
                }
                cout << "}";
                //provided accuracy
                ac = accuracy(data_temp);
                cout << " accuracy is " << setprecision(4) << ac << "%\n";

                if (local_max <= ac) { //replaces local accuracy with current best one
                    local_max = ac;
                    temp = current_features;
                }
            }

            data_temp.erase(data_temp.begin() + 1, data_temp.end()); //clears feature set for following iteration
            current_features.clear();
        }

        curr_best = temp;
        cout << "Feature set {"; //prints best feature set from possible combos
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
            cout << "(Warning, Accuracy has decreased!)\n"; //issues warning when local max is reduced
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
    cout << "} which has an accuracy of " << setprecision(4) << max << "%" << endl; //best accuracy for possible features
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

    //prexisting accuracy without features
    cout << "Using no features and 'random' evaluation, I get an accuracy of ";
    ac = accuracy(data_temp);
    cout << setprecision(4)<< ac << "%\n\n";
    cout << "Beginning search.\n\n";

    data_temp.push_back(data_set.at(0)); //add first set of values

    for(unsigned i = 1; i < data_set.size(); i++) { //"walks" down search tree
        local_max = 0.0;
        for (unsigned j = 1; j < data_set.size(); j++) { //considers first set of best features
            current_features = curr_best;


            for (unsigned k = 0; k < current_features.size(); k++) { //adds the best set of features to temp data
                data_temp.push_back(data_set.at(current_features.at(k)));
            }

            //only consider adding this feature if it was not already added
            if (find(current_features.begin(), current_features.end(), j) == current_features.end()){
                data_temp.push_back(data_set.at(j));
                current_features.push_back(j);
                cout << "Using feature(s) {"; //prints current Node

                for (int l = 0; l < current_features.size(); l++){
                    if (l == current_features.size() - 1) //prints proper notation of feature set
                        cout << current_features.at(l);
                    else
                    cout << current_features.at(l) << ",";
                }
                cout << "}";
                ac = accuracy(data_temp); //measures accuracy for given feature set
                cout << " accuracy is " << setprecision(4 ) << ac << "%\n";

                if (ac > local_max){
                    local_max = ac;
                    temp = current_features;
                }
            }
            data_temp.erase(data_temp.begin() + 1, data_temp.end()); //clears feature set for following iteration
            current_features.clear();
        }
        curr_best = temp;
        cout << "Feature set {"; //prints best feature set from possible combos
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
            cout << "(Warning, Accuracy has decreased!)\n"; //issues warning when local max is reduced
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
    cout << "} which has an accuracy of " << setprecision(4) << max << "%" << endl; //best accuracy for possible features
}

double SearchAlgos::accuracy(vector<vector<double>> data_set) {
    double num1 = (rand() % 100);
    double num2 = (float) rand()/RAND_MAX;
    return (double) num1 + num2;
}

