#include <dlfcn.h>
#include <string.h>
#include "../include/VDMocapSDK_DataRead_DataType.h"
#include "../include/libCodeTest.h"
#include <thread>

using namespace VDDataRead;

libCodeTest::libCodeTest(const std::string& libPath)
{
    // Load dynamic library
    handle = dlopen(libPath.c_str(), RTLD_LAZY);  // Attention library path
    if (!handle) 
    {
        std::cerr << "Failed to load library: " << dlerror() << std::endl;
        return;
    }

    // Clean up any existing errors
    dlerror();

    // Get function pointer
    _GetVersionInfo = (GetVersionInfo) dlsym(handle,"GetVersionInfo");
    _SetProtocol = (SetProtocol) dlsym(handle,"GetVersionInfo");
    _UdpSetPositionInInitialTpose = (UdpSetPositionInInitialTpose) dlsym(handle,"UdpSetPositionInInitialTpose");
    _UdpOpen = (UdpOpen) dlsym(handle,"UdpOpen");
    _UdpClose = (UdpClose) dlsym(handle,"UdpClose");
    _UdpIsOpen = (UdpIsOpen) dlsym(handle,"UdpIsOpen");
    _UdpRemove = (UdpRemove) dlsym(handle,"UdpRemove");
    _UdpSendRequestConnect = (UdpSendRequestConnect) dlsym(handle,"UdpSendRequestConnect");
    _UdpRecvOriginalMocapData = (UdpRecvOriginalMocapData) dlsym(handle,"UdpRecvOriginalMocapData");
    _UdpGetRecvInitialTposePosition = (UdpGetRecvInitialTposePosition) dlsym(handle,"UdpGetRecvInitialTposePosition");
    _UdpSetPositionInInitialTposePlus = (UdpSetPositionInInitialTposePlus) dlsym(handle,"GetVersionInfo");
    _GetBroadcastModelId = (GetBroadcastModelId) dlsym(handle,"GetBroadcastModelId");
    _UdpRecvOriginalMocapDataPlus = (UdpRecvOriginalMocapDataPlus) dlsym(handle,"UdpRecvOriginalMocapDataPlus");

    const char* error = dlerror();
	
    if (error) 
    {
        std::cerr << "Failed to find the function: " << error << std::endl;
        dlclose(handle);
		return;
    }
}

libCodeTest::~libCodeTest()
{
	if (handle) 
	{
        std::cout << "... close SDK ..." << std::endl;
		// close library
		dlclose(handle);
	}
}

void libCodeTest::showVersionAction()
{
	if (_GetVersionInfo)
    {
        std::cout << "...show SDK Version..." << std::endl;
        _GetVersionInfo(version);
        cout << "********************************************************" <<endl;
        cout << "Project Name : "<< (const char*)(version->Project_Name) << endl;
        cout << "Author Organization : " << (const char*)(version->Author_Organization) << endl;
        cout << "Author_Domainr : " << (const char*)version->Author_Domain << endl;
        cout << "Author_Maintainer : " << (const char*)version->Author_Maintainer << endl;
        cout << "Version : " << (const char*)version->Version << endl;
        // cout << "Version_Major : " << (version->Version_Major) << endl;
        // cout << "Version_Minor : " << version->Version_Minor << endl;
        // cout << "Version_Patch : " << version->Version_Patch << endl;
        cout << "********************************************************\n" << endl;
    }
    else 
    {
        return;
    }
}

