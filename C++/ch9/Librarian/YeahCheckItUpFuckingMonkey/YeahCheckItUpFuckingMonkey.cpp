// YeahCheckItUpFuckingMonkey.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

//Class & Struct
enum class Genre {
	fiction, nonfiction, periodical, biography, children
};
class Book {
public :
	Book(string input_isbn, string input_title, string input_author, Genre input_genre, string input_copyRight)
		: isbn{ input_isbn }, title{input_title}, author{input_author}, genre{input_genre}, copyRight{input_copyRight}, is_loan{false}
	{
		// 유효성 테스트
		;
	}

	string ISBN() const { return isbn; }
	string Title() const { return title; }
	string Author() const { return author; }
	string CopyRight() const { return copyRight; }
	bool Is_loan() const { return is_loan; }
	void	TurnIn() { is_loan = true; }
	void Loan() { is_loan = false; }

private:
	string isbn;
	string title;
	string author;
	string copyRight;
	bool is_loan;
	Genre genre;
};
class Patron {
public:
	Patron(string input_name, int input_code)
		: name{ input_name }, code{ input_code }, fee{0}
	{
		// 필요하다면 유효성 검사
	}

	string Name() const { return name; }
	int Code() const { return code; }
	int Fee() const { return fee; }
	void Change_Fee(int input_changeFee);
	bool Have_fee();

private:
	string name;
	int code;
	int fee;

};
struct Transaction
{
	Book& book;
	Patron& patron;

	Transaction(Book input_book, Patron input_Patron)
		: book{ input_book }, patron{ input_Patron }
	{
		;
	}
};

class Library {
public :
	//fuction
	void Add_book(Book& intput_book);
	void Add_patron(Patron& input_patron);
	void Loan_book(string input_isbn, int input_code);

	//helper
	bool Is_BookInLibrary(string input_isbn);
	bool Is_PatronInLibary(int input_code);
	
	Patron Get_patronByCode(int input_code);
	Book Get_bookByIsbn(string input_isbn);

	vector<Book> Books() { return books; }
	vector<Patron> Patrons() { return patrons; }

private :
	vector<Book> books;
	vector<Patron> patrons;
	vector<Transaction> transctions;

};

//Error Class
class Invald_Book {
};

//Operator
bool operator== (const Book& b1,const Book& b2)
{
	if (b1.ISBN() == b2.ISBN()) return true;

	return false;
}
bool operator!= (const Book& b1,const Book& b2)
{
	if (b1.ISBN() != b2.ISBN()) return true;

	return false;
}
ostream& operator<< (ostream& os,const Book& b1)
{
	os << b1.Title() << " | " << b1.Author() << " | " << b1.ISBN() << endl;

	return os;
}
ostream& operator<< (ostream& os, const Patron& p1)
{
	os << p1.Name() << " | " << p1.Code() << endl;

	return os;
}

//Function
void Patron::Change_Fee(int input_changeFee)
{
	fee = input_changeFee;
}
void Library::Add_book(Book& input_book)
{
	if (!Is_BookInLibrary(input_book.ISBN()))
		books.push_back(input_book);
}
void Library::Add_patron(Patron& input_patron)
{
	if (!Is_PatronInLibary(input_patron.Code()))
		patrons.push_back(input_patron);
}
void Library::Loan_book(string input_isbn, int input_code)
{
	//Check Exist
	Book b = Get_bookByIsbn(input_isbn);
	Patron p = Get_patronByCode(input_code);

	//check Fee
	if (p.Have_fee())
	{
		//오류보고
	}

	Transaction transaction(b, p);
}

//Helper Function
bool Patron::Have_fee()
{
	if (fee > 0) return true;
	else return false;
}

bool Library::Is_BookInLibrary(string input_isbn)
{
	for (Book& b : books)
		if (b.ISBN() == input_isbn) return true;

	return false;
}
Book Library::Get_bookByIsbn(string input_isbn) 
{
	for (Book& b : books)
		if (b.ISBN() == input_isbn) return b;

	//error
}

bool Library::Is_PatronInLibary(int input_code)
{
	for (Patron& p : patrons)
		if (p.Code() == input_code) return true;
	return false;
}
Patron Library::Get_patronByCode(int input_code)
{
	for (Patron& p : patrons)
		if (p.Code() == input_code) return p;

	//error
}


//Main
int main()
{
	Library libarary;

	//Literal Test
	Book b1{ "aaa-bbb-cc-1123", "Title", "author", Genre::fiction, "CopyFree" };
	libarary.Add_book(b1);
	

	Patron p1{ "Hee", 1324 };
	libarary.Add_patron(p1);



	while (cin)
	{
		char ch;
		cout << "Enter Number | 1.Loan | 2.Add Book | 3.Add Patron | 4.Show Books | 5.Show Patrons" << endl;

		cin >> ch;

		switch (ch)
		{
		case '1':
		{
			cout << "Input Book ISBN n-n-n-x (n is num, x is num and char" << endl;
			
			string inputString;
			cin >> inputString;
			
			vector<int> hyponPos;
			for (int i = 0; i < inputString.length(); i++)
			{
				if (inputString[i] == '-') hyponPos.push_back(i);
				if (hyponPos.size() > 3)
				{
					cout << "input just 3 ㅠㅠ" << endl;
				}
			}

			cout << inputString << endl;

			cout << "input Your ID" << endl;
			break;
		}
		case '2':
		{
			cout << "input ISBN" << endl;
	
			cout << "Input ";
			break;
		}
	
		case '3':
		{
			cout << "input CODE" << endl;
			
			cout << "input Name" << endl;
			break;
		}
		case '4':
			cout << "Book List" << endl;
			for (Book& b : libarary.Books())
				cout << b;
			break;

		case '5':
			cout << "Patron List" << endl;
			for (Patron& p : libarary.Patrons())
				cout << p;
			break;

		default:
			cout << "Fuck you in put correct number Fuckyou Fuck you" << endl;
			cin.clear();
			break;
		}


	}

	return 0;
}