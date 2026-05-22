/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
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
               __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/mac/mac.c",0x3e2,
                             "mac_handle_timer",&_LC7);
      mac_handle_timer(dev_00);
      return;
    }
    mac_do_active_scan(dev);
  }
  return;
}

