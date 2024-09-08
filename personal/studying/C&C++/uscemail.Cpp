#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm> 
#include <cctype> 
#include <locale>

// Function to trim spaces from the end of a string
std::string rtrim(const std::string &s) {
    std::string result = s;
    result.erase(std::find_if(result.rbegin(), result.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), result.end());
    return result;
}

int main() {
    // Multi-line string with IDs, potentially with spaces at the end
    std::string ids_str = R"(
22600002  
22104336  
18010432  
21800347  
18020947  
22800006  
22101887  
22102149  
20010003  
19010112  
22101816  
07404117  
22800024  
21800152  
22800053  
22800206  
22101095  
24105430  
24102523  
11820088  
22100811  
22100660  
07500336  
21200101  
22101539  
22104057  
22101748  
22101823  
7400097   
11820192  
22103616
)";

    // The string to append
    std::string domain = "@usc.edu.ph";

    // Split the multi-line string into individual IDs
    std::vector<std::string> ids;
    std::stringstream ss(ids_str);
    std::string id;
    while (std::getline(ss, id)) {
        id = rtrim(id);  // Trim trailing spaces
        if (!id.empty()) {  // Ignore empty lines
            ids.push_back(id);
        }
    }

    // Append the domain to each ID
    for (std::string &id : ids) {
        id += domain;
    }

    // Output the modified strings
    for (const std::string &id : ids) {
        std::cout << id << std::endl;
    }

    return 0;
}
