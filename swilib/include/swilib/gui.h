#pragma once

/**
 * @addtogroup GUI
 * @brief GUI-related stuff.
 * 
 * Usage: `#include <swilib.h>` or `#include <swilib/gui.h>`
 * @{
 */

#ifndef __IN_SWILIB__
#include "base.h"
#include "gbs.h"
#include "wstring.h"
#include "image.h"
#include "csm.h"
#endif

__swilib_begin

typedef struct RECT RECT;
typedef struct GUI GUI;
typedef struct GUI_RAM GUI_RAM;
typedef struct GUI_MSG GUI_MSG;
typedef struct GUI_METHODS GUI_METHODS;
typedef struct DRWOBJ DRWOBJ;
typedef struct LCDLAYER LCDLAYER;
typedef struct LCDLAYER_LIST LCDLAYER_LIST;
typedef struct RAP_LCDLAYER_LIST RAP_LCDLAYER_LIST;

typedef int (*KeybMsgHookProc)(int submsg, int msg);
typedef void (*GUI_TimerProc)(void *gui);

/**
 * Colors indexes in the .col
 * */
enum ThemePeletteColorID {
	PC_FOREGROUND				= 100,
	PC_BACKGROUND				= 101,
	PC_HEADERFOREGROUND			= 102,
	PC_HEADERBACKGROUND			= 103,
	PC_SELECTFOREGROUND			= 115,
	PC_SELECTBACKGROUND			= 116,
	PC_SELECTBORDER				= 117,
	PC_SELECTSHADOW				= 118,
	PC_LIGHTTEXTFOREGROUND		= 122,
	PC_LIGHTTEXTBACKGROUND		= 123,
	PC_SCROLLBARSLIDER			= 127,
	PC_SCROLLBAR				= 128,
	PC_WINDOWFOREGROUND			= 129,
	PC_WINDOWBACKGROUND			= 130,
	PC_BORDER					= 133,
	PC_BORDERSHADOW				= 134,
	PC_POPUPSELECTFOREGROUD		= 135,
	PC_POPUPSELECTBACKGROUD		= 136,
	PC_PROGRESSBACKGROUND		= 138,
	PC_PROGRESSFOREGROUND		= 139,
	PC_PROGRESSBORDER			= 140,
};

/**
 * Font IDs.
 * */
enum SystemFontID {
#ifdef ELKA
	FONT_LARGE					= 0,
	FONT_LARGE_BOLD				= 1,
	FONT_LARGE_ITALIC			= 2,
	FONT_LARGE_ITALIC_BOLD		= 3,
	FONT_MEDIUM					= 4,
	FONT_MEDIUM_BOLD			= 5,
	FONT_MEDIUM_ITALIC			= 6,
	FONT_MEDIUM_ITALIC_BOLD		= 7,
	FONT_NUMERIC_SMALL			= 8,
	FONT_NUMERIC_SMALL_BOLD		= 9,
	FONT_NUMERIC_XSMALL			= 8,
	FONT_SMALL					= 8,
	FONT_SMALL_BOLD				= 9,
	FONT_SMALL_ITALIC			= 10,
	FONT_SMALL_ITALIC_BOLD		= 11,
	FONT_NUMERIC_LARGE			= 0,
	FONT_NUMERIC_MEDIUM			= 4,
#elif defined(NEWSGOLD)
	FONT_LARGE					= 0,
	FONT_LARGE_BOLD				= 1,
	FONT_LARGE_ITALIC			= 2,
	FONT_LARGE_ITALIC_BOLD		= 3,
	FONT_MEDIUM					= 4,
	FONT_MEDIUM_BOLD			= 5,
	FONT_MEDIUM_ITALIC			= 6,
	FONT_MEDIUM_ITALIC_BOLD		= 7,
	FONT_NUMERIC_SMALL			= 8,
	FONT_NUMERIC_SMALL_BOLD		= 9,
	FONT_NUMERIC_XSMALL			= 10,
	FONT_SMALL					= 11,
	FONT_SMALL_BOLD				= 12,
	FONT_SMALL_ITALIC			= 13,
	FONT_SMALL_ITALIC_BOLD		= 14,
	FONT_NUMERIC_LARGE			= 15,
	FONT_NUMERIC_MEDIUM			= 16,
#else
	FONT_LARGE					= 0,
	FONT_LARGE_BOLD				= 1,
	FONT_LARGE_ITALIC			= 0,
	FONT_LARGE_ITALIC_BOLD		= 1,
	FONT_MEDIUM					= 2,
	FONT_MEDIUM_BOLD			= 3,
	FONT_MEDIUM_ITALIC			= 2,
	FONT_MEDIUM_ITALIC_BOLD		= 3,
	FONT_NUMERIC_SMALL			= 4,
	FONT_NUMERIC_SMALL_BOLD		= 5,
	FONT_NUMERIC_XSMALL			= 6,
	FONT_SMALL					= 7,
	FONT_SMALL_BOLD				= 8,
	FONT_SMALL_ITALIC			= 7,
	FONT_SMALL_ITALIC_BOLD		= 8,
	FONT_NUMERIC_LARGE			= 9,
	FONT_NUMERIC_MEDIUM			= 10,
#endif
};

/**
 * UTF-16 control chars for #DrawString, #DrawScrollString and standart UI.
 * */
enum UnicodeControlChars {
	UTF16_UNDERLINE			= 0xE001, /**< Set TEXT_UNDERLINE */
	UTF16_NO_UNDERLINE		= 0xE002, /**< Clear TEXT_UNDERLINE */

	UTF16_BG_INVERTION		= 0xE003, /**< Set TEXT_INVERT */
	UTF16_BG_INVERTION2		= 0xE005, /**< Set TEXT_INVERT2 */
	UTF16_NO_INVERTION		= 0xE004, /**< Clear TEXT_INVERT | TEXT_INVERT2 */

	UTF16_TEXT_COLOR_RGBA	= 0xE006, /**< Example: { UTF16_TEXT_COLOR_RGBA, 0xRRGG, 0xBBAA } */
	UTF16_BG_COLOR_RGBA		= 0xE007, /**< Example: { UTF16_BG_COLOR_RGBA, 0xRRGG, 0xBBAA } */

	UTF16_TEXT_COLOR		= 0xE008, /**< Example: { UTF16_TEXT_COLOR, PC_FOREGROUND } */
	UTF16_BG_COLOR			= 0xE009, /**< Example: { UTF16_BG_COLOR, PC_BACKGROUND } */

	UTF16_FONT_RESET		= 0xE010, /**< Reset font to the default */

