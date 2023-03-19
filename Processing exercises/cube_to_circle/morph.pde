class Morph {
  ArrayList<PVector> circle;
  ArrayList<PVector> square;
  ArrayList<PVector> current;
  
  Morph() {
    circle = new ArrayList<PVector>(); 
    float off = PI/4;
    int r = 200;

    for (float a = off; a < TWO_PI + off; a += TWO_PI/r)
    {

      PVector point = new PVector(cos(a), sin(a));

      point.mult(r);
      circle.add(point);
    }

    square = new ArrayList<PVector>(); 

    int side = r/4;
    float x = r;
    float y = r;
    
    ellipse(x,y,4,4);
    
    for (int i = 0; i < side; i++) {
      PVector v = new PVector(x, y);
      x-= r*2 / side; 
      square.add(v);
    }
    
    for (int i = 0; i < side; i++) {
      PVector v = new PVector(x, y);
      y-= r*2 / side; 
      square.add(v);
    }
    
    for (int i = 0; i < side; i++) {
      PVector v = new PVector(x, y);
      x+= r*2 / side; 
      square.add(v);
    }
    
    for (int i = 0; i < side; i++) {
      PVector v = new PVector(x, y);
      y+= r*2 / side;
      
      square.add(v);
    }
    
    current = new ArrayList<PVector>();
    
    for (PVector v : square){
      current.add(v.copy());
    }
    
    println(circle.size());
    println(square.size());
    
  }

  void show() {

    stroke(255);
    fill(255,100);
    beginShape();
    for (PVector v : current) {
      vertex(v.x, v.y);
    }
    endShape(CLOSE);

    //beginShape();
    //for (PVector v : square) {
    // vertex(v.x, v.y);
    //}
    //endShape(CLOSE);
  }
  
  void update(){
    for(int i = 0; i < current.size(); i++){
     PVector v = PVector.lerp(circle.get(i),square.get(i), amt);
     current.set(i,v);
    }
  }
}
