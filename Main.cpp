#include <iostream>
#include <string>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <ctime>
#include <cmath>
#pragma warning(disable : 4996)
using namespace std;

struct payBillNode {
    string billType;
    long long billInvoiceNumber;  // 10 digits
    double billAmount{};
    payBillNode* next{nullptr};
    payBillNode* prev{nullptr};
};

class billPaymentQueue {
private:
    payBillNode* front{nullptr};
    payBillNode* rear{nullptr};
public:
    billPaymentQueue() = default;

    bool isEmpty() const {
        return (rear == nullptr && front == nullptr);
    }

    void enqueue() {
        payBillNode* temp = new payBillNode();
        char confirmation{};

        cout << "\t\t\t\t Kindly write down your bill type from the following: Electricity, Gas, Internet -> ";
        cin >> temp->billType;
        cout << "\t\t\t\t Kindly write down the 10 digit Invoice Number -> ";
        cin >> temp->billInvoiceNumber;
        cout << "\t\t\t\t Kindly write down the bill amount -> ";
        cin >> temp->billAmount;
        cout << "\t\t\t\t----------" << endl;
        cout << "\t\t\t\tBill Type : " << temp->billType << endl;
        cout << "\t\t\t\tBill Invoice# : " << temp->billInvoiceNumber << endl;
        cout << "\t\t\t\tBill Amount : " << temp->billAmount << endl;
        cout << "\t\t\t\t----------" << endl;
        cout << "\t\t\t\t Press 'Y' to confirm, or 'N' to exit" << endl;
        cout << "\t\t\t\t ";
        cin >> confirmation;
        temp->next = nullptr;

        if (confirmation == 'y' || confirmation == 'Y') {
            if (isEmpty()) {
                temp->prev = nullptr;
                front = rear = temp;
                cout << "\t\t\t\t Transaction Completed, Bill payment in process." << endl;
            } else {
                temp->prev = rear;
                rear->next = temp;
                rear = temp;
                cout << "\t\t\t\t Transaction Completed, Bill payment in process." << endl;
            }
        } else if (confirmation == 'n' || confirmation == 'N') {
            delete temp; // prevent leak
            cout << "\t\t\t\t Transaction not Completed." << endl;
        } else {
            delete temp; // prevent leak
            cout << "\t\t\t\t ERROR!!! Wrong input entered, transaction failed!" << endl;
        }

        cout << "\t\t\t\t Press any key to return to Bank Menu" << endl;
        _getch();
    }

    void dequeue() {
        payBillNode* temp = front;

        if (isEmpty()) {
            cout << "\t\t\t\t Bill Payment Queue is empty, nothing left to process" << endl;
            cout << "\t\t\t\t Press any key to return to Bank Menu" << endl;
            _getch();
            return;
        }

        cout << "\t\t\t\t Bill# " << temp->billInvoiceNumber << " has been paid." << endl;

        if (front == rear) {
            front = rear = nullptr;
        } else {
            front = front->next;
            if (front) front->prev = nullptr; // fix dangling prev
        }
        delete temp;

        cout << "\t\t\t\t Press any key to return to Bank Menu" << endl;
        _getch();
    }

    void displayBillPaymentQueue() const {
        if (isEmpty()) {
            cout << "\t\t\t\t Bill Payment Queue is empty" << endl;
            cout << "\t\t\t\t Press any key to return to Bank Menu" << endl;
            _getch();
            return;
        }

        int count = 0;
        for (payBillNode* temp = front; temp != nullptr; temp = temp->next) {
            cout << "\t\t\t\t--------------- #" << count << " ---------------" << endl;
            cout << "\t\t\t\tBill Type : " << temp->billType << endl;
            cout << "\t\t\t\tBill Invoice# : " << temp->billInvoiceNumber << endl;
            cout << "\t\t\t\tBill Amount : " << temp->billAmount << endl;
            cout << "\t\t\t\t---------------------------------------------" << endl << endl;
            ++count;
        }
        cout << "\t\t\t\t Press any key to return to Bank Menu" << endl;
        _getch();
    }

    void displayFront() const {
        if (isEmpty()) {
            cout << "\t\t\t\t Bill Payment Queue is empty" << endl;
            cout << "\t\t\t\t Press any key to return to Bank Menu" << endl;
            _getch();
            return;
        }

        cout << "\t\t\t\t------------------------------" << endl;
        cout << "\t\t\t\tBill Amount: " << front->billAmount << endl;
        cout << "\t\t\t\tBill Invoice#: " << front->billInvoiceNumber << endl;
        cout << "\t\t\t\tBill Type: " << front->billType << endl;
        cout << "\t\t\t\t------------------------------" << endl << endl;
        cout << "\t\t\t\t Press any key to return to Bank Menu" << endl;
        _getch();
    }
};

struct withdrawDepositNode {
    long long accountNumber{};
    double cashAmount{};
    bool withdrawCash{false};
    bool depositCash{false};
    withdrawDepositNode* next{nullptr};
    withdrawDepositNode* prev{nullptr};
};

class withdrawDepositQueue {
private:
    withdrawDepositNode* front{nullptr};
    withdrawDepositNode* rear{nullptr};
public:
    withdrawDepositQueue() = default;

    bool isEmpty() const {
        return (rear == nullptr && front == nullptr);
    }

    void enqueue() {
        withdrawDepositNode* temp = new withdrawDepositNode();

        int opt = 0;
        string flag;

        cout << "\t\t\t\t Kindly choose from the following two options: 1) Withdraw Cash (cheque) or 2) Deposit Cash -> ";
        cin >> opt;

        if (opt == 1) {
            temp->withdrawCash = true;
            temp->depositCash = false;
            flag = "Withdraw Cash";
        } else if (opt == 2) {
            temp->depositCash = true;
            temp->withdrawCash = false;
            flag = "Deposit Cash";
        } else {
            delete temp;
            cout << "\t\t\t\t Wrong option entered, press any key to return to menu." << endl;
            _getch();
            return;
        }

        char confirmation{};

        cout << "\t\t\t\t Kindly write down the 10 digit Account Number -> ";
        cin >> temp->accountNumber;
        cout << "\t\t\t\t Kindly write down the cash amount -> ";
        cin >> temp->cashAmount;
        cout << "\t\t\t\t----------" << endl;
        cout << "\t\t\t\tAccount#: " << temp->accountNumber << endl;
        cout << "\t\t\t\tCash: " << temp->cashAmount << endl;
        cout << "\t\t\t\tTransaction Type: " << flag << endl;
        cout << "\t\t\t\t----------" << endl;
        cout << "\t\t\t\t Press 'Y' to confirm, or 'N' to exit" << endl;
        cout << "\t\t\t\t ";
        cin >> confirmation;
        temp->next = nullptr;

        if (confirmation == 'y' || confirmation == 'Y') {
            if (isEmpty()) {
                temp->prev = nullptr;
                front = rear = temp;
                cout << "\t\t\t\t Transaction Completed." << endl;
            } else {
                temp->prev = rear;
                rear->next = temp;
                rear = temp;
                cout << "\t\t\t\t Transaction Completed." << endl;
            }
        } else if (confirmation == 'n' || confirmation == 'N') {
            delete temp;
            cout << "\t\t\t\t Transaction not Completed." << endl;
        } else {
            delete temp;
            cout << "\t\t\t\t ERROR!!! Wrong input entered, transaction failed!" << endl;
        }

        cout << "\t\t\t\t Press any key to return to Bank Menu" << endl;
        _getch();

    }