	UTF16_FONT_SMALL		= 0xE012, /**< Set font ot FONT_SMALL */
	UTF16_FONT_SMALL_BOLD	= 0xE013, /**< Set font ot FONT_SMALL_BOLD */

	UTF16_FONT_MEDIUM		= 0xE014, /**< Set font ot FONT_MEDIUM */
	UTF16_FONT_MEDIUM_BOLD	= 0xE015, /**< Set font ot FONT_MEDIUM_BOLD */

	UTF16_FONT_LARGE_BOLD	= 0xE017, /**< Set font ot FONT_LARGE_BOLD */
	UTF16_FONT_LARGE		= 0xE018, /**< Set font ot FONT_LARGE */

	UTF16_FONT_UNK0			= 0xE011, /**< Set font ot FONT_SMALL */
	UTF16_FONT_UNK1			= 0xE016, /**< Set font ot FONT_LARGE_BOLD */
	UTF16_FONT_UNK2			= 0xE019, /**< Set font ot FONT_SMALL */
	UTF16_FONT_UNK3			= 0xE01A, /**< Set font ot FONT_SMALL_BOLD */
	UTF16_FONT_UNK4			= 0xE01B, /**< Set font ot FONT_SMALL */

	UTF16_ALIGN_NONE		= 0xE01C, /**< Clear TEXT_ALIGNLEFT | TEXT_ALIGNMIDDLE | TEXT_ALIGNRIGHT */
	UTF16_ALIGN_RIGHT		= 0xE01D, /**< Set TEXT_ALIGNRIGHT */
	UTF16_ALIGN_LEFT		= 0xE01E, /**< Set TEXT_ALIGNLEFT */
	UTF16_ALIGN_CENTER		= 0xE01F, /**< Set TEXT_ALIGNMIDDLE */
};

/**
 * Flags for the #DrawString and #DrawScrollString
 * */
enum TextAttributesFlags {
	TEXT_ALIGNLEFT		= 1,	/**< Text align: LEFT */
	TEXT_ALIGNMIDDLE	= 2,	/**< Text align: CENTER */
	TEXT_ALIGNRIGHT		= 4,	/**< Text align: RIGHT */
	TEXT_UNDERLINE		= 8,	/**< Underline text */
	TEXT_INVERT			= 16,	/**< Invert color and background of the text */
	TEXT_OUTLINE		= 32,	/**< Add an outline to each character in the text */
	TEXT_PASSWORD		= 64,	/**< Replace all character to the `*` */
	TEXT_NOFORMAT		= 128,	/**< Disable text formatting using #UnicodeControlChars */
	TEXT_INVERT2		= 256,	/**< Invert color and background of the text */
};

/**
 * Flags for the #DrawLine
 * */
enum LineDrawingFlags {
	LINE_DOTTED		= 1,		/**< Dotted line */
	LINE_DOTTED2	= 2,		/**< Dotted line (?) */
};

/**
 * Flags for the #DrawRectangle and others
 * */
enum RectDrawingFlags {
	RECT_DOT_OUTLINE	= 1,	/**< Border is dotted */
	RECT_FILL_WITH_PEN	= 2,	/**< File rectangle with the same color as the border */
	RECT_DRAW_INVERT	= 4,	/**< Invert previously painted content in area within the rectangle */
};

/**
 * Types of the rectangle filling.
 * */
enum DrwObjRectFillTypeID {
	DRWOBJ_RECT_FILL_TYPE_NONE		= 0,	/**< Transparent */
	DRWOBJ_RECT_FILL_TYPE_BRUSH		= 1,	/**< Fill rectangle with brush color */
	DRWOBJ_RECT_FILL_TYPE_PEN		= 2,	/**< Fill rectangle with pen color */
	DRWOBJ_RECT_FILL_TYPE_PATTERN	= 9,	/**< Fill rectangle with brush color using pattern */
};

/**
 * Types of the ellipse sections.
 * */
enum DrwObjEllipseSectionID {
	DRWOBJ_ELLIPSE_SECTION_UPPER_RIGHT = 1,
	DRWOBJ_ELLIPSE_SECTION_UPPER_LEFT,
	DRWOBJ_ELLIPSE_SECTION_LOWER_LEFT,
	DRWOBJ_ELLIPSE_SECTION_LOWER_RIGHT,
};

/**
 * Key event types (onKey).
 * */
enum GbsKeyEventID {
	KEY_DOWN	= 0x193, /**< Key down */
	KEY_UP		= 0x194, /**< Key up */
	LONG_PRESS	= 0x195, /**< Key longpress */
// 196 - sent 1 second after last key release, but not always?
// 197 - ? unknown kbd msg
// 198 - ? unknown kbd msg
};

/**
 * Key scancodes (onKey).
 * Keypad buttons passed '*', '#', '0'-'9' as charcode.
 * */
enum GbsKeyCodeID {
#ifdef NEWSGOLD
	LEFT_SOFT			= 0x01, /**< Left softkey */
	RIGHT_SOFT			= 0x04, /**< Right softkey */
	GREEN_BUTTON		= 0x0B, /**< Green button */
	RED_BUTTON			= 0x0C, /**< Red button */
	VOL_UP_BUTTON		= 0x0D, /**< Volume+ */
	VOL_DOWN_BUTTON		= 0x0E, /**< Volume- */
	UP_BUTTON			= 0x3B, /**< UP navkey */
	DOWN_BUTTON			= 0x3C, /**< DOWN navkey */
	LEFT_BUTTON			= 0x3D, /**< LEFT navkey */
	RIGHT_BUTTON		= 0x3E, /**< RIGHT navkey */
	ENTER_BUTTON		= 0x1A, /**< CENTER navkey */
	#ifdef ELKA
	POC_BUTTON			= 0x15, /**< Direct line key (EL71) */
	MEDIA_BUTTON		= 0x11, /**< Player key */
	EL_PLAY_BUTTON		= 0x1D, /**< Player key (EL71) */
	#else
	INTERNET_BUTTON		= 0x11, /**< Browser key */
	#endif
	PLAY_BUTTON			= 0x15, /**< Player key */
	CAMERA_BUTTON		= 0x14, /**< Camera key */
	PTT_BUTTON			= 0x27, /**< PTT key */
#else
	LEFT_SOFT			= 0x01, /**< Left softkey */
	RIGHT_SOFT			= 0x04, /**< Right softkey */
	GREEN_BUTTON		= 0x0B, /**< Green button */
	RED_BUTTON			= 0x0C, /**< Red button */
	#ifdef X75
	VOL_UP_BUTTON		= 0x14, /**< Volume+ */
	VOL_DOWN_BUTTON		= 0x15, /**< Volume- */
	#else
	VOL_UP_BUTTON		= 0x0D, /**< Volume+ */
	VOL_DOWN_BUTTON		= 0x0E, /**< Volume- */
	#endif
	UP_BUTTON			= 0x3B, /**< UP navkey */
	DOWN_BUTTON			= 0x3C, /**< DOWN navkey */
	LEFT_BUTTON			= 0x3D, /**< LEFT navkey */
	RIGHT_BUTTON		= 0x3E, /**< RIGHT navkey */
	ENTER_BUTTON		= 0x1A, /**< CENTER navkey */
	INTERNET_BUTTON		= 0x11, /**< Browser key */
	PTT_BUTTON			= 0x27, /**< PTT key */
#endif
};

