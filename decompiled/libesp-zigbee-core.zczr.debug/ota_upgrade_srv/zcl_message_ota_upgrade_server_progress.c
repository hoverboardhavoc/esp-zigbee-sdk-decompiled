/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> ota_upgrade_srv.o -> zcl_message_ota_upgrade_server_progress
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint zcl_message_ota_upgrade_server_progress
               (undefined4 param_1,uint param_2,undefined1 *param_3,undefined2 *param_4)

{
  uint uVar1;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  uint uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  uStack_4c = 0;
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
  uVar1 = zcl_packet_to_message(&uStack_4c,param_1);
  if (uVar1 != 0) {
    return uVar1;
  }
  uStack_44 = param_1;
  uStack_40 = param_2;
  if (param_2 == 5) {
    if (param_3 == (undefined1 *)0x0) {
      return 0;
    }
    uStack_3c = CONCAT31(uStack_3c._1_3_,*param_3);
    uStack_3c = CONCAT22(*(undefined2 *)(param_3 + 2),(undefined2)uStack_3c);
    uStack_38 = CONCAT22(uStack_38._2_2_,*(undefined2 *)(param_3 + 4));
    uStack_34 = *(undefined4 *)(param_3 + 8);
    goto _L0;
  }
  if (param_2 < 6) {
    if (param_2 == 0) {
      if (param_3 == (undefined1 *)0x0) {
        return 0;
      }
      memcpy(&uStack_3c,param_3,0x14);
      goto _L0;
    }
    if (param_2 == 2) {
      if (param_3 == (undefined1 *)0x0) {
        return 0;
      }
      uStack_3c = *(undefined4 *)(param_3 + 2);
      uStack_38 = *(undefined4 *)(param_3 + 8);
      uStack_34 = *(undefined4 *)(param_3 + 0xc);
      uStack_30 = CONCAT22(uStack_30._2_2_,*(undefined2 *)(param_3 + 0x1a));
      goto _L0;
    }
  }
  else if (param_2 == 6) goto _L0;
  uStack_4c = CONCAT31(uStack_4c._1_3_,0x87);
_L0:
  uStack_28 = CONCAT31(uStack_28._1_3_,0xfe);
  zcl_core_action_schedule(0x3d,&uStack_4c);
  uVar1 = 0;
  if ((uStack_28 & 0xff) != 0xfe) {
    uVar1 = uStack_28 & 0xff;
  }
  if ((uStack_40 != 6) && (uVar1 == 0x95)) {
    zcl_message_ota_upgrade_server_progress(param_1,6,0,0);
    uVar1 = 0xfe;
  }
  if ((uStack_40 == 5) && (param_4 != (undefined2 *)0x0)) {
    *param_4 = uStack_28._2_2_;
    param_4[1] = (undefined2)uStack_24;
  }
  return uVar1;
}

