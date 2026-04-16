/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> scenes.o -> scene_table_add_entry
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool scene_table_add_entry(uint8_t ep_id,zcl_scene_table_entry_t *entry,_Bool is_flash)

{
  uint uVar1;
  zcl_scene_table_t *pzVar2;
  ezb_err_t eVar3;
  undefined3 in_register_00002031;
  zcl_scene_table_entry_t *pzVar4;
  
  pzVar2 = scene_table_get(ep_id);
  pzVar4 = (zcl_scene_table_entry_t *)(pzVar2 + 1);
  uVar1 = 0;
  while( true ) {
    if ((uint)pzVar2->total <= (uVar1 & 0xff)) {
      return false;
    }
    if (entry == pzVar4) break;
    pzVar4 = pzVar4 + 1;
    uVar1 = uVar1 + 1;
  }
  if ((CONCAT31(in_register_00002031,is_flash) != 0) &&
     (eVar3 = scene_table_store_scene(ep_id,entry), eVar3 != 0)) {
    return false;
  }
  if (pzVar2[uVar1 * 4 + 1].total == '\0') {
    *pzVar2->count = *pzVar2->count + '\x01';
    pzVar2[uVar1 * 4 + 1].total = '\x01';
  }
  return true;
}

