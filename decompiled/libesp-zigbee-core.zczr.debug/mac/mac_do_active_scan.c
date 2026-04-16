/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> mac_do_active_scan
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void mac_do_active_scan(mac_device *dev)

{
  ezb_err_t eVar1;
  
  eVar1 = mac_update_scan_channel(dev);
  if (eVar1 == 0) {
    mac_do_transmit(dev);
  }
  else {
    mac_pal_set_panid((dev->pib).panid);
    mac_pal_set_rx_when_idle(*(uint *)&(dev->pib).transaction_persistence_time >> 0x11 & 1);
    mac_set_state(dev,MAC_STATE_NORMAL);
    mac_finish_op(dev);
    mac_report_active_scan_result(dev,(mac_frame_t *)0x0);
    mac_perform_next_op(dev);
  }
  return;
}

