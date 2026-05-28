# 🎬 Movie Ticket Booking System

A console-based movie ticket booking system built with **Object Oriented Programming** in C++. Supports admin movie management, customer booking, seat selection, and ticket tracking.

**Course:** Object Oriented Programming  
**Language:** C++

---

## 🎯 Features

### Admin Panel
- Add new movies to the system
- Remove existing movies
- View all movies with available seats
- Password-protected access (`umt101`)

### Customer Panel
- View all available movies
- Book tickets with seat selection (1-20 seats per movie)
- View seat map (visual representation)
- Check booked ticket status

### System Features
- Maximum 20 seats per movie
- Maximum 20 movies in system
- Duplicate seat detection
- Input validation for all user inputs

---

## 🛠 Tech Stack

| Technology | Use |
|------------|-----|
| C++ | Core language |
| OOP (Classes, Inheritance, Polymorphism) | System architecture |
| Abstract Base Classes | `BookingInterface` |
| Virtual Functions | Runtime polymorphism |
| Dynamic Memory Management | Movie objects |

---

## 🎬 Demo

### Admin Panel
--- Admin Panel ---

1. Add Movie

2. View Movies

3. Remove Movie

4. Back

Choice: 1
Enter movie title: The Batman
Movie "The Batman" added successfully.


### Customer Panel - Movie List
--- Movie List ---
Movie: The Batman | Seats Left: 20
Movie: Inception | Seats Left: 20


### Seat Map
Available Seats:
[1] [2] [3] [4] [5]
[6] [7] [8] [9] [10]
[11] [12] [13] [14] [15]
[16] [17] [18] [19] [20]


**Legend:** `[X]` = Booked | `[number]` = Available

---

## 🚀 How to Run

### Prerequisites
- C++ compiler (GCC, MinGW, or any C++11 compatible compiler)

### Compile
```bash
g++ -std=c++11 -o ticket_system src/main.cpp
```
Run
```bash
./ticket_system
```
Admin Password: umt101

### Project Structure

movie-ticket-booking-system/
├── src/
│   └── main.cpp          # Full application source code
├── docs/                 # Project documentation (if any)
├── screenshots/          # Sample output screenshots
├── README.md
└── .gitignore

### Future Improvements

- File handling for persistent data storage
- GUI using Qt or web interface
- Payment integration
- Email confirmation for bookings
- User registration system
- Database integration for movie and user management

### Author
M. Nihaas Bhatti (F2024266196)
Co-Author: Salik Saeed (F2024266596)
Course: Object Oriented Programming

### License
MIT — free to use, modify, and distribute

