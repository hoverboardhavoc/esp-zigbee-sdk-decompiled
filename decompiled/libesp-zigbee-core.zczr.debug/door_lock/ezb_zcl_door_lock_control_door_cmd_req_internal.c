/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> door_lock.o -> ezb_zcl_door_lock_control_door_cmd_req_internal
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int ezb_zcl_door_lock_control_door_cmd_req_internal(int param_1,byte param_2,undefined4 param_3)

{
  int iVar1;
  byte abStack_4c [4];
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  uStack_48 = 0;
  uStack_44 = 0;
  uStack_40 = 0;
  uStack_3c = 0;
  uStack_38 = 0;
  uStack_34 = 0;
  uStack_30 = 0;
  uStack_2c = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  abStack_4c[0] = 0;
  iVar1 = zcl_packet_init(&uStack_48,0);
  if ((iVar1 == 0) &&
     (iVar1 = zcl_cmd_to_packet(&uStack_48,0,0,*(undefined1 *)(param_1 + 0xc),0,param_3,0x101),
     iVar1 == 0)) {
    abStack_4c[0] = abStack_4c[0] & 0xfe | param_2 & 1;
    zcl_packet_send_with_ext(&uStack_48,param_1 + 0x10,abStack_4c);
    iVar1 = zcl_status_to_err();
    if (iVar1 == 0) {
      return 0;
    }
  }
  zcl_packet_free(&uStack_48);
  return iVar1;
}

