float r1 = 200;
float r2 = 200;
float m1 = 18;
float m2 = 18;
float a1 = PI/3;
float a2 = -PI;
float a1_v = 0;

float a2_v = 0;

float px2 = 0;
float py2 = 0;

float cx, cy;

float g = 1;
float damp = 1; //abbassa per simulare attrito con aria (0.999~)


PGraphics canvas;

void setup() {

  size(900, 600);
  cx = width/2;
  cy = 100;
  canvas = createGraphics(width, height);
  canvas.beginDraw();
  canvas.background(255);
  canvas.endDraw();
}

void draw() {

  float num = -g*(2*m1+m2)*sin(a1)-m2*g*sin(a1-2*a2) - 2*sin(a1-a2)*m2*(a2_v*a2_v*r2+a1_v*a1_v*r1*cos(a1-a2));
  float den = r1*(2*m1+m2-m2*cos(2*a1-2*a2));

  float a1_a = num/den;

  num = 2*sin(a1-a2)*(a1_v*a1_v*r1*(m1+m2)+g*(m1+m2)*cos(a1)+a2_v*a2_v*r2*m2*cos(a1-a2));
  den = r2*(2*m1+m2-m2*cos(2*a1-2*a2));

  float a2_a =num/den;
  
  image(canvas, 0, 0);
  stroke(0);
  strokeWeight(2);

  translate(cx, cy);

  float x1 = r1 * sin (a1);
  float y1= r1 * cos(a1);

  float x2 = x1 +r2 * sin(a2);
  float y2 = y1 +r2 * cos(a2);



  line(0, 0, x1, y1);
  fill(0);
  ellipse(x1, y1, m1, m1);

  line(x1, y1, x2, y2);
  fill(0);
  ellipse(x2, y2, m2, m2);


  a1_v += a1_a;
  a2_v += a2_a;
  a1+= a1_v;
  a2 += a2_v;

  a1_v *= damp;
  a2_v *= damp;

  canvas.beginDraw();
  canvas.translate(cx, cy);
  canvas.strokeWeight(1);
  canvas.stroke(0,123,123);
  if (frameCount > 1)
    canvas.line(px2, py2, x2, y2);
  canvas.endDraw();

  px2 = x2;
  py2 = y2;
}
