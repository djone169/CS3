#ifndef coffee_store_hpp
#define coffee_store_hpp

#include <stdio.h>
#include "drink.hpp"

class Customer{
public:
    Customer(std::string n = ""):
        name_(n){};

    void notify(std::string);

    bool operator==(const Customer &org){return name_ == org.name_;}
private:
    std::string name_;
};

enum Level {JuniorBarista, SeniorBarista, Manager};

class Barista{
public:
    Barista(Level l = JuniorBarista, Barista *b = nullptr):
        lvl_(l), super_(b){};

    void notify(Coffee&);

    void add_patron(Customer, Level);
    bool remove_patron(Customer, Level);
    void add_drink(Coffee, Level);
    bool remove_drink(Coffee, Level);

    void order_up();

    void print_order_complete(Coffee&);
private:
    std::vector<Customer> patrons_;
    std::vector<Coffee> orders_;
    Level lvl_;
    Barista *super_;
};

class Coffee_Store{
public:
    Coffee_Store();

    Coffee buy_drink();
    void   run_store();
private:
    Barista *bar_;
};

#endif /* coffee_store_hpp */
