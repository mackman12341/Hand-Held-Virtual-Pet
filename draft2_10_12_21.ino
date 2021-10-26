#include <SPI.h>
//#include <Wire.h>
//#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <EEPROM.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

//Sprites
#define sprite1_H   10
#define sprite1_W    24
static const unsigned char PROGMEM sprite1_bmp[] =
{
  B00111111,  B11111111, B11111100,
  B00111111,  B11111111, B11111100,
  B11000000,  B00000000, B00000011,
  B11000011,  B00000000, B11000011,
  B11000011,  B00000000, B11000011,
  B11000000,  B00000000, B00000011,
  B11000000,  B11111111, B00000011,
  B11000000,  B00000000, B00000011,
  B00111111,  B11111111, B11111100,
  B00111111,  B11111111, B11111100,};
  static const unsigned char PROGMEM sprite1Eat_bmp[] =
{
  B00111111,  B11111111, B11111100,
  B00111111,  B11111111, B11111100,
  B11000000,  B00000000, B00000011,
  B11000011,  B00000000, B11000011,
  B11000011,  B01111110, B11000011,
  B11000000,  B01000010, B00000011,
  B11000000,  B01111110, B00000011,
  B11000000,  B00000000, B00000011,
  B00111111,  B11111111, B11111100,
  B00111111,  B11111111, B11111100,};
#define poop_H   8
#define poop_W    8
static const unsigned char PROGMEM poop_bmp[] =
{
  B10000000,
  B01000010,
  B10000001,
  B00010010,
  B00011000,
  B00110100,
  B01011110,
  B01111110,
};
#define sprite2_H   10
#define sprite2_W    24
static const unsigned char PROGMEM sprite2_bmp[] =
{
  B00000000,  B11111111, B00000000,
  B00001111,  B00100010, B11110000,
  B00110000,  B10001000, B00001100,
  B11000100,  B01111110, B00100011,
  B10000001,  B10000001, B10000001,
  B10010000,  B01111110, B00010001,
  B11000010,  B00000000, B01000011,
  B00110000,  B01010100, B00001100,
  B00001111,  B00000000, B11110000,
  B00000000,  B11111111, B00000000,};
  #define sprite3_H   11
#define sprite3_W    24
static const unsigned char PROGMEM sprite3_bmp[] =
{
  B00011111,  B11111111, B11111000,
  B01100011,  B00011000, B11000110,
  B10000000,  B00000000, B00000001,
  B11111111,  B11111111, B11111111,
  B10000010,  B10000001, B01000001,
  B11111100,  B01111110, B00111111,
  B01000000,  B10000001, B00000010,
  B11111111,  B11111111, B11111111,
  B11111111,  B11111111, B11111111,
  B10000000,  B00000000, B00000001,
  B01111111,  B11111111, B11111110,};
static const unsigned char PROGMEM sprite4Shop_bmp[] =
{
  B01111110,  B00111111, B00000000,
  B10000001,  B11000000, B10000000,
  B01111110,  B10111111, B00000000,
  B00000000,  B10000000, B00000000,
  B11111111,  B11111111, B10000000,
  B10000000,  B00000000, B10000000,
  B11111111,  B11111111, B10000000,
  B01000000,  B00000001, B00000000,
  B01000000,  B00000001, B00000000,
  B00111111,  B11111110, B00000000,
  };
  static const unsigned char PROGMEM sprite5Shop_bmp[] =
{
  B00000000,  B01111110, B00000000,
  B00000000,  B10000001, B00000000,
  B00000001,  B00000000, B10000000,
  B00000001,  B00000000, B10000000,
  B00001111,  B11111111, B11110000,
  B01110000,  B00000000, B00001110,
  B10000011,  B00011000, B11000001,
  B01110000,  B00000000, B00001110,
  B00001111,  B11111111, B11111000,
  B00000100,  B00011000, B00100000,
  };
    static const unsigned char PROGMEM sprite6Shop_bmp[] =
{
  B00000000,  B00000000, B00000000,
  B00000000,  B00000000, B00000000,
  B00000000,  B00000000, B00000000,
  B00000000,  B00000000, B00000000,
  B00000000,  B00000000, B00000000,
  B00000000,  B00000000, B00000000,
  B00000000,  B00000000, B00000000,
  B00000000,  B00000000, B00000000,
  B00000000,  B00000000, B00000000,
  B00000000,  B00000000, B00000000,
  };
