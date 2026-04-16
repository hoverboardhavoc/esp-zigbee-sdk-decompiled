/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> scenes.o -> scene_table_add_entry
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool scene_table_add_entry(uint8_t ep_id,zcl_scene_table_entry_t *entry,_Bool is_flash)

{
  _Bool _Var1;
  zcl_scene_table_t *pzVar2;
  ezb_err_t eVar3;
  undefined3 extraout_var;
  undefined3 in_register_00002031;
  uint uVar4;
  bool bVar5;
  
  pzVar2 = scene_table_get(ep_id);
  uVar4 = 0;
  while( true ) {
    if (pzVar2->total <= uVar4) {
      return false;
    }
    if ((zcl_scene_table_entry_t *)(pzVar2 + uVar4 * 4 + 1) == entry) break;
    uVar4 = uVar4 + 1 & 0xff;
  }
  if (CONCAT31(in_register_00002031,is_flash) == 0) {
    bVar5 = true;
  }
  else {
    eVar3 = scene_table_store_scene(ep_id,entry);
    bVar5 = eVar3 == 0;
    if (eVar3 != 0) {
      return bVar5;
    }
  }
  _Var1 = scene_entry_is_used((zcl_scene_table_entry_t *)(pzVar2 + uVar4 * 4 + 1));
  if (CONCAT31(extraout_var,_Var1) != 0) {
    return bVar5;
  }
  *pzVar2->count = *pzVar2->count + '\x01';
  pzVar2[uVar4 * 4 + 1].total = '\x01';
  return bVar5;
}

