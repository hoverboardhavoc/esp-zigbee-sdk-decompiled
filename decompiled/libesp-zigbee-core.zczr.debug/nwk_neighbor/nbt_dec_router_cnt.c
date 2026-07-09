/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_neighbor.o -> nbt_dec_router_cnt
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint nbt_dec_router_cnt(uint param_1)

{
  uint uVar1;
  uint uVar2;
  int extraout_a1;
  
  if (*(short *)(param_1 + 0xe) != 0) {
    *(short *)(param_1 + 0xe) = *(short *)(param_1 + 0xe) + -1;
    return param_1;
  }
  uVar2 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_neighbor.c",0xd9,
                        "nbt_dec_router_cnt",&_LC4);
  uVar1 = 1 << (uVar2 & 7) & 0xff;
  uVar2 = __atomic_fetch_or_1((uVar2 >> 3) + extraout_a1,uVar1,5);
  return (uint)((uVar2 & uVar1) != 0);
}

