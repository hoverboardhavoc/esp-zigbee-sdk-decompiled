/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> mac_report_ed_scan_result
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void mac_report_ed_scan_result(mac_device *dev,int8_t rssi)

{
  undefined3 in_register_0000202d;
  active_scan_callback p_Var1;
  uint8_t uStack_14;
  byte bStack_13;
  uint8_t uStack_12;
  int8_t iStack_11;
  ed_scan_result_t result;
  
  p_Var1 = (dev->ctx).field_7.active_scan_result_handler;
  if ((p_Var1 != (active_scan_callback)0x0) && (CONCAT31(in_register_0000202d,rssi) != 0x7f)) {
    uStack_14 = (dev->ctx).iface_id;
    bStack_13 = (byte)((dev->ctx).scan_channels.u32 >> 0x1b);
    uStack_12 = (dev->ctx).scan_channel;
    iStack_11 = rssi;
    (*p_Var1)((active_scan_result_t *)&uStack_14,(dev->ctx).scan_user_ctx);
  }
  return;
}

