//
// Created by Abraham on 4/29/2026.
//

#include "ArchivoInvalidoException.h"
ArchivoInvalidoException::ArchivoInvalidoException(const string& m): Excepciones("Archivo invalido: " + m) {}

const char* ArchivoInvalidoException::what() const noexcept {
    return msg.c_str();
}