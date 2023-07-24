// C++ Code Challenges, LinkedIn Learning

// Challenge #11: Finding Relatives
// Write an application that reads a list of people's names in a CSV file and outputs the first pair of people it finds to be possibly related based on their family names.
// Assume that all entries have one name and one family name.
// Entries are separated by commas.
// Names and family names are separated by spaces.

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;
// Finding Relatives, main()
// Summary: This application displays the first pair of possible relatives from a list of names in a CSV file.
int main(){

    vector<string> fullName; // to hold a fullname as a vector. firstname is first element and lastname is secodn element
    vector<vector<string>> people; // vector of people's names. Each fullnamei s also a vector
    string entry, name;

    std::fstream file ("names.csv", std::ios::in);
    // Read the CSV file.
    if(file.is_open()){
        while (getline(file, entry, ',')) { // reads string from file until a comma is encountred into entry string. Tha means entry has a fullname( like Rick Davis) in it
            stringstream sstr(entry); // constructiin a stringstream from entry.
            fullName.clear();
            while (getline(sstr, name, ' ')) { // reads string from sstr(stringstream) until a space is encountred into name string. That means name has a name or surname( like Rick  or Davis) in it
                fullName.push_back(name); // push the content of name to the fullName vecor. So fullname vecot is like this ["Rick", "Davis"]
            }
            people.push_back(fullName); // // push the content of fullname to the people vetor. So people vector is like this [["Rick", "Davis"]] 
        }


        file.close();
    }
    else{
        std::cout << "Something went wrong\n" << std::flush;
        return 1;
    }

    // Write your code here
    // printing all names from poeple vector.
    for (int i = 0; i < people.size(); i++) {
        for (int j = 0; j < people[i].size(); j++) {
            cout << people[i][j] << " ";
        }
        cout << endl;
    }

    // comparin names to identify first related two people.
    for (int i = 0; i < people.size() - 1; i++) {
        for (int j =  i + 1; j < people.size(); j++) {
            if (people[i][1].compare(people[j][1]) == 0) {
                std::cout << people[i][0] << " " << people[i][1] << " may be related to " << people[j][0] << " " << people[j][1] << ".\n\n" << std::flush;
                return 0;
            }
      
        }
        cout << endl;
    }

    std::cout << "No relatives found.\n\n" << std::flush;    
    return 0;
}
 