    void dequeue() {
        if (isEmpty()) {
            cout << "\t\t\t\t Withdraw/Deposit Queue is empty, nothing left to process" << endl;
            cout << "\t\t\t\t Press any key to return to Bank Menu" << endl;
            _getch();
            return;
        }

        withdrawDepositNode* temp = front;

        cout << "\t\t\t\t----------" << endl;
        cout << "\t\t\t\t " << temp->accountNumber << endl;
        cout << "\t\t\t\t " << temp->cashAmount << endl;
        cout << "\t\t\t\t----------" << endl;
        cout << "\t\t\t\t Transaction has been done." << endl;

        if (front == rear) {
            front = rear = nullptr;
        } else {
            front = front->next;
            if (front) front->prev = nullptr; // fix
        }
        delete temp;

        cout << "\t\t\t\t Press any key to return to Bank Menu" << endl;
        _getch();
    }

    void displayWithdrawDepositQueue() const {
        if (isEmpty()) {
            cout << "\t\t\t\t Withdraw/Deposit Payment Queue is empty" << endl;
            cout << "\t\t\t\t Press any key to return to Bank Menu" << endl;
            _getch();
            return;
        }

        int count = 0;

        for (withdrawDepositNode* temp = front; temp != nullptr; temp = temp->next) {
            cout << "\t\t\t\t--------------- #" << count << " ---------------" << endl;
            cout << "\t\t\t\t " << temp->accountNumber << endl;
            cout << "\t\t\t\t " << temp->cashAmount << endl;
            cout << "\t\t\t\t Withdraw = " << (temp->withdrawCash ? "Yes" : "No") << endl;
            cout << "\t\t\t\t Deposit = " << (temp->depositCash ? "Yes" : "No") << endl;
            cout << "\t\t\t\t---------------------------------------------" << endl << endl;
            ++count;
        }
        cout << "\t\t\t\t Press any key to return to Bank Menu" << endl;
        _getch();
    }
};

class address {
public:
    int houseNumber;
    string townName;
    int streetNumber;
    string city;

    address(int hN = 0, string tN = "", int sN = 0, string c = "") {
        houseNumber = hN;
        townName = tN;
        streetNumber = sN;
        city = c;
    }
    void setAddress() {
        cout << "\t\t\t\t House# = "; cin >> houseNumber;
        cout << "\t\t\t\t Town Name = "; cin >> townName;
        cout << "\t\t\t\t Street# = "; cin >> streetNumber;
        cout << "\t\t\t\t City = "; cin >> city;
    }
    int getHouseNumber() const { return houseNumber; }
    int getStreetNumber() const { return streetNumber; } // FIX
    string getCity() const { return city; }
    string getTownName() const { return townName; }
    void displayAddress() const {
        cout << "\t\t\t\t House# = " << houseNumber << endl;
        cout << "\t\t\t\t Town Name = " << townName << endl;
        cout << "\t\t\t\t Street# = " << streetNumber << endl;
        cout << "\t\t\t\t City = " << city << endl;
    }
};

struct newAccountNode {
    string firstName;
    string lastName;
    string accountStatus;
    long long phoneNumber{};
    long long CNIC{};
    double cash{};
    string emailAddress;
    address homeAddress;
    bool debitCard{false};
    bool chequeBook{false};
    int debitCardPin{0};
    string username;
    string password;
    long long accountNumber{0};
    newAccountNode* next{nullptr};
    newAccountNode* prev{nullptr};
};

class bankAccountsDatabase {
public:
    newAccountNode* head{nullptr};
    newAccountNode* tail{nullptr};

public:
    bankAccountsDatabase() = default;

    bool checkUsernameClash(const string& usernameEnt) {
        newAccountNode* temp = head;
        while (temp != nullptr) {
            if (temp->username == usernameEnt) return true;
            temp = temp->next;
        }
        return false;
    }

