/**
* nosleep
* ----------------------------------
* Copyright (c) 2017 Brandon Herzog
*
* Permission is hereby granted, free of charge, to any person
* obtaining a copy of this software and associated documentation
* files (the "Software"), to deal in the Software without
* restriction, including without limitation the rights to use,
* copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the
* Software is furnished to do so, subject to the following
* conditions:
*
* The above copyright notice and this permission notice shall be
* included in all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
* OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
* NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
* HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
* WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
* FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
* OTHER DEALINGS IN THE SOFTWARE.
*/

#include <WinSDKVer.h>
#ifdef _WIN32_WINNT
#undef _WIN32_WINNT
#endif // _WIN32_WINNT
#define _WIN32_WINNT _WIN32_WINNT_VISTA
#include <SDKDDKVer.h>

#define WIN32_LEAN_AND_MEAN
#define _CRT_NONSTDC_NO_WARNINGS
#include <Windows.h>

#include <conio.h>
#include <io.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const char VERSION[] = "1.1";
static const char AUTHOR[] = "Brandon Herzog";

static bool display_required;

static void help()
{
	fputs("usage: nosleep [--display] [--version] [--help]\n\n"
		"    --display    keep display active\n"
		"    --version    show version\n"
		"    --help       show help\n"
		"", stdout);
	exit(EXIT_SUCCESS);
}

static void version()
{
	printf("nosleep %s\nWritten by %s\n", VERSION, AUTHOR);
	exit(EXIT_SUCCESS);
}

static option_error(const char *unknown)
{
	fprintf(stderr, "nosleep: unknown option '%s'.\nSee 'nosleep --help'.", unknown);
	exit(EXIT_FAILURE);
}

static void parse_options(int argc, const char* const* argv)
{
	for (int i = 1; i < argc; ++i) {
		const char *arg = argv[i];
		if (strcmp(arg, "--display") == 0) {
			display_required = true;
		} else if (strcmp(arg, "--help") == 0) {
			help();
		} else if (strcmp(arg, "--version") == 0) {
			version();
		} else {
			option_error(arg);
		}
	}
}

int main(int argc, char **argv) 
{
	parse_options(argc, argv);

	EXECUTION_STATE state = ES_CONTINUOUS | ES_SYSTEM_REQUIRED | ES_AWAYMODE_REQUIRED;
	if (display_required) {
		state |= ES_DISPLAY_REQUIRED;
	}

	if (!SetThreadExecutionState(state)) {
		fputs("Unable to set thread execution state.\n", stderr);
		exit(EXIT_FAILURE);
	}

	if (isatty(fileno(stdin))) {
		fputs("Wide awake. Press any key to exit...\n", stdout);
		fflush(stdout);
		getch();
	} else {
		int ch;
		while ((ch = fgetc(stdin)) != EOF) {
			fputc(ch, stdout);
		}
	}

	exit(EXIT_SUCCESS);
}