//----------
#define icon_H 8
#define icon_W 16
static const unsigned char PROGMEM iconHome_bmp[] =
{
  B00000001,  B10000000,
  B00000111,  B11100000,
  B00011111,  B11111000,
  B01111111,  B11111110,
  B00011111,  B11111000,
  B00010001,  B10001000,
  B00010001,  B10001000,
  B00011111,  B10001000,
  };
  static const unsigned char PROGMEM iconHealth_bmp[] =
{
  B00000000,  B00000000,
  B00000011,  B11000000,
  B00000011,  B11000000,
  B00011111,  B11111000,
  B00011111,  B11111000,
  B00000011,  B11000000,
  B00000011,  B11000000,
  B00000000,  B00000000,
  };
  static const unsigned char PROGMEM iconSport_bmp[] =
{
  B00000000,  B00000000,
  B00000011,  B11000000,
  B00000011,  B11000000,
  B00000011,  B11011110,
  B00000011,  B11011110,
  B01111011,  B11011110,
  B01111011,  B11011110,
  B01111011,  B11011110,
  };
  static const unsigned char PROGMEM iconShop_bmp[] =
{
  B11100000,  B00000000,
  B00011111,  B11111111,
  B00010000,  B00000001,
  B00010000,  B00000001,
  B00011111,  B11111111,
  B00010000,  B00000000,
  B00011111,  B11111111,
  B00001100,  B00000110,
  };
//----------
int menu = 0; 
int16_t Euro = 156;
int16_t hungerBar = 8;
int16_t hearts = 3;
//cursor var
int resistorVal[7] = {145,169,204,255,341,512,1023};
int buttonVal[7] = {false,false,false,false,false,false,false};
int cursorX = 20;
int cursorY = 9;
int prevClick[7] = {false,false,false,false,false,false,false};
//sprite var
int xpos = 52;
int ypos = 15;
int movement = 1;
int timer = 1;
int variance;
int numHearts = 5;
int weight = 10;
int balance = 0;
int hungry = 6;
int poop = -1;
int poopPlacement[8] = {10,11,20,20,105,12,112,22};

void setup() {
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x32
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  
  pinMode(A6, INPUT);
  pinMode(A0, OUTPUT);
  display.clearDisplay();
  display.setTextSize(1); // Draw 2X-scale text
  display.setTextColor(SSD1306_WHITE);
  int lifeCheck;
  lifeCheck = EEPROM.read(0);
  //lifeCheck = -1;  //This is used for reseting 
  Serial.begin(9600);
  Serial.println(lifeCheck);
  if(lifeCheck > -1){
    eepromGet();
  }
  else{
    numHearts = 5;
    weight = 10;
    balance = 0;
    hungry = 6;
    poop = -1;
    eepromUpdate();
    Serial.println(EEPROM.read(0));
  }
}

void loop() {
  buttonCheck();
  switch(menu){
    case 1: //health
      header("Health");
      display.setCursor(6,8);
      display.println("Life: ");
      for(int i = 0; i < numHearts; i++){
        display.setCursor(57+(i*6),8);
        display.write(hearts);
      }
      display.setCursor(6,16);
      display.println("Weight: ");
      display.setCursor(56,16);
      display.println(weight);
      display.setCursor(70,16);
      display.println("lbs");
      display.setCursor(6,24);
      display.println("Balance: ");
      display.setCursor(56,24);
      display.write(Euro);
      display.setCursor(65,24);
      display.println(balance);
      break;
    case 2: //hunger
      header("Food");
      display.setCursor(6,8);
      display.println("Meal ");
      display.setCursor(6,16);
      display.println("Snack ");
      display.setCursor(6,24);
      display.println("Hunger: ");
      hungry = (hungry > 6) ? 6: hungry;
      for(int i = 0; i < hungry; i++){
        display.setCursor(60+(i*6),24);
        display.write(hungerBar);
      }
      eatFood();
      cursorplacement();
      break;
    case 3: //sport
      header("Sport");
      display.setCursor(6,8);
      display.println("Snake ");
      display.setCursor(6,16);
      display.println("Life ");
      game();
      cursorplacement();
      break;
    case 4: //store
      header("Store");
      break;
    case 5: //WC
      toto();
      break;
    default:
      cursorplacement();
      menuSelect();
      spriteMovement();
      iconPlacement();
      poopy(0);
      eepromUpdate();
      //food();
  }
  //homeButton();
  display.display();
  delay(10);
  display.clearDisplay();
}

