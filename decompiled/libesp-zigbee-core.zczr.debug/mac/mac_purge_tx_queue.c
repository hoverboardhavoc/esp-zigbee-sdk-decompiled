/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> mac_purge_tx_queue
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void mac_purge_tx_queue(void)

{
  mac_device *dev;
  zmsg_queue_t *pzVar1;
  int iVar2;
  
  dev = s_devices;
  pzVar1 = &(s_devices->ctx).tx_q;
  while (iVar2 = zmsg_queue_get_head(pzVar1), iVar2 != 0) {
    mac_handle_tx_done(dev,pzVar1,0xda,false);
  }
  pzVar1 = &(dev->ctx).itx_q;
  while (iVar2 = zmsg_queue_get_head(pzVar1), iVar2 != 0) {
    mac_handle_tx_done(dev,pzVar1,0xda,true);
  }
  pzVar1 = &(dev->ctx).pend_q;
  while (iVar2 = zmsg_queue_get_head(pzVar1), iVar2 != 0) {
    mac_handle_tx_done(dev,pzVar1,0xda,true);
  }
  micro_timer_stop(&(dev->ctx).transaction_timer);
  return;
}

