#include <iostream>
#include <vector>
using namespace std;

class Karyawan;
class Perusahaan {
public:
	string namaPerusahaan;
	vector<Karyawan*> daftarKaryawan;

	Perusahaan(string pNamaPerusahaan) : namaPerusahaan(pNamaPerusahaan) {
		cout << "-----------------------------------" << endl;
		cout << "Perusahaan dibuat dengan nama :" << namaPerusahaan << endl;
		cout << "-----------------------------------" << endl;
	}

	~Perusahaan() {
		cout << "-----------------------------" << endl;
		cout << "Perusahaan dimusnahkan" << endl;
	}

	void tambahKaryawan(Karyawan*);
	void cetakKaryawan();
};

class Proyek {
public:
	string namaProyek;
	vector<Karyawan*> daftarKaryawan;

	Proyek(string pNama) : namaProyek(pNama) {
		cout << "------------------------------------------" << endl;
		cout << "Proyek dibuat dengan nama :" << namaProyek << endl;
		cout << "------------------------------------------" << endl;
	}

	~Proyek() {
		cout << "-------------------------------" << endl;
		cout << "Proyek dihancurkan" << endl;
	}

	void tambahKaryawan(Karyawan*);
	void cetakKaryawan();
};

class Karyawan {
public:
	string namaKaryawan;
	vector<Proyek*> daftarProyek;
	vector<Perusahaan*> daftarPerusahaan;

	Karyawan(string pNamaKaryawan) : namaKaryawan(pNamaKaryawan) {
		cout << "----------------------------------" << endl;
		cout << "Nama karyawan yang terdaftar :" << namaKaryawan << endl;
		cout << "----------------------------------" << endl;
	}

	~Karyawan() {
		cout << "-----------------------------" << endl;
		cout << "Karyawan dikeluarkan" << endl;
	}

	void tambahProyek(Proyek*);
	void tambahPerusahaan(Perusahaan*);
	void cetakProyek();
	void cetakPerusahaan();
};

void Proyek::tambahKaryawan(Karyawan* pKaryawan) {
	daftarKaryawan.push_back(pKaryawan);
}

void Proyek::cetakKaryawan() {
	cout << "----------------------------------------" << endl;
	cout << "Daftar karyawan yang ada di proyek :" << this->namaProyek << ":" << endl;
	for (auto& a : daftarKaryawan) {
		cout << a->namaKaryawan << endl;
	}
	cout << "----------------------------------------" << endl;
	cout << endl;
}

void Perusahaan::tambahKaryawan(Karyawan* pKaryawan) {
	daftarKaryawan.push_back(pKaryawan);
}

void Perusahaan::cetakKaryawan() {
	cout << "--------------------------------------------" << endl;
	cout << "Nama karyawan di perusahaan :" << this->namaPerusahaan << ":" << endl;
	for (auto& a : daftarKaryawan) {
		cout << a->namaKaryawan << endl;
	}
	cout << "----------------------------------------" << endl;
	cout << endl;
}

void Karyawan::tambahProyek(Proyek* pProyek) {
	daftarProyek.push_back(pProyek);
}

void Karyawan::cetakProyek() {
	cout << "--------------------------------------------" << endl;
	cout << "Daftar proyek dengan atas nama :" << this->namaKaryawan << ":" << endl;
	for (auto& a : daftarProyek) {
		cout << a->namaProyek << endl;
	}
	cout << "--------------------------------------------" << endl;
	cout << endl;
}

void Karyawan::tambahPerusahaan(Perusahaan* pPerusahaan) {
	daftarPerusahaan.push_back(pPerusahaan);
}

void Karyawan::cetakPerusahaan() {
	cout << "------------------------------------------------" << endl;
	cout << "Daftar karyawan yang ada di PT.Maju Mundur :" << this->namaKaryawan << ":" << endl;
	for (auto& a : daftarPerusahaan) {
		cout << a->namaPerusahaan << endl;
	}
	cout << "------------------------------------------------" << endl;
	cout << endl;
}

int main() {
	Perusahaan* varPerusahaan1 = new Perusahaan("PT.Maju Mundur");
	Proyek* varProyek1 = new Proyek("Sistem Keamanan");
	Proyek* varProyek2 = new Proyek("Sistem Informasi");
	Karyawan* varKaryawan1 = new Karyawan("Budi");
	Karyawan* varKaryawan2 = new Karyawan("Andi");
	Karyawan* varKaryawan3 = new Karyawan("Rafi");

	varPerusahaan1->tambahKaryawan(varKaryawan1);
	varPerusahaan1->tambahKaryawan(varKaryawan2);
	varPerusahaan1->tambahKaryawan(varKaryawan3);

	varProyek1->tambahKaryawan(varKaryawan1);
	varProyek1->tambahKaryawan(varKaryawan3);
	varProyek2->tambahKaryawan(varKaryawan1);
	varProyek2->tambahKaryawan(varKaryawan2);

	varKaryawan1->tambahProyek(varProyek1);
	varKaryawan1->tambahProyek(varProyek2);
	varKaryawan2->tambahProyek(varProyek2);
	varKaryawan3->tambahProyek(varProyek1);

	varPerusahaan1->cetakKaryawan();
	varProyek1->cetakKaryawan();
	varProyek2->cetakKaryawan();
	varKaryawan1->cetakPerusahaan();
	varKaryawan2->cetakPerusahaan();
	varKaryawan1->cetakProyek();
	varKaryawan2->cetakProyek();
	varKaryawan3->cetakProyek();

	delete varPerusahaan1;
	delete varProyek1;
	delete varProyek2;
	delete varKaryawan1;
	delete varKaryawan2;
	delete varKaryawan3;
}
