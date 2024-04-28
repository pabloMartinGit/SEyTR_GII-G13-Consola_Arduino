# Videoconsola Multijugador por Bluetooth con Arduino Nano

Este proyecto consiste en la creación de dos videoconsolas basadas en Arduino que permiten a los jugadores interactuar y jugar en línea entre sí. Estas consolas están diseñadas para ser económicas, accesibles y fáciles de replicar.

## Descripción

El corazón de nuestro proyecto es una placa Arduino Nano, que alimenta todos los componentes y actúa como el principal procesador de los videojuegos. Aunque la consola está orientada a usuarios no expertos en programación, en las fases iniciales se requiere un conocimiento básico de informática para construir y poner en marcha la consola. Nuestro objetivo como desarrolladores ha sido realizar este proyecto en el menor tiempo posible y con un presupuesto ajustado.

## Materiales Necesarios

- Arduino Nano
- Pantalla OLED SH1106 (equivalente a SSD1306)
- Cuatro botones
- Cuatro resistencias de 10k Ohmios
- Joystick
- Módulo Bluetooth HC-05
- Zumbador activo
- Cable de wrapping
- Soldador de estaño y estaño

> **Nota:** Estos materiales son para una sola consola. Para construir un par de consolas, duplica estos materiales.

## Configuración y Montaje

### Esquema de Conexiones

Comenzamos con el montaje de la consola. A continuación, se adjunta un diagrama de conexiones.

![Esquema Final](https://github.com/pabloMartinGit/SEyTR_GII-G13-Consola_Arduino/assets/48807058/955f667d-6f7f-4055-a114-51614a3d26b5)

Este proyecto puede realizarse usando una protoboard o soldando las conexiones para una mayor durabilidad. Usaremos una batería de 9V para alimentar el Arduino y el resto de los componentes, que el Arduino convierte a 5V necesarios para otros componentes.

## Fotos de Nuestra Consola

### Prueba de Pantalla OLED

![Pantalla OLED](https://github.com/pabloMartinGit/SEyTR_GII-G13-Consola_Arduino/assets/48807058/85b2bf15-1c1e-4347-8c37-cb7489d68b25)

Aqui vemos una prueba de la pantalla OLED funcionando por primera vez.

---

### Carcasa de la Consola

![Carcasa de Madera](https://github.com/pabloMartinGit/SEyTR_GII-G13-Consola_Arduino/assets/48807058/29995c15-8fe0-499c-a443-fd8e739910df)

Para la carcasa de nuestra consola usamos una tabla de madera pintada con Spray negro.

---

### Consolas Encendidas

![Consolas Encendidas](https://github.com/pabloMartinGit/SEyTR_GII-G13-Consola_Arduino/assets/48807058/50f2eaac-1c07-491b-9f71-33cf719852ed)

En esta foto observamos las consolas encendidas y ejecutando el sketch adjunto a este repositorio.

## Software

### Configuración del Bluetooth

1. Después de montar ambas consolas, sigue estas instrucciones para configurar el módulo Bluetooth HC-05:
    1. Envía el comando `AT` desde el monitor serial del IDE de Arduino. Si recibes un `OK`, la comunicación es correcta.
    2. Utiliza `AT+ADDR?` para obtener la dirección MAC de cada módulo.
    3. Establece un Arduino como esclavo (`AT+ROLE=0`) y el otro como maestro (`AT+ROLE=1`).
    4. Usa `AT+CMODE=0` en ambos dispositivos.
    5. Vincula los dispositivos usando `AT+BIND=DIR_MAC_OTRO`.
    6. Tras reiniciar, verifica que la luz LED del módulo parpadee más despacio, indicando una conexión exitosa.

2. Carga el sketch del videojuego a cada Arduino usando un cable Micro USB. El juego comenzará automáticamente una vez que ambos dispositivos estén conectados.

### Librerías Necesarias

- Adafruit SH1106
- Adafruit GFX
- SoftwareSerial

## Uso

Enciende ambas consolas y espera a que se conecten automáticamente vía Bluetooth. Utiliza los botones y el joystick para jugar una vez que el juego haya comenzado.

## Contribución

Este proyecto es de código abierto y animamos a la contribución para mejorar tanto el diseño de las consolas como los juegos disponibles. Si tienes alguna idea o mejora, sigue estos pasos:

1. Haz fork del repositorio.
2. Crea una rama para tus cambios (`git checkout -b feature-nueva`).
3. Haz tus cambios y confírmalos (`git commit -am 'Añadir nueva característica'`).
4. Sube los cambios a la rama (`git push origin feature-nueva`).
5. Crea una nueva Pull Request.

## Problemas conocidos y soluciones

* *Exceso de memoria ocupada:* Uno de los principales problemas que tiene este proyecto sería la memoria dinámica del Arduino Nano. Gran parte del éxito de este proyecto es gracias a la optimización de código, variables y refactorizaciones que se han llevado a cabo a lo largo de nuestro software, observamos que si la memoria reservada a las variables dinámicas alcanza un número *>90%* la ejecución del videojuego fallaba por culpa de un desbordamiento de memoria
    * *POSIBLE SOLUCIÓN* -> Ampliación de memoria mediante el uso de una tarjeta SD. Si esto no fuera suficiente, sería considerable cambiar la placa de desarrollo a una más potente (p.e. Raspberry PI)
* *Pantalla significativamente pequeña*: La pantalla apenas ocupa una pulgada, esto es bueno respecto al consumo de nuestra batería de 9V, sin embargo, para el usuario puede resultar incomodo leer o observar ciertas partes de esta.
    * *POSIBLE SOLUCIÓN* -> Sustitución de pantalla a una más grande, sin embargo, esto también llevaría a la sustitución de la placa de desarrollo por otra más potente tal y como hemos comentado más arriba.
* *Bateria de poca duración*: El diseño de nuestra consola contempla la facilidad de sustitución de dicha batería, sin embargo, no es una batería que pueda durar un tiempo prolongado.
    * *POSIBLE SOLUCIÓN* -> Reemplazo de bateria alcalina por una de litio o similares, esto significaría añadir un módulo de carga adicional para recargar esta batería y evitar que haya que sustituirla cada cierto tiempo.
* *Poca retroalimentación de errores*: Esto ciertamente supone una preocupación mayor para nosotros como desarrolladores. Somos conscientes de que si, por ejemplo, una consola perdiese la conexión con la otra, el usuario no sería capaz de enterarse más que en el momento de que su partida no consigue cargar.
    * *POSIBLE SOLUCIÓN* -> Modificación del código y retroalimentación añadida, sin embargo, esto no es tan fácil como parece, pues si lo implementasemos la memoria de las variables subiría de manera considerable y es posible que nuestro videojuego dejase de funcionar directamente, por tanto habría que valorar si es algo necesario por completo.

## Versión

Esto se trata de una fase inicial de desarrollo y por tanto, no puede ser considerada para un producto final o comercializable. Sin embargo, el proyecto puede tener un futuro más amplio y podría ser escalado fácilmente si se dispone de tiempo y recursos de aquí en adelante.

## Contacto

Este proyecto ha sido desarrollado por tres alumnos de la Universidad Rey Juan Carlos de Móstoles para la asignatura SEyTR.

- Pablo Martín Cobo
- Javier Rubia Pérez
- Aitor Martín Gómez
