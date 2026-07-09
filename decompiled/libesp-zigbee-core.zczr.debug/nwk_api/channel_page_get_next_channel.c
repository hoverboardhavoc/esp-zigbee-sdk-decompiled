/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_api.o -> channel_page_get_next_channel
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

