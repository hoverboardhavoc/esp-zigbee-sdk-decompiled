/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> mac_handle_received_frame
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void mac_handle_received_frame(mac_device *dev,ezb_radio_frame_t *radio_frame,ezb_err_t rx_error)

{
  uint8_t uVar1;
  _Bool _Var2;
  undefined3 extraout_var;
  int iVar3;
  ezb_err_t eVar4;
  undefined1 auStack_38 [4];
  mac_frame_t mac_frame;
  
  if (rx_error != 0) {
    return;
  }
  _Var2 = mac_is_enabled(dev);
  if (CONCAT31(extraout_var,_Var2) == 0) {
    return;
  }
  if (radio_frame == (ezb_radio_frame_t *)0x0) {
    return;
  }
  if (radio_frame->psdu == (uint8_t *)0x0) {
    return;
  }
  iVar3 = mac_frame_parse(radio_frame,auStack_38);
  if (iVar3 != 0) {
    return;
  }
  iVar3 = mac_filter_apply_to_rxframe(auStack_38);
  if (iVar3 != 0) {
    return;
  }
  eVar4 = mac_process_receive_security(dev,(mac_frame_t *)auStack_38);
  if (eVar4 != 0) {
    return;
  }
  uVar1 = (dev->ctx).cur_op;
  if (uVar1 == '\x01') {
    if ((mac_frame.mhr.dst_panid & 7) == 0) {
      mac_report_active_scan_result(dev,(mac_frame_t *)auStack_38);
      return;
    }
  }
  else if (uVar1 != '\x02') goto _L0;
  if ((dev->ctx).pan_channel != (dev->ctx).scan_channel) {
    return;
  }
_L0:
  if ((mac_frame.mhr.dst_panid & 7) == 1) {
    mac_handle_data(dev,(mac_frame_t *)auStack_38);
  }
  else if ((mac_frame.mhr.dst_panid & 7) == 3) {
    mac_handle_command(dev,(mac_frame_t *)auStack_38);
  }
  else if ((mac_frame.mhr.dst_panid & 7) == 0) {
    mac_handle_beacon(dev,(mac_frame_t *)auStack_38);
  }
  return;
}

