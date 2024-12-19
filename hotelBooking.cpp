#include<iostream>
#include<bits/stdc++.h>
#include<fstream>
#include<string>
#include<sstream>
#include<cmath>
#include<windows.h>
#include<unistd.h>
using namespace std;

class Room{   //room info
    public:
    static int stan, del, suite;
};

//initialize number of rooms
int Room::stan=350;
int Room::del=200;
int Room::suite=500;

class Customer{  //check-in
    int guests;   //no. of customer
    char name[60];
    char address[20];
    char mail[60];
    int days;
    string mobile;
    int age;
    string aadhaar;
    float bill;
    int ID;
    public:
        int rooms;
        string roomtype;

    void Take(int g, int room, string type, int d){
        guests = g;
        rooms = room;
        roomtype = type;
        days = d;
        cout << endl << endl << "Enter First Name: ";
        cin >> name;
        cout << "Enter age: ";
        cin >> age;
        cout << "Enter Mobile No.: ";
        cin >> mobile;
        cout << "Enter Email ID: ";
        cin >> mail;
        cout << "Enter Aadhaar No.: ";
        cin >> aadhaar;
        cout << "Enter Residential City: ";
        cin>>address;
        cout << endl<<endl<<"!!!!!!!     CHECKED IN SUCCESSFULLY     !!!!!!!";
        string con;
        cout << endl << endl << "\n\n\n ENTER Y TO CONFIRM: ";
        cin >> con;

    }
    void SummaryFile() {
        ofstream Summary("Summary.txt", ios::app);
        Summary << "Name: " << name << endl;
        Summary << "Mobile No.: " << mobile << endl;
        Summary << "Email Address: " << mail << endl;
        Summary << "Aadhaar No.: " << aadhaar << endl;
        Summary << "Address: " << address << endl;
        Summary << "No. of Guests: " << guests << endl;
        Summary << "Room Type: " << roomtype << endl;
        Summary << "No. of Rooms: " << rooms << endl;
        Summary << "Duration Of Stay: " << days << endl;
        Summary.close();
    }
    void CalculateBill(int d, int room, string type){
        int price;
        if(type=="STD"){
            price = 75000;
        }
        else if(type=="DEL"){
            price = 200000;
        }
        else if(type=="SUITE"){
            price = 500000;
        }
        bill = d*room*price*1.2;
        ofstream Bill("Summary.txt", ios::app);
        Bill << "Bill: " << bill << endl << endl;
        Bill.close();
    }

};

class Summary : public Room, public Customer{   //stay summary
public:
    void DisplaySummary(){
        char mail[60];
        cout << endl << "ENTER EMAIL ADDRESS TO FIND GUEST: ";
        cin >> mail;
        string filename = "Summary.txt";
        string word_to_find = mail;
        string line;
        bool found_word = false;

        ifstream myfile(filename);
        if (myfile.is_open()) {
                while (getline(myfile, line)) {
                    if (line.find(word_to_find) != string::npos) {
                    found_word = true;
                }
                if (found_word && line.empty()) {
                    break;
                }
                if (found_word) {
                    cout << line << endl;
                }
                }
                myfile.close();
        }else {
            cout << "!!!  GUEST ENTRY NOT FOUND  !!!" << endl;
        }

        char y;
        cout << endl<< "Enter Y to Continue: ";
        cin >> y;
        int Require();
        Require();

    }
};

