#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

const int x = 128; //width
const int y = 64; //height
const int reset = -1;
long randNumber;

//add potentiometer (mostly for fun :D)
#define knob A0
int knobValue = 0;
int pitch;

//set the led to pin 4
#define led 4

//set the sound sensor to pin A2
#define touch A2
int sound; 

//scream for attention 
#define vocal 5
long petty;
boolean love = false;

//the screen :D
Adafruit_SSD1306 display(x, y, &Wire, reset);
const int SCREEN_HEIGHT = 64;

//to monitor the button press 
#define button 6
int state = 0;
int swap = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  display.setTextSize(1.5);
  display.setTextColor(WHITE);
  display.setCursor(0,30);

  //if the screen fails 
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)){
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }

  //start up seed generator 
  randomSeed(analogRead(0));

  //set button to be an input
  pinMode(button, INPUT);

  //set up display 
  display.display();
  delay(2000);
  display.clearDisplay();

  //wake up sleepy boy
  blink();
  stash(100);

  display.display();
  delay(2000);
}

void loop() {
  //sets so text will print in the middle
  display.setCursor(0,30);
  state = digitalRead(button);
  randNumber = random(7);

  //change sound
  knobValue = analogRead(knob);
  pitch = map(knobValue, 0, 1023, 32, 700);

  //i want to replace this with a timer so after a certain amount of time 
  //it'll just start screaming for food/love/attention
  //rn its more so just a random chance thing (you'll never know when he strikes)
  petty = random(501);
  Serial.println(petty);
  
  //add leds to indicate hunger + screaming to indicate sadness
  while(petty == 500 && pets() == false){
    angryEyes();
    ledOn();
    tone(vocal, pitch); 
    delay(1000);
    noTone(vocal);
  }

  //pets :D
  pets();

  //have the user ask their question and print a grumbot answer
  ask();  

  display.display();
  delay(20);
}


boolean pets(){
  sound = 0;
  for (int i = 0; i < 32; i++){
    sound += analogRead(touch);
  }
  sound >>= 5; //bit shift to fill empty cells 
  if(sound > 500){
    display.clearDisplay();
    display.println("oo that tickles!");
    display.display();
    stash(1000);
    return true;
  }
  return false;
  delay(100);
}

void ask(){
  if(state == HIGH){
    delay(100);
    state = digitalRead(button);    

    if(state == LOW){ //button press not hold 
      display.clearDisplay();

      //totally non-random responses
      switch(randNumber){
        case 0:
          display.println(F("lol no"));
          break;
        case 1:
          display.println(F("do it before i smite you"));
          break;
        case 2:
          display.println(F("if 2 + 2 is 4...?"));
          break;
        case 3:
          display.println(F("womp womp"));
          break;
        case 4:
          display.println(F("trust your gut"));
          break;
        case 5:
          display.println(F("maybe not :<"));
          break;
        case 6:
          display.println(F("id say so"));
          break;
      }
      display.display();   
      delay(3000);
      stash(100);
    }
  }
}

void ledOn(){
  digitalWrite(led, HIGH);
  delay(1000);
  digitalWrite(led, LOW);
}

void eyes(){
  display.fillRect(30, 17, 17, 7, WHITE);
  display.fillRect(35, 12, 7, 17, WHITE);
  display.fillRect(83, 17, 17, 7, WHITE);
  display.fillRect(88, 12, 7, 17, WHITE);
}

void angryEyes(){
  display.clearDisplay();
  display.drawLine(33, 7, 53, 10, WHITE);
  display.drawLine(98, 7, 78, 10, WHITE);
  display.fillRect(30, 17, 17, 7, WHITE);
  display.fillRect(35, 12, 7, 17, WHITE);
  display.fillRect(83, 17, 17, 7, WHITE);
  display.fillRect(88, 12, 7, 17, WHITE);

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
  display.display();
}

void stash(int time){
  int counter = 0;
  while(counter < time){
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
    counter++;
  }
  
  delay(1000);
}


/*---------other methods (mainly testing)-------*/
void blink(){
  for(int i = 0; i < 4; i++){
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

/*
void moving(){
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

/*----------hermitcraft responses-------------------*/
//totally non-random responses
// switch(randNumber){
//   case 0:
//     display.println(F("Vote Mumbo!"));
//     break;
//   case 1:
//     display.println(F("wow"));
//     break;
//   case 2:
//     display.println(F("My dad said no"));
//     break;
//   case 3:
//     display.println(F("womp womp"));
//     break;
//   case 4:
//     display.println(F("tnt yes"));
//     break;
//   case 5:
//     display.println(F("dont get exiled"));
//     break;
//   case 6:
//     display.println(F(":3"));
//     break;
// }

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
