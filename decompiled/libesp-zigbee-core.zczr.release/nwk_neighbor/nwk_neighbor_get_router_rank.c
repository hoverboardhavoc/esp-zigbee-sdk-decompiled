/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_neighbor.o -> nwk_neighbor_get_router_rank
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int nwk_neighbor_get_router_rank(int param_1)

{
  if (1 < (*(uint *)(param_1 + 0xc) & 3)) {
    param_1 = __assert_func(0,0,0,0);
  }
  return (uint)*(byte *)(param_1 + 0x14) +
         (((uint)*(byte *)(param_1 + 0x18) + (uint)*(byte *)(param_1 + 0x19)) * 2 +
         (uint)*(byte *)(param_1 + 0x16)) * 4;
}

