//
// Created by hussein on 8/1/22.
//

#ifndef EXPEDIA_COM_CUSTOMER_H
#define EXPEDIA_COM_CUSTOMER_H

#include <sstream>
using namespace std;

#include "payment_card.h"
#include "common_reservation.h"
#include "user.h"

class Customer: public User {
    protected:
    vector<PaymentCard*> cards;   // * to allow polymorphism
    ReservationsSet reservations;

    public:
    // prevent copy constructor and assignment operator
    Customer(const Customer&) = delete;
    void operator=(const Customer&) = delete;

    // Deafult constructor
    Customer() {
        SetType(UserType::CustomerUser);
    }

    // Destructor
    ~Customer() {
        for (PaymentCard* card : cards)
            delete card;
        cards.clear();
    }

    // Add a payment card to the customer
    void AddPaymentCard(const PaymentCard& card) {
        cards.push_back(card.Clone());
    }

    // Add a reservation to the customer
    void AddReservation(const Reservation& reservation) {
        reservations.AddReservation(*reservation.Clone());
    }

    // Get the customer's cards
    const vector<PaymentCard*>& GetCards() const {
        return cards;
    }

    // Get the customer's reservations
    const ReservationsSet& GetReservations() const {
        return reservations;
    }
};

#endif //EXPEDIA_COM_CUSTOMER_H
