#pragma once
#ifndef LIBCODETEST_H
#define LIBCODETEST_H

#include <iostream>
#include "VDMocapSDK_DataRead_DataType.h"

using namespace std;
using namespace VDDataRead;

typedef struct
{
    bool updataFlag = false;
    int frameIndex = 0;
    float devicePower = 0;
    int frequency = 0;
    float quaternion[20][4] = {{0}};
    float position[20][3] = {{0}};
}DEVICEINFOSTRUCT;

static DEVICEINFOSTRUCT rhandInfo;
static DEVICEINFOSTRUCT lhandInfo;

static int connStatus;

class libCodeTest
{
public:
	libCodeTest(const std::string& libPath);
	~libCodeTest();

private:
    bool lFlag = false;
	int lIndex = 0,
		lModelCount = 0,
		lUpdateCount = 0,
		lModelIds[BROADCAST_MAX_NUM],
		lUpdateIds[BROADCAST_MAX_NUM];
	const char* lIp = "192.168.26.94";
	unsigned short lPort = 7000;
	float   lPositions_body[23][3] = { 0 },
            lPositions_rightHand[20][3] = { 0 },
            lPositions_leftHand[20][3] = { 0 };

    _Version_ *version = new _Version_;  // ��ʼ�� version ָ��

    VDDataRead::_WorldSpace_ lWorldSpace = VDDataRead::WS_Geo;
	//VDDataRead::_WorldSpace_ lWorldSpace = VDDataRead::WS_UE4;
	VDDataRead::_MocapData_ lMocapData,
		lMocapDataRetarget; 

/*---------------------------------------- SDK API----------------------------------------------------*/
    // Get SDK Version information
    typedef void(*GetVersionInfo)(_Version_ *version);
    GetVersionInfo _GetVersionInfo;
    // void GetVersionInfo(_Version_* version);

    typedef void(*SetProtocol)(int index, int flag);
    SetProtocol _SetProtocol;
    // void SetProtocol(int index, int flag);

    typedef bool(*UdpSetPositionInInitialTpose)(int index, const char* dst_ip, unsigned short dst_port, _WorldSpace_ worldSpace,
    float initialPosition_body[NODES_BODY][3], float initialPosition_rHand[NODES_HAND][3], float initialPosition_lHand[NODES_HAND][3]);
    UdpSetPositionInInitialTpose _UdpSetPositionInInitialTpose;
    // bool UdpSetPositionInInitialTpose(int index, const char* dst_ip, unsigned short dst_port, _WorldSpace_ worldSpace,
    // float initialPosition_body[NODES_BODY][3], float initialPosition_rHand[NODES_HAND][3], float initialPosition_lHand[NODES_HAND][3]);

    typedef bool(*UdpOpen)(int index, unsigned short localPort);
    UdpOpen _UdpOpen;
    // bool UdpOpen(int index, unsigned short localPort);

    typedef void(*UdpClose)(int index);
    UdpClose _UdpClose;
    // void UdpClose(int index);

    typedef bool(*UdpIsOpen)(int index);
    UdpIsOpen _UdpIsOpen;
    // bool UdpIsOpen(int index);

    typedef bool(*UdpRemove)(int index, const char* dst_ip, unsigned short dst_port);
    UdpRemove _UdpRemove;
    // bool UdpRemove(int index, const char* dst_ip, unsigned short dst_port);

    typedef bool(*UdpSendRequestConnect)(int index, const char* dst_ip, unsigned short dst_port);
    UdpSendRequestConnect _UdpSendRequestConnect;
    // bool UdpSendRequestConnect(int index, const char* dst_ip, unsigned short dst_port);

    typedef bool(*UdpRecvMocapData)(int index, const char* dst_ip, unsigned short dst_port, _MocapData_* mocapData);
    UdpRecvMocapData _UdpRecvMocapData;
    // bool UdpRecvMocapData(int index, const char* dst_ip, unsigned short dst_port, _MocapData_* mocapData);

    typedef bool(*UdpRecvOriginalMocapData)(int index, const char* dst_ip, unsigned short dst_port, _MocapData_* mocapData);
    UdpRecvOriginalMocapData _UdpRecvOriginalMocapData;
    // bool UdpRecvOriginalMocapData(int index, const char* dst_ip, unsigned short dst_port, _MocapData_* mocapData);

    typedef bool(*UdpGetRecvInitialTposePosition)(int index, const char* dst_ip, unsigned short dst_port, _WorldSpace_ worldSpace,
    float initialPosition_body[NODES_BODY][3], float initialPosition_rHand[NODES_HAND][3], float initialPosition_lHand[NODES_HAND][3]);
    UdpGetRecvInitialTposePosition _UdpGetRecvInitialTposePosition;
    // bool UdpGetRecvInitialTposePosition(int index, const char* dst_ip, unsigned short dst_port, _WorldSpace_ worldSpace,
    // float initialPosition_body[NODES_BODY][3], float initialPosition_rHand[NODES_HAND][3], float initialPosition_lHand[NODES_HAND][3]);

    typedef bool(*UdpSetPositionInInitialTposePlus)(int index, const char* dst_ip, unsigned short dst_port, _WorldSpace_ worldSpace,
    float initialPosition_body[NODES_BODY][3], float initialPosition_rHand[NODES_HAND][3], float initialPosition_lHand[NODES_HAND][3]);
    UdpSetPositionInInitialTposePlus _UdpSetPositionInInitialTposePlus;
    // bool UdpSetPositionInInitialTposePlus(int index, const char* dst_ip, unsigned short dst_port, int ModelId, _WorldSpace_ worldSpace,
    // float initialPosition_body[NODES_BODY][3], float initialPosition_rHand[NODES_HAND][3], float initialPosition_lHand[NODES_HAND][3]);

    typedef bool(*GetBroadcastModelId)(int index, const char* dst_ip, unsigned short dst_port, int* modelIdCount, int modelId[BROADCAST_MAX_NUM], int* UpdateIdNum, int UpdateId[UPDATEID_MAX_ID]);
    GetBroadcastModelId _GetBroadcastModelId;
    // bool GetBroadcastModelId(int index, const char* dst_ip, unsigned short dst_port, int* modelIdCount, int modelId[BROADCAST_MAX_NUM], int* UpdateIdNum, int UpdateId[UPDATEID_MAX_ID]);

    typedef bool(*UdpRecvMocapDataPlus)(int index, const char* dst_ip, unsigned short dst_port, int ModelId, _MocapDataPlus_* mocapData);
    UdpRecvMocapDataPlus _UdpRecvMocapDataPlus;
    // bool UdpRecvMocapDataPlus(int index, const char* dst_ip, unsigned short dst_port, int ModelId, _MocapDataPlus_* mocapData);

    typedef bool(*UdpRecvOriginalMocapDataPlus)(int index, const char* dst_ip, unsigned short dst_port, int ModelId, _MocapDataPlus_* mocapData);
    UdpRecvOriginalMocapDataPlus _UdpRecvOriginalMocapDataPlus;
    // bool UdpRecvOriginalMocapDataPlus(int index, const char* dst_ip, unsigned short dst_port, int ModelId, _MocapDataPlus_* mocapData);

    /*------------------------------------- end --------------------------------------------------*/
	// VDDataRead::_Version_ *lVersionInfo = new VDDataRead::_Version_;

    

public:
    void* handle;
    void getDataAction();
    void getBodyDataAction();
    void getRHandDataAction();
    void getLHandDataAction();
    void getFPSAction();

    void showVersionAction();
    void openDataReadAction();
    void closeDataReadAction();

    void autoGetDataAction();

};

#endif
