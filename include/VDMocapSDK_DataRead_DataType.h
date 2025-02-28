#pragma once
#ifndef VDMOCAPSDK_DATAREAD_DATATYPE_H
#define VDMOCAPSDK_DATAREAD_DATATYPE_H

#define NODES_BODY 23
#define NODES_HAND 20
#define NODES_FACEBS_ARKIT 52
#define NODES_FACEBS_AUDIO 26
#define TRACKER_BODY 3 //��ѧ׷�������岿������, �ֱ���Hips/RightFoot/LeftFoot
#define BROADCAST_MAX_NUM  20                //���֧��20��ģ�͹㲥
#define UPDATEID_MAX_ID    5                 //һ�θ�������ȡ��Id��

namespace VDDataRead
{
	/**
	* @brief
	*   ȫ����ڵ㼰����š�
	*/
	typedef enum BODYNODES
	{
		BN_Hips = 0,                    ///< Hips
		BN_RightUpperLeg,               ///< Right Upper Leg
		BN_RightLowerLeg,               ///< Right Lower Leg
		BN_RightFoot,                   ///< Right Foot
		BN_RightToe,                    ///< Right Toe
		BN_LeftUpperLeg,                ///< Left Upper Leg
		BN_LeftLowerLeg,                ///< Left Lower Leg
		BN_LeftFoot,                    ///< Left Foot
		BN_LeftToe,                     ///< Left Toe
		BN_Spine,                       ///< Spine
		BN_Spine1,                      ///< Spine1
		BN_Spine2,                      ///< Spine2
		BN_Spine3,                      ///< Spine3 -- Back
		BN_Neck,                        ///< Neck
		BN_Head,                        ///< Head
		BN_RightShoulder,               ///< Right Shoulder
		BN_RightUpperArm,               ///< Right Upper Arm
		BN_RightLowerArm,               ///< Right Lower Arm
		BN_RightHand,                   ///< Right Hand
		BN_LeftShoulder,                ///< Left Shoulder
		BN_LeftUpperArm,                ///< Left Upper Arm
		BN_LeftLowerArm,                ///< Left Lower Arm
		BN_LeftHand,                    ///< Left Hand
	}_BodyNodes_;



	/**
	* @brief
	*   Hand nodes name and its index.
	*/
	typedef enum HANDNODES
	{
		HN_Hand = 0,
		HN_ThumbFinger,
		HN_ThumbFinger1,
		HN_ThumbFinger2,
		HN_IndexFinger,
		HN_IndexFinger1,
		HN_IndexFinger2,
		HN_IndexFinger3,
		HN_MiddleFinger,
		HN_MiddleFinger1,
		HN_MiddleFinger2,
		HN_MiddleFinger3,
		HN_RingFinger,
		HN_RingFinger1,
		HN_RingFinger2,
		HN_RingFinger3,
		HN_PinkyFinger,
		HN_PinkyFinger1,
		HN_PinkyFinger2,
		HN_PinkyFinger3,
	}_HandNodes_;




	//Face BlendShape index
	typedef enum FACEBLENDSHAPEARKIT
	{
		ARKIT_BrowDownLeft = 0,
		ARKIT_BrowDownRight,
		ARKIT_BrowInnerUp,
		ARKIT_BrowOuterUpLeft,
		ARKIT_BrowOuterUpRight,
		ARKIT_CheekPuff,
		ARKIT_CheekSquintLeft,
		ARKIT_CheekSquintRight,
		ARKIT_EyeBlinkLeft,
		ARKIT_EyeBlinkRight,
		ARKIT_EyeLookDownLeft,
		ARKIT_EyeLookDownRight,
		ARKIT_EyeLookInLeft,
		ARKIT_EyeLookInRight,
		ARKIT_EyeLookOutLeft,
		ARKIT_EyeLookOutRight,
		ARKIT_EyeLookUpLeft,
		ARKIT_EyeLookUpRight,
		ARKIT_EyeSquintLeft,
		ARKIT_EyeSquintRight,
		ARKIT_EyeWideLeft,
		ARKIT_EyeWideRight,
		ARKIT_JawForward,
		ARKIT_JawLeft,
		ARKIT_JawOpen,
		ARKIT_JawRight,
		ARKIT_MouthClose,
		ARKIT_MouthDimpleLeft,
		ARKIT_MouthDimpleRight,
		ARKIT_MouthFrownLeft,
		ARKIT_MouthFrownRight,
		ARKIT_MouthFunnel,
		ARKIT_MouthLeft,
		ARKIT_MouthLowerDownLeft,
		ARKIT_MouthLowerDownRight,
		ARKIT_MouthPressLeft,
		ARKIT_MouthPressRight,
		ARKIT_MouthPucker,
		ARKIT_MouthRight,
		ARKIT_MouthRollLower,
		ARKIT_MouthRollUpper,
		ARKIT_MouthShrugLower,
		ARKIT_MouthShrugUpper,
		ARKIT_MouthSmileLeft,
		ARKIT_MouthSmileRight,
		ARKIT_MouthStretchLeft,
		ARKIT_MouthStretchRight,
		ARKIT_MouthUpperUpLeft,
		ARKIT_MouthUpperUpRight,
		ARKIT_NoseSneerLeft,
		ARKIT_NoseSneerRight,
		ARKIT_TongueOut,
	}_FaceBlendShapeARKit_;



