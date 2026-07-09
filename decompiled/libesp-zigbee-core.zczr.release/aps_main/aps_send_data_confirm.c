/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aps_main.o -> aps_send_data_confirm
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_send_data_confirm(int param_1,int param_2)

{
  undefined4 uVar1;
  uint uVar2;
  int iStack_48;
  undefined4 uStack_44;
  int iStack_40;
  undefined4 uStack_3c;
  uint uStack_38;
  undefined1 uStack_34;
  int iStack_30;
  undefined1 auStack_2c [4];
  undefined1 auStack_28 [10];
  undefined2 uStack_1e;
  uint uStack_1c;
  byte bStack_14;
  
  zmsg_get_footer(auStack_2c,0x1c);
  zmsg_remove_footer(param_1,0x1c);
  if ((*(ushort *)(param_1 + 0x16) & 0x20) == 0) {
    uVar1 = zmsg_get_offset(param_1);
    zmsg_remove_header(param_1,uVar1);
    memcpy(&uStack_44,auStack_28,10);
    uStack_34 = (undefined1)param_2;
    uStack_3c = CONCAT22(uStack_1e,(undefined2)uStack_3c);
    uStack_38 = uStack_1c;
    iStack_30 = param_1;
    if ((bStack_14 & 0x20) == 0) {
      aps_apsde_data_confirm();
    }
    else {
      aps_apsde_user_data_confirm(&uStack_44);
    }
  }
  else {
    iStack_48 = 0;
    zmsg_get_footer(param_1,&iStack_48,4);
    zmsg_free(param_1);
    if ((*(ushort *)(iStack_48 + 0x16) & 0x20) == 0) goto _L0;
    do {
      __assert_func(0,0,0,0);
_L0:
      uStack_44 = 0;
      iStack_40 = 0;
      uStack_3c = 0;
      uStack_38 = 0;
      zmsg_get_footer(&uStack_44,0x10);
    } while ((uStack_38 & 0xff) == 0);
    uVar2 = (uStack_38 & 0xff) - 1;
    uStack_38 = CONCAT31(uStack_38._1_3_,(char)uVar2);
    if (param_2 != 0) {
      uStack_3c = param_2;
    }
    if ((((uVar2 & 0xff) == 0) && (iStack_40 != 0)) &&
       (param_2 = aps_bind_trans_schedule_next_nmsg(uStack_44,iStack_48,&uStack_38), param_2 != 0))
    {
      uStack_3c = 1;
    }
    if ((uStack_38 & 0xff) == 0) {
      zmsg_remove_footer(iStack_48,0x10);
      aps_send_data_confirm(iStack_48,param_2);
    }
    else {
      zmsg_update_footer(&uStack_44,0x10);
    }
  }
  return;
}

