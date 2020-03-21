// IMPORTANT: Adafruit_TFTLCD LIBRARY MUST BE SPECIFICALLY
// CONFIGURED FOR EITHER THE TFT SHIELD OR THE BREAKOUT BOARD.
// SEE RELEVANT COMMENTS IN Adafruit_TFTLCD.h FOR SETUP.

// Modified for SPFD5408 Library by Joao Lopes
// and touch instead serial !!!!
// Too much modifications, so not: begins e ends
// Version 0.9.2 - Rotation for Mega and screen initial

#include <SPFD5408_Adafruit_GFX.h>    // Core graphics library
#include <SPFD5408_Adafruit_TFTLCD.h> // Hardware-specific library
#include <SPFD5408_TouchScreen.h>     // Touch library

// The control pins for the LCD can be assigned to any digital or
// analog pins...but we'll use the analog pins as this allows us to
// double up the pins with the touch screen (see the TFT paint example).
#define LCD_CS A3 // Chip Select goes to Analog 3
#define LCD_CD A2 // Command/Data goes to Analog 2
#define LCD_WR A1 // LCD Write goes to Analog 1
#define LCD_RD A0 // LCD Read goes to Analog 0

#define LCD_RESET A4 // Can alternately just connect to Arduino's reset pin

// When using the BREAKOUT BOARD only, use these 8 data lines to the LCD:
// For the Arduino Uno, Duemilanove, Diecimila, etc.:
//   D0 connects to digital pin 8  (Notice these are
//   D1 connects to digital pin 9   NOT in order!)
//   D2 connects to digital pin 2
//   D3 connects to digital pin 3
//   D4 connects to digital pin 4
//   D5 connects to digital pin 5
//   D6 connects to digital pin 6
//   D7 connects to digital pin 7
// For the Arduino Mega, use digital pins 22 through 29
// (on the 2-row header at the end of the board).

// Assign human-readable names to some common 16-bit color values:
#define	BLACK   0x0000
#define	BLUE    0x001F
#define	RED     0xF800
#define	GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

Adafruit_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);
// If using the shield, all control and data lines are fixed, and
// a simpler declaration can optionally be used:
// Adafruit_TFTLCD tft;

// Calibrates value

#define SENSIBILITY 300
#define MINPRESSURE 10
#define MAXPRESSURE 1000

//These are the pins for the shield!
#define YP A1
#define XM A2
#define YM 7
#define XP 6

// Calibrate values

#define TS_MINX 125
#define TS_MINY 85
#define TS_MAXX 965
#define TS_MAXY 905

// Init TouchScreen:

TouchScreen ts = TouchScreen(XP, YP, XM, YM, SENSIBILITY);

void setup(void) {

  tft.reset();
  tft.begin(0x9341); // SDFP5408

  tft.setRotation(0); // Need for the Mega, please changed for your choice or rotation initial

  // Border

  // drawBorder();

  // Initial screen

  /*
  tft.setCursor (55, 50);
  tft.setTextSize (3);
  tft.setTextColor(RED);
  tft.println("LEP DAN");
  tft.setCursor (65, 85);
  tft.println("VAM ZELI");
  tft.setCursor (25, 150);
  tft.setTextSize (2);
  tft.setTextColor(BLACK);
  tft.println("Miha Stele");


  tft.setCursor (55, 100);
  tft.setTextSize (3);
  tft.setTextColor(RED);
  tft.println(tft.height());

  tft.setCursor (55, 120);
    tft.setTextSize (3);
    tft.setTextColor(GREEN);
  tft.println(tft.width());
  */


  drawBorders();


} // ADDED MAN

  // Wait touch
  /*

  waitOneTouch(true);

  // Draw border

  drawBorder();

  tft.setTextSize (1);
  tft.setTextColor(BLACK);
  tft.setCursor (20, 80);
  tft.println("This is a test of the rotation");
  tft.setCursor (20, 100);
  tft.println("capabilities of the TFT library!");
  tft.setCursor (20, 160);
  tft.println("Touch to advance each test");

  // Wait touch

  waitOneTouch(true);

}

*/

void loop(void) {

  // Tests

	/*
  //rotatePixel();
  rotateLine();
  rotateFastline();
  rotateDrawrect();
  rotateFillrect();
  rotateDrawcircle();
  rotateFillcircle();
  rotateText();

  // Complete

  drawBorder();

  tft.setCursor (35, 50);
  tft.setTextSize (3);
  tft.setTextColor(RED);
  tft.println("Completed");

  waitOneTouch(true);
  */

}


