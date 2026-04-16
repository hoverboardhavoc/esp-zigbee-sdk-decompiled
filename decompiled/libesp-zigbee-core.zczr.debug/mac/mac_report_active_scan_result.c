/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> mac_report_active_scan_result
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void mac_report_active_scan_result(mac_device *dev,mac_frame_t *beacon_frame)

{
  ezb_err_t eVar1;
  active_scan_callback p_Var2;
  undefined1 auStack_2c [4];
  active_scan_result_t scan_result;
  
  p_Var2 = (dev->ctx).field_7.active_scan_result_handler;
  if (p_Var2 != (active_scan_callback)0x0) {
    if (beacon_frame == (mac_frame_t *)0x0) {
      (*p_Var2)((active_scan_result_t *)0x0,(dev->ctx).scan_user_ctx);
    }
    else {
      auStack_2c[0] = '\0';
      auStack_2c[1] = '\0';
      auStack_2c[2] = '\0';
      auStack_2c[3] = 0;
      scan_result.iface_id = '\0';
      scan_result.bsn = '\0';
      scan_result.beacon_type = '\0';
      scan_result._3_1_ = 0;
      scan_result.pan_descriptor.coord_addr._0_4_ = 0;
      scan_result.pan_descriptor.coord_addr.u._2_4_ = 0;
      scan_result.pan_descriptor._8_4_ = 0;
      scan_result.pan_descriptor.channel_page = '\0';
      scan_result.pan_descriptor.channel_number = '\0';
      scan_result.pan_descriptor.superframe_spec = 0;
      scan_result.pan_descriptor.lqi = '\0';
      scan_result.pan_descriptor.rssi = '\0';
      scan_result.beacon_payload_length = '\0';
      scan_result._23_1_ = 0;
      eVar1 = mac_convert_beacon_to_active_scan_result
                        (beacon_frame,(active_scan_result_t *)auStack_2c);
      if (eVar1 == 0) {
        (*(dev->ctx).field_7.active_scan_result_handler)
                  ((active_scan_result_t *)auStack_2c,(dev->ctx).scan_user_ctx);
      }
    }
  }
  return;
}

