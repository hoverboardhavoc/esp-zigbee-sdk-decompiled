/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_retrans.o -> aps_reasm_ent_new
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void * aps_reasm_ent_new(int param_1)

{
  void *__s;
  char cVar1;
  uint uVar2;
  
  uVar2 = bitmap_find_first_zero_bit(param_1 + 0x500,0x20);
  uVar2 = uVar2 & 0xff;
  if (uVar2 < 0x20) {
    cVar1 = test_and_set_bitmap(uVar2,param_1 + 0x500);
    if (cVar1 != '\x01') {
      __s = (void *)(param_1 + uVar2 * 0x28);
      memset(__s,0,0x28);
      return __s;
    }
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_retrans.c",0x1b2,
                  "aps_reasm_ent_new","!test_and_set_bitmap(idx, ctx->ent_in_use)");
  }
  return (void *)0x0;
}