void drawBorders(){
	//const uint16_t x = 10;
	//const uint16_t y = 10;
	//const uint16_t h = 110;
	//const uint16_t w = 70;
	//tft.fillRect(x, y, w, tft.height(), BLACK);
	//tft.fillRect(10, 120, tft.width(), h, BLACK);
	const uint16_t OFF_X = 10;
	const uint16_t OFF_Y = 5;

	// x, y, w, h, color
	tft.fillRect(0, 0, tft.width(), 5, BLACK); // top border
	tft.fillRect(0, tft.height()-5, tft.width(), 5, BLACK); // bottom border
	tft.fillRect(0, 0, 10, tft.height(), BLACK); // left border
	tft.fillRect(tft.width()-10, 0, 10, tft.height(), BLACK); // right border

	tft.fillRect(0, OFF_Y + 100, tft.width(), 5, BLACK); //
	tft.fillRect(0, OFF_Y + 200, tft.width(), 5, BLACK); //

	tft.fillRect(OFF_X + 70, 0, 5, tft.height(), BLACK); //
	tft.fillRect(OFF_X + 140, 0, 5, tft.height(), BLACK); //


}



/*
void rotateText() {
  for (uint8_t i=0; i<4; i++) {
    tft.fillScreen(WHITE);

    tft.setCursor(0, 30);
    tft.setTextColor(RED);
    tft.setTextSize(1);
    tft.println("Hello World!");
    tft.setTextColor(YELLOW);
    tft.setTextSize(2);
    tft.println("Hello World!");
    tft.setTextColor(GREEN);
    tft.setTextSize(3);
    tft.println("Hello World!");
    tft.setTextColor(BLUE);
    tft.setTextSize(4);
    tft.print(1234.567);

    waitOneTouch(true); // Wait touch

    tft.setRotation(tft.getRotation()+1);
  }
}

void rotateFillcircle(void) {
  for (uint8_t i=0; i<4; i++) {
    tft.fillScreen(WHITE);

    tft.fillCircle(10, 30, 10, YELLOW);

    tft.setRotation(tft.getRotation()+1);

    waitOneTouch(true); // Wait touch

  }
}

void rotateDrawcircle(void) {
  for (uint8_t i=0; i<4; i++) {
    tft.fillScreen(WHITE);

    tft.drawCircle(10, 30, 10, YELLOW);

    waitOneTouch(true); // Wait touch

    tft.setRotation(tft.getRotation()+1);
  }
}

void rotateFillrect(void) {
  for (uint8_t i=0; i<4; i++) {
    tft.fillScreen(WHITE);

    tft.fillRect(10, 20, 10, 20, GREEN);

    waitOneTouch(true); // Wait touch

    tft.setRotation(tft.getRotation()+1);
  }
}

void rotateDrawrect(void) {
  for (uint8_t i=0; i<4; i++) {
    tft.fillScreen(WHITE);

    tft.drawRect(10, 20, 10, 20, GREEN);

    waitOneTouch(true); // Wait touch

    tft.setRotation(tft.getRotation()+1);
  }
}

void rotateFastline(void) {
  for (uint8_t i=0; i<4; i++) {
    tft.fillScreen(WHITE);
    tft.drawFastHLine(0, 20, tft.width(), RED);
    tft.drawFastVLine(20, 0, tft.height(), BLUE);

    waitOneTouch(true); // Wait touch

    tft.setRotation(tft.getRotation()+1);
  }
}

void rotateLine(void) {
  for (uint8_t i=0; i<4; i++) {
    tft.fillScreen(WHITE);

    tft.drawLine(tft.width()/2, tft.height()/2, 0, 0, RED);

    waitOneTouch(true); // Wait touch

    tft.setRotation(tft.getRotation()+1);
  }
}

void rotatePixel(void) {
  for (uint8_t i=0; i<4; i++) {
    tft.fillScreen(WHITE);

    tft.drawPixel(10,20, RED);

    waitOneTouch(true); // Wait touch

    tft.setRotation(tft.getRotation()+1);
  }
}

TSPoint waitOneTouch(boolean showMessage) {

  // wait 1 touch to exit function

  uint8_t save = 0;

  if (showMessage) {

    save = tft.getRotation(); // Save it
    tft.setRotation(0); // Show in normal

    tft.setCursor (80, 250);
    tft.setTextSize (1);
    tft.setTextColor(BLACK);
    tft.println("Touch to proceed");

  }

  // Wait a touch

  TSPoint p;

  do {
    p= ts.getPoint();

    pinMode(XM, OUTPUT); //Pins configures again for TFT control
    pinMode(YP, OUTPUT);

  } while((p.z < MINPRESSURE )|| (p.z > MAXPRESSURE));

  if (showMessage) {
    tft.setRotation(save);
  }

  return p;
}

void drawBorder () {

  // Draw a border

  uint16_t width = tft.width() - 1;
  uint16_t height = tft.height() - 1;
  uint8_t border = 10;

  tft.fillScreen(RED);
  tft.fillRect(border, border, (width - border * 2), (height - border * 2), WHITE);

}

*/
