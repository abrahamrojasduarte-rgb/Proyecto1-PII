cmake_minimum_required(VERSION 4.1)
project(Proyecto1_PII)

set(CMAKE_CXX_STANDARD 20)

add_executable(Proyecto1_PII main.cpp
        Incidencia.cpp
        Incidencia.h
        GestorEquipos.cpp
        GestorEquipos.h
        Equipo.cpp
        registroCompleto.cpp
        Registro.cpp
        registroReparados.cpp
        Simulador.cpp
        Mantenimiento.cpp
        Mantenimiento.h
        Menu.cpp
        Menu.h
        Excepciones.h
        FormatoInvalidoException.cpp
        FormatoInvalidoException.h
        Excepciones.cpp
        ArchivoInvalidoException.cpp
        ArchivoInvalidoException.h
        OperacionInconsistenteException.cpp
        OperacionInconsistenteException.h

)
