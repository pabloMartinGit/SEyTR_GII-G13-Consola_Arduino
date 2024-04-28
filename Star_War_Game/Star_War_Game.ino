#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Fonts/FreeSans9pt7b.h>
#include <Adafruit_SH1106.h>
#include <SoftwareSerial.h>

#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 64  // OLED display height, in pixels
#define VERTICAL_JOYSTICK 1

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET -1                 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SH1106 display(OLED_RESET);  //use SSD1306 oled replace -> Adafruit_SSD1306 display(OLED_RESET);






const int c = 261;
const int d = 294;
const int e = 329;
const int f = 349;
const int g = 391;
const int gS = 415;
const int a = 440;
const int aS = 455;
const int b = 466;
const int cH = 523;
const int cSH = 554;
const int dH = 587;
const int dSH = 622;
const int eH = 659;
const int fH = 698;
const int fSH = 740;
const int gH = 784;
const int gSH = 830;
const int aH = 880;

const unsigned char PROGMEM dioda16[] = {

  0x00, 0x00, 0x00, 0x00, 0x1C, 0x00, 0x3F, 0xF0, 0x3C, 0x00, 0x3C, 0x00, 0xFF, 0x00, 0x7F, 0xFF,
  0x7F, 0xFF, 0xFF, 0x00, 0x3C, 0x00, 0x3C, 0x00, 0x1F, 0xF0, 0x1C, 0x00, 0x00, 0x00, 0x00, 0x00

};

const unsigned char PROGMEM storm[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x7F, 0xFE, 0x00, 0x00, 0x00, 0x07, 0x80, 0x01, 0xE0, 0x00, 0x00, 0x0C,
  0x00, 0x00, 0x20, 0x00, 0x00, 0x18, 0x00, 0x00, 0x18, 0x00, 0x00, 0x30, 0x00, 0x00, 0x04, 0x00,
  0x00, 0x20, 0x00, 0x00, 0x04, 0x00, 0x00, 0x20, 0x00, 0x00, 0x04, 0x00, 0x00, 0x60, 0x00, 0x00,
  0x02, 0x00, 0x00, 0x40, 0x00, 0x00, 0x02, 0x00, 0x00, 0x40, 0x00, 0x00, 0x01, 0x00, 0x00, 0x40,
  0x00, 0x00, 0x01, 0x00, 0x00, 0x40, 0x00, 0x00, 0x01, 0x00, 0x00, 0x7F, 0xE0, 0x00, 0x01, 0x00,
  0x00, 0x7F, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x7F, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0xD7, 0xFF, 0xFF,
  0xE1, 0x00, 0x01, 0xBF, 0xFC, 0x1F, 0xFA, 0x80, 0x01, 0xBF, 0xF1, 0xCF, 0xFA, 0x80, 0x01, 0x3F,
  0xC2, 0x37, 0xF7, 0x80, 0x01, 0xEF, 0x9C, 0x01, 0xE7, 0xC0, 0x01, 0xE0, 0x70, 0x06, 0x06, 0x80,
  0x01, 0xE0, 0xC0, 0x03, 0x06, 0x80, 0x01, 0xFF, 0x80, 0x01, 0xFF, 0x80, 0x01, 0xF8, 0x00, 0x00,
  0x1D, 0xC0, 0x03, 0x70, 0x00, 0x80, 0x0C, 0x60, 0x05, 0xB0, 0x07, 0xF0, 0x08, 0x90, 0x09, 0x10,
  0x1F, 0xF8, 0x09, 0xD0, 0x0B, 0x90, 0x1F, 0x7C, 0x03, 0xF0, 0x0F, 0xC0, 0xFC, 0x0F, 0x07, 0x90,
  0x0D, 0x43, 0xC0, 0x03, 0x07, 0x90, 0x05, 0x64, 0x00, 0x00, 0xCF, 0x10, 0x07, 0xFC, 0x00, 0x00,
  0x26, 0x10, 0x01, 0x80, 0x00, 0x00, 0x10, 0x20, 0x01, 0x00, 0x00, 0x00, 0x0E, 0x40, 0x01, 0x80,
  0x07, 0xF0, 0x01, 0x80, 0x00, 0x80, 0x07, 0xC8, 0x00, 0x80, 0x00, 0x80, 0x0B, 0xE8, 0x00, 0x80,
  0x00, 0x87, 0x97, 0xE9, 0xE0, 0x80, 0x00, 0x87, 0xDF, 0xEF, 0xA0, 0x80, 0x00, 0x4B, 0xFF, 0xFF,
  0xA0, 0x80, 0x00, 0x6B, 0xDF, 0xFB, 0xA3, 0x00, 0x00, 0x24, 0x97, 0xE8, 0x24, 0x00, 0x00, 0x1E,
  0x1F, 0xC0, 0x2C, 0x00, 0x00, 0x07, 0xF8, 0x1F, 0xF0, 0x00, 0x00, 0x00, 0x0F, 0xF8, 0x00, 0x00
};

