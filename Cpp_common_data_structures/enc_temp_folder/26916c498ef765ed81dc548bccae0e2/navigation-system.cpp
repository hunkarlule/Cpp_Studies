#include <iostream>
#include <list>
using namespace std;

class Route
{
    list<string> stopsList;
    list<string>::iterator currentStop;

public:
   void add_stop(string stop) {
       if (stopsList.empty()) {
           stopsList.list::push_front(stop);
           currentStop = stopsList.begin();
       }
       else {
           stopsList.list::insert(++currentStop, stop);
       }


    }

   void current_stop() {
       cout << "Current stop :" << *currentStop << endl;
   }

   void next_stop() {
     currentStop =  std::next(currentStop);
   }

   void prev_stop() {
       currentStop = std::prev(currentStop);

   }
};

int main()
{
    Route route;

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