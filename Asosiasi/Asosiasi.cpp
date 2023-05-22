#include <iostream>
#include <vector>
using namespace std;

class dokter;
class pasien {
public:
	string nama;
	vector<dokter*> daftar_dokter;
	pasien(string pNama) :nama (pNama) {
		cout << "Pasien \"" << nama "\" ada\n";
	}
	~pasien() {
		cout << "Pasien \"" << nama "\" tidak ada\n";
	}
};

class dokter {
	string nama;
	vector<pasien*> daftar_pasien;

	dokter(string pNama) : nama(pNama) {
		cout << "Dokter \"" << nama << "\" ada\n";
	}
	~dokter() {
		cout << "Dokter \"" << nama << "\" tidak ada\n";
	}
	void tambahPasien(pasien*);
	void cetakPasien();
};
void pasien::tambahPasien(pasien* pPasien) {
	daftar_pasien.push_back(pPasien);
	pPasien->tambahDokter(this); 
}
void dokter::cetakPasien() {
	cout << "Daftar Pasien dari Dokter \"" << this->nama << "\":\n";
	for (auto& a : daftar_pasien) {
		cout << a->nama << "\n";
	}
	cout << endl;
}