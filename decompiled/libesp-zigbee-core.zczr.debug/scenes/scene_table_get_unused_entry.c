/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> scenes.o -> scene_table_get_unused_entry
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zcl_scene_table_entry_t * scene_table_get_unused_entry(uint8_t ep_id)

{
  uint uVar1;
  _Bool _Var2;
  zcl_scene_table_t *pzVar3;
  undefined3 extraout_var;
  
  pzVar3 = scene_table_get(ep_id);
  if (pzVar3 != (zcl_scene_table_t *)0x0) {
    for (uVar1 = 0; uVar1 < pzVar3->total; uVar1 = uVar1 + 1 & 0xff) {
      _Var2 = scene_entry_is_used((zcl_scene_table_entry_t *)(pzVar3 + uVar1 * 4 + 1));
      if (CONCAT31(extraout_var,_Var2) == 0) {
        return (zcl_scene_table_entry_t *)(pzVar3 + uVar1 * 4 + 1);
      }
    }
  }
  return (zcl_scene_table_entry_t *)0x0;
}

