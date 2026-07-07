#include <fstream>
#include <iostream>
using namespace std;

struct expense {
    int date;
    int month;
    int year;
    string cat;
    float amount;
    string desc;
};
  
void save(expense e[], int n)
{
    ofstream fout("SpendSense.txt");
    for (int i = 0; i < n; i++) {
        fout << e[i].date << " " << e[i].month << " " << e[i].year << " " << e[i].cat << " " << e[i].amount << " " << e[i].desc << '\n';
    }
    fout.close();
}

void load(expense e[], int &n)
{
    ifstream fin("SpendSense.txt");
    n = 0;
    while (fin >> e[n].date >> e[n].month >> e[n].year >> e[n].cat >> e[n].amount) {
        getline(fin >> ws, e[n].desc);
        n++;
    }
    fin.close();
}

void category(expense e[],int &n) {
    cout << "Category Section :-\n";
    cout << "1.Food\n";
    cout << "2.Transport\n";
    cout << "3.Entertainment\n";
    cout << "4.Education\n";
    cout << "5.Shopping\n";
    cout << "6.Medical\n";
    cout << "7.Others\n";
    cout << "Enter The Category From The List Available :- \n";
    int choice;
    cin >> choice;
    switch(choice) {
        case 1:
        e[n].cat="Food";
        break;
        case 2:
        e[n].cat="Transport";
        break;
        case 3:
        e[n].cat="Entertainment";
        break;
        case 4:
        e[n].cat="Education";
        break;
        case 5:
        e[n].cat="Shopping";
        break;
        case 6:
        e[n].cat="Medical";
        break;
        case 7:
        e[n].cat="Others";
        break;
        default:
        cout << "Invalid Choice!!";
    }
}

void add(expense e[],int &n) {
    if (n == 100) {
        cout << "Database Full!!\n";
        return;
    }
    cout << "Fill In The Details Of Expense :-\n";
    cout << "Enter Data (DD MM YYYY) :-  ";
    cin >> e[n].date >> e[n].month >> e[n].year;
    category(e[],n);
    cout << "Enter Amount :-  ";
    cin >> e[n].amount;
    cout << "Enter Description :- ";
    getline(cin >> ws, e[n].desc);
    n++;
    cout << "Expense Added Successfully!!\n";
}

void viewall(expense e[],int &n) {
    if (n == 0) {
        cout << "No Expense Found!!\n";
        return;
    }
    for(int i=0;i<n;i++) {
        cout << "\n";
        cout << "Expense " << i+1 << " :-" << endl;
        cout << "Date :- " << e[i].date << "/" << e[i].month << "/" << e[i].year << endl;
        cout << "Category :- " << e[i].cat << endl;
        cout << "Amount :- " << e[i].amount << endl;
        cout << "Description :- " << e[i].desc << endl;
        cout << "\n";
    }
    
}

void searchbydate(expense e[],int &n) {
    if (n == 0) {
        cout << "No Expense Found!!\n";
        return;
    }
    int a,b,c;
    cout << "Enter The Date (DD MM YYYY)?  ";
    cin >> a >> b >> c;
    for(int i=0;i<n;i++) {
        if (e[i].date==a && e[i].month==b && e[i].year==c) {
            cout << "\n";
            cout << "Expense " << i+1 << " :-" << endl;;
            cout << "Date :- " << e[i].date << "/" << e[i].month << "/" << e[i].year << endl;
            cout << "Category :- " << e[i].cat << endl;
            cout << "Amount :- " << e[i].amount << endl;
            cout << "Description :- " << e[i].desc << endl;
            cout << "\n";
        }
    }
}

void searchbycat(expense e[],int &n) {
    if (n == 0) {
        cout << "No Expense Found!!\n";
        return;
    }
    string x;
    cout << "Category?  ";
    cin >> x;
    for(int i=0;i<n;i++) {
        if (e[i].cat==x) {
            cout << "\n";
            cout << "Expense " << i+1 << " :-" << endl;;
            cout << "Date :- " << e[i].date << "/" << e[i].month << "/" << e[i].year << endl;
            cout << "Category :- " << e[i].cat << endl;
            cout << "Amount :- " << e[i].amount << endl;
            cout << "Description :- " << e[i].desc << endl;
            cout << "\n";
        }
    }
}

void edit(expense e[],int &n) {
    if (n == 0) {
        cout << "No Expense Found!!\n";
        return;
    }
    int a,b,c;
    int x,y,z,q;
    string p,r;
    cout << "Enter The Date (DD MM YYYY)?  ";
    cin >> a >> b >> c;
    for(int i=0;i<n;i++) {
        if (e[i].date==a && e[i].month==b && e[i].year==c) {
            cout << "\n";
            cout << "Current Expense Details :-" << endl;
            cout << "Date :- " << e[i].date << "/" << e[i].month << "/" << e[i].year << endl;
            cout << "Category :- " << e[i].cat << endl;
            cout << "Amount :- " << e[i].amount << endl;
            cout << "Description :- " << e[i].desc << endl;
            cout << "\n";
            cout << "Enter New Expense Details :-" << endl;
            cout << "Enter New Date (DD MM YYYY)?  " ;
            cin >> x >> y >> z;
            e[i].date=x; e[i].month=y; e[i].year=z;
            cout << "1.Food\n";
            cout << "2.Transport\n";
            cout << "3.Entertainment\n";
            cout << "4.Education\n";
            cout << "5.Shopping\n";
            cout << "6.Medical\n";
            cout << "7.Others\n";
            cout << "Enter New Category From The List Available :- \n"; 
            cin >> p;
            e[i].cat=p;
            cout << "Enter New Amount?  ";
            cin >> q;
            e[i].amount=q;
            cout << "Enter New Description?  ";
            cin >> r;
            e[i].desc=r;
            cout << "\n";
        }
    }
}

