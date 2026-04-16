/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> mac_handle_data
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void mac_handle_data(mac_device *dev,mac_frame_t *mac_frame)

{
  _Bool _Var1;
  undefined3 extraout_var;
  
  if ((dev->ctx).state != '\x02') {
    if ((((dev->ctx).cur_op == '\x06') && ((mac_frame->mhr).dst_addr.addr_mode != '\0')) &&
       (_Var1 = mac_frame_is_from_coord(dev,mac_frame), CONCAT31(extraout_var,_Var1) != 0)) {
      mac_stop_timer(dev);
      mac_finish_op(dev);
      mac_report_poll_result(dev,'\0');
      mac_perform_next_op(dev);
    }
    nwk_mm_data_indication((dev->ctx).iface_id,mac_frame);
  }
  return;
}

