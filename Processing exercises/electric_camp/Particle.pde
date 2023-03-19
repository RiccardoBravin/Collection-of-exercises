class Particle {
  float x;
  float y;
  float velx = 0;
  float vely = 0;
  float accx = 0;
  float accy = 0;
  float carica = 1;
  float massa = 1;
  float fx;
  float fy;
  float sx;
  float sy;

  Particle(float c, float m, boolean pn) {
    x = mouseX;
    y = mouseY;
    ellipse(x, y, 5, 5);
    if (pn)
      carica = c;
    else 
    carica = -c;
    massa = m;
  }

  void update() {
    
    fx = carica / k;
    fy = fx;


    for (int j = 0; j < particles.size(); j++) {
      if (particles.get(j) != this) 
        sx -= ((particles.get(j).getC() * (particles.get(j).getX() - x)) / abs(pow(particles.get(j).getX() - x, 3)));
      if(particles.get(j) != this)
        sy -= ((particles.get(j).getC() * (particles.get(j).getY() - y)) / abs(pow(particles.get(j).getY() - y, 3)));
            
      //float Q = carica * particles.get(j).getC();
      //if (particles.get(j).getX() - x < 0) {
      //  accx += (Q / (4 * PI * 8.85 * pow(10, -12) * pow(particles.get(j).getX() - x, 2) * massa));
      //} else if (particles.get(j).getX() - x > 0){
      //  accx -= (Q / (4 * PI * 8.85 * pow(10, -12) * pow(particles.get(j).getX() - x, 2) * massa));
      //}
      //if (particles.get(j).getY() - y < 0) {
      //  accy += (Q / (4 * PI * 8.85 * pow(10, -12) * pow(particles.get(j).getY() - y, 2) * massa));
      //} else if (particles.get(j).getY() - y > 0){
      //  accy -= (Q / (4 * PI * 8.85 * pow(10, -12) * pow(particles.get(j).getY() - y, 2) * massa));
      //}
    }

    fx *= sx;
    fy *= sy;
    
    velx = fx / massa / frameRate;
    vely = fy/ massa / frameRate;
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
