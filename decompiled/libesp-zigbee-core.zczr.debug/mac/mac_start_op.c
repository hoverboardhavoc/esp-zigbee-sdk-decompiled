/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> mac_start_op
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void mac_start_op(mac_device *dev,mac_operation_t op)

{
  if (op != MAC_OPERATION_IDLE) {
    mac_set_pending_op(dev,op);
  }
  if ((dev->ctx).cur_op == '\0') {
    tasklet_post(&(dev->ctx).operation_task);
  }
  return;
}

