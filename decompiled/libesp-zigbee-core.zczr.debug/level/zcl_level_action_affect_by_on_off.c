/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> level.o -> zcl_level_action_affect_by_on_off
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

bool zcl_level_action_affect_by_on_off(undefined4 param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  undefined1 auStack_44 [4];
  uint uStack_40;
  uint uStack_3c;
  undefined2 uStack_38;
  uint uStack_34;
  undefined1 uStack_30;
  code *pcStack_2c;
  uint uStack_28;
  byte abStack_21 [5];
  
  abStack_21[0] = 0;
  auStack_44[0] = (undefined1)param_1;
  uStack_40 = 0;
  uStack_3c = 0;
  uStack_38 = 1;
  uStack_34 = 0;
  uStack_30 = 0;
  pcStack_2c = level_cvc_affect_with_on_off_output_handler;
  uStack_28 = 0;
  iVar2 = ezb_af_get_ep_desc();
  if (iVar2 == 0) {
    bVar1 = false;
  }
  else {
    iVar2 = ezb_zcl_get_cluster_desc(param_1,8,1);
    if (iVar2 == 0) {
      bVar1 = false;
    }
    else {
      iVar2 = level_srv_get_attr_desc(param_1,0x11);
      iVar3 = level_srv_get_attr_desc(param_1,0);
      iVar4 = level_srv_get_attr_desc(param_1,2);
      iVar5 = level_srv_get_attr_desc(param_1,0x10);
      if (iVar4 == 0) {
        uVar6 = 0;
      }
      else {
        uVar6 = (uint)**(byte **)(iVar4 + 8);
      }
      abStack_21[0] = (byte)uVar6;
      uVar7 = (uint)**(byte **)(iVar3 + 8);
      if (param_2 == 0) {
        uStack_40 = uVar7;
        uStack_3c = uVar6;
        uStack_28 = uVar7;
        if ((iVar2 != 0) && (**(char **)(iVar2 + 8) != -1)) {
          uStack_28 = uVar6;
        }
      }
      else {
        level_srv_set_attr_value(param_1,0,abStack_21);
        uStack_40 = (uint)abStack_21[0];
        uStack_3c = uVar7;
        uStack_28 = uVar7;
        if ((iVar2 != 0) && (**(byte **)(iVar2 + 8) != 0xff)) {
          uStack_3c = (uint)**(byte **)(iVar2 + 8);
          uStack_28 = (uint)**(byte **)(iVar2 + 8);
        }
      }
      if (uStack_40 == uStack_3c) {
        bVar1 = false;
      }
      else {
        if (iVar5 == 0) {
          uStack_34 = 0xffff;
        }
        else {
          uStack_34 = (uint)**(ushort **)(iVar5 + 8);
        }
        iVar2 = schedule_cvc_level(param_1,auStack_44);
        bVar1 = iVar2 == 0;
      }
    }
  }
  return bVar1;
}

