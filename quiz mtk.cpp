/*
Nama : Muhammad Azka Taslimi
NPM : 24340007
Judul program : Quiz operasi matematika
Deskripsi : Permainan sederhana di mana pengguna harus menjawab pertanyaan matematika dengan benar.
*/
#include <iostream>
#include <cstdlib> // Untuk fungsi rand() dan srand()
#include <ctime>   // Untuk fungsi time()
#include <iomanip> //Untuk std::fixed dan std::setprecision(

using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0))); // Menginisialisasi seed untuk angka acak
    // static_cast: operator casting di C++ yang digunakan untuk mengkonversi tipe data dari satu jenis ke jenis lainnya dengan cara yang aman.
    char continueQuiz; // Variabel untuk menyimpan pilihan pengguna

    do {
        // Menghasilkan dua angka acak antara 1 sampai 20
        int num1 = rand() % 20 + 1; // Angka pertama
        int num2 = rand() % 20 + 1; // Angka kedua

        // Menghasilkan operasi acak (0: penjumlahan, 1: pengurangan, 2: perkalian)
        int operation = rand() % 4; // menghasilkan 4 operasi matematika

        double correctAnswer; // Variabel untuk menyimpan jawaban yang benar

        // Menentukan operasi dan jawaban yang benar
        if (operation == 0) { // Penjumlahan
            correctAnswer = num1 + num2;
            cout << "Apa hasil dari " << num1 << " + " << num2 << "? ";
        } else if (operation == 1) { // Pengurangan
            correctAnswer = num1 - num2;
            cout << "Apa hasil dari " << num1 << " - " << num2 << "? ";
        } else if (operation == 2) {//Perkalian
            correctAnswer = num1 * num2;
            cout << "Apa hasil dari " << num1 << " * " << num2 << "? ";
        }else {//Pembagian
            //Memastikan angka pertama tidak lebih kecil dari angka kedua
            if(num1 < num2){
                swap(num1, num2);
            }
            correctAnswer = static_cast<float> (num1) / num2;
            cout << "Apa hasil dari " << num1 << " / " << num2 << "? ";
        }
        // Menerima jawaban pengguna
        float userAnswer; // Variabel untuk menyimpan jawaban pengguna
        cin >> userAnswer; // Mengambil input dari pengguna

        // Memeriksa jawaban
        if (userAnswer == correctAnswer) {
            cout << "\nYeayyy benar!" << endl;
        } else {
           cout << fixed << setprecision(1); //agar angka di belakang koma tidak terlalu banyak
            cout << "\nYah, jawaban Kamu salah :( \n\nJawaban yang benar adalah " << correctAnswer << endl;
        }

        // Menanyakan apakah pengguna ingin mencoba lagi
        cout << "Apakah Kamu mau mencoba lagi? (y/n): ";
        cin >> continueQuiz;

    } while (continueQuiz == 'y' || continueQuiz == 'Y'); // Mengulangi jika pengguna menjawab 'y' atau 'Y'

    cout << "Terima kasih telah bermain!" << endl; // Pesan penutup
    return 0; // Mengakhiri program
}