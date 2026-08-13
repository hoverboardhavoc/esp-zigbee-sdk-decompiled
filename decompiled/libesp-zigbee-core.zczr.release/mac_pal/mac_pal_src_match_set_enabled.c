/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.release -> mac_pal.o -> mac_pal_src_match_set_enabled
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void mac_pal_src_match_set_enabled(uint param_1)

{
  uint uVar1;
  
  if ((_DAT_00010644 >> 0x11 & 1) != param_1) {
    uVar1 = _DAT_00010644 >> 0x10;
    _DAT_00010644 = CONCAT12((byte)((param_1 & 1) << 1) | (byte)uVar1 & 0xfd,DAT_00010644);
    ezb_plat_radio_set_src_match();
    return;
  }
  return;
}

