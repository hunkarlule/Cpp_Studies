
#include <iostream>
#include <fstream>

int main() {
    static int lineno {};
    ////static const char* filename { "text.txt" }; // this wil relative url. it will be the doler that the current project is located
    static const char* filename{ "C:\\Users\\hlule\\Downloads\\text.txt" }; // this is compelte url of a file.
    static const char* textstring { "This is the test file." };

    // writing to a file:
    std::cout << "write to the wile:\n";
    // creating a output file-stream named ofile with giving file url as an argument.
    // note that filename is a location of the file in the file directory.
    // after creating the file stream we can use it like cout.
    std::ofstream ofile(filename);  // if file not there it will first create the file and open it for writing.
    ofile << ++lineno << " " << textstring << "\n";
    ofile << ++lineno << " " << textstring << "\n";
    ofile << ++lineno << " " << textstring << "\n";
    ofile.close(); // we need to close the file/stream after finishin it. otherwise can cause memory-leak.

  

    // read from file:
    static char buf[128];
    std::cout << "read from the file:\n";
    // creating a input file-stream named infile with giving file url as an argument.
    // note that filename is the location of the file in the file directory.
    // after creating the file stream we can use it like cin.
    // if file not there or url is wrong then it will throw an error.
    std::ifstream infile(filename);
    while (infile.good()) {
        infile.getline(buf, sizeof(buf)); // see this is excatly the same method we used with cin.
        std::cout << buf << '\n';
    }

    infile.close(); // we need to close the file/stream after finishin it. otherwise can cause memory-leak.

    //deleting file
    std::cout << "delete file.\n";
    remove(filename);
}
