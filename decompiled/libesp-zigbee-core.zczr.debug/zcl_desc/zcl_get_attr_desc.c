/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_desc.o -> zcl_get_attr_desc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zcl_get_attr_desc(uint param_1,uint param_2)

{
  int iVar1;
  ushort *puVar2;
  
  iVar1 = zcl_get_cluster_desc();
  if (iVar1 != 0) {
    for (puVar2 = *(ushort **)(iVar1 + 0xc);
        (puVar2 != (ushort *)0x0 &&
        ((*puVar2 != param_1 ||
         ((param_2 != 0 && (((*(byte *)((int)puVar2 + 3) & 0x20) == 0 || (puVar2[2] != param_2))))))
        )); puVar2 = *(ushort **)(puVar2 + 6)) {
    }
  }
  return;
}

