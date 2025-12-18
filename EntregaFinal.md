# Practica Final - SIM
### Pablo Marcos Serrano

## Cómo navegar la práctica
Los números del 1 al 8 permitirán acceder a apartados de las prácticas semanales. Para acceder a los que no estaban en el proyecto intermedio, sería la tecla `6` para muelles, `7` para flotación y `8` para sólido-rígido.

Para comenzar el 'juego' como tal de la práctica final hay que presional el `9`. En las escenas de juego, te mueves a los lados con `A` y `D` y disparas con `W`. Al terminar un nivel pasas al siguiente. A lo largo de estos niveles se pueden apreciar los distintos apartados requiridos.

## Apartado A

La temática del juego es intentar hacer un juego similar al Angry Birds pero en 3D. El objetivo en cada nivel es eliminar a los cerdos golpeandoles o simplemente haciendo que se caigan (son alérgicos a la hierba). 

## Apartado B
![Diagrama de clases](ClassDiagram.png)

(La imagen no va a aparecer debido a que solo me deja adjuntar un archivo en la entrega. Si se abre este documento en el repositorio de GitHub see deberá de poder ver la imagen)

## Apartado C

- **Euler Semi-Implicito** para las partículas. Primero cambia la velocidad sumandole a cada componente la velocidad en el frame anterior, la aceleración fija por el tiempo (después de añadir fuerzas solo se usa para gravedad estática); y la fuerza multiplicada por el timpo y la inversa de la masa. A eso se le aplica un damping.

- **Fuerza del viento** que se aplica tanto a partículas como a sólidos. Esta fórmula tiene en cuenta la diferencia de velocidades entre el objeto a aplicar la fuerza y la velocidad del viento, así como el rozamiento que aplicaría el viento. Para sólidos aplican la fuerza *1000 debido a problemas de escalas, ya que estaban diseñados para particulas de masa ambigua.

- **Explosiones**. Tienen en cuenta la distancia entre el objeto y el centro de la explosión y aplican una fuerza que se va debilitando según pasa el tiempo desde que comenzó la explosión. Al igual que el viento, aplican la fuerza *1000 a los sólidos.

- **Fuerza de flotación**. Uso una misma fórmula para calcular el porcentaje sumergido de cada objeto, independientemente de su forma. Una vez calculado el porcentaje se calcula la fuerza a aplicar dependiendo del volumen de líquido desplazada (el porcentaje de inmersion * el volumen del objeto), y el peso del líquido (su densidad por la gravedad). A diferencia de los otros generadores, no necesita modificar su aplicación de fuerzas ya que está directamente ligada a la densidad del líquido.

## Apartado D

(Pequeño aparte porque no comprendo del todo que significa esto. Sé que un compañero ha preguntado y me ha comentado lo que le habeis contestado, pero si es sobre efectos físicos estos se explican antes y después; y volver a eescribirlo todo de nuevo sería gastar tiempo en algo que podría ser redundante.)

## Apartado E

### Fórmulas Usadas

- Euler Semi-Implicito: `Particle.cpp` líneas 121-130.
- Fuerza del viento: `Wind.cpp` líneas 39-61.
- Explosiones: `Explosive.cpp` líneas 26-52.
- Fuerza de flotación: `Float.cpp` líneas 30-67.

### Dos generadors de partículas distintos

Se ha usado un fireworks al final de todos los niveles (`Level.cpp` líneas 40-59). Se ha usado un generador de particulas Gausiano para el viento en el segundo nivel (`Level2.cpp` líneas 26-31). Además, se ha usado un tercer generador, uno uniforme en este caso, en el tercer nivel para simular la lluvia (`Level3.cpp` líneas 12-17).

### Gestión de creación y destrucción de instancias (las partículas no pueden estar indefinidamente en escena, teniendo límites espaciotemporales de existencia).

Toda la gestión se lleva a cabo en la clase `EntityManager`. Hay diversos métodos para crear, un update, gestión de fuerzas y geestión de entidades a destruir una vez concluido el bucle de actualización.

### Destrucción de todos los elementos al salir de la escena.

Se lleva a cabo en la clase `Scene`. En concreto descargar una escena se lleva a cabo en `Scene.cpp` líneas 28-38.

### Un sistema de sólidos rígidos.

Está todo contenido en el archivo `SolidEnt.h` y `SolidEnt.cpp`, que contienen dicha clase así como sus hijos para objetos dinámicos y estáticos. Su gestión también se lleva a cabo en la clase `EntityManager`.

### Sólidos rígidos con distinto tamaño, forma, masa y tensor de inercia.

En los métodos loadScene() de `Level1`, `Level2`, `Level3` y su clase base `Level` se puede apreciar el uso de solidos rígidos con tales characteerísticas, así como en el archivo `GameSolids` que contiene las clases para los enemigos, los barriles y las balas.

### Dos generadores de fuerzas diferentes (sin contar muelles), cada uno con su fórmula y sus restricciones de aplicación.

Se usan explosiones en los barriles explosivos (clase `Explosive`, `GameSolids.cpp` líneas 30-43; y `Level1.cpp` líneas 31-34), así como viento en el segundo nivel (`Level2.cpp` línea 24).

### Interacción con el usuario a través del teclado y/o ratón.

Se llevan a cabo en `main.cpp` y van descendiendo a la escena como eventos cuando es necesario.

### Un ejemplo de muelle o de flotación.

Hay un ejemplo de flotación en el tercer nivel (`Level3.cpp` en la línea 20).

## Apartado F

### Objetivo del juego

El objetivo en cada nivel deel juego es eliminar a todos los cerdos (orbes verdes) disparándoles o haciéndoles tocar el suelo.

### Navegación entre escenas

- Para la  navegación entre escenas de la Entrega intermedia, vease dicho documento

- Para la navegación entre escenas de practicas posteriores:
    - 6 - Escena con ejemplos de muelles
    - 7 - Escena con ejemplos de flotación
    - 8 - Escena con ejemplos de sólido-rígido

- Para acceder al juego de la práctica final, pulsa tecla 9

### Interacción con el juego

- W - Disparar en dirección de la cámara
- A - Desplazarte a la izquierda (por un raíl)
- D - Desplazarte a la derecha (por un raíl)
- Click + Mover Ratón - Mover la cámara

## Apartado G

EL único 'extra' que se ha añadido (con respecto a lo enseñado en clase y las prácticas de laboratorio) es el hecho de que hay colisiones customizables. Se usa la base de sólidos-rígidos de physx, pero se añade una clase que hereda para tener callbacks propios como que un enemigo muera al tocar el suelo o que un barril explote cuando le da una bala.