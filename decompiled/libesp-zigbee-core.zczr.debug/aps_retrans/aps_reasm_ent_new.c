/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> aps_retrans.o -> aps_reasm_ent_new
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

aps_reasm_ent_t * aps_reasm_ent_new(aps_rx_context_t *ctx)

{
  _Bool _Var1;
  uint uVar2;
  
  uVar2 = bitmap_find_first_zero_bit(ctx->ent_in_use,0x20);
  uVar2 = uVar2 & 0xff;
  if (uVar2 < 0x20) {
    _Var1 = test_and_set_bitmap(uVar2,ctx->ent_in_use);
    if (!_Var1) {
      memset(ctx->ents + uVar2,0,0x28);
      return ctx->ents + uVar2;
    }
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_retrans.c",0x1b2,
                  "aps_reasm_ent_new","!test_and_set_bitmap(idx, ctx->ent_in_use)");
  }
  return (aps_reasm_ent_t *)0x0;
}

