/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> comm_api.o -> ezb_app_signal_to_string
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined * ezb_app_signal_to_string(uint param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  while ((uVar1 < 0x16 && ((ushort)(&s_app_signal_table)[uVar1 * 4] != param_1))) {
    uVar1 = uVar1 + 1 & 0xff;
  }
  return (&PTR__L0_000103c8)[uVar1 * 2];
}

