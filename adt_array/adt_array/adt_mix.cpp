#include <iostream>
#include <string>
using namespace std;

struct Person {
    string name;
    int age;

    // Contoh array pada struct
    string hobbies[3];  // Fixed size array
    
    // Variabel biasa tambahan
    float height;       // tinggi cm
    bool isStudent;
};

int main() {
    Person person1;

    // Mengisi nilai variabel biasa
    person1.name = "John";
    person1.age = 25;
    person1.height = 175.5;
    person1.isStudent = true;

    // Mengisi array dalam struct
    person1.hobbies[0] = "Reading";
    person1.hobbies[1] = "Gaming";
    person1.hobbies[2] = "Swimming";

    // Output
    cout << "=== Person Information ===" << endl;
    cout << "Name     : " << person1.name << endl;
    cout << "Age      : " << person1.age << endl;
    cout << "Height   : " << person1.height << " cm" << endl;
    cout << "Student? : " << (person1.isStudent ? "Yes" : "No") << endl;

    cout << "\nHobbies: " << endl;
    for (int i = 0; i < 3; i++) {
        cout << "- " << person1.hobbies[i] << endl;
    }

    return 0;
}
