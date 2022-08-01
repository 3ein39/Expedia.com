/*
 * expedia_hotels_api.h
 *
 *  Created on: Sep 22, 2020
 *      Author: moustafa
 */

#ifndef EXPEDIA_HOTELS_API_H_
#define EXPEDIA_HOTELS_API_H_

#include<bits/stdc++.h>

using namespace std;

#include "common_reservation.h"

class HiltonRoom {
public:
	string room_type;
	int available;
	double price_per_night;
	string date_from;
	string date_to;
};

class HiltonHotelAPI {
public:
	static vector<HiltonRoom> SearchRooms(string country, string city, string from_date, string to_date, int adults, int children, int needed_rooms) {
		vector<HiltonRoom> rooms;

		rooms.push_back( { "Interior View", 6, 200.0, "29-01-2022", "10-02-2022" });
		rooms.push_back( { "City View", 3, 300.0, "29-01-2022", "10-02-2022" });
		rooms.push_back( { "Deluxe View", 8, 500.0, "29-01-2022", "10-02-2022" });

		return rooms;
	}
};

class MarriottFoundRoom {
public:
	string room_type;
	int available;
	double price_per_night;
	string date_from;
	string date_to;
};

class MarriottHotelAPI {
public:
	static vector<MarriottFoundRoom> FindRooms(string from_date, string to_date, string country, string city, int needed_rooms, int adults, int children) {
		vector<MarriottFoundRoom> rooms;

		rooms.push_back( { "City View", 8, 320.0, "29-01-2022", "10-02-2022" });
		rooms.push_back( { "Interior View", 8, 220.0, "29-01-2022", "10-02-2022" });
		rooms.push_back( { "Private View", 5, 600.0, "29-01-2022", "10-02-2022" });

		return rooms;
	}
};

class HotelRoom {
private:
    string hotel_name;
    string room_type;
    int available_rooms = 0;
    double price_per_night = 0;
    string date_from;
    string date_to;

public:
    // printing
    void ToString() const {
        ostringstream oss;
        oss << "Hotel: " << hotel_name << " Room Type: " << room_type << "(" << available_rooms << ") Price per night: " << price_per_night << " From Date " << date_from << " to " << date_to << "";
        return oss.str();
    }

    // setters and getters
    const string& GetDateFrom() const {
        return date_from;
    }

    void SetDateFrom(const string& date_from) {
        this->date_from = date_from;
    }

    const string& GetDateTo() const {
        return date_to;
    }

    void SetDateTo(const string& date_to) {
        this->date_to = date_to;
    }

    double GetPricePerNight() const {
        return price_per_night;
    }

    void SetPricePerNight(double price_per_night) {
        this->price_per_night = price_per_night;
    }

    const string& GetRoomType() const {
        return room_type;
    }

    void SetRoomType(const string& room_type) {
        this->room_type = room_type;
    }

    int GetAvailableRooms() const {
        return available_rooms;
    }

    void SetAvailableRooms(int available_rooms) {
        this->available_rooms = available_rooms;
    }

    const string& GetHotelName() const {
        return hotel_name;
    }

    void SetHotelName(const string& hotel_name) {
        this->hotel_name = hotel_name;
    }
};























#endif /* EXPEDIA_HOTELS_API_H_ */
