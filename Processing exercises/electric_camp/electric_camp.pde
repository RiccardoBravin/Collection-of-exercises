import controlP5.*;

ControlP5 cp5;

ArrayList<Particle> particles = new ArrayList<Particle>();
float damping = 0.999;

float charge = 0;
float mass = 0;
boolean pm = true; 
boolean reset = false;
float k = 4 * PI * 8.85 * pow(10, -12);


void setup() {
  size(900, 800);
  cp5 = new ControlP5(this);
  
  cp5.addKnob("charge").setPosition(50,10).setRange(0.00001, 0.001).setSize(70,70).setValue(0.0001);
  cp5.addKnob("mass").setPosition(200, 10).setRange(0.0001,1).setSize(70,70).setValue(0.1);
  cp5.addToggle("pm").setPosition(350,35).setMode(ControlP5.SWITCH).setSize(60,30).setLabel("pos/neg");
  cp5.addToggle("reset").setPosition(500,20).setSize(60,60);
  
  
}

void draw() {
  background(0);
  fill(255);
  rect(0, 100, width, 2);
  

  for (int i = 0; i < particles.size(); i++) {

    particles.get(i).update();

    particles.get(i).show();

    if (particles.get(i).getX() > width || particles.get(i).getX() < 0 || particles.get(i).getY() > height || particles.get(i).getY() < 100 || reset)
      particles.remove(i);
  }
}


void mousePressed() {
  if (mouseY > 100)
    particles.add( new Particle(charge,mass,pm));
}
