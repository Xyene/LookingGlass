/*
Looking Glass - KVM FrameRelay (KVMFR) Client
Copyright (C) 2017-2021 Geoffrey McRae <geoff@hostfission.com>
https://looking-glass.hostfission.com

This program is free software; you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free Software
Foundation; either version 2 of the License, or (at your option) any later
version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with
this program; if not, write to the Free Software Foundation, Inc., 59 Temple
Place, Suite 330, Boston, MA 02111-1307 USA
*/

#ifndef _H_LG_KB_
#define _H_LG_KB_

#include "kb.h"

const uint32_t xfree86_to_ps2[KEY_MAX] =
{
  [KEY_RESERVED]         /* = USB   0 */ = 0x000000,
  [KEY_ESC]              /* = USB  41 */ = 0x000001,
  [KEY_1]                /* = USB  30 */ = 0x000002,
  [KEY_2]                /* = USB  31 */ = 0x000003,
  [KEY_3]                /* = USB  32 */ = 0x000004,
  [KEY_4]                /* = USB  33 */ = 0x000005,
  [KEY_5]                /* = USB  34 */ = 0x000006,
  [KEY_6]                /* = USB  35 */ = 0x000007,
  [KEY_7]                /* = USB  36 */ = 0x000008,
  [KEY_8]                /* = USB  37 */ = 0x000009,
  [KEY_9]                /* = USB  38 */ = 0x00000A,
  [KEY_0]                /* = USB  39 */ = 0x00000B,
  [KEY_MINUS]            /* = USB  45 */ = 0x00000C,
  [KEY_EQUAL]            /* = USB  46 */ = 0x00000D,
  [KEY_BACKSPACE]        /* = USB  42 */ = 0x00000E,
  [KEY_TAB]              /* = USB  43 */ = 0x00000F,
  [KEY_Q]                /* = USB  20 */ = 0x000010,
  [KEY_W]                /* = USB  26 */ = 0x000011,
  [KEY_E]                /* = USB   8 */ = 0x000012,
  [KEY_R]                /* = USB  21 */ = 0x000013,
  [KEY_T]                /* = USB  23 */ = 0x000014,
  [KEY_Y]                /* = USB  28 */ = 0x000015,
  [KEY_U]                /* = USB  24 */ = 0x000016,
  [KEY_I]                /* = USB  12 */ = 0x000017,
  [KEY_O]                /* = USB  18 */ = 0x000018,
  [KEY_P]                /* = USB  19 */ = 0x000019,
  [KEY_LEFTBRACE]        /* = USB  47 */ = 0x00001A,
  [KEY_RIGHTBRACE]       /* = USB  48 */ = 0x00001B,
  [KEY_ENTER]            /* = USB  40 */ = 0x00001C,
  [KEY_LEFTCTRL]         /* = USB 224 */ = 0x00001D,
  [KEY_A]                /* = USB   4 */ = 0x00001E,
  [KEY_S]                /* = USB  22 */ = 0x00001F,
  [KEY_D]                /* = USB   7 */ = 0x000020,
  [KEY_F]                /* = USB   9 */ = 0x000021,
  [KEY_G]                /* = USB  10 */ = 0x000022,
  [KEY_H]                /* = USB  11 */ = 0x000023,
  [KEY_J]                /* = USB  13 */ = 0x000024,
  [KEY_K]                /* = USB  14 */ = 0x000025,
  [KEY_L]                /* = USB  15 */ = 0x000026,
  [KEY_SEMICOLON]        /* = USB  51 */ = 0x000027,
  [KEY_APOSTROPHE]       /* = USB  52 */ = 0x000028,
  [KEY_GRAVE]            /* = USB  53 */ = 0x000029,
  [KEY_LEFTSHIFT]        /* = USB 225 */ = 0x00002A,
  [KEY_BACKSLASH]        /* = USB  49 */ = 0x00002B,
  [KEY_Z]                /* = USB  29 */ = 0x00002C,
  [KEY_X]                /* = USB  27 */ = 0x00002D,
  [KEY_C]                /* = USB   6 */ = 0x00002E,
  [KEY_V]                /* = USB  25 */ = 0x00002F,
  [KEY_B]                /* = USB   5 */ = 0x000030,
  [KEY_N]                /* = USB  17 */ = 0x000031,
  [KEY_M]                /* = USB  16 */ = 0x000032,
  [KEY_COMMA]            /* = USB  54 */ = 0x000033,
  [KEY_DOT]              /* = USB  55 */ = 0x000034,
  [KEY_SLASH]            /* = USB  56 */ = 0x000035,
  [KEY_RIGHTSHIFT]       /* = USB 229 */ = 0x000036,
  [KEY_KPASTERISK]       /* = USB  85 */ = 0x000037,
  [KEY_LEFTALT]          /* = USB 226 */ = 0x000038,
  [KEY_SPACE]            /* = USB  44 */ = 0x000039,
  [KEY_CAPSLOCK]         /* = USB  57 */ = 0x00003A,
  [KEY_F1]               /* = USB  58 */ = 0x00003B,
  [KEY_F2]               /* = USB  59 */ = 0x00003C,
  [KEY_F3]               /* = USB  60 */ = 0x00003D,
  [KEY_F4]               /* = USB  61 */ = 0x00003E,
  [KEY_F5]               /* = USB  62 */ = 0x00003F,
  [KEY_F6]               /* = USB  63 */ = 0x000040,
  [KEY_F7]               /* = USB  64 */ = 0x000041,
  [KEY_F8]               /* = USB  65 */ = 0x000042,
  [KEY_F9]               /* = USB  66 */ = 0x000043,
  [KEY_F10]              /* = USB  67 */ = 0x000044,
  [KEY_NUMLOCK]          /* = USB  83 */ = 0x000045,
  [KEY_SCROLLLOCK]       /* = USB  71 */ = 0x000046,
  [KEY_KP7]              /* = USB  95 */ = 0x000047,
  [KEY_KP8]              /* = USB  96 */ = 0x000048,
  [KEY_KP9]              /* = USB  97 */ = 0x000049,
  [KEY_KPMINUS]          /* = USB  86 */ = 0x00004A,
  [KEY_KP4]              /* = USB  92 */ = 0x00004B,
  [KEY_KP5]              /* = USB  93 */ = 0x00004C,
  [KEY_KP6]              /* = USB  94 */ = 0x00004D,
  [KEY_KPPLUS]           /* = USB  87 */ = 0x00004E,
  [KEY_KP1]              /* = USB  89 */ = 0x00004F,
  [KEY_KP2]              /* = USB  90 */ = 0x000050,
  [KEY_KP3]              /* = USB  91 */ = 0x000051,
  [KEY_KP0]              /* = USB  98 */ = 0x000052,
  [KEY_KPDOT]            /* = USB  99 */ = 0x000053,
  [KEY_102ND]            /* = USB 100 */ = 0x000056,
  [KEY_F11]              /* = USB  68 */ = 0x000057,
  [KEY_F12]              /* = USB  69 */ = 0x000058,
  [KEY_RO]               /* = USB 135 */ = 0x000073,
  [KEY_HENKAN]           /* = USB 138 */ = 0x000079,
  [KEY_KATAKANAHIRAGANA] /* = USB 136 */ = 0x000070,
  [KEY_MUHENKAN]         /* = USB 139 */ = 0x00007B,
  [KEY_KPENTER]          /* = USB  88 */ = 0x00E01C,
  [KEY_RIGHTCTRL]        /* = USB 228 */ = 0x00E01D,
  [KEY_KPSLASH]          /* = USB  84 */ = 0x00E035,
  [KEY_SYSRQ]            /* = USB  70 */ = 0x00E037,
  [KEY_RIGHTALT]         /* = USB 230 */ = 0x00E038,
  [KEY_HOME]             /* = USB  74 */ = 0x00E047,
  [KEY_UP]               /* = USB  82 */ = 0x00E048,
  [KEY_PAGEUP]           /* = USB  75 */ = 0x00E049,
  [KEY_LEFT]             /* = USB  80 */ = 0x00E04B,
  [KEY_RIGHT]            /* = USB  79 */ = 0x00E04D,
  [KEY_END]              /* = USB  77 */ = 0x00E04F,
  [KEY_DOWN]             /* = USB  81 */ = 0x00E050,
  [KEY_PAGEDOWN]         /* = USB  78 */ = 0x00E051,
  [KEY_INSERT]           /* = USB  73 */ = 0x00E052,
  [KEY_DELETE]           /* = USB  76 */ = 0x00E053,
  [KEY_KPEQUAL]          /* = USB 103 */ = 0x000059,
  [KEY_PAUSE]            /* = USB  72 */ = 0x00E046,
  [KEY_KPCOMMA]          /* = USB 133 */ = 0x00007E,
  [KEY_HANGEUL]          /* = USB 144 */ = 0x0000F2,
  [KEY_HANJA]            /* = USB 145 */ = 0x0000F1,
  [KEY_YEN]              /* = USB 137 */ = 0x00007D,
  [KEY_LEFTMETA]         /* = USB 227 */ = 0x00E05B,
  [KEY_RIGHTMETA]        /* = USB 231 */ = 0x00E05C,
  [KEY_COMPOSE]          /* = USB 101 */ = 0x00E05D,
  [KEY_F13]              /* = USB 104 */ = 0x00005D,
  [KEY_F14]              /* = USB 105 */ = 0x00005E,
  [KEY_F15]              /* = USB 106 */ = 0x00005F,
  [KEY_PRINT]            /* = USB  70 */ = 0x00E037,
};

#endif
