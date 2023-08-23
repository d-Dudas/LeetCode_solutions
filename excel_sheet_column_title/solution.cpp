#include <iostream>
#include <string>

using namespace std;

#define NR_OF_LETTERS 26
#define INT_TO_CHAR 64

class Solution {
    public:
        string convertToTitle(int columnNumber)
        {
            string rez;
            int letter;
            while(columnNumber > 0)
            {
                letter = NR_OF_LETTERS;
                while(letter * NR_OF_LETTERS >= columnNumber) letter--;
                cout << letter << " is the letter\n";
                if(letter == 0)
                {
                    rez += char(columnNumber + INT_TO_CHAR);
                    break;
                } else 
                {
                    rez += char(letter + INT_TO_CHAR);
                    columnNumber -= letter * NR_OF_LETTERS;
                }
                
            }

            return rez;
        }
};

int main()
{
    Solution s;
    cout << s.convertToTitle(701) << "\n";

    return 0;
}