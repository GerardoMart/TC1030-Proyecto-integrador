# TC1030 Proyecto Integrador - Gerardo Martínez Carbajal A01713474

Ya que el actual presidente del FC Barcelona está de vacaciones, ahora **tú eres el encargado de gestionar y manejar al equipo**, con sus limitantes, claro:  
no puedes despedir ni contratar a ningún jugador nuevo, pero **sí puedes aumentar sueldos, contratar directores técnicos y visualizar el rendimiento de los jugadores**
para el reporte que después le tendrás que entregar al presidente.

Tú te harás responsable de dichas gestiones mediante la información general que se te proporciona a través de clases.

---

##  Funcionalidad de las Clases

### `Barcelona`

Gestiona los datos generales del club, incluyendo información histórica (como año de fundación y estadio) y detalles de la temporada actual (partidos jugados, goles, director técnico).  
Genera métodos para visualizar estos datos y realizar modificaciones, como cambiar al entrenador.

---

### `Jugadores` (Clase Base)

Representa las características básicas de cualquier jugador del equipo, como:

- Nombre
- Posición
- Sueldo
- Duración del contrato

Proporciona funcionalidades genéricas como:

- Calcular el sueldo total
- Renovar el contrato

---

### `Titulares` (Hija de la clase Jugadores)

Se enfoca en los jugadores titulares, añadiendo estadísticas detalladas del rendimiento por partidos y que sean útiles para calcularlo:

- Goles
- Asistencias
- Minutos jugados

Incluye métodos para:

- Calcular el rendimiento por partido
- Analizar desempeño

---

### `Banca` (Hija de la clase Jugadores)

Maneja información específica de los jugadores suplentes, ya sea:

- Minutos jugados
- Horas de entrenamiento

Y te permite:

- Evaluar su disponibilidad para ser titulares
- Medir rendimiento en entrenamientos

---

### `Cantera` (Hija de la clase Jugadores)

Administra datos de jugadores jóvenes y en desarrollo del club, permitiendo gestionar su progreso y preparación para jugar en el primer equipo.

---

## Casos en los que podría fallar el proyecto
Este proyecto puede fallar si es que:
- Las entradas del usuario no sean válidas, como ingresar números envés de caractéres o, ingresando números negativos o 0 cuando se pidan valores numéricos.
- No tenemos en consideración su estructura base a la hora de modificar el código, ya sea por ejemplo
si una función externa modifica directamente Jugadores::nombre (por error a la hora de encapsular).

---

## ¿Cómo compilarlo?

Se requieren descargar todos los archivos .h (las clases del programa) que están en repositorio junto con el archivo llamado "main.cpp", una vez descargados, podemos compilar de la siguiente manera:

g++ main.cpp  -o (nombre del ejecutable a elección libre)

---

## Comentario

Para finalizar el programa, seleccione la opción "salir" del menú principal del código.

---

##  Autor

- Gerardo Martínez Carbajal A01713474

