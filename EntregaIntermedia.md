# Practica Intermedia - SIM
### Pablo Marcos Serrano

## Cómo navegar la práctica

- 1 - Escena usada para generadores de partículas
- 2 - Escena usada para la práctica de fuerzas
- 3 - Escena usada para la práctica de fuerzas. Se puede disparar
- 4 - Escena de 'Lobby' la ejecución lanza esta escena al inicio
- 5 - Escena de juego. En esta escena se puede disparar y causar una explosión
- V - Disparo de flecha
- B - Disparo de otro tipo de flecha
- N - Disparo de bala
- M - Causar una explosion 


## Apartado A

La clase párticula hereda de una clase abstrracta 'Entidad'. Originalmente la clase `Entity` era una clase casi completamente abstracta, pero debido a las limitaciones se han tenido que mover algunos parámetros de `Particle` a la clase `Entity`.
Por esto, algunos métodos se encuentran en diferentes clases en vez dee estar todo unificado. Por falta de tiempo, no se ha podido arreglar esto, pero estará solucionado para la siguiente entrega.

### A-1

Se encuentran en `Particle.cpp` líneas 119-154. Están incluidos los tres métodos de integración pero se usa Semi-Explícito porque es más estable.

### A-2

Se encuentra en `Particle.h`línea 32, aunque será movido a Entity como antes mencionado para reaprovecharlo en sólido-rígido.

Las partículas con distinta masa se ve en `main.cpp`, líneas 242-307, o incluso en la creación de las diversas escenas.

### A-3

Recibir fuerzas se encuentra en `Entity.cpp` líneas 9-13.

Aplicar esas fuerzas se encuentra en `Particle.h`, líneas 66-69.

Luego se aplica la fuerza como aceleración en los métodos de integración.

## Apartado B

No hay mucha diferencia entre un proyectil y una partícula ya que no hay un parámetro 'energía' (se calcularía mediante sacar la velocidad y la masa), ya que no tenmos nada a lo que aplicarle esa energía sin tener colisiones.

Los proyectiles se crean cuando pùlsas V, B o N en `main.cpp`, líneas 242-307.

## Apartado C

`EntityManager` y `Scene` toman la carga. `EntityManager` se encarga de todo el manejo de todo tipo de entidades (que por ahora son solo parículas, pero también generadores). Se encarga dee crear, updatear, y borrar entidades. `Scene` mientras tanto tiene un `EntityManager`, así como una lista de `ForceGen`, los generadores de fuerzas; y es quién se ocupa de llamar al `EntityManager` asociado, aplicando las fuerzas y llamando al update.

## Apartado D

### D-1

El modelo está guardado en `Generator.h` línea 24. Se genera en `Generator.cpp` en líneas 37-49.

### D-2

Las clases `Gausian` y `Uniform`, que heredan de `Generator`, se encargan de generar las partículas. 

### D-3

Como mencionado en el apartado C, `EntityManager` se ocupa de gestionar los generadores. En `EntityManager.cpp` líneas 79-91, y se añade a la gestión de entidades.

## Apartado E

### E-1

El cálculo se realiza de manera independiente para cada partícula. 

Debido a la arquiteectura elegida, la partícula no llama a los generadores de fuerzas, si no que `Scene` le entrega a su `EntityManager` cada generador de fuerzas, y para cada uno de ellos `EntityManager` le pasa cada entidad para que el generador le aplique las fuerzas.

### E-2

Como mencionado en el apartado anterior, por como está la arquitectura, cada partícula es afectada por todas las fuerzas de las que esté en rango.

### E-3

Est apartado no está completo. Por culpa de la arquitectura, no se me ocurrió una forma de filtrar en específico que afectasen ciertas fuerzas a ciertas entidades. La razón es que cuando hice la arquitectura de `EntityManager` y posteriormente de `Scene`, pensé en que `EntityManager` fuera único. 

Esto ha hecho que especificar 'grupos' de partículas no sea tan simple. Probablemente pueda hacer una clase grupo que heredase de entidad y que contenga en ella entidades, y que sea estas clases las que se guarden información de qué fuerzas usar, pero eso lo ví a menos de una semana de la entrega final y no había tiempo de cambiarlo. 

### E-4

Se pueden apreciar los distintos generados en `GameScene.cpp`, donde se crean objetos de las clases `Explosion` y `Torbellino`. Otra fuerza (aunque no usada) está en la clase `Wind`.

