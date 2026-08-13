/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> aps_retrans.o -> aps_retrans_ent_new
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void * aps_retrans_ent_new(int param_1)

{
  void *__s;
  char cVar1;
  uint uVar2;
  
  uVar2 = bitmap_find_first_zero_bit(param_1 + 0x41c,0x20);
  uVar2 = uVar2 & 0xff;
  if (uVar2 < 0x20) {
    cVar1 = test_and_set_bitmap(uVar2,param_1 + 0x41c);
    if (cVar1 != '\x01') {
      __s = (void *)(param_1 + uVar2 * 0x20 + 0x1c);
      memset(__s,0,0x20);
      aps_retrans_start_fast_poll();
      return __s;
    }
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_retrans.c",0x90,
                  "aps_retrans_ent_new","!test_and_set_bitmap(idx, ctx->ent_in_use)");
  }
  return (void *)0x0;
}

