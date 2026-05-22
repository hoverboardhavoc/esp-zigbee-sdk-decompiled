/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> scenes.o -> scene_table_get
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zcl_scene_table_t * scene_table_get(uint8_t ep_id)

{
  uint8_t ep_id_00;
  zcl_attr_desc_t *pzVar1;
  zcl_scene_table_t *pzVar2;
  uint uVar3;
  char *pcVar4;
  uint uVar5;
  
  pzVar1 = scenes_srv_get_attr_desc(ep_id,0xeff1);
  if ((pzVar1 == (zcl_attr_desc_t *)0x0) ||
     (pzVar1 = (zcl_attr_desc_t *)pzVar1->data_p, pzVar1 != (zcl_attr_desc_t *)0x0)) {
    return (zcl_scene_table_t *)pzVar1;
  }
  pcVar4 = "scene_table_get";
  uVar3 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/scenes.c",0x12e,
                        "scene_table");
  pzVar2 = scene_table_get(ep_id_00);
  if (pzVar2 != (zcl_scene_table_t *)0x0) {
    for (uVar5 = 0; uVar5 < pzVar2->total; uVar5 = uVar5 + 1 & 0xff) {
      if (((pzVar2[uVar5 * 4 + 1].total != '\0') &&
          (*(ushort *)&pzVar2[uVar5 * 4 + 1].field_0x2 == uVar3)) &&
         ((char *)(uint)*(byte *)&pzVar2[uVar5 * 4 + 1].count == pcVar4)) {
        return pzVar2 + uVar5 * 4 + 1;
      }
    }
    pzVar2 = (zcl_scene_table_t *)0x0;
  }
  return pzVar2;
}

