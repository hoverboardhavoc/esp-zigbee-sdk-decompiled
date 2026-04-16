/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> mac.o -> mac_scan
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void mac_scan(mac_device *dev,mac_operation_t scan_op,channel_page_t scan_channels,
             uint16_t scan_duration)

{
  int iVar1;
  mac_device *dev_00;
  uint extraout_a1;
  mac_operation_t scan_op_00;
  channel_page_t scan_channels_00;
  uint16_t scan_duration_00;
  
  scan_duration_00 = 0;
  scan_channels_00.u32 = 0;
  iVar1 = __assert_func(0,0);
  *(byte *)(iVar1 + 0x9c) = *(byte *)(iVar1 + 0x9c) & 0xfe | (byte)(extraout_a1 & 1);
  if ((extraout_a1 & 1) != 0) {
    dev_00 = (mac_device *)mac_pal_enable();
    if (dev_00 == (mac_device *)0x0) {
      return;
    }
    mac_scan(dev_00,scan_op_00,scan_channels_00,scan_duration_00);
  }
  iVar1 = mac_pal_disable();
  if (iVar1 != 0) {
    __assert_func(0,0,0,0);
  }
  return;
}

