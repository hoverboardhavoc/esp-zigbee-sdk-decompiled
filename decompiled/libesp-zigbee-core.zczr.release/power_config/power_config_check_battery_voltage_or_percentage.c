/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> power_config.o -> power_config_check_battery_voltage_or_percentage
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void power_config_check_battery_voltage_or_percentage
               (undefined4 param_1,uint param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined1 auStack_2c [4];
  
  if (param_3 == 0x20) {
    uVar5 = 0x39;
    uVar6 = 0x38;
    uVar7 = 0x37;
    uVar8 = 0x36;
  }
  else if (param_3 == 0x40) {
    uVar5 = 0x59;
    uVar6 = 0x58;
    uVar7 = 0x57;
    uVar8 = 0x56;
  }
  else {
    uVar5 = 0x79;
    uVar6 = 0x78;
    uVar7 = 0x77;
    uVar8 = 0x76;
  }
  if (param_4 != 0) {
    if (param_3 == 0x20) {
      uVar5 = 0x3d;
      uVar6 = 0x3c;
      uVar7 = 0x3b;
      uVar8 = 0x3a;
    }
    else if (param_3 == 0x40) {
      uVar5 = 0x5d;
      uVar6 = 0x5c;
      uVar7 = 0x5b;
      uVar8 = 0x5a;
    }
    else {
      uVar5 = 0x7d;
      uVar6 = 0x7c;
      uVar7 = 0x7b;
      uVar8 = 0x7a;
    }
  }
  iVar1 = zcl_get_attr_desc(param_1,1,param_3 + 0x1eU & 0xffff,0);
  iVar2 = zcl_get_attr_desc(param_1,1,param_3 + 0x15U & 0xffff,0);
  if ((iVar1 == 0) || (iVar2 == 0)) {
    return;
  }
  iVar3 = zcl_get_attr_desc(param_1,1,uVar8,0);
  if ((iVar3 == 0) || ((**(byte **)(iVar3 + 8) <= param_2 || (**(byte **)(iVar3 + 8) == 0xff)))) {
    iVar3 = zcl_get_attr_desc(param_1,1,uVar7,0);
    if ((iVar3 == 0) || ((**(byte **)(iVar3 + 8) <= param_2 || (**(byte **)(iVar3 + 8) == 0xff)))) {
      iVar3 = zcl_get_attr_desc(param_1,1,uVar6,0);
      if ((iVar3 == 0) || ((**(byte **)(iVar3 + 8) <= param_2 || (**(byte **)(iVar3 + 8) == 0xff))))
      {
        iVar3 = zcl_get_attr_desc(param_1,1,uVar5,0);
        if (iVar3 == 0) {
          return;
        }
        if (**(byte **)(iVar3 + 8) <= param_2) {
          return;
        }
        if (**(byte **)(iVar3 + 8) == 0xff) {
          return;
        }
        iVar3 = 3;
        uVar4 = 8;
      }
      else {
        iVar3 = 2;
        uVar4 = 4;
      }
    }
    else {
      iVar3 = 1;
      uVar4 = 2;
    }
  }
  else {
    iVar3 = 0;
    uVar4 = 1;
  }
  **(undefined1 **)(iVar2 + 8) = uVar4;
  **(int **)(iVar1 + 8) = (param_5 << ((param_5 + -1) * 10 & 0x1fU)) + iVar3;
  iVar1 = af_get_ep_desc();
  if ((iVar1 != 0) && (iVar1 = af_endpoint_get_cluster_desc(9,1), iVar1 != 0)) {
    memset(auStack_2c,0,0x1a);
    ezb_zcl_alarms_alarm_cmd_req(auStack_2c);
  }
  return;
}

