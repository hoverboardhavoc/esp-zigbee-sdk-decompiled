/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_cluster.o -> zcl_cluster_template_find
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zcl_cluster_template_t * zcl_cluster_template_find(uint16_t cluster_id,uint8_t cluster_role)

{
  undefined2 in_register_0000202a;
  int iVar1;
  zcl_cluster_template_t *pzVar2;
  undefined3 in_register_0000202d;
  undefined4 *puVar3;
  
  iVar1 = core_globals_get();
  pzVar2 = *(zcl_cluster_template_t **)(iVar1 + 0xd38);
  if (pzVar2 != (zcl_cluster_template_t *)0x0) {
    iVar1 = core_globals_get();
    for (puVar3 = *(undefined4 **)(iVar1 + 0xd38); pzVar2 = (zcl_cluster_template_t *)(puVar3 + -5),
        pzVar2 != (zcl_cluster_template_t *)0xffffffec; puVar3 = (undefined4 *)*puVar3) {
      if (((uint)pzVar2->cluster_id == CONCAT22(in_register_0000202a,cluster_id)) &&
         ((uint)*(byte *)((int)puVar3 + -0x12) == CONCAT31(in_register_0000202d,cluster_role))) {
        return pzVar2;
      }
    }
    pzVar2 = (zcl_cluster_template_t *)0x0;
  }
  return pzVar2;
}

