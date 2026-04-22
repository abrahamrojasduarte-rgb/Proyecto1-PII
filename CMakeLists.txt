cmake_minimum_required(VERSION 4.1)
project(Proyecto1_PII)

set(CMAKE_CXX_STANDARD 20)

add_executable(Proyecto1_PII main.cpp
        Incidencia.cpp
        Incidencia.h
        GestorEquipos.cpp
        GestorEquipos.h
        Equipo.cpp)
