//
// Created by Abraham on 4/29/2026.
//

#include "FormatoInvalidoException.h"


FormatoInvalidoException::FormatoInvalidoException(const string& m) : Excepciones("Formato invalido "+  m){}

const char* FormatoInvalidoException::what() const noexcept {
    return msg.c_str();
}