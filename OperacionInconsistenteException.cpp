//
// Created by Abraham on 4/29/2026.
//

#include "OperacionInconsistenteException.h"
OperacionInconsistenteException::OperacionInconsistenteException(const string& m): Excepciones("Operacion inconsistente: " + m) {}

const char* OperacionInconsistenteException::what() const noexcept {
    return msg.c_str();
}