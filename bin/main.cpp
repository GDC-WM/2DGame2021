#include <memory>
#include <thread>
#include <chrono>
#include <cmath>

#include "glob.hpp"
#include "user_view.hpp"
#include "game_state.hpp"


int main(int argc, char** argv) {
	std::shared_ptr<GameState> game_state = std::make_shared<GameState>();
	std::shared_ptr<UserView> user_view = std::make_shared<UserView>(game_state);
	game_state->add_view(user_view);

	auto loop_dt = std::chrono::nanoseconds(long(std::round(glob::dt * 10E9)));
	using clock = std::chrono::steady_clock;
	clock::time_point next_update = clock::now();
	while (user_view->running()) {
		next_update += loop_dt; // = ~60fps

		user_view->draw();
		game_state->update();

		std::this_thread::sleep_for(next_update - clock::now());
	}

	return 0;
}
