#include <memory>
#include <thread>
#include <chrono>
#include <cmath>

#include "glob.hpp"
#include "user_view.hpp"
#include "game_controller.hpp"
#include <iostream>
int main(int argc, char** argv) {
	GameController gameController; 

	auto loop_dt = std::chrono::nanoseconds(long(std::round(glob::dt * 10E9)));
	using clock = std::chrono::steady_clock;
	clock::time_point next_update = clock::now();
	std::cout << "Before game controller initialize" << std::endl; 
	while (gameController.isRunning) {
		next_update += loop_dt; // = ~60fps
		gameController.update(); 

		std::this_thread::sleep_for(next_update - clock::now());
	}

	return 0;
}