void homeButton(){
  menu = (buttonVal[0] == true) ? 0 : menu;
  cursorX = (buttonVal[0] == true) ? 20: cursorX;
  cursorY = (buttonVal[0] == true) ? 9: cursorY;
}
void buttonCheck() {
  int val = analogRead(A6);
  for(int i = 0; i < 7; i++){
    if(val >= (resistorVal[i] - 5) && val <= (resistorVal[i] + 5)){
      buttonVal[i] = true;
    }else{buttonVal[i] = false;}
  }
  if(buttonVal[0] == true){
    homeButton();
  }
}
void cursorplacement(){
  if(menu == 0){
    cursorX = (buttonVal[3] == true && prevClick[3] == false) ? (cursorX - 21): cursorX;
    cursorX = (buttonVal[5] == true && prevClick[5] == false) ? (cursorX + 21): cursorX;
    for(int i = 0; i < 8; i++){prevClick[i] = buttonVal[i];}
    if(cursorX > 104){cursorX = 104;}
    else if(cursorX < 20){cursorX = 20;}
    display.drawPixel(cursorX, cursorY, SSD1306_WHITE);
  }
  if(menu == 2 || menu == 3){
    cursorY = (buttonVal[6] == true && prevClick[6] == false) ? (cursorY + 8): cursorY;
    cursorY = (buttonVal[4] == true && prevClick[4] == false) ? (cursorY - 8): cursorY;
    for(int i = 0; i < 8; i++){prevClick[i] = buttonVal[i];}
    if(cursorY > 18){cursorY = 18;}
    else if(cursorY < 10){cursorY = 10;}
    display.drawPixel(cursorX, cursorY, SSD1306_WHITE);
  }
}
void menuSelect(){
  menu = (buttonVal[1] == true) ? (((cursorX - 20)/21)+1): menu;
  if(menu == 2){cursorX = 60; cursorY = 10;} //prevClick[1] == true;}
}
void header(char title[15]){
  display.setTextSize(1); // Draw 2X-scale text
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(6,0);
  display.println(title);
}
void spriteMovement(){
  if(timer == 40){
    movement = movement * -1;
    variance = random(-2,3); //random is not random simulation confirmed
    display.drawBitmap(xpos + variance, ypos + movement, sprite1_bmp, sprite1_W, sprite1_H, 1);
    xpos+=variance;
    xpos = (xpos <= -10 || xpos >= 128) ? 58 : xpos;
    timer=1;
  }
  else{
    display.drawBitmap(xpos + variance, ypos + movement, sprite1_bmp, sprite1_W, sprite1_H, 1);
    timer++;
  }
}
void iconPlacement(){
   //static const unsigned char PROGMEM bmpList[4] = {iconHome_bmp, iconHealth_bmp,iconSport_bmp, iconShop_bmp};
   display.setCursor(100, 0);
   display.println("WC");
   display.drawBitmap(12, 0, iconHome_bmp, icon_W, icon_H, 1);
   display.drawBitmap(33, 0, iconHealth_bmp, icon_W, icon_H, 1);
   display.drawBitmap(54, 0, iconSport_bmp, icon_W, icon_H, 1);
   display.drawBitmap(75, 0, iconShop_bmp, icon_W, icon_H, 1);
}
void toto(){
  for(int i = 1; i < 129; i++){
    spriteMovement();
    poopy(i);
    for(int z = 1; z < 33; z++){
      display.drawPixel(i, z, SSD1306_WHITE);
    }
    display.display();
    delay(10);
    display.clearDisplay();
  }
  menu = 0;
  poop = -1;
}
void poopy(int totoSweep){
  poop = (poop > 3) ? 3: poop;
  for(int i = 0; i < poop+1; i++){
    if(totoSweep < poopPlacement[i*2]){
      display.drawBitmap(poopPlacement[i*2] + movement, poopPlacement[((i+1)*2)-1], poop_bmp, poop_W, poop_H, 1);
    }
    else{
      display.drawBitmap(totoSweep, poopPlacement[((i+1)*2)-1], poop_bmp, poop_W, poop_H, 1);   
    }
  }
}
void food(){
  display.drawBitmap(5, 15, sprite2_bmp, sprite2_W, sprite2_H, 1);
  display.drawBitmap(100, 15, sprite3_bmp, sprite3_W, sprite3_H, 1);
}
void eatFood(){
  if(buttonVal[1] == true && prevClick[1] == false){
    display.clearDisplay();
    display.display(); //weight
    int chomp = 1;
    if(cursorY == 10){
      for(int i = 0; i < 10; i++){
        display.drawBitmap(5, 15, sprite3_bmp, sprite2_W, sprite2_H - i, 1);
        if(chomp == 1){
          display.drawBitmap(52,15,sprite1_bmp, sprite1_W, sprite1_H,1);
        }
        else{
          display.drawBitmap(52,15,sprite1Eat_bmp, sprite1_W, sprite1_H,1);
        }
        display.display();
        delay(400);
        display.clearDisplay();
        chomp*=-1;
      }
      weight+=5;
      hungry+=2;
    }
    else{
      for(int i = 0; i < 10; i++){
        display.drawBitmap(5, 15, sprite2_bmp, sprite2_W, sprite2_H - i, 1);
        if(chomp == 1){
          display.drawBitmap(52,15,sprite1_bmp, sprite1_W, sprite1_H,1);
        }
        else{
          display.drawBitmap(52,15,sprite1Eat_bmp, sprite1_W, sprite1_H,1);
        }
        display.display();
        delay(400);
        display.clearDisplay();
        chomp*=-1;
      }
      weight+=3;
      hungry+=1;
    }
     poop+=1;
  }
}
void game(){
  if(buttonVal[1] == true && prevClick[1] == false){
    display.clearDisplay();
    display.display();
    //game var
    int snakeX = 24;
    int snakeXmover = 1;
    int snakeY = 4;
    int snakeYmover = 0;
    int snakeLength = 0;
    int gameOver = false;
    int snakeCoordinatesX[100];
    int snakeCoordinatesY[100];
    int candyX = 3;
    int candyY = 3;
    int16_t candy = 9;
    while(true){
      buttonCheck();
      snakeXmover = (buttonVal[3] == true && prevClick[3] == false) ? -1: snakeXmover;
      snakeXmover = (buttonVal[5] == true && prevClick[5] == false) ? 1: snakeXmover;
      snakeYmover = (buttonVal[6] == true && prevClick[6] == false) ? 1: snakeYmover;
      snakeYmover = (buttonVal[4] == true && prevClick[4] == false) ? -1: snakeYmover;
      snakeYmover = ((buttonVal[3] == true && prevClick[3] == false) || (buttonVal[5] == true && prevClick[5] == false)) ? 0: snakeYmover;
      snakeXmover = ((buttonVal[4] == true && prevClick[4] == false) || (buttonVal[6] == true && prevClick[6] == false)) ? 0: snakeXmover;
      
      snakeX = snakeX + snakeXmover;
      snakeY = snakeY + snakeYmover;
      for(int i = snakeLength; i > -1; i--){
        if((snakeX == snakeCoordinatesX[i]) && (snakeY == snakeCoordinatesY[i])){
          balance+=(snakeLength - 1);
          weight-= (snakeLength / 3);
          hungry-= (snakeLength / 3);
          return 0;
        }
      }
      for(int i = snakeLength; i > -1; i--){
        for(int y = 0; y < 3; y++){
          for(int x = 0; x < 4; x++){
            display.drawPixel((snakeCoordinatesX[i]*4) + x, (snakeCoordinatesY[i]*3) + y, SSD1306_WHITE);
          }
        }
        snakeCoordinatesX[i+1] = snakeCoordinatesX[i];
        snakeCoordinatesY[i+1] = snakeCoordinatesY[i];
      }
      snakeCoordinatesX[0] = snakeX;
      snakeCoordinatesY[0] = snakeY;
        
      if(snakeX > 31 || snakeX < 0 || snakeY > 10 || snakeY < 0){
        balance+=(snakeLength - 1);
        weight-= (snakeLength / 3);
        hungry-= (snakeLength / 3);
        return 0;
      }
      for(int y = 0; y < 3; y++){
        for(int x = 0; x < 4; x++){
          display.drawPixel((snakeX*4) + x, (snakeY*3) + y, SSD1306_WHITE);
        }
      }
      if(snakeX == candyX && snakeY == candyY){
        candyX = random(0, 31);
        candyY = random(0, 9);
        snakeLength++;
      }
      display.setCursor(candyX * 4,(candyY * 3) - 2);
      display.write(candy);

      display.display();
      delay(100);
      display.clearDisplay();
    }
  }
}




void eepromUpdate(){
  //0: life
  //1: weight
  //2: balance
  //3: hunger
  //4: poop
  EEPROM.update(0, numHearts);
  EEPROM.update(1, weight);
  EEPROM.update(2, balance);
  EEPROM.update(3, hungry);
  EEPROM.update(4, poop);
}
void eepromGet(){
  numHearts = EEPROM.read(0);
  weight = EEPROM.read(1);
  balance = EEPROM.read(2);
  hungry = EEPROM.read(3);
  poop = EEPROM.read(4);
}
