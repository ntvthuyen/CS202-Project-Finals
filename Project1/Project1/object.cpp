#include "HeaderFile/object.h"

void Object::resetPosition() {
	position = 10;
}
int Object::getPosition() {
	if (this != nullptr)
		return position;
}
int Object::getW() {
	return w;
}
void Object::moveLeft() {
	--position;
	if (position < w)
		position = w;
}
void Object::moveRight() {
	++position;
	if (position > MAXLENGHT - 2)
		position = MAXLENGHT - 2;
}
void Player::draw(int row) {
	Draw drawer;
	drawer.drawHuman(getPosition(), row + 3);
}
bool Player::isImpact(mObject &obj) {
	if (obj.getPosition() + obj.getW() == getPosition() - getW()) return true;
	if (obj.getPosition() - obj.getW() == getPosition() + getW()) return true;
	return false;
}
void Player::moveForward() {
	--lane;
}
void Truck ::draw(int row) {
	Draw drawer;
	drawer.drawTruck(getPosition(), row + 3, direct);
}
void Car::draw(int row) {
	Draw drawer;
	drawer.drawCar(getPosition(), row +3, direct);
}
void Bird::draw(int row) {
	Draw drawer;
	drawer.drawBird(getPosition(), row + 1, direct);
}
void Dino::draw(int row){
	Draw drawer;
	drawer.drawDino(getPosition(), row);
}
void mObject::moveLeft() {
	--position;
	if (position < getW())
		position = MAXLENGHT - getW();
}
void mObject::moveRight() {
	position++;
	if (position > MAXLENGHT - getW())
		position = getW();
}
void  Player::setLane(int lane) {
	this->lane = lane;
}
int  Player::getLane() {
	return lane;
}