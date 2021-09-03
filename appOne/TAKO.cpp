#include<libOne.h>
#include "TAKO.h"
void TAKO::setImage(int img) {
	Img = img;
}
void TAKO::init() {
	Px = random() % (int)width;
	Py = random() % (int)height;
	angleMode(RADIANS);
	Angle = random() % 360 + 1.0f;
}
void TAKO::move() {
	Angle += 0.01f;
}
void TAKO::draw() {
	image(Img, Px, Py, Angle);
}

