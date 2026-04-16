/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> mac.o -> mac_reset_ctx
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void mac_reset_ctx(mac_device *dev)

{
  memset(&dev->ctx,0,0x74);
  (dev->ctx).phy_channel = '\v';
  (dev->ctx).scan_channel = 0xff;
  (dev->ctx).phy_channel_page = '\0';
  (dev->ctx).pan_channel = 0xff;
  (dev->ctx).pan_channel_page = 0xff;
  tasklet_init(&(dev->ctx).operation_task,mac_tasklet_func_wrapper,dev);
  micro_timer_init(&(dev->ctx).operation_timer,mac_timer_func_wrapper,dev);
  zmsg_queue_init(&(dev->ctx).tx_q);
  micro_timer_init(&(dev->ctx).transaction_timer,mac_handle_transaction_timeout,dev);
  zmsg_queue_init(&(dev->ctx).itx_q);
  zmsg_queue_init(&(dev->ctx).pend_q);
  return;
}

