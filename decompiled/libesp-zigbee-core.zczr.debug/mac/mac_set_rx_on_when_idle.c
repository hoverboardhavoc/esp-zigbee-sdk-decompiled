/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> mac_set_rx_on_when_idle
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void mac_set_rx_on_when_idle(mac_device *dev,_Bool rx_on_when_idle)

{
  undefined3 in_register_0000202d;
  
  if ((*(uint *)&(dev->pib).transaction_persistence_time >> 0x11 & 1) !=
      CONCAT31(in_register_0000202d,rx_on_when_idle)) {
    (dev->pib).field_0x2a = (dev->pib).field_0x2a & 0xfd | (byte)((rx_on_when_idle & 1) << 1);
    mac_pal_set_rx_when_idle(CONCAT31(in_register_0000202d,rx_on_when_idle));
    mac_do_idle(dev);
  }
  return;
}

