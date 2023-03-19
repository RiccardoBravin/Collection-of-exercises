PImage img;
PImage sort;
int record;
int i = 0;

color aux;




void setup() {
  size(800, 400);
  img = loadImage("2.jpg");
  sort = img.get();
  sort.loadPixels();
  //for (int i = 0; i < sort.pixels.length; i++) {
  //  for (int j = i; j < sort.pixels.length; j++) {
  //    if (brightness(sort.pixels[record]) < brightness(sort.pixels[j])) {
  //      record = j;
  //    }
  //    aux = sort.pixels[record];
  //    sort.pixels[record] = sort.pixels[i];
  //    sort.pixels[i] = aux;
  //  }
  //}
}

void draw() {
  
  frameRate(400);
  sort.loadPixels();
    record = i; 
    for (int j = i; j < sort.pixels.length; j++) {
      if (brightness(sort.pixels[record]) < brightness(sort.pixels[j])) {
        record = j;
      }
    }

    aux = sort.pixels[i];
    sort.pixels[i] = sort.pixels[record];
    sort.pixels[record] = aux;
    if (i < sort.pixels.length-1)
      i++;

    sort.updatePixels();

    println(frameRate);

    //background(0);
    image(img, 0, 0);
    image(sort, height, 0);
}
