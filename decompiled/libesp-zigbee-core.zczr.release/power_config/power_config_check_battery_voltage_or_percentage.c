/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> power_config.o -> power_config_check_battery_voltage_or_percentage
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void power_config_check_battery_voltage_or_percentage
               (uint8_t ep_id,uint8_t value,uint16_t base_attr_id,_Bool is_percentage,uint8_t source
               )

{
  undefined3 in_register_00002029;
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined3 in_register_0000202d;
  uint uVar5;
  undefined2 in_register_00002032;
  undefined3 in_register_00002035;
  undefined3 in_register_00002039;
  undefined1 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined1 auStack_2c [4];
  
  iVar3 = CONCAT22(in_register_00002032,base_attr_id);
  uVar5 = CONCAT31(in_register_0000202d,value);
  uVar1 = CONCAT31(in_register_00002029,ep_id);
  if (iVar3 == 0x20) {
    uVar7 = 0x39;
    uVar8 = 0x38;
    uVar9 = 0x37;
    uVar10 = 0x36;
  }
  else if (iVar3 == 0x40) {
    uVar7 = 0x59;
    uVar8 = 0x58;
    uVar9 = 0x57;
    uVar10 = 0x56;
  }
  else {
    uVar7 = 0x79;
    uVar8 = 0x78;
    uVar9 = 0x77;
    uVar10 = 0x76;
  }
  if (CONCAT31(in_register_00002035,is_percentage) != 0) {
    if (iVar3 == 0x20) {
      uVar7 = 0x3d;
      uVar8 = 0x3c;
      uVar9 = 0x3b;
      uVar10 = 0x3a;
    }
    else if (iVar3 == 0x40) {
      uVar7 = 0x5d;
      uVar8 = 0x5c;
      uVar9 = 0x5b;
      uVar10 = 0x5a;
    }
    else {
      uVar7 = 0x7d;
      uVar8 = 0x7c;
      uVar9 = 0x7b;
      uVar10 = 0x7a;
    }
  }
  iVar2 = zcl_get_attr_desc(uVar1,1,iVar3 + 0x1eU & 0xffff,0);
  iVar3 = zcl_get_attr_desc(uVar1,1,iVar3 + 0x15U & 0xffff,0);
  if ((iVar2 == 0) || (iVar3 == 0)) {
    return;
  }
  iVar4 = zcl_get_attr_desc(uVar1,1,uVar10,0);
  if ((iVar4 == 0) || ((**(byte **)(iVar4 + 8) <= uVar5 || (**(byte **)(iVar4 + 8) == 0xff)))) {
    iVar4 = zcl_get_attr_desc(uVar1,1,uVar9,0);
    if ((iVar4 == 0) || ((**(byte **)(iVar4 + 8) <= uVar5 || (**(byte **)(iVar4 + 8) == 0xff)))) {
      iVar4 = zcl_get_attr_desc(uVar1,1,uVar8,0);
      if ((iVar4 == 0) || ((**(byte **)(iVar4 + 8) <= uVar5 || (**(byte **)(iVar4 + 8) == 0xff)))) {
        iVar4 = zcl_get_attr_desc(uVar1,1,uVar7,0);
        if (iVar4 == 0) {
          return;
        }
        if (**(byte **)(iVar4 + 8) <= uVar5) {
          return;
        }
        if (**(byte **)(iVar4 + 8) == 0xff) {
          return;
        }
        iVar4 = 3;
        uVar6 = 8;
      }
      else {
        iVar4 = 2;
        uVar6 = 4;
      }
    }
    else {
      iVar4 = 1;
      uVar6 = 2;
    }
  }
  else {
    iVar4 = 0;
    uVar6 = 1;
  }
  **(undefined1 **)(iVar3 + 8) = uVar6;
  **(int **)(iVar2 + 8) =
       (CONCAT31(in_register_00002039,source) <<
       ((CONCAT31(in_register_00002039,source) + -1) * 10 & 0x1fU)) + iVar4;
  iVar3 = af_get_ep_desc();
  if ((iVar3 != 0) && (iVar3 = af_endpoint_get_cluster_desc(9,1), iVar3 != 0)) {
    memset(auStack_2c,0,0x1a);
    ezb_zcl_alarms_alarm_cmd_req(auStack_2c);
  }
  return;
}

