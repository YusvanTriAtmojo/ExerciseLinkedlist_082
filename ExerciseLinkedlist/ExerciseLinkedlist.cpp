#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int rollNumber;
	string name;
	Node* next;
};

class CircularLinkedList {
private:
	Node* LAST;
public:
	CircularLinkedList() {
		LAST = NULL;
	}
	void addNode();
	bool search(int rollno, Node** previous, Node** current);
	bool listEmpty(); 
	bool delNode(int element); 
	void traverse();
};
void CircularLinkedList::addNode() { //Write your answer here
	int rollno;
	string nm;
	cout << "\nMasukkan nomor: "; //Memasukkan data
	cin >> rollno;
	cout << "\nMasukkan nama: ";
	cin >> nm;
	Node* nodeBaru = new Node; //Membuat node baru untuk memasukkan data
	nodeBaru->rollNumber = rollno;

	//Add diawal
	if (LAST == NULL) {
		nodeBaru->next = nodeBaru;
		LAST = nodeBaru;
	}
	else {
		nodeBaru->next = LAST->next;
		LAST->next = nodeBaru;
		return;
	}
	//Add di tengah
	Node* atmojo, * yusvan;
	yusvan = LAST->next;
	atmojo = NULL;
	while ((yusvan <= nodeBaru) || (atmojo != LAST))
	{
		atmojo = yusvan;
		yusvan = yusvan->next;
	}
	//Add diakhir
	nodeBaru->next = LAST->next;
	LAST->next = nodeBaru;
	LAST = nodeBaru;
};
bool CircularLinkedList::search(int rollno, Node** previous, Node** current)
{
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

bool CircularLinkedList::listEmpty() { 
	return LAST == NULL;
}

bool CircularLinkedList::delNode(int rollno) { //write your answer here
	Node* yusvan, * atmojo;
	if (search(rollno, &atmojo, &yusvan) == false)
		return false;
	//Menghapus jika hanya ada satu data
	if (LAST->next == LAST) {
		delete LAST;
		LAST = NULL;
		return LAST;
	}
	//Menghapus diawal
	else {
		yusvan = LAST->next;
		LAST->next = yusvan->next;
	}
	//Menghapus ditengah
	yusvan = LAST;
	atmojo = LAST->next;
	while (atmojo->next != LAST)
	{
		atmojo = atmojo->next;
	}
	atmojo->next = LAST->next;
	atmojo = LAST;

	//Menghapus diakhir
	atmojo = LAST;
	yusvan = LAST->next;
	while ((yusvan != LAST) || (atmojo != LAST))
	{
		atmojo = yusvan;
		yusvan = yusvan->next;
	}
		delete yusvan;
		return true;
}

void CircularLinkedList::traverse() {
	if (listEmpty()) {
		cout << "\nList is empty\n";
	}
	else {
		cout << "\nRecords in the list are:\n"; 
		Node* currentNode = LAST->next;
		while (currentNode != LAST) {
			cout << currentNode->rollNumber << " " << currentNode->name << endl;
			currentNode = currentNode->next;
		}
		cout << LAST->rollNumber << " " << LAST->name << endl;
	}
}

int main() {
	CircularLinkedList obj; 
	int rollno;
	char ch;
	while (true)
	{
		try {
			cout << "\nMenu" << endl; 
			cout << "1. Add a record to the list" << endl; 
			cout << "2. Delete a record from the list" << endl; 
			cout << "3. View all the records in the list" << endl; 
			cout << "4. Exit" << endl; 
			cout << "\nEnter your choice (1-4): ";
			char ch; 
			cin >> ch; 
			switch (ch) {
			case '1': {
				obj.addNode();
			}
			break;
			case '2': { 
				if (obj.listEmpty()) {
					cout << endl << "List Kosong" << endl;
					break;
				}
				cout << endl << "\nMasukkan nomro yang dihapus: ";
				cin >> rollno;

				if (obj.delNode(rollno) == false) 
					cout << endl << "Data tidak ditemukan" << endl;
				else
					cout << endl << "Data nomor" << rollno << "Berhasil dihapus" << endl;
			} 
			break;
			case '3': { 
				obj.traverse(); 
				break; 
			}
			case '4': { 
				return 0; 
			}
			default: { 
				cout << "Invalid option" << endl; 
				break; 
			}
		}
	}
		catch (exception& e) {
			cout << e.what() << endl;
		}
	}
	return 0;
}