void libCodeTest::getDataAction()
{
    char userInput;

    if(_UdpSendRequestConnect(lIndex, lIp, lPort))
	{
        cout << "--------------------------- Udp Send Request Connect ----------------\n" << endl;
        lFlag = _UdpSetPositionInInitialTpose(0, lIp, lPort, lWorldSpace, lPositions_body, lPositions_rightHand, lPositions_leftHand);
        if (lFlag == false)
            int a = 0;

        while (1)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
    
            lFlag = _UdpRecvOriginalMocapData(lIndex, lIp, lPort, &lMocapData);

            if (lMocapData.isUpdate)
            {
                string str = "\n==================== Mocap Data =================\r\n";
                str += "frameIndex : " + to_string(lMocapData.frameIndex) + "\n";
                str += "frequency : " + to_string(lMocapData.frequency) + "\n";
                str += "========  Body Data  ========\n";
                for (int ii = 0; ii < NODES_BODY; ii++)
                {
                    for (int i = 0; i < 4; i++) { str += to_string(lMocapData.quaternion_body[ii][i]) + " "; }
                    for (int i = 0; i < 3; i++) { str += to_string(lMocapData.position_body[ii][i]) + " "; }
                    str += "\n";
                }
                str += "========  Righthand Data  ========\n";
                for (int ii = 0; ii < NODES_HAND; ii++)
                {
                    for (int i = 0; i < 4; i++) { str += to_string(lMocapData.quaternion_rHand[ii][i]) + " "; }
                    for (int i = 0; i < 3; i++) { str += to_string(lMocapData.position_rHand[ii][i]) + " "; }
                    str += "\n";
                }
                str += "========  Lefthand Data  ========\n";
                for (int ii = 0; ii < NODES_HAND; ii++)
                {
                    for (int i = 0; i < 4; i++) { str += to_string(lMocapData.quaternion_lHand[ii][i]) + " "; }
                    for (int i = 0; i < 3; i++) { str += to_string(lMocapData.position_lHand[ii][i]) + " "; }
                    str += "\n";
                }
                str += "========  Righthand sign  ========\n";
                str += to_string(lMocapData.gestureResultR) + " ";
                str += "\n";
                str += "========  Lefthand sign  ========\n";
                str += to_string(lMocapData.gestureResultL) + " ";
                str += "\n";
                str += "========  Audio another expressions(unuse)  ========\n";
                str += "valid or not : " + to_string(lMocapData.isUseFaceBlendShapesARKit) + "\n";
                for (int ii = 0; ii < NODES_FACEBS_ARKIT; ii++)
                {
                    str += to_string(lMocapData.faceBlendShapesARKit[ii]) + " ";
                }
                str += "\n";

                str += "========  Audio another expressions(unuse)  ========\n";
                str += "valid or not : " + to_string(lMocapData.isUseFaceBlendShapesAudio) + "\n";
                for (int ii = 0; ii < NODES_FACEBS_AUDIO; ii++)
                {
                    str += to_string(lMocapData.faceBlendShapesAudio[ii]) + " ";
                }
                str += "\n";
                str += "========  eyes Data(unuse)  ========\n";
                for (int ii = 0; ii < 4; ii++)
                {
                    str += to_string(lMocapData.localQuat_RightEyeball[ii]) + " ";
                }
                for (int ii = 0; ii < 4; ii++)
                {
                    str += to_string(lMocapData.localQuat_LeftEyeball[ii]) + " ";
                }
                str += "\n";
                cout << str << endl;
            }

            if (lFlag)
            {
                int a = 0;
            }
            int a = 0;
        }
    }
}

void libCodeTest::getBodyDataAction()
{
    char userInput;

    if(_UdpSendRequestConnect(lIndex, lIp, lPort))
	{
        cout << "--------------------------- Udp Send Request Connect ----------------\n" << endl;
        lFlag = _UdpSetPositionInInitialTpose(0, lIp, lPort, lWorldSpace, lPositions_body, lPositions_rightHand, lPositions_leftHand);
        if (lFlag == false)
            int a = 0;

        while (1)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
    
            lFlag = _UdpRecvOriginalMocapData(lIndex, lIp, lPort, &lMocapData);

            if (lMocapData.isUpdate)
            {
                string str = "\n==================== Mocap Data =================\r\n";
                str += "frameIndex : " + to_string(lMocapData.frameIndex) + "\n";
                str += "frequency : " + to_string(lMocapData.frequency) + "\n";
                str += "========  Body Data  ========\n";
                for (int ii = 0; ii < NODES_BODY; ii++)
                {
                    for (int i = 0; i < 4; i++) { str += to_string(lMocapData.quaternion_body[ii][i]) + " "; }
                    for (int i = 0; i < 3; i++) { str += to_string(lMocapData.position_body[ii][i]) + " "; }
                    str += "\n";
                }
                cout << str << endl;
            }
        }
    }
}

