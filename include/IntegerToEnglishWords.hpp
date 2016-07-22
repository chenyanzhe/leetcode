#ifndef INTEGER_TO_ENGLISH_WORDS_HPP_
#define INTEGER_TO_ENGLISH_WORDS_HPP_

#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class IntegerToEnglishWords {
public:

    string numberToWords(int num);

private:

    unordered_map<int, string> dict_a{
            {1,  "One"},
            {2,  "Two"},
            {3,  "Three"},
            {4,  "Four"},
            {5,  "Five"},
            {6,  "Six"},
            {7,  "Seven"},
            {8,  "Eight"},
            {9,  "Nine"},
            {10, "Ten"},
            {11, "Eleven"},
            {12, "Twelve"},
            {13, "Thirteen"},
            {14, "Fourteen"},
            {15, "Fifteen"},
            {16, "Sixteen"},
            {17, "Seventeen"},
            {18, "Eighteen"},
            {19, "Nineteen"},
            {20, "Twenty"},
            {30, "Thirty"},
            {40, "Forty"},
            {50, "Fifty"},
            {60, "Sixty"},
            {70, "Seventy"},
            {80, "Eighty"},
            {90, "Ninety"}
    };
    vector<string> dict_b{"", "Thousand", "Million", "Billion"};

    string parse(int value);
};

#endif // INTEGER_TO_ENGLISH_WORDS_HPP_
