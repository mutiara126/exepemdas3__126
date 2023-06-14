#include <iostream>
using namespace std;

class bidangDatar {
private: 
	int x;  //variabel untuk menyimpan inpur dari lingkaran maupun bujur sangkar
public:
	bidangDatar() { //constructor
		x = 0;
	}
	virtual void input() {} //fungsi yang menerima input dan mengirim input melalui fungsi setX untuk disimpan di x
	virtual float luas(int a) { return 0;} //fungsi untuk menghitung luas
	virtual float keliling(int a) { return 0; } //fungsi untuk menghitung keliling
	void setx(int a) { //fungsi untuk memberi/mengirim nilai pada x
		this->x = a;
	}
	int getx() {   //fungsi untuk membaca/mengambil nilai dalam x
		return x;
	}
};
class Lingkaran :public bidangDatar {
public:
	void input() {
		cout << "Masukkan jejari: ";
		int r;
		cin >> r;
		setx(r);
	}
	float Luas(int r) {
		return 3.14 * r * r;
	}
	float keliling(int r) {
		return 2 * 3.14 * r;
	}
};
class Bujursangkar : public bidangDatar {
public:
	void input() {
		cout << "Masukkan sisi: ";
		int s;
		cin >> s;
		setx(s);
    }
	float Luas(int s) {
		return s * s;
	}
	float keliling(int s) {
		return 4 * s;
	}
};

int main() {
	bidangDatar* bd; //pointer untuk objek polymorphic
	Lingkaran lingkaran;
	Bujursangkar bujursangkar;

	//Lingkaran
	cout << "Lingkaran dibuat" << endl;
	lingkaran.input();
	bd = &lingkaran;
	cout << "Luas Lingkaran = " << bd->luas(bd->getx()) << endl;
	cout << "Keliling Lingkaran = " << bd->keliling(bd->getx()) << endl;

	//Bujursangkar
	cout << "Bujursangkar dibuat" << endl;
	bujursangkar.input();
	bd = &bujursangkar;
	cout << "Luas Bujursangkar = " << bd->luas(bd->getx()) << endl;
	cout << "Keliling Bujursangkar = " << bd->keliling(bd->getx()) << endl;

	return 0;
};