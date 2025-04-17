#ifndef HW06_H
#define HW06_H

#include <vector>
#include <string>

struct Hall {
    int id;
    int rows;
    int seats_per_row;
    std::vector<std::vector<bool>> reserved_seats;
};

struct Session {
    int id;
    std::string movie_title;
    Hall hall;
};

Hall create_hall(int id, int rows, int seats_per_row);
Session create_session(int id, const std::string& movie_title, const Hall& hall);
bool reserve_seat(Session& session, int row, int seat_number);
bool cancel_reservation(Session& session, int row, int seat_number);
void display_hall(const Hall& hall);
int get_available_seats(const Hall& hall);

#endif