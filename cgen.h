/**
	*	sergen cepoglu
	* github.com/csergen
	*/

#pragma once
#ifndef __CGEN_H__
#define __CGEN_H__

#if defined ( _WIN32 ) || defined ( _WIN64 )
#define _CRT_SECURE_NO_DEPRECATE
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdarg.h>
#include <stdint.h>
#include <string.h>

#ifdef _DEBUG
#define Log(...) printf( __VA_ARGS__ )
#else
#define Log(...) printf()
#endif // DEBUG


/* COLORS */
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

/* DATA TYPES REDEFINE */
#define String char*

#define I8  int8_t				// [ 0, 2^8	 )
#define I16 int16_t				// [ 0, 2^16 )
#define I32 int32_t				// [ 0, 2^32 )
#define I64 int64_t				// [ 0, 2^64 )

#define U8  uint8_t				// [ -2^8 , 2^8  )
#define U16 uint16_t			// [ -2^16, 2^16 )
#define U32 uint32_t			// [ -2^32, 2^32 )
#define U64 uint64_t			// [ -2^64, 2^64 )


/* MACROS */
#define Malloc(type_, size_) malloc( sizeof(type_) * ( size_ ) )
#define Calloc(type_, size_) calloc( size_, sizeof(type_) )
#define Free(arg_)					 free( arg_ )

#define Size(arg_) ( sizeof(arg_) / sizeof((arg_)[0]) )

#define Min(x, y) ((x) < (y) ? (true) : (false))
#define Max(x, y) ((x) > (y) ? (true) : (false))

#define For(start_, end_, inc_) for (int i = start_; i < end_; i += inc_)

/* FILE HANDLING FUNCTIONS */
FILE* Open(const String const _file_path, const String const _file_mode)
{
	return fopen(_file_path, _file_mode);
}

int Close(const FILE* const _file)
{
	int status = true;

	if (_file != NULL)
		status = (fclose(_file) == NULL) ? true : false;

	if (status)
		free(_file);
	else
		printf("File is already closed\n");

	return status;
}

int Write(const FILE* const _file, const String const _text)
{
	if (_file == NULL) {
		printf("File is not opened\n");
		return false;
	}

	fprintf(_file, "%s", _text);

	return true;
}

int Read(const FILE* const _file, const String const _destination)
{
	const BUFFER = 0x3E8;

	String line = Calloc(String, BUFFER);

	while (fscanf(_file, "%[^\n] ", line) == 1)
	{
		strcat(line, "\n");
		strcat(_destination, line);
	}

	free(line);

	if (_destination[0] == NULL)
		return false;

	return true;
}


#endif
