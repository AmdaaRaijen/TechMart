#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Struct untuk merepresentasikan data satu unit produk
struct Product
{
  string code;
  string name;
  string category;
  double price;
  int stock;
};

// Fungsi global untuk menampilkan Menu Utama
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

class Inventory
{
private:
  static const int MAX_PRODUCTS = 50; // Batas array statis
  Product products[MAX_PRODUCTS];     // Array of struct
  int productCount;                   // Counter jumlah produk aktif

  // Manipulasi String: Mengubah teks menjadi Huruf Kapital agar pencarian case-insensitive
  string toUpperCase(const string &str)
  {
    string upperStr = str;
    for (char &c : upperStr)
    {
      c = toupper(c);
    }
    return upperStr;
  }

  // Penggunaan POINTER: Mencari alamat memori produk berdasarkan kodenya
  Product *findProductByCode(const string &code)
  {
    Product *ptr = products; // Inisialisasi pointer ke awal array
    for (int i = 0; i < productCount; i++)
    {
      if ((ptr + i)->code == code) // Akses data menggunakan aritmatika pointer
      {
        return (ptr + i); // Mengembalikan alamat produk yang ditemukan
      }
    }
    return nullptr; // Jika tidak ditemukan
  }

  // FUNGSI REKURSIF: Menghitung total nilai (Harga x Stok) secara akumulatif
  double calculateTotalValueRecursive(int index)
  {
    // Base case: jika index di bawah 0, berhenti
    if (index < 0)
    {
      return 0.0;
    }
    // Recursive step: (Nilai index saat ini) + (Nilai index sebelumnya)
    return (products[index].price * products[index].stock) + calculateTotalValueRecursive(index - 1);
  }

public:
  // Constructor: Inisialisasi jumlah produk saat objek dibuat
  Inventory()
  {
    productCount = 0;
  }

  // Menambah produk baru ke dalam array
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
    cin.ignore(); // Membersihkan buffer

    newProduct.code = toUpperCase(newProduct.code);

    // Validasi String: Nama tidak boleh kosong
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
    getline(cin, newProduct.category);

    cout << "Enter product price: ";
    cin >> newProduct.price;
    // Validasi input harga negatif
    while (newProduct.price < 0)
    {
      cout << "[ERROR] Price cannot be negative. Enter again: ";
      cin >> newProduct.price;
    }

    cout << "Enter product stock: ";
    cin >> newProduct.stock;
    // Validasi input stok negatif
    while (newProduct.stock < 0)
    {
      cout << "[ERROR] Stock cannot be negative. Enter again: ";
      cin >> newProduct.stock;
    }

    products[productCount] = newProduct;
    productCount++;
    cout << "[SUCCESS] Product added successfully!\n";
  }

  // Menampilkan semua data menggunakan Pointer
  void displayProducts()
  {
    if (productCount == 0)
    {
      cout << "[INFO] No products in inventory.\n";
      return;
    }

    cout << "\n--- Product List ---\n";
    cout << left << setw(10) << "CODE" << setw(25) << "NAME" << setw(15) << "CATEGORY"
         << setw(15) << "PRICE ($)" << setw(10) << "STOCK" << endl;
    cout << string(75, '-') << endl;

    Product *ptr = products;
    for (int i = 0; i < productCount; i++)
    {
      // Menampilkan data dengan akses pointer (ptr + i)
      cout << left << setw(10) << (ptr + i)->code
           << setw(25) << (ptr + i)->name
           << setw(15) << (ptr + i)->category
           << fixed << setprecision(2) << setw(15) << (ptr + i)->price
           << setw(10) << (ptr + i)->stock << endl;
    }
  }

  // Mencari produk dengan memanggil helper findProductByCode
  void searchProduct()
  {
    string searchCode;
    cout << "\nEnter product code to search: ";
    cin >> searchCode;
    searchCode = toUpperCase(searchCode);

    Product *foundProduct = findProductByCode(searchCode);

    if (foundProduct)
    {
      cout << "\nProduct found:\n";
      cout << "Code: " << foundProduct->code << endl;
      cout << "Name: " << foundProduct->name << endl;
      cout << "Category: " << foundProduct->category << endl;
      cout << "Price: $" << fixed << setprecision(2) << foundProduct->price << endl;
      cout << "Stock: " << foundProduct->stock << endl;
    }
    else
    {
      cout << "[INFO] Product with code " << searchCode << " not found.\n";
    }
  }

  // Wrapper untuk menjalankan fungsi rekursif
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

  // Menampilkan produk dengan stok di bawah 5
  void showLowStockProducts()
  {
    cout << "\n--- Low Stock Products (Stock < 5) ---\n";
    bool found = false;
    for (int i = 0; i < productCount; i++)
    {
      if (products[i].stock < 5)
      {
        cout << "- [" << products[i].code << "] " << products[i].name << " (Stock: " << products[i].stock << ")\n";
        found = true;
      }
    }
    if (!found)
      cout << "[INFO] All stocks are sufficient.\n";
  }

  // Mengurutkan produk menggunakan Bubble Sort (Ascending)
  void sortProductsByStock()
  {
    if (productCount < 2)
      return;

    for (int i = 0; i < productCount - 1; i++)
    {
      for (int j = 0; j < productCount - i - 1; j++)
      {
        if (products[j].stock > products[j + 1].stock)
        {
          Product temp = products[j];
          products[j] = products[j + 1];
          products[j + 1] = temp;
        }
      }
    }
    cout << "\n[SUCCESS] Products sorted by stock.\n";
    displayProducts();
  }

  // Mengubah stok produk tertentu melalui pointer
  void updateProductStock()
  {
    string code;
    cout << "Enter product code to update stock: ";
    cin >> code;
    code = toUpperCase(code);

    Product *product = findProductByCode(code);
    if (product)
    {
      cout << "Current stock: " << product->stock << ". New stock: ";
      cin >> product->stock;
      cout << "[SUCCESS] Stock updated!\n";
    }
    else
    {
      cout << "[ERROR] Product not found.\n";
    }
  }

  // Menghapus produk dari array dengan menggeser elemen
  void deleteProduct()
  {
    string code;
    cout << "Enter product code to delete: ";
    cin >> code;
    code = toUpperCase(code);

    int index = -1;
    for (int i = 0; i < productCount; i++)
    {
      if (products[i].code == code)
      {
        index = i;
        break;
      }
    }

    if (index != -1)
    {
      // Menggeser semua elemen setelah index ke kiri
      for (int i = index; i < productCount - 1; i++)
      {
        products[i] = products[i + 1];
      }
      productCount--;
      cout << "[SUCCESS] Product deleted.\n";
    }
    else
    {
      cout << "[ERROR] Product not found.\n";
    }
  }
};