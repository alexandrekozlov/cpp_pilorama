#include <iostream>
#include <cstring>
#include <exception>

class DeviceDriver
{
public:
    DeviceDriver() : connected(false) {}

    ~DeviceDriver()
    {
        Disconnect();
    }

    void Connect()
    {
        if (!connected)
        {
            // Some connect code...
            connected = true;
        }
    }

    void Disconnect()
    {
        if (connected) 
        {
            // Disconnect code...
            connected = false;
        }
        else
        {
            throw std::runtime_error("Not connected");
        }
    }

private:
    bool connected;
};

int main()
{
    try 
    {
        DeviceDriver driver;

        driver.Connect();
        driver.Disconnect();
    }
    catch(...)
    {
        std::cout << "Error!" << std::endl;
    }

    std::cout << "Exiting." << std::endl;

    return 0;
}