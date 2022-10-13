#include <vector>
#include <iostream>
#include <string>
 
int main()
{
    std::vector<char> characters;
 
    auto print_vector = [&](){
        for (char c : characters)
            std::cout << c << ' ';
        std::cout << '\n';  
    };
 
    characters.assign(7, 'a');
    print_vector();
 
    const std::string extra(6, 'b');
    characters.assign(extra.begin(), extra.end());
	std::cout << characters.size() << std::endl;
    print_vector();
 
    characters.assign({'C', '+', '+', '1', '1'});
	std::cout << characters.size() << std::endl;
    print_vector();
}