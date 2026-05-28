// M.NIHAAS BHATTI --- F2024266196

#include <iostream>
#include <string>
#include <limits>
using namespace std;

class BookingInterface
{

public:

    virtual void showDetails() = 0;

};

class Movie
{

private:

    string title;
    bool bookedSeats[20];

public:

    Movie(string t = "")
    {

        title = t;
        for (int i = 0; i < 20; i++)
        {
            bookedSeats[i] = false;
        }

    }

    Movie(const Movie& m)
    {

        title = m.title;
        for (int i = 0; i < 20; i++)
        {
            bookedSeats[i] = m.bookedSeats[i];
        }

    }

    ~Movie()
    {

    }

    string getTitle()
    {
        return title;
    }

    int getAvailableSeats()
    {

        int count = 0;
        for (int i = 0; i < 20; i++)
        {
            if (!bookedSeats[i])
            {
                count++;
            }
        }

        return count;

    }

    void showSeatMap()
    {

        cout << "\nAvailable Seats:\n";
        for (int i = 0; i < 20; i++)
        {

            if (bookedSeats[i])
            {
                cout << "[X] ";
            }
            else
            {
                cout << "[" << i + 1 << "] ";
            }

            if ((i + 1) % 5 == 0)
            {
                cout << endl;
            }

        }

    }

    bool bookSeat(int seatNumber)
    {

        if (seatNumber < 1 || seatNumber > 20)
        {
            cout << "Invalid seat number.\n";
            return false;
        }

        if (bookedSeats[seatNumber - 1])
        {
            cout << "Seat already booked.\n";
            return false;
        }

        bookedSeats[seatNumber - 1] = true;
        return true;

    }

    void showDetails()
    {
        cout << "Movie: " << title << " | Seats Left: " << getAvailableSeats() << endl;
    }

};

void clearInput()
{

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

}

class User
{

protected:

    string username;

public:

    User(string name = "")
    {
        username = name;
    }

    virtual void showDetails() = 0;

};

class Customer : public User, public BookingInterface
{

public:

    Movie* bookedMovie;

public:

    Customer(string name = "") : User(name)
    {
        bookedMovie = nullptr;
    }

    void bookMovie(Movie* m)
    {

        int available = m->getAvailableSeats();
        if (available == 0)
        {
            cout << "No seats available!\n";
            return;
        }

        cout << "Total available seats: " << available << endl;
        int ticketCount;
        cout << "How many tickets do you want to book? ";
        cin >> ticketCount;

        if (cin.fail() || ticketCount <= 0 || ticketCount > available)
        {
            clearInput();
            cout << "Invalid ticket count.\n";
            return;
        }

        m->showSeatMap();
        for (int i = 0; i < ticketCount; i++)
        {
            int seat;
            cout << "Enter seat number for ticket #" << i + 1 << ": ";
            cin >> seat;
            if (m->bookSeat(seat))
            {
                cout << "Seat #" << seat << " booked successfully.\n";
            }
            else
            {
                cout << "Failed to book seat #" << seat << ". Try again.\n";
                i--;
            }
        }

        bookedMovie = m;
        cout << ticketCount << " ticket(s) booked for " << m->getTitle() << " successfully.\n";

    }

    void showDetails()
    {

        cout << "Customer: " << username << endl;
        if (bookedMovie)
        {
            cout << "You have booked tickets for: " << bookedMovie->getTitle() << endl;
        }
        else
        {
            cout << "No ticket booked yet.\n";
        }

    }

};

class Admin : public User, public BookingInterface
{

public:

    Admin(string name = "") : User(name)
    {

    }

    void showDetails()
    {
        cout << "Admin: " << username << endl;
    }

};

class TicketSystem
{

private:

    Movie* movies[20];
    int movieCount;

public:

    TicketSystem()
    {

        for (int i = 0; i < 20; i++)
        {
            movies[i] = nullptr;
        }
        movieCount = 0;

    }

    ~TicketSystem()
    {

        for (int i = 0; i < movieCount; i++)
        {
            delete movies[i];
        }

    }

