/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> mac.o -> mac_indirect_transmit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void mac_indirect_transmit(mac_device *dev,ezb_address_t *dst_addr,zmsg_t *msg)

{
  micro_timer_t *pmVar1;
  int iVar2;
  
  iVar2 = micro_timer_get_now();
  (msg->timestamp).val = (uint)(dev->pib).transaction_persistence_time * 0x3c00 + iVar2;
  zmsg_add_footer(msg,dst_addr,10);
  zmsg_queue_enqueue(&(dev->ctx).pend_q,msg);
  pmVar1 = &(dev->ctx).transaction_timer;
  iVar2 = micro_timer_is_running(pmVar1);
  if (iVar2 == 0) {
    micro_timer_fire_at(pmVar1,(msg->timestamp).val);
    return;
  }
  return;
}

