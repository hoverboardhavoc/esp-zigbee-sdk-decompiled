/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.release -> nwk_join_srv.o -> nwk_set_mac_permit_joining
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_set_mac_permit_joining(undefined1 param_1)

{
  int iVar1;
  undefined1 auStack_11 [13];
  
  auStack_11[0] = param_1;
  iVar1 = nwk_mm_set_pib_attr(0xff,0x41,auStack_11);
  if (iVar1 != 0) {
    nwk_join_indication_with_method_part_0();
  }
  return;
}

