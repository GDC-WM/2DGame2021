#ifndef GLOB_HPP
#define GLOB_HPP

#include <SFML/System/Vector2.hpp>
#include <cmath>
#include <chrono>
#include <SFML/Graphics.hpp>


namespace glob {
	/* physics update time in ms */
	inline extern const double dt = 1.0 / 60.0;

	/* scale of drawing */
	inline extern const float scale = 0.08;

	/* Geometric vector */
	struct vect {
		vect() {};

		vect(const float &x, const float &y) : x(x), y(y) {};

		/* Magnitude */
		float length() { return std::sqrt(x * x + y * y); };

		/* Angle */
		float angle() { return std::atan2(y, x); };

		/* Negate */
		vect operator-() const { return vect(-x, -y); };

		/* Add */
		vect operator+(const vect &v) const { return vect(x + v.x,
		                                                  y + v.y); };

		/* Subtract */
		vect operator-(const vect &v) const { return vect(x - v.x,
		                                                  y - v.y); };

		/* Multiply by a scalar */
		vect operator*(const float &s) const { return vect(x * s,
		                                                   y * s); };

		/* Divide by a scalar */
		vect operator/(const float &s) const { return vect(x / s,
		                                                   y / s); };

		/* Dot product */
		float operator*(const vect &v) const { return x * v.x
		                                            + y * v.y; };

		/* Subtract from this vector */
		void operator+=(const vect &v) { x += v.x; y += v.y; };

		/* Subtract from this vector */
		void operator-=(const vect &v) { x -= v.x; y -= v.y; };

		/* Multiply into this vector by a scalar */
		void operator*=(const float &s) { x *= s; y *= s; };

		/* Divide into this vector by a scalar */
		void operator/=(const float &s) { x /= s; y /= s; };

		float x, y;
	};

	/* Multiply by a scalar */
	inline vect operator*(const float &s, const vect &v) {
		return vect(v.x * s, v.y * s);
	};

	/**
	 * Convert vectors
	 */
	inline vect convert_vect(const sf::Vector2f &v) { return vect(v.x, -v.y); };

	inline sf::Vector2f convert_vect(const vect &v) { return sf::Vector2f(v.x, -v.y); };
}


#endif
