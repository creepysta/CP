#include<iostream>
#include<fstream>
#include<map>
#include<iterator>
#include<cmath>

using namespace std;

class Individuals {
	double /*rate, price_per_item,*/ total_expenditure;
	// string item_name, description, item_type;
	map <string, double> item_prices;
	map <string, string> details;
	map <string, double>::iterator mi;
	map <string, string>::iterator di;
public:
	Individuals( double te=0) : total_expenditure(te) {};

	void item_details() {
		int ch;
		// cout << "Kindly Enter the details first.\n";
		while(ch) {
			cout << "Enter 0 to stop entering items.\nEnter your choice: ";
			cin >> ch;
			if(!ch)
				return;
			getchar();
			string name;
			cout << "Enter the name of the item: ";
			cin >> name;
			getchar();
			cout << "Enter the prices of the item: ";
			double price;
			cin >> price;
			getchar();
			item_prices.insert(pair <string, double> (name, price));
			string type, i_details;
			cout << "Enter type of item: ";
			getline(cin, type);
			getchar();
			cout<<"Enter description of item: ";
			getline(cin, i_details);
			getchar();
			details.insert(pair <string, string> (type, i_details));
		}
		getchar();
	}

	void total_expenditure_over_a_period() {
		int period;
		// ofstream periodically;
		// periodically.open("Total_Expenditure_Over_a_period.txt",ios::app);
		cout << "Enter the desired period in months: ";
		getchar();
		cin >> period;
		getchar();
		for(int i=0;i<period;i++) {
			for(auto i : item_prices) {
				total_expenditure += i.second;
				
				// periodically << "Month: " << i << "\t" << total_expenditure << endl;
			}
		}
		cout << "Total Expenditure considering near about equal number of items brought every month: " << total_expenditure << endl;
	}

	void expenditure_per_item() {
		double total = 0;
		int period;
		string iname;
		cout << "Enter the period in months: ";
		cin >> period;
		cout << "Enter the particular Item name: ";
		cin >> iname;
		mi = item_prices.find(iname);
		if(mi != item_prices.end()) {
			for(int i=1;i<period;i++) {
				int n;
				cout << "Number of times the item was bought in the " << i << " month: ";
				cin >> n;
				total = total + item_prices.find(iname)->second * n;
			}
		} else {
			cout << "Wrong item name.";
			exit;
		}
		cout << "The total expenditure in item " << item_prices.find(iname)->first << " is " << total << endl;
	}

	void details_all_items () {
		auto j = details.begin();
		for(auto i = item_prices.begin(); i != item_prices.end(); i++, j++) {
			cout << "Item Name: " << i->first << " \nPrice: " << i->second << " \nType: " << j->first << " \nProduct details: " << j->second << endl;
		}
	}

	void details_one_item () {
		string name;
		cout << "Enter the name of the item you want to know the details of: ";
		cin >> name;
		auto j = details.begin();
		for(auto i = item_prices.begin(); i != item_prices.end(); i++, j++) {
			if(item_prices.find(name)->first == name) {
				cout << "Name: " << i->first << "\nPrice: " << i->second << "\nType: " << j->first << "\nDetails: " << j->second << endl;
				return;
			}
		}
		cout << "Invalid Item name.\n" << name << " not found in the list of products.";
	}
};

int main()
{
	int ch;
	Individuals spoiled_brat(0);
	spoiled_brat.item_details();
	cout<<"1.Total Expenditure\t2.Expenditure for a particular item\t3.Details of Items purchased\t4.Details of a particular Item\nEnter your Choice: " << endl;
	cin>>ch;
	 switch (ch) {
	 	case 1:
			spoiled_brat.total_expenditure_over_a_period();
	 		break;
	 	case 2:
			spoiled_brat.expenditure_per_item();
	 		break;
	 	case 3:
			spoiled_brat.details_all_items();
	 		break;
	 	case 4:
			spoiled_brat.details_one_item();
	 		break;
	 	default:
	 		cout << "Please enter a correct option: ";
	 }

	// int ch;
	// Individuals spoiled_brat(0);
	// spoiled_brat.item_details();
	// /*
	// write the switch case on your risk, i couldn't make it work along with the whole program
	// r if you think that they wont check the copy that minutely then write it and let me know if you do.
	// sorry for being so late.
	// */
	// // cout<<"1.Total Expenditure\t2.Expenditure for a particular item\t3.Details of Items purchased\t4.Details of a particular Item\nEnter your Choice: ";
	// // cin >> ch;
	// // getchar();
	// // switch (ch) {
	// // 	case 1:
	// 		spoiled_brat.total_expenditure_over_a_period();
	// // 		break;
	// // 	case 2:
	// 		spoiled_brat.expenditure_per_item();
	// // 		break;
	// // 	case 3:
	// 		spoiled_brat.details_all_items();
	// // 		break;
	// // 	case 4:
	// 		spoiled_brat.details_one_item();
	// // 		break;
	// // 	default:
	// // 		cout << "Please enter a correct option: ";
	// // }

	return 0;
}