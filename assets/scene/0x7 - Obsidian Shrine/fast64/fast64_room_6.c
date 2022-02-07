#include "ultra64.h"
#include "z64.h"
#include "macros.h"
#include "fast64_scene.h"

#include "segment_symbols.h"
#include "command_macros_base.h"
#include "z64cutscene_commands.h"
#include "variables.h"

SCmdBase fast64_room_6_header00[] = {
	SCENE_CMD_ECHO_SETTINGS(0x04),
	SCENE_CMD_ROOM_BEHAVIOR(0x00, 0x02, false, false),
	SCENE_CMD_SKYBOX_DISABLES(false, true),
	SCENE_CMD_TIME_SETTINGS(0xFF, 0xFF, 10),
	SCENE_CMD_MESH(&fast64_room_6_meshHeader),
	SCENE_CMD_OBJECT_LIST(3, &fast64_room_6_header00_objectList),
	SCENE_CMD_ACTOR_LIST(11, &fast64_room_6_header00_actorList),
	SCENE_CMD_END(),
};

s16 fast64_room_6_header00_objectList[3] = {
	OBJECT_SYOKUDAI,
	OBJECT_FIREFLY,
	OBJECT_BOX,
};

ActorEntry fast64_room_6_header00_actorList[11] = {
	{ ACTOR_EN_FIREFLY, -1030, -485, -729, 0, 9736, 0, 0 },
	{ ACTOR_OBJ_ROOMTIMER, -789, -526, -619, 0, 49152, 0, 0x301E },
	{ ACTOR_EN_FIREFLY, -964, -485, -788, 0, 64222, 0, 0 },
	{ ACTOR_EN_BOX, -789, -591, -619, 0, 49152, 0, 0x5844 },
	{ ACTOR_EN_FIREFLY, -955, -485, -458, 0, 31708, 0, 0 },
	{ ACTOR_EN_FIREFLY, -458, -484, -799, 0, 0, 0, 0 },
	{ ACTOR_EN_FIREFLY, -350, -504, -771, 0, 0, 0, 0 },
	{ ACTOR_BG_HIDAN_CURTAIN, -789, -591, -619, 0, 0, 0, 0x0000 },
	{ ACTOR_EN_RIVER_SOUND, -795, -618, -621, 0, 118, 0, 0x0002 },
	{ ACTOR_EN_FIREFLY, -1030, -485, -516, 0, 22784, 0, 0 },
	{ ACTOR_EN_FIREFLY, -1090, -485, -621, 0, 16882, 0, 0 },
};

MeshHeader0 fast64_room_6_meshHeader = { {0}, 1, (u32)&fast64_room_6_meshDListEntry, (u32)&(fast64_room_6_meshDListEntry) + sizeof(fast64_room_6_meshDListEntry) };

MeshEntry0 fast64_room_6_meshDListEntry[1] = {
	{ (u32)fast64_room_6_entry_0_opaque, (u32)fast64_room_6_entry_0_transparent },
};

Gfx fast64_room_6_entry_0_opaque[] = {
	gsSPDisplayList(fast64_dl_Room6Mesh_mesh_layer_Opaque),
	gsSPEndDisplayList(),
};

Gfx fast64_room_6_entry_0_transparent[] = {
	gsSPDisplayList(fast64_dl_Room6Mesh_001_mesh_layer_Transparent),
	gsSPEndDisplayList(),
};

