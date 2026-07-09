/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> thermostat.o -> thermostat_get_weekly_schedule_rsp_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void thermostat_get_weekly_schedule_rsp_cmd_handler(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uStack_2c;
  void *pvStack_28;
  ushort auStack_22 [7];
  
  auStack_22[0] = 0;
  uStack_2c = 0;
  pvStack_28 = (void *)0x0;
  if (param_1 == 0) {
    uVar3 = 0x80;
  }
  else if (param_2 == 0) {
    uVar3 = 0x80;
  }
  else {
    af_read_le8(*(undefined4 *)(param_1 + 0x24),auStack_22,&uStack_2c);
    af_read_le8(*(undefined4 *)(param_1 + 0x24),auStack_22,(int)&uStack_2c + 2);
    af_read_le8(*(undefined4 *)(param_1 + 0x24),auStack_22,(int)&uStack_2c + 1);
    pvStack_28 = calloc(1,(uStack_2c & 0xff) * 6);
    if (pvStack_28 == (void *)0x0) {
      uVar3 = 0x89;
    }
    else {
      for (uVar2 = 0; uVar2 < (uStack_2c & 0xff); uVar2 = uVar2 + 1 & 0xff) {
        iVar1 = uVar2 * 6;
        af_read_le16(*(undefined4 *)(param_1 + 0x24),auStack_22,(void *)((int)pvStack_28 + iVar1));
        if ((uStack_2c & 0x10000) == 0) {
          *(undefined2 *)((int)pvStack_28 + iVar1 + 2) = 0;
        }
        else {
          af_read_le16(*(undefined4 *)(param_1 + 0x24),auStack_22,(int)pvStack_28 + iVar1 + 2);
        }
        if ((uStack_2c & 0x20000) == 0) {
          *(undefined2 *)((int)pvStack_28 + iVar1 + 4) = 0;
        }
        else {
          af_read_le16(*(undefined4 *)(param_1 + 0x24),auStack_22,(int)pvStack_28 + iVar1 + 4);
        }
      }
      uVar2 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
      if (uVar2 < auStack_22[0]) {
        uVar3 = 0x80;
      }
      else {
        uVar3 = zcl_message_thermostat_get_weekly_schedule_response(param_1,&uStack_2c);
      }
    }
  }
  zcl_packet_setup_default_response(param_2,param_1,uVar3);
  return;
}

