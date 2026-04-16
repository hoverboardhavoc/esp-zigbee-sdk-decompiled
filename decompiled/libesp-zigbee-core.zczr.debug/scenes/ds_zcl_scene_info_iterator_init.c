/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> scenes.o -> ds_zcl_scene_info_iterator_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void ds_zcl_scene_info_iterator_init(zcl_scene_info_iterator_t *itor)

{
  *(undefined1 *)&itor->length = 0;
  *(undefined1 *)((int)&itor->length + 1) = 0;
  *(undefined1 *)&itor->index = 0;
  *(undefined1 *)((int)&itor->index + 1) = 0;
  itor->is_done = false;
  itor->field_0x5 = 0;
  itor->field_0x6 = 0;
  itor->field_0x7 = 0;
  *(undefined1 *)&itor->blob = 0;
  *(undefined1 *)((int)&itor->blob + 1) = 0;
  *(undefined1 *)((int)&itor->blob + 2) = 0;
  *(undefined1 *)((int)&itor->blob + 3) = 0;
  ds_zcl_scene_info_read(itor);
  return;
}

