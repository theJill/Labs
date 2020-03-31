#include "pch.h"
#include <iostream>
#include <ctime>
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include "Winsock2.h"
#include <cmath>
#pragma comment (lib, "ws2_32.lib")
using namespace std;

struct NTP_packet	//пакет NTP
{
	CHAR head[4];
	DWORD32 RootDelay;
	DWORD32 RootDispersion;
	CHAR ReferenceIdentifier[4];	//идентификатор
	DWORD ReferenceTimestamp[2];	//32 бита  - секунды с 01.01.1900 00:00, 32 бита - доли секунды в 2^-32 единицах
	DWORD64 OriginateTimestamp;
	DWORD32 TransmitTimestamp[2];	//32 бита  - секунды с 01.01.1900 00:00, 32 бита - доли секунды в 2^-32 единицах
	DWORD32 KeyIdentifier;			//optional
	DWORD64 MessageDigest[2];		//optional
};


void UnixTimeToFileTime(time_t t, LPFILETIME pft)
{
	// Note that LONGLONG is a 64-bit value
	LONGLONG ll;

	ll = Int32x32To64(t, 10000000) + 116444736000000000;
	pft->dwLowDateTime = (DWORD)ll;
	pft->dwHighDateTime = ll >> 32;
}

void UnixTimeToSystemTime(time_t t, LPSYSTEMTIME pst)
{
	FILETIME ft;
	UnixTimeToFileTime(t, &ft);
	FileTimeToSystemTime(&ft, pst);
}

int main()
{
	int h = CLOCKS_PER_SEC;
	clock_t t = clock();
	int d = 613608 * 3600;
	time_t ttime;
	time(&ttime);

	WSAData wsaData;
	SOCKET s;
	SOCKADDR_IN server;
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = inet_addr("88.147.254.235");  
	server.sin_port = htons(123);

	NTP_packet out_buf, in_buf;
	ZeroMemory(&out_buf, sizeof(out_buf));
	ZeroMemory(&in_buf, sizeof(in_buf));
	out_buf.head[0] = 0x1B;
	out_buf.head[1] = 0x00;
	out_buf.head[2] = 4;
	out_buf.head[3] = 0xEC;

	int avgCorrection = 0;

	for (int i = 0; i < 5; i++) {
		try
		{
			if (WSAStartup(MAKEWORD(2, 0), &wsaData) != 0)
				throw WSAGetLastError();
			if ((s = socket(AF_INET, SOCK_DGRAM, NULL)) == INVALID_SOCKET)
				throw WSAGetLastError();
			int lenout = 0, lenin = 0, lensockaddr = sizeof(server);

			if ((lenout = sendto(s, (char*)&out_buf, sizeof(out_buf), NULL, (sockaddr*)&server, sizeof(server))) == SOCKET_ERROR)
				throw  WSAGetLastError();
			if ((lenin = recvfrom(s, (char*)&in_buf, sizeof(in_buf), NULL, (sockaddr*)&server, &lensockaddr)) == SOCKET_ERROR)
				throw  WSAGetLastError();

			in_buf.ReferenceTimestamp[0] = ntohl(in_buf.ReferenceTimestamp[0]) - d;
			in_buf.TransmitTimestamp[0] = ntohl(in_buf.TransmitTimestamp[0]) - d;
			in_buf.TransmitTimestamp[1] = ntohl(in_buf.TransmitTimestamp[1]);
			int ms = (int) 1000.0*((double)(in_buf.TransmitTimestamp[1]) / (double)0xffffffff);

			SYSTEMTIME systemTime;
			UnixTimeToSystemTime(in_buf.TransmitTimestamp[0], &systemTime);
			systemTime.wMilliseconds = ms;
			SYSTEMTIME localTime;
			GetLocalTime(&localTime);

			cout << "\n\n\t#" << i;
			cout << "\n\tServerTime:";
			cout << "\n\tDate: " << systemTime.wMonth << "." << systemTime.wDay << "." << systemTime.wYear;
			cout << "\n\tTime: " << systemTime.wHour + 3 << ":" << systemTime.wMinute << ":" << systemTime.wSecond << "." << systemTime.wMilliseconds;
			cout << "\n\tOSTime:";
			cout << "\n\tDate: " << localTime.wMonth << "." << localTime.wDay << "." << localTime.wYear;
			cout << "\n\tTime: " << localTime.wHour + 3 << ":" << localTime.wMinute << ":" << localTime.wSecond << "." << localTime.wMilliseconds;

			avgCorrection += abs(systemTime.wMilliseconds - localTime.wMilliseconds);

			cout << "\n\tDifference in milliseconds: " << (systemTime.wMilliseconds - localTime.wMilliseconds) << endl;
			if (closesocket(s) == INVALID_SOCKET)
				throw WSAGetLastError();
			if (WSACleanup() == SOCKET_ERROR)
				throw WSAGetLastError();

			Sleep(10000);
		}
		catch (int e)
		{
			cout << "error: " << e << endl;
		}
	}
	cout << "Average correction = " << avgCorrection / 10 << endl;
	system("pause");
	return 0;
}
