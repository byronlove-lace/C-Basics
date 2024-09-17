#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>


class Device {};

class DeviceManager
{
        private:
                std::unordered_map<std::string, std::vector<Device*>> m_Devices;
        public: 
                const std::unordered_map<std::string, std::vector<Device*>>& GetDevices() const;
};

std::string getName() 
{
        return "JAN";
}

int main()
{
        // don't have to chage the code on the client-side
        auto name = getName();
        // int nameSize = name.size();

        std::string a = "Jah";

        // Example of good idea to use auto
        std::vector<std::string> strings;
        strings.push_back("Apple");
        strings.push_back("Oranges");

        // for (std::vector<std::string>::iterator it = strings.begin(); it != strings.end(); ++it)
        for (auto it = strings.begin(); it != strings.end(); ++it)
        {
                std::cout << *it << std::endl;
        }

        // C++
        // better to include in class
        using DeviceMap = std::unordered_map<std::string, std::vector<Device*>>;
        // C
        // typedef DeviceMap = std::unordered_map<std::string, std::vector<Device*>>& devices = dm.GetDevices();
 
        DeviceManager dm;
        // plebby
        // std::unordered_map<std::string, std::vector<Device*>>& devices = dm.GetDevices();
        const DeviceMap& devices = dm.GetDevices();

        // auto& devices = dm.GetDevices();
        // still need to use reference);
}
