#include <iostream>
#include "get_time.cpp"

double past_time = GetCurrentTime();

double current_time;
double delta_time;

 while (true){
    current_time = GetCurrentTime();
    delta_time = current_time - past_time;

    processInput();

    update(delta_time);

    render();

    past_time = current_time;
}