/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_retrans.o -> aps_reasm_ent_delete
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint aps_reasm_ent_delete(int param_1,int param_2)

{
  uint uVar1;
  int extraout_a1;
  uint uVar2;
  
  uVar2 = (param_2 - param_1 >> 3) * -0x33333333;
  if ((uVar2 & 0xff) < 0x20) {
    uVar2 = test_and_clr_bitmap(uVar2 & 0xff,param_1 + 0x500);
    if (uVar2 != 0) {
      return uVar2;
    }
  }
  else {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_retrans.c",0x1bf,
                  "aps_reasm_ent_delete","idx < 32");
  }
  uVar1 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_retrans.c",0x1c0,
                        "aps_reasm_ent_delete","test_and_clr_bitmap(idx, ctx->ent_in_use)");
  uVar2 = 1 << (uVar1 & 7) & 0xff;
  uVar1 = __atomic_fetch_or_1((uVar1 >> 3) + extraout_a1,uVar2,5);
  return (uint)((uVar1 & uVar2) != 0);
}

