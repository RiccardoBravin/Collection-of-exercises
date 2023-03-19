class Drop {
  
  float x, y;
  float z;
  float h,w;
  
  
  Drop() {
    x = random(0, width);
    y = random(height);
    h = random(2, 6);
    w = random(1, 2);
    z = random(20,150);
  }

  void update() {

    if (h<4)
      y += speed+random(0.5);
    else
      y += speed+random(1.5);
    if (y > height) {
      y = 0;
      x = random(0, width);
      z = random(20,150);
    }
  }

  void show() {
    fill(z, z, 250);
    noStroke();



    rect(x, y, w, h);
  }
}
