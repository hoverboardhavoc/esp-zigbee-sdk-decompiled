/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> aps_retrans.o -> aps_reasm_ent_delete
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void aps_reasm_ent_delete(aps_rx_context_t *ctx,aps_reasm_ent_t *ent)

{
  _Bool _Var1;
  undefined3 extraout_var;
  int extraout_a1;
  uint uVar2;
  
  uVar2 = ((int)ent - (int)ctx >> 3) * -0x33333333;
  if ((uVar2 & 0xff) < 0x20) {
    _Var1 = test_and_clr_bitmap(uVar2 & 0xff,ctx->ent_in_use);
    if (CONCAT31(extraout_var,_Var1) != 0) {
      return;
    }
  }
  else {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_retrans.c",0x1bf,
                  "aps_reasm_ent_delete","idx < 32");
  }
  uVar2 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_retrans.c",0x1c0,
                        "aps_reasm_ent_delete","test_and_clr_bitmap(idx, ctx->ent_in_use)");
  __atomic_fetch_or_1((uVar2 >> 3) + extraout_a1,1 << (uVar2 & 7) & 0xff,5);
  return;
}

