/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> nwk.o -> nwk_lqa_to_rssi
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

int8_t nwk_lqa_to_rssi(uint8_t lqa)

{
  undefined3 in_register_00002029;
  uint uVar1;
  int iVar2;
  
  if (CONCAT31(in_register_00002029,lqa) != 0) {
    iVar2 = CONCAT31(in_register_00002029,lqa) * 0x6d;
    return (int8_t)((uint)((iVar2 / 0xff + (iVar2 >> 0x1f) + -0x65) * 0x1000000) >> 0x18);
  }
  uVar1 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk.c",0x5c,
                        "nwk_lqa_to_rssi","lqa != 0");
  if (uVar1 != 0) {
    if (uVar1 < 0x11) {
      return '\a';
    }
    if (uVar1 < 0x21) {
      return '\x06';
    }
    if (uVar1 < 0x41) {
      return '\x05';
    }
    if (uVar1 < 0x61) {
      return '\x04';
    }
    if (uVar1 < 0x81) {
      return '\x03';
    }
    if (uVar1 < 0xc1) {
      return '\x02';
    }
    uVar1 = 1;
  }
  return (int8_t)uVar1;
}