    void insertNewAccount() {
        newAccountNode* temp = new newAccountNode();

        char confirmation{};
        int debitCardOpt = 0;
        int chequeBookOpt = 0;
        time_t t = time(nullptr);
        tm* tPtr = localtime(&t);

        cout << "\t\t\t\t Kindly write down your First Name -> ";
        cin >> temp->firstName;
        cout << "\t\t\t\t Kindly write down your Last Name -> ";
        cin >> temp->lastName;
        cout << "\t\t\t\t Kindly write down your Email Address -> ";
        cin >> temp->emailAddress;
        cout << "\t\t\t\t Kindly write down your Home Address -> " << endl;
        temp->homeAddress.setAddress();
        cout << "\t\t\t\t Kindly write down your Phone Number -> ";
        cin >> temp->phoneNumber;
        cout << "\t\t\t\t Kindly write down your CNIC -> ";
        cin >> temp->CNIC;
        cout << "\t\t\t\t Do you want to get a Debit Card: write Yes(1) or No(0)-> ";
        cin >> debitCardOpt;

        if (debitCardOpt == 1) {
            temp->debitCard = true;
            cout << "\t\t\t\t Kindly write down your Debit Card PIN (4 Digits) -> ";
            cin >> temp->debitCardPin;
        } else if (debitCardOpt == 0) {
            temp->debitCard = false;
            temp->debitCardPin = 0;
            cout << "\t\t\t\t Debit card is set as No(0)" << endl;
        } else {
            temp->debitCard = false;
            temp->debitCardPin = 0;
            cout << "\t\t\t\t Invalid Option entered, debit card is set as No(N)" << endl;
        }

        cout << "\t\t\t\t Do you want to get a ChequeBook: write Yes(1) or No(0)-> ";
        cin >> chequeBookOpt;
        if (chequeBookOpt == 1) {
            temp->chequeBook = true;
        } else if (chequeBookOpt == 0) {
            temp->chequeBook = false;
        } else {
            cout << "\t\t\t\t Invalid Option entered, cheque book is set as No(N)" << endl;
        }

TYPEAGAINUSNM:
        cout << "\t\t\t\t Kindly write down your desired Username(NO Space Allowed) -> ";
        cin >> temp->username;

        if (checkUsernameClash(temp->username)) {
            cout << "\t\t\t\t Username has already been taken.!" << endl;
            goto TYPEAGAINUSNM;
        }

        cout << "\t\t\t\t Kindly write down your desired Password(NO Space Allowed) -> ";
        cin >> temp->password;

        system("cls");

        cout << "\n\n\n\t\t\t Date: " << (tPtr->tm_mday) << "/" << (tPtr->tm_mon) + 1 << "/" << (tPtr->tm_year) + 1900 << endl;
        cout << "\t\t\t Time: " << (tPtr->tm_hour) << ":" << (tPtr->tm_min) << endl;

        cout << "\t\t\t ##########################################################################################################################" << endl;
        cout << "\t\t\t #" << "\t\t\t\t\t\t Cybertech's Bank Management Application\t\t\t\t\t\t  #" << endl;
        cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
        cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;

        cout << "\t\t\t\t----------" << endl;
        cout << "\t\t\t\tFirst Name: " << temp->firstName << endl;
        cout << "\t\t\t\tLast Name: " << temp->lastName << endl;
        cout << "\t\t\t\tEmail Address: " << temp->emailAddress << endl;
        cout << "\t\t\t\tCNIC: " << temp->CNIC << endl;
        cout << "\t\t\t\tPhone#: " << temp->phoneNumber << endl;
        cout << "\t\t\t\t ---Address--- " << endl;
        temp->homeAddress.displayAddress();
        cout << "\t\t\t\t -------------" << endl;
        cout << "\t\t\t\tUsername: " << temp->username << endl;
        cout << "\t\t\t\tPassword: " << temp->password << endl;
        cout << "\t\t\t\tDebit Card: " << temp->debitCard << endl;
        cout << "\t\t\t\tCheque Book: " << temp->chequeBook << endl;
        cout << "\t\t\t\tDebit Card PIN: " << temp->debitCardPin << endl;
        cout << "\t\t\t\t Press 'Y' to confirm, or 'N' to exit" << endl;
        cout << "\t\t\t\t ";
        cin >> confirmation;
        temp->next = nullptr;

        if (confirmation == 'y' || confirmation == 'Y') {
            temp->cash = 900000;
            temp->accountStatus = "In Process";
            temp->accountNumber = 0;

            if (head == nullptr) {
                temp->prev = nullptr;
                head = tail = temp;
            } else {
                temp->prev = tail;
                tail->next = temp;
                tail = temp;
            }
            cout << "\t\t\t\t Account Details Completed, in process now." << endl;
        } else if (confirmation == 'n' || confirmation == 'N') {
            delete temp; // prevent leak
            cout << "\t\t\t\t Account not Completed." << endl;
        } else {
            delete temp;
            cout << "\t\t\t\t ERROR!!! Wrong input entered, account opening failed!" << endl;
        }

        cout << "\t\t\t\t Press any key to return to Bank Menu" << endl;
        _getch();
    }

    void viewAccountsToBeProcessed() {
        newAccountNode* temp = head;

        if (head == nullptr) {
            cout << "\t\t\t\t Account Database is empty" << endl;
            cout << "\t\t\t\t Press any key to return to Bank Menu" << endl;
            _getch();
            return;
        }

        int count = 1;

        while (temp != nullptr) {
            if (temp->accountStatus == "In Process") {
                cout << "\t\t\t\t--------------- #" << count++ << " ---------------" << endl;
                cout << "\t\t\t\t----------" << endl;
                cout << "\t\t\t\tFirst Name: " << temp->firstName << endl;
                cout << "\t\t\t\tLast Name: " << temp->lastName << endl;
                cout << "\t\t\t\tCNIC: " << temp->CNIC << endl;
                cout << "\t\t\t\t ---Address--- " << endl;
                temp->homeAddress.displayAddress();
                cout << "\t\t\t\t -------------" << endl;
                cout << "\t\t\t\tUsername: " << temp->username << endl;
                cout << "\t\t\t\tPassword: " << temp->password << endl;
                cout << "\t\t\t\t--------------- #" << count << " ---------------" << endl << endl;
            }
            temp = temp->next;
        }
        cout << "\t\t\t\t Press any key to return to Bank Menu" << endl;
        _getch();
    }

    void processAccounts() {
        newAccountNode* temp = head;

        if (head == nullptr) {
            cout << "\t\t\t\t Account Database is empty" << endl;
            cout << "\t\t\t\t Press any key to return to Bank Menu" << endl;
            _getch();
            return;
        }

        int count = 1;
        int opt = 0;

        while (temp != nullptr) {
            if (temp->accountStatus == "In Process") {
                cout << "\t\t\t\t--------------- #" << count++ << " ---------------" << endl;
                cout << "\t\t\t\t----------" << endl;
                cout << "\t\t\t\tFirst Name: " << temp->firstName << endl;
                cout << "\t\t\t\tLast Name: " << temp->lastName << endl;
                cout << "\t\t\t\tCNIC: " << temp->CNIC << endl;
                cout << "\t\t\t\t ---Address--- " << endl;
                temp->homeAddress.displayAddress();
                cout << "\t\t\t\t -------------" << endl;
                cout << "\t\t\t\tUsername: " << temp->username << endl;
                cout << "\t\t\t\tPassword: " << temp->password << endl;
                cout << "\t\t\t\t--------------- #" << count << " ---------------" << endl << endl;
                cout << "\t\t\t\t Do you want to process this account or not? Yes(1) No(0)" << endl;
                cin >> opt;

                if (opt == 1) {
                    temp->accountStatus = "Completed";
                    temp->accountNumber = generateAccountNumber();
                } else if (opt == 0) {
                    temp->accountStatus = "Declined"; // FIX
                } else {
                    cout << "\t\t\t\t Wrong option entered, account not completed nor declined." << endl;
                }
            }
            temp = temp->next;
        }
        cout << "\t\t\t\t Press any key to return to Bank Menu" << endl;
        _getch();
    }

    int countNodes() {
        int count = 0;
        newAccountNode* temp = head;
        while (temp != nullptr) {
            if (temp->accountStatus == "Completed") {
                ++count;
            }
            temp = temp->next;
        }
        return count;
    }

    long long generateAccountNumber() {
        long long accNumber = 1007750LL + static_cast<long long>(countNodes());
        return accNumber;
    }