/**
 * Return codes for global KeyHook.
 * */
enum KeyHookReturnCode {
	KEYHOOK_NEXT			= 0, /**< Process key to next keyhook and to gui */
	KEYHOOK_NEXT_NOT2GUI	= 1, /**< Process key only to next keyhook, not to gui */
	KEYHOOK_BREAK			= 2, /**< Break process and exit without processing in gui */
	KEYHOOK_ENDQ			= 3, /**< Break process and exit with or not processing in gui (selected by prev values 0/1) */
};

/**
 * GUI state.
 * */
enum CsmGuiState {
	CSM_GUI_STATE_CLOSED		= 0, /**< GUI closed */
	CSM_GUI_STATE_UNFOCUSED		= 1, /**< GUI not in focus */
	CSM_GUI_STATE_FOCUSED		= 2, /**< GUI in focus */
};

/**
 * Drawing object.
 * */
struct DRWOBJ {
	char dummy[0x24];
};

/**
 * Rectangle region.
 * */
struct RECT {
	short x;	/**< left */
	short y;	/**< top */
	short x2;	/**< right */
	short y2;	/**< bottom */
};

/**
 * GUI GBS message for onKey callback.
 * */
struct GUI_MSG {
	char zero;
	char unk1;
	short keys;
	GBS_MSG *gbsmsg;
};

/**
 * GUI callbacks.
 * */
struct GUI_METHODS {
	void (*onRedraw)(GUI *);								/**< Method for the drawing */
	void (*onCreate)(GUI *, malloc_func_t);					/**< Constructor */
	void (*onClose)(GUI *, mfree_func_t);					/**< Destructor */
	void (*onFocus)(GUI *, malloc_func_t, mfree_func_t);	/**< GUI is in focus */
	void (*onUnfocus)(GUI *, mfree_func_t);					/**< GUI not in focus */
	int (*onKey)(GUI *, GUI_MSG *);							/**< Keyboard handler */
	void *unk0;
	void (*onDestroy)(void *, mfree_func_t);				/**< Free resources */
	int (*method8)();
	int (*method9)();
	void *unk1;
};

/**
 * GUI RAM representation.
 */
struct GUI_RAM {
	GUI_RAM *next;
	GUI_RAM *prev;
	GUI *gui;
	int id;
};

/**
 * GUI description and state.
 * */
#ifdef NEWSGOLD
struct GUI {
	RECT *canvas;					/**< Region on the screen. */
#ifdef SWILIB_MODERN
	GUI_METHODS *methods;			/**< Pointer to the #GUI_METHODS, union with #GUI.methods. */
#else
	void *methods;
#endif
	void *definition;
	char state;						/**< GUI state, see #CsmGuiState */
	char unk2;
	char unk3;
	char unk4;
	int color1;
	int color2;
	LLQ item_ll;
	int unk5;
	char unk6;
	char unk7;
	char unk8;
	char unk9;
	int unk10;
	int flag30;
};
#else
struct GUI {
	RECT *canvas;					/**< Region on the screen. */
#ifdef SWILIB_MODERN
	GUI_METHODS *methods;			/**< Pointer to the #GUI_METHODS, union with #GUI.methods. */
#else
	void *methods;
#endif
	void *definition;
	char state;						/**< GUI state, see #CsmGuiState */
	char unk2;
	char unk3;
	char unk4;
	int color1;
//	int color2;
	LLQ item_ll;
	int unk5;
	char unk6;
	char unk7;
	char unk8;
	char unk9;
	int unk10;
	int flag30;
};
#endif

/**
 * LCD drawing layer.
 * */
struct LCDLAYER {
	int w;					/**< Layer width */
	int h;					/**< Layer height */
	RECT invalidate;		/**< Layer region to invalidate */
	RECT rect;				/**< Rectangle region on the LCD */
	void *buffer;			/**< Layer buffer */
	void *_unk2;
	uint8_t depth;			/**< Color depth */
#ifdef ELKA
	char _unk3[3];
	int _unk4[7];
	int redraw_requested;	/**< 1 when redraw is requested */
	char unk5[86];
#elif defined(NEWSGOLD)
	char _unk3[3];
	int _unk4[5];
	int redraw_requested;	/**< 1 when redraw is requested */
	char unk5[88];
#else
	// TODO
#endif
};

/**
 * LCD drawing layer container.
 * */
struct LCDLAYER_LIST {
	LCDLAYER *layer;
	malloc_func_t malloc_func;
	mfree_func_t mfree_func;
	uint32_t unk;
};

/**
 * LCD drawing layer container (RAP).
 * */
struct RAP_LCDLAYER_LIST {
	LCDLAYER *layer;
	int unk1[3];
	short cepid;
	short unk2;
	int unk3;
	void *app;
	int unk4;
};

/**
 * @name Information functions
 * @{
 * */

/**
 * Phone screen width.
 * @return width in px
 * */
__swi_begin(0x8188)
int ScreenW(void)
__swi_end(0x8188, ScreenW, ());

/**
 * Phone screen height.
 * @return height in px
 * */
__swi_begin(0x8189)
int ScreenH(void)
__swi_end(0x8189, ScreenH, ());

/**
 * Header height (iconbar).
 * @return height in px
 * */
__swi_begin(0x818A)
int HeaderH(void)
__swi_end(0x818A, HeaderH, ());

/**
 * Softkeys height.
 * @return height in px
 * */
__swi_begin(0x818B)
int SoftkeyH(void)
__swi_end(0x818B, SoftkeyH, ());

/**
 * Pointer to the last pressed key.
 * @return pointer to the keycode value
 * ```C
 * int last_pressed_keycode = *RamPressedKey();
 * ```
 * @note Useless for ELF's, use onKey callback in the GUI.
 * */
__swi_begin(0x80DF)
char *RamPressedKey()
__swi_end(0x80DF, RamPressedKey, ());

