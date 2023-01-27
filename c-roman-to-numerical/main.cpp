#include<iostream>
using namespace std;

#include<iostream>
using namespace std;

class Solution {
public:
    int integerValue = 0;
    int romanToInt(string s) {
        int strLength = s.length();
        for ( int i = 0; i < strLength; i++)
        {
            if ( s[i] == 'I')
            {
                if ( s[i+1] == 'V')
                {
                 integerValue += 4;
                    i++;
                }
                else if ( s[i+1] == 'X')
                {
                    integerValue += 9;
                    i++;
                }       
                else
                    integerValue += 1;
            }
            
            else if ( s[i] == 'V')
                integerValue += 5;
            
            else if (s[i] == 'X')
            {
                if (s[i+1] == 'L')
                {
                    integerValue += 40;
                    i++;
                }
                else if (s[i+1] == 'C')
                {
                    integerValue += 90;
                    i++;
                }
                else
                    integerValue += 10;
            }
            
            else if (s[i] == 'L')
                integerValue += 50;
            
            else if ( s[i] == 'C') 
            {
                 if ( s[i+1] == 'D')
                 {
                    integerValue += 400;
                    i++;
                 }
                else if ( s[i+1] == 'M')
                {
                    integerValue += 900;
                    i++;
                }
                else
                    integerValue += 100;
            }
            
            else if (s[i] == 'D')
                integerValue += 500;
            
            else if ( s[i] == 'M')
            integerValue += 1000;
        }  
    
        return integerValue;
    }
};

int main()
{
    Solution solutionClassObj;
    string s;
    cout << "Enter the Roman number : ";
    cin >> s;
    cout << endl << "Roman Number : " << s << endl;
    int result = solutionClassObj.romanToInt(s);
    cout << "The Equivalent Integer Value : " << result << endl;
return 0;
}