Vtx fast64_dl_Room6Mesh_mesh_layer_Opaque_vtx_cull[8] = {
	{{{-1160, -629, -400},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{-1160, -431, -400},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{-1160, -431, -845},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{-1160, -629, -845},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{-310, -629, -400},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{-310, -431, -400},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{-310, -431, -845},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{-310, -629, -845},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
};

Vtx fast64_dl_Room6Mesh_mesh_layer_Opaque_vtx_0[24] = {
	{{{-366, -479, -413},0, {-1552, 496},{0x63, 0x63, 0x63, 0xFF}}},
	{{{-352, -479, -400},0, {-1552, 400},{0x0, 0x0, 0x0, 0xFF}}},
	{{{-352, -579, -400},0, {1488, 400},{0x0, 0x0, 0x0, 0xFF}}},
	{{{-366, -579, -413},0, {1488, 496},{0x63, 0x63, 0x63, 0xFF}}},
	{{{-324, -579, -456},0, {1488, 496},{0x63, 0x63, 0x63, 0xFF}}},
	{{{-310, -579, -442},0, {1488, 400},{0x0, 0x0, 0x0, 0xFF}}},
	{{{-310, -479, -442},0, {-1552, 400},{0x0, 0x0, 0x0, 0xFF}}},
	{{{-324, -479, -456},0, {-1552, 496},{0x63, 0x63, 0x63, 0xFF}}},
	{{{-324, -479, -456},0, {-1616, 496},{0x41, 0x41, 0x41, 0xFF}}},
	{{{-310, -479, -442},0, {-1616, 400},{0x0, 0x0, 0x0, 0xFF}}},
	{{{-352, -479, -400},0, {464, 400},{0x0, 0x0, 0x0, 0xFF}}},
	{{{-366, -479, -413},0, {464, 496},{0x41, 0x41, 0x41, 0xFF}}},
	{{{-314, -463, -467},0, {-2096, 512},{0x6B, 0x6B, 0x6B, 0xFF}}},
	{{{-324, -479, -456},0, {-1616, -16},{0x97, 0x97, 0x97, 0xFF}}},
	{{{-366, -479, -413},0, {464, -16},{0x97, 0x97, 0x97, 0xFF}}},
	{{{-376, -464, -403},0, {944, 496},{0x6D, 0x6D, 0x6D, 0xFF}}},
	{{{-376, -464, -403},0, {-2032, 496},{0x6D, 0x6D, 0x6D, 0xFF}}},
	{{{-366, -479, -413},0, {-1552, -16},{0x97, 0x97, 0x97, 0xFF}}},
	{{{-366, -579, -413},0, {1488, -16},{0x6D, 0x6D, 0x6D, 0xFF}}},
	{{{-376, -579, -403},0, {1488, 496},{0x6D, 0x6D, 0x6D, 0xFF}}},
	{{{-314, -463, -467},0, {-2048, 494},{0x6E, 0x6E, 0x6E, 0xFF}}},
	{{{-314, -579, -467},0, {1488, 496},{0x6D, 0x6D, 0x6D, 0xFF}}},
	{{{-324, -579, -456},0, {1488, -16},{0x6D, 0x6D, 0x6D, 0xFF}}},
	{{{-324, -479, -456},0, {-1552, -16},{0x97, 0x97, 0x97, 0xFF}}},
};

Gfx fast64_dl_Room6Mesh_mesh_layer_Opaque_tri_0[] = {
	gsSPVertex(fast64_dl_Room6Mesh_mesh_layer_Opaque_vtx_0 + 0, 24, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
	gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
	gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
	gsSP2Triangles(16, 17, 18, 0, 16, 18, 19, 0),
	gsSP2Triangles(20, 21, 22, 0, 20, 22, 23, 0),
	gsSPEndDisplayList(),
};

Vtx fast64_dl_Room6Mesh_mesh_layer_Opaque_vtx_1[29] = {
	{{{-314, -431, -467},0, {4223, 2300},{0x6D, 0x6D, 0x6D, 0xFF}}},
	{{{-376, -431, -403},0, {4240, 1424},{0x6D, 0x6D, 0x6D, 0xFF}}},
	{{{-313, -431, -845},0, {1616, 4912},{0x6D, 0x6D, 0x6D, 0xFF}}},
	{{{-366, -579, -413},0, {1008, 1008},{0xA8, 0xA8, 0xA8, 0xFF}}},
	{{{-352, -579, -400},0, {1008, 667},{0x0, 0x0, 0x0, 0xFF}}},
	{{{-310, -579, -442},0, {-16, 667},{0x4, 0x4, 0x4, 0xFF}}},
	{{{-324, -579, -456},0, {-16, 1008},{0xA8, 0xA8, 0xA8, 0xFF}}},
	{{{-1160, -431, -483},0, {-1663, -3367},{0x64, 0x3B, 0x3D, 0xFF}}},
	{{{-1160, -431, -762},0, {-3617, -1433},{0x64, 0x3B, 0x3D, 0xFF}}},
	{{{-1080, -431, -843},0, {-3629, -333},{0x64, 0x3B, 0x3D, 0xFF}}},
	{{{-313, -431, -845},0, {1616, 4912},{0x53, 0x78, 0x7C, 0xFF}}},
	{{{-1080, -431, -403},0, {-558, -3374},{0x64, 0x3B, 0x3D, 0xFF}}},
	{{{-602, -607, -558},0, {-393, -1759},{0xBA, 0x51, 0x4C, 0xFF}}},
	{{{-713, -591, -711},0, {1808, -3344},{0xCE, 0x44, 0x3D, 0xFF}}},
	{{{-713, -591, -529},0, {-801, -3324},{0xCE, 0x44, 0x3D, 0xFF}}},
	{{{-602, -607, -682},0, {1328, -1764},{0xBA, 0x51, 0x4C, 0xFF}}},
	{{{-465, -579, -558},0, {-387, 181},{0xA3, 0x5F, 0x5D, 0xFF}}},
	{{{-465, -579, -682},0, {1334, 176},{0xA3, 0x5F, 0x5D, 0xFF}}},
	{{{-713, -591, -529},0, {-801, -3324},{0xCF, 0x43, 0x3C, 0xFF}}},
	{{{-713, -591, -711},0, {1808, -3344},{0xCF, 0x43, 0x3C, 0xFF}}},
	{{{-900, -591, -705},0, {1698, -5945},{0xEB, 0x31, 0x28, 0xFF}}},
	{{{-900, -591, -535},0, {-732, -5926},{0xEB, 0x31, 0x28, 0xFF}}},
	{{{-465, -579, -842},0, {3568, 176},{0xA3, 0x5F, 0x5D, 0xFF}}},
	{{{-314, -579, -842},0, {3561, 2282},{0x6D, 0x6D, 0x6D, 0xFF}}},
	{{{-314, -579, -467},0, {-1680, 2288},{0x6D, 0x6D, 0x6D, 0xFF}}},
	{{{-465, -579, -558},0, {-387, 181},{0xA8, 0x5E, 0x5C, 0xFF}}},
	{{{-376, -579, -403},0, {-2576, 1392},{0x6D, 0x6D, 0x6D, 0xFF}}},
	{{{-465, -579, -470},0, {-1616, 176},{0xA3, 0x5F, 0x5D, 0xFF}}},
	{{{-531, -579, -403},0, {-2576, -784},{0xA3, 0x5F, 0x5D, 0xFF}}},
};

Gfx fast64_dl_Room6Mesh_mesh_layer_Opaque_tri_1[] = {
	gsSPVertex(fast64_dl_Room6Mesh_mesh_layer_Opaque_vtx_1 + 0, 29, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
	gsSP2Triangles(3, 5, 6, 0, 7, 8, 9, 0),
	gsSP2Triangles(9, 1, 7, 0, 9, 10, 1, 0),
	gsSP2Triangles(1, 11, 7, 0, 12, 13, 14, 0),
	gsSP2Triangles(12, 15, 13, 0, 16, 15, 12, 0),
	gsSP2Triangles(16, 17, 15, 0, 18, 19, 20, 0),
	gsSP2Triangles(18, 20, 21, 0, 22, 17, 23, 0),
	gsSP2Triangles(23, 17, 24, 0, 17, 25, 24, 0),
	gsSP2Triangles(25, 26, 24, 0, 25, 27, 26, 0),
	gsSP1Triangle(27, 28, 26, 0),
	gsSPEndDisplayList(),
};

Vtx fast64_dl_Room6Mesh_mesh_layer_Opaque_vtx_2[35] = {
	{{{-900, -591, -705},0, {2367, 211},{0xF7, 0x25, 0x1D, 0xFF}}},
	{{{-887, -629, -754},0, {2448, 976},{0xFF, 0x26, 0x7, 0xFF}}},
	{{{-988, -629, -692},0, {3376, 976},{0xF5, 0x64, 0x51, 0xFF}}},
	{{{-900, -591, -535},0, {2367, 211},{0xF8, 0x1F, 0x14, 0xFF}}},
	{{{-988, -629, -547},0, {3376, 976},{0xFF, 0x25, 0x0, 0xFF}}},
	{{{-887, -629, -485},0, {2448, 976},{0xFF, 0x25, 0x0, 0xFF}}},
	{{{-465, -579, -682},0, {1213, -16},{0xA3, 0x5F, 0x5D, 0xFF}}},
	{{{-465, -579, -842},0, {2992, -16},{0xA3, 0x5F, 0x5D, 0xFF}}},
	{{{-557, -629, -842},0, {2992, 1008},{0xFF, 0x25, 0x0, 0xFF}}},
	{{{-557, -629, -711},0, {1535, 1008},{0xFF, 0x28, 0xC, 0xFF}}},
	{{{-531, -579, -403},0, {-2256, -16},{0xA3, 0x5F, 0x5D, 0xFF}}},
	{{{-557, -629, -470},0, {-1168, 1008},{0xFF, 0x25, 0x0, 0xFF}}},
	{{{-623, -629, -403},0, {-2256, 1008},{0xFF, 0x25, 0x0, 0xFF}}},
	{{{-465, -579, -470},0, {-1168, -16},{0xA3, 0x5F, 0x5D, 0xFF}}},
	{{{-557, -629, -529},0, {-509, 1008},{0xFF, 0x23, 0x0, 0xFF}}},
	{{{-465, -579, -558},0, {-183, -16},{0xBA, 0x54, 0x50, 0xFF}}},
	{{{-713, -591, -711},0, {-183, 150},{0xD9, 0x31, 0x2D, 0xFF}}},
	{{{-602, -607, -682},0, {-1872, 16},{0xD7, 0x48, 0x43, 0xFF}}},
	{{{-557, -629, -711},0, {-2352, 976},{0xFE, 0x28, 0xF, 0xFF}}},
	{{{-465, -579, -682},0, {-3792, 16},{0xA1, 0x67, 0x6A, 0xFF}}},
	{{{-713, -591, -529},0, {-151, 157},{0xE1, 0x30, 0x2D, 0xFF}}},
	{{{-900, -591, -535},0, {2502, 102},{0xF7, 0x1D, 0x15, 0xFF}}},
	{{{-753, -629, -458},0, {548, 1441},{0xFF, 0x30, 0x4, 0xFF}}},
	{{{-557, -629, -529},0, {-2352, 976},{0xFD, 0x34, 0x23, 0xFF}}},
	{{{-602, -607, -558},0, {-1872, 16},{0xD7, 0x48, 0x43, 0xFF}}},
	{{{-465, -579, -558},0, {-3792, 16},{0xA1, 0x67, 0x6A, 0xFF}}},
	{{{-753, -629, -782},0, {548, 1441},{0xFF, 0x2A, 0x2, 0xFF}}},
	{{{-900, -591, -705},0, {2540, 55},{0xF2, 0x19, 0x18, 0xFF}}},
	{{{-713, -591, -711},0, {-151, 157},{0xE1, 0x2E, 0x2A, 0xFF}}},
	{{{-900, -591, -535},0, {1991, 128},{0xEA, 0x38, 0x2F, 0xFF}}},
	{{{-900, -591, -705},0, {4088, 128},{0xEA, 0x38, 0x2F, 0xFF}}},
	{{{-988, -629, -692},0, {3888, 976},{0xF5, 0x64, 0x51, 0xFF}}},
	{{{-900, -591, -535},0, {1991, 128},{0xEA, 0x38, 0x2F, 0xFF}}},
	{{{-988, -629, -692},0, {3888, 976},{0xF5, 0x64, 0x51, 0xFF}}},
	{{{-988, -629, -547},0, {2448, 976},{0xFF, 0x25, 0x0, 0xFF}}},
};

Gfx fast64_dl_Room6Mesh_mesh_layer_Opaque_tri_2[] = {
	gsSPVertex(fast64_dl_Room6Mesh_mesh_layer_Opaque_vtx_2 + 0, 32, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
	gsSP2Triangles(6, 7, 8, 0, 6, 8, 9, 0),
	gsSP2Triangles(10, 11, 12, 0, 10, 13, 11, 0),
	gsSP2Triangles(13, 14, 11, 0, 13, 15, 14, 0),
	gsSP2Triangles(16, 17, 18, 0, 17, 19, 18, 0),
	gsSP2Triangles(20, 21, 5, 0, 20, 5, 22, 0),
	gsSP2Triangles(20, 22, 23, 0, 23, 24, 20, 0),
	gsSP2Triangles(24, 23, 25, 0, 26, 1, 27, 0),
	gsSP2Triangles(26, 27, 28, 0, 26, 28, 18, 0),
	gsSP1Triangle(29, 30, 31, 0),
	gsSPVertex(fast64_dl_Room6Mesh_mesh_layer_Opaque_vtx_2 + 32, 3, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSPEndDisplayList(),
};

Vtx fast64_dl_Room6Mesh_mesh_layer_Opaque_vtx_3[9] = {
	{{{-1160, -629, -762},0, {3666, -160},{0xFF, 0x98, 0x79, 0xFF}}},
	{{{-1160, -629, -483},0, {1387, -2423},{0xFF, 0x98, 0x79, 0xFF}}},
	{{{-1080, -629, -403},0, {84, -2420},{0xFF, 0x98, 0x79, 0xFF}}},
	{{{-1080, -629, -842},0, {3667, 1142},{0xFF, 0x98, 0x79, 0xFF}}},
	{{{-557, -629, -711},0, {-1665, 4363},{0xFF, 0x3A, 0x24, 0xFF}}},
	{{{-557, -629, -470},0, {-3632, 2416},{0xFF, 0xC7, 0xA1, 0xFF}}},
	{{{-623, -629, -403},0, {-3632, 1296},{0xFF, 0x98, 0x79, 0xFF}}},
	{{{-557, -629, -529},0, {-3152, 2891},{0xFF, 0x7D, 0x62, 0xFF}}},
	{{{-557, -629, -842},0, {-592, 5424},{0xFF, 0x98, 0x79, 0xFF}}},
};

Gfx fast64_dl_Room6Mesh_mesh_layer_Opaque_tri_3[] = {
	gsSPVertex(fast64_dl_Room6Mesh_mesh_layer_Opaque_vtx_3 + 0, 9, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 0, 2, 0),
	gsSP2Triangles(2, 4, 3, 0, 2, 5, 4, 0),
	gsSP2Triangles(2, 6, 5, 0, 5, 7, 4, 0),
	gsSP1Triangle(4, 8, 3, 0),
	gsSPEndDisplayList(),
};

Vtx fast64_dl_Room6Mesh_mesh_layer_Opaque_vtx_4[30] = {
	{{{-314, -463, -467},0, {18620, -784},{0x54, 0x54, 0x54, 0xFF}}},
	{{{-314, -431, -467},0, {18620, -1232},{0x54, 0x54, 0x54, 0xFF}}},
	{{{-313, -431, -845},0, {12432, -1264},{0x54, 0x54, 0x54, 0xFF}}},
	{{{-314, -579, -842},0, {12464, 880},{0x54, 0x54, 0x54, 0xFF}}},
	{{{-314, -579, -467},0, {18608, 880},{0x54, 0x54, 0x54, 0xFF}}},
	{{{-314, -463, -467},0, {18620, -784},{0x54, 0x54, 0x54, 0xFF}}},
	{{{-314, -463, -467},0, {-20010, -815},{0x7A, 0x7A, 0x7A, 0xFF}}},
	{{{-376, -464, -403},0, {-18544, -784},{0x7A, 0x7A, 0x7A, 0xFF}}},
	{{{-376, -431, -403},0, {-18544, -1264},{0x7A, 0x7A, 0x7A, 0xFF}}},
	{{{-314, -431, -467},0, {-20010, -1295},{0x7A, 0x7A, 0x7A, 0xFF}}},
	{{{-1160, -431, -483},0, {-5743, -1283},{0x64, 0x3B, 0x3D, 0xFF}}},
	{{{-1160, -629, -762},0, {-1265, 1776},{0xFF, 0x25, 0x0, 0xFF}}},
	{{{-1160, -431, -762},0, {-1265, -1283},{0x64, 0x3B, 0x3D, 0xFF}}},
	{{{-1160, -629, -483},0, {-5743, 1776},{0xFF, 0x25, 0x0, 0xFF}}},
	{{{-1080, -431, -403},0, {-7024, -1283},{0x64, 0x3B, 0x3D, 0xFF}}},
	{{{-1080, -629, -403},0, {-7056, 1776},{0xFF, 0x25, 0x0, 0xFF}}},
	{{{-1080, -629, -842},0, {48, 1776},{0xFF, 0x25, 0x0, 0xFF}}},
	{{{-1160, -431, -762},0, {-1264, -1296},{0x64, 0x3B, 0x3D, 0xFF}}},
	{{{-1160, -629, -762},0, {-1264, 1776},{0xFF, 0x25, 0x0, 0xFF}}},
	{{{-1080, -431, -843},0, {16, -1296},{0x64, 0x3B, 0x3D, 0xFF}}},
	{{{-557, -629, -842},0, {8528, 1776},{0xFF, 0x25, 0x0, 0xFF}}},
	{{{-465, -579, -842},0, {10064, 880},{0xB6, 0x58, 0x54, 0xFF}}},
	{{{-313, -431, -845},0, {12464, -1264},{0x56, 0x77, 0x7A, 0xFF}}},
	{{{-314, -579, -842},0, {12464, 880},{0x6D, 0x6D, 0x6D, 0xFF}}},
	{{{-376, -464, -403},0, {-18544, -784},{0x6D, 0x6D, 0x6D, 0xFF}}},
	{{{-376, -579, -403},0, {-18544, 880},{0x6D, 0x6D, 0x6D, 0xFF}}},
	{{{-531, -579, -403},0, {-16144, 880},{0x98, 0x62, 0x61, 0xFF}}},
	{{{-376, -431, -403},0, {-18544, -1264},{0x6D, 0x6D, 0x6D, 0xFF}}},
	{{{-1080, -431, -403},0, {-7024, -1296},{0x64, 0x3B, 0x3D, 0xFF}}},
	{{{-623, -629, -403},0, {-14640, 1776},{0xFF, 0x25, 0x0, 0xFF}}},
};

Gfx fast64_dl_Room6Mesh_mesh_layer_Opaque_tri_4[] = {
	gsSPVertex(fast64_dl_Room6Mesh_mesh_layer_Opaque_vtx_4 + 0, 30, 0),
	gsSP2Triangles(0, 1, 2, 0, 2, 3, 4, 0),
	gsSP2Triangles(2, 4, 5, 0, 6, 7, 8, 0),
	gsSP2Triangles(6, 8, 9, 0, 10, 11, 12, 0),
	gsSP2Triangles(10, 13, 11, 0, 13, 10, 14, 0),
	gsSP2Triangles(13, 14, 15, 0, 16, 17, 18, 0),
	gsSP2Triangles(16, 19, 17, 0, 19, 16, 20, 0),
	gsSP2Triangles(19, 20, 21, 0, 22, 19, 21, 0),
	gsSP2Triangles(23, 22, 21, 0, 24, 25, 26, 0),
	gsSP2Triangles(27, 24, 26, 0, 28, 27, 26, 0),
	gsSP2Triangles(26, 29, 28, 0, 29, 15, 28, 0),
	gsSPEndDisplayList(),
};

Vtx fast64_dl_Room6Mesh_001_mesh_layer_Transparent_vtx_cull[8] = {
	{{{-1184, -619, -373},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{-1184, -619, -373},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{-1184, -619, -879},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{-1184, -619, -879},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{-524, -619, -373},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{-524, -619, -373},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{-524, -619, -879},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{-524, -619, -879},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
};

Vtx fast64_dl_Room6Mesh_001_mesh_layer_Transparent_vtx_0[7] = {
	{{{-1184, -619, -879},0, {4075, 731},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-1184, -619, -373},0, {492, -2828},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-601, -619, -373},0, {-3632, 1296},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-524, -619, -879},0, {-592, 5424},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-524, -619, -518},0, {-3152, 2891},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-524, -619, -450},0, {-3632, 2416},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-524, -619, -728},0, {-1665, 4363},{0x0, 0x7F, 0x0, 0xFF}}},
};

Gfx fast64_dl_Room6Mesh_001_mesh_layer_Transparent_tri_0[] = {
	gsSPVertex(fast64_dl_Room6Mesh_001_mesh_layer_Transparent_vtx_0 + 0, 7, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 0, 2, 0),
	gsSP2Triangles(2, 4, 3, 0, 2, 5, 4, 0),
	gsSP1Triangle(4, 6, 3, 0),
	gsSPEndDisplayList(),
};

Gfx mat_fast64_dl_LavaFadeFloorNoSlip_layerOpaque[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, 1, COMBINED, 0, PRIMITIVE, 0, 0, 0, 0, COMBINED),
	gsSPLoadGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BACK | G_FOG | G_SHADING_SMOOTH),
	gsSPSetOtherMode(G_SETOTHERMODE_H, 4, 20, G_AD_NOISE | G_CD_MAGICSQ | G_CK_NONE | G_TC_FILT | G_TF_BILERP | G_TL_TILE | G_TD_CLAMP | G_TP_PERSP | G_CYC_2CYCLE | G_PM_NPRIMITIVE),
	gsSPSetOtherMode(G_SETOTHERMODE_L, 0, 32, G_AC_NONE | G_ZS_PIXEL | G_RM_FOG_SHADE_A | G_RM_AA_ZB_OPA_SURF2),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetTextureLUT(G_TT_RGBA16),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, fast64_dl_Shrine_Floor_Fade_00_ci8_pal_rgba16),
	gsDPTileSync(),
	gsDPSetTile(0, 0, 0, 256, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadSync(),
	gsDPLoadTLUTCmd(7, 200),
	gsDPPipeSync(),
	gsDPTileSync(),
	gsDPSetTextureImage(G_IM_FMT_CI, G_IM_SIZ_8b_LOAD_BLOCK, 1, fast64_dl_Shrine_Floor_Fade_00_ci8),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_8b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_MIRROR, 5, 0),
	gsDPLoadSync(),
	gsDPLoadBlock(7, 0, 0, 511, 512),
	gsDPPipeSync(),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_8b, 4, 0, 0, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_MIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsDPSetPrimColor(0, 0, 245, 176, 196, 255),
	gsSPEndDisplayList(),
};

