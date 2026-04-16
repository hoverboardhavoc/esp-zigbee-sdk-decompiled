/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> mac.o -> mac_update_scan_channel
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t mac_update_scan_channel(mac_device *dev)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = (dev->ctx).scan_channels.u32;
  uVar2 = (uint)(dev->ctx).scan_channel;
  if ((uVar2 == 0xff) && (uVar2 = 0, uVar1 < 0x8000000)) {
    uVar2 = 10;
  }
  uVar2 = uVar2 + 1 & 0xff;
  do {
    uVar3 = uVar2;
    if (0x1a < (uVar3 & 0xff)) {
      return 5;
    }
    uVar2 = uVar3 + 1;
  } while (((uVar1 & 0x7ffffff) >> (uVar3 & 0x1f) & 1) == 0);
  (dev->ctx).scan_channel = (uint8_t)uVar3;
  return 0;
}