void CheckIn(int n, Room *r){     //use OOPS
    int room, tot_rooms, days;
    string type;
    if(r->stan>0||r->del>0||r->suite>0){
        void Rooms();
        Rooms();
        cout << "\nSELECT TYPE OF ROOM TO BOOK: ";
        cin >> room;
        system("cls");
        if(room==1){
                type = "STD";
            cout << endl << "STANDARD ROOM" << endl;
            if(n%2==0){
                cout << endl << "No. of rooms to book: " << ceil(n/2) << endl;
                tot_rooms=ceil(n/2);
                r->stan-=tot_rooms;
            }
            else{
                cout << endl << "No. of rooms to book: " << ceil(n/2)+1 << endl;
                tot_rooms=ceil(n/2)+1;
                r->stan-=tot_rooms;
            }
        }
        else if(room==2){
                type = "DEL";
            cout << endl << "DELUXE ROOMS" << endl;
            if(n%2==0){
                cout << endl << "No. of rooms to book: " << ceil(n/4) << endl;
                tot_rooms=ceil(n/4);
                r->del-=tot_rooms;
            }
            else{
                cout << endl << "No. of rooms to book: " << ceil(n/4)+1 << endl;
                tot_rooms=ceil(n/4)+1;
                r->del-=tot_rooms;
            }
        }
        else if(room==3){
                type = "SUITE";
            cout << endl << "SUITES" << endl;
            if(n%2==0){
                cout << endl << "No. of rooms you can book: \n 2 OCCUPANCY ROOMS: " << ceil(n/2) << "\n OR\n 4 OCCUPANCY ROOMS: " << ceil(n/4) << endl;
            }
            else{
                cout << endl << "No. of rooms you can book: \n 2 OCCUPANCY ROOMS: " << ceil(n/2)+1 << "\n OR\n 4 OCCUPANCY ROOMS: " << ceil(n/4)+1 << endl;
            }
            int ch;
            cout << "Enter occupancy per room:\n\t1. 2 OCCUPANTS\n\t2. 4 OCCUPANTS\nEnter choice: ";
            cin >> ch;
            if(ch==1 && n%2==0){
                tot_rooms=ceil(n/2);
                r->suite-=tot_rooms;
            }
            else if(ch==2 && n%2==0){
                tot_rooms=ceil(n/4);
                r->suite-=tot_rooms;
            }
            else if(ch==1 && n%2!=0){
                tot_rooms=ceil(n/2)+1;
                r->suite-=tot_rooms;
            }
            else if(ch==2 && n%2!=0){
                tot_rooms=ceil(n/4)+1;
                r->suite-=tot_rooms;
            }

        }
        else{
            cout << "Invalid choice entered.\nEnter choice again.";
            CheckIn(n,r);
        }

        cout << endl << "PLANNED DURATION OF STAY (in days) : ";
        cin >> days;

        //take customer info
        Customer c;
        c.Take(n, tot_rooms, type, days);
        c.SummaryFile();
        c.CalculateBill(days, tot_rooms, type);

        int Require();
        Require();

    }
}
void CheckOutSumm(){
    char mail[60];
    cout << endl << "ENTER EMAIL ADDRESS TO FIND GUEST: ";
    cin >> mail;
    string filename = "Summary.txt";
    string word_to_find = mail;
    string line;
    bool found_word = false;
    ifstream myfile(filename);
    if (myfile.is_open()) {
            while (getline(myfile, line)) {
                    if (line.find(word_to_find) != string::npos) {
                        found_word = true;
                    }
                    if (found_word && line.empty()) {
                        break;
                    }
                    if (found_word) {
                        cout << line << endl;
                    }
            }
            cout << endl<<endl<<"!!!!!!!     CHECKED OUT SUCCESSFULLY     !!!!!!!" << endl << endl;
            myfile.close();
    }
    else{
        cout << endl << "!!!! GUEST NOT FOUND !!!!" << endl;
    }

    string inputFileName = "Summary.txt";
    string outputFileName = "PastGuests.txt";
    string searchWord = mail;

    ifstream inputFile(inputFileName);
    ofstream outputFile(outputFileName);
    string lines, paragraph;
    while (getline(inputFile, lines)) {
        if (lines.find(searchWord) != string::npos) {
            paragraph += line + "\n";
            while (getline(inputFile, lines)) {
                    if (lines.empty()) {
                    outputFile << paragraph << endl;
                    paragraph.clear();
                    break;
                    }
                    paragraph += lines + "\n";
            }
        }else{
            outputFile << lines << endl;
        }
    }
    inputFile.close();
    outputFile.close();

    remove(inputFileName.c_str());

    char y;
    cout << endl << "Enter Y to Continue: ";
    cin >> y;
}

void CheckOut(){
    Room r;
    Customer c;
    Summary b;
    CheckOutSumm();
    if(c.roomtype=="STD"){
        r.stan+=c.rooms;
    }
    else if(c.roomtype=="DEL"){
        r.del+=c.rooms;
    }
    else if(c.roomtype=="SUITE"){
        r.suite+=c.rooms;
    }
    int y;
    //cout << endl << endl << "Enter a number to continue: ";
    //cin >> y;
    int Require();
    Require();
}

void ShowSummary(){
    Summary s;
    cout << endl << "                         *  *  *  *  *  *  *                        " << endl;
    cout << "================        SUMMARY OF YOUR STAY        ================" << endl;
    cout << "||                                                                ||" << endl;
    cout << "||                      THE   OPULENT   OASIS                     ||" << endl;
    cout << "||                                                                ||" << endl;
    cout << "================           7 - STAR HOTEL           ================" << endl;
    cout << "                         *  *  *  *  *  *  *                        " << endl << endl;
    s.DisplaySummary();
}

void START(){
    cout << endl << "                         *  *  *  *  *  *  *                        " << endl;
    cout << "================             WELCOME TO             ================" << endl;
    cout << "||                                                                ||" << endl;
    cout << "||                      THE   OPULENT   OASIS                     ||" << endl;
    cout << "||                                                                ||" << endl;
    cout << "================           7 - STAR HOTEL           ================" << endl;
    cout << "                         *  *  *  *  *  *  *                        " << endl << endl;

    int num;
    cout << "\n\n\n\n\nENTER ANY NUMBER TO CONTINUE: ";
    cin >> num;
    int Require();
    Require();
}

void Contact(){
    cout <<  endl << endl << "=================       CONTACT DETAILS      =================" << endl;
    cout << "                                                           "<<endl;
    cout << "      Name: The Opulent Oasis                              " << endl;
    cout << "      Address: The Opulent Oasis, 1 MG Road, Bangalore     " << endl;
    cout << "      Contact No.: 0120-2400975                            " << endl;
    cout << "      Email : enquire@opulentoasis.in                      " << endl << endl << endl;
}

