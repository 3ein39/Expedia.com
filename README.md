
# Expedia.com

A simple Expedia.com implementation in c++
applying some polymorphism and OOP concepts.

#### Expedia user have several *itineraries*, each consist of
* 0 or more flights, hotels, cars, etc. E.g. 4 flights, 2 hotels and 2 cars.
#### An itinerary item  -e.g a filght- has :
* Its own cost
* Its info: E.g. A flight has request from user, and his selected flight details
  - E.g. Hotel cost: total nights x price per night
* Itinerary cost is the sum of all internal items cost.
#### For Simplicity
* Dummy data is used
* 2 Types of users: Admin & customer. Our code focus is on customer part
* Local APIs is used to call for flights and hotels 



![User Interface](https://res.cloudinary.com/ein39/image/upload/v1659458269/Expedia.com/Screenshot_from_2022-08-02_18-18-11_h8m7cw.png)
![Booking a flight](https://res.cloudinary.com/ein39/image/upload/v1659458269/Expedia.com/Screenshot_from_2022-08-02_18-21-15_uknafr.png)
![Choosing Payment](https://res.cloudinary.com/ein39/image/upload/v1659458269/Expedia.com/Screenshot_from_2022-08-02_18-22-49_bkgmlr.png)
![Total cost](https://res.cloudinary.com/ein39/image/upload/v1659458269/Expedia.com/Screenshot_from_2022-08-02_18-23-21_k3tnkp.png)
## Acknowledgements

 - [Dr. Mostafa Saad Mastering 4 critical SKILLS using C++ 17](https://www.udemy.com/course/cpp-4skills/)


## Run Locally

Clone the project

```bash
  git clone https://github.com/3ein39/Expedia.com
```

Go to the project directory

```bash
  cd my-project
```

Run the main.cpp file using a cpp compiler

```text
  username : user
  password : 111