/**
 * Pointer to the current LCD buffer.
 * Useful for screenshots, but not for direct rendering.
 * @return RGB565 screen buffer
 * */
__swi_begin(0x80E0)
void *RamScreenBuffer()
__swi_end(0x80E0, RamScreenBuffer, ());

/** @} */

/**
 * @name Color utils
 * @{
 * */

/**
 * Get color from the phone theme.
 * @param index		color index in .col, see #ThemePeletteColorID
 * @return pointer to the char[4] array (RR, GG, BB, AA)
 * */
__swi_begin(0x12E)
char *GetPaletteAdrByColorIndex(int index)
__swi_end(0x12E, GetPaletteAdrByColorIndex, (index));

/**
 * Get color from the phone theme.
 * @param index			color index in .col, see #ThemePeletteColorID
 * @param[out] color	pointer to the char[4] array for RGBA
 * */
__swi_begin(0x12F)
void getRGBcolor(int index, void *color)
__swi_end(0x12F, getRGBcolor, (index, color));

/**
 * Copy color from the theme palette.
 * @param src_color			color returned by #GetPaletteAdrByColorIndex
 * @param[out] dst_color	pointer to the char[4] array for RGBA
 * 
 * ```C
 * memcpy(src_color, dst_color, 4); // functional analog
 * ```
 * */
__swi_begin(0x130)
void getRGBbyPaletteAdr(const void *src_color, void *dst_color)
__swi_end(0x130, getRGBbyPaletteAdr, (src_color, dst_color));

/**
 * Initialize color by individual values.
 * @param a				alpha channel 0-100
 * @param r, g, b		colors 0-255
 * @param dst			pointer to the char[4] array for RGBA
 * */
__swi_begin(0x131)
void setColor(int a, int r, int g, int b, void *dst)
__swi_end(0x131, setColor, (a, r, g, b, dst));

/** @} */

/**
 * @name RECT utils
 * @{
 * */

/**
 * Initialize #RECT by coordinates and size.
 * @param rect	pointer to the rect
 * @param x, y	rect coordinates
 * @param w, h	rect size
 * */
__swi_begin(0x133)
void StoreXYWHtoRECT(RECT *rect, int x, int y, int w, int h)
__swi_end(0x133, StoreXYWHtoRECT, (rect, x, y, w, h));

/**
 * Initialize #RECT by two points.
 * @param rect		pointer to the rect
 * @param x, y		1-st point: top + left
 * @param x2, y2	2-nd point: bottom + right
 * */
__swi_begin(0x134)
void StoreXYXYtoRECT(RECT *rect, int x, int y, int x2, int y2)
__swi_end(0x134, StoreXYXYtoRECT, (rect, x, y, x2, y2));

/** @} */

/**
 * @name General GUI functions
 * @{
 * */

/**
 * Check if the GUI is in focus on the screen.
 * @param id	GUI ID
 * @return 1 or 0
 * */
__swi_begin(0x135)
int IsGuiOnTop(int id)
__swi_end(0x135, IsGuiOnTop, (id));

/**
 * Get current focused GUI.
 * @return GUI ID
 * */
__swi_begin(0x210)
int GetCurGuiID()
__swi_end(0x210, GetCurGuiID, ());

/**
 * Create new GUI.
 * @param gui	pointer to the #GUI description.
 * @return ID of created GUI
 * 
 * It can be called only within created CSM.
 * @note Always use this function if possible.
 * */
__swi_begin(0x137)
int CreateGUI(void *gui)
__swi_end(0x137, CreateGUI, (gui));

/**
 * Create new GUI with specified ID.
 * @param gui	pointer to the #GUI description.
 * @param id	GUI ID
 * @return ID of created GUI
 * @deprecated Don't use this function!
 * */
__swi_begin(0x136)
int CreateGUI_ID(void *gui, int id)
__swi_end(0x136, CreateGUI_ID, (gui, id));

/**
 * Create new GUI.
 * @param gui	pointer to the #GUI description.
 * @return ID of created GUI
 * 
 * It can be called only within created CSM.
 * The difference between #CreateGUI is unknown.
 * */
__swi_begin(0x138)
int CreateGUI_30or2(void *gui)
__swi_end(0x138, CreateGUI_30or2, (gui));

/**
 * Create new GUI with dummy CSM.
 * @param gui	pointer to the #GUI description.
 * @param flag	unknown
 * @return ID of created GUI
 * */
__swi_begin(0x139)
int CreateGUIWithDummyCSM(void *gui, int flag)
__swi_end(0x139, CreateGUIWithDummyCSM, (gui, flag));

/**
 * Create new GUI with dummy CSM.
 * @param gui	pointer to the #GUI description.
 * @param flag	unknown
 * @return ID of created GUI
 * 
 * The difference between #CreateGUIWithDummyCSM is unknown.
 * */
__swi_begin(0x13A)
int CreateGUIWithDummyCSM_30or2(void *gui, int flag)
__swi_end(0x13A, CreateGUIWithDummyCSM_30or2, (gui, flag));

/**
 * Request closing of the focused GUI.
 * @param cmd	code which bypassed the #MSG_GUI_DESTROYED event
 * */
__swi_begin(0x13B)
void GeneralFuncF1(int cmd)
__swi_end(0x13B, GeneralFuncF1, (cmd));

/**
 * Unknown function.
 * @param cmd	unknown
 * */
__swi_begin(0x13C)
void GeneralFuncF0(int cmd)
__swi_end(0x13C, GeneralFuncF0, (cmd));

/**
 * Request closing of the GUI with given ID.
 * @param id	GUI ID
 * @param cmd	code which bypassed the #MSG_GUI_DESTROYED event
 * */
__swi_begin(0x13D)
void GeneralFunc_flag1(int id, int cmd)
__swi_end(0x13D, GeneralFunc_flag1, (id, cmd));

/**
 * Unknown function.
 * @param id	GUI ID
 * @param cmd	unknown
 * */
__swi_begin(0x13E)
void GeneralFunc_flag0(int id, int cmd)
__swi_end(0x13E, GeneralFunc_flag0, (id, cmd));

/**
 * Get pointer to the currently focused GUI.
 * @return pointer to the GUI
 * */
__swi_begin(0x14D)
GUI *GetTopGUI(void)
__swi_end(0x14D, GetTopGUI, ());

/**
 * Find GUI by ID.
 * @param id	GUI ID
 * @param csm	list of the #CSM_RAM pointers where GUI can be located.
 * @return pointer to the GUI
 * */
__swi_begin(0x209)
void *FindGUIbyId(int id, CSM_RAM **csm)
__swi_end(0x209, FindGUIbyId, (id, csm));