void Rooms(){
    cout << endl << endl <<"=========================== ROOMS AT THE OPULENT OASIS ===========================" << endl<< endl;
    string roomtype[]={"Standard", "Deluxe\t", "Suite\t"};
    string occupancy[]={"2","4","2 or 4"};
    static int total[]={350, 200, 500};
    string price[]={"Rs. 75,000", "Rs. 2,00,000", "Rs. 5,00,000"};

    cout << "S.No.\tROOM\t\tOCCUPANCY\tTOTAL ROOMS\tPRICE (per night)"<<endl;
    cout << endl;
    for(int i=0;i<3;i++){
        cout << i+1<<".\t"<<roomtype[i]<<"\t"<<occupancy[i]<<"\t\t"<<total[i]<<"\t\t"<<price[i]<<endl;
    }
}

void Facilities(){
    cout << endl << endl <<"============ FACILITIES AT THE HOTEL ===========" << endl<< endl;
    cout << " 1. Room Service" << endl;
    cout << "\t a. Cleaning" << endl;
    cout << "\t b. Luggage Carrier" << endl;
    cout << "\t c. Laundry" << endl;
    cout << "\t d. Dry Cleaning" << endl;
    cout << " 2. Gym" << endl;
    cout << " 3. Restaurant" << endl;
    cout << " 4. Movie Theatre" << endl;
    cout << " 5. Gaming Arcade" << endl;
    cout << " 6. Daycare" << endl;
    cout << " 7. Salon & Spa" << endl;
}

void Info(){
    cout << endl << endl <<  "============= = = ==== = ==== = = =============" << endl;
    cout << "||                                           ||" << endl;
    cout << "||             HOTEL INFORMATION             ||" << endl;
    cout << "||                                           ||" << endl;
    cout << "============= = = ==== = ==== = = =============" << endl << endl << endl;
    cout << " 1. Contact Details" << endl;
    cout << " 2. Rooms at the Hotel" << endl;
    cout << " 3. Facilities at the Hotel" << endl;
    cout << " 4. Back to Main Menu " << endl << endl;
    int ch;
    cout << "Enter choice: ";
    cin >> ch;
    system("cls");
    if(ch==1){
        Contact();
        Info();
    }
    else if(ch==2){
        Rooms();
        Info();
    }
    else if(ch==3){
        Facilities();
        Info();
    }
    else if(ch==4){
        int Require();
        Require();
    }
    else{
        cout << "Invalid choice." << endl;
        Info();
    }

}

void exit_menu(){
    cout << endl;
    cout << "================         PLEASE COME BACK TO        ================" << endl;
    cout << "||                                                                ||" << endl;
    cout << "||                      THE   OPULENT   OASIS                     ||" << endl;
    cout << "||                                                                ||" << endl;
    cout << "================           7 - STAR HOTEL           ================" << endl;
    cout << "                         *  *  *  *  *  *  *                        " << endl << endl;
    cout << "            THANK YOU FOR YOUR STAY AT THE OPULENT OASIS!" << endl;
    cout << "          WE HOPE OUR SERVICES WERE UP TO YOUR EXPECTATIONS!" << endl;
    cout << "                                GOODBYE!                              " << endl;
}

int Require(){
    int n;
    cout << endl << endl << endl;
    system("cls");
    cout << "++++++++++++ + + ++++ ++ ++++ + + ++++++++++++" << endl;
    cout << "+                                            +" << endl;
    cout << "+                 MAIN   MENU                +" << endl;
    cout << "+                                            +" << endl;
    cout << "++++++++++++ + + ++++ ++ ++++ + + ++++++++++++" << endl;
    cout << endl << endl << "CHOOSE FUNCTION:" << endl << endl;
    cout << " 1.  Hotel Information \n 2.  Check In \n 3.  Summary \n 4.  Check-Out \n 5.  Exit Main Menu" << endl;
    cout << endl << "Enter choice: ";
    cin >> n;

    while(1){
        system("cls");
        if(n==1){
            Info();
        }
        else if(n==2){
            int n;
            cout << endl <<  "============= = = ==== = ==== = = =============" << endl;
            cout << "||                                           ||" << endl;
            cout << "||              CHECK-IN PORTAL              ||" << endl;
            cout << "||                                           ||" << endl;
            cout << "============= = = ==== = ==== = = =============" << endl << endl << endl;
            cout << endl << endl << "Enter number of guests: ";
            cin >> n;
            Room r;
            CheckIn(n, &r);
        }
        else if(n==3){
            ShowSummary();
        }
        else if(n==4){
            CheckOut();
        }
        else if(n==5){
            exit_menu();
            exit(1);
            break;
        }
        else{
            cout << "Invalid choice entered.";
            Require();
        }
    }
}

int main(){

    START();

    return 0;
}
