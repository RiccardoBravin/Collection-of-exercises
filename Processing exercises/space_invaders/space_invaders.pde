PImage alien;
PImage ship;
boolean m = true;

ArrayList<Alien> aliens = new ArrayList<Alien>();
ArrayList<Bullet> bullets = new ArrayList<Bullet>();
Ship s;

void setup(){
  size(800,500);
  frameRate(60);
  s = new Ship();
  alien = loadImage("/sprite/alien.png");
  ship = loadImage("/sprite/ship.png");
  
  for(int i = 10; i < 700; i+= alien.width + 20)
    aliens.add(new Alien(i));
}


void draw(){
 background(0);
 println(frameRate);
 println(bullets.size());
 
 
  for(Alien a : aliens){
  a.show();
  a.update();
 }
 
 for(Bullet b : bullets){
   b.show(); 
   b.update();
 }
 for(int i = 0; i < bullets.size(); i++){
   println(get(bullets.get(i).x, bullets.get(i).y - 7 ));
   if(bullets.get(i).y < 6 || bullets.get(i).del()) 
     bullets.remove(i);
   
 }
   
 s.show();
 s.update();

 
}

void mouseClicked(){
    bullets.add(new Bullet(s.x, m));
    if(m == true)
      m = false;
    else
      m = true;
}
