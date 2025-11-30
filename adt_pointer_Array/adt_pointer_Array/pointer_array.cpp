#include <iostream>
using namespace std;

int main() {
    // Deklarasi array
    // int angka[5] = {10, 20, 30, 40, 50};
    string angka[5] = {"A", "B", "C", "D", "E"};
    // Pointer ke elemen pertama array
    string *ptr = angka;  // sama dengan &angka[0]

    // &angka[0] adalah alamat elemen pertama, sehingga pointer dapat menjelajah seluruh array dengan aman.
    // &angka[3] sah dan valid, tetapi pointer hanya semestinya digunakan untuk membaca dari elemen itu dan seterusnya — bukan awal array.

    cout << " Alamat angka :" << ptr <<endl;
    // Menampilkan elemen array dan alamatnya
    cout << "Data isi array dan alamat memorinya:" <<endl;
    for (int i = 0; i < 5; i++) {
        cout << "angka[" << i << "] = " << angka[i]
             << "\tAlamat: " << &angka[i]
             << "\tMelalui pointer: " << *(ptr + i)
             << endl;
    }

    return 0;
}
