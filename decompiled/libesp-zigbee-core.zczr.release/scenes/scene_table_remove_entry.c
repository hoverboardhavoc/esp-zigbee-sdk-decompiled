/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> scenes.o -> scene_table_remove_entry
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void scene_table_remove_entry(uint8_t ep_id,zcl_scene_table_entry_t *entry)

{
  zcl_scene_table_t *pzVar1;
  uint8_t *puVar2;
  uint8_t uVar3;
  
  pzVar1 = scene_table_get(ep_id);
  uVar3 = entry->is_used;
  if ((_Bool)uVar3 != false) {
    scene_table_remove_stored_scene(ep_id,entry->group_id,entry->scene_id);
    scene_entry_set_unused(entry);
    puVar2 = pzVar1->count;
    if ((puVar2 == (uint8_t *)0x0) || (uVar3 = *puVar2, uVar3 == '\0')) {
      __assert_func(0,0,0,0);
    }
    *puVar2 = uVar3 + 0xff;
  }
  return;
}

