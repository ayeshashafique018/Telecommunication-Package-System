#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>

using namespace std;




int balance = 0;

enum PackageType {
    INTERNET,
    CALL,
    SMS,
    BUNDLE
};

struct Package {
    string packageName;
    float price;
    bool isPrepaid;
    Package(string packageName, float price, bool isPrepaid) : packageName(packageName), price(price), isPrepaid(isPrepaid) {}
};

struct InternetPackage : public Package {
    int dataLimit;
    InternetPackage(string packageName, float price, bool isPrepaid, int dataLimit) :
        Package(packageName, price, isPrepaid), dataLimit(dataLimit) {}
};

struct CallPackage : public Package {
    int callLimit;
    CallPackage(string packageName, float price, bool isPrepaid, int callLimit) :
        Package(packageName, price, isPrepaid), callLimit(callLimit) {}
};

struct SMSPackage : public Package {
    int smsLimit;
    SMSPackage(string packageName, float price, bool isPrepaid, int smsLimit) :
        Package(packageName, price, isPrepaid), smsLimit(smsLimit) {}
};

struct BundlePackage : public Package {
    string internetName;
    float internetPrice;
    bool isPrepaid;
    int dataLimit;
    string callName;
    float callPrice;
    int callLimit;
    string smsName;
    float smsPrice;
    int smsLimit;
    BundlePackage(string packageName, float price, bool isPrepaid, string internetName, float internetPrice, int dataLimit, string callName, float callPrice, int callLimit, string smsName, float smsPrice, int smsLimit) :
        Package(packageName, price, isPrepaid), internetName(internetName), internetPrice(internetPrice), dataLimit(dataLimit), callName(callName), callPrice(callPrice), callLimit(callLimit), smsName(smsName), smsPrice(smsPrice), smsLimit(smsLimit) {}
};




InternetPackage prepaidInternet("Prepaid Internet", 25.0, true, 100);
InternetPackage prepaidInternet1("Prepaid Internet", 30.0, true, 50);
InternetPackage prepaidInternet2("Prepaid Internet", 20.0, true, 30);
InternetPackage prepaidInternet3("Prepaid Internet", 5.0, true, 15);
InternetPackage postpaidInternet("Postpaid Internet", 35.0, false, 100);
InternetPackage postpaidInternet1("Postpaid Internet", 35.0, false, 100);
InternetPackage postpaidInternet2("Postpaid Internet", 25.0, false, 75);
InternetPackage postpaidInternet3("Postpaid Internet", 15.0, false, 40);
CallPackage prepaidCall("Prepaid Call", 15.0, true, 200);
CallPackage prepaidCall1("Prepaid Call", 25.0, true, 200);
CallPackage prepaidCall2("Prepaid Call", 15.0, true, 100);
CallPackage prepaidCall3("Prepaid Call", 7.50, true, 80);
CallPackage postpaidCall("Postpaid Call", 20.0, false, 300);
CallPackage postpaidCall1("Postpaid Call", 25.0, false, 300);
CallPackage postpaidCall2("Postpaid Call", 18.0, false, 200);
CallPackage postpaidCall3("Postpaid Call", 12.5, false, 100);
SMSPackage prepaidSMS("Prepaid SMS", 10.0, true, 500);
SMSPackage prepaidSMS1("Prepaid SMS", 10.0, true, 500);
SMSPackage prepaidSMS2("Prepaid SMS", 7.0, true, 300);
SMSPackage prepaidSMS3("Prepaid SMS", 5.0, true, 100);
SMSPackage postpaidSMS("Postpaid SMS", 15.0, false, 1000);
SMSPackage postpaidSMS1("Postpaid SMS", 15.0, false, 750);
SMSPackage postpaidSMS2("Postpaid SMS", 10.0, false, 500);
SMSPackage postpaidSMS3("Postpaid SMS", 7.5, false, 1000);
BundlePackage bundle("Bundle Package", 100.0, true, "Prepaid Internet", 25.0, 50, "Prepaid Call", 15.0, 200, "Prepaid SMS", 10.0, 500);



