#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>

using namespace std;

void menu(int& k) {
	system("cls"); //clear console

	char ch[5] = { 0 };

	while (k < 0) {
		k += 5;
	}
	k = k % 5;

	ch[k] = '*';


	cout << ch[0] << "add" << endl;
	cout << ch[1] << "change" << endl;
	cout << ch[2] << "delete" << endl;
	cout << ch[3] << "output" << endl;
	cout << ch[4] << "exit" << endl << endl;
}
void menu2(int k, int& d) {
	system("cls"); //clear console

	string word;
	if (k == 2) word = "change";
	if (k == 3) word = "delete";

	char ch[6] = { 0 };

	while (d < 0) {
		d += 6;
	}
	d = d % 6;

	ch[d] = '*';

	cout << "u want " << word << " date shop" << endl;
	cout << ch[0] << "by number" << endl;
	cout << ch[1] << "by name" << endl;
	cout << ch[2] << "by addres" << endl;
	cout << ch[3] << "by telephone" << endl;
	cout << ch[4] << "by time to work" << endl;
	cout << ch[5] << "exit" << endl;
}
void menu3(int& k) {
	system("cls"); //clear console

	char ch[4] = { 0 };

	while (k < 0) {
		k += 4;
	}
	k = k % 4;

	ch[k] = '*';

	cout << "output: " << endl;
	cout << ch[0] << "every" << endl;
	cout << ch[1] << "only one" << endl;
	cout << ch[2] << "in a certain interval" << endl;
	cout << ch[3] << "exit" << endl;
}
void slash(int& left, int& right) {
	int buff;

	buff = left;
	left = right;
	right = buff;
}
void slash(string& left, string& right) {
	string buff;

	buff = left;
	left = right;
	right = buff;
}
void print(string* name, string* addr, string* tele, string* time, int st, int kc) {
	for (int i = st; i < kc; i++) {
		cout << "name: " << name[i] << endl;
		cout << "addres: " << addr[i] << endl;
		cout << "telepgone: " << tele[i] << endl;
		cout << "time to work: " << time[i] << endl << endl;
	}

	int g = _getch();
}
void search_magaz(string* name, string* search, int n, int& vivod, int& d) {
	string namesearch;
	bool d1 = 1;
	while (d1 != 0) {
		cout << "enter what you count" << endl;
		getline(cin, namesearch);

		int k = 0;
		for (int i = 0; i < n; i++) {
			if (search[i] == namesearch) {
				k++;
			}
		}

		if (k == 1) {
			for (int i = 0; i < n; i++) {
				if (search[i] == namesearch) {
					vivod = i;
				}
			}
			cout << "we have found only one suitable option for you, this is a store: " << name[vivod] << endl;
		}

		if (k > 1) {
			cout << "we have found for you " << k << " options" << endl;
			int schet = 0;
			int* schet1 = new int[k];
			for (int i = 0; i < n; i++) {
				if (search[i] == namesearch) {
					cout << schet + 1 << ") " << name[i] << endl;
					schet1[schet] = i;
					schet++;
				}
			}
			cout << "choose" << endl;
			cin >> schet;
			vivod = schet1[schet];
			d1 = 0;
		}

		if (k == 0) {
			cout << "we didn't find anything on your request" << endl;
			cout << "try again?" << endl;
			cout << " 0 - nope, 1 - yes" << endl;
			cin >> d1;
			if (d1 == 0) {
				d = 0;
			}
		}
	}
}
void search_magaz(string* name, int n, int& vivod, int& d) {
	string namemagaz;
	int k = 0;
	cout << "enter the name of the store" << endl;
	cin >> namemagaz;

	for (int i = 0; i < n; i++) {
		if (namemagaz == name[i]) {
			k++;
		}
	}
	if (k == 0) {
		cout << "there is not a single suitable option" << endl;
		d = 0;

	}
	else {
		if (k > 1) {
			int schet = 0;
			int* schet1 = new int[k];
			cout << "we have found for you " << k << " options" << endl;
			for (int i = 0; i < n; i++) {
				cout << schet + 1 << ")" << name[i] << endl;
				schet1[schet] = i;
				schet++;
			}
			cout << "choose one, please" << endl;
			cin >> schet;

			vivod = schet1[schet - 1];
		}
		if (k == 1) {
			cout << "we found only one match: " << endl;

			for (int i = 0; i < n; i++) {
				if (namemagaz == name[i]) {
					cout << name[i] << endl;
					vivod = i;
				}

			}
		}
	}

}
void slash(string*& name, string*& addr, string*& tele, string*& time, int n, int perv, int vtor) {
	slash(name[perv], name[vtor]);
	slash(addr[perv], addr[vtor]);
	slash(tele[perv], tele[vtor]);
	slash(time[perv], time[vtor]);
}
void udal(string*& name, string*& addr, string*& tele, string*& time, int& n, int vibor) {
	//create buff
	string* name1 = new string[n - 1];
	string* addr1 = new string[n - 1];
	string* tele1 = new string[n - 1];
	string* time1 = new string[n - 1];

	int schet = 0; //second timer
	//pull buff
	for (int i = 0; i < n; i++) {
		if (vibor != i) {
			name1[schet] = name[i];
			addr1[schet] = addr[i];
			tele1[schet] = tele[i];
			time1[schet] = time[i];
			schet++;
		}
	}

	//clear arr
	delete[] name;
	delete[] addr;
	delete[] tele;
	delete[] time;

	//smalling arr
	n--;

	//take date to buff
	name = name1;
	addr = addr1;
	tele = tele1;
	time = time1;
}
void edit(string*& name, string*& addr, string*& tele, string*& time, int n, int vibor) {
	getline(cin, name[vibor]); //go to next line
	cout << "enter the name of the store: ";
	getline(cin, name[vibor]);//rewrite empty line
	cout << endl;
	cout << "enter the store's address: ";
	getline(cin, addr[vibor]);
	cout << endl;
	cout << "enter the store's phone number: ";
	getline(cin, tele[vibor]);
	cout << endl;
	cout << "enter the store's opening hours: ";
	getline(cin, time[vibor]);
	cout << endl;
}
void append(string*& name, string*& addr, string*& tele, string*& time, int& n) {
	//create buff
	string* name1 = new string[n + 1];
	string* addr1 = new string[n + 1];
	string* tele1 = new string[n + 1];
	string* time1 = new string[n + 1];

	//pull buff
	for (int i = 0; i < n; i++) {
		name1[i] = name[i];
		addr1[i] = addr[i];
		tele1[i] = tele[i];
		time1[i] = time[i];
	}

	//date
	getline(cin, name1[n]); //go to next line
	cout << "enter a name " << endl;
	getline(cin, name1[n]); //rewrite name
	cout << "enter the address " << endl;
	getline(cin, addr1[n]);
	cout << "enter your phone number " << endl;
	getline(cin, tele1[n]);
	cout << "enter the opening time (example: 10:00-22:00) " << endl;
	getline(cin, time1[n]);

	//delete arr
	delete[] name;
	delete[] addr;
	delete[] tele;
	delete[] time;

	//++ array
	n++;

	//takin date from buff
	name = name1;
	addr = addr1;
	tele = tele1;
	time = time1;
}

