class Bullet{
  int x;
  int y;
  
  Bullet(int n, boolean rl){
    x = n;
    y = height - 20;
    
    if(rl)
      x += 11;
    else
      x += 38;
      
    
  }

  void show(){
    fill(255);
    noStroke();
    
    ellipse(x, y, 3, 3);
  }
  
  void update(){
      y-=2;
  }
  
  boolean del(){
    
    
    if(get(y - 7, x) == -13395747 ){
      return true;
    }else 
      return false;
  }
  
  
}
