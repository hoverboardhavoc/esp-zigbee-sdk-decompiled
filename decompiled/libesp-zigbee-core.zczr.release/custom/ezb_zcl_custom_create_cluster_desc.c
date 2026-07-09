/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> custom.o -> ezb_zcl_custom_create_cluster_desc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

short * ezb_zcl_custom_create_cluster_desc(short *param_1)

{
  short *psVar1;
  
  psVar1 = param_1;
  if (param_1 != (short *)0x0) {
    if (*param_1 < 0) {
      psVar1 = (short *)zcl_create_cluster_desc(0);
      *(undefined4 *)(psVar1 + 4) = *(undefined4 *)(param_1 + 2);
    }
    else {
      psVar1 = (short *)0x0;
    }
  }
  return psVar1;
}

