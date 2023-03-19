PImage image;
PImage red;

int x;
int y;
color col;



void setup() {
  size(835, 437);
  image = loadImage("cantiere.jpg");
  background(0);
  set(0, 0, image);
  red = image.get();
  col = image.get(0, 0);
  loadPixels();
  for (y = 1; y < red.height - 1; y++) {
    for (x = 1; x < red.width - 1; x++) {
      if (col()) {
        red.set(x, y, col);
      }
    }
  }
  updatePixels();
  set(0, 0, red);
}

void draw() {
}


boolean col() {
  if (((image.pixels[y * width + x] > image.pixels[(y + 1) * width + x] * 0.99) ||  (image.pixels[y * width + x] < image.pixels[(y + 1) * width + x] * 1.01)) && 
    ((image.pixels[y * width + x] > image.pixels[(y + 1) * width + x] * 0.99) ||  (image.pixels[y * width + x] < image.pixels[(y + 1) * width + x] * 1.01)) &&
    ((image.pixels[y * width + x] > image.pixels[(y + 1) * width + x] * 0.99) ||  (image.pixels[y * width + x] < image.pixels[(y + 1) * width + x] * 1.01)) &&
    ((image.pixels[y * width + x] > image.pixels[(y + 1) * width + x] * 0.99) ||  (image.pixels[y * width + x] < image.pixels[(y + 1) * width + x] * 1.01))) {
      return true;
  } else 
  return false;
}
