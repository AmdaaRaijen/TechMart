#include <iostream>

using namespace std;

void showMenu()
{
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
}