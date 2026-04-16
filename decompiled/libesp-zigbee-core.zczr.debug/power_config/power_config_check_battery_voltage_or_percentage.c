/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> power_config.o -> power_config_check_battery_voltage_or_percentage
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
  _Bool _Var1;
  undefined3 in_register_00002029;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  undefined2 in_register_00002032;
  undefined3 in_register_00002035;
  undefined1 uVar6;
  undefined3 in_register_00002039;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  
  iVar4 = CONCAT22(in_register_00002032,base_attr_id);
  uVar2 = CONCAT31(in_register_00002029,ep_id);
  if (iVar4 == 0x20) {
    uVar9 = 0x39;
    uVar8 = 0x38;
    uVar7 = 0x37;
    uVar10 = 0x36;
  }
  else if (iVar4 == 0x40) {
    uVar9 = 0x59;
    uVar8 = 0x58;
    uVar7 = 0x57;
    uVar10 = 0x56;
  }
  else {
    if (iVar4 != 0x60) {
      return;
    }
    uVar9 = 0x79;
    uVar8 = 0x78;
    uVar7 = 0x77;
    uVar10 = 0x76;
  }
  if (CONCAT31(in_register_00002035,is_percentage) != 0) {
    if (iVar4 == 0x20) {
      uVar9 = 0x3d;
      uVar8 = 0x3c;
      uVar7 = 0x3b;
      uVar10 = 0x3a;
    }
    else if (iVar4 == 0x40) {
      uVar9 = 0x5d;
      uVar8 = 0x5c;
      uVar7 = 0x5b;
      uVar10 = 0x5a;
    }
    else {
      uVar9 = 0x7d;
      uVar8 = 0x7c;
      uVar7 = 0x7b;
      uVar10 = 0x7a;
    }
  }
  iVar3 = zcl_get_attr_desc(uVar2,1,iVar4 + 0x1eU & 0xffff,0);
  iVar4 = zcl_get_attr_desc(uVar2,1,iVar4 + 0x15U & 0xffff,0);
  if ((iVar3 != 0) && (iVar4 != 0)) {
    iVar5 = zcl_get_attr_desc(uVar2,1,uVar10,0);
    if ((iVar5 == 0) ||
       (_Var1 = power_config_value_under_threshold(value,**(uint8_t **)(iVar5 + 8)),
       CONCAT31(extraout_var,_Var1) == 0)) {
      iVar5 = zcl_get_attr_desc(uVar2,1,uVar7,0);
      if ((iVar5 == 0) ||
         (_Var1 = power_config_value_under_threshold(value,**(uint8_t **)(iVar5 + 8)),
         CONCAT31(extraout_var_00,_Var1) == 0)) {
        iVar5 = zcl_get_attr_desc(uVar2,1,uVar8,0);
        if ((iVar5 == 0) ||
           (_Var1 = power_config_value_under_threshold(value,**(uint8_t **)(iVar5 + 8)),
           CONCAT31(extraout_var_01,_Var1) == 0)) {
          iVar5 = zcl_get_attr_desc(uVar2,1,uVar9,0);
          if (iVar5 == 0) {
            return;
          }
          _Var1 = power_config_value_under_threshold(value,**(uint8_t **)(iVar5 + 8));
          if (CONCAT31(extraout_var_02,_Var1) == 0) {
            return;
          }
          iVar5 = 3;
          uVar6 = 8;
        }
        else {
          iVar5 = 2;
          uVar6 = 4;
        }
      }
      else {
        iVar5 = 1;
        uVar6 = 2;
      }
    }
    else {
      iVar5 = 0;
      uVar6 = 1;
    }
    **(undefined1 **)(iVar4 + 8) = uVar6;
    **(int **)(iVar3 + 8) =
         (CONCAT31(in_register_00002039,source) <<
         ((CONCAT31(in_register_00002039,source) + -1) * 10 & 0x1fU)) + iVar5;
    power_config_alarm(ep_id,source * '\x10' + (char)iVar5);
  }
  return;
}

