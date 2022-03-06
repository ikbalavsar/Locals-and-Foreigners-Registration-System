#include <iostream>
using namespace std;

/*
 * Student Name,Surname : Gülsüm İkbal avşar
 * Student ID : 64180006
 * Department : CoE - EEE
 * Assignment No: 3
 */

class Locals{
protected:
    int TC;
    int age;
    string name;
    string cityOfResidency;
public:
    Locals(int TCC, int agee, string namee, string cityOfResidencyy ){ // constructor
        this->TC= TCC;
        this->age = agee;
        this->name = namee;
        this->cityOfResidency = cityOfResidencyy;
    }
    Locals() {
        TC= 0;
        name = "Unknown";
        age = 0;
        cityOfResidency = "Unknown";
    }

    void read(){
        cout<<"\n";
        cout << "Please enter your TC ID: ";
        cin >> TC;

        cout << "Please enter your age: ";
        cin >> age;

        cout << "Please enter your name: ";
        cin >> name;

        cout << "Please enter city of residence: ";
        cin >> cityOfResidency;
    }

    Locals operator++(int){
        this-> age++;
        return *this;
    }

    void changeResidency(string newResidency){
        cityOfResidency = newResidency;
    }

    string getName() {
        return name;
    }

    void erasee(){
        cout<< "\nDeleting Local...\n"<< endl;
        TC= 0;
        name = "Unknown";
        age = 0;
        cityOfResidency = "Unknown";
    }

    void printClass(){
        cout << "\n***** Information about Locals *****\n";
        cout << "TC: "<< TC << endl;
        cout << "Age: "<< age << endl;
        cout << "Name: "<< name << endl;
        cout << "CityOfResidency: "<< cityOfResidency << endl;
        cout<< "\n";
    }



};


class Foreign : public Locals{
private:
    int numOfYear;
    string countryOfOrigin;
public:
    Foreign(int TC, int age, std::string name, std::string cityOfResidency, int numOfYearr, string countryOfOriginn  ):
    Locals(TC, age, name, cityOfResidency){

        this->numOfYear = numOfYearr;
        this->countryOfOrigin = countryOfOriginn;
    }

    Foreign() {
        numOfYear = 0;
        countryOfOrigin = "Unknown";
    }

    void read(){
        cout << "\n";
        Locals::read();
        cout << "Please enter your number of years spent in Turkey: ";
        cin >> numOfYear;

        cout << "Please enter your country of origin: ";
        cin >> countryOfOrigin;

    }

    Foreign operator++(int){
        this-> age++;
        this-> numOfYear++;
        return *this;
    }


    void printClass(){
        cout << "\n***** Information about Foreigns *****\n";
        Locals::printClass();
        cout << "Number of Years Spent in Turkey: "<< numOfYear << endl;
        cout << "CityOfResidency: "<< countryOfOrigin << endl;
        cout << endl;
    }

    void erasee(){
        cout<< "\nDeleting Foreign...\n"<< endl;
        Locals::erasee();
        numOfYear = 0;
        countryOfOrigin = "Unknown";

    }


};


int main() {

    // Create a list of residents with at least 5 locals and 5 foreigners.
    int rand1 = 5 + rand() %3 ;
    int rand2 = rand1 + 2;

    Locals localss[rand1];
    Foreign foreignn[rand2];

    cout<< "In the resident,Locals: " << rand1<<""<< endl;
    cout<< "In the resident,Foreigns: " << rand2<<""<< endl;

    cout <<"***** Locals *****"<< endl;

    for(int ii = 0; ii< rand1;ii++){
        localss[ii].read();
    }

    cout <<"***** Foreigns ***** "<< endl;

    for(int ii = 0; ii < rand2; ii++){
        foreignn[ii].read();
    }

    string newCityLocal;
    string newCityForeign;
    int year = 1;
    while(year <6){
        cout<< "*** Year: "<< year<<"***"<< endl;

        int randx = rand() %6 +1;
        //Each year, at least one foreigner or local is leaving the country and a new
        //foreigner is coming to Turkey.
        if(randx % 2 == 0){ //local is leaving
            localss[rand1-1].erasee();

        }else{
            foreignn[rand2-1].erasee();
        }
        foreignn[rand2-1].read();

        //Each year, at least one local and one foreigner change their city.
        cout<<"Please enter the new city for a local: ";
        cin>>newCityLocal;
        localss[rand1-2].changeResidency(newCityLocal);

        cout<<"Please enter the new city for a foreign: ";
        cin>> newCityForeign;
        foreignn[rand2-2] .changeResidency(newCityForeign);

        //Each year, update the ages and years of residency for all residents
        for(int jj= 0; jj< rand1; jj++){
            localss[jj].operator++(1);
        }

        for(int jj = 0; jj< rand2; jj++){
            foreignn[jj].operator++(1);
        }

        //Print the current information of all residents at the end of each year.
        for(int kk= 0; kk< rand1; kk++){
            localss[kk].printClass();
        }

        for(int kk= 0; kk< rand2; kk++){
            foreignn[kk].printClass();
        }
        year++;
    }
    return 0;
}

