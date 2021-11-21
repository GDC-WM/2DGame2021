#include "sprite_sheet.hpp"

#include "glob.hpp"

#include <SFML/Graphics.hpp>
#include <chrono>
#include <cmath>

SpriteSheet::SpriteSheet(const std::string &filename, const int &sprite_length) {
	// load a sprite sheet
	_texture.loadFromFile(filename);

	// calculate rows/columns of sprites in the sprite sheet
	_sheet_size.x = _texture.getSize().x / sprite_length;
	_sheet_size.y = _texture.getSize().y / sprite_length;

	// Set sprite size
	_sprite_rect = sf::IntRect(0, 0, sprite_length, sprite_length);
	_sprite = sf::Sprite(_texture, _sprite_rect);
	_sprite.setScale(glob::scale, glob::scale);
	_sprite.setOrigin(sprite_length * glob::scale / 2, sprite_length * glob::scale / 2);

	_start_time = std::chrono::steady_clock::now();
}

const sf::Sprite &SpriteSheet::get_sprite() {
	int dt = std::chrono::duration_cast<std::chrono::milliseconds>(
			std::chrono::steady_clock::now() - _start_time).count();

	// check for oneshot
	Loop loop = dt < _one_shot.frame_time * _one_shot.frames ? _one_shot : _loop;

	// set frame
	int n = dt / loop.frame_time;
	int frame = loop.start + n % loop.frames;
	_set_frame(frame);
	return (_sprite);
}

void SpriteSheet::set_one_shot(const Loop &loop) {
	_one_shot = loop;
	_start_time = std::chrono::steady_clock::now();
}

void SpriteSheet::set_one_shot(const int &start, const int &frames, const int &frame_time) {
	_one_shot = {start, frames, frame_time};
	_start_time = std::chrono::steady_clock::now();
}

void SpriteSheet::_set_frame(const int &frame) {
	// calculate frame position
	_sprite_rect.top = _sprite_rect.height * (frame / _sheet_size.x);
	_sprite_rect.left = _sprite_rect.width * (frame % _sheet_size.x);
	_sprite.setTextureRect(_sprite_rect);
}
