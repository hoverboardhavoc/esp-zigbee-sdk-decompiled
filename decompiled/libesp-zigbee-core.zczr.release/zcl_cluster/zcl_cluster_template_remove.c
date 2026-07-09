/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zcl_cluster.o -> zcl_cluster_template_remove
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_cluster_template_remove(uint param_1,uint param_2)

{
  int *piVar1;
  ushort *puVar2;
  int iVar3;
  
  iVar3 = core_globals_get();
  piVar1 = *(int **)(iVar3 + 0xd38);
  if (piVar1 != (int *)0x0) {
    for (; puVar2 = (ushort *)(piVar1 + -5), puVar2 != (ushort *)0xffffffec; piVar1 = (int *)*piVar1
        ) {
      if ((*puVar2 == param_1) && (*(byte *)((int)piVar1 + -0x12) == param_2)) {
        iVar3 = core_globals_get();
        list_remove_node(iVar3 + 0xd38,piVar1);
        mm_free(puVar2);
        return 0;
      }
    }
  }
  return 0;
}

