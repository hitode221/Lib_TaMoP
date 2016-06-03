#include <iostream>
#include <string>
#include "Windows.h"
using namespace std;

int main() {
	string c;
	cout << "Queue - 'qlib', Priority queue - 'qwplib', else any key: ";
	cin >> c;
	while (c == "qlib" || c == "qwplib") {
		HINSTANCE h;
		if (c == "qlib") h = LoadLibrary(L"qlib");
		if (c == "qwplib") h  = LoadLibrary(L"qwplib");
		if (h) {
			int n;
			cin >> n;
			for (int i = 0; i < n; i++) {
				string b;
				int c;
				cin >> b;

				if (b == "add") {
					cin >> c;
					typedef void s(int b);
					FARPROC add = (FARPROC)GetProcAddress((HMODULE)h, "add");
					((s*)add)(c);
				}

				if (b == "del") {
					FARPROC del = (FARPROC)GetProcAddress((HMODULE)h, "del");
					try {
						del();
					}
					catch (const char* msg) {
						cout << msg;
					}
				}

				if (b == "get") {
					FARPROC get = (FARPROC)GetProcAddress((HMODULE)h, "get");
					try {
						cout << get() << endl;
					}
					catch (const char* msg) {
						cout << msg;
					}
				}
			}
			FreeLibrary(h);
		}
		else cout << "Can't load library!\n";
		cout << "If you want to continue the work, reselect queue type, else any key: ";
		cin >> c;
	}
	system("pause");
	return 0;
}
