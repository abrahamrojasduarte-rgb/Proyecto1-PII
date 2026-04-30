//
// Created by Abraham on 4/29/2026.
//

#ifndef MAIN_CPP_EXCEPCIONES_H
#define MAIN_CPP_EXCEPCIONES_H
#include <string>
#include <stdexcept>
using namespace std;

class Excepciones :public exception {
protected:
    string msg;
public:
    Excepciones(const string& m);
    virtual const char* what() const noexcept override = 0;;
};
#endif //MAIN_CPP_EXCEPCIONES_H