#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	const int MAX_MAHASISWA = 100;
	int rollNumber;
	string name;
	string jurusan;
	int tahunMasuk;
	int jumlahMahasiswa;
	Node* next;
	Node* LAST;
};

class sorting {
private:
	Node* LAST;
public:
	sorting() {
		LAST = NULL;
	}
	void addNode();
	bool search(int rollno, Node** previous, Node** current);
	bool listEmpty();
	void traverse();
	void searchdata();
	void algorithmaSortByTahunMasuk();
};
void sorting::addNode() {
	int nim;
	string nama;
	string jurusan;
	int tahunMasuk;
	Node* nodeBaru = new Node();
	cout << "|Masukan Nim :     ";
	cin >> nim;
	cout << "|Masukan Nama :    ";
	cin >> nama;
	cout << "jurusan:    ";
	cin >> jurusan;
	cout << "|Masukan tahun masuk :     ";
	cin >> tahunMasuk;
	nodeBaru->rollNumber = nim;
	nodeBaru->name = nama;
	nodeBaru->tahunMasuk = tahunMasuk;
	nodeBaru->jurusan = jurusan;

	if (LAST == NULL || nim <= LAST->rollNumber) {
		if (LAST != NULL && nim == LAST->rollNumber)
		{
			cout << "|   NIM sudah ada   |" << endl;
			return;
		}

		nodeBaru->next = LAST;
		LAST = nodeBaru;
		return;
	}

	Node* previous = LAST;
	Node* current = LAST;

	while ((current != NULL) && (nim >= current->rollNumber))
	{
		if (nim == current->rollNumber) {
			cout << "NIM sudah ada" << endl;
			return;
		}
		previous = current;
		current = current->next;
	}

	nodeBaru->next = current;
	previous->next = nodeBaru;
}
bool sorting::search(int rollno, Node** previous, Node** current) {
	*previous = LAST->next;
	*current = LAST->next;
	while (*current != LAST) {
		if (rollno == (*current)->rollNumber) {
			return true;
		}
		*previous = *current;
		*current = (*current)->next;
	}
	if (rollno == LAST->rollNumber) {
		return true;
	}
	else {
		return false;
	}
}
bool sorting::listEmpty() {
	if (LAST == NULL)
		return true;
	else
		return false;

	return LAST == NULL;
}

void sorting::traverse() {
	if (listEmpty()) {
		cout << "List Kosong" << endl;
		system("pause");
		system("cls");
		return;
	}
	else {
		Node* currentNode = LAST;
		while (currentNode != NULL) {
			cout << "_______________________________________________________________________" << endl;
			cout << "|\tNim\t| nama mahasiswa |  tahun masuknya  | jurusann \t|" << endl;
			cout << "|     " << currentNode->rollNumber << "\t\t| " << currentNode->name << "\t\t| " << currentNode->tahunMasuk << "\t " << currentNode->jurusan << endl;
			cout << "________________________________________________________________________" << endl;
			cout << endl;
			currentNode = currentNode->next;
		}
	}

}
void sorting::searchdata() {
	if (listEmpty()) {
		cout << "List Kosong" << endl;
		system("pause");
		system("cls");
		return;
	}
	else {
		int nim;
		int tahunMasuk;
		string jurusan;
		cout << "Masukan NIM: ";
		cin >> nim;
		cout << "tahun masuk; ";
		cin >> tahunMasuk;
		cout << "jurusan:     ";
		cin >> jurusan;
		Node* currentNode = LAST;
		while (currentNode != NULL) {
			if (currentNode->rollNumber == nim) {
				cout << "________________________________________________" << endl;
				cout << "|\tNim\t\t| nama mahasiswa\t\t | tahun masuk  |\t\t jurusan \t\t |" << endl;
				cout << "|" << currentNode->rollNumber << "\t\t| " << currentNode->name  << "\t\t| " << currentNode->tahunMasuk << "\t| " << currentNode->jurusan << endl;
				cout << "________________________________________________" << endl;
				cout << endl;
				cout << "|  NIM TERSEDIA  | " << endl;
				cout << endl;
				cout << "__________________________________________________________________________" << endl;
				return;
			}
			currentNode = currentNode->next;
		}
		cout << "Data tidak ditemukan" << endl;
	}
}
void sorting::algorithmaSortByTahunMasuk() {
	if (listEmpty()) {
		cout << "List Kosong" << endl;
		system("pause");
		system("cls");
		return;
	}
	else {
		Node* currentNode = LAST;
		while (currentNode != NULL) {
			cout << "________________________________________________" << endl;
			cout << "|\ttahun masuk\t\t| \t\tjurusan \t\t" << endl;
			cout << "|     " << currentNode->tahunMasuk << currentNode->jurusan << endl;
			cout << "________________________________________________" << endl;
			cout << endl;
			currentNode = currentNode->next;
		}
	}
}


int main() {

	sorting obj;
	int pilihan;
	do {
		cout << "========== MENU MANAJEMEN DATA MAHASISWA ==========" << endl;
		cout << "1. Tambah Mahasiswa" << endl;
		cout << "2. Tampilkan Semua Mahasiswa" << endl;
		cout << "3. Cari Mahasiswa berdasarkan NIM" << endl;
		cout << "4. Tampilkan Mahasiswa berdasarkan Tahun Masuk" << endl;
		cout << "5. Keluar" << endl;
		cout << "Pilihan: ";
		cin >> pilihan;
		cin.ignore();
		switch (pilihan) {
		case 1:
			obj.addNode();
			break;
		case 2:
			obj.traverse();
			break;
		case 3:
			obj.searchdata();
			break;
		case 4:
			obj.algorithmaSortByTahunMasuk();
			break;
		default:
			cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
		}
		cout << endl;
	} while (pilihan != 5);
	return 0;
}





//2. Berdasarkan studi kasus diatas, algoritma apa saja yang anda gunakan ? menggunakan algoritma linked list untuk mengsetting secara dinamis lalu di sorting (10 Poin)
//3. Jelaskan perbedaan mendasar antara algorithma stack dan queue! perbedaan nya terdapat pada algoritma di mana stack itu tumpukan apabila terakhir di masukan pertama keluar (LIFO) ,QUEUE adalah antrian dimana yang pertama masuk maka dia akan pertma keluar (fifo)(15 Poin)
//4. Jelaskan pada saat bagaimana harus menggunakan algorithma stack ? pada saat di butuhkan untuk menyimpan data dengan cara di tumpuk supaya data dapat di simpan ,contoh nya pada (UNDO)  saat men delete kata di word (15 poin)
//5. Perhatikan gambar berikut : (20 Poin)
//a.Seberapa banyak kedalaman yang dimiliki struktur tersebut ? 4 level
//b.Bagaimana cara membaca struktur pohon di atas ? post order traversal (Pilih salah satu metode yaitu
	//Inorder, Preorder atau Postorder Traversal
