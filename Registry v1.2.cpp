#include <iostream>
#include <map>
#include <string>

std::string find_patient(std::map<std::string,int>&);

int main()
{
    std::string input;
    bool working = true;
    int patientNumber = 0;
    std::map<std::string,int> list;
    std::cout << "\tRegistry!" << std::endl;
    while (working)
    {
        std::cin >> input;
        if (input == "Exit")
        {
            working = false;
        }
        else if (input == "Next")
        {
            if (list.begin() == list.end())
            {
                std::cerr << "Error! The List is empty!" << std::endl;
            }
            else
            {
                std::cout << find_patient(list) << std::endl;
            }
        }
        else
        {
            patientNumber++;
            list.insert(std::pair<std::string,int>(input, patientNumber));

        }
    }

}

std::string find_patient(std::map<std::string, int>& list)
{
    std::map<std::string,int>::iterator it = list.begin();
    std::string result = it->first;
    list.erase(result);
    return result;
       
}