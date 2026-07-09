/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> door_lock.o -> door_lock_cluster_cli_cmd_proc_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int door_lock_cluster_cli_cmd_proc_handler(int param_1)

{
  int iVar1;
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
    iVar1 = 1;
  }
  else if ((*(byte *)(param_1 + 0x1a) & 8) == 0) {
    iVar1 = 1;
  }
  else {
    iVar1 = zcl_packet_init(&uStack_38,*(byte *)(param_1 + 0x1a) >> 2 & 1);
    if (iVar1 == 0) {
      if (*(char *)(param_1 + 0x20) == '\0') {
        iVar1 = door_lock_cluster_lock_door_rsp_handler(param_1,&uStack_38);
      }
      else if (*(char *)(param_1 + 0x20) == '\x01') {
        iVar1 = door_lock_cluster_unlock_door_rsp_handler(param_1,&uStack_38);
      }
      else {
        iVar1 = zcl_packet_setup_default_response(&uStack_38,param_1,0x81);
      }
      if (iVar1 == 0) {
        zcl_packet_send(&uStack_38,0);
      }
      else {
        zcl_packet_free(&uStack_38);
      }
    }
  }
  return iVar1;
}

