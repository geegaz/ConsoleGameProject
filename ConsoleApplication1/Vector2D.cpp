#include "Vector2D.h"
#include <cmath>

intVector2_t intVector2_t::operator+(intVector2_t& other) {
	return intVector2_t(this->x + other.x, this->y+other.y);
}
intVector2_t intVector2_t::operator-(intVector2_t& other) {
	return intVector2_t(this->x - other.x, this->y - other.y);
}
intVector2_t& intVector2_t::operator+=(intVector2_t& other) {
	this->x += other.x;
	this->y += other.y;
	return *this;
}
intVector2_t& intVector2_t::operator-=(intVector2_t& other) {
	this->x -= other.x;
	this->y -= other.y;
	return *this;
}

floatVector2_t intVector2_t::toFloat() {
	return floatVector2_t(this->x, this->y);
}


floatVector2_t floatVector2_t::operator+(intVector2_t& other) {
	floatVector2_t res(this->x + other.x, this->y + other.y);
	return DecimalRound(res);
}
floatVector2_t floatVector2_t::operator-(intVector2_t& other) {
	floatVector2_t res(this->x - other.x, this->y - other.y);
	return DecimalRound(res);
}
floatVector2_t& floatVector2_t::operator+=(intVector2_t& other) {
	this->x += other.x;
	this->y += other.y;
	DecimalRound(*this);
	return *this;
}

floatVector2_t& floatVector2_t::operator-=(intVector2_t& other) {
	this->x -= other.x;
	this->y -= other.y;
	DecimalRound(*this);
	return *this;
}

floatVector2_t floatVector2_t:: operator+(floatVector2_t& other) {
	floatVector2_t res(this->x + other.x, this->y + other.y);
	return DecimalRound(res);
}
floatVector2_t floatVector2_t::operator-(floatVector2_t& other) {
	floatVector2_t res(this->x - other.x, this->y - other.y);
	return DecimalRound(res);
}
floatVector2_t& floatVector2_t::operator+=(floatVector2_t& other) {
	this->x += other.x;
	this->y += other.y;
	DecimalRound(*this);
	return *this;
}
floatVector2_t& floatVector2_t::operator-=(floatVector2_t& other) {
	this->x -= other.x;
	this->y -= other.y;
	DecimalRound(*this);
	return *this;
}
intVector2_t floatVector2_t::ToInt() {
	return intVector2_t(this->x, this->y);
}
intVector2_t floatVector2_t::Round() {
	return intVector2_t(nearbyint(this->x), nearbyint(this->y));
}

floatVector2_t& floatVector2_t::DecimalRound(floatVector2_t& toRound) {
	float multiplier = pow(10, DECIMAL_PLACES);
	toRound.x = round(toRound.x * multiplier) / multiplier;
	toRound.y = round(toRound.y * multiplier) / multiplier;
	return toRound;
}
