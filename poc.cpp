#include <Windows.h>
#include <wchar.h>
#include <iostream>
#include <clfsw32.h>
#include <Clfsmgmtw32.h>
#pragma comment(lib, "clfsw32.lib")

int main() {


	wchar_t szLogPath[] = L"LOG:C:\\Users\\Public\\MyLog::Stream1";

	//wchar_t szLogPath[] = L"??\\LOG:\\HarddiskVolume0\\MyLog";

	//wchar_t szLogPath[] = L"LOG:\\\\?\\GLOBALROOT\\Device\\HarddiskVolume0\\Users\\Public\\MysssLog";

	//\\\\?\\GLOBALROOT\\Device\\HarddiskVolume0

	//SECURITY_ATTRIBUTES psaLogFile = {};


	HANDLE   hLog = CreateLogFile(szLogPath, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ, NULL, OPEN_ALWAYS, NULL);

	if (INVALID_HANDLE_VALUE == hLog)
	{
		printf("error=%d\n", GetLastError());

		return 1;
	}

	if (!RegisterManageableLogClient(hLog, 0))
		printf("error=%d\n", GetLastError());


	printf("hLog=%p\n", hLog);

	CLFS_INFORMATION pinfoBuffer = {};


	//ULONG infoSize = sizeof(pinfoBuffer);

	ULONG infoSize = 0x110;

	//	system("pause");
	DWORD dwRet = GetLogFileInformation(hLog, &pinfoBuffer, &infoSize);



	if (dwRet == NULL)
	{
		printf("error=%d\n", GetLastError());

		return 1;
	}

	printf("dwRet=%08x\n", dwRet);



	return 0;
}
