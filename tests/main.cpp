#include <cxxgui/cxxgui.hpp>
#include <iostream>

using namespace cxxgui;

class contentview : public view {
public:
    contentview() {
		body = new hstack {
			new vstack {
				new hstack {
					(new toggle([](view*, bool) {}))->margin(8.0f),
					(new toggle([](view*, bool) {}, true))->margin(8.0f)
				},
				new hstack {
					(new toggle([](view*, bool) {}))->margin(8.0f),
					(new toggle([](view*, bool) {}, true))->margin(8.0f)
				}
			},
			(new stepper<int>([](view*, int i) { std::cout << i << std::endl; }, 0, 10, 5))->margin(8.0f)
		};
	}
};

int main(int argc, char* argv[]) {

	window_t window = window_t(
		"CXXGUI Test",
		1280,
		720,
		new contentview
	);

	return 0;
}
