#include <hw06.h>
#include <iostream>
#include <vector>
#include <string>

Hall create_hall(int id, int rows, int seats_per_row) {
    Hall hall;
    hall.id = id;
    hall.rows = rows;
    hall.seats_per_row = seats_per_row;
    hall.reserved_seats.resize(rows);
    for (int i = 0; i < rows; ++i) {
        hall.reserved_seats[i].resize(seats_per_row, false);
    }
    return hall;
}

Session create_session(int id, const std::string& movie_title, const Hall& hall) {
    Session session;
    session.id = id;
    session.movie_title = movie_title;
    session.hall = hall;
    return session;
}

bool reserve_seat(Session& session, int row, int seat_number) {
    if (row < 1 || row > session.hall.rows || seat_number < 1 || seat_number > session.hall.seats_per_row) {
        return false;
    }
    int r = row - 1;
    int s = seat_number - 1;
    if (session.hall.reserved_seats[r][s]) {
        return false;
    }
    session.hall.reserved_seats[r][s] = true;
    return true;
}

bool cancel_reservation(Session& session, int row, int seat_number) {
    if (row < 1 || row > session.hall.rows || seat_number < 1 || seat_number > session.hall.seats_per_row) {
        return false;
    }
    int r = row - 1;
    int s = seat_number - 1;
    if (!session.hall.reserved_seats[r][s]) {
        return false;
    }
    session.hall.reserved_seats[r][s] = false;
    return true;
}

void display_hall(const Hall& hall) {
    for (const auto& row : hall.reserved_seats) {
        for (bool seat : row) {
            std::cout << (seat ? "X " : "O ");
        }
        std::cout << std::endl;
    }
}

int get_available_seats(const Hall& hall) {
    int count = 0;
    for (const auto& row : hall.reserved_seats) {
        for (bool seat : row) {
            if (!seat) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    return 0;
}