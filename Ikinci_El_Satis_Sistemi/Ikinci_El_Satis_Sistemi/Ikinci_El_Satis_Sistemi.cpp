#include <iostream>  
#include <vector>  
#include <string>    

using namespace std;
// Ürün bilgilerini tutacak yapı
struct Item {
    string name;    // Ürün ismi
    double price;        // Ürün fiyatı
    string seller;  // Satıcı ismi
};

// Ürünlerin saklanacağı vektör
vector<Item> items;

// Yeni ürün ekleme fonksiyonu
void addItem() {
    Item newItem;
    cout << "Ürün ismi: ";
    cin >> newItem.name;  // Ürün ismi al
    cout << "Ürün fiyatı: ";
    cin >> newItem.price; // Ürün fiyatı al
    cout << "Satıcı ismi: ";
    cin >> newItem.seller; // Satıcı ismi al
    items.push_back(newItem);   // Yeni ürün vektöre ekle
    cout << "Ürün başarıyla eklendi!" << endl;
}

// Mevcut ürünleri listele
void listItems() {
    if (items.empty()) {
        cout << "Listede hiçbir ürün yok." << endl; // liste null ise
        return;
    }

    // Ürünlerin listelenmesi
    for (size_t i = 0; i < items.size(); ++i) {
        cout << i + 1 << ". Ürün: " << items[i].name
            << ", Fiyat: " << items[i].price
            << ", Satıcı: " << items[i].seller << endl;
    }
}

// Ürün satın al
void buyItem() {
    if (items.empty()) {
        cout << "Satın alınabilecek hiçbir ürün yok." << endl;
        return;
    }

    // Mevcut ürünleri listele
    listItems();

    size_t index;
    cout << "Satın almak istediğiniz ürünün numarasını girin: ";
    cin >> index;  // Kullanıcıdan satın almak istediği ürünün numarasımı al

    // Geçersiz ürün numarası kontrolü
    if (index < 1 || index > items.size()) {
        cout << "Geçersiz ürün numarası!" << endl; // error
        return;
    }

    string buyerName;
    cout << "Alıcı ismi: ";
    cin >> buyerName;  // Alıcı ismi al

    items.erase(items.begin() + index - 1);  // Ürünü listeden si
    cout << "Ürün başarıyla satın alındı!" << endl;
}

// Ana menüyü
void showMenu() {
    cout << "1. Yeni Ürün Ekle" << endl;
    cout << "2. Ürünleri Listele" << endl;
    cout << "3. Ürün Satın Al" << endl;
    cout << "4. Çıkış" << endl;
}

// Programın başlangıç noktası
int main() {
    setlocale(LC_ALL, "Turkish");

    cout<< "İkinci El Ürun Satış" << endl;
    while (true) {
        showMenu();  // Ana menü goster
        int choice;
        cout << "Seçiminizi yapın: ";
        cin >> choice;  // Kullanıcıdan seçim yapmasını iste

        // Kullanıcı seçimlerine göre işlemler yap
        switch (choice) {
        case 1:
            addItem();  // Yeni ürün ekle
            break;
        case 2:
            listItems();  // Ürünleri lietele
            break;
        case 3:
            buyItem();  // Ürün satın al
            break;
        case 4:
            cout << "Programdan çıkılıyor..." << endl;
            return 0;  // Exet
        default:
            cout << "Geçersiz seçim, lütfen tekrar deneyin." << endl;
        }
        cout << "********************************************" << endl;
    }

    return 0;
}
// Engin Aktaş Adiyaman Unüversitesi Biliigisayar Mühendisliği
