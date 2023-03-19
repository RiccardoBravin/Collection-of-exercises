int [][] pile;
int skip = 1000;

void setup() {
  size(601, 601);
  pile = new int[width][height];
  //pile[width/2][height/2] = 4 * 20000;
}

void draw() {
  render();
  for(int i = 0; i < skip; i++)
  fall();
}

void fall() {
  for (int x = 0; x < width; x++) {
    for (int y = 0; y < width; y++) {
     if(pile[x][y] >= 4)
      {
        pile[x][y] -= 4;
        if(x + 1 < width)
        pile[x + 1][y]++;
        if(x - 1 > 0)
        pile[x - 1][y]++;
        if(y + 1 < width)
        pile[x][y+1]++;
        if(y - 1 > 0)
        pile[x][y-1]++;
        
      }
    }
  }
}

void render() {
  loadPixels();

  for (int x = 0; x < width; x++) {
    for (int y = 0; y < width; y++) {

      int num = pile[x][y];
      color col = color(255);
      if (num == 3)
        col = color(118,54,38);
      else if (num == 1)
        col = color(42,49,50);
      else if (num == 2)
        col = color(51,107,135);
      else if (num == 0)
        col = color(144,175,197);
        
        pixels[x+y*width] = col;
    }
  }
  
  updatePixels();
}

void mousePressed(){
  pile[mouseX][mouseY] = 4 * round(random(1000, 10000));
}
