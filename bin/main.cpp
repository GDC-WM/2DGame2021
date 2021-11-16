#include "glob.hpp"
#include "state_controller.hpp"
#include "state_menu.hpp"

#include <chrono>
#include <cmath>
#include <memory>
#include <thread>

int main(int argc, char **argv) {
	std::shared_ptr<StateController> game = std::make_shared<StateController>();
	game->states().push(std::make_shared<StateMenu>(game));

	// game update loop
	auto loop_dt = std::chrono::nanoseconds(16666667); // ~60th of a second
	using clock = std::chrono::steady_clock;
	clock::time_point next_update = clock::now();
	while (game->running()) {
		next_update += loop_dt; // = ~60fps
		game->update();
		std::this_thread::sleep_for(next_update - clock::now());
	}

	return 0;
}
