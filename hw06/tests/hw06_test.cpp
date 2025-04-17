#include <gtest/gtest.h>
#include "hw06.h"

TEST(Hw06Tests, TestCreateHallAndSession) {
    Hall hall = create_hall(1, 5, 10);
    ASSERT_EQ(hall.id, 1);
    ASSERT_EQ(hall.rows, 5);
    ASSERT_EQ(hall.seats_per_row, 10);
    ASSERT_EQ(hall.reserved_seats.size(), 5);
    for (const auto& row : hall.reserved_seats) {
        ASSERT_EQ(row.size(), 10);
        for (bool seat : row) {
            ASSERT_FALSE(seat);
        }
    }

    Session session = create_session(1, "Inception", hall);
    ASSERT_EQ(session.id, 1);
    ASSERT_EQ(session.movie_title, "Inception");
    ASSERT_EQ(session.hall.id, 1);
}

TEST(Hw06Tests, TestReserveSeat) {
    Hall hall = create_hall(1, 2, 3);
    Session session = create_session(1, "Inception", hall);
    
    EXPECT_TRUE(reserve_seat(session, 1, 1));
    EXPECT_TRUE(session.hall.reserved_seats[0][0]);
    
    EXPECT_FALSE(reserve_seat(session, 1, 1));
    EXPECT_FALSE(reserve_seat(session, 0, 1));
    EXPECT_FALSE(reserve_seat(session, 3, 1));
    EXPECT_FALSE(reserve_seat(session, 1, 0));
    EXPECT_FALSE(reserve_seat(session, 1, 4));
}

TEST(Hw06Tests, TestCancelReservation) {
    Hall hall = create_hall(1, 2, 3);
    Session session = create_session(1, "Inception", hall);
    
    reserve_seat(session, 1, 1);
    EXPECT_TRUE(cancel_reservation(session, 1, 1));
    EXPECT_FALSE(session.hall.reserved_seats[0][0]);
    
    EXPECT_FALSE(cancel_reservation(session, 1, 1));
    EXPECT_FALSE(cancel_reservation(session, 0, 1));
}

TEST(Hw06Tests, TestAvailableSeats) {
    Hall hall = create_hall(1, 2, 3);
    Session session = create_session(1, "Inception", hall);
    
    ASSERT_EQ(get_available_seats(session.hall), 6);
    reserve_seat(session, 1, 1);
    ASSERT_EQ(get_available_seats(session.hall), 5);
    cancel_reservation(session, 1, 1);
    ASSERT_EQ(get_available_seats(session.hall), 6);
}

TEST(Hw06Tests, TestDisplayHall) {
    Hall hall = create_hall(1, 2, 2);
    Session session = create_session(1, "Inception", hall);
    reserve_seat(session, 1, 1);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}