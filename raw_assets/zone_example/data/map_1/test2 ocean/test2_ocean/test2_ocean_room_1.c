#include "ultra64.h"
#include "z64.h"
#include "macros.h"
#include "test2_ocean_scene.h"

#include "segment_symbols.h"
#include "command_macros_base.h"
#include "z64cutscene_commands.h"
#include "variables.h"

SCmdBase test2_ocean_room_1_header00[] = {
	SCENE_CMD_ECHO_SETTINGS(0x00),
	SCENE_CMD_ROOM_BEHAVIOR(0x00, 0x00, false, false),
	SCENE_CMD_SKYBOX_DISABLES(false, false),
	SCENE_CMD_TIME_SETTINGS(0xFF, 0xFF, 10),
	SCENE_CMD_MESH(&test2_ocean_room_1_meshHeader),
	SCENE_CMD_END(),
};

MeshHeader0 test2_ocean_room_1_meshHeader = { {0}, 1, (u32)&test2_ocean_room_1_meshDListEntry, (u32)&(test2_ocean_room_1_meshDListEntry) + sizeof(test2_ocean_room_1_meshDListEntry) };

MeshEntry0 test2_ocean_room_1_meshDListEntry[1] = {
	{ (u32)test2_ocean_room_1_entry_0_opaque, (u32)test2_ocean_room_1_entry_0_transparent },
};

Gfx test2_ocean_room_1_entry_0_opaque[] = {
	gsSPDisplayList(test2_ocean_dl_Floor_001_mesh_layer_Opaque),
	gsSPEndDisplayList(),
};

Gfx test2_ocean_room_1_entry_0_transparent[] = {
	gsSPDisplayList(test2_ocean_dl_Water_001_mesh_layer_Transparent),
	gsSPEndDisplayList(),
};

Vtx test2_ocean_dl_Floor_001_mesh_layer_Opaque_vtx_0[29] = {
	{{{-300, -214, -586},0, {-16, 1008},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{-300, -214, -1473},0, {-16, 1008},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{-300, 339, -1473},0, {-16, 1008},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{-300, 339, -586},0, {-16, 1008},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{-300, -214, -1473},0, {-4619, 5742},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-300, -214, -856},0, {-4619, -4779},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{300, -214, -856},0, {5611, -4779},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{300, -214, -1473},0, {5611, 5742},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-240, 51, -606},0, {-3596, -4779},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{300, 51, -606},0, {5611, -4779},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{300, 51, -856},0, {5611, -4779},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-300, 51, -856},0, {-4619, -4779},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-300, 51, -606},0, {-4619, -4779},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-240, 51, -586},0, {-3596, -4779},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-300, 51, -586},0, {-4619, -4779},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{300, 339, -606},0, {5611, -4779},{0x0, 0x0, 0x81, 0xFF}}},
	{{{300, 51, -606},0, {5611, -4779},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-240, 51, -606},0, {-3596, -4779},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-240, 151, -606},0, {-3596, -4779},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-300, 339, -606},0, {-4619, -4779},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-300, 151, -606},0, {-4619, -4779},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-240, 151, -606},0, {-3596, -4779},{0x0, 0x81, 0x0, 0xFF}}},
	{{{-240, 151, -586},0, {-3596, -4779},{0x0, 0x81, 0x0, 0xFF}}},
	{{{-300, 151, -586},0, {-4619, -4779},{0x0, 0x81, 0x0, 0xFF}}},
	{{{-300, 151, -606},0, {-4619, -4779},{0x0, 0x81, 0x0, 0xFF}}},
	{{{-240, 51, -606},0, {-3596, -4779},{0x81, 0x0, 0x0, 0xFF}}},
	{{{-240, 51, -586},0, {-3596, -4779},{0x81, 0x0, 0x0, 0xFF}}},
	{{{-240, 151, -586},0, {-3596, -4779},{0x81, 0x0, 0x0, 0xFF}}},
	{{{-240, 151, -606},0, {-3596, -4779},{0x81, 0x0, 0x0, 0xFF}}},
};

Gfx test2_ocean_dl_Floor_001_mesh_layer_Opaque_tri_0[] = {
	gsSPVertex(test2_ocean_dl_Floor_001_mesh_layer_Opaque_vtx_0 + 0, 15, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 2, 3, 0),
	gsSP1Triangle(4, 5, 6, 0),
	gsSP1Triangle(4, 6, 7, 0),
	gsSP1Triangle(8, 9, 10, 0),
	gsSP1Triangle(8, 10, 11, 0),
	gsSP1Triangle(11, 12, 8, 0),
	gsSP1Triangle(12, 13, 8, 0),
	gsSP1Triangle(12, 14, 13, 0),
	gsSPVertex(test2_ocean_dl_Floor_001_mesh_layer_Opaque_vtx_0 + 15, 14, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 2, 3, 0),
	gsSP1Triangle(3, 4, 0, 0),
	gsSP1Triangle(3, 5, 4, 0),
	gsSP1Triangle(6, 7, 8, 0),
	gsSP1Triangle(6, 8, 9, 0),
	gsSP1Triangle(10, 11, 12, 0),
	gsSP1Triangle(10, 12, 13, 0),
	gsSPEndDisplayList(),
};

Vtx test2_ocean_dl_Floor_001_mesh_layer_Opaque_vtx_1[4] = {
	{{{-300, -214, -856},0, {2154, 4898},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-300, 51, -856},0, {2154, -3906},{0x0, 0x0, 0x81, 0xFF}}},
	{{{300, 51, -856},0, {-1734, -3906},{0x0, 0x0, 0x81, 0xFF}}},
	{{{300, -214, -856},0, {-1734, 4898},{0x0, 0x0, 0x81, 0xFF}}},
};

Gfx test2_ocean_dl_Floor_001_mesh_layer_Opaque_tri_1[] = {
	gsSPVertex(test2_ocean_dl_Floor_001_mesh_layer_Opaque_vtx_1 + 0, 4, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 2, 3, 0),
	gsSPEndDisplayList(),
};

Vtx test2_ocean_dl_Water_001_mesh_layer_Transparent_vtx_0[4] = {
	{{{-300, -120, -1473},0, {-9744, 11012},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-300, -120, -856},0, {-9744, -10049},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{300, -120, -856},0, {10736, -10049},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{300, -120, -1473},0, {10736, 11012},{0x0, 0x7F, 0x0, 0xFF}}},
};

Gfx test2_ocean_dl_Water_001_mesh_layer_Transparent_tri_0[] = {
	gsSPVertex(test2_ocean_dl_Water_001_mesh_layer_Transparent_vtx_0 + 0, 4, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 2, 3, 0),
	gsSPEndDisplayList(),
};

Gfx test2_ocean_dl_Floor_001_mesh_layer_Opaque[] = {
	gsSPDisplayList(mat_test2_ocean_dl_sand_layerOpaque),
	gsSPDisplayList(test2_ocean_dl_Floor_001_mesh_layer_Opaque_tri_0),
	gsSPDisplayList(mat_test2_ocean_dl_climb_layerOpaque),
	gsSPDisplayList(test2_ocean_dl_Floor_001_mesh_layer_Opaque_tri_1),
	gsSPEndDisplayList(),
};

Gfx test2_ocean_dl_Water_001_mesh_layer_Transparent[] = {
	gsSPDisplayList(mat_test2_ocean_dl_floor_mat_layerTransparent),
	gsSPDisplayList(test2_ocean_dl_Water_001_mesh_layer_Transparent_tri_0),
	gsSPEndDisplayList(),
};
