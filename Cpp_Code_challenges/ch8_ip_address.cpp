// C++ Code Challenges, LinkedIn Learning

// Challenge #8: IP Address Validation
// Write an application that reads a string from the terminal and responds with a message indicating whether the string is a valid IP address or not.
// Assume decimal IP addresses.
// 158.25.0.33
// All numbers between 0 and 255.

#include <iostream>
#include <vector>
#include <string>

/// <summary>
///  receives a string and returns true if the string is a decial number, false otherwise.
/// 
/// </summary>
/// <param name="str"> the string to analyze </param>
/// <returns>bool: true for decimal numbers, false otherwise.</returns>
bool isNumber(const std::string& str) {
    if (str.empty()) {
        return false;
    }

    if (str.find_first_not_of("[0123456789]") == std::string::npos) {
        return true;
    }

    return false;
}

/// <summary>
/// receives a string with tokens seperated by dots(.) and return a vector that contains the tokens.
/// </summary>
/// <param name="str">the string to analyze</param>
/// <returns> std::vector<std::string>: a vector of string that contains the tokens. </returns>
std::vector<std::string>  getIPTokens(const std::string &str) {
    size_t i = 0;
    int dotCharIndex = -1;

    std::vector<std::string> tokens;

    do {
        dotCharIndex = str.find('.', dotCharIndex + 1);
        tokens.push_back(str.substr(i, dotCharIndex - i));
        i = dotCharIndex + 1;
    } while (dotCharIndex != std::string::npos);

    return tokens;
}


// is_valid_ip()
// Summary: This function validates an IP address.
// Arguments:
//           ip: The string to analyze with a potential ip address.
// Returns: A boolean value. True for valid ip addresses, false otherwise.
bool is_valid_ip(std::string ip){

    // Write your code here
    std::vector<std::string> ipTokens = getIPTokens(ip);

    if (ipTokens.size() != 4) {
        return false;
    }

    for (std::string token : ipTokens) {
        if (isNumber(token)) {
            int tokenAsInt = std::stoi(token);
            if (tokenAsInt < 0 || tokenAsInt > 255) {
                return 0;
            }
        }
        else {
            return false;
        }
    }

    return true;
}

// Main function
int main(){
    std::string s;
    
    std::cout << std::endl << "Enter an IP address in decimal: " << std::flush;
    std::getline(std::cin,s);
    std::cout << " \n" << s << (is_valid_ip(s) ? " is" : " is not" ) << " a valid IP address.\n\n";
    return 0;
}
