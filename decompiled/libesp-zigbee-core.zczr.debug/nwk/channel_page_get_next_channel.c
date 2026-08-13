/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> nwk.o -> channel_page_get_next_channel
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 channel_page_get_next_channel(uint param_1,byte *param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = (uint)*param_2;
  if (uVar1 == 0xff) {
    if (param_1 < 0x8000000) {
      uVar1 = 10;
    }
    else {
      uVar1 = 0;
    }
  }
  do {
    uVar2 = uVar1 + 1;
    uVar1 = uVar2 & 0xff;
    if (0x1a < uVar1) {
      return 5;
    }
  } while (((param_1 & 0x7ffffff) >> (uVar2 & 0x1f) & 1) == 0);
  *param_2 = (byte)uVar2;
  return 0;
}

