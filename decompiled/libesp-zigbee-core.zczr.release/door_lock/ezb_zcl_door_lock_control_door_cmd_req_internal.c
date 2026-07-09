/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> door_lock.o -> ezb_zcl_door_lock_control_door_cmd_req_internal
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int ezb_zcl_door_lock_control_door_cmd_req_internal(void *param_1,byte param_2,undefined4 param_3)

{
  int iVar1;
  undefined1 auStack_60 [20];
  byte abStack_4c [4];
  undefined1 auStack_48 [52];
  
  memset(auStack_48,0,0x28);
  abStack_4c[0] = 0;
  iVar1 = zcl_packet_init(auStack_48,0);
  if (iVar1 == 0) {
    memcpy(auStack_60,param_1,10);
    iVar1 = zcl_cmd_to_packet(auStack_48,0,0,*(undefined1 *)((int)param_1 + 0xc),0,param_3,0x101);
    if (iVar1 == 0) {
      abStack_4c[0] = abStack_4c[0] & 0xfe | param_2 & 1;
      zcl_packet_send_with_ext(auStack_48,(int)param_1 + 0x10,abStack_4c);
      iVar1 = zcl_status_to_err();
      if (iVar1 == 0) {
        return 0;
      }
    }
  }
  zcl_packet_free(auStack_48);
  return iVar1;
}