void displayPackages() {
    cout << "press 1 for Internet" << endl;
    cout << "press 3 for Call" << endl;
    cout << "press 5 for SMS" << endl;
    cout << "press 7 for Bundle Package (Internet, Call, SMS)" << endl;
}

void subscribeToPackage(PackageType type) {
    switch (type) {
    case INTERNET: {
        int a;
        int choice;
        cout << "Select prepaid or postpaid internet package: " << endl;
        cout << "1. Prepaid Internet" << endl;
        cout << "2. Postpaid Internet" << endl;
        cin >> choice;
        cout << "Press 1 For Monthly, 2 For Weekly or 3 For Daily Package" << endl;
        cin >> a;
        if (choice == 1) {
            cout << "You have subscribed to the " << prepaidInternet.packageName << " package" << endl;
            if (a == 1) {
                cout << "Your Monthly Package Bill is: $" << prepaidInternet1.price << endl;
                cout << "Package Type: Internet" << endl;
                cout << "Package Name: " << prepaidInternet.packageName << endl;
                cout << "Price: $" << prepaidInternet1.price << endl;
                cout << "Prepaid: Yes" << endl;
                cout << "Data Limit: " << prepaidInternet1.dataLimit << "GB" << endl;

                // Save package details to file

                ofstream outFile;
                outFile.open("subscribed_package.txt", ios::app);
                outFile << "Package Type: Internet" << endl;
                outFile << "Package Name: " << prepaidInternet1.packageName << endl;
                outFile << "Price: $" << prepaidInternet1.price << endl;
                outFile << "Prepaid: Yes" << endl;
                outFile << "Data Limit: " << prepaidInternet1.dataLimit << "GB" << endl;
                outFile.close();
            }
            else if (a == 2) {
                cout << "Your Weekly Package Bill is: $" << prepaidInternet2.price << endl;
                cout << "Package Type: Internet" << endl;
                cout << "Package Name: " << prepaidInternet.packageName << endl;
                cout << "Price: $" << prepaidInternet2.price << endl;
                cout << "Prepaid: Yes" << endl;
                cout << "Data Limit: " << prepaidInternet2.dataLimit << "GB" << endl;

                // Save package details to file

                ofstream outFile;
                outFile.open("subscribed_package.txt", ios::app);
                outFile << "Package Type: Internet" << endl;
                outFile << "Package Name: " << prepaidInternet2.packageName << endl;
                outFile << "Price: $" << prepaidInternet2.price << endl;
                outFile << "Prepaid: Yes" << endl;
                outFile << "Data Limit: " << prepaidInternet2.dataLimit << "GB" << endl;
                outFile.close();
            }
            else if (a == 3) {
                cout << "Your Daily Package Bill is: $" << prepaidInternet3.price << endl;
                cout << "Package Type: Internet" << endl;
                cout << "Package Name: " << prepaidInternet.packageName << endl;
                cout << "Price: $" << prepaidInternet3.price << endl;
                cout << "Prepaid: Yes" << endl;
                cout << "Data Limit: " << prepaidInternet3.dataLimit << "GB" << endl;

                // Save package details to file

                ofstream outFile;
                outFile.open("subscribed_package.txt", ios::app);
                outFile << "Package Type: Internet" << endl;
                outFile << "Package Name: " << prepaidInternet3.packageName << endl;
                outFile << "Price: $" << prepaidInternet3.price << endl;
                outFile << "Prepaid: Yes" << endl;
                outFile << "Data Limit: " << prepaidInternet3.dataLimit << "GB" << endl;
                outFile.close();
            }


        }
        else if (choice == 2) {
            cout << "You have subscribed to the " << postpaidInternet.packageName << " package" << endl;
            if (a == 1) {
                cout << "Your Monthly Package Bill is: $" << postpaidInternet1.price << endl;
                cout << "Package Type: Internet" << endl;
                cout << "Package Name: " << postpaidInternet.packageName << endl;
                cout << "Price: $" << postpaidInternet1.price << endl;
                cout << "Prepaid: No" << endl;
                cout << "Data Limit: " << postpaidInternet1.dataLimit << "GB" << endl;

                // Save package details to file

                ofstream outFile;
                outFile.open("subscribed_package.txt", ios::app);
                outFile << "Package Type: Internet" << endl;
                outFile << "Package Name: " << postpaidInternet1.packageName << endl;
                outFile << "Price: $" << postpaidInternet1.price << endl;
                outFile << "Prepaid: No" << endl;
                outFile << "Data Limit: " << postpaidInternet1.dataLimit << "GB" << endl;
                outFile.close();
            }
            else if (a == 2) {
                cout << "Your Weekly Package Bill is: $" << postpaidInternet2.price << endl;
                cout << "Package Type: Internet" << endl;
                cout << "Package Name: " << postpaidInternet.packageName << endl;
                cout << "Price: $" << postpaidInternet2.price << endl;
                cout << "Prepaid: No" << endl;
                cout << "Data Limit: " << postpaidInternet2.dataLimit << "GB" << endl;

                // Save package details to file

                ofstream outFile;
                outFile.open("subscribed_package.txt", ios::app);
                outFile << "Package Type: Internet" << endl;
                outFile << "Package Name: " << postpaidInternet2.packageName << endl;
                outFile << "Price: $" << postpaidInternet2.price << endl;
                outFile << "Prepaid: No" << endl;
                outFile << "Data Limit: " << postpaidInternet2.dataLimit << "GB" << endl;
                outFile.close();
            }
            else if (a == 3) {
                cout << "Your Daily Package Bill is: $" << postpaidInternet3.price << endl;
                cout << "Package Type: Internet" << endl;
                cout << "Package Name: " << postpaidInternet.packageName << endl;
                cout << "Price: $" << postpaidInternet3.price << endl;
                cout << "Prepaid: No" << endl;
                cout << "Data Limit: " << postpaidInternet3.dataLimit << "GB" << endl;

                // Save package details to file

                ofstream outFile;
                outFile.open("subscribed_package.txt", ios::app);
                outFile << "Package Type: Internet" << endl;
                outFile << "Package Name: " << postpaidInternet3.packageName << endl;
                outFile << "Price: $" << postpaidInternet3.price << endl;
                outFile << "Prepaid: No" << endl;
                outFile << "Data Limit: " << postpaidInternet3.dataLimit << "GB" << endl;
                outFile.close();
            }

        }
        else {
            cout << "Invalid choice. Please try again." << endl;
        }
        break;
    }
    case CALL: {
        int choice;
        int a;
        cout << "Select prepaid or postpaid call package: " << endl;
        cout << "1. Prepaid Call" << endl;
        cout << "2. Postpaid Call" << endl;
        cin >> choice;
        cout << "Press 1 For Monthly, 2 For Weekly or 3 For Daily Package" << endl;
        cin >> a;
        if (choice == 1) {
            cout << "You have subscribed to the " << prepaidCall.packageName << " package" << endl;
            if (a == 1) {
                cout << "Your Monthly Package Bill is: $" << prepaidCall1.price << endl;
                cout << "Package Type: Call" << endl;
                cout << "Package Name: " << prepaidCall1.packageName << endl;
                cout << "Price: $" << prepaidCall1.price << endl;
                cout << "Prepaid: Yes" << endl;
                cout << "Call Limit: " << prepaidCall1.callLimit << " minutes" << endl;

                // Save package details to file
                ofstream outFile;
                outFile.open("subscribed_package.txt", ios::app);
                outFile << "Package Type: Call" << endl;
                outFile << "Package Name: " << prepaidCall1.packageName << endl;
                outFile << "Price: $" << prepaidCall1.price << endl;
                outFile << "Prepaid: Yes" << endl;
                outFile << "Call Limit: " << prepaidCall1.callLimit << " minutes" << endl;
                outFile.close();
            }
            else if (a == 2) {
                cout << "Your Weekly Package Bill is: $" << prepaidCall2.price << endl;
                cout << "Package Type: Call" << endl;
                cout << "Package Name: " << prepaidCall2.packageName << endl;
                cout << "Price: $" << prepaidCall2.price << endl;
                cout << "Prepaid: Yes" << endl;
                cout << "Call Limit: " << prepaidCall2.callLimit << " minutes" << endl;

                // Save package details to file
                ofstream outFile;
                outFile.open("subscribed_package.txt", ios::app);
                outFile << "Package Type: Call" << endl;
                outFile << "Package Name: " << prepaidCall2.packageName << endl;
                outFile << "Price: $" << prepaidCall2.price << endl;
                outFile << "Prepaid: Yes" << endl;
                outFile << "Call Limit: " << prepaidCall2.callLimit << " minutes" << endl;
                outFile.close();
            }
            else if (a == 3) {
                cout << "Your Daily Package Bill is: $" << prepaidCall3.price << endl;
                cout << "Package Type: Call" << endl;
                cout << "Package Name: " << prepaidCall3.packageName << endl;
                cout << "Price: $" << prepaidCall3.price << endl;
                cout << "Prepaid: Yes" << endl;
                cout << "Call Limit: " << prepaidCall3.callLimit << " minutes" << endl;

                // Save package details to file
                ofstream outFile;
                outFile.open("subscribed_package.txt", ios::app);
                outFile << "Package Type: Call" << endl;
                outFile << "Package Name: " << prepaidCall3.packageName << endl;
                outFile << "Price: $" << prepaidCall3.price << endl;
                outFile << "Prepaid: Yes" << endl;
                outFile << "Call Limit: " << prepaidCall3.callLimit << " minutes" << endl;
                outFile.close();
            }

        }
        else if (choice == 2) {
            cout << "You have subscribed to the " << postpaidCall.packageName << " package" << endl;
            if (a == 1) {
                cout << "Your Monthly Package Bill is: $" << postpaidCall1.price << endl;
                cout << "Package Type: Call" << endl;
                cout << "Package Name: " << postpaidCall1.packageName << endl;
                cout << "Price: $" << postpaidCall1.price << endl;
                cout << "Prepaid: No" << endl;
                cout << "Call Limit: " << postpaidCall1.callLimit << " minutes" << endl;

                // Save package details to file
                ofstream outFile;
                outFile.open("subscribed_package.txt", ios::app);
                outFile << "Package Type: Call" << endl;
                outFile << "Package Name: " << postpaidCall1.packageName << endl;
                outFile << "Price: $" << postpaidCall1.price << endl;
                outFile << "Prepaid: No" << endl;
                outFile << "Call Limit: " << postpaidCall1.callLimit << " minutes" << endl;
                outFile.close();
            }
            else if (a == 2) {
                cout << "Your Weekly Package Bill is: $" << postpaidCall2.price << endl;
                cout << "Your Monthly Package Bill is: $" << postpaidCall2.price << endl;
                cout << "Package Type: Call" << endl;
                cout << "Package Name: " << postpaidCall2.packageName << endl;
                cout << "Price: $" << postpaidCall2.price << endl;
                cout << "Prepaid: No" << endl;
                cout << "Call Limit: " << postpaidCall2.callLimit << " minutes" << endl;

                // Save package details to file
                ofstream outFile;
                outFile.open("subscribed_package.txt", ios::app);
                outFile << "Package Type: Call" << endl;
                outFile << "Package Name: " << postpaidCall2.packageName << endl;
                outFile << "Price: $" << postpaidCall2.price << endl;
                outFile << "Prepaid: No" << endl;
                outFile << "Call Limit: " << postpaidCall2.callLimit << " minutes" << endl;
                outFile.close();
            }
            else if (a == 3) {
                cout << "Your Daily Package Bill is: $" << postpaidCall3.price << endl;
                cout << "Your Monthly Package Bill is: $" << postpaidCall3.price << endl;
                cout << "Package Type: Call" << endl;
                cout << "Package Name: " << postpaidCall3.packageName << endl;
                cout << "Price: $" << postpaidCall3.price << endl;
                cout << "Prepaid: No" << endl;
                cout << "Call Limit: " << postpaidCall3.callLimit << " minutes" << endl;

                // Save package details to file
                ofstream outFile;
                outFile.open("subscribed_package.txt", ios::app);
                outFile << "Package Type: Call" << endl;
                outFile << "Package Name: " << postpaidCall3.packageName << endl;
                outFile << "Price: $" << postpaidCall3.price << endl;
                outFile << "Prepaid: No" << endl;
                outFile << "Call Limit: " << postpaidCall3.callLimit << " minutes" << endl;
                outFile.close();
            }

        }
        else {
            cout << "Invalid choice. Please try again." << endl;
        }
        break;
    }
    case SMS: {
        int choice;
        int a;
        cout << "Select prepaid or postpaid SMS package: " << endl;
        cout << "1. Prepaid SMS" << endl;
        cout << "2. Postpaid SMS" << endl;
        cin >> choice;
        cout << "Press 1 For Monthly, 2 For Weekly or 3 For Daily Package" << endl;
        cin >> a;
        if (choice == 1) {
            cout << "You have subscribed to the " << prepaidSMS.packageName << " package" << endl;
            if (a == 1) {
                cout << "Your Monthly Package Bill is: $" << prepaidSMS1.price << endl;
                cout << "Package Type: SMS" << endl;
                cout << "Package Name: " << prepaidSMS1.packageName << endl;
                cout << "Price: $" << prepaidSMS1.price << endl;
                cout << "Prepaid: Yes" << endl;
                cout << "SMS Limit: " << prepaidSMS1.smsLimit << " messages" << endl;

                // Save package details to file
                ofstream outFile;
                outFile.open("subscribed_package.txt", ios::app);
                outFile << "Package Type: SMS" << endl;
                outFile << "Package Name: " << prepaidSMS1.packageName << endl;
                outFile << "Price: $" << prepaidSMS1.price << endl;
                outFile << "Prepaid: Yes" << endl;
                outFile << "SMS Limit: " << prepaidSMS1.smsLimit << " messages" << endl;
                outFile.close();
            }
            else if (a == 2) {
                cout << "Your Weekly Package Bill is: $" << prepaidSMS2.price << endl;
                cout << "Your Monthly Package Bill is: $" << prepaidSMS2.price << endl;
                cout << "Package Type: SMS" << endl;
                cout << "Package Name: " << prepaidSMS2.packageName << endl;
                cout << "Price: $" << prepaidSMS2.price << endl;
                cout << "Prepaid: Yes" << endl;
                cout << "SMS Limit: " << prepaidSMS2.smsLimit << " messages" << endl;

                // Save package details to file
                ofstream outFile;
                outFile.open("subscribed_package.txt", ios::app);
                outFile << "Package Type: SMS" << endl;
                outFile << "Package Name: " << prepaidSMS2.packageName << endl;
                outFile << "Price: $" << prepaidSMS2.price << endl;
                outFile << "Prepaid: Yes" << endl;
                outFile << "SMS Limit: " << prepaidSMS2.smsLimit << " messages" << endl;
                outFile.close();
            }
            else if (a == 3) {
                cout << "Your Daily Package Bill is: $" << prepaidSMS3.price << endl;
                cout << "Your Monthly Package Bill is: $" << prepaidSMS3.price << endl;
                cout << "Package Type: SMS" << endl;
                cout << "Package Name: " << prepaidSMS3.packageName << endl;
                cout << "Price: $" << prepaidSMS3.price << endl;
                cout << "Prepaid: Yes" << endl;
                cout << "SMS Limit: " << prepaidSMS3.smsLimit << " messages" << endl;

                // Save package details to file
                ofstream outFile;
                outFile.open("subscribed_package.txt", ios::app);
                outFile << "Package Type: SMS" << endl;
                outFile << "Package Name: " << prepaidSMS3.packageName << endl;
                outFile << "Price: $" << prepaidSMS3.price << endl;
                outFile << "Prepaid: Yes" << endl;
                outFile << "SMS Limit: " << prepaidSMS3.smsLimit << " messages" << endl;
                outFile.close();
            }

        }
        else
            if (choice == 2) {
                cout << "You have subscribed to the " << postpaidSMS.packageName << " package" << endl;
                if (a == 1) {
                    cout << "Your Monthly Package Bill is: $" << postpaidSMS1.price << endl;
                    cout << "Package Type: SMS" << endl;
                    cout << "Package Name: " << postpaidSMS1.packageName << endl;
                    cout << "Price: $" << postpaidSMS1.price << endl;
                    cout << "Prepaid: Yes" << endl;
                    cout << "SMS Limit: " << postpaidSMS1.smsLimit << " messages" << endl;

                    // Save package details to file
                    ofstream outFile;
                    outFile.open("subscribed_package.txt", ios::app);
                    outFile << "Package Type: SMS" << endl;
                    outFile << "Package Name: " << postpaidSMS1.packageName << endl;
                    outFile << "Price: $" << postpaidSMS1.price << endl;
                    outFile << "Prepaid: No" << endl;
                    outFile << "SMS Limit: " << postpaidSMS1.smsLimit << " messages" << endl;
                    outFile.close();
                }
                else if (a == 2) {
                    cout << "Your Weekly Package Bill is: $" << postpaidSMS2.price << endl;
                    cout << "Package Type: SMS" << endl;
                    cout << "Package Name: " << postpaidSMS2.packageName << endl;
                    cout << "Price: $" << postpaidSMS2.price << endl;
                    cout << "Prepaid: Yes" << endl;
                    cout << "SMS Limit: " << postpaidSMS2.smsLimit << " messages" << endl;

                    // Save package details to file
                    ofstream outFile;
                    outFile.open("subscribed_package.txt", ios::app);
                    outFile << "Package Type: SMS" << endl;
                    outFile << "Package Name: " << postpaidSMS2.packageName << endl;
                    outFile << "Price: $" << postpaidSMS2.price << endl;
                    outFile << "Prepaid: No" << endl;
                    outFile << "SMS Limit: " << postpaidSMS2.smsLimit << " messages" << endl;
                    outFile.close();
                }
                else if (a == 3) {
                    cout << "Your Daily Package Bill is: $" << postpaidSMS3.price << endl;
                    cout << "Package Type: SMS" << endl;
                    cout << "Package Name: " << postpaidSMS3.packageName << endl;
                    cout << "Price: $" << postpaidSMS3.price << endl;
                    cout << "Prepaid: Yes" << endl;
                    cout << "SMS Limit: " << postpaidSMS3.smsLimit << " messages" << endl;

                    // Save package details to file
                    ofstream outFile;
                    outFile.open("subscribed_package.txt", ios::app);
                    outFile << "Package Type: SMS" << endl;
                    outFile << "Package Name: " << postpaidSMS3.packageName << endl;
                    outFile << "Price: $" << postpaidSMS3.price << endl;
                    outFile << "Prepaid: No" << endl;
                    outFile << "SMS Limit: " << postpaidSMS3.smsLimit << " messages" << endl;
                    outFile.close();
                }

            }
            else {
                cout << "Invalid choice. Please try again." << endl;
            }
        break;
    }
    case BUNDLE: {
        cout << "You have subscribed to the " << bundle.packageName << " package" << endl;
        cout << "Your Monthly Bundle Bill is: $" << bundle.price << endl;
        // Save package details to file
        ofstream outFile;
        outFile.open("subscribed_package.txt", ios::app);
        outFile << "Package Type: Bundle" << endl;
        outFile << "Package Name: " << bundle.packageName << endl;
        outFile << "Price: $" << bundle.price << endl;
        outFile << "Prepaid: Yes" << endl;
        outFile << "Internet Package: " << bundle.internetName << endl;
        outFile << "Internet Price: $" << bundle.internetPrice << endl;
        outFile << "Data Limit: " << bundle.dataLimit << "GB" << endl;
        outFile << "Call Package: " << bundle.callName << endl;
        outFile << "Call Price: $" << bundle.callPrice << endl;
        outFile << "Call Limit: " << bundle.callLimit << " minutes" << endl;
        outFile << "SMS Package: " << bundle.smsName << endl;
        outFile << "SMS Price: $" << bundle.smsPrice << endl;
        outFile << "SMS Limit: " << bundle.smsLimit << " messages" << endl;
        outFile.close();
        break;
    }
    }
}
void acc_setup()
{
    char acc;
    cout << "do you want to signup or do you want to login \nPress s for signup \nPress l for login " << endl;
    cin >> acc;
    if (acc == 's')
    {
        cin.ignore();
        string signup_name, signup_pass, conf_pass;
        int ph_no;
        cout << "\t\t\t\t\t\t------- ACCOUNT SIGNUP -------" << endl;
        cout << "Enter your name:" << endl;
        getline(cin, signup_name);
        cout << "Enter your phone number:" << endl;
        cin >> ph_no;
        cout << "Enter password:" << endl;
        cin >> signup_pass;
        cout << "enter password again for verification:" << endl;
        cin >> conf_pass;
        if (conf_pass == signup_pass)
        {
            cout << "SIGNUP SUCCESFULL!" << endl;
        }
        else
        {
            cout << "password does not match! \nplease try again" << endl;
            acc_setup();
        }

    }
    else if (acc == 'l')
    {
        cin.ignore();
        string login_name;
        int login_pass;
        cout << "\t\t\t\t\t\t ------- ACCOUNT LOGIN ------- " << endl;
        cout << "Enter regestered username:" << endl;
        getline(cin, login_name);
        cout << "Enter password:" << endl;
        cin >> login_pass;
        int sk = 007;
        if (login_name == "saimkhan" && login_pass == sk)
        {
            cout << "LOGIN SUCCESFULL!" << endl;

        }
        else
        {
            cout << "the username or password you entered is incorrect." << endl;

        }
    }
    else
    {
        cout << "you entered invalid opotion." << endl;

    }
}

