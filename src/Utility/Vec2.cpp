/**
 * @file Vec2.cpp
 * @brief [Description of file]
 *
 * @author Filip Dabkowski
 * @date 20/03/2024
 */
#include "Vec2.h"

#include <cmath>


float Vec2::dot(Vec2 vec1, Vec2 vec2) { return vec1.x * vec2.x + vec1.y * vec2.y; }


float Vec2::dot(Vec2 vec) { return Vec2::dot(*this, vec); }


float Vec2::magnitude2() {
	// calculate the square magnitude using the dot with itself
	return dot(*this, *this);
}


float Vec2::length(Vec2 vec1, Vec2 vec2) {
	return sqrtf((float) ((vec1.x - vec2.x) * (vec1.x - vec2.x) + (vec1.y - vec2.y) * (vec1.y - vec2.y)));
}


float Vec2::length() { return sqrtf(magnitude2()); }


Vec2 Vec2::normalised() {
	Vec2 result = *this;
	result /= result.magnitude2();
	return result;
}


Vec2 Vec2::scalarMultiply(float scalar) {
	Vec2 result = *this;
	// Multiply each dimension with the scalar.
	result.x *= scalar;
	result.y *= scalar;

	return result; // Return the vector.
}


Vec2 Vec2::unitX() { return {1, 0}; }


Vec2 Vec2::unitY() { return {0, 1}; }
