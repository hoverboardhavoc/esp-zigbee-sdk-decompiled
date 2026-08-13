/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.release -> touchlink_utility.o -> touchlink_nwk_update_id
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 touchlink_nwk_update_id(void)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = touchlink_touchlink_info();
  if ((uVar1 & 1) == 0) {
    uVar2 = nwk_get_update_id();
    return uVar2;
  }
  return 0;
}

