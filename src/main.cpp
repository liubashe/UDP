#include <iostream>
// #include <format> //C++20
#include <chrono>
#include <thread>
#include "../include/VDMocapSDK_DataRead_DataType.h"
#include "../include/libCodeTest.h"


#define SOFTWARE_VERSION "1.0.0"
#define LIB_PATH "../lib/libVDMocapSDK_dataRead.so"


int main()
{
    if(LIB_PATH == "")
    {
        std::cout<<"Unknown architecture!\n"<<std::endl;
        return 0;
    }
    libCodeTest libUsing(LIB_PATH);

    if (!libUsing.handle) 
	{
        std::cout<<"lib is not exist!\n"<<std::endl;
        return 0;
	}

    char userInput;

    std::cout << "Please enter the keyboard for control(press 'h' get help):" << std::endl;
    while (true) 
    {
        std::cin >> userInput;  // �ȴ��û������ַ�
        if (userInput == 'q') 
        {
            std::cout << "exit application..." << std::endl;
            break;
        } 
        else if(userInput == 'h')
        {
            std::cout << "software version : " << SOFTWARE_VERSION << std::endl;
            std::cout << "h : get help" << std::endl;

            // udp operate
            std::cout << "o : open udp" << std::endl;
            // std::cout << "s : stop udp" << std::endl;
            std::cout << "c : close udp" << std::endl;


            // udp operate
            std::cout << "v : get sdk version" << std::endl;
            std::cout << "g : get whole data" << std::endl;
            std::cout << "b : get body data" << std::endl;
            std::cout << "r : get right hand data" << std::endl;
            std::cout << "l : get left hand data" << std::endl;
            std::cout << "f : get fps data" << std::endl;

            std::cout << "\nPlease enter the keyboard for control(press 'h' get help):" << std::endl;
        }
        else if(userInput == 'b')
        {
            libUsing.getBodyDataAction();
            std::cout << "\nPlease enter the keyboard for control(press 'h' get help):" << std::endl;
        }
        else if(userInput == 'r')
        {
            libUsing.getRHandDataAction();
            std::cout << "\nPlease enter the keyboard for control(press 'h' get help):" << std::endl;
        }
        else if(userInput == 'l')
        {
            libUsing.getLHandDataAction();
            std::cout << "\nPlease enter the keyboard for control(press 'h' get help):" << std::endl;
        }
        else if(userInput == 'f')
        {
            libUsing.getFPSAction();
            std::cout << "\nPlease enter the keyboard for control(press 'h' get help):" << std::endl;
        }
        else if(userInput == 'g')
        {
            libUsing.getDataAction();
            std::cout << "\nPlease enter the keyboard for control(press 'h' get help):" << std::endl;
        }
        else if(userInput == 'v')
        {
            libUsing.showVersionAction();
            std::cout << "\nPlease enter the keyboard for control(press 'h' get help):" << std::endl;
        }
        else if(userInput == 'c')
        {
            libUsing.closeDataReadAction();
            std::cout << "\nPlease enter the keyboard for control(press 'h' get help):" << std::endl;
        }
        else if(userInput == 'o')
        {
            libUsing.openDataReadAction();
            std::cout << "\nPlease enter the keyboard for control(press 'h' get help):" << std::endl;
        }
        else 
        {
            std::cout << "The button you pressed was :" << userInput << std::endl;
            std::cout << "This command is unsupport!" << std::endl;
            std::cout << "\nPlease enter the keyboard for control(press 'h' get help):" << std::endl;
        }
    }

    return 0;
}


// g++ -o ./bin/main main.cpp libCodeTest.cpp -ldl
// ./bin/main 



