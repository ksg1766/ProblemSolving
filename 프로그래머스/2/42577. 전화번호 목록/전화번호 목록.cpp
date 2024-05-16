#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    sort(phone_book.begin(), phone_book.end());
    
    for(int i = 0; i < phone_book.size() - 1; ++i)
    {
        string* pShort = &phone_book[i];
        string* pLong = &phone_book[i + 1];
        
        int sizeShort = pShort->size();
        int sizeLong = pLong->size();
        
        if(sizeShort >= sizeLong)
        {
            swap(pShort, pLong);
            swap(sizeShort, sizeLong);
        }
        
        if(pLong->substr(0, sizeShort) == *pShort)
        {
            return false;
        }        
    }
    
    return true;
}