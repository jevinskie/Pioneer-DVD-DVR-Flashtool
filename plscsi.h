/**
**  plscsi.h
**  Saturday. September 21, 2002
**
**  Help link together the *.c* of ../plscsi/.
**
**  See http://members.aol.com/plscsi/
**/

/**
**  Compile at most once.
**/

#pragma once

/**
**  Link as C, not C++.
**/

#ifdef __cplusplus
extern "C" {
#endif

/**
**  Link with standard C libraries.
**/

typedef int EXIT_INT;
typedef int INT;
typedef unsigned int UINT;

#define INT_M1 (-1)
#define INT_MOST_NEG INT_MIN
#define INT_MOST_POS INT_MAX

#define CALLOC calloc

#define FREAD fread
#define FWRITE fwrite
#define MEMCMP memcmp
#define MEMMOVE memmove
#define MEMSET memset

#define TO_VOID_P(II) ((void *)(II))
#define TO_INT(VO) ((INT)(VO))

/**
**  List some different ways to copy data.
**/

#define X0_DATA_NOT 0x0
#define X1_DATA_IN 0x1  /* read = copy IN to host from device */
#define X2_DATA_OUT 0x2 /* write = copy OUT from host to device */

/**
**  Distinguish one negative return code from another, in accord with
**  an anonymous convention seen used in the Scsi storage industry.
**/

#define X2000_DIFFERENCE 0x2000 /* data copied In != data copied Out */
#define X0100_RESIDUE 0x0100    /* copied less than max data In or Out */
#define X0002_SENSE 0x0002      /* did copy In sense data */

/**
**  Choose which .cpp to link.
**/

#ifdef __linux__
#define SGIO SGIO
#else
#error only Linux supported, sorry
#endif

/**
**  Name some struct's.
**/

typedef struct Aspi Aspi;
typedef struct CommandLine CommandLine;
typedef struct Scsi Scsi;
typedef struct ScsiCommandLine ScsiCommandLine;
typedef struct Sgio Sgio;
typedef struct Sptx Sptx;
typedef struct Stuc Stuc;

/**
**  Link with "scsi.cpp".
**/

extern Scsi *newScsi(void);
extern void scsiSetErr(Scsi *, FILE *);
extern void scsiClose(Scsi *);
extern int scsiOpen(Scsi *, char const *);
extern int scsiLimitSense(Scsi *, int);
extern int scsiLimitSeconds(Scsi *, INT, INT);
extern INT scsiSay(Scsi *, char const *, int, char *, INT, int);
extern INT scsiGetLength(Scsi *, INT);
extern int scsiGetSense(Scsi *, char *, int, int);
extern int scsiReadName(Scsi *, char *, int);
extern int scsiSwallowArg(Scsi *, char const *);

/**
**  Link with "sgio.cpp".
**/

#ifndef SGIO
#error must use SGIO
#endif

#ifdef SGIO
extern Sgio *newSgio(void);
extern void sgioSetErr(Sgio *, FILE *);
extern void sgioClose(Sgio *);
extern int sgioOpen(Sgio *, char const *);
extern int sgioLimitSense(Sgio *, int);
extern int sgioLimitSeconds(Sgio *, int, int);
extern int sgioSay(Sgio *, char const *, int, char *, int, int);
extern int sgioGetLength(Sgio *, int);
extern int sgioGetSense(Sgio *, char *, int, int);
extern int sgioReadName(Sgio *, char *, int);
extern int sgioSwallowArg(Sgio *, char const *);
#endif

/**
**  Finish linking as C, not C++.
**/

#ifdef __cplusplus
}
#endif

/* end of file */