void highestexpense(expense e[],int &n) {
    if (n==0) {
        cout << "No Expense Found!!\n";
        return;
    }
    int x,y;
    int pos=-1;
    cout << "Enter The Month & Year (MM YYYY) To Find The Highest Expense?  ";
    cin >> x >> y;
    for (int i=0;i<n;i++) {
        if (e[i].month==x && e[i].year==y) {
            if (pos == -1 || e[i].amount > e[pos].amount) {
                pos=i;
            }
        }
    }
    if (pos==-1) {
        cout << "No Expense Found!!\n";
        return;
    }
    cout << "\n";
    cout << "Highest Expense Details:\n";
    cout << "Date :- " << e[pos].date << "/" << e[pos].month << "/" << e[pos].year << endl;
    cout << "Category :- " << e[pos].cat << endl;
    cout << "Amount :- " << e[pos].amount << endl;
    cout << "Description :- " << e[pos].desc << endl; 
    cout << "\n";
}

void expensebtwtwodates(expense e[], int &n) {
    if (n==0) {
        cout << "No Expense Found!!\n";
        return;
    }
    int count = 0;
    int x,y,z,a,b,c;
    cout << "Enter 1st Date (DD MM YYYY) :- ";
    cin >> x >> y >> z;
    cout << "Enter 2nd Date (DD MM YYYY) :- ";
    cin >> a >> b >> c;
    int start=z*10000+y*100+x;
    int end=c*10000+b*100+a;
    if (start>end) {
        swap(start, end);
    }
    for (int i=0;i<n;i++) {
        int current=e[i].year*10000+e[i].month*100+e[i].date;
        if (current>=start && current<=end) {
            if (count==0) {
                cout << "\nExpense Details Between " << x << "/" << y << "/" << z << " And " << a << "/" << b << "/" << c << "\n";
            }
            count++;
            cout << "\n";
            cout << "Date :- " << e[i].date << "/" << e[i].month << "/" << e[i].year << endl;
            cout << "Category :- " << e[i].cat << endl;
            cout << "Amount :- " << e[i].amount << endl;
            cout << "Description :- " << e[i].desc << endl;
            cout << "\n";
        }
    }
    if (count==0) {
        cout << "No Expense Found Between These Dates!!\n";
    }
}
void del(expense e[],int &n) {
    if (n == 0) {
    cout << "No Expense Found!!\n";
    return;
    }
    int a,b,c;
    cout << "\n";
    cout << "Enter The Date (DD MM YYYY)?  ";
    cin >> a >> b >> c;
    int pos=-1;
    for (int i=0;i<n;i++) {
        if (e[i].date==a && e[i].month==b && e[i].year==c) {
            pos=i;
            break;
        }
    }
    if (pos==-1) {
        cout << "No Expense Found!!\n";
        cout << "\n";
        return;
    }
    char confirm;
    cout << "Do You Want To Delete The Expense (Y/N)?   ";
    cin >> confirm;
    if (confirm!='Y' && confirm!='y') {
        cout << "Deletion Cancelled!!\n";
        return;
    }
    for (int i=pos;i<n-1;i++) {
        e[i]=e[i+1];
    }
    n--;
    cout << "Expense Deleted Successfully!!\n";
    cout << "\n";
}
    
void monthly(expense e[],int &n) {
    if (n == 0) {
    cout << "No Expense Found!!\n";
    return;
    }
    int mon,yr;
    cout << "\n";
    cout << "Enter Month & Year?  ";
    cin >> mon >> yr;
    float tot=0;
    for (int i=0;i<n;i++) {
        if (e[i].month==mon && e[i].year==yr) {
            cout << e[i].cat << "     " << e[i].amount << endl;
            tot+=e[i].amount;
        }
    }
    cout << "Total :- " << tot << endl;
    cout << "\n";
}
    
int main () {
    int n=0;
    int choice;
    expense e[100];
    load(e, n);
    cout << "Welcome To SpendSense - Personal Expense Tracker\n";
    while (true) {
        cout << "1. Add Expense\n";
        cout << "2. View All Expenses\n";
        cout << "3. Search Expense By Date\n";
        cout << "4. Search Expense By Category\n";
        cout << "5. Edit Expense\n";
        cout << "6. Highest Expense\n";
        cout << "7. Expense Between Two Dates\n";
        cout << "8. Delete Expense\n";
        cout << "9. Monthly Summary\n";
        cout << "10. Exit\n";
        cout << "Enter Your Choice?  ";
        cin >> choice;
        switch (choice) {
            case 1:
            add(e,n);
            save(e, n);
            break;
            case 2:
            viewall(e,n);
            break;
            case 3:
            searchbydate(e,n);
            break;
            case 4:
            searchbycat(e,n);
            break;
            case 5:
            edit(e,n);
            break;
            case 6:
            highestexpense(e,n);
            break;
            case 7:
            expensebtwtwodates(e,n);
            break;
            case 8:
            del(e,n);
            save(e, n);
            break;
            case 9:
            monthly(e,n);
            break;
            case 10:
            cout << "Exiting Program...";
            return 0;
            default:
            cout << "Invalid Choice!!";
        }
    }
   return 0;
}