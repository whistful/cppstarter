#ifndef MYUTILS_H_INCLUDED
#define MYUTILS_H_INCLUDED

#include <iostream>
#include <string>

extern unsigned int gDbgPrint;

// enum of mask bits for gDbgPrint
enum dbgPrint_t
{
    DBGPRINT_NONE = 0,
    DBGPRINT_ARGS = 1 << 0,
    DBGPRINT_TEMP = 1 << 1,
    DBGPRINT_OBJECTCALLS = 1 << 2,
    DBGPRINT_CUDAKERNEL = 1 << 3,
    DBGPRINT_MATRIXDATA = 1<< 4,
    DBGPRINT_ANY = 0xFFFFFFFF
};

// Extract the hexvalue of a float
inline unsigned HexVal( float *pFloat )
{
    unsigned hexvalue = 0;
    unsigned *uPtr = (unsigned *) pFloat;
    hexvalue = *uPtr;
    return hexvalue;
}

// Simple utilities for printing and handling files

inline void PrintFlush()
{
    cout << flush;
}
inline void PrintInt( string s, int i )
{
    cout << s << i;
}
inline void PrintInt2( string s, int i, string t, int j )
{
    cout << s << i << t << j;
}
inline void PrintHex( string s, unsigned u )
{
    cout << s << std::hex << u;
}

 inline void PrintHexFloat( string s, float f )
{
    unsigned u = HexVal( &f );
    cout << s << std::hex << u;
}

inline void PrintFixed( string s, float f )
{
    cout << s << std::fixed << f;
}
inline void PrintFixed2( string s, float f )
{
    cout << s << std::fixed << std::setprecision(2) << f;
}
inline void PrintFixed10( string s, float f )
{
    cout << s << std::fixed << std::setprecision(10) << f;
}
inline void PrintScientific( string s, float f )
{
    cout << s << std::scientific << f;
}

inline void PrintEndl( void ) { cout << endl; }
inline void PrintString( string s ) { cout << s; }
inline void PrintStringEndl( string s) { cout << s << endl; }

// DbgPrint*() functions check gDbgPrint to see whether to print
inline void DbgPrintStringEndl(dbgPrint_t d, string s) 
{ 
    if (gDbgPrint & d) { cout << s << endl; }
}
inline void DbgPrintInt(dbgPrint_t d, string s, int i)
{
    if (gDbgPrint & d) { cout << s << i; }
}
inline void DbgPrintIntEndl(dbgPrint_t d, string s, int i)
{
    if (gDbgPrint & d) { cout << s << i << endl; }
}
inline void DbgPrint2IntsEndl(dbgPrint_t d, string s, int i, int j)
{
    if (gDbgPrint & d) { cout << s << i << ',' << j << endl; }
}
inline void DbgPrintEndl(dbgPrint_t d)
{ 
    if (gDbgPrint & d) { cout << endl; }
}

#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) > (b) ? (a) : (b))

#define ASSERTNOTREACHED() (assert(0))


#endif // MYUTILS_H_INCLUDED