/**
 * Focus GUI by ID.
 * @param id	GUI ID
 * */
__swi_begin(0x21E)
void FocusGUI(int id)
__swi_end(0x21E, FocusGUI, (id));

/**
 * Unfocus focused GUI.
 * */
__swi_begin(0x21F)
void UnfocusGUI(void)
__swi_end(0x21F, UnfocusGUI, ());

/** @} */

/**
 * @name Redrawing
 * @{
 * */

/**
 * Request redraw of the GUI.
 * 
 * @note Platform independent function. Use it where possible.
 * @builtin ELKA, NSG, X75, SG
 * */
__swi_begin(0x172)
void REDRAW(void)
__swi_end(0x172, REDRAW, ());

/**
 * Immediate redraw the GUI.
 * 
 * @warning Low-level function, use only if you know what the doing.
 * @warning Call only from MMI! (not SUBPROC)
 * */
__swi_begin(0x13F)
void DirectRedrawGUI(void)
__swi_end(0x13F, DirectRedrawGUI, ());

/**
 * Immediate redraw the GUI (by ID).
 * @param id	id of the GUI
 * 
 * @warning Low-level function, use only if you know what the doing.
 * @warning Call only from MMI! (not SUBPROC)
 * */
__swi_begin(0x140)
void DirectRedrawGUI_ID(int id)
__swi_end(0x140, DirectRedrawGUI_ID, (id));

/**
 * Request redraw of the GUI.
 * 
 * @warning Low-level function, use only if you know what the doing.
 * @note It can be called in the SUBPORC.
 * */
__swi_begin(0x141)
void PendedRedrawGUI(void)
__swi_end(0x141, PendedRedrawGUI, ());

/** @} */

/**
 * @name Global keyhook
 * @{
 * */
/**
 * Add global keyhook to the beginning of the list.
 * @param callback		int callback(int submsg, int msg)
 * @builtin X75, SG
 * */
__swi_begin(0x12B)
void AddKeybMsgHook(KeybMsgHookProc callback)
__swi_end(0x12B, AddKeybMsgHook, (callback));

/**
 * Add global keyhook to the end of the list.
 * @param callback		int callback(int submsg, int msg)
 * @return 1: success, 0: error
 * @builtin X75, SG
 * */
__swi_begin(0x12C)
int AddKeybMsgHook_end(KeybMsgHookProc callback)
__swi_end(0x12C, AddKeybMsgHook_end, (callback));

/**
 * Remove global keyhook from the list.
 * @param callback		int callback(int submsg, int msg)
 * @builtin X75, SG
 * */
__swi_begin(0x12D)
void RemoveKeybMsgHook(KeybMsgHookProc callback)
__swi_end(0x12D, RemoveKeybMsgHook, (callback));

/** @} */

/**
 * @name Fonts
 * @{
 * */

/**
 * Get a char height in the specified font.
 * @param font_id		see #SystemFontID
 * @return height in px
 * */
__swi_begin(0x1C5)
int GetFontYSIZE(int font_id)
__swi_end(0x1C5, GetFontYSIZE, (font_id));

/**
 * Get a char width in the specified font.
 * @param character		UTF-16 codepoint
 * @param font_id		see #SystemFontID
 * @return width in px
 * */
__swi_begin(0x1E1)
int GetSymbolWidth(int character, int font_id)
__swi_end(0x1E1, GetSymbolWidth, (character, font_id));

/**
 * Measure string width with the specified font.
 * @param text			text to be measured
 * @param font_id		see #SystemFontID
 * @return width in px
 * */
__swi_begin(0x208)
int Get_WS_width(WSHDR *text, int font_id)
__swi_end(0x208, Get_WS_width, (text, font_id));

/** @} */

/**
 * @name Painting
 * @{
 * */

/**
 * Draw image.
 * @param x, y		image coordinates
 * @param img		pointer to the #IMGHDR
 * */
__swi_begin(0x3A5)
void DrawIMGHDR(int x, int y, IMGHDR *img)
__swi_end(0x3A5, DrawIMGHDR, (x, y, img));

/**
 * Draw cropped image.
 * @param x, y					coordinates
 * @param offset_x, offset_y	offsets
 * @param w						width
 * @param h						height
 * @param flags					drawing flags
 * @param img					pointer to the #IMGHDR
 * */
__swi_begin(0x3D4)
void DrawCroppedIMGHDR(int x, int y, int offset_x, int offset_y, int w, int h, int flags, const IMGHDR *img)
__swi_end(0x3D4, DrawCroppedIMGHDR, (x, y, offset_x, offset_y, w, h, flags, img));

/**
 * Draw image from the PIT table.
 * @param x, y		image coordinates
 * @param picture	image number
 * */
__swi_begin(0x023)
void DrawImg(int x, int y, int picture)
__swi_end(0x023, DrawImg, (x, y, picture));

/**
 * Draw BW image from the PIT table.
 * @param x, y		image coordinates
 * @param picture	image number
 * @param pen		replace black color or NULL
 * @param brush		replace white color or NULL
 * */
__swi_begin(0x026)
void DrawImgBW(int x, int y, int picture, const char *pen, const char *brush)
__swi_end(0x026, DrawImgBW, (x, y, picture, pen, brush));

/**
 * Draw single pixel.
 * @param x, y		coordinates
 * @param color		pixel color
 * */
__swi_begin(0x203)
void DrawPixel(int x, int y, const char *color)
__swi_end(0x203, DrawPixel, (x, y, color));

/**
 * Draw a triangle polygon.
 * @param x1, y1	1st point of the triangle
 * @param x2, y2	2nd point of the triangle
 * @param x3, y3	3rd point of the triangle
 * @param flags		drawing flags, see #RectDrawingFlags
 * @param pen		stroke color
 * @param brush		fill color
 * */
__swi_begin(0x202)
void DrawTriangle(int x1, int y1, int x2, int y2, int x3, int y3, int flags, const char *pen, const char *brush)
__swi_end(0x202, DrawTriangle, (x1, y1, x2, y2, x3, y3, flags, pen, brush));

/**
 * Draw an arc or pie.
 * @param x1, y1		left+top coordinates
 * @param x2, y2		right+bottom coordinates
 * @param start_angle	start angle of pie or arc
 * @param end_start		end angle of pie or arc
 * @param flags			drawing flags, see #RectDrawingFlags
 * @param pen			stroke color
 * @param brush			fill color
 * */
__swi_begin(0x204)
void DrawArc(int x1, int y1, int x2, int y2, int start_angle, int end_start, int flags, const char *pen, const char *brush)
__swi_end(0x204, DrawArc, (x1, y1, x2, y2, start_angle, end_start, flags, pen, brush));

