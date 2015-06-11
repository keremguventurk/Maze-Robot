#include <StackArray.h>



boolean turnback = false;
int motor1A = 12; //Burayı güncelle baba
//int motor1B = 0;
int motor1E = 3;
int motor2A = 13;
//int motor2B = 0;
int motor2E = 11;
boolean gayfatih = true;
/*ArrayList<Integer> yol = new ArrayList<Integer>();
ArrayList<Integer> geridon = new ArrayList<Integer>();*/
int THRESHOLD = 3;
const int echoPin2 = 8;
const int trigPin2 = 9;
const int echoPin3 = 6;
const int trigPin3 = 7;
const int echoPin4 = 2;
const int trigPin4 = 10;
int sageski = 0;
int soleski = 0;
int oneski = 0;
boolean geridon = false;
int baban = 0;

int sagYakin [] = {0, 0, 0};
int solYakin [] = {0, 0, 0};

StackArray <String> stack;



void setup() {
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
  pinMode(trigPin4, OUTPUT);
  pinMode(echoPin4, INPUT);
  pinMode(motor1E, OUTPUT);
  pinMode(motor2E, OUTPUT);
  pinMode(motor1A, OUTPUT);
  pinMode(motor2A, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  long duration2, sag;
  long duration3, sol;
  long duration4, on;


  /*while(getRect == 0 && digitalRead(button) == LOW) { //button basılı değilse
    digitalWrite(LED, !digitalRead(LED));
    delay(50);
  }*/
  //getRect = 1;
  //*************************************
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);


  duration2 = pulseIn(echoPin2, HIGH);

  // convert the time into a distance
  sag = microsecondsToCentimeters(duration2);

  //Serial.print(sag);



  digitalWrite(trigPin3, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin3, LOW);


  duration3 = pulseIn(echoPin3, HIGH);

  // convert the time into a distance
  sol = microsecondsToCentimeters(duration3);
  /*Serial.print(" ");
  Serial.print(sol);*/


  digitalWrite(trigPin4, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin4, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin4, LOW);

 

  duration4 = pulseIn(echoPin4, HIGH);

  // convert the time into a distance
  on = microsecondsToCentimeters(duration4);

  Serial.println(on);
  
  
  int a = 9;
  /*if (on > THRESHOLD && sag > THRESHOLD+5) {
      a = random(1,3);
      if (a == 2) {
        stack.push("on");
        forward(50);
        delay(500);
        forward(0);
        delay(200);
      }
      else {
        stack.push("sag");
        forward(50);
        delay(150);
        forward(0);
        delay(100);
        right(85);
        delay(240);
        right(0);
        delay(200);
        forward(50);
        delay(300);
        forward(0);
        delay(200);
      }
    }
    else if (on > THRESHOLD && sol > THRESHOLD+5) {
      a = random(1,3);
      if (a == 1) {
        stack.push("on");
        forward(50);
        delay(500);
        forward(0);
        delay(200);
      }
      else {
        stack.push("sol");
        forward(50);
        delay(150);
        forward(0);
        delay(100);
        left(85);
        delay(240);
        left(0);
        delay(200);
        forward(50);
        delay(300);
        forward(0);
        delay(200);
      }
    }
    else if (sag > THRESHOLD + 5 && sol > THRESHOLD+5) {
      a = random(1,3);
      if (a == 1) {
        stack.push("sag");
        forward(50);
        delay(150);
        forward(0);
        delay(100);
        right(85);
        delay(240);
        right(0);
        delay(200);
        forward(50);
        delay(300);
        forward(0);
        delay(200);
      }
      else {
        stack.push("sol");
        forward(50);
        delay(150);
        forward(0);
        delay(100);
        left(85);
        delay(240);
        left(0);
        delay(200);
        forward(50);
        delay(300);
        forward(0);
        delay(200);
      }
    }
    else {
      */
      if (on > THRESHOLD) {
        if (sol <= 4 && sag <= 4) {
          forward(30);
        }
        else if (sol <= 4) {
          digitalWrite(motor1A, LOW);
          analogWrite(motor1E, 60);
          digitalWrite(motor2A, LOW);
          analogWrite(motor2E, 20);
        } 
        else if (sag <= 4) {
          digitalWrite(motor2A, LOW);
          analogWrite(motor2E, 60);
          digitalWrite(motor1A, LOW);
          analogWrite(motor1E, 20);
        } 
        else {
          forward(30);
        }
    delay(10);
    forward(0);
      }
      else {
        if (sag > THRESHOLD + 5) {
          stack.push("sag");
          backward(50);
          delay(30);
          backward(0);
          delay(30);
          right(85);
          delay(240);
          right(0);
          delay(200);
        }
        else if (sol > THRESHOLD + 5) {
          stack.push("sol");
          backward(50);
          delay(30);
          backward(0);
          delay(30);
          left(85);
          delay(240);
          left(0);
          delay(200);
        }
        else {
          backward(50);
          delay(30);
          backward(0);
          delay(30);
          right(85);
          delay(240);
          right(0);
          delay(100);
          right(85);
          delay(240);
          right(0);
          geridon = true;
          delay(200);
        }
      }
    

  
}

//************************************************





void forward(int powa) {
  digitalWrite(motor1A, LOW);
  digitalWrite(motor2A, LOW);
  analogWrite(motor1E, powa);
  analogWrite(motor2E, powa);
}

void backward(int powa) {
  digitalWrite(motor1A, HIGH);
  digitalWrite(motor2A, HIGH);
  analogWrite(motor1E, powa);
  analogWrite(motor2E, powa);
}

void left(int powa) {
  digitalWrite(motor1A, HIGH);
  digitalWrite(motor2A, LOW);
  analogWrite(motor1E, powa);
  analogWrite(motor2E, powa);
}

void right(int powa) {
  digitalWrite(motor1A, LOW);
  digitalWrite(motor2A, HIGH);
  analogWrite(motor1E, powa);
  analogWrite(motor2E, powa);
}
long microsecondsToCentimeters(long microseconds)
{
  return microseconds / 29 / 2;
}