	//Face BlendShape index
	typedef enum FACEBLENDSHAPEAUDIO
	{
		AUDIO_a = 0,
		AUDIO_b,
		AUDIO_c,
		AUDIO_d,
		AUDIO_e,
		AUDIO_f,
		AUDIO_g,
		AUDIO_h,
		AUDIO_i,
		AUDIO_j,
		AUDIO_k,
		AUDIO_l,
		AUDIO_m,
		AUDIO_n,
		AUDIO_o,
		AUDIO_p,
		AUDIO_q,
		AUDIO_r,
		AUDIO_s,
		AUDIO_t,
		AUDIO_u,
		AUDIO_v,
		AUDIO_w,
		AUDIO_x,
		AUDIO_y,
		AUDIO_z,
	}_FaceBlendShapeAudio_;



	typedef enum SENSORSTATE {
		SS_NONE = 0,
		SS_Well,                        //����
		SS_NoData,                      //������
		SS_UnReady,                     //��ʼ����
		SS_BadMag,                      //�Ÿ���
	}_SensorState_;



	typedef enum WORLDSPACE {
		WS_Geo = 0,                        //��ʾ��������ϵΪ��������ϵ
		WS_Unity,                          //��ʾ��������ϵΪUnity��������ϵ
		WS_UE4,                            //��ʾ��������ϵΪUE4��������ϵ
	}_WorldSpace_;

	typedef enum GESTURE {
		GESTURE_NONE = 0,  // δ֪����
		// 1 ~ 10
		GESTURE_1,         // ָ��ʳָ��ֱ��������ָ��£
		GESTURE_2,         // ������
		GESTURE_3,         // OK
		GESTURE_4,         // ��
		GESTURE_5,         // �ƣ�����
		GESTURE_6,         // ��
		GESTURE_7,         // ��
		GESTURE_8,         // ��
		GESTURE_9,         // �����ޡ�
		GESTURE_10,        // �����ޡ�
		// 11 ~ 20
		GESTURE_11,        // ����
		GESTURE_12,        // �Ұ��㣺��Ĵָ��ʳָ��Сָ��ֱ��������ָ��£
		GESTURE_13,        // ҡ����ʳָ��βָ��ֱ��������£
		GESTURE_14,        // ����
		GESTURE_15,        // ץȡ
		GESTURE_16,        // ��ȭ��ʯͷ��
		GESTURE_17,        // ��ǹ����Ĵָ�����ʳָ����ָ��ֱ��£
		GESTURE_18,        // �����ޡ�
		GESTURE_19,        // �����ޡ�
		GESTURE_20,        // ����ָ
		// 21 ~ 22
		GESTURE_21,        // ��βָ
		GESTURE_22,        // ��
	}_Gesture_;



	//���ڻ�ȡ��������ݣ��� isUpdate = false ��ʾ��֡δ���£�����֡�Ƕ�֡�Ĳ��ϵģ���������ǰһ֡��ͬ��
	typedef struct MOCAPDATA
	{
		bool isUpdate;                              //true��ʾ�豸�����Ѹ���
		unsigned int frameIndex;                    //֡���
		int frequency;                              //�豸���ݴ���Ƶ��

		int nsResult;                               //��������

		_SensorState_ sensorState_body[NODES_BODY] = { SS_NONE };
		float position_body[NODES_BODY][3]/*xyz-m*/ = { {0} };
		float quaternion_body[NODES_BODY][4]/*wxyz*/ = { {0} };
		float gyr_body[NODES_BODY][3] = { 0 };
		float acc_body[NODES_BODY][3] = { 0 }; //ȥ�������ٶ�
		float velocity_body[NODES_BODY][3] = { 0 };

		_SensorState_ sensorState_rHand[NODES_HAND] = { SS_NONE };
		float position_rHand[NODES_HAND][3]/*xyz-m*/ = { {0} };
		float quaternion_rHand[NODES_HAND][4]/*wxyz*/ = { {0} };
		float gyr_rHand[NODES_HAND][3] = { 0 };
		float acc_rHand[NODES_HAND][3] = { 0 };  //ȥ�������ٶ�
		float velocity_rHand[NODES_HAND][3] = { 0 };

		_SensorState_ sensorState_lHand[NODES_HAND] = { SS_NONE };
		float position_lHand[NODES_HAND][3]/*xyz-m*/ = { {0} };
		float quaternion_lHand[NODES_HAND][4]/*wxyz*/ = { {0} };
		float gyr_lHand[NODES_HAND][3] = { 0 };
		float acc_lHand[NODES_HAND][3] = { 0 };  //ȥ�������ٶ�
		float velocity_lHand[NODES_HAND][3] = { 0 };

		bool isUseFaceBlendShapesARKit = false;
		bool isUseFaceBlendShapesAudio = false;
		float faceBlendShapesARKit[NODES_FACEBS_ARKIT] = { 0 };  //���� bs ���ݣ�����ͷ��ʽʶ��ı���
		float faceBlendShapesAudio[NODES_FACEBS_AUDIO] = { 0 };  //���� bs ���ݣ�������ʽʶ��ı���
		float localQuat_RightEyeball[4] = { 0 };  //����������
		float localQuat_LeftEyeball[4] = { 0 };   //����������

		_Gesture_ gestureResultL = GESTURE_NONE;   //������������  
		_Gesture_ gestureResultR = GESTURE_NONE;   //������������

	}_MocapData_;


