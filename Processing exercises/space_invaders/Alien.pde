class Alien{

  float x;
  float y;
  boolean dx = true;
  
  Alien(float h){
    x = h;
    y = 10;
  }

  void show(){
    image(alien, x, y);
  }
  
  void update(){
    if(x <= width - alien.width - 10 && x >= 10){
      if(dx == true)
        x += round(log(y));
      else
        x -= round(log(y));
    }
    else{
      y += 40;
      if(dx == true){
        dx = false;
        x -= round(log(y));
      }else{
       dx = true;
       x += round(log(y));
      }
    }
  }
}
