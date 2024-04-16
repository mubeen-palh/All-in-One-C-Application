#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class Node
{
public:
    int money;
    string email;
    string name;
    int userid;
    string password;
    Node *next;

    Node(int m, string e, string n, int u, string p)
    {
        email = e;
        name = n;
        userid = u;
        password = p;
        money = m;
        next = NULL;
    }
};

class LinkedList
{
    Node *head;

public:
    LinkedList()
    {
        head = NULL;
    }

    void display()
    {
        if (head == NULL)
        {
            cout << "List is Empty" << endl;
            return;
        }
        Node *temp = head;

        while (temp != NULL)
        {
            cout << " | " << temp->userid << " " << temp->name;
            temp = temp->next;
        }
    }

    void insert(int m, string e, string n, int u, string p)
    {
        Node *newnode = new Node(m, e, n, u, p);

        if (head == NULL)
        {
            head = newnode;
            return;
        }

        Node *temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }

    void prepend(int m, string e, string n, int u, string p)
    {
        Node *newnode = new Node(m, e, n, u, p);

        newnode->next = head;
        head = newnode;
    }

    int moneyvalue(int uid)
    {
        Node *temp = head;

        while (temp != NULL)
        {
            if (temp->userid == uid)
            {
                return temp->money;
            }
            temp = temp->next;
        }
        return -1;
    }

    bool finduid(int uid)
    {
        Node *temp = head;
        if (temp == NULL)
        {
            return true;
        }

        while (temp != NULL)
        {
            if (temp->userid == uid)
            {
                return false;
            }
            temp = temp->next;
        }
        return true;
    }

    void deleteacc(int uid)
    {
        Node *temp = head;
        Node *temp2 = temp;

        while (temp != NULL)
        {
            if (temp->userid == uid)
            {
                if (temp == head)
                {
                    head = head->next;
                    delete temp;
                    return;
                }
                temp2->next = temp->next;
                delete temp;
                return;
            }
            else
            {
                temp2 = temp;
                temp = temp->next;
            }
        }
    }

    void moneytransfer(int loguid, int transferuid, int amount)
    {
        Node *temp = head;

        while (temp != NULL)
        {
            if (temp->userid == loguid)
            {
                break;
            }
            temp = temp->next;
        }

        Node *temp2 = head;

        while (temp2 != NULL)
        {
            if (temp2->userid == transferuid)
            {
                break;
            }
            temp2 = temp2->next;
        }
        temp->money = temp->money - amount;
        temp2->money = temp2->money + amount;
        return;
    }