SoftwareSerial BT(8, 9);
int receivedLevel;
int receivedScore;

void setup() {

  BT.begin(9600);
  pinMode(6, INPUT);

  display.begin(SH1106_SWITCHCAPVCC, 0x3C);
  display.display();
  display.clearDisplay();
  display.setTextSize(0);
  display.drawBitmap(6, 11, storm, 48, 48, 1);
  display.setFont(&FreeSans9pt7b);
  display.setTextColor(WHITE);
  display.setCursor(65, 14);
  display.println("URJC");
  display.setFont();
  display.setCursor(65, 17);
  display.setTextSize(0);
  display.println("vs");
  display.setFont(&FreeSans9pt7b);
  display.setCursor(65, 39);
  display.println(" Death");
  display.setFont();
  display.setCursor(65, 42);
  display.println("star ");
  display.setCursor(2, 0);
  display.println("Waiting BT");
  display.setTextSize(0);

  display.setCursor(65, 20);

  display.display();



  display.setFont();
  beep(a, 500);
  beep(a, 500);
  beep(a, 500);
  beep(f, 350);
  beep(cH, 150);
  beep(a, 500);
  beep(f, 350);
  beep(cH, 150);
  beep(a, 650);

  delay(500);

  delay(500);
  while (!BT.available()) {
    BT.write("Ready");
  }
}

int metx = 0;
int mety = 0;
int exists = 0;
int nep = 8;
int direction = 0;
int go = 0;
int rx = 95;
int ry = 0;
int rx2 = 95;
int ry2 = 0;
int rx3 = 95;
int ry3 = 0;
int points = 0;

int bulletSpeed = 3;  //speed of bullet
int bullets = 1;
int min = 600;
int max = 1200;
int diameter = 10;

int rx4 = 95;
int ry4 = 0;
int lives = 5;
int begin = 0;
int shot = 0;
int level = 1;
int centar = 95;
unsigned long initialTime = 0;
unsigned long selectedTime = 0;
unsigned long currentTime = 0;
unsigned long auxTime = 0;
int position = 30;

