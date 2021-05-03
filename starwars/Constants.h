#pragma once

class Constants {
private:
    Constants() = default;
public:
    static int max_time_of_game;
    static int normal_height_of_window;
    static int normal_width_of_window;
    static int tick;
    const static int frequency_of_dd_asteroids = 5;
    const static int frequency_of_fast_asteroids = 7;
    const static int frequency_of_slow_asteroids = 9;
};
