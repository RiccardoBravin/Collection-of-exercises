
int i = 0;
IntList seq = new IntList();
int x,max, d;

void setup() {
  size(500, 500);
  background(255);
  seq.append(0);
}

void draw() {
  strokeWeight(0.1);
  translate(0,height/2);
  noFill();
  x = seq.get(i) - i;
  if (x < 0 || seq.hasValue(x)){
    x = seq.get(i) + i;
  }
  
  seq.append(x);
  if(max < x)
    max = x;
  
  
  
  //ellipse(seq.get(i),0,x,x);
  d = x - i/2;
  if(x < seq.get(i))
  d = x + i/2;
  println(d);

  if(i%2 == 0)
    arc(d, 0, i, i, 0, PI);
  else
    arc(d, 0, i, i, PI, TWO_PI);
  
  //arc(width/2 , height/2, 100, 100, PI, TWO_PI);
    
  i++;
  
}
