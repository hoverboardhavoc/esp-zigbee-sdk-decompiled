/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_neighbor.o -> nbt_dec_ed_cnt
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint nbt_dec_ed_cnt(int param_1)

{
  uint uVar1;
  uint uVar2;
  int extraout_a1;
  
  if (*(short *)(param_1 + 0xc) != 0) {
    *(short *)(param_1 + 0xc) = *(short *)(param_1 + 0xc) + -1;
    uVar1 = nwk_update_beacon_payload();
    return uVar1;
  }
  uVar2 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_neighbor.c",0xeb,
                        "nbt_dec_ed_cnt","tbl->ed_num > 0");
  uVar1 = 1 << (uVar2 & 7) & 0xff;
  uVar2 = __atomic_fetch_and_1((uVar2 >> 3) + extraout_a1,~uVar1 & 0xff,5);
  return (uint)((uVar2 & uVar1) != 0);
}

