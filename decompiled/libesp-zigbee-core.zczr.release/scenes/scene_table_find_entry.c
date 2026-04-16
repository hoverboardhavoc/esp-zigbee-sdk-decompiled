/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> scenes.o -> scene_table_find_entry
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zcl_scene_table_entry_t * scene_table_find_entry(uint8_t ep_id,uint16_t group_id,uint16_t scene_id)

{
  zcl_scene_table_entry_t *pzVar1;
  undefined2 in_register_0000202e;
  undefined2 in_register_00002032;
  char *pcVar2;
  uint uVar3;
  
  pzVar1 = (zcl_scene_table_entry_t *)scene_table_get(ep_id);
  if (pzVar1 != (zcl_scene_table_entry_t *)0x0) {
    pcVar2 = pzVar1->scene_name;
    for (uVar3 = 0; (uVar3 & 0xff) < (uint)pzVar1->is_used; uVar3 = uVar3 + 1) {
      if (((*pcVar2 != '\0') &&
          ((uint)*(ushort *)(pcVar2 + 2) == CONCAT22(in_register_0000202e,group_id))) &&
         ((uint)(byte)pcVar2[4] == CONCAT22(in_register_00002032,scene_id))) {
        return (zcl_scene_table_entry_t *)pzVar1[uVar3].scene_name;
      }
      pcVar2 = pcVar2 + 0x20;
    }
    pzVar1 = (zcl_scene_table_entry_t *)0x0;
  }
  return pzVar1;
}

