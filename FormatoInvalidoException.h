//
// Created by Abraham on 4/29/2026.
//

#ifndef MAIN_CPP_FORMATOINVALIDOEXCEPTION_H
#define MAIN_CPP_FORMATOINVALIDOEXCEPTION_H
#include "Excepciones.h"


class FormatoInvalidoException  : public Excepciones {
public:
    FormatoInvalidoException(const string& m);
    const char* what() const noexcept override;
};


#endif //MAIN_CPP_FORMATOINVALIDOEXCEPTION_H