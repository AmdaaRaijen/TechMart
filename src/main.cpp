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
    case 0:
      techMart.importFromFile("/home/amda/code/cpp/kuliah/Smester1/Algorithm/TechMart/src/products.txt");
      break;
    case 1:
      techMart.addProduct();
      break;
    case 2:
      techMart.displayProducts();
      break;
    case 3:
      techMart.searchProduct();
      break;
    case 4:
      techMart.showTotalInventoryValue();
      break;
    case 5:
      techMart.showLowStockProducts();
      break;
    case 6:
      techMart.sortProductsByStock();
      break;
    case 7:
      techMart.updateProductStock();
      break;
    case 8:
      techMart.deleteProduct();
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