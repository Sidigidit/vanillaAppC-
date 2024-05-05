#include <iostream>

int main() {
    int a, b;

    // Meminta pengguna untuk memasukkan nilai a
    std::cout << "Enter a value: ";
    std::cin >> a;

    // Meminta pengguna untuk memasukkan nilai b
    std::cout << "Enter b value: ";
    std::cin >> b;

    // Menampilkan pesan ke layar
    std::cout << "Hello!" << std::endl;
    std::cout << "Hasil penjumlahan " << a << " + " << b << " = " << a + b << std::endl;

    // Menentukan jika hasil penjumlahan lebih besar dari 5
    if (a + b > 5) {
        std::cout << "Nilai hasil penjumlahan lebih besar dari 5" << std::endl;
    }

    // Mencetak angka dari 1 hingga a
    std::cout << "Mencetak angka dari 1 hingga " << a << ":" << std::endl;
    for (int i = 1; i <= a; ++i) {
        std::cout << i << std::endl;
    }

    return 0;
}