/**
 * Draw a single line between two points.
 * @param x1, y1		1-st point coordinates
 * @param x2, y2		2-nd point coordinates
 * @param flags			drawing flags bitmask, see #LineDrawingFlags
 * @param pen			stroke color
 * */
__swi_begin(0x1B3)
void DrawLine(int x1, int y1, int x2, int y2, int flags, const char *pen)
__swi_end(0x1B3, DrawLine, (x1, y1, x2, y2, flags, pen));

/**
 * Draw a rectangle.
 * @param x1, y1		left+top coordinates
 * @param x2, y2		right+bottom coordinates
 * @param flags			drawing flags bitmask, see #RectDrawingFlags
 * @param pen			stroke color
 * @param brush			fill color
 * */
__swi_begin(0x1B4)
void DrawRectangle(int x1, int y1, int x2, int y2, int flags, const char *pen, const char *brush)
__swi_end(0x1B4, DrawRectangle, (x1, y1, x2, y2, flags, pen, brush));

/**
 * Draw a rounded rectangle.
 * @param x1, y1		left+top coordinates
 * @param x2, y2		right+bottom coordinates
 * @param x_round		horizontal round
 * @param y_round		vertical round
 * @param flags			drawing flags bitmask, see #RectDrawingFlags
 * @param pen			stroke color
 * @param brush			fill color
 * */
__swi_begin(0x150)
void DrawRoundedFrame(int x1, int y1, int x2, int y2, int x_round, int y_round, int flags, const char *pen, const char *brush)
__swi_end(0x150, DrawRoundedFrame, (x1, y1, x2, y2, x_round, y_round, flags, pen, brush));

/**
 * Draw a multi-line string.
 * You can use #UnicodeControlChars for custom formatting of the text.
 * @param text			UTF-16 text of the string
 * @param x1, y1		left+top coordinates
 * @param x2, y2		right+bottom coordinates
 * @param font			font ID, see #SystemFontID
 * @param text_flags	text attributes bitmask, see #TextAttributesFlags
 * @param pen			stroke color
 * @param brush			fill color
 * */
__swi_begin(0x14C)
void DrawString(WSHDR *text, int x1, int y1, int x2, int y2, int font, int text_flags, const char *pen, const char *brush)
__swi_end(0x14C, DrawString, (text, x1, y1, x2, y2, font, text_flags, pen, brush));

/**
 * Draw a one-line string with optional x-scrolling offset.
 * You can use #UnicodeControlChars for custom formatting of the text.
 * @param text			UTF-16 text of the string
 * @param x1, y1		left+top coordinates
 * @param x2, y2		right+bottom coordinates
 * @param xdisp			horizontal scrolling offset + 1
 * @param font			font ID, see #SystemFontID
 * @param text_flags	text attributes bitmask, see #TextAttributesFlags
 * @param pen			stroke color
 * @param brush			fill color
 * */
__swi_begin(0x207)
void DrawScrollString(WSHDR *text, int x1, int y1, int x2, int y2, int xdisp, int font, int text_flags, const char *pen, const char *brush)
__swi_end(0x207, DrawScrollString, (text, x1, y1, x2, y2, xdisp, font, text_flags, pen, brush));

/**
 * Build "Canvas" with IDLE Wallpaper.
 * "Canvas" is a really meaning for standard UI background.
 * @note Useful for painting widgets to the IDLE screen.
 * @return pointer to the "canvas" object
 * @pointer-type FLASH
 * */
__swi_begin(0x80F1)
void *BuildCanvas(void)
__swi_end(0x80F1, BuildCanvas, ());

/**
 * "Canvas" is a really meaning for standard UI background.
 * This function can draw any part of this "canvas".
 * @param data				pointer to the canvas created by #BuildCanvas
 * @param x, y, x2, y2		region for pain
 * @param flag_one			unknown, set to 1
 * */
__swi_begin(0x025)
void DrawCanvas(void *data, int x, int y, int x2, int y2, int flag_one)
__swi_end(0x025, DrawCanvas, (data, x, y, x2, y2, flag_one));

/**
 * Draw #DRWOBJ to the screen buffer.
 * @param drwobj	draw object
 * */
__swi_begin(0x12A)
void DrawObject(DRWOBJ *drwobj)
__swi_end(0x12A, DrawObject, (drwobj));

/** @} */

/**
 * @name DrwObj
 * Low-level drawing framework. Use this function for constructing objects which can be drawn with #DrawObject.
 * @{
 * */

#if 0
/**
 * Init #DRWOBJ which draw line.
 * @param flags			drawing flags bitmask, see #LineDrawingFlags
 * @param x1, y1		1-st point coordinates
 * @param x2, y2		2-nd point coordinates
 * */
__swi_begin(0xXXX)
void DrwObj_InitLine(DRWOBJ *drwobj, RECT *rect, int flags, int x, int y, int x2, int y2)
__swi_end(0xXXX, DrwObj_InitLine, (drwobj, rect, flags, x, y, x2, y2));

/**
 * Init #DRWOBJ which draw triangle.
 * @param drwobj		draw object
 * @param x1, y1		1st point of the triangle
 * @param x2, y2		2nd point of the triangle
 * @param x3, y3		3rd point of the triangle
 * @param flags			drawing flags, see #RectDrawingFlags
 * @param pen			stroke color
 * @param brush			fill color
 * */
__swi_begin(0xXXX)
void DrwObj_InitTriangle(DRWOBJ *drwobj, int x1, int y1, int x2, int y2, int x3, int y3, int flags, char *pen, char *brush)
__swi_end(0xXXX, DrwObj_InitTriangle, (drwobj, x1, y1, x2, y2, x3, y3, flags, pen, brush));
#endif

/**
 * Init #DRWOBJ which draw rectangle.
 * @param drwobj			draw object
 * @param rect				area on the screen
 * @param flags				drawing flags
 * */
__swi_begin(0x1FD)
void DrwObj_InitRect(DRWOBJ *drwobj, RECT *rect, int flags)
__swi_end(0x1FD, DrwObj_InitRect, (drwobj, rect, flags));

/**
 * Init #DRWOBJ which draw rectangle with custom filling.
 * @param drwobj			draw object
 * @param rect				area on the screen
 * @param flags				drawing flags
 * @param fill_type			filling type, see #DrwObjRectFillTypeID
 * @param fill_pattern		bit pattern, for example: 0b10101010
 * */
__swi_begin(0x205)
void DrwObj_InitRectEx(DRWOBJ *drwobj, RECT *rect, int flags, int fill_type, int fill_pattern)
__swi_end(0x205, DrwObj_InitRectEx, (drwobj, rect, flags, fill_type, fill_pattern));

