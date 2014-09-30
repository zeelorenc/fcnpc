/* =========================================
			
		FCNPC - Fully Controllable NPC
			----------------------

	- File: Address.cpp
	- Author(s): OrMisicL, Lorenc_

  =========================================*/

#include "Main.h"

#ifdef _WIN32
DWORD CAddress::FUNC_Logprintf_03ZR4 = 0x004875F0;
#else
DWORD CAddress::FUNC_Logprintf_03ZR4 = 0x80A7A90;
#endif

// Callbacks
DWORD CAddress::CALLBACK_CFilterScriptPool__OnPlayerGiveDamage = NULL;

// Functions
DWORD CAddress::FUNC_CreateNPC_RPC = NULL;
DWORD CAddress::FUNC_CPlayerPool__DeletePlayer = NULL;

DWORD CAddress::FUNC_CPlayer__SpawnForWorld = NULL;
DWORD CAddress::FUNC_CPlayer__Kill = NULL;
DWORD CAddress::FUNC_CPlayer__EnterVehicle = NULL;
DWORD CAddress::FUNC_CPlayer__ExitVehicle = NULL;

DWORD CAddress::FUNC_CConfig__GetValueAsInteger = NULL;

DWORD CAddress::FUNC_GetVehicleModelInfo = NULL;

// Variables
DWORD CAddress::VAR_ServerPtr = NULL;
DWORD CAddress::VAR_ConfigPtr = NULL;
DWORD CAddress::VAR_RakPeerPtr = NULL;
DWORD CAddress::VAR_ServerAuthentication = NULL;

void CAddress::Initialize(eSAMPVersion sampVersion)
{
	switch(sampVersion)
	{
		case SAMP_VERSION_03Z_R4:
		{
#ifdef _WIN32
			// Credits to therainycat
			CALLBACK_CFilterScriptPool__OnPlayerGiveDamage  =   0x48E7CF;

			FUNC_CPlayerPool__DeletePlayer					=	0x4661A0;  
			FUNC_CPlayer__Kill								=	0x480E10;
			FUNC_CPlayer__EnterVehicle						=	0x481510; 
			FUNC_CPlayer__ExitVehicle						=	0x481630; 
			FUNC_CPlayer__SpawnForWorld						=	0x483590; 
			FUNC_GetVehicleModelInfo						=	0x484AA0; 
			FUNC_CConfig__GetValueAsInteger					=	0x4862F0; 
			FUNC_CreateNPC_RPC								=	0x48C460; 
 		
			VAR_ServerAuthentication						=	0x4F3390;
#else
			// Credits to Lorenc_
			CALLBACK_CFilterScriptPool__OnPlayerGiveDamage  = 0x80B1367; 

			FUNC_CPlayerPool__DeletePlayer                  = 0x80CE870; 
			FUNC_CreateNPC_RPC                              = 0x80AE660; 
			FUNC_CPlayer__SpawnForWorld                     = 0x80CB160; 
			FUNC_CPlayer__Kill                              = 0x80C9620; 
			FUNC_CPlayer__EnterVehicle                      = 0x80CA360; 
			FUNC_CPlayer__ExitVehicle                       = 0x80CA4E0; 
			FUNC_CConfig__GetValueAsInteger                 = 0x809EFE0; 
			FUNC_GetVehicleModelInfo                        = 0x80D3A20; 

			VAR_ServerAuthentication                        = 0x819CB8C; 
#endif
			break;
		}
#ifndef _WIN32
		case SAMP_VERSION_03Z_R4_1000P:
		{
			CALLBACK_CFilterScriptPool__OnPlayerGiveDamage  = 0x80B1663; 

			FUNC_CPlayerPool__DeletePlayer                  = 0x80CE870; 
			FUNC_CreateNPC_RPC                              = 0x80AE660; 
			FUNC_CPlayer__SpawnForWorld                     = 0x80CB160; 
			FUNC_CPlayer__Kill                              = 0x80C9620; 
			FUNC_CPlayer__EnterVehicle                      = 0x80CA360; 
			FUNC_CPlayer__ExitVehicle                       = 0x80CA4E0; 
			FUNC_CConfig__GetValueAsInteger                 = 0x809EFE0; 
			FUNC_GetVehicleModelInfo                        = 0x80D3A30; 

			VAR_ServerAuthentication                        = 0x819C5AC; 
			break;
		}
#endif
	}
	VAR_ServerPtr									=	CSAMPFunctions::GetNetGame(); 
	VAR_ConfigPtr									=	CSAMPFunctions::GetConsole();
	VAR_RakPeerPtr                                  =   CSAMPFunctions::GetRakServer();
}