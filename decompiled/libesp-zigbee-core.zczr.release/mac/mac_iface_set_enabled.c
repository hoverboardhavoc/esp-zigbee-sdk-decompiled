/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> mac.o -> mac_iface_set_enabled
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void mac_iface_set_enabled(mac_interface_t *iface,_Bool enable)

{
  mac_device *dev;
  int iVar1;
  mac_operation_t scan_op;
  channel_page_t in_a2;
  uint16_t in_a3;
  
  *(byte *)((int)iface->dev + 0x9c) = *(byte *)((int)iface->dev + 0x9c) & 0xfe | enable;
  if (enable) {
    dev = (mac_device *)mac_pal_enable();
    if (dev == (mac_device *)0x0) {
      return;
    }
    mac_scan(dev,scan_op,in_a2,in_a3);
  }
  iVar1 = mac_pal_disable();
  if (iVar1 != 0) {
    __assert_func(0,0,0,0);
  }
  return;
}

