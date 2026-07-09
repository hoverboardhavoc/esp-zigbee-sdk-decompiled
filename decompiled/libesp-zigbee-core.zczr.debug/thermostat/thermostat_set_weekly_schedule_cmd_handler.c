/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> thermostat.o -> thermostat_set_weekly_schedule_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void thermostat_set_weekly_schedule_cmd_handler(int param_1,undefined4 param_2)

{
  undefined1 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uStack_2c;
  void *pvStack_28;
  ushort auStack_22 [3];
  
  auStack_22[0] = 0;
  uStack_2c = 0;
  pvStack_28 = (void *)0x0;
  uVar1 = *(undefined1 *)(param_1 + 0x15);
  uVar4 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
  af_read_le8(*(undefined4 *)(param_1 + 0x24),auStack_22,&uStack_2c);
  af_read_le8(*(undefined4 *)(param_1 + 0x24),auStack_22,(int)&uStack_2c + 1);
  af_read_le8(*(undefined4 *)(param_1 + 0x24),auStack_22,(int)&uStack_2c + 2);
  if ((byte)uStack_2c < 0xb) {
    pvStack_28 = calloc(1,0x3c);
    if (pvStack_28 == (void *)0x0) {
      iVar2 = 0x89;
    }
    else {
      for (uVar3 = 0; (auStack_22[0] < uVar4 && (uVar3 < (uStack_2c & 0xff)));
          uVar3 = uVar3 + 1 & 0xff) {
        iVar2 = uVar3 * 6;
        af_read_le16(*(undefined4 *)(param_1 + 0x24),auStack_22,(void *)((int)pvStack_28 + iVar2));
        if ((uStack_2c & 0x10000) != 0) {
          af_read_le16(*(undefined4 *)(param_1 + 0x24),auStack_22,(int)pvStack_28 + iVar2 + 2);
        }
        if ((uStack_2c & 0x20000) != 0) {
          af_read_le16(*(undefined4 *)(param_1 + 0x24),auStack_22,(int)pvStack_28 + iVar2 + 4);
        }
      }
      iVar2 = zcl_message_thermostat_set_weekly_schedule(param_1,&uStack_2c);
      if ((iVar2 == 0) &&
         (iVar2 = thermostat_weekly_schedule_add_transitions(uVar1,&uStack_2c), iVar2 == 0)) {
        thermostat_weekly_schedule_loop_start(uVar1);
      }
    }
  }
  else {
    iVar2 = 0x87;
  }
  if (pvStack_28 != (void *)0x0) {
    mm_free();
  }
  zcl_packet_setup_default_response(param_2,param_1,iVar2);
  return;
}

