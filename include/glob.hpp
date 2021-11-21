#ifndef GLOB_HPP
#define GLOB_HPP

#include <SFML/System/Vector2.hpp>
#include <cmath>

namespace glob {
/* physics update time in ms */
inline extern const double dt = 1.f / 60.f;

/* scale of drawing */
inline extern const float scale = 1; // TODO: settle in on a scale factor

/* define pi */
inline extern const double pi = 3.14159265358979323846;

/* rotational direction */
enum class Rot { clockwise, counterclockwise, none };

/* Geometric vector */
struct vect {
	vect(const float &x, const float &y) : x(x), y(y){};

	/* Magnitude */
	float length() const { return std::sqrt(x * x + y * y); };

	/* Angle */
	float angle() const { return std::atan2(y, x); };

	/* Set angle */
	void set_angle(const float &a) {
		float len = this->length();
		x = len * std::cos(a);
		y = len * std::sin(a);
	};

	/* Negate */
	vect operator-() const { return vect(-x, -y); };

	/* Add */
	vect operator+(const vect &v) const { return vect(x + v.x, y + v.y); };

	/* Subtract */
	vect operator-(const vect &v) const { return vect(x - v.x, y - v.y); };

	/* Multiply by a scalar */
	vect operator*(const float &s) const { return vect(x * s, y * s); };

	/* Divide by a scalar */
	vect operator/(const float &s) const { return vect(x / s, y / s); };

	/* Dot product */
	float operator*(const vect &v) const { return x * v.x + y * v.y; };

	/* Equals? */
	bool operator==(const vect &v) const { return x == v.x && y == v.y; };

	/* Add to this vector's magnitude */
	void operator+=(const float &s) {
		float angle = this->angle();
		x += s * std::cos(angle);
		y += s * std::sin(angle);
	};

	/* Add a vector to this vector */
	void operator+=(const vect &v) {
		x += v.x;
		y += v.y;
	};

	/* Subtract from this vector's magnitude */
	void operator-=(const float &s) { *this += -s; };

	/* Subtract a vector from this vector */
	void operator-=(const vect &v) { *this += -v; };

	/* Multiply the magnitude by a scalar */
	void operator*=(const float &s) {
		float angle = this->angle();
		x *= s * std::cos(angle);
		y *= s * std::sin(angle);
	};

	/* Divide into this vector by a scalar */
	void operator/=(const float &s) {
		x /= s;
		y /= s;
	};

	float x, y;
};

/* Multiply by a scalar */
inline vect operator*(const float &s, const vect &v) { return vect(v.x * s, v.y * s); };

/**
 * Convert vector into a unit vector
 */
inline vect normalize(const vect &v) {
	if (v == vect(0, 0)) return v;
	float magnitude = v.length();
	return vect(v.x / magnitude, v.y / magnitude);
}

/**
 * Convert vectors. Flips Y axis and applies scale factor
 */
inline vect convert_vect(const sf::Vector2f &v) { return vect(v.x, -v.y) / scale; };
inline vect convert_vect(const sf::Vector2i &v) { return vect(v.x, -v.y) / scale; };

inline sf::Vector2f convert_vect(const vect &v) { return sf::Vector2f(v.x, -v.y) * scale; };

/**
 * @param point the point to check
 * @param rect_pos center point of the rectangle
 * @param rect_size dimensions of the rectangle
 * @return whether point lies inside rect
 */
inline bool collides_point_rect(const vect &point, const vect &rect_pos, const vect &rect_size) {
	return point.x > rect_pos.x - (rect_size.x / 2) && point.y > rect_pos.y - (rect_size.y / 2)
	    && point.x < rect_pos.x + (rect_size.x / 2) && point.y < rect_pos.y + (rect_size.y / 2);
}
} // namespace glob

#endif
