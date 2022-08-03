#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
int wordsCount(const std::string & sentence)
{
    int count = 0;
    for (int i = 0; i < sentence.size(); i++)
    {
        if (isalpha(sentence[i]))
        {
            while (sentence[i] != ' ' && i < sentence.size())
            {
                i++;
                continue;
            }
            count++;
        }
    }
    return count;
}

int main()
{
    std::string words;
    std::cout << "Enter a sentence please: ";
    std::getline(std::cin, words);

    int result = wordsCount(words);
    std::cout << "This sentence has " << result << " words\n";

    return 0;
}