#include "stdafx.h"
#include "PotatoLibrary.h"

namespace Potato{
	Pair Pair::operator-(const Pair& other){
		this->x -= other.x;
		this->y -= other.y;
		return *this;
	}

	Pair Pair::operator+(const Pair& other){
		this->x += other.x;
		this->y += other.y;
		return *this;
	}

	Pair Pair::operator*(const Pair& other){
		this->x *= other.x;
		this->y *= other.y;
		return *this;
	}

	Pair Pair::operator=(const Pair& other){
		this->x = other.x;
		this->y = other.y;
		return *this;
	}

	bool Pair::operator==(const Pair& other){
		return (this->x == other.x && this->y == other.y);
	}

	Pair Pair::operator++(void){
		this->x++;
		this->y++;
		return *this;
	}

	Pair Pair::operator--(void){
		this->x--;
		this->y--;
		return *this;
	}

	Pair Pair::operator+=(const Pair& other){
		this->x += other.x;
		this->y += other.y;
		return *this;
	}

	Pair Pair::operator-=(const Pair& other){
		this->x -= other.x;
		this->y -= other.y;
		return *this;
	}

	Pair Pair::operator*=(const Pair& other){
		this->x *= other.x;
		this->y *= other.y;
		return *this;
	}
}