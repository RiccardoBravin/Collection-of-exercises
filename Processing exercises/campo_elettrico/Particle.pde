class Particle {
  float x;
  float y;
  float velx = 0;
  float vely = 0;
  float accx = 0;
  float accy = 0;
  float carica = 1;
  float massa = 1;


  Particle(float c, float m, boolean pn) {
    x = mouseX;
    y = mouseY;
    ellipse(x, y, 5, 5);
    if(pn)
      carica = c;
    else 
      carica = -c;
    massa = m;
  }

  void update() {

    for (int j = 0; j < particles.size(); j++) {
        float Q = carica * particles.get(j).getC();
        if (particles.get(j).getX() - x < 0) {
          accx += (Q / (4 * PI * 8.85 * pow(10, -12) * pow(particles.get(j).getX() - x, 2) * massa));
        } else if (particles.get(j).getX() - x > 0){
          accx -= (Q / (4 * PI * 8.85 * pow(10, -12) * pow(particles.get(j).getX() - x, 2) * massa));
        }
        if (particles.get(j).getY() - y < 0) {
          accy += (Q / (4 * PI * 8.85 * pow(10, -12) * pow(particles.get(j).getY() - y, 2) * massa));
        } else if (particles.get(j).getY() - y > 0){
          accy -= (Q / (4 * PI * 8.85 * pow(10, -12) * pow(particles.get(j).getY() - y, 2) * massa));
        }
    }
    
    velx = accx/frameRate;
    vely = accy/frameRate;
    y += velx/frameRate; //* damping;            //QUI HO PROVATO A SCAMBIARE X E Y E SEMBRA FUNZIONARE PUR NON AVENDO CHIARO IL PERCHE
    x += vely/frameRate; //* damping;
    
    //x += velx/frameRate*2;
    //y += vely/frameRate*2;
      
  }

  void show() {
    fill(255);
    noStroke();



    ellipse(x, y, massa *50, massa*50);
    
    
  }

  float getC() {
    return carica;
  }

  float getX() {
    return x;
  }

  float getY() {
    return y;
  }
}
