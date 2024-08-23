#pragma pack(2)
#pragma pack(2)
/*
**
** $VER: InfoText_mcc.h V15.3
** Copyright � 1997 Benny Kj�r Nielsen. All rights reserved.
**
*/

/*** Include stuff ***/

#ifndef INFOTEXT_MCC_H
#define INFOTEXT_MCC_H

#ifndef LIBRARIES_MUI_H
#pragma pack()
#pragma pack()
#include <libraries/mui.h>
#pragma pack(2)
#pragma pack(2)
#endif

#ifndef EXEC_TYPES_H
#pragma pack()
#pragma pack()
#include <exec/types.h>
#pragma pack(2)
#pragma pack(2)
#endif

#ifndef BKN_SERIAL
#define BKN_SERIAL 0xfcf70000
#endif

/*** MUI Defines ***/

#define MUIC_InfoText "InfoText.mcc"
#define InfoTextObject MUI_NewObject(MUIC_InfoText

/*** Methods ***/
#define MUIM_InfoText_TimeOut          (BKN_SERIAL | 0x101 )

/*** Attributes ***/
#define MUIA_InfoText_Contents         (BKN_SERIAL | 0x110 )
#define MUIA_InfoText_ExpirationPeriod (BKN_SERIAL | 0x111 )
#define MUIA_InfoText_FallBackText     (BKN_SERIAL | 0x112 )


#endif /* INFOTEXT_MCC_H */

#pragma pack()
#pragma pack()