    void deleteAccount(long long accountNum) {
        if (head == nullptr) {
            cout << "\t\t\t\tAccount Database is empty, nothing is available to delete!!!!" << endl;
        } else {
            newAccountNode* cur = head;
            while (cur && cur->accountNumber != accountNum) {
                cur = cur->next;
            }
            if (!cur) {
                cout << "\t\t\t\tAccount not found in database !!!!" << endl;
            } else {
                if (cur == head) head = head->next;
                if (cur == tail) tail = tail->prev;
                if (cur->prev) cur->prev->next = cur->next;
                if (cur->next) cur->next->prev = cur->prev;
                delete cur;
                cout << "\t\t\t\tAccount found in database and successfully deleted !!!!" << endl;
            }
        }
        cout << "\t\t\t\t Press any key to return to Bank Menu" << endl;
        _getch();
    }

    newAccountNode* checkIfAccountPresent(const string& usernm, const string& paswd) {
        if (head == nullptr) {
            cout << "\t\t\t\tAccount not found in Database, because database is empty." << endl;
            return nullptr;
        }

        newAccountNode* temp = head;

        while (temp != nullptr) {
            if (temp->username == usernm && temp->password == paswd && temp->accountStatus == "Completed") {
                cout << "\t\t\t\tAccount found in Database." << endl;
                return temp;
            }
            temp = temp->next;
        }
        cout << "\t\t\t\tAccount not found in Database." << endl;

        return nullptr;
    }

    bool checkATMCredentials(int pn, long long accNum) {
        if (head == nullptr) {
            return false;
        }

        newAccountNode* temp = head;

        while (temp != nullptr) {
            if (temp->debitCardPin == pn && temp->accountNumber == accNum && temp->accountStatus == "Completed") {
                return true;
            }
            temp = temp->next;
        }

        return false;
    }

    void withDrawCash(const string& usernm, const string& paswd, double amount) {
        newAccountNode* withDrawAcc = checkIfAccountPresent(usernm, paswd);

        if (withDrawAcc == nullptr) {
            cout << "\t\t\t\tAccount not found in database, transaction failed !!!!" << endl;
        } else {
            if (amount <= 0) {
                cout << "\t\t\t\tInvalid amount." << endl;
            } else if (amount > withDrawAcc->cash) {
                cout << "\t\t\t\tAccount does not contain this much cash, transaction failed !!!!" << endl;
                cout << "\t\t\t\tPress any key to return to Bank Menu" << endl;
                _getch();
                return;
            } else {
                withDrawAcc->cash = withDrawAcc->cash - amount;
                cout << "\t\t\t\tTransaction successful!" << endl;
                cout << "\t\t\t\tRemaining Balance -> " << withDrawAcc->cash << endl;
            }
        }
        cout << "\t\t\t\tPress any key to return to Bank Menu" << endl;
        _getch();
    }

    void changeATMpin(const string& usernm, const string& paswd, int oldPin, int newPin) {
        newAccountNode* changePinAcc = checkIfAccountPresent(usernm, paswd);
        if (changePinAcc == nullptr) {
            cout << "\t\t\t\tAccount not found in database, transaction failed !!!!" << endl;
        } else {
            if (newPin < 0 || newPin > 9999 || changePinAcc->debitCardPin != oldPin) {
                cout << "\t\t\t\tNew PIN is not 4 digits or Old PIN is invalid, process failed!!!!" << endl;
            } else {
                changePinAcc->debitCardPin = newPin;
                cout << "\t\t\t\tProcess successful!" << endl;
                cout << "\t\t\t\tPin Updated " << endl;
            }
        }
        cout << "\t\t\t\tPress any key to return to Bank Menu" << endl;
        _getch();
    }

    void balanceEnquiry(const string& usernm, const string& paswd) {
        newAccountNode* balanceEnquiryAcc = checkIfAccountPresent(usernm, paswd);

        if (balanceEnquiryAcc == nullptr) {
            cout << "\t\t\t\tAccount not found in database, process failed !!!!" << endl;
        } else {
            cout << "\t\t\t\tAccount# -> " << balanceEnquiryAcc->accountNumber << endl;
            cout << "\t\t\t\tBalance -> " << balanceEnquiryAcc->cash << endl;
        }
        cout << "\t\t\t\tPress any key to return to Bank Menu" << endl;
        _getch();
    }

    void displayAccountDetails(const string& usernm, const string& paswd) {
        newAccountNode* accountDisplay = checkIfAccountPresent(usernm, paswd);
        if (accountDisplay == nullptr) {
            cout << "\t\t\t\tAccount not found in database, process failed !!!!" << endl;
        } else {
            cout << "\t\t\t\t------------------------------" << endl;
            cout << "\t\t\t\t----------" << endl;
            cout << "\t\t\t\tAccount#: " << accountDisplay->accountNumber << endl;
            cout << "\t\t\t\tAccount Status: " << accountDisplay->accountStatus << endl;
            cout << "\t\t\t\tFirst Name: " << accountDisplay->firstName << endl;
            cout << "\t\t\t\tLast Name: " << accountDisplay->lastName << endl;
            cout << "\t\t\t\tEmail Address: " << accountDisplay->emailAddress << endl;
            cout << "\t\t\t\tCNIC: " << accountDisplay->CNIC << endl;
            cout << "\t\t\t\tPhone#: " << accountDisplay->phoneNumber << endl;
            cout << "\t\t\t\tCash: " << accountDisplay->cash << endl;
            cout << "\t\t\t\t ---Address--- " << endl;
            accountDisplay->homeAddress.displayAddress();
            cout << "\t\t\t\t -------------" << endl;
            cout << "\t\t\t\tUsername: " << accountDisplay->username << endl;
            cout << "\t\t\t\tPassword: " << accountDisplay->password << endl;
            cout << "\t\t\t\tDebit Card: " << accountDisplay->debitCard << endl;
            cout << "\t\t\t\tCheque Book: " << accountDisplay->chequeBook << endl;
            cout << "\t\t\t\tDebit Card PIN: " << accountDisplay->debitCardPin << endl;
            cout << "\t\t\t\t------------------------------" << endl << endl;
        }
        cout << "\t\t\t\tPress any key to return to Bank Menu" << endl;
        _getch();
    }

