#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

string bersihkan_Dan_Kecilkan_Hurufnya_2031(string str) {
    string cleanStr;
    for (char &c : str) {
        if (isalpha(c)) {
            cleanStr += tolower(c);
        }
    }
    return cleanStr;
}

string balik_Kalimat_2031(string kalimat) {
    stack<char> tumpukanKarakter;
    string kalimat_Terbalik_2031;

    kalimat = bersihkan_Dan_Kecilkan_Hurufnya_2031(kalimat);

    for (char c : kalimat) {
        if (c != ' ') {
            tumpukanKarakter.push(c);
        } else {
            while (!tumpukanKarakter.empty()) {
                kalimat_Terbalik_2031 += tumpukanKarakter.top();
                tumpukanKarakter.pop();
            }
            kalimat_Terbalik_2031 += ' ';
        }
    }

    while (!tumpukanKarakter.empty()) {
        kalimat_Terbalik_2031 += tumpukanKarakter.top();
        tumpukanKarakter.pop();
    }

    return kalimat_Terbalik_2031;
}

int main() {
    string kalimat_2031;
    char lanjutkan_2031;

    do {
        cout << "\nMasukkan kata atau kalimat (minimal 3 kata): ";
        getline(cin, kalimat_2031);

        int jumlah_Spasi_2031 = count(kalimat_2031.begin(), kalimat_2031.end(), ' ');
        int jumlah_Kata_2031 = jumlah_Spasi_2031 + 1;

        if (jumlah_Kata_2031 < 3) {
            cout << "Masukkan minimal 3 kata!" << endl;
        } else {
            string kalimatTerbalik = balik_Kalimat_2031(kalimat_2031);
            cout << "Kalimat Terbalik: " << kalimatTerbalik << endl; 
        }

        cout << "Apakah ingin memasukkan kata atau kalimat lagi? (y/n): ";
        cin >> lanjutkan_2031;
        cin.ignore();
    } while (lanjutkan_2031 == 'y' || lanjutkan_2031 == 'Y');

    return 0;
}