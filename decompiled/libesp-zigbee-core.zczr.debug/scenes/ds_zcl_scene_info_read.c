/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> scenes.o -> ds_zcl_scene_info_read
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void ds_zcl_scene_info_read(zcl_scene_info_iterator_t *itor)

{
  int iVar1;
  dataset_zcl_scene_info_t *pdVar2;
  
  if (itor->blob != (dataset_zcl_scene_info_t *)0x0) {
    mm_free();
    itor->blob = (dataset_zcl_scene_info_t *)0x0;
  }
  itor->length = 0;
  iVar1 = ds_internal_read(0xb,itor->index,0,itor);
  if (iVar1 == 0) {
    pdVar2 = (dataset_zcl_scene_info_t *)mm_alloc(1,itor->length);
    itor->blob = pdVar2;
    if ((itor->length == 0) || (pdVar2 == (dataset_zcl_scene_info_t *)0x0)) {
      itor->is_done = true;
    }
    else {
      ds_internal_read(0xb,itor->index,pdVar2,itor);
    }
  }
  else {
    itor->is_done = true;
  }
  return;
}