    void addMovie(string title)
    {

        if (movieCount >= 20)
        {
            cout << "Cannot add more movies.\n";
            return;
        }

        movies[movieCount++] = new Movie(title);
        cout << "Movie \"" << title << "\" added successfully.\n";

    }

    void removeMovie(string title)
    {

        for (int i = 0; i < movieCount; ++i)
        {
            if (movies[i]->getTitle() == title)
            {
                delete movies[i];
                for (int j = i; j < movieCount - 1; j++)
                {
                    movies[j] = movies[j + 1];
                }
                movies[--movieCount] = nullptr;
                cout << "Movie \"" << title << "\" removed successfully.\n";
                return;
            }
        }

        cout << "Movie not found.\n";

    }

    void viewMovies()
    {

        if (movieCount == 0)
        {
            cout << "No movies available.\n";
            return;
        }

        cout << "\n--- Movie List ---\n";
        for (int i = 0; i < movieCount; i++)
        {
            movies[i]->showDetails();
        }

    }

    Movie* getMovie(string title)
    {

        for (int i = 0; i < movieCount; i++)
        {
            if (movies[i]->getTitle() == title)
            {
                return movies[i];
            }
        }

        return nullptr;

    }

};

int main()
{

    TicketSystem system;
    Admin admin("AdminBOSS");
    Customer customer("JohnDoe");

    int choice;

    do
    {

        cout << "\n1. Customer Panel\n2. Admin Panel\n3. Exit\nChoice: ";
        cin >> choice;

        if (cin.fail())
        {
            clearInput();
            cout << "Invalid input. Try again.\n";
            continue;
        }

        if (choice == 1)
        {

            int c;
            do
            {

                cout << "\n--- Customer Panel ---\n";
                cout << "1. View Movies\n2. Book Ticket\n3. My Ticket\n4. Back\nChoice: ";
                cin >> c;

                if (cin.fail())
                {
                    clearInput();
                    cout << "Invalid input.\n";
                    continue;
                }

                if (c == 1)
                {
                    system.viewMovies();
                }
                else if (c == 2)
                {

                    cout << "\n--- Available Movies ---\n";
                    system.viewMovies();
                    string title;
                    cout << "Enter movie title: ";
                    cin.ignore();
                    getline(cin, title);

                    if (title.empty())
                    {
                        cout << "Title cannot be empty.\n";
                        continue;
                    }

                    Movie* m = system.getMovie(title);
                    if (m)
                    {
                        customer.bookMovie(m);
                    }
                    else
                    {
                        cout << "Movie not found.\n";
                    }

                }
                else if (c == 3)
                {
                    customer.showDetails();
                }
                else if (c == 4)
                {
                    cout << "Returning to main menu...\n";
                }

            } while (c != 4);

        }
        else if (choice == 2)
        {

            string pass;
            cout << "Enter Admin Password: ";
            cin >> pass;

            if (pass != "umt101")
            {
                cout << "Access denied.\n";
                continue;
            }

            admin.showDetails();

            int a;
            do
            {

                cout << "\n--- Admin Panel ---\n";
                cout << "1. Add Movie\n2. View Movies\n3. Remove Movie\n4. Back\nChoice: ";
                cin >> a;

                if (cin.fail())
                {
                    clearInput();
                    cout << "Invalid input.\n";
                    continue;
                }

                if (a == 1)
                {
                    string title;
                    cout << "Enter movie title: ";
                    cin.ignore();
                    getline(cin, title);

                    if (title.empty())
                    {
                        cout << "Title cannot be empty.\n";
                        continue;
                    }

                    system.addMovie(title);

                }
                else if (a == 2)
                {
                    system.viewMovies();
                }
                else if (a == 3)
                {

                    string title;
                    cout << "Enter movie title to remove: ";
                    cin.ignore();
                    getline(cin, title);

                    if (title.empty())
                    {
                        cout << "Title cannot be empty.\n";
                        continue;
                    }

                    system.removeMovie(title);

                }
                else if (a == 4)
                {
                    cout << "Returning to main menu...\n";
                }

            } while (a != 4);

        }
        else if (choice == 3)
        {
            cout << "Thank you for using the Ticket Booking System. Goodbye!\n";
        }

    } while (choice != 3);

    return 0;

}