    void displayAllAccounts() {
        newAccountNode* temp = head;

        if (head == nullptr) {
            cout << "\t\t\t\t Account Database is empty" << endl;
            cout << "\t\t\t\t Press any key to return to Bank Menu" << endl;
            _getch();
            return;
        }

        int count = 1;

        while (temp != nullptr) {
            cout << "\t\t\t\t--------------- #" << count++ << " ---------------" << endl;
            cout << "\t\t\t\t----------" << endl;
            cout << "\t\t\t\tAccount Status: " << temp->accountStatus << endl;
            cout << "\t\t\t\tAccount Number: " << temp->accountNumber << endl;
            cout << "\t\t\t\tFirst Name: " << temp->firstName << endl;
            cout << "\t\t\t\tLast Name: " << temp->lastName << endl;
            cout << "\t\t\t\tEmail Address: " << temp->emailAddress << endl;
            cout << "\t\t\t\tCNIC: " << temp->CNIC << endl;
            cout << "\t\t\t\tPhone#: " << temp->phoneNumber << endl;
            cout << "\t\t\t\t ---Address--- " << endl;
            temp->homeAddress.displayAddress();
            cout << "\t\t\t\t -------------" << endl;
            cout << "\t\t\t\tUsername: " << temp->username << endl;
            cout << "\t\t\t\tPassword: " << temp->password << endl;
            cout << "\t\t\t\tDebit Card: " << temp->debitCard << endl;
            cout << "\t\t\t\tCheque Book: " << temp->chequeBook << endl;
            cout << "\t\t\t\tDebit Card PIN: " << temp->debitCardPin << endl;
            cout << "\t\t\t\t--------------- #" << count << " ---------------" << endl << endl;
            temp = temp->next;
        }
        cout << "\t\t\t\t Press any key to return to Bank Menu" << endl;
        _getch();
    }
};

class admin {
private:
    const string username = "Tabish72";
    const string password = "AdminTabish";
public:
    admin() = default;
    string getUserName() const { return username; }
    string getPassWord() const { return password; }
    bool checkCredentials(const string& userNm, const string& passWd) {
        return (userNm == username && passWd == password);
    }
};

void startScreen(tm* tPtr);
void endScreen(tm* tPtr);
void bankEnterScreen(tm* tPtr, int& opt);
void screenBank(tm* tPtr, int& opt);
void screenATMone(tm* tPtr, long long& userCardNumber, int& userPINnumber);
void screenATMtwo(tm* tPtr, int& opt);
void screenAdminOne(tm* tPtr, string& adminUserName, string& adminPassword);
void screenAdminTwo(tm* tPtr, int& opt);
void screenAdminAccountOpenings(tm* tPtr, int& opt);
void screenAdminBillPayments(tm* tPtr, int& opt);

