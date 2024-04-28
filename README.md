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

### Software




## Código

```cpp
// Código fuente básico para Arduino aquí
// Puede incluir snippets o enlaces a repositorios si el código es muy largo
