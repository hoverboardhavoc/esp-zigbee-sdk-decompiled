/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> alarms.o -> ezb_zcl_alarms_alarm_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int ezb_zcl_alarms_alarm_cmd_req(void *param_1)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined2 uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined1 auStack_50 [22];
  undefined2 uStack_3a;
  undefined1 auStack_38 [36];
  undefined4 uStack_14;
  
  memset(auStack_38,0,0x28);
  if ((param_1 == (void *)0x0) || (iVar4 = zcl_packet_init(auStack_38,0), iVar4 != 0)) {
    iVar4 = -1;
  }
  else {
    memcpy(auStack_50,param_1,10);
    iVar4 = zcl_cmd_to_packet(auStack_38,0,1,*(undefined1 *)((int)param_1 + 0xc),0,0,9);
    if (iVar4 == 0) {
      uStack_3a = CONCAT11(uStack_3a._1_1_,*(undefined1 *)((int)param_1 + 0x18));
      iVar4 = zmsg_append_bytes(uStack_14,1,&uStack_3a);
      if (iVar4 == 0) {
        uStack_3a = *(undefined2 *)((int)param_1 + 0x1a);
        iVar4 = zmsg_append_bytes(uStack_14,2,&uStack_3a);
        if (iVar4 == 0) {
          zcl_packet_send(auStack_38,(int)param_1 + 0x10);
          iVar4 = zcl_status_to_err();
          if (iVar4 == 0) {
            return 0;
          }
        }
      }
    }
  }
  zcl_packet_free(auStack_38);
  uVar1 = *(undefined1 *)((int)param_1 + 0xb);
  uVar2 = *(undefined1 *)((int)param_1 + 0x18);
  uVar3 = *(undefined2 *)((int)param_1 + 0x1a);
  uVar5 = zcl_time_get_utc_time(uVar1);
  alarm_table_add(uVar1,uVar2,uVar3,uVar5);
  return iVar4;
}

