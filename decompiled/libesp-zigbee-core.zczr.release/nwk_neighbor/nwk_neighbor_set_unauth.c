/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_neighbor.o -> nwk_neighbor_set_unauth
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_neighbor_set_unauth(int param_1,undefined4 param_2)

{
  *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) & 0xfffffc3f | 0x140;
  memset((void *)(param_1 + 0x10),0,0xc);
  *(undefined4 *)(param_1 + 0x14) = param_2;
  return;
}

