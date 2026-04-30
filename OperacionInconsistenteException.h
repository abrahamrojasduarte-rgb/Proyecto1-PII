//
// Created by Abraham on 4/29/2026.
//

#ifndef MAIN_CPP_OPERACIONINCONSISTENTEEXCEPTION_H
#define MAIN_CPP_OPERACIONINCONSISTENTEEXCEPTION_H
#include "Excepciones.h"

class OperacionInconsistenteException : public Excepciones {
public:
    OperacionInconsistenteException(const string& m);
    const char* what() const noexcept override;
};


#endif //MAIN_CPP_OPERACIONINCONSISTENTEEXCEPTION_H