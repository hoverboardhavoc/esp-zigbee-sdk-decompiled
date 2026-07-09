/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk.o -> nwk_lqa_to_lqi
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint nwk_lqa_to_lqi(int param_1)

{
  int iVar1;
  uint uVar2;
  
  if (param_1 != 0) {
    return 10;
  }
  iVar1 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk.c",0x55,__func___3,
                        "lqa != 0");
  if (iVar1 != 0) {
    return ((iVar1 * 0x6d) / 0xff + (iVar1 * 0x6d >> 0x1f) + -0x65) * 0x1000000 >> 0x18;
  }
  uVar2 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk.c",0x5c,
                        "nwk_lqa_to_rssi","lqa != 0");
  if (uVar2 != 0) {
    if (uVar2 < 0x11) {
      return 7;
    }
    if (uVar2 < 0x21) {
      return 6;
    }
    if (uVar2 < 0x41) {
      return 5;
    }
    if (uVar2 < 0x61) {
      return 4;
    }
    if (uVar2 < 0x81) {
      return 3;
    }
    if (uVar2 < 0xc1) {
      return 2;
    }
    uVar2 = 1;
  }
  return uVar2;
}

