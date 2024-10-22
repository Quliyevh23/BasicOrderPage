#include <iostream>
#include <string>
#include "Product.h"
#include <vector>
using namespace std;

int main() {
	int process,cartProcess,check;
	short int promoBlock = 0;
	double balance = 9000;
	double resultValue = 0;
	int close = 0;
	string promoCodeUser;
	string promoCodeData = "Quliyev20";  // for discount :D


	// Products in region
	#pragma region Products

	Product product1;
	product1.Name = "Iphone 11";
	product1.Price = 1199.99;
	product1.id = 1;

	Product product2;
	product2.Name = "Apple AirPods Pro 2";
	product2.Price = 799.99;
	product2.id = 2;

	Product product3;
	product3.Name = "Iphone 13";
	product3.Price = 1399.99;
	product3.id = 3;


	Product product4;
	product4.Name = "Ipad pro";
	product4.Price = 2999.99;
	product4.id = 4;

#pragma endregion 


	vector<Product> Products = { product1, product2, product3, product4 }; // Product arr ( database )
	vector<Product> SelectedProducts; // Selected products will added here

	cout << "Welcome to Quliyev shop \n";
	

	while (close == 0) {
		cout << "\n";
		cout << "0. Exit \n";
		cout << "1. Buy products\n";
		cout << "2. Show cart\n\n";

		cout << "Emeliyyat daxil edin: ";
		cin >> process;
		
		switch (process) {

		case 0: // Exiting
			cout << "Exiting...";
			close++;
			break;

		case 1: // Purchasing products
			do {
				cout << "Products: \n\n";

				for (Product obj : Products)
				{
					cout << obj.id << ". " << obj.Name << " : " << obj.Price << " Azn" << endl;
				}
				cout << "\n";
				cout << "Almaq istediyiniz mehsulun id - ni daxil edin (cixmaq ucun '0' daxil edin): ";
				cin >> check;

				for (Product obj : Products) {
					if (check == obj.id) {
						SelectedProducts.push_back(obj);
						resultValue += obj.Price;
					}
					
				}
			} while (check != 0);
			break;

		case 2: // Shopping cart
			
			cout << "\n";
			cout << "Mehsullar: \n";
			for (Product obj : SelectedProducts) {
				cout << "Id: " << obj.id << " " << "Name: " << obj.Name << " Price: " << obj.Price << endl; // Products in cart
			}
			cout << "\n";
			cout << "Yekun qiymet: " << resultValue <<"\n"; // Final value
			cout << "Balansiniz: " << balance << endl;



			cout << " \n";						 
			cout << "1. Promo kod isletmek \n";	
			cout << "2. Sebeti tesdiqle ve ode.\n";
			cout << "\n";								// operations in cart
			cout << "Emeliyyat sechin: ";
			cin >> cartProcess;


			switch (cartProcess)
			{

			case 1:
				cout << "\n";
				cout << "Promo kodu daxil edin: ";
				cin >> promoCodeUser;
				if (promoBlock == 0) {
					if (promoCodeUser == promoCodeData) {
						promoBlock++;
						resultValue *= 0.8;
						cout << "\n";
						cout << "20% endirim tetbiq olundu.\n";
					}
					else
						cout << "Bele kod yoxdur!\n";
				}
				else
					cout << "Bu kodu artiq isletmisiniz.";
				
				break;


			case 2:

				if (balance >= resultValue) {
					cout << "Odenildi.\n";
					balance -= resultValue;
					cout << "Qalan balans: ";
					cout << balance;
					cout << "\n";
					close++;
				}
				else
					cout << "Balansinizda kifayet qeder pul yoxdur!";
				
				break;

			default:
				cout << "Duzgun daxil edin!";
				break;
			}

			break;

		default:
			cout << "Duzgun daxil edin!";
			break;
		}
		
	}
}