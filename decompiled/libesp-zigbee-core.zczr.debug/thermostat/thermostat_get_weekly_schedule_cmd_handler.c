/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> thermostat.o -> thermostat_get_weekly_schedule_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 thermostat_get_weekly_schedule_cmd_handler(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  char cVar5;
  undefined2 uStack_26;
  undefined2 uStack_24;
  ushort auStack_22 [3];
  
  auStack_22[0] = 0;
  uStack_24 = 0;
  if (param_1 == 0) {
    uVar4 = 0x80;
  }
  else if (param_2 == 0) {
    uVar4 = 0x80;
  }
  else {
    af_read_le8(*(undefined4 *)(param_1 + 0x24),auStack_22,&uStack_24);
    af_read_le8(*(undefined4 *)(param_1 + 0x24),auStack_22,(int)&uStack_24 + 1);
    uVar1 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
    if (uVar1 < auStack_22[0]) {
      uVar4 = 0x80;
    }
    else {
      iVar2 = count_ones((undefined1)uStack_24);
      if (iVar2 == 1) {
        iVar2 = thermostat_weekly_schedule_context_get(*(undefined1 *)(param_1 + 0x15));
        uStack_26._0_1_ = 0;
        zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),1,&uStack_26);
        uStack_26._0_1_ = (undefined1)uStack_24;
        zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),1,&uStack_26);
        uStack_26 = CONCAT11(uStack_26._1_1_,uStack_24._1_1_);
        zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),1,&uStack_26);
        uVar1 = 0;
        do {
          if (6 < uVar1) {
            cVar5 = '\0';
_L0:
            uStack_26 = CONCAT11(uStack_26._1_1_,cVar5);
            zmsg_write_bytes(*(undefined4 *)(param_2 + 0x24),0,1,&uStack_26);
            zcl_packet_setup_response(param_2,param_1,0);
            return 0;
          }
          iVar3 = thermostat_weekly_schedule_day_is_set((undefined1)uStack_24,uVar1);
          if (iVar3 != 0) {
            iVar2 = *(int *)(iVar2 + uVar1 * 4 + 8);
            cVar5 = '\0';
            for (uVar1 = 0; ((iVar2 != 0 && (uVar1 < *(byte *)(iVar2 + 1))) && (uVar1 < 10));
                uVar1 = uVar1 + 1 & 0xff) {
              iVar3 = uVar1 * 6;
              uStack_26 = *(undefined2 *)(*(int *)(iVar2 + 4) + iVar3);
              zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),2,&uStack_26);
              if ((uStack_24 & 0x100) != 0) {
                uStack_26 = *(undefined2 *)(*(int *)(iVar2 + 4) + iVar3 + 2);
                zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),2,&uStack_26);
              }
              if ((uStack_24 & 0x200) != 0) {
                uStack_26 = *(undefined2 *)(*(int *)(iVar2 + 4) + iVar3 + 4);
                zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),2,&uStack_26);
              }
              cVar5 = cVar5 + '\x01';
            }
            goto _L0;
          }
          uVar1 = uVar1 + 1 & 0xff;
        } while( true );
      }
      uVar4 = 0x85;
    }
  }
  zcl_packet_setup_default_response(param_2,param_1,uVar4);
  return uVar4;
}

