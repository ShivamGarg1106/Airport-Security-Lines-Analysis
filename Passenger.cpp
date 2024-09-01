#include <Passenger.h>

Passenger::Passenger(double arrival_rate, double service_rate)
{
    default_random_engine generator(random_device{}());
    exponential_distribution<double> arrival_distribution(arrival_rate);
    exponential_distribution<double> processing_distribution(service_rate);

    inter_arrival_time = static_cast<int>(arrival_distribution(generator) * 1000);
    processing_time = static_cast<int>(processing_distribution(generator) * 1000);

    global_time += inter_arrival_time;
    global_arrival_time = global_time;
    std::cout << "Created passenger has values : " << inter_arrival_time << " " << processing_time << "\n";
}