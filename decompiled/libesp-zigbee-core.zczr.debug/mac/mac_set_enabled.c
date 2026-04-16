/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> mac_set_enabled
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void mac_set_enabled(mac_device *dev,_Bool enable)

{
  int iVar1;
  undefined4 *puVar2;
  _Bool enable_00;
  
  (dev->ctx).field_0x70 = (dev->ctx).field_0x70 & 0xfe | enable;
  if (enable) {
    iVar1 = mac_pal_enable();
    if (iVar1 == 0) {
      return;
    }
    __assert_func("//build/esp-zigbee/src/core/mac/mac.c",0x546,"mac_set_enabled",
                  "(mac_pal_enable()) == 0");
  }
  iVar1 = mac_pal_disable();
  if (iVar1 == 0) {
    return;
  }
  puVar2 = (undefined4 *)
           __assert_func("//build/esp-zigbee/src/core/mac/mac.c",0x548,"mac_set_enabled",
                         "(mac_pal_disable()) == 0");
  mac_set_enabled((mac_device *)*puVar2,enable_00);
  return;
}

