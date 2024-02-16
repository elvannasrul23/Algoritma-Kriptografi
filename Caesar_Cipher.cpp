#include<iostream>
#include<string>
#include<cctype>
using namespace std;

int main() {
    int i, key, mode;
    string s, t;

    cout << "Pilih mode:\n1. Enkripsi\n2. Dekripsi\n";
    cout << "===========\n";
    cin >> mode;

    if (mode != 1 && mode != 2) {
        cout << "Mode tidak valid.\n";
        return 1;
    }

    cout << "Masukkan pergeseran(kunci) :\n";
    cin >> key;

    cout << "Masukkan pesan :\n";
    cin.ignore(); // Membersihkan buffer sebelum membaca string
    getline(cin, s);

    for (i = 0; i < s.size(); i++) {
        if (isalpha(s[i])) {
            // Menangani hanya huruf kapital
            if (mode == 1) {
                t += (toupper(s[i]) - 'A' + key) % 26 + 'A';
            } else {
                t += (toupper(s[i]) - 'A' - key + 26) % 26 + 'A';
            }
        } else {
            // Menangani karakter non-huruf kapital
            t += s[i];
        }
    }

    if (mode == 1) {
        cout << "\n\nEncrypted message is : " << t << '\n';
    } else {
        cout << "\n\nDecrypted message is : " << t << '\n';
    }

    return 0;
}
