#include <iostream>
#include <string>
#include <iomanip>

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

struct Product
{
  string code;
  string name;
  string categroy;
  double price;
  int stock;
};

class Inventory
{
private:
  static const int MAX_PRODUCTS = 50;
  Product products[MAX_PRODUCTS];
  int productCount;

  string toUpperCase(const string &str)
  {
    string upperStr = str;
    for (char &c : upperStr)
    {
      c = toupper(c);
    }
    return upperStr;
  }

  Product *findProductByCode(const string &code)
  {
    Product *ptr = products;
    for (int i = 0; i < productCount; i++)
    {
      if ((ptr + i)->code == code)
      {
        return (ptr + i);
      }
    }
    return nullptr;
  }

  double calculateTotalValueRecursive(int index)
  {
    if (index < 0)
    {
      return 0.0;
    }

    return products[index].price * products[index].stock + calculateTotalValueRecursive(index - 1);
  }

public:
  Inventory()
  {
    productCount = 0;
  }

  void addProduct()
  {
    if (productCount >= MAX_PRODUCTS)
    {
      cout << "[ERROR] Inventory full. Cannot add more products.\n";
      return;
    }

    Product newProduct;
    cout << "Enter product code: ";
    cin >> newProduct.code;

    cin.ignore();

    newProduct.code = toUpperCase(newProduct.code);

    do
    {
      cout << "Enter product name: ";
      getline(cin, newProduct.name);
      if (newProduct.name.empty())
      {
        cout << "[ERROR] Product name cannot be empty.\n";
      }
    } while (newProduct.name.empty());

    cout << "Enter product category (Smartphone/Laptop/Accessories): ";
    cin >> newProduct.categroy;

    cout << "Enter product price: ";
    cin >> newProduct.price;

    while (newProduct.price < 0)
    {
      cout << "[ERROR] Price cannot be negative. Enter again: ";
      cin >> newProduct.price;
    }

    cout << "Enter product stock: ";
    cin >> newProduct.stock;

    while (newProduct.stock < 0)
    {
      cout << "[ERROR] Stock cannot be negative. Enter again: ";
      cin >> newProduct.stock;
    }

    products[productCount] = newProduct;
    productCount++;
    cout << newProduct.code << " | " << newProduct.name << " | " << newProduct.categroy << " | $" << newProduct.price << " | Stock: " << newProduct.stock << "\n";
    cout << "[SUCCESS] Product added successfully!\n";
  }

  void displayProducts()
  {
    if (productCount == 0)
    {
      cout << "[INFO] No products in inventory.\n";
      return;
    }

    cout << "\n--- Product List ---\n";
    cout << left << setw(10) << "CODE"
         << setw(25) << "NAME"
         << setw(15) << "CATEGORY"
         << setw(15) << "PRICE ($)"
         << setw(10) << "STOCK" << endl;
    cout << string(75, '-') << endl;

    Product *ptr = products;
    for (int i = 0; i < productCount; i++)
    {
      cout << left << setw(10) << (ptr + i)->code
           << setw(25) << (ptr + i)->name
           << setw(15) << (ptr + i)->categroy
           << fixed << setprecision(2) << setw(15) << (ptr + i)->price
           << setw(10) << (ptr + i)->stock << endl;
    }
  }

  void searchProduct()
  {
    string searchCode;

    cout << "\nEnter product code to search: ";
    cin >> searchCode;
    searchCode = toUpperCase(searchCode);

    Product *ptr = products;
    Product *foundProduct = findProductByCode(searchCode);

    if (foundProduct)
    {
      cout << "\nProduct found:\n";
      cout << "Code: " << foundProduct->code << endl;
      cout << "Name: " << foundProduct->name << endl;
      cout << "Category: " << foundProduct->categroy << endl;
      cout << "Price: $" << fixed << setprecision(2) << foundProduct->price << endl;
      cout << "Stock: " << foundProduct->stock << endl;
    }
    else
    {
      cout << "[INFO] Product with code " << searchCode << " not found.\n";
    }
  }

  void showTotalInventoryValue()
  {
    if (productCount == 0)
    {
      cout << "[INFO] No products in inventory.\n";
      return;
    }

    double totalValue = calculateTotalValueRecursive(productCount - 1);

    cout << "\n--- Inventory Analysis ---\n";
    cout << "Total Items: " << productCount << endl;
    cout << "Total Inventory Value: $" << fixed << setprecision(2) << totalValue << endl;
  }
};