void libCodeTest::getRHandDataAction()
{
    char userInput;

    if(_UdpSendRequestConnect(lIndex, lIp, lPort))
	{
        cout << "--------------------------- Udp Send Request Connect ----------------\n" << endl;
        lFlag = _UdpSetPositionInInitialTpose(0, lIp, lPort, lWorldSpace, lPositions_body, lPositions_rightHand, lPositions_leftHand);
        if (lFlag == false)
            int a = 0;

        while (1)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
    
            lFlag = _UdpRecvOriginalMocapData(lIndex, lIp, lPort, &lMocapData);

            if (lMocapData.isUpdate)
            {
                string str = "\n==================== Mocap Data =================\r\n";
                str += "frameIndex : " + to_string(lMocapData.frameIndex) + "\n";
                str += "frequency : " + to_string(lMocapData.frequency) + "\n";
                str += "========  Righthand Data  ========\n";
                for (int ii = 0; ii < NODES_HAND; ii++)
                {
                    for (int i = 0; i < 4; i++) { str += to_string(lMocapData.quaternion_rHand[ii][i]) + " "; }
                    for (int i = 0; i < 3; i++) { str += to_string(lMocapData.position_rHand[ii][i]) + " "; }
                    str += "\n";
                }
                cout << str << endl;
            }
        }
    }
}

void libCodeTest::getLHandDataAction()
{
    char userInput;

    if(_UdpSendRequestConnect(lIndex, lIp, lPort))
	{
        cout << "--------------------------- Udp Send Request Connect ----------------\n" << endl;
        lFlag = _UdpSetPositionInInitialTpose(0, lIp, lPort, lWorldSpace, lPositions_body, lPositions_rightHand, lPositions_leftHand);
        if (lFlag == false)
            int a = 0;

        while (1)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
    
            lFlag = _UdpRecvOriginalMocapData(lIndex, lIp, lPort, &lMocapData);

            if (lMocapData.isUpdate)
            {
                string str = "\n==================== Mocap Data =================\r\n";
                str += "frameIndex : " + to_string(lMocapData.frameIndex) + "\n";
                str += "frequency : " + to_string(lMocapData.frequency) + "\n";
                str += "========  Lefthand Data  ========\n";
                for (int ii = 0; ii < NODES_HAND; ii++)
                {
                    for (int i = 0; i < 4; i++) { str += to_string(lMocapData.quaternion_lHand[ii][i]) + " "; }
                    for (int i = 0; i < 3; i++) { str += to_string(lMocapData.position_lHand[ii][i]) + " "; }
                    str += "\n";
                }
                cout << str << endl;
            }
        }
    }
}

void libCodeTest::getFPSAction()
{
    char userInput;

    if(_UdpSendRequestConnect(lIndex, lIp, lPort))
	{
        cout << "--------------------------- Udp Send Request Connect ----------------\n" << endl;
        lFlag = _UdpSetPositionInInitialTpose(0, lIp, lPort, lWorldSpace, lPositions_body, lPositions_rightHand, lPositions_leftHand);
        if (lFlag == false)
            int a = 0;

        while (1)
        {
            string str;
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
            lFlag = _UdpRecvOriginalMocapData(lIndex, lIp, lPort, &lMocapData);

            if (lMocapData.isUpdate)
            {
                str += "frameIndex : " + to_string(lMocapData.frameIndex) + "\n";
                str += "frequency : " + to_string(lMocapData.frequency) + "\n";
                cout << str << endl;
            }
        }
    }
}


void libCodeTest::openDataReadAction()
{
    if(!_UdpIsOpen(lIndex))
    {
        if(_UdpOpen(lIndex,lPort))
        {
            cout << "["<< __FILE__<<"]"<< "["<< __LINE__<<"]"<< "open succeed! \n" << endl;
        }
        else
        {
            cout << "["<< __FILE__<<"]"<< "["<< __LINE__<<"]"<< "open fail! \n" << endl;
        }
    }
}

void libCodeTest::closeDataReadAction()
{
    if(_UdpIsOpen(lIndex))
    {
        _UdpClose(lIndex);
    }
}



