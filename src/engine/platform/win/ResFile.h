/**
\author		Korotkov Andrey aka DRON
\date		22.01.2010 (c)Korotkov Andrey

This file is a part of DGLE2 project and is distributed
under the terms of the GNU Lesser General Public License.
See "DGLE2.h" for more details.
*/

#pragma once

#include "..\Common.h"

extern HMODULE hModule;

class CResFile: public CInstancedObj, public IFile
{
	char		_acName[MAX_PATH];
	uint32		_ui32Pos,
				_ui32Size;
	bool		_bOpened;
	HGLOBAL		_hRes;
	LPVOID		_pData;

public:

	CResFile(uint uiInstIdx, WORD resId);
	~CResFile();

	DGLE2_RESULT DGLE2_API Read(void *pBuffer, uint uiCount, uint &uiRead);
	DGLE2_RESULT DGLE2_API Write(const void *pBuffer, uint uiCount, uint &uiWritten);
	DGLE2_RESULT DGLE2_API Seek(uint32 ui32Offset, E_FILE_SYSTEM_SEEK_FLAG eWay, uint32 &ui32Position);
	DGLE2_RESULT DGLE2_API GetSize(uint32 &ui32Size);
	DGLE2_RESULT DGLE2_API IsOpen(bool &bOpened);
	DGLE2_RESULT DGLE2_API GetName(char *pcName, uint &uiCharsCount);
	DGLE2_RESULT DGLE2_API GetPath(char *pcPath, uint &uiCharsCount);
	DGLE2_RESULT DGLE2_API Free();

	IDGLE2_BASE_IMPLEMENTATION(IFile)
};