    bool passwordcheck(string pwddel, int uid)
    {
        Node *temp = head;

        while (temp != NULL)
        {
            if (temp->userid == uid && temp->password == pwddel)
            {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    void withdraw(int loguid, int amount)
    {
        Node *temp = head;

        while (temp != NULL)
        {
            if (temp->userid == loguid)
            {
                break;
            }
            temp = temp->next;
        }

        temp->money = temp->money - amount;
    }

    void deposit(int loguid, int amount)
    {
        Node *temp = head;

        while (temp != NULL)
        {
            if (temp->userid == loguid)
            {
                break;
            }
            temp = temp->next;
        }

        temp->money = temp->money + amount;
    }
};

void printfront()
{
    cout << "\t\t\t\tWelcome to Nayapay" << endl;
    cout << "Press 1 to login your account\n";
    cout << "Press 2 to create a new account\n";
    cout << "Press 3 to delete your account\n";
    cout << "Press 4 to view all members of NayaPay\n";
    cout << "Press 5 to exit!\n";
    cout << "Enter your choice: ";
}

void printsecond()
{
    cout << "\n\nDo you wish to continue?\n"
         << endl;
    cout << "Press 1 to continue\n";
    cout << "Press 2 to exit\n";
    cout << "Enter your choice: ";
}

void printthird()
{
    cout << "\nPress 1 to Transfer the money to other account\n";
    cout << "Press 2 to withdraw money\n";
    cout << "Press 3 to deposit money\n";
    cout << "Press 4 to view your balance\n";
    cout << "Press 5 to close this account\n";
    cout << "Press 6 to exit\n";
    cout << "Enter your choice: ";
}

void enterdata(string &name, string &email, int &money, int &uid, string &pwd, LinkedList l)
{
    cout << "Enter your Full Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter your Email Address: ";
    cin.ignore();
    getline(cin, email);
    do
    {
        cout << "Enter your User Id: ";
        cin >> uid;
        if (!l.finduid(uid))
        {
            cout << "Please enter another user id this one is already taken!" << endl;
        }
    } while (!l.finduid(uid));
    cout << "Enter your password: ";
    cin.ignore();
    getline(cin, pwd);
    cout << "Enter Amount of money you want to deposit: ";
    cin >> money;
}


start_nayapay_app(){
	
	
	LinkedList mainlist;
    mainlist.insert(150000, "uzair@gmail.com", "Uzair Gabol", 5, "Uzair123");
    mainlist.insert(50000, "mubeen@gmail.com", "Mubeen Palh", 12, "Mubeen123");
    mainlist.insert(15000, "aziz@gmail.com", "Abdul Aziz", 16, "Aziz123");
    mainlist.insert(20000, "asim@gmail.com", "Asim Nadeem", 7, "Asim123");
    mainlist.insert(55600, "munib@gmail.com", "Munib Rehman", 3, "Munib123");
    string name, email, pwd;
    int money, uid;
    int choice1, choice2;
    do
    {
        system("CLS");
        printfront();
        cin >> choice1;
        if (choice1 == 1)
        {
            int loguid;
            string pwdlog;
            mainlist.display();
            cout << endl;
            do
            {
                cout << "Please Enter your userid: ";
                cin >> loguid;
                if (mainlist.finduid(loguid) == true)
                {
                    cout << "Please Enter a valid user id" << endl;
                }
            } while (mainlist.finduid(loguid));
            do
            {
                cout << "Please Enter the password to confirm: ";
                cin.ignore();
                getline(cin, pwdlog);
                if (mainlist.passwordcheck(pwdlog, loguid) == false)
                {
                    cout << "Invalid Password!!" << endl;
                    int c;
                    cout << "Enter 1 to try again\nEnter 2 to exit\nEnter your choice: ";
                    cin >> c;
                    if (c == 2)
                    {
                        break;
                    }
                }
            } while (mainlist.passwordcheck(pwdlog, loguid) == false);
            if (mainlist.passwordcheck(pwdlog, loguid) == true)
            {
                int choice3;
                int choice4;
                cout << "Login Succesful!!" << endl;
                do
                {
                    printthird();
                    cin >> choice3;
                    if (choice3 == 1)
                    {
                        int transferuid;
                        int transfermoney;
                        int m;
                        mainlist.display();
                        cout << endl;
                        do
                        {
                            cout << "Please Enter your friend userid: ";
                            cin >> transferuid;
                            if (mainlist.finduid(transferuid) == true)
                            {
                                cout << "Please Enter a valid user id" << endl;
                            }
                        } while (mainlist.finduid(transferuid));
                        m = mainlist.moneyvalue(loguid);
                        while (1)
                        {
                            cout << "Enter the amount you want to transfer: ";
                            cin >> transfermoney;
                            if (transfermoney > m)
                            {
                                cout << "Invalid Amount entered or no money in your account" << endl;
                                continue;
                            }
                            break;
                        }
                        mainlist.moneytransfer(loguid, transferuid, transfermoney);
                        cout << "Transferred Successfully!!" << endl;
                    }
                    else if (choice3 == 2)
                    {
                        int m;
                        int withdrawamount;
                        m = mainlist.moneyvalue(loguid);
                        cout << "Amount: " << mainlist.moneyvalue(loguid) << endl;
                        while (1)
                        {
                            cout << "Enter the amount you want to withdraw: ";
                            cin >> withdrawamount;
                            if (withdrawamount > m)
                            {
                                cout << "Invalid Amount entered or no money in your account" << endl;
                                continue;
                            }
                            break;
                        }
                        mainlist.withdraw(loguid, withdrawamount);
                        cout << "Withdraw Succesful!" << endl;
                        cout << "New Amount: " << mainlist.moneyvalue(loguid) << endl;
                    }
                    else if (choice3 == 3)
                    {
                        int depositamount;
                        cout << "Amount: " << mainlist.moneyvalue(loguid) << endl;
                        while (1)
                        {
                            cout << "Enter the amount you want to deposit: ";
                            cin >> depositamount;
                            if (depositamount < 1)
                            {
                                cout << "Invalid Amount entered" << endl;
                                continue;
                            }
                            break;
                        }
                        mainlist.deposit(loguid, depositamount);
                        cout << "Deposit Succesful!" << endl;
                        cout << "New Amount: " << mainlist.moneyvalue(loguid) << endl;
                    }
                    else if (choice3 == 4)
                    {
                        cout << "\n";
                        cout << mainlist.moneyvalue(loguid);
                    }
                    else if (choice3 == 5)
                    {
                        mainlist.deleteacc(loguid);
                        cout << "Account Deleted Successfully!!" << endl;
                        system("PAUSE");
                        break;
                    }
                    else if (choice3 == 6)
                    {
                        break;
                    }
                    else
                    {
                        cout << "Please enter a valid choice!" << endl;
                        continue;
                    }
                    printsecond();
                    cin >> choice4;
                } while (choice4 != 2);
                continue;
            }
        }
        else if (choice1 == 2)
        {
            enterdata(name, email, money, uid, pwd, mainlist);
            mainlist.insert(money, email, name, uid, pwd);
            cout << "Account Created Successfully!!!" << endl;
        }
        else if (choice1 == 3)
        {
            int deluserid;
            string pwddel;
            mainlist.display();
            cout << endl;
            do
            {
                cout << "Please Enter your userid you wish to delete: ";
                cin >> deluserid;
                if (mainlist.finduid(deluserid) == true)
                {
                    cout << "Please Enter a valid user id" << endl;
                }
            } while (mainlist.finduid(deluserid));
            do
            {
                cout << "Please Enter the password to confirm: ";
                cin.ignore();
                getline(cin, pwddel);
                if (mainlist.passwordcheck(pwddel, deluserid) == false)
                {
                    cout << "Invalid Password!!" << endl;
                    int c;
                    cout << "Enter 1 to try again\nEnter 2 to exit\nEnter your choice: ";
                    cin >> c;
                    if (c == 2)
                    {
                        break;
                    }
                }
            } while (mainlist.passwordcheck(pwddel, deluserid) == false);
            if (mainlist.passwordcheck(pwddel, deluserid) == true)
            {
                mainlist.deleteacc(deluserid);
                cout << "Account Deleted Successfully!!!" << endl;
            }
        }
        else if (choice1 == 4)
        {
            mainlist.display();
        }
        else if (choice1 == 5)
        {
            cout << "Thank you for using Nayapay" << endl;
            return 0;
        }
        else
        {
            cout << "Please enter a valid choice!!!\n";
            continue;
        }
        printsecond();
        cin >> choice2;
    } while (choice2 != 2);
    cout << "Thank you for using Nayapay" << endl;
	
	
}

//int main()
//{
//   
////    return 0;
//}
