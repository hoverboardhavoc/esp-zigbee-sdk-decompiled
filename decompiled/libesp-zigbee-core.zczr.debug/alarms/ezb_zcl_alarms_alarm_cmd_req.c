/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> alarms.o -> ezb_zcl_alarms_alarm_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int ezb_zcl_alarms_alarm_cmd_req(int param_1)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined2 uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined2 uStack_4a;
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
  if (param_1 == 0) {
    iVar4 = -1;
  }
  else {
    iVar4 = zcl_packet_init(&uStack_48,0);
    if (iVar4 == 0) {
      iVar4 = zcl_cmd_to_packet(&uStack_48,0,1,*(undefined1 *)(param_1 + 0xc),0,0,9);
      if (iVar4 == 0) {
        uStack_4a = CONCAT11(uStack_4a._1_1_,*(undefined1 *)(param_1 + 0x18));
        iVar4 = zmsg_append_bytes(uStack_24,1,&uStack_4a);
        if (iVar4 == 0) {
          uStack_4a = *(undefined2 *)(param_1 + 0x1a);
          iVar4 = zmsg_append_bytes(uStack_24,2,&uStack_4a);
          if (iVar4 == 0) {
            zcl_packet_send(&uStack_48,param_1 + 0x10);
            iVar4 = zcl_status_to_err();
            if (iVar4 == 0) {
              return 0;
            }
          }
        }
      }
    }
    else {
      iVar4 = -1;
    }
  }
  zcl_packet_free(&uStack_48);
  uVar1 = *(undefined1 *)(param_1 + 0xb);
  uVar2 = *(undefined1 *)(param_1 + 0x18);
  uVar3 = *(undefined2 *)(param_1 + 0x1a);
  uVar5 = zcl_time_get_utc_time(uVar1);
  alarm_table_add(uVar1,uVar2,uVar3,uVar5);
  return iVar4;
}

