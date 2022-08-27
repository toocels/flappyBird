#include <iostream>

#include "bird.h"

void Bird::renderBird() const{
		move(pos[0], pos[1]);
		printw("\\O>");
		move(pos[0]+1, pos[1]);
		printw("^^");
}