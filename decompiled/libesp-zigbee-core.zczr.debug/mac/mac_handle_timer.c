/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> mac_handle_timer
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void mac_handle_timer(mac_device *dev)

{
  uint8_t uVar1;
  mac_device *dev_00;
  
  uVar1 = (dev->ctx).cur_op;
  if (uVar1 == '\x03') {
    mac_finish_op(dev);
    mac_start_op(dev,MAC_OPERATION_TRANSMIT_POLL);
    mac_perform_next_op(dev);
  }
  else if (uVar1 == '\x06') {
    mac_finish_op(dev);
    mac_report_poll_result(dev,0xeb);
    mac_perform_next_op(dev);
  }
  else {
    if (uVar1 != '\x01') {
      dev_00 = (mac_device *)
               __assert_func("//build/esp-zigbee/src/core/mac/mac.c",0x3e2,"mac_handle_timer",&_L0);
      mac_handle_timer(dev_00);
      return;
    }
    mac_do_active_scan(dev);
  }
  return;
}

