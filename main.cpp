// C++ program to demonstrate working of regex_search()
#include <iostream>
#include <regex>
#include <openssl/md5.h>
#include <iomanip>
#include <sstream>
#include <string>
using namespace std;


std::string
GetMD5Hash(const std::string& input)
{
    unsigned char hash[MD5_DIGEST_LENGTH];

    MD5((unsigned char*)input.c_str(), input.size(), hash);

    std::ostringstream hashStream;

    hashStream << std::hex << std::setfill('0');
    for (uint16_t c : hash)
    {
        hashStream << std::setw(2) << c;
    }
    return hashStream.str();
}

int main()
{
    // Target sequence
    string s = "1) First MAC 01-23-45-67-89-AB 2) Second MAC 01:23:45:67:89:AB 3) Third MAC 01-23-45-67-89-AB 4) Fourth MAC  11:22:33:44:55:66";
    string sTraverse = s;
    cout << "Initial String : " << s << std::endl;
    // An object of regex for pattern to be searched
    // regex r("([0-9A-Fa-f]{2}[:-]){5}([0-9A-Fa-f]{2})|([0-9a-fA-F]{4}\\.[0-9a-fA-F]{4}\\.[0-9a-fA-F]{4})");
    // regex r("([0-9A-Fa-f]{2}");
    // regex r("([[:xdigit:]]{2}([-:]))([[:xdigit:]]{2}\1){4}[[:xdigit:]]{2}");
    //regex r("[0-9A-Fa-f][0-9A-Fa-f]:[0-9A-Fa-f][0-9A-Fa-f]:[0-9A-Fa-f][0-9A-Fa-f]:[0-9A-Fa-f][0-9A-Fa-f]:[0-9A-Fa-f][0-9A-Fa-f]:[0-9A-Fa-f][0-9A-Fa-f]");
    //regex r("(?:[0-9A-F]{2}[:]){5}(?:[0-9A-F]{2})"); //Perfect match for : notation
    //const regex r("(?:[0-9A-Fa-f]{2}(?:([:-])|)[0-9A-Fa-f]{2})(?:(?(1)\1|\.)(?:[0-9A-Fa-f]{2}([:-]?)[0-9A-Fa-f]{2})){2}");

    // flag type for determining the matching behavior
    // here it is for matches on 'string' objects
    smatch m;

    // regex_search() for searching the regex pattern
    // 'r' in the string 's'. 'm' is flag for determining
    // matching behavior.

    cout << "After regex:\n ==================================\n" << endl;
    std::regex macid_regex("(?:[0-9A-F]{2}[:]){5}(?:[0-9A-F]{2})");
//    auto macid_begin = std::sregex_iterator(s.begin(), s.end(), macid_regex);
//    auto macid_end = std::sregex_iterator();

//    for (std::sregex_iterator i = macid_begin; i != macid_end; ++i) {
//           std::smatch match = *i;
//           std::string match_str = match.str();
//           if (match_str.size() > 0) {
//               std::cout << "  " << match_str << '\n';
//               s.replace(s.find(match_str),match_str.length(),GetMD5Hash(match_str));
//               std::cout << "modified string : " << s << std::endl;
//           }
//    }


    // for each loop

    while (regex_search(sTraverse, m, macid_regex))
    {
        cout << m.str() << "\n";
        s.replace(s.find(m.str()),m.str().length(),GetMD5Hash(m.str()));
        cout << s << std::endl;
        sTraverse = m.suffix();
    }

    return 0;
}
