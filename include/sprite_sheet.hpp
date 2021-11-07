#ifndef SPRITE_SHEET_HPP
#define SPRITE_SHEET_HPP


#include <SFML/Graphics.hpp>
#include <chrono>
#include <cmath>

#include "glob.hpp"


struct Loop {
	int start, frames, frame_time;

	bool operator==(Loop l) {
		return l.start == start
		    && l.frames == frames
		    && l.frame_time == frame_time;
	}

	bool operator!=(Loop l) { return !(*this == l); }
};


/**
 * Facilitates creating an animation from a spritesheet.
 */
class SpriteSheet {
public:
	/**
	 * @param filename Filename
	 * @param sprite_size The length of a side of the (square) sprite in pixels
	 */
	SpriteSheet(const std::string &filename, const int &sprite_length);

	void set_pos(const glob::vect &v) { _sprite.setPosition(glob::convert_vect(v)); };

	void set_pos(const float &x, const float &y) { this->set_pos({ x, y }); };

	/**
	 * First updates the sprite to the proper frame, then returns
	 *
	 * @return The sprite
	 */
	const sf::Sprite &get_sprite();

	/**
	 * @return The current loop.
	 */
	const Loop &get_loop() const { return _loop; };

	/**
	 * Set the loop within the sprite sheet.
	 *
	 * @param loop New loop
	 */
	void set_loop(const Loop &loop) { _loop = loop; };

	/**
	 * Set the loop within the sprite sheet.
	 *
	 * @param start The frame number of the first frame in the sequence
	 * @param frames The number of frames in the sequence
	 * @param frame_time The time between each frame of the animation
	 */
	void set_loop(const int &start, const int &frames, const int &frame_time) {
		_loop = { start, frames, frame_time };
	};

	/**
	 * Run a loop one time, then return to the last loop.
	 *
	 * @param loop Oneshot loop
	 */
	void set_one_shot(const Loop &loop);

	/**
	 * Run a loop one time, then return to the last loop.
	 *
	 * @param start The frame number of the first frame in the sequence
	 * @param frames The number of frames in the sequence
	 * @param frame_time The time between each frame of the animation
	 */
	void set_one_shot(const int &start, const int &frames, const int &frame_time);

	/**
	 * @param mirrored Set whether to mirror the sprite
	 */
	void mirror(const bool &mirrored) {
		_sprite.setScale((mirrored? -1 : 1) * glob::scale, glob::scale);
	};

	/**
	 * Mirror sprite
	 */
	void mirror() { _sprite.setScale(-_sprite.getScale().x, glob::scale); };

	/**
	 * Reset the animation to the first frame in the sequence.
	 */
	void restart() { _start_time = std::chrono::steady_clock::now(); };


private:
	std::chrono::steady_clock::time_point _start_time;
	sf::Texture _texture;
	sf::Sprite _sprite;
	sf::IntRect _sprite_rect; // pixels
	sf::Vector2i _sheet_size; // rows/columns
	Loop _loop { 0, 0, 0 };
	Loop _one_shot { 0, 0, 0 };

	/**
	 * Set the frame of the animation
	 *
	 * @param frame Number ordered left to right, top to bottom
	 */
	void _set_frame(const int &frame);
};


#endif
