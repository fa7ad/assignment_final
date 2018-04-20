#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Restaurant {
protected:
  string name;
  string address;
  double rating;
public:
  Restaurant (string nm, string addr, double rt) :
    name(nm), address(addr), rating(rt) {}
  virtual void showRestaurentDetails() = 0;
};


class FoodItem {
  string itemName;
  double itemPrice;
  bool available;
public:
  FoodItem () {}
  FoodItem (string item, double price, bool avl) :
    itemName(item), itemPrice(price), available(avl) {}
  void setItemDetail (string item, double price, bool avl) {
    itemName = item;
    itemPrice = price;
    available = avl;
  }
  string getItemDetail () {
    string output = string(itemName) + " ";
    output += to_string(itemPrice);
    output += string(" ");
    output += string(available ? "yes" : "no");
    return output;
  }
};

class ChineseRestaurant : public Restaurant {
  vector<FoodItem> menu;
public:
  ChineseRestaurant (string nm, string addr, double rt) :
    Restaurant (nm, addr, rt) {}
  void showRestaurentDetails () {
    cout << name << endl
      << "Chinese Restaurant" << endl
      << address << endl
      << "Rating: " << rating;
  }
};

class ItalianRestaurant : public Restaurant {
  vector<FoodItem> menu;
};

int main (void) {
  FoodItem fi = {"coke", 15, true};
  cout << fi.getItemDetail() << endl;

  return 0;
}
