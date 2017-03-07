#include <WinSDKVer.h>

#ifndef _WIN32_WINNT
#define _WIN32_WINNT _WIN32_WINNT_VISTA
#endif // !_WIN32_WINNT
#include <SDKDDKVer.h>

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif // !WIN32_LEAN_AND_MEAN

#include <windows.h>

#include <conio.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
	bool display = false;
	if (argc == 2 && strcmp(argv[1], "--display") == 0) {
		display = true;
	} else if (argc > 1) {
		printf("Unknown option.\n");
		printf("usage: %s [--display]\n", argv[0]);
		return 1;
	}

	EXECUTION_STATE state = ES_CONTINUOUS | ES_SYSTEM_REQUIRED | ES_AWAYMODE_REQUIRED;
	if (display) {
		state |= ES_DISPLAY_REQUIRED;
	}

	if (!SetThreadExecutionState(state)) {
		printf("Unable to set thread execution state.\n");
		return 1;
	}

	printf("Insomnia activated. Press any key to exit...\n");
	fflush(stdout);
	_getch();

	return 0;
}