int main() {
	setlocale(LC_ALL, "rus");		//rus alf

	ifstream f1;		//work with files
	int n;		//current 

	f1.open("bd.txt");		//open file

	if (!f1.is_open()) {
		cout << "bd not founded" << endl;
	}
	else {
		bool work = 1; //workin programm
		int k = 0; //menu
		string add; //add
		int st;
		int kc;
		int vivod;
		int d1 = 1;

		//update date
		f1 >> n; //current
		string* name = new string[n]; //name
		string* addr = new string[n]; //addr
		string* tele = new string[n]; //tel
		string* time = new string[n]; //time to work

		//считывание строк
		for (int i = 0; i < n; i++) {
			if (i == 0) {
				getline(f1, name[i]); //go to next line (name[i] nothin, rewrited)
			}
			getline(f1, name[i]); //take name
			getline(f1, addr[i]); //take addr
			getline(f1, tele[i]); //take tele
			getline(f1, time[i]); //take time to work
		}

		int g, g1;
		int d = 0;

		while (work) {
			menu(k);

			int g, g1;
			int d = 0;

			bool work1 = 1;
			g = _getch();

			switch (g) {
			case(72):
				k--;
				break;
			case(75):
				k--;
				break;
			case(80):
				k++;
				break;
			case(77):
				k++;
				break;
			case(13): //if push enter
				k = k % 5;

				switch (k)
				{
				case(0):
					append(name, addr, tele, time, n);
					break;
				case(1):
					//change
					while (work1) {
						menu2(k, d);
						g1 = _getch();
						switch (g1) {
						case(72):
							d--;
							break;
						case(75):
							d--;
							break;
						case(80):
							d++;
							break;
						case(77):
							d++;
							break;
						case(13): //if push enter
							d = d % 6;
							switch (d)
							{
							case(0):
								cout << "enter the store number" << endl;
								cin >> vivod;
								vivod--;  //go to next index (first element = 0)
								if ((vivod > 0) && (vivod < n)) {
									edit(name, addr, tele, time, n, vivod);
								}
								break;
							case(1):
								search_magaz(name, n, vivod, d1);
								if ((vivod > 0) && (vivod < n) && (d != 0)) {
									edit(name, addr, tele, time, n, vivod);
								}
								break;
							case(2):
								search_magaz(name, addr, n, vivod, d1);
								if (((vivod > 0) && (vivod < n)) || (d != 0)) {
									edit(name, addr, tele, time, n, vivod);
								}
								break;
							case(3):
								search_magaz(name, tele, n, vivod, d1);
								if (((vivod > 0) && (vivod < n)) || (d != 0)) {
									edit(name, addr, tele, time, n, vivod);
								}
								break;
							case(4):
								search_magaz(name, time, n, vivod, d1);
								if (((vivod > 0) && (vivod < n)) || (d != 0)) {
									edit(name, addr, tele, time, n, vivod);
								}
								break;
							case(5):
								work1 = 0;
								break;
							default:
								cout << "error" << endl;
								break;
							}
							break;
						}
					}
					break;
				case(2):
					//delete
					while (work1) {
						menu2(k, d);
						g1 = _getch();
						switch (g1) {
						case(72):
							d--;
							break;
						case(75):
							d--;
							break;
						case(80):
							d++;
							break;
						case(77):
							d++;
							break;
						case(13): //if push to enter
							d = d % 6;
							//what he choise
							switch (d)
							{
							case(5):
								work1 = 0;
								break;
							case(0):
								cout << "enter the store number" << endl;
								cin >> vivod;
								vivod--;  //go to index(first element = 0)
								if ((vivod > 0) && (vivod < n)) {
									udal(name, addr, tele, time, n, vivod);
								}
								break;
							case(1):
								search_magaz(name, n, vivod, d);
								if (((vivod > 0) && (vivod < n)) || (d != 0)) {
									udal(name, addr, tele, time, n, vivod);
								}
								break;
							case(2):
								search_magaz(name, addr, n, vivod, d);
								if (((vivod > 0) && (vivod < n)) || (d != 0)) {
									udal(name, addr, tele, time, n, vivod);
								}
								break;
							case(3):
								search_magaz(name, tele, n, vivod, d);
								if (((vivod > 0) && (vivod < n)) || (d != 0)) {
									udal(name, addr, tele, time, n, vivod);
								}
								break;
							case(4):
								search_magaz(name, time, n, vivod, d);
								if (((vivod > 0) && (vivod < n)) || (d != 0)) {
									udal(name, addr, tele, time, n, vivod);
								}
								break;
							default:
								cout << "error" << endl;
								break;
							}
							break;
						}
					}
					break;
				case(3):
					//cout
					while (work1) {
						menu3(d);
						g1 = _getch();
						switch (g1) {
						case(72):
							d--;
							break;
						case(75):
							d--;
							break;
						case(80):
							d++;
							break;
						case(77):
							d++;
							break;
						case(13): //if push to enter
							d = d % 4;
							//what he choise
							switch (d)
							{
							case(3):
								work1 = 0;
								break;
							case(0):
								print(name, addr, tele, time, 0, n);
								break;
							case(1):
								cout << "enter which store you want to withdraw" << endl;
								cout << "всего " << n << " магазинов" << endl;
								cin >> st;
								print(name, addr, tele, time, st - 1, st);
								break;
							case(2):
								cout << "there are " << n << " stores in total" << endl;
								cout << "enter the first number" << endl;
								cin >> st;
								cout << "enter the second number" << endl;
								cin >> kc;

								//the smaller number was the first
								if (st > kc) {
									slash(st, kc);
								}
								//checking whether they are equal
								if (st == kc) {
									cout << "you have entered two identical numbers" << endl;
									cout << "output number: " << endl;
								}
								else {
									cout << "output from " << st << " to " << kc << ":" << endl;
								}
								print(name, addr, tele, time, st - 1, kc);
								break;
							default:
								cout << "error" << endl;
								break;
							}

						}
					}
					break;
				case(4):
					//end
					work = 0;
					break;
				default:
					cout << "error";
					break;
				}
				break;
			}
		}

		//save to file bd.txt
		ofstream f2;
		f2.open("bd.txt");
		f2 << n << endl;
		for (int i = 0; i < n; i++) {
			f2 << name[i] << endl;
			f2 << addr[i] << endl;
			f2 << tele[i] << endl;
			f2 << time[i] << endl;
		}
		f2.close();
	}

	f1.close();
}