/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> mac_scan
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void mac_scan(mac_device *dev,mac_operation_t scan_op,channel_page_t scan_channels,
             uint16_t scan_duration)

{
  mac_operation_t extraout_a1;
  char *pcVar1;
  uint uVar2;
  
  if (scan_op - MAC_OPERATION_ACTIVE_SCAN < 2) {
    (dev->ctx).scan_duration = (uint8_t)scan_duration;
    (dev->ctx).scan_channel = 0xff;
    (dev->ctx).scan_channels.u32 =
         (dev->ctx).scan_channels.u32 & 0x7ffffff | (scan_channels.u32 >> 0x1b) << 0x1b;
    if (scan_channels.u32 >> 0x1b != (dev->pib).supported_channel_page.u32 >> 0x1b) {
      (dev->ctx).scan_channels.u32 = (dev->ctx).scan_channels.u32 & 0xf8000000;
      goto _L0;
    }
  }
  else {
    pcVar1 = "mac_scan";
    dev = (mac_device *)
          __assert_func("//build/esp-zigbee/src/core/mac/mac.c",0x2ee,
                        "scan_op == MAC_OPERATION_ACTIVE_SCAN || scan_op == MAC_OPERATION_ED_SCAN");
    scan_op = extraout_a1;
    scan_channels = (channel_page_t)pcVar1;
  }
  uVar2 = (dev->ctx).scan_channels.u32 & 0xf8000000;
  (dev->ctx).scan_channels.u32 = uVar2 | scan_channels.u32 & 0x7ffffff;
  (dev->ctx).scan_channels.u32 =
       uVar2 | scan_channels.u32 & 0x7ffffff & (dev->pib).supported_channel_page.u32 & 0x7ffffff;
_L0:
  mac_start_op(dev,scan_op);
  return;
}

