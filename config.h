/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int snap      = 16;       /* snap pixel */
static const unsigned int gappih    = 10;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 10;       /* vert inner gap between windows */
static const unsigned int gappoh    = 10;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 10;       /* vert outer gap between windows and screen edge */
static       int smartgaps          = 1;        /* 1 means no outer gap when there is only one window */
static const int swallowfloating    = 0;        /* 1 means swallow floating windows by default */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const Bool viewontag         = True;     /* Switch view on tag switch */
static const int viewonrulestag     = 1;	/* 1 means when open applications view will move to tags defined in rules*/
static const int user_bh            = 8;        /* 2 is the default spacing around the bar's font */
static const char *fonts[]          = { "Symbols Nerd Font:size=18", "Iosevka Nerd Font Mono:size=16"};
static const char dmenufont[]       = "Iosevka Nerd Font Mono:size=14";

/* Default dwm colors */
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#005577";
static const char col_urgborder[]   = "#ff0000";

/* Pywal colors (base16-materialer) */
static const char norm_fg[]     = "#FFFFFF";
static const char norm_bg[]     = "#212121";
static const char norm_border[] = "#4A4A4A";
static const char sel_fg[]      = "#FFFFFF";
static const char sel_bg[]      = "#C3E88D";
static const char sel_border[]  = "#FFFFFF";
static const char urg_fg[]      = "#FFFFFF";
static const char urg_bg[]      = "#F07178";
static const char urg_border[]  = "#F07178";

static const unsigned int baralpha = 0xd0;
static const unsigned int borderalpha = OPAQUE;
static const char *colors[][3]      = {
	/*                   fg         bg         border      */
	[SchemeNorm]     = { norm_fg,   norm_bg,   norm_border }, // Unfocused windows
	[SchemeSel]      = { sel_fg,    sel_bg,    sel_border  }, // The focused window
	[SchemeUrg]      = { urg_fg,    urg_bg,    urg_border  },
	[SchemeTitle]    = { norm_fg,   norm_bg,   norm_border },
	[SchemeStatus]   = { norm_fg,   norm_bg,   "#000000"   }, // Statusbar right {text,background,not used but cannot be empty}
	[SchemeTagsSel]  = { sel_fg,    norm_bg,   "#000000"   }, // Tagbar left selected {text,background,not used but cannot be empty}
	[SchemeTagsNorm] = { norm_fg,   norm_bg,   "#000000"   }, // Tagbar left unselected {text,background,not used but cannot be empty}
	[SchemeInfoSel]  = { sel_fg,    sel_bg,    "#000000"   }, // infobar middle  selected {text,background,not used but cannot be empty}
	[SchemeInfoNorm] = { norm_fg,   norm_bg,   "#000000"   }, // infobar middle  unselected {text,background,not used but cannot be empty}
};
static const unsigned int alphas[][3]      = {
    /*               fg      bg        border      */
    [SchemeNorm] = { OPAQUE, baralpha, borderalpha },
    [SchemeSel]  = { OPAQUE, baralpha, borderalpha },
};

/* tagging */
static const char *tags[]    = { "", "", "", "󰇮", "", "󰑋", "", "󰙯", "" };
static const char *tagsalt[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };
static const int momentaryalttags = 0; /* 1 means alttags will show only when key is held down */

static const unsigned int ulinepad	= 2;	/* horizontal padding between the underline and tag */
static const unsigned int ulinestroke	= 2;	/* thickness / height of the underline */
static const unsigned int ulinevoffset	= 0;	/* how far above the bottom of the bar the line should appear */
static const int ulineall 		= 0;	/* 1 to show underline on all tags, 0 for just the active ones */

/* Tag Masks:
 * Tab 1 = 1 << 0
 * Tab 2 = 1 << 1
 * Tab 3 = 1 << 2
 * Tab 4 = 1 << 3
 * Tab 5 = 1 << 4
 * Tab 6 = 1 << 5
 * Tab 7 = 1 << 6
 * Tab 8 = 1 << 7
 * Tab 9 = 1 << 8
 * Any = 0
 */
static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class             instance     title           tags mask  isfloating  isterminal   noswallow  monitor */
	{ "st",              NULL,        NULL,           1 << 1,    0,          1,           0,         -1 },
	{ "Thorium-browser", NULL,        NULL,           1 << 2,    0,          0,           0,         -1 },
	{ "thunderbird",     NULL,        NULL,           1 << 3,    0,          0,           0,         -1 },
	{ "Virt-manager",    NULL,        NULL,           1 << 4,    0,          0,           0,         -1 },
	{ "obs",             NULL,        NULL,           1 << 5,    0,          0,           0,         -1 },
	{ "steam",           NULL,        NULL,           1 << 6,    0,          0,           0,         -1 },
	{ "discord",         NULL,        NULL,           1 << 7,    0,          0,           0,         -1 },
	{ "Spotify",         NULL,        NULL,           1 << 8,    0,          0,           0,         -1 },
	{ "zoom",            NULL,        NULL,           0,         0,          0,           0,         -1 },
	{ "feh",             NULL,        NULL,           0,         0,          0,           0,         -1 },
	{ "mpv",             NULL,        NULL,           0,         0,          0,           0,         -1 },
	{ "Gimp",            NULL,        NULL,           0,         1,          0,           0,         -1 },
	{ "qpwgraph",        NULL,        NULL,           0,         0,          0,           0,         -1 },
	{ "Deluge",          NULL,        NULL,           0,         0,          0,           0,         -1 },
	{ NULL,              "Zathura",   NULL,           0,         0,          0,           0,         -1 },
	{ NULL,              NULL,        "Event Tester", 0,         0,          0,           1,         -1 }, /* xev */
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split vertically */
#include "vanitygaps.c"

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "[M]",      monocle },
	{ "[@]",      spiral },
	{ "[\\]",     dwindle },
	{ "H[]",      deck },
	{ "TTT",      bstack },
	{ "===",      bstackhoriz },
	{ "HHH",      grid },
	{ "###",      nrowgrid },
	{ "---",      horizgrid },
	{ ":::",      gaplessgrid },
	{ "|M|",      centeredmaster },
	{ ">M>",      centeredfloatingmaster },
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ NULL,       NULL },
};

