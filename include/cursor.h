#ifndef CURSOR_H
#define CURSOR_H

class Cursor {
private:
	int x, y;

public:
	void setX(int p_x);
	void setY(int p_y);
	int getX();
	int getY();
};

#endif //CURSOR_H
