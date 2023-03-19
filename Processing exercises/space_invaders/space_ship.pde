class Ship{
  int x;
  float y;
  
  
  Ship(){
    x = width/2;
    y = height-32;
  }

  void show(){
    image(ship, x, y);
  }
  
  void update(){
    if(mouseX >= 0 && mouseX <= width - 49)
      x = mouseX;
       
  }
}
