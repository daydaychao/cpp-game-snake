#include <iostream>
#include <conio.h>
#include <stdlib.h> /* 亂數涵式 */
#include <windows.h> /* render 慢一點*/

#define KEY_UP     72  //上
#define KEY_DOWN    80  //下 
#define KEY_LEFT    75  //左 
#define KEY_RIGHT    77  //右

using namespace std;

// Scene
const int width = 20;
const int height = 10;

// Position
int x,y;
int fruitX, fruitY;
int gX, gY;

// Current player direction
enum eDirection{STOP = 0 , UP,DOWN,LEFT,RIGHT};
eDirection dir;

// Game status
bool gameOver;
int score;


void Setup(){
  gameOver = false;
  dir = STOP;

  //Snake中間
  x = width/2;
  y = height/2;

  fruitX = rand() % width;
  fruitY = rand() % height;

  score = 0;
}

void Draw(){
  system("cls"); //system("clear")

  // Top wall
  for (int w = 0; w < width+2; w++)
    cout << "#";
  cout << endl;

  // Left Right wall
  for (int h = 0; h < height; h++){
    for (int w = 0; w < width; w++){
      if(w == 0)
        cout << "#";

      // Game Objects   
      if(w == x && h == y)
      cout << "O";

      else if(w == fruitX && h == fruitY)
      cout << "F";

      else if(w == gX && h == gY)
      cout << "G";

      else cout << " ";

      if(w == width-1)
        cout << "#";
    }
    cout << endl;
  }

  // Bottom wall 
  for (int w = 0; w < width+2; w++)
    cout << "#";
  cout << endl;

  // Score
  cout << "Score: "  << score << endl;

}

void Input(){
  if(_kbhit()){
  switch(_getch()){
    case 'w':
      dir = UP;
      break;
    case 's':
      dir = DOWN;
      break;
    case 'a':
      dir = LEFT;
      break;
    case 'd':
      dir = RIGHT;
      break;
    case KEY_UP:
      dir = UP;
      break;
    case KEY_DOWN:
      dir = DOWN;
      break;
    case KEY_LEFT:
      dir = LEFT;
      break;
    case KEY_RIGHT:
      dir = RIGHT;
      break;
    case 'x':
      gameOver = true;
      break;
  }
}
}

void Logic(){
  switch(dir){
    case STOP:
    break;

    case UP:
    y --;
    break;

    case DOWN:
    y ++;
    break;

    case LEFT:
    x--;
    break;

    case RIGHT:
    x++;
    break;

    default:
    break;
  }

  // Got fruit
  if(x == fruitX, y == fruitY) {
    score+= 100;
    fruitX = rand() % width;
    fruitY = rand() % height;
  }

  // Got K
  if(x == gX, y == gY) {
    score+= 1000;
    gX = rand() % width;
    gY = rand() % height;
  }

  // Game over
  if(x > width || x <= 0 || y >= height || y < 0) gameOver = true;
}

int main() {

int num = 10 << 3 ;
printf("num = %d\n",num);

Setup();

while(!gameOver){
  Draw();
  Input();
  Logic();
  Sleep(100);
}

cout << "GAME OVER" << endl;

}