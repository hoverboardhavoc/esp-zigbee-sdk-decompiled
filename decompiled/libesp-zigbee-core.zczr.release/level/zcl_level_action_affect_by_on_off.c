/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> level.o -> zcl_level_action_affect_by_on_off
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

bool zcl_level_action_affect_by_on_off(undefined4 param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  byte bStack_41;
  undefined1 auStack_40 [4];
  uint uStack_3c;
  uint uStack_38;
  undefined2 uStack_34;
  uint uStack_30;
  undefined1 uStack_2c;
  code *pcStack_28;
  uint uStack_24;
  
  bStack_41 = 0;
  auStack_40[0] = (undefined1)param_1;
  uStack_3c = 0;
  uStack_38 = 0;
  uStack_34 = 1;
  uStack_30 = 0;
  uStack_2c = 0;
  pcStack_28 = level_cvc_affect_with_on_off_output_handler;
  uStack_24 = 0;
  iVar2 = ezb_af_get_ep_desc();
  if (iVar2 == 0) {
    return false;
  }
  iVar2 = ezb_zcl_get_cluster_desc(param_1,8,1);
  if (iVar2 == 0) {
    return false;
  }
  iVar2 = level_srv_get_attr_desc(param_1,0x11);
  iVar3 = level_srv_get_attr_desc(param_1,0);
  iVar4 = level_srv_get_attr_desc(param_1,2);
  iVar5 = level_srv_get_attr_desc(param_1,0x10);
  uVar6 = 0;
  if (iVar4 != 0) {
    uVar6 = (uint)**(byte **)(iVar4 + 8);
  }
  bStack_41 = (byte)uVar6;
  uVar1 = (uint)**(byte **)(iVar3 + 8);
  if (param_2 == 0) {
    uStack_3c = uVar1;
    uStack_38 = uVar6;
    if ((iVar2 == 0) || (**(char **)(iVar2 + 8) == -1)) goto _L0;
  }
  else {
    level_srv_set_attr_value_constprop_0(param_1,&bStack_41);
    uStack_3c = (uint)bStack_41;
    uVar6 = uVar1;
    if (iVar2 != 0) {
      uStack_38 = (uint)**(byte **)(iVar2 + 8);
      if (uStack_38 != 0xff) {
        uVar1 = (uint)**(byte **)(iVar2 + 8);
        goto _L0;
      }
    }
  }
  uVar1 = uVar6;
  uStack_38 = uVar1;
_L0:
  if (uStack_3c == uStack_38) {
    return false;
  }
  if (iVar5 == 0) {
    uStack_30 = 0xffff;
  }
  else {
    uStack_30 = (uint)**(ushort **)(iVar5 + 8);
  }
  uStack_24 = uVar1;
  iVar2 = schedule_cvc_level(param_1,auStack_40);
  return iVar2 == 0;
}

