/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> zcl_cluster.o -> zcl_cluster_template_find
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
  int *piVar3;
  
  iVar1 = core_globals_get();
  if (*(int *)(iVar1 + 0xd38) != 0) {
    iVar1 = core_globals_get();
    for (piVar3 = *(int **)(iVar1 + 0xd38); pzVar2 = (zcl_cluster_template_t *)(piVar3 + -5),
        pzVar2 != (zcl_cluster_template_t *)0xffffffec; piVar3 = (int *)*piVar3) {
      if (((uint)pzVar2->cluster_id == CONCAT22(in_register_0000202a,cluster_id)) &&
         ((uint)*(byte *)((int)piVar3 + -0x12) == CONCAT31(in_register_0000202d,cluster_role))) {
        return pzVar2;
      }
    }
  }
  return (zcl_cluster_template_t *)0x0;
}

