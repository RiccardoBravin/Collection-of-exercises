Drop[] drops = new Drop[1000];

float speed;

void setup() {
  size(600, 600);

  for (int i=0; i < drops.length; i++)
    drops[i] = new Drop();
}

void draw() {

  speed = map(mouseX, 0, width, 0, 10);
  
  background(220,220,250);
  for (int i = 0; i < drops.length; i++) {
    drops[i].update();
    drops[i].show();
  }
}
