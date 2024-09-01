#include <random>

class Passenger
{
public:
    int inter_arrival_time;
    int global_arrival_time;
    int processing_time;
    Passenger(double arrival_rate, double service_rate);
};