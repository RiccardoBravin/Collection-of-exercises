Morph m;
float amt = 0;

void setup() {
  
  size(600, 600);
  m = new Morph();
}

void draw() {
  amt = map(mouseX, 0, width, 0, 1 );
  background(50);
  translate(width/2, height/2);
  
  m.show();
  m.update();
  
  
}