void loop() {

  if (go == 0) {
    display.clearDisplay();

    display.drawPixel(50, 30, 1);
    display.drawPixel(30, 17, 1);
    display.drawPixel(60, 18, 1);
    display.drawPixel(55, 16, 1);
    display.drawPixel(25, 43, 1);
    display.drawPixel(100, 43, 1);
    display.drawPixel(117, 52, 1);
    display.drawPixel(14, 49, 1);
    display.drawPixel(24, 24, 1);
    display.drawPixel(78, 36, 1);
    display.drawPixel(80, 57, 1);
    display.drawPixel(107, 11, 1);
    display.drawPixel(150, 11, 1);
    display.drawPixel(5, 5, 1);
    display.drawPixel(8, 7, 1);
    display.drawPixel(70, 12, 1);
    display.drawPixel(10, 56, 1);
    display.drawPixel(70, 25, 1);

    if (begin == 0) {
      initialTime = millis();
      selectedTime = random(400, 1200);
      begin = 1;
    }
    currentTime = millis();


    if ((currentTime - auxTime) > 50000) {
      auxTime = currentTime;
      level = level + 1;

      bulletSpeed = bulletSpeed + 1;
      if (level % 2 == 0) {
        bullets = bullets + 1;
        diameter = diameter - 1;
      }
      min = min - 50;
      max = max - 50;
    }



    if ((selectedTime + initialTime) < currentTime) {
      begin = 0;
      shot = shot + 1;
      if (shot == 1) {
        rx = 95;
        ry = nep;
      }
      if (shot == 2) {
        rx2 = 95;
        ry2 = nep;
      }
      if (shot == 3) {
        rx3 = 95;
        ry3 = nep;
      }
      if (shot == 4) {
        rx4 = 95;
        ry4 = nep;
      }
    }

    if (shot > 0) {
      display.drawCircle(rx, ry, 2, 1);
      rx = rx - bulletSpeed;
    }

    if (shot > 1) {
      display.drawCircle(rx2, ry2, 1, 1);
      rx2 = rx2 - bulletSpeed;
    }

    if (shot > 2) {
      display.drawCircle(rx3, ry3, 4, 1);
      rx3 = rx3 - bulletSpeed;
    }

    if (shot > 3) {
      display.drawCircle(rx4, ry4, 2, 1);
      rx4 = rx4 - bulletSpeed;
    }

    if ((analogRead(VERTICAL_JOYSTICK) < 300) && position >= 2) {
      position = position - 2;
    }

    if ((analogRead(VERTICAL_JOYSTICK) > 700) && position <= 46) {
      position = position + 2;
    }

    if (digitalRead(6) == 1 && exists == 0) {
      exists = 1;
      metx = 6;
      mety = position + 8;
      tone(12, 1200, 20);
    }

    if (exists == 1) {
      metx = metx + 8;

      display.drawLine(metx, mety, metx + 4, mety, 1);
    }

    display.drawBitmap(4, position, dioda16, 16, 16, 1);
    display.fillCircle(centar, nep, diameter, 1);
    display.fillCircle(centar + 2, nep + 3, diameter / 3, 0);

    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(33, 57);
    display.println("score:");
    display.setCursor(68, 57);
    display.println(points);

    display.setCursor(33, 0);
    display.println("lives:");
    display.setCursor(68, 0);
    display.println(lives);

    display.setCursor(110, 0);
    display.println("L:");

    display.setCursor(122, 0);
    display.println(level);

    display.setCursor(108, 57);
    display.println(currentTime / 1000);
    display.display();

    if (metx > 128) exists = 0;

    if (direction == 0) {
      nep = nep + bullets;
    } else {
      nep = nep - bullets;
    }

    if (nep >= (64 - diameter))
      direction = 1;
    if (nep <= diameter)
      direction = 0;

    if (mety >= nep - diameter && mety <= nep + diameter)
      if (metx > (centar - diameter) && metx < (centar + diameter)) {
        metx = -20;
        tone(12, 500, 20);
        points = points + 1;
        exists = 0;
      }

    int newPosition = position + 8;
    if (ry >= newPosition - 8 && ry <= newPosition + 8)
      if (rx < 12 && rx > 4) {
        rx = 95;
        ry = -50;
        tone(12, 100, 100);
        lives = lives - 1;
      }

    if (ry2 >= newPosition - 8 && ry2 <= newPosition + 8)
      if (rx2 < 12 && rx2 > 4) {
        rx2 = -50;
        ry2 = -50;
        tone(12, 100, 100);
        lives = lives - 1;
      }

    if (ry3 >= newPosition - 8 && ry3 <= newPosition + 8)
      if (rx3 < 12 && rx3 > 4) {
        rx3 = -50;
        ry3 = -50;
        tone(12, 100, 100);
        lives = lives - 1;
      }

    if (ry4 >= newPosition - 8 && ry4 <= newPosition + 8)
      if (rx4 < 12 && rx4 > 4) {
        rx4 = 200;
        ry4 = -50;
        shot = 0;
        tone(12, 100, 100);
        lives = lives - 1;
      }

    if (rx4 < 1) {
      shot = 0;
      rx4 = 200;
    }

    if (lives == 0)
      go = 1;
  }

  if (go == 1) {
    if (lives == 0) {
      tone(12, 200, 300);
      delay(300);
      tone(12, 250, 200);
      delay(200);
      tone(12, 300, 300);
      delay(300);
      lives = 5;
    }

    display.clearDisplay();

    display.setFont();
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(20, 25);
    display.println("Waiting");
    display.display();

    String winner = "";
    String receivedMsg = "";
    receivedLevel = -1;
    receivedScore = -1;
    while (receivedScore == -1) {
      while (!receivedMsg.length() || receivedMsg.charAt(0) != '$') {
        if (BT.available()) {
          receivedMsg = BT.readStringUntil('\n');
        }
        String message = "$" + String(level) + "," + String(points);
        BT.println(message);
        delay(500);
      }

      // Procesar el mensaje recibido
      int separatorIndex = receivedMsg.indexOf(',');
      if (separatorIndex != -1) {
        receivedLevel = receivedMsg.substring(1, separatorIndex).toInt();
        receivedScore = receivedMsg.substring(separatorIndex + 1).toInt();
      }
    }


    while (BT.available() > 0) {
      BT.read();  // Leer y descartar los datos disponibles en el buffer
    }

    while (digitalRead(6) != 1) {
      display.clearDisplay();
      display.setFont();
      display.setTextSize(2);
      display.setTextColor(WHITE);
      display.setCursor(7, 20);
      display.println("GAME OVER!");
      display.setCursor(14, 40);
      display.setTextSize(1);
      display.println("Press OK to start");
      display.display();
      delay(2500);

      display.clearDisplay();
      display.setFont();
      display.setTextSize(1);
      display.setCursor(25, 0);
      display.println("Final Results");
      display.setCursor(0, 10);
      display.println("Your score: ");
      display.setCursor(80, 10);
      display.println(points);
      display.setCursor(0, 20);
      display.println("Opponent's score: ");
      display.setCursor(110, 20);
      display.println(receivedScore);

      if (points > receivedScore) {
        display.setCursor(30, 40);
        display.setTextSize(1);
        display.println("You won!");
      } else if (points < receivedScore) {
        display.setCursor(30, 40);
        display.setTextSize(1);
        display.println("You lost!");
      } else {
        display.setCursor(30, 40);
        display.setTextSize(1);
        display.println("It's a draw!");
      }

      display.display();
      delay(2500);  // Mostrar el resultado durante 5 segundos.
    }


    while (BT.available() > 0) {
      BT.read();  // Leer y descartar los datos disponibles en el buffer
    }

    tone(12, 280, 300);
    delay(300);
    tone(12, 250, 200);
    delay(200);
    tone(12, 370, 300);
    delay(300);
    ponovo();
  }
}

void ponovo() {
  metx = 0;
  mety = 0;
  exists = 0;
  nep = 8;
  direction = 0;
  go = 0;
  rx = 95;
  ry = 0;
  rx2 = 95;
  ry2 = 0;
  rx3 = 95;
  ry3 = 0;
  points = 0;

  bulletSpeed = 3;
  bullets = 1;
  min = 600;
  max = 1200;
  diameter = 12;

  rx4 = 95;
  ry4 = 0;
  lives = 5;
  begin = 0;
  shot = 0;
  level = 1;
  initialTime = 0;
  selectedTime = 0;
  currentTime = 0;
  auxTime = 0;
}


void beep(int note, int duration) {
  //Play tone on buzzerPin
  tone(12, note, duration);
  delay(duration);
  noTone(12);

  delay(50);
}
