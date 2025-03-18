#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

const int x = 128;
const int y = 64;
const int reset = -1;

Adafruit_SSD1306 display(x, y, &Wire, reset);
const int button = 6;
const int SCREEN_HEIGHT = 64;
int state = 0;
int swap = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)){
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }

  //set button to be an input
  pinMode(button, INPUT);

  //set up display 
  display.display();
  delay(2000);
  display.clearDisplay();

  //wake up sleepy boy
  blink();

  display.display();
  delay(2000);
}

void loop() {
  // put your main code here, to run repeatedly:
  state = digitalRead(button);

  if(swap == 0){
    display.clearDisplay();
    eyes();
    //moustachio
    display.fillRect(25, 45, 80, 7, WHITE); //main part
    //bottoms
    display.fillRect(30, 50, 20, 7, WHITE); 
    display.fillRect(80, 50, 20, 7, WHITE);
    //side bits
    display.fillRect(20, 40, 7, 10, WHITE);
    display.fillRect(102, 40, 7, 10, WHITE);
    //tops
    display.fillRect(47, 40, 12, 7, WHITE);
    display.fillRect(72, 40, 12, 7, WHITE);
    swap = 1;
  } else {
    display.clearDisplay();
    eyes();
    //moustachio
    display.fillRect(25, 40, 80, 7, WHITE); //main part
    //bottoms
    display.fillRect(30, 45, 20, 7, WHITE); 
    display.fillRect(80, 45, 20, 7, WHITE);
    //side bits
    display.fillRect(20, 35, 7, 10, WHITE);
    display.fillRect(102, 35, 7, 10, WHITE);
    //tops
    display.fillRect(47, 35, 12, 7, WHITE);
    display.fillRect(72, 35, 12, 7, WHITE);
    swap = 0;
  }
  delay(1000);

  display.display();
  delay(20);

}

void eyes(){
  display.fillRect(30, 17, 17, 7, WHITE);
  display.fillRect(35, 12, 7, 17, WHITE);
  display.fillRect(83, 17, 17, 7, WHITE);
  display.fillRect(88, 12, 7, 17, WHITE);
}

void angryEyes(){
  display.drawLine(33, 7, 53, 10, WHITE);
  display.drawLine(98, 7, 78, 10, WHITE);
  display.fillRect(30, 17, 17, 7, WHITE);
  display.fillRect(35, 12, 7, 17, WHITE);
  display.fillRect(83, 17, 17, 7, WHITE);
  display.fillRect(88, 12, 7, 17, WHITE);
}


/*---------other methods (mainly testing)-------*/
void blink(){
  for(int i = 0; i < 6; i++){
    display.clearDisplay();
    if(swap == 0){
      //eyes
      display.drawLine(15, 25, 45, 25, WHITE);
      display.drawLine(80, 25, 110, 25, WHITE);
      swap = 1;
    }
    else{
      //eyes
      display.drawLine(15, 30, 30, 20, WHITE);
      display.drawLine(30, 20, 45, 30, WHITE);
      display.drawLine(80, 30, 95, 20, WHITE);
      display.drawLine(95, 20, 110, 30, WHITE);
      swap = 0;
    }
    display.display();
    delay(1000);
  }
}

/*void moving(){
  if(swap == 0){
    display.clearDisplay();
    //eyes
    display.drawLine(15, 30, 30, 20, WHITE);
    display.drawLine(30, 20, 45, 30, WHITE);
    display.drawLine(80, 30, 95, 20, WHITE);
    display.drawLine(95, 20, 110, 30, WHITE);
    swap = 1;
  }
  else{
    display.clearDisplay();
    //eyes
    display.drawLine(15, 25, 30, 15, WHITE);
    display.drawLine(30, 15, 45, 25, WHITE);
    display.drawLine(80, 25, 95, 15, WHITE);
    display.drawLine(95, 15, 110, 25, WHITE);
    swap = 0;
  }
  delay(1000);

  if(state == HIGH){
    display.clearDisplay();
    display.drawLine(15, 25, 45, 25, WHITE);
    display.drawLine(80, 25, 110, 25, WHITE);
  }
}

void grid(){
  //draw grid
  display.drawLine(20, 50, 100, 50, WHITE);
  display.drawLine(20, 30, 100, 30, WHITE);
  display.drawLine(40, 20, 40, 70, WHITE);
  display.drawLine(80, 20, 80, 70, WHITE);
}

void makeX(int x, int y){
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(x, y);
  display.println(F("X"));
}


void makeO(int x, int y){
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(x, y);
  display.println(F("O"));
}*/

/*----------me failing to make a mustache-----------*/
  // display.fillRect(35, 50, 15, 6, WHITE);
  // display.fillRect(50, 60, 15, 6, WHITE);
  // display.fillRect(65, 55, 15, 6, WHITE);
  // display.fillRect(80, 60, 15, 6, WHITE);
  // display.fillRect(95, 50, 15, 6, WHITE);
  // display.drawLine(35, 50, 50, 60, WHITE);
  // display.drawLine(50, 60, 65, 55, WHITE);
  // display.drawLine(65, 55, 80, 60, WHITE);
  // display.drawLine(80, 60, 95, 50, WHITE);

  // display.drawLine(35, 50, 45, 55, WHITE);
  // display.drawLine(45, 55, 60, 55, WHITE);
  // display.drawLine(60, 55, 65, 55, WHITE);
  // display.drawLine(65, 55, 80, 60, WHITE);
  // display.drawLine(80, 60, 95, 50, WHITE);