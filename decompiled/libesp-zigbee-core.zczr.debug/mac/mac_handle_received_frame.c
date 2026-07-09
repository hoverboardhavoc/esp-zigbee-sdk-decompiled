/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> mac_handle_received_frame
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void mac_handle_received_frame(int param_1,int *param_2,int param_3)

{
  int iVar1;
  undefined1 auStack_38 [28];
  ushort uStack_1c;
  
  if (param_3 != 0) {
    return;
  }
  iVar1 = mac_is_enabled();
  if (iVar1 == 0) {
    return;
  }
  if (param_2 == (int *)0x0) {
    return;
  }
  if (*param_2 == 0) {
    return;
  }
  iVar1 = mac_frame_parse(param_2,auStack_38);
  if (iVar1 != 0) {
    return;
  }
  iVar1 = mac_filter_apply_to_rxframe(auStack_38);
  if (iVar1 != 0) {
    return;
  }
  iVar1 = mac_process_receive_security(param_1,auStack_38);
  if (iVar1 != 0) {
    return;
  }
  if (*(char *)(param_1 + 0x2e) == '\x01') {
    if ((uStack_1c & 7) == 0) {
      mac_report_active_scan_result(param_1,auStack_38);
      return;
    }
  }
  else if (*(char *)(param_1 + 0x2e) != '\x02') goto _L0;
  if (*(char *)(param_1 + 0x43) != *(char *)(param_1 + 0x32)) {
    return;
  }
_L0:
  if ((uStack_1c & 7) == 1) {
    mac_handle_data(param_1,auStack_38);
  }
  else if ((uStack_1c & 7) == 3) {
    mac_handle_command(param_1,auStack_38);
  }
  else if ((uStack_1c & 7) == 0) {
    mac_handle_beacon(param_1,auStack_38);
  }
  return;
}

