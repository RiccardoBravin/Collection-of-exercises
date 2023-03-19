/**
 * SaveFile 2
 * 
 * This file a PrintWriter object to write data continuously to a file
 * while the mouse is pressed. When a key is pressed, the file closes
 * itself and the program is stopped.
 */

PrintWriter output;
boolean circle = false;

void setup() 
{
  size(24, 24);
  // Create a new file in the sketch directory
  output = createWriter("training_data.txt");
  output.print("topology: ");
  output.println("576 64 124 8 4 1");
  //output.println("2 1 1");
  frameRate(10000);
}

void draw() {
  circle_learning();

  //sum();

  //greater();

  if (frameCount > 10) {  
    output.flush(); // Write the remaining data
    output.close(); // Finish the file
    exit();
  }
}

void mousePressed() {
  loadPixels();
  output.print("in: ");
  for (int i = 0; i < width*height; i++) {
    output.print(brightness(pixels[i])/255 + " ");
  }
  if (circle)
    output.println("\nout: 1.0");
  else
    output.println("\nout: 0.0");
}

void keyPressed() { // Press a key to save the data
  output.flush(); // Write the remaining data
  output.close(); // Finish the file
  exit(); // Stop the program
}

void circle_learning() {
  circle = false;
  int bck = int(random(200.0, 255.0));
  background(bck);
  noFill();
  float ran = random(0, 1);
  if (ran < 0.5) {
    circle = true;
    int radius = int(random(2, width-2));
    int x = int(random(2+radius/2, width-radius/2)- 2);
    int y = int(random(2+radius/2, height-radius/2- 2));
    circle(x, y, radius);
  } else if (ran >0.5 && ran < 0.7) {
    translate(height/2, width/2);
    rotate(random(0, PI/4));
    rectMode(CENTER);
    int radius = int(random(15, 40));
    //int x = int(random(-20,20));
    //int y = int(random(-20,20));
    square(0, 0, radius);
  } else if (ran >0.7 && ran < 0.9) {
    triangle(random(5, width/2-5), random(5, width/2-5), random(width/2-5, 59), random(5, width/2-5), random(5, width), random(width/2-5, 59));
  }
  loadPixels();
  output.print("in: ");
  for (int i = 0; i < width*height; i++) {
    output.print(brightness(pixels[i])/255 + " ");
  }
  if (circle)
    output.println("\nout: 1.0");
  else
    output.println("\nout: 0.0");
}

void sum() {
  float x = random(0, 1);
  float y = random(0, 1-x);
  output.println("in: " + x + " " + y);
  output.println("out: " + (x+y));
}

void greater() {
  float x = random(0, 1);
  //float y = random(0,1-x);
  output.println("in: " + x);
  if (x >  0.5)
    output.println("out: " + 1);
  else
    output.println("out: " + 0);
}