Gfx fast64_dl_Room6Mesh_mesh_layer_Opaque[] = {
	gsSPClearGeometryMode(G_LIGHTING),
	gsSPVertex(fast64_dl_Room6Mesh_mesh_layer_Opaque_vtx_cull + 0, 8, 0),
	gsSPCullDisplayList(0, 7),
	gsSPDisplayList(mat_fast64_dl_DoorTrim_layerOpaque),
	gsSPDisplayList(fast64_dl_Room6Mesh_mesh_layer_Opaque_tri_0),
	gsSPDisplayList(mat_fast64_dl_ObsidianFloor_layerOpaque),
	gsSPDisplayList(fast64_dl_Room6Mesh_mesh_layer_Opaque_tri_1),
	gsSPDisplayList(mat_fast64_dl_LavaFadeFloorNoSlip_layerOpaque),
	gsSPDisplayList(fast64_dl_Room6Mesh_mesh_layer_Opaque_tri_2),
	gsSPDisplayList(mat_fast64_dl_VoidLava_layerOpaque),
	gsSPDisplayList(fast64_dl_Room6Mesh_mesh_layer_Opaque_tri_3),
	gsSPDisplayList(mat_fast64_dl_Brick_layerOpaque),
	gsSPDisplayList(fast64_dl_Room6Mesh_mesh_layer_Opaque_tri_4),
	gsSPEndDisplayList(),
};

Gfx fast64_dl_Room6Mesh_001_mesh_layer_Transparent[] = {
	gsSPClearGeometryMode(G_LIGHTING),
	gsSPVertex(fast64_dl_Room6Mesh_001_mesh_layer_Transparent_vtx_cull + 0, 8, 0),
	gsSPCullDisplayList(0, 7),
	gsSPDisplayList(mat_fast64_dl_LavaFog_layerTransparent),
	gsSPDisplayList(fast64_dl_Room6Mesh_001_mesh_layer_Transparent_tri_0),
	gsSPEndDisplayList(),
};

