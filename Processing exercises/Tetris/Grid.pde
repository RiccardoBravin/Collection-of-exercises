class Grid {
  int s;
  int x, y;
  boolean[][] b = new boolean[h][w]; 
  Grid() {
    s = min(width / (2 + w), height / (2 + h));
  }
  
  void block_at(int ix, int iy) {
    x = ix;
    y = iy;
  }
  
  void draw() {
    pushMatrix();
    translate((width - (w * s)) / 2, (height - (h * s)) / 2);
    background(0);
    stroke(128);
    for ( int j = 0; j < h; j++ ) {
      for ( int i = 0; i < w; i++ ) {
        fill(0);
        if ( j==y && i==x ) {
          fill(255, 0, 0);
        }
        rect(s * i, s * j, s, s);
      }
    }
    popMatrix();
  }
}