int main() {
    time_t t = time(nullptr);
    tm* tPtr = localtime(&t);
    int bankEnterOption = 0;
    int optionInBankOne = 0;
    int optionInBankTwo = 0;
    int optionInATMone = 0;
    int optionInATMtwo = 0;
    int optionInAdmin = 0;
    int optionInAdminAccOpen = 0;
    int optionInAdminBillPaymt = 0;
    long long userCardNumber = 0;
    int userCardPIN = 0;
    string accountViewUsnm = "";
    string accountViewPaswd = "";
    string adminUserName;
    string adminPassword;
    int flag = 0;
    admin administrator;
    double withdrawCash = 0.00;
    int oldPinChange = 0;
    int newPinChange = 0;
    bankAccountsDatabase accDatabase;
    billPaymentQueue billPaymentLine;
    withdrawDepositQueue withDwDepstLine;
    string usnmATM = "";
    string pssdATM = "";

    startScreen(tPtr);
    system("cls");

BANKSCREEN:
    bankEnterScreen(tPtr, bankEnterOption);
    system("cls");
    switch (bankEnterOption) {
    case 1:
INSIDEBANK:
        screenBank(tPtr, optionInBankOne);
        system("cls");

        cout << "\n\n\n\t\t\t Date: " << (tPtr->tm_mday) << "/" << (tPtr->tm_mon) + 1 << "/" << (tPtr->tm_year) + 1900 << endl;
        cout << "\t\t\t Time: " << (tPtr->tm_hour) << ":" << (tPtr->tm_min) << endl;

        cout << "\t\t\t ##########################################################################################################################" << endl;
        cout << "\t\t\t #" << "\t\t\t\t\t\t Cybertech's Bank Management Application\t\t\t\t\t\t  #" << endl;
        cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
        cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
        switch (optionInBankOne) {
        case 1:
            billPaymentLine.enqueue();
            system("cls");
            goto INSIDEBANK;
        case 2:
            withDwDepstLine.enqueue();
            system("cls");
            goto INSIDEBANK;
        case 3:
            accDatabase.insertNewAccount();
            system("cls");
            goto INSIDEBANK;
        case 4:
            cout << "\t\t\t Enter Username: ";
            cin >> accountViewUsnm;
            cout << endl;
            cout << "\t\t\t Enter Password: ";
            cin >> accountViewPaswd;
            cout << endl;
            accDatabase.displayAccountDetails(accountViewUsnm, accountViewPaswd);
            system("cls");
            goto INSIDEBANK;
        case 5:
            system("cls");
            goto BANKSCREEN;
        default:
            system("cls");
            cout << "\n\n\n\t\t\t Date: " << (tPtr->tm_mday) << "/" << (tPtr->tm_mon) + 1 << "/" << (tPtr->tm_year) + 1900 << endl;
            cout << "\t\t\t Time: " << (tPtr->tm_hour) << ":" << (tPtr->tm_min) << endl;

            cout << "\t\t\t ##########################################################################################################################" << endl;
            cout << "\t\t\t #" << "\t\t\t\t\t\t Cybertech's Bank Management Application\t\t\t\t\t\t  #" << endl;
            cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
            cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
            cout << "\t\t\t  Wrong Option Entered, press any key to go back to Main Menu " << endl;
            _getch();
            system("cls");
            goto INSIDEBANK;
        }
        break;
    case 2:
MAINATMSCREEN:
        screenATMone(tPtr, userCardNumber, userCardPIN);
        system("cls");

        if (accDatabase.checkATMCredentials(userCardPIN, userCardNumber)) {
ATMSCREEN:
            screenATMtwo(tPtr, optionInATMtwo);
            system("cls");
            cout << "\n\n\n\t\t\t Date: " << (tPtr->tm_mday) << "/" << (tPtr->tm_mon) + 1 << "/" << (tPtr->tm_year) + 1900 << endl;
            cout << "\t\t\t Time: " << (tPtr->tm_hour) << ":" << (tPtr->tm_min) << endl;

            cout << "\t\t\t ##########################################################################################################################" << endl;
            cout << "\t\t\t #" << "\t\t\t\t\t\t Cybertech's Bank Management Application\t\t\t\t\t\t  #" << endl;
            cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
            cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
            switch (optionInATMtwo) {
            case 1:
                cout << "\t\t\t # Enter amount you wish to withdraw -> ";
                cin >> withdrawCash;
                cout << "\t\t\t # Enter your username -> ";
                cin >> usnmATM;
                cout << "\t\t\t # Enter your password -> ";
                cin >> pssdATM;
                accDatabase.withDrawCash(usnmATM, pssdATM, withdrawCash);
                system("cls");
                goto ATMSCREEN;
            case 2:
                cout << "\t\t\t # Enter your username -> ";
                cin >> usnmATM;
                cout << "\t\t\t # Enter your password -> ";
                cin >> pssdATM;
                accDatabase.balanceEnquiry(usnmATM, pssdATM);
                system("cls");
                goto ATMSCREEN;
            case 3:
                cout << "\t\t\t # Enter your username -> ";
                cin >> usnmATM;
                cout << "\t\t\t # Enter your password -> ";
                cin >> pssdATM;
                cout << "\t\t\t # Enter old pin -> ";
                cin >> oldPinChange;
                cout << "\t\t\t # Enter new pin (4 Digits) -> ";
                cin >> newPinChange;
                accDatabase.changeATMpin(usnmATM, pssdATM, oldPinChange, newPinChange);
                system("cls");
                goto ATMSCREEN;
            case 4:
                system("cls");
                goto BANKSCREEN;
            default:
                system("cls");
                cout << "\n\n\n\t\t\t Date: " << (tPtr->tm_mday) << "/" << (tPtr->tm_mon) + 1 << "/" << (tPtr->tm_year) + 1900 << endl;
                cout << "\t\t\t Time: " << (tPtr->tm_hour) << ":" << (tPtr->tm_min) << endl;

                cout << "\t\t\t ##########################################################################################################################" << endl;
                cout << "\t\t\t #" << "\t\t\t\t\t\t Cybertech's Bank Management Application\t\t\t\t\t\t  #" << endl;
                cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
                cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
                cout << "\t\t\t  Wrong Option Entered, press any key to go back to Main Menu " << endl;
                _getch();
                system("cls");
                goto ATMSCREEN;
            }
        } else {
            cout << "\n\n\n\t\t\t Date: " << (tPtr->tm_mday) << "/" << (tPtr->tm_mon) + 1 << "/" << (tPtr->tm_year) + 1900 << endl;
            cout << "\t\t\t Time: " << (tPtr->tm_hour) << ":" << (tPtr->tm_min) << endl;

            cout << "\t\t\t ##########################################################################################################################" << endl;
            cout << "\t\t\t #" << "\t\t\t\t\t\t Cybertech's Bank Management Application\t\t\t\t\t\t  #" << endl;
            cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
            cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
            cout << "\t\t\t # Invalid Credentials Added" << endl;
            cout << "\t\t\t Press any key to return to Bank Menu" << endl;
            _getch();
            system("cls");
            goto BANKSCREEN;
        }
        break;
    case 3:
        screenAdminOne(tPtr, adminUserName, adminPassword);
        system("cls");
        if (administrator.checkCredentials(adminUserName, adminPassword)) {
ADMINSCREEN:
            screenAdminTwo(tPtr, optionInAdmin);
            system("cls");

            switch (optionInAdmin) {
            case 1:
ACCOPPSCREN:
                screenAdminAccountOpenings(tPtr, optionInAdminAccOpen);
                system("cls");
                cout << "\n\n\n\t\t\t Date: " << (tPtr->tm_mday) << "/" << (tPtr->tm_mon) + 1 << "/" << (tPtr->tm_year) + 1900 << endl;
                cout << "\t\t\t Time: " << (tPtr->tm_hour) << ":" << (tPtr->tm_min) << endl;

                cout << "\t\t\t ##########################################################################################################################" << endl;
                cout << "\t\t\t #" << "\t\t\t\t\t\t Cybertech's Bank Management Application\t\t\t\t\t\t  #" << endl;
                cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
                cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
                switch (optionInAdminAccOpen) {
                case 1:
                    accDatabase.viewAccountsToBeProcessed();
                    system("cls");
                    goto ACCOPPSCREN;
                case 2:
                    accDatabase.processAccounts();
                    system("cls");
                    goto ACCOPPSCREN;
                case 3:
                    accDatabase.displayAllAccounts();
                    system("cls");
                    goto ACCOPPSCREN;
                case 4:
                    system("cls");
                    goto ADMINSCREEN;
                default:
                    system("cls");
                    cout << "\n\n\n\t\t\t Date: " << (tPtr->tm_mday) << "/" << (tPtr->tm_mon) + 1 << "/" << (tPtr->tm_year) + 1900 << endl;
                    cout << "\t\t\t Time: " << (tPtr->tm_hour) << ":" << (tPtr->tm_min) << endl;

                    cout << "\t\t\t ##########################################################################################################################" << endl;
                    cout << "\t\t\t #" << "\t\t\t\t\t\t Cybertech's Bank Management Application\t\t\t\t\t\t  #" << endl;
                    cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
                    cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
                    cout << "\t\t\t  Wrong Option Entered, press any key to go back to Main Menu " << endl;
                    _getch();
                    system("cls");
                    goto ACCOPPSCREN;
                }
            case 2:
BILLPAYSCREEN:
                screenAdminBillPayments(tPtr, optionInAdminBillPaymt);
                system("cls");
                cout << "\n\n\n\t\t\t Date: " << (tPtr->tm_mday) << "/" << (tPtr->tm_mon) + 1 << "/" << (tPtr->tm_year) + 1900 << endl;
                cout << "\t\t\t Time: " << (tPtr->tm_hour) << ":" << (tPtr->tm_min) << endl;

                cout << "\t\t\t ##########################################################################################################################" << endl;
                cout << "\t\t\t #" << "\t\t\t\t\t\t Cybertech's Bank Management Application\t\t\t\t\t\t  #" << endl;
                cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
                cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
                switch (optionInAdminBillPaymt) {
                case 1:
                    billPaymentLine.displayBillPaymentQueue();
                    system("cls");
                    goto BILLPAYSCREEN;
                case 2:
                    billPaymentLine.displayFront();
                    system("cls");
                    goto BILLPAYSCREEN;
                case 3:
                    billPaymentLine.dequeue();
                    system("cls");
                    goto BILLPAYSCREEN;
                case 4:
                    system("cls");
                    goto ADMINSCREEN;
                default:
                    system("cls");
                    cout << "\n\n\n\t\t\t Date: " << (tPtr->tm_mday) << "/" << (tPtr->tm_mon) + 1 << "/" << (tPtr->tm_year) + 1900 << endl;
                    cout << "\t\t\t Time: " << (tPtr->tm_hour) << ":" << (tPtr->tm_min) << endl;

                    cout << "\t\t\t ##########################################################################################################################" << endl;
                    cout << "\t\t\t #" << "\t\t\t\t\t\t Cybertech's Bank Management Application\t\t\t\t\t\t  #" << endl;
                    cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
                    cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
                    cout << "\t\t\t  Wrong Option Entered, press any key to go back to Main Menu " << endl;
                    _getch();
                    system("cls");
                    goto BILLPAYSCREEN;
                }
                break;
            case 3:
                system("cls");
                goto BANKSCREEN;
            default:
                system("cls");
                cout << "\n\n\n\t\t\t Date: " << (tPtr->tm_mday) << "/" << (tPtr->tm_mon) + 1 << "/" << (tPtr->tm_year) + 1900 << endl;
                cout << "\t\t\t Time: " << (tPtr->tm_hour) << ":" << (tPtr->tm_min) << endl;

                cout << "\t\t\t ##########################################################################################################################" << endl;
                cout << "\t\t\t #" << "\t\t\t\t\t\t Cybertech's Bank Management Application\t\t\t\t\t\t  #" << endl;
                cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
                cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
                cout << "\t\t\t  Wrong Option Entered, press any key to go back to Main Menu " << endl;
                _getch();
                system("cls");
                goto ADMINSCREEN;
            }
        } else {
            cout << "\n\n\n\t\t\t Date: " << (tPtr->tm_mday) << "/" << (tPtr->tm_mon) + 1 << "/" << (tPtr->tm_year) + 1900 << endl;
            cout << "\t\t\t Time: " << (tPtr->tm_hour) << ":" << (tPtr->tm_min) << endl;

            cout << "\t\t\t ##########################################################################################################################" << endl;
            cout << "\t\t\t #" << "\t\t\t\t\t\t Cybertech's Bank Management Application\t\t\t\t\t\t  #" << endl;
            cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
            cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
            cout << "\t\t\t # Invalid Credentials Added" << endl;
            cout << "\t\t\t Press any key to return to Bank Menu" << endl;
            _getch();
            system("cls");
            goto BANKSCREEN;
        }
        break;
    case 4:
        system("cls");
        endScreen(tPtr);
        break;
    default:
        system("cls");
        cout << "\n\n\n\t\t\t Date: " << (tPtr->tm_mday) << "/" << (tPtr->tm_mon) + 1 << "/" << (tPtr->tm_year) + 1900 << endl;
        cout << "\t\t\t Time: " << (tPtr->tm_hour) << ":" << (tPtr->tm_min) << endl;

        cout << "\t\t\t ##########################################################################################################################" << endl;
        cout << "\t\t\t #" << "\t\t\t\t\t\t Cybertech's Bank Management Application\t\t\t\t\t\t  #" << endl;
        cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
        cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
        cout << "\t\t\t  Wrong Option Entered, press any key to go back to Main Menu " << endl;
        _getch();
        system("cls");
        goto BANKSCREEN;
    }

    cout << "\t\t\t ";
    system("pause");
    return 0;
}