int balance_inquiry()
{
    if (balance == 0)
    {
        balance = 1 + rand() % 5000;
        cout << "your current balance is : $" << balance << endl;
    }
    else
    {
        cout << "your current balance is : $" << balance << endl;
    }

    return balance;
}

int balance_topup()
{

    int current_bal, topup;
    if (balance == 0)
    {
        balance = 1 + rand() % 5000;
        cout << "your current balance is : $" << balance << endl;
    }
    else
    {
        cout << "your current balance is : $" << balance << endl;
    }
    cout << "enter the amount you want to topup:" << endl;
    cin >> topup;
    current_bal = balance + topup;
    cout << "your updated balance is : $" << current_bal << endl;
    return balance = current_bal;

}
void package_funct()
{
    int count = 0;
    int choice;
    int sub;
    int b;
    cout << "Press 1 to Subscribe a Package \nPress 2 to Unsubscribe a Package" << endl;
    cin >> sub;
    if (sub == 1)
    {
        displayPackages();
    }

    else if (sub == 2)
    {
        cout << "You have Successfully Unsubscribe the Package" << endl;
        cout << "Press 1 If You Want To Subscribe A New Package Or Any Other Number To Exit" << endl;
        cin >> b;
        if (b == 1)
        {
            cout << "Enter Choice for New Package" << endl;
            displayPackages();
        }
        else
        {
            count = 1;
            cout << "Thank You For Enjoying Our Services. Have A Good Day!" << endl;
        }

    }
    while (count == 0)
    {

        cout << "Enter your choice: " << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            subscribeToPackage(INTERNET);
            count = 1;
            break;
        }
        case 2:
        {
            subscribeToPackage(INTERNET);
            count = 1;
            break;
        }
        case 3:
        {
            subscribeToPackage(CALL);
            count = 1;
            break;
        }
        case 4:
        {
            subscribeToPackage(CALL);
            count = 1;

            break;
        }
        case 5:
        {
            subscribeToPackage(SMS);
            count = 1;
            break;
        }
        case 6:
        {
            subscribeToPackage(SMS);
            count = 1;
            break;
        }
        case 7:
        {
            subscribeToPackage(BUNDLE);
            count = 1;
            break;
        }
        default:
        {
            cout << "Invalid choice. Please try again." << endl;
            count = 0;
            break;
        }
        }
    }

}

