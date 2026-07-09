/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_dup.o -> mempool_free_ent
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint mempool_free_ent(uint param_1,undefined4 param_2,int param_3,undefined4 param_4,uint param_5)

{
  uint uVar1;
  uint uVar2;
  int extraout_a1;
  
  if (param_1 <= param_5) {
    uVar1 = mempool_free_idx(param_2,param_4,(int)(param_5 - param_1) / param_3 & 0xffff);
    return uVar1;
  }
  uVar2 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/common/mempool.h",0x69,
                        "mempool_free_ent","blk_base <= obj");
  uVar1 = 1 << (uVar2 & 7) & 0xff;
  uVar2 = __atomic_fetch_or_1((uVar2 >> 3) + extraout_a1,uVar1,5);
  return (uint)((uVar2 & uVar1) != 0);
}