/**
 * Init #DRWOBJ which draw text.
 * @param drwobj		draw object
 * @param rect			area on the screen
 * @param flags			drawing flags
 * @param text			UTF-16 text of the string
 * @param font			font ID, see #SystemFontID
 * @param text_flags	drawing flags bitmask, see #TextAttributesFlags
 * */
__swi_begin(0x149)
void DrwObj_InitText(DRWOBJ *drwobj, RECT *rect, int flags, WSHDR *text, int font, int text_flags)
__swi_end(0x149, DrwObj_InitText, (drwobj, rect, flags, text, font, text_flags));

/**
 * Init #DRWOBJ which draw image.
 * @param drwobj	draw object
 * @param rect		area on the screen
 * @param flags		image drawing flags
 * @param img		pointer to the image
 * */
__swi_begin(0x151)
void DrwObj_InitImage(DRWOBJ *drwobj, RECT *rect, int flags, IMGHDR *img)
__swi_end(0x151, DrwObj_InitImage, (drwobj, rect, flags, img));

/**
 * Init #DRWOBJ which draw tiled image.
 * @param drwobj				draw object
 * @param rect					area on the screen
 * @param flags					image drawing flags
 * @param img					pointer to the image #IMGHDR
 * @param offset_x, offset_y	tile offset in image
 * */
__swi_begin(0x201)
void DrwObj_InitTiledImage(DRWOBJ *drwobj, RECT *rect, int flags, IMGHDR *img, int offset_x, int offset_y)
__swi_end(0x201, DrwObj_InitTiledImage, (drwobj, rect, flags, img, offset_x, offset_y));

/**
 * Init #DRWOBJ which draw tiled image (without 255x255 limit).
 * @param drwobj				draw object
 * @param rect					area on the screen
 * @param flags					image drawing flags
 * @param img					pointer to the extended image #EIMGHDR
 * @param offset_x, offset_y	tile offset in image
 * */
__swi_begin(0x386)
void DrwObj_InitTiledImageEx(DRWOBJ *drwobj, RECT *rect, int flags, EIMGHDR *img, int offset_x, int offset_y)
__swi_end(0x386, DrwObj_InitTiledImageEx, (drwobj, rect, flags, img, offset_x, offset_y));

/**
 * Set color to the #DRWOBJ.
 * @param drwobj	draw object
 * @param pen		stroke color
 * @param brush		fill color
 * */
__swi_begin(0x14B)
void DrwObj_SetColor(DRWOBJ *drwobj, const char *pen, const char *brush)
__swi_end(0x14B, DrwObj_SetColor, (drwobj, pen, brush));

/**
 * Get WxH of the draw object.
 * @param drwobj	draw object
 * @param[out] w	width
 * @param[out] h	height
 * */
__swi_begin(0x3A6)
void DrwObj_GetWH(DRWOBJ *drwobj, int *w, int *h)
__swi_end(0x3A6, DrwObj_GetWH, (drwobj, w, h));

/**
 * Free draw object internal resources.
 * @param drwobj	draw object
 * */
__swi_begin(0x14A)
void DrwObj_Free(DRWOBJ *drwobj)
__swi_end(0x14A, DrwObj_Free, (drwobj));

/** @} */

/**
 * @name GUI timers
 * @{
 * */

/**
 * Create new GUI timer.
 * @param gui	pointer to the #GUI
 * @return ID of the created GUI timer.
 * */
__swi_begin(0x3A7)
int GUI_NewTimer(void *gui)
__swi_end(0x3A7, GUI_NewTimer, (gui));

/**
 * Delete GUI timer.
 * @param gui	pointer to the #GUI
 * @param id	timer ID
 * @return 0 on success
 * */
__swi_begin(0x3A8)
int GUI_DeleteTimer(void *gui, int id)
__swi_end(0x3A8, GUI_DeleteTimer, (gui, id));

/**
 * Schedule GUI timer.
 * @param gui		pointer to the #GUI
 * @param id		timer ID
 * @param timeout	timeout in ms
 * @param callback	timer callback
 * */
__swi_begin(0x3A9)
void GUI_StartTimerProc(void *gui, int id, long timeout, GUI_TimerProc callback)
__swi_end(0x3A9, GUI_StartTimerProc, (gui, id, timeout, callback));

/** @} */

/**
 * @name LCD layers
 * @{
 * */

/**
 * Set LCDLAYER buffer depth.
 * @param layer		pointer to the #LCDLAYER
 * @param depth		buffer depth
 * */
__swi_begin(0x389)
void LCDLAYER_SetBufferDepth(LCDLAYER *layer, char depth)
__swi_end(0x389, LCDLAYER_SetBufferDepth, (layer, depth));

/**
 * Get an LCD layer which is associated with the current CEPID.
 * @return pointer to the #LCDLAYER
 * */
__swi_begin(0x387)
LCDLAYER *LCDLAYER_GetCurrent()
__swi_end(0x387, LCDLAYER_GetCurrent, ());

/**
 * Request redrawing of the given LCDLAYER (delayed).
 * @param layer		pointer to the #LCDLAYER
 * */
__swi_begin(0x384)
void LCDLAYER_Redraw(LCDLAYER *layer)
__swi_end(0x384, LCDLAYER_Redraw, (layer));

/**
 * Do redrawing of the given LCDLAYER (immediate).
 * @param layer		pointer to the #LCDLAYER
 * */
__swi_begin(0x07A)
void LCDLAYER_Flush(LCDLAYER *layer)
__swi_end(0x07A, LCDLAYER_Flush, (layer));

/**
 * Limit drawing region on current LCDLAYER (selected by current CEPID).
 * @param x, y, x2, y2	drawing region	
 * */
__swi_begin(0x3A4)
void LCDLAYER_Current_SetClipRegion(int x, int y, int x2, int y2)
__swi_end(0x3A4, LCDLAYER_Current_SetClipRegion, (x, y, x2, y2));

/**
 * Set LCDLAYER buffer depth on current LCDLAYER (selected by current CEPID).
 * @param depth		buffer depth
 * */
__swi_begin(0x388)
void LCDLAYER_Current_SetBufferDepth(char depth)
__swi_end(0x388, LCDLAYER_Current_SetBufferDepth, (depth));

/**
 * Push #DRWOBJ to the given LCDLAYER (with redraw!)
 * @param drwobj	source #DRWOBJ
 * @param layer		destination #LCDLAYER
 * */
__swi_begin(0x079)
void DrawObject2Layer(LCDLAYER *layer, DRWOBJ *drwobj)
__swi_end(0x079, DrawObject2Layer, (layer, drwobj));

