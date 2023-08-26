// 04-solution.cpp by Bill Weinman [bw.org]
// updated 2022-06-16
#include <format>
#include <iostream>

using std::format;
using std::cout;

struct catalog_card {
    const char* title {};
    const char* author {};
    const char* publisher {};
    const char* subject {};
    const char* isbn{};
    const char* oclc{};
    short int ddc1{};
    short int ddc2{};
    short int year_pub{};
    short int year_acq{};
    short int quantity{};


};

int main() {
    catalog_card lc1{ "The CG! Book", "William E. Weinman", "New Riders", "CGI (Computer network protocol)" ,  "1562055712 9781562055714", "477166381",  510, 78, 1996, 1997, 2 };
    cout << format(" Title: {}\n", lc1.title);
    cout << format("Author: {}\n", lc1.author);
    cout << format("Publisher: {}\n", lc1.publisher);
    cout << format("Subject: {}\n", lc1.subject);
    cout << format("ISBN: {}\n", lc1.isbn);
    cout << format("WorldCat (OCLC): {}\n", lc1.oclc);
    cout << format("Dewey Decimal : {}.{}\n", lc1.ddc1, lc1.ddc2);
    cout << format("Year published: {}\n", lc1.year_pub);
    cout << format("Year acquired: {}\n", lc1.year_acq);
    cout << format("Quantity: {}\n", lc1.quantity);

    cout << format("===============================\n");

    //we can do the same thing using pointer like below.
    auto* ptr = &lc1;
    cout << format(" Title: {}\n", ptr->title);
    cout << format("Author: {}\n", ptr->author);
    cout << format("Publisher: {}\n", ptr->publisher);
    cout << format("Subject: {}\n", ptr->subject);
    cout << format("ISBN: {}\n", ptr->isbn);
    cout << format("WorldCat (OCLC): {}\n", ptr->oclc);
    cout << format("Dewey Decimal : {}.{}\n", ptr->ddc1, ptr->ddc2);
    cout << format("Year published: {}\n", ptr->year_pub);
    cout << format("Year acquired: {}\n", ptr->year_acq);
    cout << format("Quantity: {}\n", ptr->quantity);
}
