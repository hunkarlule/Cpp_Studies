#include <iostream>
#include <list>
using namespace std;

class Route
{
private:
    list<string> stopsList;
    list<string>::iterator currentStop;

public:
    Route() {
        currentStop = stopsList.end();
    }

   void add_stop(const string &stop) {

       stopsList.list::push_back(stop);
 

       if (currentStop == stopsList.end()) {
           currentStop = stopsList.begin();
       }



    }

   void current_stop() {
       if (!stopsList.empty()) {
           cout << "Current stop: " << *currentStop << endl;
       }
       else {
           cout << "There are no stops in the route." << endl;
       }
   }

   void next_stop() {
       if (!stopsList.empty()) {
           currentStop = std::next(currentStop);
           //++currentStop // will do the same thing
           if (currentStop == stopsList.end()) {
               currentStop = stopsList.begin();
           }
       }
   }

   void prev_stop() {
       if (!stopsList.empty()) {
           if (currentStop == stopsList.begin()) {
               currentStop = stopsList.end();
           }
           currentStop = std::prev(currentStop);
           //--currentStop // will do the same thing

       }

   }
};

int main()
{
    Route route;

    route.current_stop(); // empty route. no stops.

    route.add_stop("Los Angeles");
    route.add_stop("Las Vegas");
    route.add_stop("Salt Lake City");
    route.add_stop("Denver");

    route.current_stop(); // "Current stop: Los Angeles"
    route.next_stop();
    route.current_stop(); // "Current stop: Las Vegas"
    route.next_stop();
    route.current_stop(); // "Current stop: Salt Lake City"
    route.next_stop();
    route.current_stop(); // "Current stop: Denver"
    route.prev_stop();
    route.current_stop(); // "Current stop: Salt Lake City"

    return 0;
}