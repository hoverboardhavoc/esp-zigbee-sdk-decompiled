/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_forwarder.o -> nwk_btr_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 * nwk_btr_create(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  
  uVar1 = 0;
  while( true ) {
    if (0x59 < uVar1) {
      return (undefined4 *)0x0;
    }
    if (*(char *)((int)&DAT_00011a5c + (uVar1 + 6) * 8 + 3) == '\0') break;
    uVar1 = uVar1 + 1 & 0xff;
  }
  nwk_btr_setup(&DAT_00011a5c + (uVar1 + 6) * 2,param_1,param_2);
  return &DAT_00011a5c + (uVar1 + 6) * 2;
}

