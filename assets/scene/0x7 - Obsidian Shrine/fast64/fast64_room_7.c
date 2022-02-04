#include "ultra64.h"
#include "z64.h"
#include "macros.h"
#include "fast64_scene.h"

#include "segment_symbols.h"
#include "command_macros_base.h"
#include "z64cutscene_commands.h"
#include "variables.h"

SCmdBase fast64_room_7_header00[] = {
	SCENE_CMD_ECHO_SETTINGS(0x04),
	SCENE_CMD_ROOM_BEHAVIOR(0x00, 0x02, false, false),
	SCENE_CMD_SKYBOX_DISABLES(false, true),
	SCENE_CMD_TIME_SETTINGS(0xFF, 0xFF, 10),
	SCENE_CMD_MESH(&fast64_room_7_meshHeader),
	SCENE_CMD_OBJECT_LIST(4, &fast64_room_7_header00_objectList),
	SCENE_CMD_ACTOR_LIST(11, &fast64_room_7_header00_actorList),
	SCENE_CMD_END(),
};

s16 fast64_room_7_header00_objectList[4] = {
	OBJECT_SYOKUDAI,
	OBJECT_AM,
	OBJECT_BW,
	OBJECT_FIREFLY,
};

ActorEntry fast64_room_7_header00_actorList[11] = {
	{ ACTOR_EN_FIREFLY, -286, -281, -863, 0, 18998, 0, 0x0000 },
	{ ACTOR_EN_BW, -119, -379, -1083, 0, 764, 0, 0xFFFF },
	{ ACTOR_EN_AM, -118, -369, -1368, 0, 0, 0, 0xFFFF },
	{ ACTOR_EN_AM, -252, -369, -1369, 0, 0, 0, 0xFFFF },
	{ ACTOR_EN_BW, -79, -369, -1357, 0, 60485, 0, 0xFFFF },
	{ ACTOR_EN_BW, -315, -369, -1299, 0, 7816, 0, 0xFFFF },
	{ ACTOR_EN_FIREFLY, -387, -265, -1367, 0, 5373, 0, 0x0000 },
	{ ACTOR_EN_BW, -352, -379, -871, 0, 22504, 0, 0xFFFF },
	{ ACTOR_EN_FIREFLY, 3, -279, -1355, 0, 63177, 0, 0x0000 },
	{ ACTOR_OBJ_SYOKUDAI, 16, -369, -1369, 0, 16502, 0, 0x143F },
	{ ACTOR_OBJ_SYOKUDAI, -385, -369, -1369, 0, 16502, 0, 0x143F },
};

MeshHeader0 fast64_room_7_meshHeader = { {0}, 1, (u32)&fast64_room_7_meshDListEntry, (u32)&(fast64_room_7_meshDListEntry) + sizeof(fast64_room_7_meshDListEntry) };

MeshEntry0 fast64_room_7_meshDListEntry[1] = {
	{ (u32)fast64_room_7_entry_0_opaque, (u32)0 },
};

Gfx fast64_room_7_entry_0_opaque[] = {
	gsSPDisplayList(fast64_dl_Room7Mesh_mesh_layer_Opaque),
	gsSPEndDisplayList(),
};

