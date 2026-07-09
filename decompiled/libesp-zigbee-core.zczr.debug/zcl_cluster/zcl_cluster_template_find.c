/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_cluster.o -> zcl_cluster_template_find
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

ushort * zcl_cluster_template_find(uint param_1,uint param_2)

{
  int iVar1;
  ushort *puVar2;
  undefined4 *puVar3;
  
  iVar1 = core_globals_get();
  puVar2 = *(ushort **)(iVar1 + 0xd38);
  if (puVar2 != (ushort *)0x0) {
    iVar1 = core_globals_get();
    for (puVar3 = *(undefined4 **)(iVar1 + 0xd38); puVar2 = (ushort *)(puVar3 + -5),
        puVar2 != (ushort *)0xffffffec; puVar3 = (undefined4 *)*puVar3) {
      if ((*puVar2 == param_1) && (*(byte *)((int)puVar3 + -0x12) == param_2)) {
        return puVar2;
      }
    }
    puVar2 = (ushort *)0x0;
  }
  return puVar2;
}