	typedef struct MOCAPDATAPLUS
	{
		bool isUpdate;                              //true��ʾ�豸�����Ѹ���
		int id = 0;
		unsigned int frameIndex;                    //֡���
		int frequency;                              //�豸���ݴ���Ƶ��
		long time ;
		int nsResult;                               //��������

		bool haveBody = false;
		bool haveRHand = false;
		bool haveLHand = false;
		bool haveFace = false;

		_SensorState_ sensorState_body[NODES_BODY] = { SS_NONE };
		float position_body[NODES_BODY][3]/*xyz-m*/ = { {0} };
		float quaternion_body[NODES_BODY][4]/*wxyz*/ = { {0} };
		float gyr_body[NODES_BODY][3] = { 0 };
		float acc_body[NODES_BODY][3] = { 0 }; //ȥ�������ٶ�
		float velocity_body[NODES_BODY][3] = { 0 };

		_SensorState_ sensorState_rHand[NODES_HAND] = { SS_NONE };
		float position_rHand[NODES_HAND][3]/*xyz-m*/ = { {0} };
		float quaternion_rHand[NODES_HAND][4]/*wxyz*/ = { {0} };
		float gyr_rHand[NODES_HAND][3] = { 0 };
		float acc_rHand[NODES_HAND][3] = { 0 };  //ȥ�������ٶ�
		float velocity_rHand[NODES_HAND][3] = { 0 };

		_SensorState_ sensorState_lHand[NODES_HAND] = { SS_NONE };
		float position_lHand[NODES_HAND][3]/*xyz-m*/ = { {0} };
		float quaternion_lHand[NODES_HAND][4]/*wxyz*/ = { {0} };
		float gyr_lHand[NODES_HAND][3] = { 0 };
		float acc_lHand[NODES_HAND][3] = { 0 };  //ȥ�������ٶ�
		float velocity_lHand[NODES_HAND][3] = { 0 };

		bool isUseFaceBlendShapesARKit = false;
		bool isUseFaceBlendShapesAudio = false;
		float faceBlendShapesARKit[NODES_FACEBS_ARKIT] = { 0 };  //���� bs ���ݣ�����ͷ��ʽʶ��ı���
		float faceBlendShapesAudio[NODES_FACEBS_AUDIO] = { 0 };  //���� bs ���ݣ�������ʽʶ��ı���
		float localQuat_RightEyeball[4] = { 0 };  //����������
		float localQuat_LeftEyeball[4] = { 0 };   //����������

		_Gesture_ gestureResultL = GESTURE_NONE;   //������������  
		_Gesture_ gestureResultR = GESTURE_NONE;   //������������

		int haveTracker[TRACKER_BODY] = { false };					 //��ѧ׷�������ڱ�� 
		float position_Tracker[TRACKER_BODY][3] = { 0 };			//��ѧ׷�������� 
		float quat_Tracker[TRACKER_BODY][4] = { 0 };				//��ѧ׷������̬ 
		bool haveVRglass = false;									 //VR�۾�׷�������ڱ��		
		float position_VRglass[3] = { 0 };						//VR�۾�׷��������
		float quat_VRglass[4] = { 0 };							//VR�۾�׷������̬

		bool haveTrackerR = false;									 //��ѧ׷�������ڱ��		
		float position_TrackerR[3] = { 0 };						//��ѧ׷��������
		float quat_TrackerR[4] = { 0 };							//��ѧ׷������̬

		bool haveTrackerL = false;									  //��ѧ׷�������ڱ��	
		float position_TrackerL[3] = { 0 };						  //��ѧ׷��������
		float quat_TrackerL[4] = { 0 };							  //��ѧ׷������̬

	}_MocapDataPlus_;



	//
	typedef struct VERSION
	{
		unsigned char Project_Name[26] = { 0 };
		unsigned char Author_Organization[128] = { 0 };
		unsigned char Author_Domain[26] = { 0 };
		unsigned char Author_Maintainer[26] = { 0 };
		unsigned char Version[26] = { 0 };
		unsigned char Version_Major;
		unsigned char Version_Minor;
		unsigned char Version_Patch;
	}_Version_;

}//end namespace

#endif // !VDMOCAPSDK_DATAREAD_DATATYPE_H

