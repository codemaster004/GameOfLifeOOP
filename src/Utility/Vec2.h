/**
 * Created by Filip Dabkowski on 20/03/2024.
 */

#ifndef GAMEOFLIFEOOP_VEC2_H
#define GAMEOFLIFEOOP_VEC2_H

/**
 * @struct Vec2
 * @brief Represents a vector in 2D space
 *
 * @details Structure is used to hold coordinates of various elements in the game,
 * in order to simplify mathematical operation.
 */
struct Vec2 {
	int x, y; ///< table with coordinates for each dimension

	/// Static method to get a base X axis
	static Vec2 unitX();

	/// Static method to get a base Y axis
	static Vec2 unitY();

	/**
	 * @brief This function calculates and returns the dot product of two given vectors.
	 *
	 * @details The dot product is the result of
	 * multiplication of the corresponding entries in the two input vectors,
	 * summed up for all entries.
	 *
	 * @param vec1 The first vector.
	 * @param vec2 The second vector.
	 * @returns The dot product of the two vectors.
	 */
	static float dot(Vec2 vec1, Vec2 vec2);

	static float length(Vec2 vec1, Vec2 vec2);

	float length();

	float dot(Vec2 vec);

	/**
	 * @brief This function calculates and returns the square of the magnitude of the vector.
	 *
	 * @return The square of the magnitude of the vector.
	 */
	float magnitude2();

	Vec2 normalised();

	/**
	 * @brief Multiplies the vector by a scalar.
	 *
	 * @details Function creates a new vector with the multiplied values and returns it.
	 *
	 * @param scalar The scalar value to multiply the vector by.
	 * @return The resulting vector after scalar multiplication.
	 */
	[[nodiscard]] Vec2 scalarMultiply(float scalar);


	/* Scalar Multiplication operators */

	Vec2 operator*(float scalar) {
		Vec2 result = *this;
		return result.scalarMultiply(scalar);
	}


	void operator*=(float scalar) { *this = this->scalarMultiply(scalar); }


	Vec2 operator/(float scalar) {
		Vec2 result = *this;
		return result.scalarMultiply(1 / scalar);
	}


	void operator/=(float scalar) { *this = this->scalarMultiply(1 / scalar); }


	/// + Add operations
	Vec2& add(const Vec2& vec) {
		this->x += vec.x;
		this->y += vec.y;
		return *this;
	}


	Vec2 operator+(const Vec2& vec) {
		Vec2 result = *this;
		return result.add(vec);
	}


	void operator+=(const Vec2& vec) { this->add(vec); }


	/// - Subtract operation
	Vec2& subtract(const Vec2& vec) {
		this->x -= vec.x;
		this->y -= vec.y;
		return *this;
	}


	Vec2 operator-(const Vec2& vec) {
		Vec2 result = *this;
		return result.subtract(vec);
	}


	void operator-=(const Vec2& vec) { this->subtract(vec); }


	/// * Multiply operation
	Vec2& multiply(const Vec2& vec) {
		this->x *= vec.x;
		this->y *= vec.y;
		return *this;
	}


	Vec2 operator*(const Vec2& vec) {
		Vec2 result = *this;
		return result.multiply(vec);
	}


	void operator*=(const Vec2& vec) { this->multiply(vec); }


	/// / Divide operation
	Vec2& divide(const Vec2& vec) {
		this->x /= vec.x;
		this->y /= vec.y;
		return *this;
	}


	Vec2 operator/(const Vec2& vec) {
		Vec2 result = *this;
		return result.divide(vec);
	}


	void operator/=(const Vec2& vec) { this->divide(vec); }


	/// == Equality check
	bool operator==(const Vec2& vec) const { return x == vec.x && y == vec.y; }


	bool operator!=(const Vec2& vec) const { return !(*this == vec); }


	/// < is Less than
	bool operator<(const Vec2& vec) const { return dot(*this, *this) < dot(vec, vec); }


	/// > is More than
	bool operator>(const Vec2& vec) const { return dot(*this, *this) > dot(vec, vec); }
};

#endif // GAMEOFLIFEOOP_VEC2_H
