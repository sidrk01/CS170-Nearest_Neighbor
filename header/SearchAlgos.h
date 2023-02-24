//
// Created by sidha on 2/24/2023.
//

#ifndef UNTITLED_SEARCHALGOS_H
#define UNTITLED_SEARCHALGOS_H
#include <utility>
#include <cstdlib>
#include <cmath>
#include <vector>

struct Node {
    double score;
    std::vector<double>feature_set;
public:
    Node(int s, std::vector<double> f) {
        score = s;
        feature_set = std::move(f);
    }
    Node (){
        score = 0.0;
    }
    double accuracy(){ //generates random percentage
        double num1 = (rand() % 100);
        double num2 = (float) rand()/RAND_MAX;
        return (double) num1 + num2;
    }
};
class SearchAlgos {
private:
    double highest_accuracy;
    std::vector<double> high_feature;
public:
    SearchAlgos();
    std::vector<double> explore_features(std::vector<double> feature_list);
    void forward_selection();
    void backward_selection();

};


#endif //UNTITLED_SEARCHALGOS_H
