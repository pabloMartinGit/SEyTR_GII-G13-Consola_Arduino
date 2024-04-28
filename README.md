# Videoconsola multijugador por Bluetooth con Arduino Nano

Este proyecto consiste en la creación de dos videoconsolas basadas en Arduino que permiten a los jugadores interactuar y jugar en línea entre sí. Las consolas están diseñadas para ser económicas, accesibles y fáciles de replicar.

## Descripción

Nuestro proyecto está construido alrededor de una placa Arduino Nano que alimenta todos los componentes y es el principal procesador de los videojuegos, a continuación mostraremos los materiales necesarios para la construcción de tu propia consola multijugador. Aunque esta consola está orientada a un público que no sea experto en programación, o al menos ese es su espiritu, en estas fases iniciales se requiere de un mínimo de conocimiento de informática para construir la consola y para ponerla en marcha.
Nuestro objetivo principal como desarrolladores ha sido el de llevar este proyecto a cabo en el menor tiempo posible y con un presupuesto ajustado a nuestras necesidades, sin sobrepasarnos.

## Materiales necesarios

- Arduino Nano
- Pantalla OLED SH1106 (equiv. SSD1306)
- Cuatro botones
- Cuatro resistencias de 10k Ohmios
- Joystick
- Un modulo Bluetooth HC-05
- Un zumbador activo
- Cable de wrapping preferiblemente
- Soldador de estaño
- Estaño

Estos son los materiales necesarios para realizar una única consola, si se desea realizar el par de consolas se debe duplicar esta lista de materiales.

## Configuración y montaje

Comenzamos con el montaje de la consola, a continuación os adjuntamos un diagrama de conexiones.
![esquema final_bb](https://github.com/pabloMartinGit/SEyTR_GII-G13-Consola_Arduino/assets/48807058/955f667d-6f7f-4055-a114-51614a3d26b5)
Este proyecto se puede llevar a cabo usando una protoboard o si disponemos de estaño y un soldador, podemos realizar las conexiones de una forma más fiable y duradera, en nuestro caso, combinamos el uso de soldaduras con clemas de electricidad para asegurar que las conexiones son fiables y los cables no se desconectaban.
Ya que el espiritu de este proyecto es llevar a cabo una consola asequible, estaremos usando una pila de 9V para alimentar el Arduino y el resto de componentes, esta pila se conecta al Arduino y este se encarga de transformar esta tensión a 5V, los cuales necesitamos para alimentar la pantalla, el módulo BT, etc.

## Fotos de nuestra consola

![7ACB22D4-2052-496E-A910-486EDA9B39C9](https://github.com/pabloMartinGit/SEyTR_GII-G13-Consola_Arduino/assets/48807058/85b2bf15-1c1e-4347-8c37-cb7489d68b25)

Aqui vemos una prueba de la pantalla OLED funcionando por primera vez.

---

![41153B0E-98D6-41D1-AADB-AA57A93BDA54](https://github.com/pabloMartinGit/SEyTR_GII-G13-Consola_Arduino/assets/48807058/29995c15-8fe0-499c-a443-fd8e739910df)

Para la carcasa de nuestra consola usamos una tabla de madera pintada con Spray negro.

---

![consolas](https://github.com/pabloMartinGit/SEyTR_GII-G13-Consola_Arduino/assets/48807058/50f2eaac-1c07-491b-9f71-33cf719852ed)

En esta foto observamos las consolas encendidas y ejecutando el sketch adjunto a este repositorio.

## Software

#### Instrucciones
1. Una vez que tengamos montadas ambas consolas, el módulo BT estará desconfigurado, esta será una de las tareas que tenemos que llevar a cabo. Dentro de este repositorio tenemos un documento que muestra las diferentes instrucciones que se pueden usar desde el monitor serial del IDE de Arduino para comunicarnos con el módulo bluetooth HC-O5.
   1. Escribiremos el comando "AT", si el monitor serial nos devuelve un OK confirmaremos que estamos comunicandonos con el HC-05, si esto no sucede, debemos revisar las conexiones y ver que estamos en la velocidad correcta de transmisión de datos.
   2. Escribimos el comando "AT+ADDR?" en ambos dispositivos, esto nos devolverá la dirección MAC de cada módulo, lo apuntamos para más adelante.
   3. En uno de los Arduinos escribiremos: "AT+ROLE=0", este será nuestro Arduino esclavo. En el otro escribimos "AT+ROLE=1", este pasará a ser el maestro.
   4. En ambos terminales escribimos: "AT+CMODE=0"
   5. A continuación escribiremos en cada Arduino la dirección del Arduino contrario: "AT+BIND=DIR_MAC_OTRO"
   6. Al resetear ambas placas observamos como al poco tiempo la luz LED de cada módulo que parpadeaba de forma rápida y continua ahora parpadea más despacio, esto confirmará que la conexión está bien hecha entre ambos modulos.
2. Cargamos el sketch de Star Wars en cada uno de los Arduino mediante un cable Micro USB a USB mediante la aplicación de ARDUINO IDE. Si no disponemos de esta aplicación, disponemos de un script en Python que sirve para cargar ficheros compilados en el puerto que deseamos.
3. ¡A jugar!

#### Librerias necesarias
* Adafruit SH1106
* Adafruit GFX
* SoftwareSerial

#### Código

Dentro de este repositorio podrás encontrar el sketch que contiene el programa de Arduino que contiene el videojuego el cual hemos añadido la funcionalidad Bluetooth, para ejecutar correctamente este videojuego debes tener dos consolas encendidas al mismo tiempo y que estas estén vinculadas por Bluetooth, solo de esta forma arrancará la partida.
Una de las ventajas de este proyecto es que una vez configurados los módulos BT como hemos hecho en *Instrucciones* bastará con cargar el mismo programa tanto en uno como en otro, no hay necesidad de diferenciar nunca más entre Arduino maestro y esclavo.

## Uso

Una vez que las consolas están configuradas y el software está cargado, el funcionamiento es bastante sencillo. Para comenzar a jugar, simplemente enciende ambas consolas. El sistema automáticamente buscará y se conectará a la otra consola mediante Bluetooth. Asegúrate de que ambas consolas estén dentro del rango de conexión Bluetooth para evitar desconexiones.

### Iniciar un juego

- Enciende ambas consolas.
- Espera a que se conecten automáticamente vía Bluetooth (esto puede tardar unos segundos).
- Una vez conectadas, el juego cargado se iniciará automáticamente.
- Utiliza los botones y el joystick para controlar el juego en cada consola.

## Contribuir

Este proyecto es de código abierto y animamos a otros desarrolladores a contribuir y mejorar el diseño de las consolas y los juegos disponibles. Si tienes alguna idea o mejora, por favor sigue estos pasos para contribuir:

1. Fork el repositorio.
2. Crea una nueva rama para tus cambios (`git checkout -b mi-nueva-caracteristica`).
3. Haz tus cambios y haz commit de ellos (`git commit -am 'Añadir alguna característica'`).
4. Push a la rama (`git push origin mi-nueva-caracteristica`).
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