void startScreen(tm* tPtr) {
    cout << "\n\n\n\t\t\t Date: " << (tPtr->tm_mday) << "/" << (tPtr->tm_mon) + 1 << "/" << (tPtr->tm_year) + 1900 << endl;
    cout << "\t\t\t Time: " << (tPtr->tm_hour) << ":" << (tPtr->tm_min) << endl;

    cout << "\t\t\t ##########################################################################################################################" << endl;
    cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
    cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
    cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
    cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
    cout << "\t\t\t #" << "\t\t\t\t\t\t\tWelcome\t\t\t\t\t\t\t\t  #" << endl;
    cout << "\t\t\t #" << "\t\t\t\t\t\t\t  to\t\t\t\t\t\t\t\t  #" << endl;
    cout << "\t\t\t #" << "\t\t\t\t\t\t Cybertech's Bank Management Application\t\t\t\t\t\t  #" << endl;
    cout << "\t\t\t ##########################################################################################################################" << endl;
    cout << "\t\t\t ";
    system("pause");
}

void endScreen(tm* tPtr) {
    cout << "\n\n\n\t\t\t Date: " << (tPtr->tm_mday) << "/" << (tPtr->tm_mon) + 1 << "/" << (tPtr->tm_year) + 1900 << endl;
    cout << "\t\t\t Time: " << (tPtr->tm_hour) << ":" << (tPtr->tm_min) << endl;

    cout << "\t\t\t ##########################################################################################################################" << endl;
    cout << "\t\t\t #" << "\t\t\t\t\t\t\tThank you\t\t\t\t\t\t\t  #" << endl;
    cout << "\t\t\t #" << "\t\t\t\t\t\t\tfor using\t\t\t\t\t\t\t  #" << endl;
    cout << "\t\t\t #" << "\t\t\t\t\t\t Cybertech's Bank Management Application\t\t\t\t\t\t  #" << endl;
    cout << "\t\t\t ##########################################################################################################################" << endl;
}

void bankEnterScreen(tm* tPtr, int& opt) {
    cout << "\n\n\n\t\t\t Date: " << (tPtr->tm_mday) << "/" << (tPtr->tm_mon) + 1 << "/" << (tPtr->tm_year) + 1900 << endl;
    cout << "\t\t\t Time: " << (tPtr->tm_hour) << ":" << (tPtr->tm_min) << endl;

    cout << "\t\t\t ##########################################################################################################################" << endl;
    cout << "\t\t\t #" << "\t\t\t\t\t\t Cybertech's Bank Management Application\t\t\t\t\t\t  #" << endl;
    cout << "\t\t\t #" << "\t\t\t\t\t\t   Choose an option:\t\t\t\t\t\t          #" << endl;
    cout << "\t\t\t #" << "\t\t\t\t\t\t    1) Enter Bank\t\t\t\t\t\t\t  #" << endl;
    cout << "\t\t\t #" << "\t\t\t\t\t\t    2) Enter ATM\t\t\t\t\t\t\t  #" << endl;
    cout << "\t\t\t #" << "\t\t\t\t\t\t    3) Admin Login\t\t\t\t\t\t\t  #" << endl;
    cout << "\t\t\t #" << "\t\t\t\t\t\t    4) Exit\t\t\t\t\t\t\t\t  #" << endl;
    cout << "\t\t\t ##########################################################################################################################" << endl;
    cout << "\t\t\t Enter Option: ";
    cin >> opt;
    cout << endl;
}

