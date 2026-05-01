# Presentación Técnica – Proyecto de Programación II

## Introducción
Este proyecto consiste en desarrollar un sistema en C++ para la planificación automática de mantenimiento de equipos en un laboratorio.  
El enfoque principal no es solo almacenar datos, sino tomar decisiones sobre qué equipos reparar en función de su estado.

---

## Modelado del sistema
Se utilizó Programación Orientada a Objetos con clases como:

- Equipo
- Incidencia
- GestorEquipos
- Simulador
- Mantenimiento
- Registro (clase abstracta)
- RegistroReparado
- RegistroComplero
- Excepciones(clase abstracta)
- ArchivoInvalido
- FormatoInvalido
- OperacionIncostente
- Menu

Cada clase tiene una responsabilidad específica, lo que ayuda a mantener el código ordenado y entendible.

---

## Simulación
El sistema simula 30 días de operación.  
Cada día se realizan los siguientes pasos:

1. Los equipos se degradan
2. Se actualizan incidencias
3. Se calcula la prioridad
4. Se ordenan los equipos
5. Se seleccionan los 3 más críticos
6. Se les aplica mantenimiento
7. Nosotros como grupo decidimos que al hacerles un mantenimiento no se danen de nuevo, en el documento decia que a criterio de cada estudiante

---

## Cálculo de prioridad
Se usa la formula proporcionada en el documento del proyecto:

prioridad = (criticidad * 0.5) + (incidencias * 0.3) + (tiempo_inactivo * 0.2)

Esto permite decidir objetivamente qué equipo atender primero.

---

## Algoritmo
Merge Sort Manual

Para cumplir el requisito de implementar un algoritmo propio, se desarrolló manualmente un algoritmo Merge Sort para ordenar los equipos según su prioridad dinámica.

Métodos implementados
ordenarEquipos()
combinarEquipos()
---

## Polimorfismo
Se utilizó una clase abstracta `Registro` con clases derivadas como:

- registroCompleto
- registroReparados

Esto permite cambiar la forma de guardar datos sin afectar el resto del sistema.

---
## Patron de Diseno
Patrón Strategy

El proyecto implementa el patrón de diseño Strategy mediante la jerarquía:

Registro
├── registroCompleto
└── registroReparados

El objetivo del patrón es permitir cambiar dinámicamente la estrategia de persistencia utilizada por el sistema.

El simulador trabaja con la abstracción:

Registro* registro;

y puede utilizar distintas implementaciones mediante:

setRegistro()
Ventajas obtenidas
Bajo acoplamiento.
Mayor extensibilidad.
Reutilización de código.
Polimorfismo real.
Separación clara de responsabilidades.

Esto permite cambiar la forma de guardar datos sin afectar el resto del sistema.

---
## Manejo de errores
Se implementaron excepciones personalizadas para controlar errores como:

- archivos inválidos
- formatos incorrectos
- operaciones inconsistentes

---
## Persistencia en archivos de texto
Persistencia en archivos

El sistema utiliza archivos .txt para:

almacenar resultados,
generar evidencia verificable,
mantener trazabilidad completa de la simulación.
Se evidencia mas que todo en el registro de reparados
---
## Conclusión
El sistema cumple con los objetivos del proyecto, ya que:

- Toma decisiones automáticamente
- Simula un entorno real
- Aplica POO, algoritmos y manejo de errores

En general, se logró una solución funcional y bien estructurada.