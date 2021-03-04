/** 
*	sergen cepoglu
* github.com/csergen
*/

#ifndef __MYLIB_H__
#define __MYLIB_H__

#if defined (_WIN32) || defined (_WIN64) || defined (__WINDOWS__) || defined (__CYGWIN__)
	#define _CRT_SECURE_NO_DEPRECATE
#elif defined (__linux__)
	#define _CRT_SECURE_NO_DEPRECATE
#elif defined (__APPLE__) || (__MACH__)
	#define _CRT_SECURE_NO_DEPRECATE
#elif defined (unix) || defined (__unix__) || defined (__unix)
	#define _CRT_SECURE_NO_DEPRECATE
#else
	#error Unknown
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define False 0x00
#define True	!False

#define DEBUG True

#define String char*


static const BUFFER = 0x3E8;

#if DEBUG == True
	#define Logi(_int_arg) printf("%d\n", _int_arg)
	#define Logc(_char_arg) printf("%c\n", _char_arg)
	#define Log(_format, ...) fprintf(stderr, _format, ##__VA_ARGS__)
#else
	#define Logi(void)
	#define Logc(void)
	#define Log(_format, ...)
#endif


#define Min(x, y) ((x) < (y) ? (True) : (False))

#define Max(x, y) ((x) > (y) ? (True) : (False))

#define Malloc(_type_arg, _size) malloc(sizeof(_type_arg)*(_size));
#define Calloc(_type_arg, _size) calloc(_size, sizeof(_type_arg));

#define Size(_array_arg) (sizeof(_array_arg) / sizeof((_array_arg)[0]))


// FILE HANDLING
FILE* Open(const String const _file_path, const String const _file_mode)
{
	return fopen(_file_path, _file_mode);
}

int Close(const FILE* const _file)
{
	int status = True;

	if (_file != NULL) 
		status = (fclose(_file) == NULL) ? True : False;
	
	if (status == True)
		free(_file);
	else
		Log("File is already closed.");

	return status;
}

int Write(const FILE* const _file, const String const _text)
{
	if (_file == NULL) {
		Log("File is not opened.");
		return False;
	} 
	
	fprintf(_file, "%s", _text);

	return True;
}

int Read(const FILE* const _file, const String const _destination)
{
	String line = Calloc(String, BUFFER);

	while (fscanf(_file, "%[^\n] ", line) == 1)
	{
		strcat(line, "\n");
		strcat(_destination, line);
	}
	
	free(line);

	if (_destination[0] == NULL)
		return False;

	return True;
}


#endif