void screenBank(tm* tPtr, int& opt) {
    cout << "\n\n\n\t\t\t Date: " << (tPtr->tm_mday) << "/" << (tPtr->tm_mon) + 1 << "/" << (tPtr->tm_year) + 1900 << endl;
    cout << "\t\t\t Time: " << (tPtr->tm_hour) << ":" << (tPtr->tm_min) << endl;

    cout << "\t\t\t ##########################################################################################################################" << endl;
    cout << "\t\t\t #" << "\t\t\t\t\t\t Cybertech's Bank Management Application\t\t\t\t\t\t  #" << endl;
    cout << "\t\t\t #" << "\t\t\t\t\t\t     Welcome to Bank\t\t\t\t\t\t\t  #" << endl;
    cout << "\t\t\t #" << "\t\t\t\t\t\t   Choose an option:\t\t\t\t\t\t          #" << endl;
    cout << "\t\t\t #" << "\t\t\t\t\t\t    1) Pay Bills\t\t\t\t\t\t\t  #" << endl;
    cout << "\t\t\t #" << "\t\t\t\t\t\t    2) Deposits/Cheques\t\t\t\t\t\t          #" << endl;
    cout << "\t\t\t #" << "\t\t\t\t\t\t    3) Open up Account\t\t\t\t\t\t\t  #" << endl;
    cout << "\t\t\t #" << "\t\t\t\t\t\t    4) View your Account\t\t\t\t\t\t  #" << endl;
    cout << "\t\t\t #" << "\t\t\t\t\t\t    5) Exit\t\t\t\t\t\t\t\t  #" << endl;
    cout << "\t\t\t ##########################################################################################################################" << endl;
    cout << "\t\t\t Enter Option: ";
    cin >> opt;
    cout << endl;
}

void screenATMone(tm* tPtr, long long& userCardNumber, int& userPINnumber) {
    cout << "\n\n\n\t\t\t Date: " << (tPtr->tm_mday) << "/" << (tPtr->tm_mon) + 1 << "/" << (tPtr->tm_year) + 1900 << endl;
    cout << "\t\t\t Time: " << (tPtr->tm_hour) << ":" << (tPtr->tm_min) << endl;

    cout << "\t\t\t ##########################################################################################################################" << endl;
    cout << "\t\t\t #" << "\t\t\t\t\t\t Cybertech's Bank Management Application\t\t\t\t\t\t  #" << endl;
    cout << "\t\t\t #" << "\t\t\t\t\t\t     Welcome to ATM\t\t\t\t\t\t\t  #" << endl;
    cout << "\t\t\t #" << "\t\t\t\t\t\tEnter Following Details:\t\t\t\t\t          #" << endl;
    cout << "\t\t\t #" << "\t\t\t\t\t\t    1) Account Number\t\t\t\t\t\t\t  #" << endl;
    cout << "\t\t\t #" << "\t\t\t\t\t\t    2) Debit Card PIN\t\t\t\t\t\t          #" << endl;
    cout << "\t\t\t ##########################################################################################################################" << endl;
    cout << "\t\t\t Enter Account Number: ";
    cin >> userCardNumber;
    cout << endl;
    cout << "\t\t\t Enter Debit Card PIN: ";
    cin >> userPINnumber;
    cout << endl;
}

void screenATMtwo(tm* tPtr, int& opt) {
    cout << "\n\n\n\t\t\t Date: " << (tPtr->tm_mday) << "/" << (tPtr->tm_mon) + 1 << "/" << (tPtr->tm_year) + 1900 << endl;
    cout << "\t\t\t Time: " << (tPtr->tm_hour) << ":" << (tPtr->tm_min) << endl;

    cout << "\t\t\t ##########################################################################################################################" << endl;
    cout << "\t\t\t #" << "\t\t\t\t\t\t Cybertech's Bank Management Application\t\t\t\t\t\t  #" << endl;
    cout << "\t\t\t #" << "\t\t\t\t\t\t     Welcome to ATM\t\t\t\t\t\t\t  #" << endl;
    cout << "\t\t\t #" << "\t\t\t\t\t\t   Choose an option:\t\t\t\t\t\t          #" << endl;
    cout << "\t\t\t #" << "\t\t\t\t\t\t    1) Withdraw Cash\t\t\t\t\t\t\t  #" << endl;
    cout << "\t\t\t #" << "\t\t\t\t\t\t    2) Balance Inquiry\t\t\t\t\t\t          #" << endl;
    cout << "\t\t\t #" << "\t\t\t\t\t\t    3) Change Pin\t\t\t\t\t\t\t  #" << endl;
    cout << "\t\t\t #" << "\t\t\t\t\t\t    4) Exit\t\t\t\t\t\t\t\t  #" << endl;
    cout << "\t\t\t ##########################################################################################################################" << endl;
    cout << "\t\t\t Enter Option: ";
    cin >> opt;
    cout << endl;
}

void screenAdminOne(tm* tPtr, string& adminUserName, string& adminPassword) {
    cout << "\n\n\n\t\t\t Date: " << (tPtr->tm_mday) << "/" << (tPtr->tm_mon) + 1 << "/" << (tPtr->tm_year) + 1900 << endl;
    cout << "\t\t\t Time: " << (tPtr->tm_hour) << ":" << (tPtr->tm_min) << endl;

    cout << "\t\t\t ##########################################################################################################################" << endl;
    cout << "\t\t\t #" << "\t\t\t\t\t\t Cybertech's Bank Management Application\t\t\t\t\t\t  #" << endl;
    cout << "\t\t\t #" << "\t\t\t\t\t\t     Welcome to Admin\t\t\t\t\t\t\t  #" << endl;
    cout << "\t\t\t #" << "\t\t\t\t\t\tEnter Following Details:\t\t\t\t\t          #" << endl;
    cout << "\t\t\t #" << "\t\t\t\t\t\t    1) Username\t\t\t\t\t\t\t\t  #" << endl;
    cout << "\t\t\t #" << "\t\t\t\t\t\t    2) Password\t\t\t\t\t\t\t          #" << endl;
    cout << "\t\t\t ##########################################################################################################################" << endl;
    cout << "\t\t\t Enter Username: ";
    cin >> adminUserName;
    cout << endl;
    cout << "\t\t\t Enter Password: ";
    cin >> adminPassword;
    cout << endl;
}

void screenAdminTwo(tm* tPtr, int& opt) {
    cout << "\n\n\n\t\t\t Date: " << (tPtr->tm_mday) << "/" << (tPtr->tm_mon) + 1 << "/" << (tPtr->tm_year) + 1900 << endl;
    cout << "\t\t\t Time: " << (tPtr->tm_hour) << ":" << (tPtr->tm_min) << endl;

    cout << "\t\t\t ##########################################################################################################################" << endl;
    cout << "\t\t\t #" << "\t\t\t\t\t\t Cybertech's Bank Management Application\t\t\t\t\t\t  #" << endl;
    cout << "\t\t\t #" << "\t\t\t\t\t\t     Welcome to Admin\t\t\t\t\t\t\t  #" << endl;
    cout << "\t\t\t #" << "\t\t\t\t\t\t   Choose an option:\t\t\t\t\t\t          #" << endl;
    cout << "\t\t\t #" << "\t\t\t\t\t\t    1) Process Account Openings\t\t\t\t\t\t  #" << endl;
    cout << "\t\t\t #" << "\t\t\t\t\t\t    2) Process Bill Payments\t\t\t\t\t          #" << endl;
    cout << "\t\t\t #" <
