/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> mac_clear_temporary_channel
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void mac_clear_temporary_channel(mac_device *dev)

{
  if (((dev->ctx).field_0x70 & 2) != 0) {
    (dev->ctx).field_0x70 = (dev->ctx).field_0x70 & 0xfd;
    (dev->ctx).phy_channel_page = (dev->ctx).pan_channel_page;
    (dev->ctx).phy_channel = (dev->ctx).pan_channel;
    mac_do_idle(dev);
  }
  return;
}

