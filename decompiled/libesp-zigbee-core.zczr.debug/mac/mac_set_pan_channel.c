/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> mac_set_pan_channel
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t mac_set_pan_channel(mac_device *dev,uint8_t page,uint8_t channel)

{
  ezb_err_t eVar1;
  
  if ((((dev->pib).supported_channel_page.u32 & 0x7ffffff) >> (channel & 0x1f) & 1) == 0) {
    eVar1 = 2;
  }
  else {
    (dev->ctx).pan_channel_page = page;
    (dev->ctx).pan_channel = channel;
    if (((dev->ctx).field_0x70 & 2) == 0) {
      (dev->ctx).phy_channel_page = page;
      (dev->ctx).phy_channel = channel;
      mac_do_idle(dev);
      eVar1 = 0;
    }
    else {
      eVar1 = 0;
    }
  }
  return eVar1;
}

