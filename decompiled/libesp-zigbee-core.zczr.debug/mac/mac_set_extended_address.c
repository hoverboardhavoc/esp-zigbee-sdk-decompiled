/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> mac_set_extended_address
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void mac_set_extended_address(mac_device *dev,ezb_extaddr_t *ext_addr)

{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)((int)&ext_addr->field_0 + 4);
  *(undefined4 *)&(dev->pib).extended_address.field_0 = *(undefined4 *)&ext_addr->field_0;
  *(undefined4 *)((int)&(dev->pib).extended_address.field_0 + 4) = uVar1;
  mac_pal_set_extaddr();
  return;
}

