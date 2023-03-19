int[][] grid = new int [10][10] ;
int x = 0;
int y = 0;
boolean perso = false;
int q = 0;

void setup() {
  size(500, 500);
  background(255);
  for (int i = 0; i < 10; i++)
    for (int j = 0; j < 10; j++)
      if (int(random(10)) == 1)
        grid[i][j] = 1;
      else {
        grid[i][j] = 0;
        q++;
      }
}

void draw() {

  fill(0);
  for (x = 0; x < width; x += 50) {
    line(x, 0, x, height);
    line(0, x, width, x );
  }

  x = int(map(mouseX, 0, width, 0, 10));
  y = int(map(mouseY, 0, height, 0, 10));

  if (x < 10 && y < 10 && !perso) {
    if ((grid[x][y] == 1) && mousePressed) {
      ellipse(x*50+25, y*50+25, 10, 10);
      fill(255, 0, 0);
      textSize(80);
      text("HAI PERSO", 50, 250);
      perso = true;
    } else if (grid[x][y] == 0 && mousePressed) {
      rect(x*50+5, y*50+5, 40, 40);
      grid[x][y] = 2;
      q--;
    }
  }

  if (q==0) {
    perso = true;
    fill(255, 0, 0);
    textSize(80);
    text("HAI VINTO", 50, 250);
  }
  //for (int i = 0; i < 10; i++)
  //  for (int j = 0; j < 10; j++) 
  //    if (grid[i][j] == 2)
  //      ellipse(i*50+25, j*50+25, 10, 10);
  //    else if (grid[i][j] == 3) 
  //      rect(i*50, j*50, 50, 50);
}
