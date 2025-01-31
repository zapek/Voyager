/**************************************************************************

  =======================
  The Voyager Web Browser
  =======================

  Copyright (C) 1995-2003 by
   Oliver Wagner <owagner@vapor.com>
   All Rights Reserved

  Parts Copyright (C) by
   David Gerber <zapek@vapor.com>
   Jon Bright <jon@siliconcircus.com>
   Matt Sealey <neko@vapor.com>

**************************************************************************/


/*
**
** $Id: mbx_cross.c,v 1.12 2003/07/06 16:51:34 olli Exp $
**
*/

#include "voyager.h"
#include "classes.h"
#include "prefs.h"
#include "mui_func.h"

#if USE_STB_NAV

static struct MUI_CustomClass *lcc;

#define CROSS_XS 24
#define CROSS_YS 24

static unsigned char crossdata[CROSS_XS*CROSS_YS]={
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x00,0x00,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x00,0x00,0x00,0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x00,0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x00,0x00,0x01,0x01,0x01,0x01,0x01,0x00,0x00,0x01,0x01,0x01,0x01,0x01,
	0x00,0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x00,0x00,0x00,0x01,0x01,0x01,0x01,0x01,
	0x00,0x00,0x01,0x01,0x01,0x01,0x01,0x00,0x00,0x00,0x01,0x01,0x01,0x01,0x01,0x00,0x00,
	0x00,0x00,0x01,0x01,0x01,0x01,0x00,0x00,0x00,0x00,0x01,0x01,0x01,0x01,0x00,0x00,0x00,
	0x00,0x01,0x01,0x01,0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x01,0x00,0x00,0x00,0x00,0x00,
	0x00,0x01,0x01,0x01,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x01,0x00,
	0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x01,0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x01,0x00,
	0x00,0x00,0x00,0x01,0x01,0x01,0x01,0x00,0x00,0x00,0x00,0x01,0x01,0x01,0x01,0x00,0x00,
	0x00,0x00,0x01,0x01,0x01,0x01,0x01,0x00,0x00,0x00,0x01,0x01,0x01,0x01,0x01,0x00,0x00,
	0x01,0x01,0x01,0x01,0x01,0x00,0x00,0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x00,0x00,
	0x01,0x01,0x01,0x01,0x01,0x00,0x00,0x01,0x01,0x01,0x01,0x01,0x00,0x00,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x00,0x00,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x00,0x00,0x00,0x00,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x00,0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01
};

struct Data
{
	int dirs;
};

static void da( RastPort_p rp, int pen, int dxp, int dyp, int sx, int sy, int w, int h )
{
	int x, y;

	SetAPen( rp, pen );

	w += sx;
	h += sy;

	for( x = sx; x < w; x++ )
	{
		for( y = sy; y < h; y++ )
		{
			if( !crossdata[ x + y * CROSS_XS ] )
				WritePixel( rp, dxp + x, dyp + y );
		}
	}
}

#define COLOR_YES 0xffff00
#define COLOR_NO 0x9da8dd


DECMMETHOD( Draw )
{
	GETDATA;

	DOSUPER;

	if( msg->flags & MADF_DRAWOBJECT )
	{
		da( _rp( obj ), data->dirs & CROSSDIR_NORTH ? COLOR_YES : COLOR_NO, _mleft( obj ), _mtop( obj ), 7, 0, 10, 9 ); 
		da( _rp( obj ), data->dirs & CROSSDIR_SOUTH ? COLOR_YES : COLOR_NO, _mleft( obj ), _mtop( obj ), 7, 15, 10, 9 ); 
		da( _rp( obj ), data->dirs & CROSSDIR_EAST ? COLOR_YES : COLOR_NO, _mleft( obj ), _mtop( obj ), 15, 8, 9, 10 ); 
		da( _rp( obj ), data->dirs & CROSSDIR_WEST ? COLOR_YES : COLOR_NO, _mleft( obj ), _mtop( obj ), 0, 8, 9, 10 ); 
	}

	return(0);
}

DECMMETHOD( AskMinMax )
{
	struct MUI_MinMax *mmx;

	DOSUPER;

	mmx = msg->MinMaxInfo;
	mmx->MinWidth += 25;
	mmx->MinHeight += 25;

	mmx->DefWidth += 25;
	mmx->DefHeight += 25;

	mmx->MaxWidth += 25;
	mmx->MaxHeight += 25;

	return( 0 );
}

DECSMETHOD( Cross_SetDir )
{
	GETDATA;

	if( data->dirs != msg->newdir )
	{
		data->dirs = msg->newdir;
		MUI_Redraw( obj, MADF_DRAWOBJECT );
	}

	return( 0 );
}

BEGINMTABLE
DEFMMETHOD( Draw )
DEFMMETHOD( AskMinMax )
DEFSMETHOD( Cross_SetDir )
ENDMTABLE

int create_crossclass( void )
{
	D( db_init, bug( "initializing..\n" ) );
	
	if( !( lcc = ( struct MUI_CustomClass * )MUI_CreateCustomClass( NULL, MUIC_Area, NULL, sizeof( struct Data ), DISPATCHERREF ) ) )
	{
		return( FALSE );
	}

#ifdef VDEBUG
	if( MUIMasterBase->lib_Version >= 20 )
		lcc->mcc_Class->cl_ID = "crossclass";
#endif

	return( TRUE );
}

void delete_crossclass( void )
{
	if( lcc )
	{
		MUI_DeleteCustomClass( lcc );
		lcc = NULL; //TOFIX!! (I think)
	}
}

APTR getcrossclass( void )
{
	return( lcc->mcc_Class );
}

#endif
