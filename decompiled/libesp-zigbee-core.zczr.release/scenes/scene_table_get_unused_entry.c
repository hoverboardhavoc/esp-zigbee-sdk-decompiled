/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> scenes.o -> scene_table_get_unused_entry
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zcl_scene_table_entry_t * scene_table_get_unused_entry(uint8_t ep_id)

{
  char cVar1;
  uint uVar2;
  zcl_scene_table_entry_t *pzVar3;
  char *pcVar4;
  uint uVar5;
  
  pzVar3 = (zcl_scene_table_entry_t *)scene_table_get(ep_id);
  if (pzVar3 != (zcl_scene_table_entry_t *)0x0) {
    pcVar4 = pzVar3->scene_name;
    uVar2 = 0;
    do {
      uVar5 = uVar2;
      if ((uint)pzVar3->is_used <= (uVar5 & 0xff)) {
        return (zcl_scene_table_entry_t *)0x0;
      }
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 0x20;
      uVar2 = uVar5 + 1;
    } while (cVar1 != '\0');
    pzVar3 = (zcl_scene_table_entry_t *)pzVar3[uVar5].scene_name;
  }
  return pzVar3;
}