int main()
{
    cout << setfill('=') << setw(120) << "=" << endl;
    cout << endl;
    cout << setfill('=') << setw(120) << "=" << endl;
    cout << endl;
    cout << "\t\t\t    #       # ##### #     ##### ###### ##     ## #####     ##### #####" << endl;
    cout << "\t\t\t    #   #   # #     #     #     #    # # #   # # #           #   #   #" << endl;
    cout << "\t\t\t    #  # #  # ####  #     #     #    # #  # #  # ####        #   #   #" << endl;
    cout << "\t\t\t    # #   # # #     #     #     #    # #   #   # #           #   #   #" << endl;
    cout << "\t\t\t    ##     ## ##### ##### ##### ###### #       # #####       #   #####" << endl;
    cout << endl;
    cout << setfill('=') << setw(120) << "=" << endl;
    cout << endl;
    cout << "\t\t\t\t    ##### ##### #     ##### ##### ###### ##     ## " << endl;
    cout << "\t\t\t\t      #   #     #     #     #     #    # # #   # # " << endl;
    cout << "\t\t\t\t      #   ##### #     ##### #     #    # #  # #  # " << endl;
    cout << "\t\t\t\t      #   #     #     #     #     #    # #   #   # " << endl;
    cout << "\t\t\t\t      #   ##### ##### ##### ##### ###### #       # " << endl;
    cout << endl;
    cout << setfill('=') << setw(120) << "=" << endl;
    cout << endl;
    cout << setfill('=') << setw(120) << "=" << endl;
    cout << endl;

    ofstream ofile;
    ofile.open("welcomescreen.txt", ios::app);
    ofile << setfill('=') << setw(120) << "=" << endl;
    ofile << endl;
    ofile << setfill('=') << setw(120) << "=" << endl;
    ofile << endl;
    ofile << "\t\t\t    #       # ##### #     ##### ###### ##     ## #####     ##### #####" << endl;
    ofile << "\t\t\t    #   #   # #     #     #     #    # # #   # # #           #   #   #" << endl;
    ofile << "\t\t\t    #  # #  # ####  #     #     #    # #  # #  # ####        #   #   #" << endl;
    ofile << "\t\t\t    # #   # # #     #     #     #    # #   #   # #           #   #   #" << endl;
    ofile << "\t\t\t    ##     ## ##### ##### ##### ###### #       # #####       #   #####" << endl;
    ofile << endl;
    ofile << setfill('=') << setw(120) << "=" << endl;
    ofile << endl;
    ofile << "\t\t\t\t    ##### ##### #     ##### ##### ###### ##     ## " << endl;
    ofile << "\t\t\t\t      #   #     #     #     #     #    # # #   # # " << endl;
    ofile << "\t\t\t\t      #   ##### #     ##### #     #    # #  # #  # " << endl;
    ofile << "\t\t\t\t      #   #     #     #     #     #    # #   #   # " << endl;
    ofile << "\t\t\t\t      #   ##### ##### ##### ##### ###### #       # " << endl;
    ofile << endl;
    ofile << setfill('=') << setw(120) << "=" << endl;
    ofile << endl;
    ofile << setfill('=') << setw(120) << "=" << endl;
    ofile << endl;
    ofile.close();

    int repeat;

    acc_setup();
    int var_switch;

    do
    {
        cout << "Press 1 for balance inquiry:" << endl;
        cout << "Press 2 for balance topup:" << endl;
        cout << "Press 3 for package subscription:" << endl;
        cin >> var_switch;
        switch (var_switch)
        {
        case 1:
            balance_inquiry();

            break;
        case 2:
            balance_topup();

            break;
        case 3:
            package_funct();

            break;
        default:
            cout << "Invalid optins please try again later!" << endl;
            break;
        }


        cout << "press 0 to continue or any other ke to exit" << endl;
        cin >> repeat;
    } while (repeat == 0);

    return 0;

}