Grid grid;

int block_x = 5;
int block_y = 0;
int block_t;
int w = 10;
int h = 20;

void setup() {
  size(500, 1000);
  grid = new Grid();
  block_t = millis() + 1000;
}

void draw() {
  background(0);
  if ( millis() > block_t) {
    block_down();
  }
  grid.block_at(block_x, block_y);
  grid.draw();
}

void keyPressed() {
  if ( keyCode == SHIFT ) { 
    block_drop();
  }
  if ( keyCode == DOWN ) { 
    block_down();
  }
  if ( keyCode == LEFT ) { 
    block_left();
  }
  if ( keyCode == RIGHT ) { 
    block_right();
  }
}

void block_drop() {
  while (block_y < h - 1) {
    block_y++;
  }
}

void block_down() {
  block_t = millis() + 1000;
  if (block_y < h-1)
    block_y++;
}

void block_right() {
  if (block_x < w-1)
    block_x++;
}

void block_left() {
  if (block_x > 0)
    block_x--;
}
