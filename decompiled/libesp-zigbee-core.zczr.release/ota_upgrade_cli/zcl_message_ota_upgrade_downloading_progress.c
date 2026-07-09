/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> ota_upgrade_cli.o -> zcl_message_ota_upgrade_downloading_progress
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint zcl_message_ota_upgrade_downloading_progress(int param_1,uint param_2,int *param_3)

{
  uint uVar1;
  undefined1 local_40 [8];
  int iStack_38;
  uint uStack_34;
  int iStack_30;
  int iStack_2c;
  int iStack_28;
  byte bStack_24;
  
  memset(local_40,0,0x20);
  uVar1 = zcl_packet_to_message(local_40,param_1);
  if (uVar1 != 0) {
    return uVar1;
  }
  iStack_38 = param_1;
  uStack_34 = param_2;
  if (param_2 == 4) {
    if (param_3 == (int *)0x0) {
      return 0;
    }
    iStack_2c = param_3[1];
    iStack_30 = *param_3;
    goto _L0;
  }
  if (param_2 < 5) {
    if (param_2 == 1) {
      if (param_3 == (int *)0x0) {
        return 0;
      }
      iStack_30 = param_3[3];
      iStack_2c = CONCAT31(iStack_2c._1_3_,(char)param_3[4]);
      iStack_28 = param_3[5];
      goto _L0;
    }
    if (param_2 == 3) {
      if (param_3 == (int *)0x0) {
        return 0;
      }
      iStack_2c = param_3[2];
      iStack_30 = param_3[1];
      goto _L0;
    }
    if (param_2 == 0) {
      if (param_3 == (int *)0x0) {
        return 0;
      }
      iStack_30 = *(int *)((int)param_3 + 2);
      iStack_2c = param_3[2];
      iStack_28 = param_3[3];
      goto _L0;
    }
  }
  else {
    if (param_2 == 5) {
      if (param_3 == (int *)0x0) {
        return 0;
      }
      iStack_30 = param_3[3] - param_3[2];
      goto _L0;
    }
    if (param_2 == 6) {
      ota_upgrade_downloading_context_get(*(undefined1 *)(param_1 + 0x15));
      ota_upgrade_set_upgrade_status_normal();
      goto _L0;
    }
  }
  local_40[0] = 0x87;
_L0:
  bStack_24 = 0xfe;
  zcl_core_action_schedule(0x3b,local_40);
  uVar1 = 0;
  if (bStack_24 != 0xfe) {
    uVar1 = (uint)bStack_24;
  }
  if ((uStack_34 != 6) && (uVar1 == 0x95)) {
    zcl_message_ota_upgrade_downloading_progress(param_1,0);
    uVar1 = 0xfe;
  }
  return uVar1;
}

