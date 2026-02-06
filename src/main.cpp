#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

#include "TechMart.cpp"

using namespace std;

int main()
{
  Inventory techMart;
  int choice;

  do
  {
    showMenu();

    if (!(cin >> choice))
    {
      cout << "[ERROR] Invalid input. Please enter a number.\n";
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      continue;
    }

    switch (choice)
    {
    case 1:
      techMart.addProduct();
      break;
    case 2:
      techMart.displayProducts();
      break;
    case 3:
      cout << "Searching product\n";
      break;
    case 4:
      cout << "Showing total inventory valud\n";
      break;
    case 5:
      cout << "Showing low stock products\n";
      break;
    case 6:
      cout << "Shorting product by stock\n";
      break;
    case 7:
      cout << "Editing stock\n";
      break;
    case 8:
      cout << "Deleting stock\n";
      break;
    case 9:
      cout << "\nExiting TechMart System. Goodbye!\n";
      break;
    default:
      cout << "\n[ERROR] Invalid choice. Try again.\n";
    }

  } while (choice != 9);

  return 0;
}