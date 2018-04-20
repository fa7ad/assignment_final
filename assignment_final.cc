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
    string output = string(itemName) + "\t\t";
    output += to_string(itemPrice) + string("\t\t");
    output += string(available ? "yes" : "no");
    return output;
  }
  bool getAvl () {
    return available;
  }
  void setAvl (bool val = false) {
    available = val;
  }
};

class ChineseRestaurant : public Restaurant {
  static vector<FoodItem> menu;
public:
  ChineseRestaurant (string nm, string addr, double rt) :
    Restaurant (nm, addr, rt) {}
  void showRestaurentDetails () {
    cout << name << " " << "Chinese Restaurant" << endl
      << address << endl
      << "Rating: " << rating << endl;
  }
  bool orderFood (unsigned int idx) {
    if (idx >= menu.size()) {
      cout << "This item is not on the menu" << endl;
      return false;
    }
    if (!menu[idx].getAvl()) {
      cout << "Sorry, This item is not available" << endl;
      cout << "Order something else" << endl;
      return false;
    }
    menu[idx].setAvl();
    return true;
  }
  void showAvailableMenu () {
    int i = 0;
    cout << "ID\tName\t\tPrice\t\tAvailable?" << endl;
    for (vector<FoodItem>::iterator f = menu.begin(); f != menu.end(); f++) {
      cout << i++ << ".\t" << f->getItemDetail() << endl;
    }
  }
};

class ItalianRestaurant : public Restaurant {
  static vector<FoodItem> menu;
public:
  ItalianRestaurant (string nm, string addr, double rt) :
    Restaurant (nm, addr, rt) {}
  void showRestaurentDetails () {
    cout << name << " " << "Italian Restaurant" << endl
      << address << endl
      << "Rating: " << rating << endl;
  }
  bool orderFood (unsigned int idx) {
    if (idx >= menu.size()) {
      cout << "This item is not on the menu" << endl;
      cout << "Order something else" << endl;
      return false;
    }
    if (!menu[idx].getAvl()) {
      cout << "Sorry, This item is not available" << endl;
      return false;
    }
    menu[idx].setAvl();
    return true;
  }
  void showAvailableMenu () {
    int i = 0;
    cout << "ID\tName\t\tPrice\t\tAvailable?" << endl;
    for (vector<FoodItem>::iterator f = menu.begin(); f != menu.end(); f++) {
      cout << i++ << ".\t" << f->getItemDetail() << endl;
    }
  }
};

vector<FoodItem> ChineseRestaurant::menu = {
  {"Wontons", 15, true},
  {"Dim sum", 20, true}
};

vector<FoodItem> ItalianRestaurant::menu = {
  {"Pizza", 5, true},
  {"Ravioli", 10, true},
  {"Risotto", 9, false}
};

int main (void) {
  cout << "What do you want to eat?" << endl;
  cout << "1: Chinese" << endl
       << "2: Italian" << endl
       << "99: Exit program" << endl;
  unsigned int n;
  cin >> n;
  if (n == 1) {
    ChineseRestaurant cn("Quanjude", "14 Qianmen West Street, Xuanwu", 4);
    cn.showRestaurentDetails();
    cn.showAvailableMenu();
    do {
      cout << "Enter an item number to order: ";
      cin >> n;
    } while (!cn.orderFood(n));
    cout << "Menu after order:" << endl;
    cn.showAvailableMenu();
  }
  if (n == 2) {
    ItalianRestaurant it("La Italiano", "Viale dei Gladiatori, 00135 Roma", 5);
    it.showRestaurentDetails();
    it.showAvailableMenu();
    do {
      cout << "Enter an item number to order: ";
      cin >> n;
    } while (!it.orderFood(n));
    cout << "Menu after order:" << endl;
    it.showAvailableMenu();
  }
  return 0;
}
