/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> af_desc.o -> af_endpoint_add_cluster_desc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 af_endpoint_add_cluster_desc(int param_1,short *param_2)

{
  undefined4 uVar1;
  short *psVar2;
  
  uVar1 = 2;
  if (param_1 == 0) {
    return uVar1;
  }
  if (param_2 != (short *)0x0) {
    for (psVar2 = *(short **)(param_1 + 4); psVar2 != (short *)0x0; psVar2 = *(short **)(psVar2 + 8)
        ) {
      if ((*psVar2 == *param_2) && ((*(byte *)(param_2 + 1) & *(byte *)(psVar2 + 1)) != 0)) {
        return 2;
      }
    }
    *(short **)(param_2 + 8) = *(short **)(param_1 + 4);
    *(short **)(param_1 + 4) = param_2;
    uVar1 = 0;
  }
  return uVar1;
}

