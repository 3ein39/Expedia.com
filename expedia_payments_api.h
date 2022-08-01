/*
 * expedia_payments_api.h
 *
 *  Created on: Sep 18, 2020
 *      Author: moustafa
 */

#ifndef EXPEDIA_PAYMENTS_API_H_
#define EXPEDIA_PAYMENTS_API_H_



using namespace std;

#include "json.hpp"
using namespace json;


// Below: What we did with flights and payments satisfy Dependency inversion principle
// High-level modules (expedia.com) should not depend on low-level modules (AirCandaAirlines/PaypalPayment APIs).
// Both should depend on abstractions (e.g. IFlighsFinder and IPayment).
// That is the power of interfaces BTW ;)

class PayPalCreditCard {
public:
	string name;
	string address;
	string id;
	string expiry_date;
	int ccv;
};

class PayPalOnlinePaymentAPI {
public:
	void SetCardInfo(const PayPalCreditCard* const card) {
	}
	bool MakePayment(double money) {
		return true;
	}
};

class StripeUserInfo {
public:
	string name;
	string address;
};

class StripeCardInfo {
public:
	string id;
	string expiry_date;
};

class StripePaymentAPI {
public:
	bool static WithDrawMoney(StripeUserInfo user, StripeCardInfo card, double money) {
		return true;
	}
};

class SquarePaymentAPI {
public:
	bool static WithDrawMoney(string JsonQuery) {
		//cout << JsonQuery << "\n";
		json::JSON obj = JSON::Load(JsonQuery);
		return true;
	}
};

class IPayment {
public:
    virtual void SetUserInfo(string name, string address) = 0;
    virtual void SetCardInfo(string id, string expiry_date, int ccv) = 0;
    virtual bool MakePayment(double money) = 0;
    virtual ~IPayment() {}
};





















#endif /* EXPEDIA_PAYMENTS_API_H_ */
