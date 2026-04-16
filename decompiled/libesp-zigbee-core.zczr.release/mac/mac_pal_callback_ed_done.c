/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> mac.o -> mac_pal_callback_ed_done
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void mac_pal_callback_ed_done(int8_t max_rssi)

{
  mac_device *dev;
  undefined3 in_register_00002029;
  active_scan_callback p_Var1;
  uint8_t uStack_14;
  byte bStack_13;
  uint8_t uStack_12;
  int8_t iStack_11;
  ed_scan_result_t result;
  
  dev = s_devices;
  p_Var1 = (s_devices->ctx).field_7.active_scan_result_handler;
  if ((p_Var1 != (active_scan_callback)0x0) && (CONCAT31(in_register_00002029,max_rssi) != 0x7f)) {
    uStack_14 = (s_devices->ctx).iface_id;
    bStack_13 = (byte)((s_devices->ctx).scan_channels.u32 >> 0x1b);
    uStack_12 = (s_devices->ctx).scan_channel;
    iStack_11 = max_rssi;
    (*p_Var1)((active_scan_result_t *)&uStack_14,(s_devices->ctx).scan_user_ctx);
  }
  mac_do_ed_scan(dev);
  return;
}

