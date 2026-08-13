/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.release -> nwk_join_srv.o -> nwk_join_indication_with_method
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_join_indication_with_method(int param_1,undefined1 param_2)

{
  byte local_20;
  undefined1 uStack_1f;
  undefined2 uStack_1e;
  undefined1 auStack_1c [16];
  
  memset(&uStack_1e,0,0xe);
  local_20 = (byte)(*(uint *)(param_1 + 0xc) >> 0xd) & 0x1f;
  uStack_1f = param_2;
  uStack_1e = nwk_neighbor_get_shortaddr(param_1);
  nwk_neighbor_get_extaddr(param_1,auStack_1c);
  nwk_join_indication(&local_20);
  return;
}