Vtx fast64_dl_Room7Mesh_mesh_layer_Opaque_vtx_cull[8] = {
	{{{-452, -379, -725},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{-452, -179, -725},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{-452, -179, -1444},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{-452, -379, -1444},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{152, -379, -725},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{152, -179, -725},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{152, -179, -1444},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{152, -379, -1444},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
};

Vtx fast64_dl_Room7Mesh_mesh_layer_Opaque_vtx_0[48] = {
	{{{-91, -279, -745},0, {-1552, 496},{0x63, 0x63, 0x63, 0xFF}}},
	{{{-91, -279, -725},0, {-1552, 400},{0x0, 0x0, 0x0, 0xFF}}},
	{{{-91, -379, -725},0, {1488, 400},{0x0, 0x0, 0x0, 0xFF}}},
	{{{-91, -379, -745},0, {1488, 496},{0x63, 0x63, 0x63, 0xFF}}},
	{{{-31, -379, -745},0, {1488, 496},{0x63, 0x63, 0x63, 0xFF}}},
	{{{-31, -379, -725},0, {1488, 400},{0x0, 0x0, 0x0, 0xFF}}},
	{{{-31, -279, -725},0, {-1552, 400},{0x0, 0x0, 0x0, 0xFF}}},
	{{{-31, -279, -745},0, {-1552, 496},{0x63, 0x63, 0x63, 0xFF}}},
	{{{-31, -279, -745},0, {-1616, 496},{0x41, 0x41, 0x41, 0xFF}}},
	{{{-31, -279, -725},0, {-1616, 400},{0x0, 0x0, 0x0, 0xFF}}},
	{{{-91, -279, -725},0, {464, 400},{0x0, 0x0, 0x0, 0xFF}}},
	{{{-91, -279, -745},0, {464, 496},{0x41, 0x41, 0x41, 0xFF}}},
	{{{-106, -264, -745},0, {-2032, 496},{0x49, 0x47, 0x47, 0xFF}}},
	{{{-91, -279, -745},0, {-1552, -16},{0x79, 0x79, 0x79, 0xFF}}},
	{{{-91, -379, -745},0, {1488, -16},{0x59, 0x58, 0x58, 0xFF}}},
	{{{-106, -379, -745},0, {1488, 496},{0x59, 0x58, 0x58, 0xFF}}},
	{{{-16, -264, -745},0, {-2032, 496},{0x49, 0x47, 0x47, 0xFF}}},
	{{{-16, -379, -745},0, {1488, 496},{0x59, 0x58, 0x58, 0xFF}}},
	{{{-31, -379, -745},0, {1488, -16},{0x59, 0x58, 0x58, 0xFF}}},
	{{{-31, -279, -745},0, {-1552, -16},{0x85, 0x84, 0x84, 0xFF}}},
	{{{-106, -264, -745},0, {-2096, 496},{0x49, 0x47, 0x47, 0xFF}}},
	{{{-16, -264, -745},0, {944, 496},{0x49, 0x47, 0x47, 0xFF}}},
	{{{-31, -279, -745},0, {464, -16},{0x85, 0x84, 0x84, 0xFF}}},
	{{{-91, -279, -745},0, {-1616, -16},{0x79, 0x79, 0x79, 0xFF}}},
	{{{132, -279, -994},0, {-1552, 496},{0x63, 0x63, 0x63, 0xFF}}},
	{{{152, -279, -994},0, {-1552, 400},{0x0, 0x0, 0x0, 0xFF}}},
	{{{152, -379, -994},0, {1488, 400},{0x0, 0x0, 0x0, 0xFF}}},
	{{{132, -379, -994},0, {1488, 496},{0x63, 0x63, 0x63, 0xFF}}},
	{{{132, -379, -1054},0, {1488, 496},{0x63, 0x63, 0x63, 0xFF}}},
	{{{152, -379, -1054},0, {1488, 400},{0x0, 0x0, 0x0, 0xFF}}},
	{{{152, -279, -1054},0, {-1552, 400},{0x0, 0x0, 0x0, 0xFF}}},
	{{{132, -279, -1054},0, {-1552, 496},{0x63, 0x63, 0x63, 0xFF}}},
	{{{132, -279, -1054},0, {-1616, 496},{0x41, 0x41, 0x41, 0xFF}}},
	{{{152, -279, -1054},0, {-1616, 400},{0x0, 0x0, 0x0, 0xFF}}},
	{{{152, -279, -994},0, {464, 400},{0x0, 0x0, 0x0, 0xFF}}},
	{{{132, -279, -994},0, {464, 496},{0x41, 0x41, 0x41, 0xFF}}},
	{{{132, -264, -979},0, {-2032, 496},{0x49, 0x47, 0x47, 0xFF}}},
	{{{132, -279, -994},0, {-1552, -16},{0x84, 0x84, 0x84, 0xFF}}},
	{{{132, -379, -994},0, {1488, -16},{0x49, 0x47, 0x47, 0xFF}}},
	{{{132, -379, -979},0, {1488, 496},{0x49, 0x47, 0x47, 0xFF}}},
	{{{132, -264, -1069},0, {-2032, 496},{0x49, 0x47, 0x47, 0xFF}}},
	{{{132, -379, -1069},0, {1488, 496},{0x49, 0x47, 0x47, 0xFF}}},
	{{{132, -379, -1054},0, {1488, -16},{0x49, 0x47, 0x47, 0xFF}}},
	{{{132, -279, -1054},0, {-1552, -16},{0x7C, 0x7C, 0x7C, 0xFF}}},
	{{{132, -264, -979},0, {-2096, 496},{0x49, 0x47, 0x47, 0xFF}}},
	{{{132, -264, -1069},0, {944, 496},{0x49, 0x47, 0x47, 0xFF}}},
	{{{132, -279, -1054},0, {464, -16},{0x7C, 0x7C, 0x7C, 0xFF}}},
	{{{132, -279, -994},0, {-1616, -16},{0x84, 0x84, 0x84, 0xFF}}},
};

Gfx fast64_dl_Room7Mesh_mesh_layer_Opaque_tri_0[] = {
	gsSPVertex(fast64_dl_Room7Mesh_mesh_layer_Opaque_vtx_0 + 0, 32, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
	gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
	gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
	gsSP2Triangles(16, 17, 18, 0, 16, 18, 19, 0),
	gsSP2Triangles(20, 21, 22, 0, 20, 22, 23, 0),
	gsSP2Triangles(24, 25, 26, 0, 24, 26, 27, 0),
	gsSP2Triangles(28, 29, 30, 0, 28, 30, 31, 0),
	gsSPVertex(fast64_dl_Room7Mesh_mesh_layer_Opaque_vtx_0 + 32, 16, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
	gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
	gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
	gsSPEndDisplayList(),
};

Vtx fast64_dl_Room7Mesh_mesh_layer_Opaque_vtx_1[44] = {
	{{{-412, -179, -745},0, {2032, -714},{0x47, 0x33, 0x33, 0xFF}}},
	{{{-452, -219, -1444},0, {9392, -80},{0x6D, 0x6D, 0x6D, 0xFF}}},
	{{{-412, -179, -1444},0, {9392, -714},{0x6D, 0x6D, 0x6D, 0xFF}}},
	{{{-452, -219, -745},0, {2032, -80},{0x47, 0x33, 0x33, 0xFF}}},
	{{{-452, -379, -1140},0, {6191, 1712},{0x6D, 0x6D, 0x6D, 0xFF}}},
	{{{-452, -379, -745},0, {2032, 1712},{0x47, 0x33, 0x33, 0xFF}}},
	{{{-452, -299, -1444},0, {9392, 816},{0xFF, 0xA6, 0x70, 0xFF}}},
	{{{-452, -379, -1444},0, {9392, 1712},{0xDC, 0x8B, 0x63, 0xFF}}},
	{{{42, -179, -1140},0, {16267, -661},{0x60, 0x5B, 0x5B, 0xFF}}},
	{{{132, -219, -1100},0, {16777, -80},{0x47, 0x33, 0x33, 0xFF}}},
	{{{132, -179, -1100},0, {16777, -528},{0x47, 0x33, 0x33, 0xFF}}},
	{{{82, -219, -1140},0, {16102, -80},{0x47, 0x33, 0x33, 0xFF}}},
	{{{42, -179, -1444},0, {12691, -621},{0x6D, 0x6D, 0x6D, 0xFF}}},
	{{{82, -219, -1444},0, {12902, -80},{0x6F, 0x6D, 0x6D, 0xFF}}},
	{{{82, -299, -1444},0, {12902, 816},{0xFF, 0xA3, 0x6F, 0xFF}}},
	{{{-185, -299, -1444},0, {10192, 816},{0xA0, 0x7B, 0x7A, 0xFF}}},
	{{{-412, -179, -1444},0, {7648, -548},{0x6D, 0x6D, 0x6D, 0xFF}}},
	{{{-452, -299, -1444},0, {7273, 839},{0xFF, 0xA6, 0x70, 0xFF}}},
	{{{-452, -219, -1444},0, {7248, -80},{0x6D, 0x6D, 0x6D, 0xFF}}},
	{{{-452, -379, -1444},0, {7298, 1759},{0xDC, 0x8B, 0x63, 0xFF}}},
	{{{-185, -379, -1444},0, {10096, 1744},{0x73, 0x58, 0x58, 0xFF}}},
	{{{82, -379, -1444},0, {12902, 1712},{0xEA, 0x94, 0x67, 0xFF}}},
	{{{82, -379, -1140},0, {16102, 1712},{0x4B, 0x3A, 0x3A, 0xFF}}},
	{{{82, -299, -1140},0, {16102, 816},{0x47, 0x33, 0x33, 0xFF}}},
	{{{132, -379, -1100},0, {16777, 1712},{0x47, 0x33, 0x33, 0xFF}}},
	{{{-452, -379, -745},0, {4487, 1796},{0x47, 0x33, 0x33, 0xFF}}},
	{{{-452, -219, -745},0, {4581, -68},{0x47, 0x33, 0x33, 0xFF}}},
	{{{-412, -179, -745},0, {4107, -548},{0x47, 0x33, 0x33, 0xFF}}},
	{{{-106, -264, -745},0, {80, 400},{0xC0, 0xA3, 0x8D, 0xFF}}},
	{{{132, -179, -745},0, {-2672, -624},{0x47, 0x33, 0x33, 0xFF}}},
	{{{-16, -264, -745},0, {-944, 400},{0xC0, 0xA3, 0x8D, 0xFF}}},
	{{{132, -379, -745},0, {-2640, 1712},{0x4C, 0x3B, 0x3B, 0xFF}}},
	{{{132, -379, -745},0, {-2640, 1712},{0x4C, 0x3B, 0x3B, 0xFF}}},
	{{{-16, -379, -745},0, {-944, 1712},{0x8E, 0x7C, 0x6F, 0xFF}}},
	{{{-16, -264, -745},0, {-944, 400},{0xC0, 0xA3, 0x8D, 0xFF}}},
	{{{-106, -264, -745},0, {80, 400},{0xC0, 0xA3, 0x8D, 0xFF}}},
	{{{-106, -379, -745},0, {80, 1712},{0x99, 0x82, 0x70, 0xFF}}},
	{{{-452, -379, -745},0, {4487, 1796},{0x47, 0x33, 0x33, 0xFF}}},
	{{{-412, -179, -1444},0, {9590, 1452},{0x6D, 0x6D, 0x6D, 0xFF}}},
	{{{42, -179, -1444},0, {9619, -3247},{0x6D, 0x6D, 0x6D, 0xFF}}},
	{{{42, -179, -1140},0, {6166, -3268},{0x6D, 0x6D, 0x6D, 0xFF}}},
	{{{-412, -179, -745},0, {1651, 1404},{0x47, 0x33, 0x33, 0xFF}}},
	{{{132, -179, -745},0, {1686, -4228},{0x47, 0x33, 0x33, 0xFF}}},
	{{{132, -179, -1100},0, {5716, -4204},{0x6D, 0x6D, 0x6D, 0xFF}}},
};

Gfx fast64_dl_Room7Mesh_mesh_layer_Opaque_tri_1[] = {
	gsSPVertex(fast64_dl_Room7Mesh_mesh_layer_Opaque_vtx_1 + 0, 32, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
	gsSP2Triangles(1, 3, 4, 0, 3, 5, 4, 0),
	gsSP2Triangles(4, 6, 1, 0, 4, 7, 6, 0),
	gsSP2Triangles(8, 9, 10, 0, 8, 11, 9, 0),
	gsSP2Triangles(12, 11, 8, 0, 12, 13, 11, 0),
	gsSP2Triangles(14, 13, 12, 0, 15, 14, 12, 0),
	gsSP2Triangles(15, 12, 16, 0, 16, 17, 15, 0),
	gsSP2Triangles(16, 18, 17, 0, 15, 17, 19, 0),
	gsSP2Triangles(20, 15, 19, 0, 20, 21, 15, 0),
	gsSP2Triangles(21, 14, 15, 0, 22, 14, 21, 0),
	gsSP2Triangles(22, 23, 14, 0, 23, 22, 24, 0),
	gsSP2Triangles(23, 24, 9, 0, 9, 11, 23, 0),
	gsSP2Triangles(23, 11, 13, 0, 23, 13, 14, 0),
	gsSP2Triangles(25, 26, 27, 0, 25, 27, 28, 0),
	gsSP2Triangles(27, 29, 28, 0, 29, 30, 28, 0),
	gsSP1Triangle(29, 31, 30, 0),
	gsSPVertex(fast64_dl_Room7Mesh_mesh_layer_Opaque_vtx_1 + 32, 12, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
	gsSP2Triangles(6, 7, 8, 0, 9, 6, 8, 0),
	gsSP2Triangles(8, 10, 9, 0, 8, 11, 10, 0),
	gsSPEndDisplayList(),
};

Vtx fast64_dl_Room7Mesh_mesh_layer_Opaque_vtx_2[11] = {
	{{{132, -264, -979},0, {-35, 443},{0xC0, 0xA3, 0x8D, 0xFF}}},
	{{{132, -379, -979},0, {-35, 2320},{0x6D, 0x6D, 0x6D, 0xFF}}},
	{{{132, -379, -745},0, {3824, 2320},{0x4C, 0x3B, 0x3B, 0xFF}}},
	{{{132, -179, -745},0, {3824, -944},{0x47, 0x33, 0x33, 0xFF}}},
	{{{132, -264, -1069},0, {-1520, 443},{0xC0, 0xA3, 0x8D, 0xFF}}},
	{{{132, -264, -979},0, {-35, 443},{0xC0, 0xA3, 0x8D, 0xFF}}},
	{{{132, -179, -1100},0, {-2032, -944},{0x47, 0x33, 0x33, 0xFF}}},
	{{{132, -219, -1100},0, {-2032, -291},{0x47, 0x33, 0x33, 0xFF}}},
	{{{132, -379, -1069},0, {-1520, 2320},{0x8F, 0x77, 0x6E, 0xFF}}},
	{{{132, -264, -1069},0, {-1520, 443},{0xC0, 0xA3, 0x8D, 0xFF}}},
	{{{132, -379, -1100},0, {-2032, 2320},{0x47, 0x33, 0x33, 0xFF}}},
};

Gfx fast64_dl_Room7Mesh_mesh_layer_Opaque_tri_2[] = {
	gsSPVertex(fast64_dl_Room7Mesh_mesh_layer_Opaque_vtx_2 + 0, 11, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSP2Triangles(4, 5, 3, 0, 4, 3, 6, 0),
	gsSP2Triangles(4, 6, 7, 0, 8, 9, 7, 0),
	gsSP1Triangle(8, 7, 10, 0),
	gsSPEndDisplayList(),
};

Vtx fast64_dl_Room7Mesh_mesh_layer_Opaque_vtx_3[17] = {
	{{{132, -379, -994},0, {1008, 1008},{0x76, 0x70, 0x70, 0xFF}}},
	{{{152, -379, -994},0, {1008, 667},{0x0, 0x0, 0x0, 0xFF}}},
	{{{152, -379, -1054},0, {-16, 667},{0x4, 0x4, 0x4, 0xFF}}},
	{{{132, -379, -1054},0, {-16, 1008},{0x76, 0x70, 0x70, 0xFF}}},
	{{{-452, -379, -745},0, {-4400, 944},{0x49, 0x37, 0x37, 0xFF}}},
	{{{-106, -379, -745},0, {-1712, 3632},{0x6D, 0x6D, 0x6D, 0xFF}}},
	{{{-452, -379, -1140},0, {-1328, -2096},{0xCE, 0xA9, 0x8E, 0xFF}}},
	{{{-12, -379, -943},0, {544, 2832},{0xAD, 0x90, 0x7C, 0xFF}}},
	{{{132, -379, -923},0, {1504, 4112},{0x75, 0x72, 0x6F, 0xFF}}},
	{{{-91, -379, -745},0, {-1584, 3760},{0xA8, 0xA8, 0xA8, 0xFF}}},
	{{{-31, -379, -745},0, {-1136, 4208},{0x6D, 0x6D, 0x6D, 0xFF}}},
	{{{-31, -379, -725},0, {-1296, 4368},{0x4, 0x4, 0x4, 0xFF}}},
	{{{-91, -379, -725},0, {-1744, 3920},{0x0, 0x0, 0x0, 0xFF}}},
	{{{-16, -379, -745},0, {-1008, 4336},{0x6D, 0x6D, 0x6D, 0xFF}}},
	{{{132, -379, -745},0, {144, 5488},{0x6D, 0x6D, 0x6D, 0xFF}}},
	{{{82, -379, -1140},0, {2800, 2032},{0x5E, 0x48, 0x42, 0xFF}}},
	{{{132, -379, -1100},0, {2864, 2736},{0x59, 0x4C, 0x4A, 0xFF}}},
};

Gfx fast64_dl_Room7Mesh_mesh_layer_Opaque_tri_3[] = {
	gsSPVertex(fast64_dl_Room7Mesh_mesh_layer_Opaque_vtx_3 + 0, 17, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSP2Triangles(4, 5, 6, 0, 6, 5, 7, 0),
	gsSP2Triangles(7, 5, 8, 0, 5, 9, 8, 0),
	gsSP2Triangles(8, 9, 10, 0, 9, 11, 10, 0),
	gsSP2Triangles(9, 12, 11, 0, 10, 13, 8, 0),
	gsSP2Triangles(13, 14, 8, 0, 6, 7, 15, 0),
	gsSP2Triangles(7, 8, 15, 0, 16, 15, 8, 0),
	gsSPEndDisplayList(),
};

Vtx fast64_dl_Room7Mesh_mesh_layer_Opaque_vtx_4[9] = {
	{{{82, -369, -1140},0, {-3216, -8208},{0x49, 0x35, 0x2B, 0xFF}}},
	{{{-452, -369, -1140},0, {-3216, -16},{0x49, 0x35, 0x2B, 0xFF}}},
	{{{-452, -379, -1140},0, {-3088, -16},{0x49, 0x35, 0x2B, 0xFF}}},
	{{{82, -379, -1140},0, {-3088, -8208},{0x49, 0x35, 0x2B, 0xFF}}},
	{{{82, -369, -1140},0, {-3088, -16},{0x6F, 0x5B, 0x51, 0xFF}}},
	{{{82, -369, -1444},0, {1008, -16},{0xFF, 0x9E, 0x6B, 0xFF}}},
	{{{-185, -369, -1444},0, {1008, -4112},{0x91, 0x53, 0x3F, 0xFF}}},
	{{{-452, -369, -1140},0, {-3088, -8208},{0x6F, 0x5B, 0x51, 0xFF}}},
	{{{-452, -369, -1444},0, {1008, -8208},{0xFF, 0x9E, 0x6B, 0xFF}}},
};

Gfx fast64_dl_Room7Mesh_mesh_layer_Opaque_tri_4[] = {
	gsSPVertex(fast64_dl_Room7Mesh_mesh_layer_Opaque_vtx_4 + 0, 9, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSP2Triangles(4, 5, 6, 0, 7, 4, 6, 0),
	gsSP1Triangle(8, 7, 6, 0),
	gsSPEndDisplayList(),
};

Gfx fast64_dl_Room7Mesh_mesh_layer_Opaque[] = {
	gsSPClearGeometryMode(G_LIGHTING),
	gsSPVertex(fast64_dl_Room7Mesh_mesh_layer_Opaque_vtx_cull + 0, 8, 0),
	gsSPCullDisplayList(0, 7),
	gsSPDisplayList(mat_fast64_dl_DoorTrim_layerOpaque),
	gsSPDisplayList(fast64_dl_Room7Mesh_mesh_layer_Opaque_tri_0),
	gsSPDisplayList(mat_fast64_dl_Walls_layerOpaque),
	gsSPDisplayList(fast64_dl_Room7Mesh_mesh_layer_Opaque_tri_1),
	gsSPDisplayList(mat_fast64_dl_Brick_layerOpaque),
	gsSPDisplayList(fast64_dl_Room7Mesh_mesh_layer_Opaque_tri_2),
	gsSPDisplayList(mat_fast64_dl_ObsidianFloor_layerOpaque),
	gsSPDisplayList(fast64_dl_Room7Mesh_mesh_layer_Opaque_tri_3),
	gsSPDisplayList(mat_fast64_dl_FloorTile_layerOpaque),
	gsSPDisplayList(fast64_dl_Room7Mesh_mesh_layer_Opaque_tri_4),
	gsSPEndDisplayList(),
};

