/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> mac_set_enabled
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void mac_set_enabled(int param_1,byte param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  *(byte *)(param_1 + 0x9c) = *(byte *)(param_1 + 0x9c) & 0xfe | param_2 & 1;
  if ((param_2 & 1) != 0) {
    iVar1 = mac_pal_enable();
    if (iVar1 == 0) {
      return;
    }
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/mac/mac.c",0x58c,"mac_set_enabled",
                  "(mac_pal_enable()) == 0");
  }
  iVar1 = mac_pal_disable();
  if (iVar1 == 0) {
    return;
  }
  puVar2 = (undefined4 *)
           __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/mac/mac.c",0x58e,
                         "mac_set_enabled","(mac_pal_disable()) == 0");
  mac_set_enabled(*puVar2);
  return;
}

