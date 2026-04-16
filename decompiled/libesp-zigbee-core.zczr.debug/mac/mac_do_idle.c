/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> mac_do_idle
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void mac_do_idle(mac_device *dev)

{
  if ((dev->ctx).cur_op == '\0') {
    if ((*(uint *)&(dev->pib).transaction_persistence_time >> 0x11 & 1) == 0) {
      mac_pal_sleep();
    }
    else {
      mac_pal_receive((dev->ctx).phy_channel_page,(dev->ctx).phy_channel);
    }
  }
  return;
}

