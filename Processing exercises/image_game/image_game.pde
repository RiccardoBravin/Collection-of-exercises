PImage image;

void setup() {
  size(1280, 720);
  String I = str(int(random(1,7.9))) + ".jpg";
  image = loadImage(I);
  background(0);
}

void draw() {
  
  //if you add this you'll generate also radom points on the image as ellipse;
  
  //for (int i = 0; i < 1; i++) {
  //  int x = int(random(width));
  //  int y = int(random(height));

  //  color c = image.get(x, y);

  //  fill(c);
  //  noStroke();

  //  ellipse(x, y, 5, 5);
  //}
  
  //use this if it gets to difficult
  frameRate(100);
  
  int x = mouseX;
  int y = mouseY;

  color c = image.get(x, y);

  fill(c, 180);
  noStroke();
  //if (mousePressed)  // if you want it to only work when the mouse is pressed
    ellipse(x, y, 25, 25);
}
