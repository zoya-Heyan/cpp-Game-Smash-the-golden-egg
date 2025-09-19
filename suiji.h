#ifndef SUIJI_H
#define SUIJI_H

#include <random>
using namespace std;

class Random {
private:
    mt19937 gen;
public:
    Random() {
        random_device rd;
        gen.seed(rd());
    }

    int randint(int a, int b) {
        uniform_int_distribution<> dist(a, b);
        return dist(gen);
    }

    double randfloat(double a, double b) {
        uniform_real_distribution<double> dist(a, b);
        return dist(gen);
    }

    double randnormal(double mean, double stddev) {
        normal_distribution<double> dist(mean, stddev);
        return dist(gen);
    }
};

#endif
