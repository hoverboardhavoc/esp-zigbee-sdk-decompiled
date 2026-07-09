/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> thermostat.o -> ezb_zcl_thermostat_set_weekly_schedule_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int ezb_zcl_thermostat_set_weekly_schedule_cmd_req(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
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
    iVar1 = -1;
  }
  else {
    iVar1 = zcl_packet_init(&uStack_48,0);
    if (iVar1 == 0) {
      iVar1 = zcl_cmd_to_packet(&uStack_48,0,0,*(undefined1 *)(param_1 + 0xc),0,1,0x201);
      if (iVar1 == 0) {
        uStack_4a = CONCAT11(uStack_4a._1_1_,*(undefined1 *)(param_1 + 0x18));
        iVar1 = zmsg_append_bytes(uStack_24,1,&uStack_4a);
        if (iVar1 == 0) {
          uStack_4a = CONCAT11(uStack_4a._1_1_,*(undefined1 *)(param_1 + 0x19));
          iVar1 = zmsg_append_bytes(uStack_24,1,&uStack_4a);
          if (iVar1 == 0) {
            uStack_4a = CONCAT11(uStack_4a._1_1_,*(undefined1 *)(param_1 + 0x1a));
            iVar1 = zmsg_append_bytes(uStack_24,1,&uStack_4a);
            uVar2 = 0;
            if (iVar1 == 0) {
              while (((uVar2 < 10 && (uVar2 < *(byte *)(param_1 + 0x18))) &&
                     (*(int *)(param_1 + 0x1c) != 0))) {
                iVar3 = uVar2 * 6;
                uStack_4a = *(undefined2 *)(*(int *)(param_1 + 0x1c) + iVar3);
                iVar1 = zmsg_append_bytes(uStack_24,2,&uStack_4a);
                if (iVar1 != 0) goto _L0;
                if ((*(byte *)(param_1 + 0x1a) & 1) != 0) {
                  uStack_4a = *(undefined2 *)(*(int *)(param_1 + 0x1c) + iVar3 + 2);
                  iVar1 = zmsg_append_bytes(uStack_24,2,&uStack_4a);
                  if (iVar1 != 0) goto _L0;
                }
                if ((*(byte *)(param_1 + 0x1a) & 2) != 0) {
                  uStack_4a = *(undefined2 *)(*(int *)(param_1 + 0x1c) + iVar3 + 4);
                  iVar1 = zmsg_append_bytes(uStack_24,2,&uStack_4a);
                  if (iVar1 != 0) goto _L0;
                }
                uVar2 = uVar2 + 1 & 0xff;
              }
              zcl_packet_send(&uStack_48,param_1 + 0x10);
              iVar1 = zcl_status_to_err();
_L0:
              if (iVar1 == 0) {
                return 0;
              }
            }
          }
        }
      }
    }
    else {
      iVar1 = -1;
    }
  }
  zcl_packet_free(&uStack_48);
  return iVar1;
}

