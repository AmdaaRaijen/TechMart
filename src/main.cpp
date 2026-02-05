#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;

int main()
{
  int choice;

  do
  {
    // Tampilan Menu
    cout << "\n========================================";
    cout << "\n   TECHMART INVENTORY MANAGEMENT SYSTEM";
    cout << "\n========================================";
    cout << "\n1. Add New Product";
    cout << "\n2. Show All Products";
    cout << "\n3. Search Product (by Code)";
    cout << "\n4. Calculate Total Inventory Value (Recursive)";
    cout << "\n5. Show Low Stock Products (< 5)";
    cout << "\n6. Sort Products by Stock";
    cout << "\n7. Edit Product Stock";
    cout << "\n8. Delete Product";
    cout << "\n9. Exit";
    cout << "\n========================================";
    cout << "\nSelect option (1-9): ";

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
      cout << "Adding product\n";
      break;
    case 2:
      cout << "Displaying product\n";
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