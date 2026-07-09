/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> poll_control.o -> poll_control_cluster_cli_cmd_proc_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint poll_control_cluster_cli_cmd_proc_handler(int param_1)

{
  byte bVar1;
  uint uVar2;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  uStack_38 = 0;
  uStack_34 = 0;
  uStack_30 = 0;
  uStack_2c = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  uStack_20 = 0;
  uStack_1c = 0;
  uStack_18 = 0;
  uStack_14 = 0;
  if (param_1 == 0) {
    uVar2 = 0;
  }
  else {
    bVar1 = *(byte *)(param_1 + 0x1a);
    uVar2 = bVar1 & 8;
    if (((bVar1 & 8) != 0) && (uVar2 = zcl_packet_init(&uStack_38,bVar1 >> 2 & 1), uVar2 == 0)) {
      if (*(char *)(param_1 + 0x20) == '\0') {
        uVar2 = poll_control_cluster_cli_check_in_req_handler(param_1,&uStack_38);
      }
      else {
        uVar2 = zcl_packet_setup_default_response(&uStack_38,param_1,0x81);
      }
      if (uVar2 == 0) {
        zcl_packet_send(&uStack_38,0);
      }
      else {
        zcl_packet_free(&uStack_38);
      }
    }
  }
  return uVar2;
}

