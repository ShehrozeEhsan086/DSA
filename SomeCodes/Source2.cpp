#include <iostream>
#include <string.h>
using namespace std;

struct Student {
	char studentName[20];
	char bookName[20];
	int regNumber;
	int bookType;
	int numberOfBooks;
	Student* next;
	Student* prev;
}*head, *tail, *t;

struct Book {
	char bookTitle[20];
	int bookPrice;
	int totalBooks;
	Book* next;
}*head1, *tail1, *t1;

class LibraryManagment {
public:
	void addStudent(char studentName[20], char bookName[20], int regNumber, int bookType, int numberOfBooks) {
		Student* temp = new Student;
		strcpy_s(temp->studentName, studentName);
		strcpy_s(temp->bookName, bookName);
		temp->regNumber = regNumber;
		temp->bookType = bookType;
		temp->numberOfBooks = numberOfBooks;
		temp->next = NULL;
		if (head == NULL) {
			temp->prev = NULL;
			head = temp;
			tail = temp;
			temp = NULL;
		}
		else {
			tail->next = temp;
			tail = temp;
		}
	}
	
	void displayStudent() {
		t = head;
		if (head == NULL) {
			cout << "List is empty." << endl;
			return;
		}
		while (t != NULL) {
			cout << endl;
			cout << "Student Name: " << t->studentName << endl;
			cout << "Book Name: " << t->bookName << endl;
			cout << "Reg Number: " << t->regNumber << endl;
			cout << "Book Type: " << t->bookType << endl;
			cout << "Number Of Books: " << t->numberOfBooks << endl;
			cout << endl;
			t = t->next;
		}
		cout << "END OF LIST"<<endl;
	}

	void addBook(char bookTitle[20], int bookPrice, int totalNumOfBooks) {
		Book* temp1 = new Book;
		strcpy_s(temp1->bookTitle, bookTitle);
		temp1->bookPrice = bookPrice;
		temp1->totalBooks = totalNumOfBooks;
		if (head1 == NULL) {
			head1 = temp1;
			tail1 = temp1;
			temp1 = NULL;
		}
		else {
			tail1->next = temp1;
			tail1 = temp1;
			tail1->next = NULL;
		}
	}

	void displayBook() {
		t1 = head1;
		if (head1 == NULL) {
			cout << "No Book record."<<endl;
			return;
		}
		while (t1 != NULL) {
			cout << endl;
			cout << "Book Title: " << t1->bookTitle << endl;
			cout << "Book Price: " << t1->bookPrice << endl;
			cout << "Number of Books: " << t1->totalBooks << endl;
			cout << endl;
			t1 = t1->next;
		}
		cout << "END OF DATA" << endl;
	}
};

int main() {
	int choice;
	
	//Student Details
	char studentName[20], bookName[20];
	int regNumber;
	int bookType;
	int numOfBooks;
	
	//Book Details
	char bookTitle[20];
	int bookPrice;
	int totalNumberOfBooks;

	LibraryManagment L1;

	while (1) {
		cout << "----------------------------------------" << endl;
		cout << "1. Register New Student ";
		cout << "2. Display Registered Students ";
		cout << "3. Add New Book ";
		cout << "4. Display Detail of Books ";
		cout << "5. EXIT " << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Enter Student Name: " ;
			cin >> studentName;
			cout << "Enter Book Name: ";
			cin >> bookName;
			cout << "Enter Reg Number: ";
			cin >> regNumber;
			cout << "Enter Book Type: ";
			cin >> bookType;
			cout << "Enter Number of Books: ";
			cin >> numOfBooks;
			L1.addStudent(studentName, bookName, regNumber, bookType, numOfBooks);
			break;
		case 2:
			L1.displayStudent();
			break;
		case 3:
			cout << "Enter Book Title: ";
			cin >> bookTitle;
			cout << "Enter Book Price: ";
			cin >> bookPrice;
			cout << "Enter Number of Books: ";
			cin >> totalNumberOfBooks;
			L1.addBook(bookTitle, bookPrice, totalNumberOfBooks);
			break;
		case 4:
			L1.displayBook();
			break;
		case 5:
			exit(1);
			break;
		default:
			cout << "Wrong choice.";
		}
	}
}