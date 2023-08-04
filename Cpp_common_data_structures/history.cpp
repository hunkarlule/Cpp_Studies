#include <iostream>
#include <stack>
#include <string>

using namespace std;

class BrowserHistory {
private:
    stack<string>browserHistory;

    public:
        void visit(const string& url) {
            cout << "visiting site: " << url << endl;
            browserHistory.push(url);
        }

        void back() {
            cout << "Navigating back in browser history." << endl;
            if (!browserHistory.empty()) {
                browserHistory.pop();
            }
            else {
                cout << "No sites in browser history" << endl;
            }
        }

        string current() const {
            return !browserHistory.empty() ? browserHistory.top() : "no sites curretnly being used";
         }
};

int main()
{
    BrowserHistory bh;

    bh.visit("explorecalifornia.org");
    bh.visit("pixelford.com");
    bh.visit("landonhotel.com");

    cout << "Current Site: " << bh.current() << endl;

    bh.back();
    cout << "Current Site: " << bh.current() << endl;

    bh.back();
    cout << "Current Site: " << bh.current() << endl;

    bh.back();
    cout << "Current Site: " << bh.current() << endl;

    return 0;
}