/* custom symbols for nr. of clients in monocle layout */
/* when clients >= LENGTH(monocles), uses the last element */
static const char *monocles[] = { "󰎤", "󰎧", "󰎪", "󰎭", "󰎱", "󰎳", "󰎶", "󰎹", "󰎼", "󰎿" };

/* key definitions */
#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *termcmd[]  = { "st", NULL };

static const Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },   /* Open dmenu */
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },    /* Open st    */
	{ MODKEY,                       XK_b,      togglebar,      {0} },                /* Toggle bar */
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },         /* Focus on next client */
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },         /* Focus on prev client */
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },         /* Increase clients in master */
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },         /* Decrease clients in master */
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },       /* Decrease master size */
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },       /* Increase master size */
	{ MODKEY|ShiftMask,             XK_h,      setcfact,       {.f = +0.25} },
	{ MODKEY|ShiftMask,             XK_l,      setcfact,       {.f = -0.25} },
	{ MODKEY|ShiftMask,             XK_o,      setcfact,       {.f =  0.00} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },                /* Close dwm       */
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },                /* Close window    */
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} }, /* Layout: tile    */
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} }, /* Layout: monocle */
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} }, /* Layout: spiral  */
	{ MODKEY,                       XK_n,      togglealttag,   {0} },                /* Toggle tag numbers/icons */
	{ MODKEY,                       XK_Tab,    viewnext,       {0} },                /* View next occupied tag   */
	{ MODKEY|ShiftMask,             XK_Tab,    viewprev,       {0} },                /* View prev occupied tag   */
	{ MODKEY,                       XK_Right,  viewnext,       {0} },                /* View next occupied tag   */
	{ MODKEY,                       XK_Left,   viewprev,       {0} },                /* View prev occupied tag   */
	{ MODKEY|ShiftMask,             XK_Right,  tagtonext,      {0} },                /* Move window to next occupied tag */
	{ MODKEY|ShiftMask,             XK_Left,   tagtoprev,      {0} },                /* Move window to prev occupied tag */
	TAGKEYS(                        XK_1,                      0)                    /* Show tag 1 */
	TAGKEYS(                        XK_2,                      1)                    /* Show tag 2 */
	TAGKEYS(                        XK_3,                      2)                    /* Show tag 3 */
	TAGKEYS(                        XK_4,                      3)                    /* Show tag 4 */
	TAGKEYS(                        XK_5,                      4)                    /* Show tag 5 */
	TAGKEYS(                        XK_6,                      5)                    /* Show tag 6 */
	TAGKEYS(                        XK_7,                      6)                    /* Show tag 7 */
	TAGKEYS(                        XK_8,                      7)                    /* Show tag 8 */
	TAGKEYS(                        XK_9,                      8)                    /* Show tag 9 */

	/* Disabled keybinds */
//	{ MODKEY|Mod4Mask,              XK_u,      incrgaps,       {.i = +1 } },
//	{ MODKEY|Mod4Mask|ShiftMask,    XK_u,      incrgaps,       {.i = -1 } },
//	{ MODKEY|Mod4Mask,              XK_i,      incrigaps,      {.i = +1 } },
//	{ MODKEY|Mod4Mask|ShiftMask,    XK_i,      incrigaps,      {.i = -1 } },
//	{ MODKEY|Mod4Mask,              XK_o,      incrogaps,      {.i = +1 } },
//	{ MODKEY|Mod4Mask|ShiftMask,    XK_o,      incrogaps,      {.i = -1 } },
//	{ MODKEY|Mod4Mask,              XK_6,      incrihgaps,     {.i = +1 } },
//	{ MODKEY|Mod4Mask|ShiftMask,    XK_6,      incrihgaps,     {.i = -1 } },
//	{ MODKEY|Mod4Mask,              XK_7,      incrivgaps,     {.i = +1 } },
//	{ MODKEY|Mod4Mask|ShiftMask,    XK_7,      incrivgaps,     {.i = -1 } },
//	{ MODKEY|Mod4Mask,              XK_8,      incrohgaps,     {.i = +1 } },
//	{ MODKEY|Mod4Mask|ShiftMask,    XK_8,      incrohgaps,     {.i = -1 } },
//	{ MODKEY|Mod4Mask,              XK_9,      incrovgaps,     {.i = +1 } },
//	{ MODKEY|Mod4Mask|ShiftMask,    XK_9,      incrovgaps,     {.i = -1 } },
//	{ MODKEY|Mod4Mask,              XK_0,      togglegaps,     {0} },
//	{ MODKEY|Mod4Mask|ShiftMask,    XK_0,      defaultgaps,    {0} },
//	{ MODKEY,                       XK_Tab,    view,           {0} },
//	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
//	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
//	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
//	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
//	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
//	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        MODKEY,         Button2,        spawn,          {.v = termcmd } },
	{ ClkStatusText,        0,              Button2,        spawn,          SHCMD("amixer set Master toggle") },
	{ ClkStatusText,        0,              Button4,        spawn,          SHCMD("amixer set Master 5%+") },
	{ ClkStatusText,        0,              Button5,        spawn,          SHCMD("amixer set Master 5%-") },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
