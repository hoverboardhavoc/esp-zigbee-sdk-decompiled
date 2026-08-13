/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.release -> nwk_address.o -> ezb_eui64_is_invalid
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 ezb_eui64_is_invalid(int *param_1)

{
  undefined4 uVar1;
  
  uVar1 = 1;
  if ((param_1[1] + 1U != (uint)(*param_1 == 0)) || (*param_1 - 1U < 0xfffffffe)) {
    uVar1 = 0;
  }
  return uVar1;
}

