/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> scenes.o -> scene_table_remove_entry
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void scene_table_remove_entry(uint8_t ep_id,zcl_scene_table_entry_t *entry)

{
  uint uVar1;
  _Bool _Var2;
  uint8_t ep_id_00;
  zcl_scene_table_t *pzVar3;
  undefined3 extraout_var;
  uint uVar4;
  uint8_t *puVar5;
  
  pzVar3 = scene_table_get(ep_id);
  if ((entry != (zcl_scene_table_entry_t *)0x0) &&
     (_Var2 = scene_entry_is_used(entry), CONCAT31(extraout_var,_Var2) != 0)) {
    scene_table_remove_stored_scene(ep_id,entry->group_id,entry->scene_id);
    scene_entry_set_unused(entry);
    puVar5 = pzVar3->count;
    if ((puVar5 == (uint8_t *)0x0) || (*puVar5 == '\0')) {
      uVar4 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/scenes.c",
                            0x16c,"scene_table_remove_entry",
                            "(scene_table->count && *scene_table->count >= 1)");
      pzVar3 = scene_table_get(ep_id_00);
      if (pzVar3 != (zcl_scene_table_t *)0x0) {
        for (uVar1 = 0; uVar1 < pzVar3->total; uVar1 = uVar1 + 1 & 0xff) {
          if (*(ushort *)&pzVar3[uVar1 * 4 + 1].field_0x2 == uVar4) {
            scene_table_remove_entry(ep_id_00,(zcl_scene_table_entry_t *)(pzVar3 + uVar1 * 4 + 1));
          }
        }
      }
      return;
    }
    *puVar5 = *puVar5 + 0xff;
  }
  return;
}

