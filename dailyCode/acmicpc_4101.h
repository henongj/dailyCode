#include<iostream>

void acmicpc_4101(void)
{
    int nNumber1{};
    int nNumber2{};
    
    while(1)
    {
        std::cin >> nNumber1 >> nNumber2;
        if(nNumber1 == 0 && nNumber2 == 0)
            break;
        
        if(nNumber1 > nNumber2)
            std::cout << "Yes\n";
        else
            std::cout << "No\n";

        
    }

}
