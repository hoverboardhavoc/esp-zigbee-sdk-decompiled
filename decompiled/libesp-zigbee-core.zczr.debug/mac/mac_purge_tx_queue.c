/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> mac_purge_tx_queue
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void mac_purge_tx_queue(mac_device *dev,ezb_address_t *dst_addr)

{
  zmsg_queue_t *pzVar1;
  int iVar2;
  
  if (dst_addr->addr_mode == '\0') {
    pzVar1 = &(dev->ctx).tx_q;
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
  }
  return;
}

