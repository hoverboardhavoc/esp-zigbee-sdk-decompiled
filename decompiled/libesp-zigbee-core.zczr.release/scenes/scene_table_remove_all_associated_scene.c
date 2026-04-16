/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> scenes.o -> scene_table_remove_all_associated_scene
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t scene_table_remove_all_associated_scene(uint8_t ep_id,uint16_t group_id)

{
  uint uVar1;
  ezb_zcl_status_t eVar2;
  zcl_scene_table_t *pzVar3;
  undefined2 in_register_0000202e;
  
  pzVar3 = scene_table_get(ep_id);
  if (pzVar3 == (zcl_scene_table_t *)0x0) {
    eVar2 = 0x8b;
  }
  else {
    for (uVar1 = 0; uVar1 < pzVar3->total; uVar1 = uVar1 + 1 & 0xff) {
      if ((uint)*(ushort *)&pzVar3[uVar1 * 4 + 1].field_0x2 ==
          CONCAT22(in_register_0000202e,group_id)) {
        scene_table_remove_entry(ep_id,(zcl_scene_table_entry_t *)(pzVar3 + uVar1 * 4 + 1));
      }
    }
    eVar2 = '\0';
  }
  return eVar2;
}

