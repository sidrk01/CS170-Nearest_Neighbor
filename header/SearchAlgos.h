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
    vector<double>feature_set;
public:
    Node(int s, vector<double> f) {
        score = s;
        feature_set = std::move(f);
    }
    Node (){
        score = 0.0;
    }
    double accuracy(Node* node){ //generates random percentage
        double num1 = (rand() % 100);
        double num2 = (float) rand()/RAND_MAX;
        return (double) num1 + num2;
    }
};
class SearchAlgos {
private:
    double score;
    vector<double>feature_set;
public:
    SearchAlgos();
    double evaluation();
};


#endif //UNTITLED_SEARCHALGOS_H