/**
 * Push #DRWOBJ to the given LCDLAYER (without redraw!)
 * @param drwobj	source #DRWOBJ
 * @param layer		destination #LCDLAYER
 * */
__swi_begin(0x383)
void PushDRWOBJOnLAYER(DRWOBJ *drwobj, LCDLAYER *layer)
__swi_end(0x383, PushDRWOBJOnLAYER, (drwobj, layer));

/**
 * Pointer to the list of the LCDLAYER's (main).
 * @return pointer to the array of #LCDLAYER_LIST
 * */
__swi_begin(0x80F6)
LCDLAYER_LIST *RamLcdMainLayersList()
__swi_end(0x80F6, RamLcdMainLayersList, ());

/**
 * Pointer to the list of the LCDLAYER's (RAP).
 * @return pointer to the array of #LCDLAYER_LIST
 * */
__swi_begin(0x80F7)
RAP_LCDLAYER_LIST *RamLcdRapLayersList()
__swi_end(0x80F7, RamLcdRapLayersList, ());

/**
 * Unknown
 * @return pointer to the unknown
 * */
__swi_begin(0x80F5)
void *Ram_LCD_Overlay_Layer()
__swi_end(0x80F5, Ram_LCD_Overlay_Layer, ());

/** @} */

/**
 * @name Deprecated
 * @{
 * */

/**
 * @copydoc DrawPixel
 * @deprecated Use #DrawPixel
 * */
__swi_begin(0x203)
void SetPixel(int x, int y, const char *color)
__swi_end(0x203, SetPixel, (x, y, color));

/**
 * @copydoc DrawTriangle
 * @deprecated Use #DrawTriangle
 * */
__swi_begin(0x202)
void fillTriangle(int x1, int y1, int x2, int y2, int x3, int y3, int flags, const char *pen, const char *brush)
__swi_end(0x202, fillTriangle, (x1, y1, x2, y2, x3, y3, flags, pen, brush));

/**
 * @copydoc DrawArc
 * @deprecated Use #DrawArc
 * */
__swi_begin(0x204)
void drawArc(int x1, int y1, int x2, int y2, int start_angle, int end_start, int flags, const char *pen, const char *brush)
__swi_end(0x204, drawArc, (x1, y1, x2, y2, start_angle, end_start, flags, pen, brush));

/**
 * @copydoc DrwObj_InitImage
 * @deprecated Use #DrwObj_InitImage
 * */
__swi_begin(0x151)
void SetPropTo_Obj5(DRWOBJ *drwobj, RECT *rect, int flags, IMGHDR *img)
__swi_end(0x151, SetPropTo_Obj5, (drwobj, rect, flags, img));

/**
 * @copydoc DrwObj_InitText
 * @deprecated Use #DrwObj_InitText
 * */
__swi_begin(0x149)
void SetPropTo_Obj1(DRWOBJ *drwobj, RECT *rect, int flags, WSHDR *text, int font, int text_flags)
__swi_end(0x149, SetPropTo_Obj1, (drwobj, rect, flags, text, font, text_flags));

/**
 * @copydoc DrwObj_InitTiledImage
 * @deprecated Use #DrwObj_InitTiledImage
 * */
__swi_begin(0x201)
void SetProp2ImageOrCanvas(DRWOBJ *drwobj, RECT *rect, int flags, IMGHDR *img, int offset_x, int offset_y)
__swi_end(0x201, SetProp2ImageOrCanvas, (drwobj, rect, flags, img, offset_x, offset_y));

/**
 * @copydoc DrwObj_InitTiledImageEx
 * @deprecated Use #DrwObj_InitTiledImageEx
 * */
__swi_begin(0x386)
void SetPropTo_obj0x17(DRWOBJ *drwobj, RECT *rect, int flags, EIMGHDR *img, int offset_x, int offset_y)
__swi_end(0x386, SetPropTo_obj0x17, (drwobj, rect, flags, img, offset_x, offset_y));

/**
 * @copydoc DrwObj_InitRectEx
 * @deprecated Use #DrwObj_InitRectEx
 * */
__swi_begin(0x205)
void SetProp2Square_v1(DRWOBJ *drwobj, RECT *rect, int flags, int fill_type, int fill_pattern)
__swi_end(0x205, SetProp2Square_v1, (drwobj, rect, flags, fill_type, fill_pattern));

/**
 * @copydoc DrwObj_SetColor
 * @deprecated Use #DrwObj_SetColor
 * */
__swi_begin(0x14B)
void SetColor(DRWOBJ *drwobj, const char *pen, const char *brush)
__swi_end(0x14B, SetColor, (drwobj, pen, brush));

/**
 * @copydoc DrwObj_GetWH
 * @deprecated Use #DrwObj_GetWH
 * */
__swi_begin(0x3A6)
void Get_Obj1_WH(DRWOBJ *drwobj, int *w, int *h)
__swi_end(0x3A6, Get_Obj1_WH, (drwobj, w, h));

/**
 * @copydoc DrwObj_Free
 * @deprecated Use #DrwObj_Free
 * */
__swi_begin(0x14A)
void FreeDrawObject_subobj(DRWOBJ *drwobj)
__swi_end(0x14A, FreeDrawObject_subobj, (drwobj));

/**
 * @copydoc LCDLAYER_SetBufferDepth
 * @deprecated use #LCDLAYER_SetBufferDepth
 * */
__swi_begin(0x389)
void SetDepthBufferOnLCDLAYER(LCDLAYER *layer, char depth)
__swi_end(0x389, SetDepthBufferOnLCDLAYER, (layer, depth));

/**
 * @copydoc LCDLAYER_GetCurrent
 * @deprecated use #LCDLAYER_GetCurrent
 * */
__swi_begin(0x387)
LCDLAYER *GetLCDLAYERByCurCepID()
__swi_end(0x387, GetLCDLAYERByCurCepID, ());

/**
 * @copydoc LCDLAYER_Redraw
 * @deprecated use #LCDLAYER_Redraw
 * */
__swi_begin(0x384)
void LCDRedrawLAYER(LCDLAYER *layer)
__swi_end(0x384, LCDRedrawLAYER, (layer));

/**
 * @copydoc LCDLAYER_Current_SetClipRegion
 * @deprecated use #LCDLAYER_Current_SetClipRegion
 * */
__swi_begin(0x3A4)
void SetDrawingCanvas(int x, int y, int x2, int y2)
__swi_end(0x3A4, SetDrawingCanvas, (x, y, x2, y2));

/** @} */

__swilib_end

/** @} */
