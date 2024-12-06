/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_simple_meas.o -> check_value_simple_s16_meas_server
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4
check_value_simple_s16_meas_server
          (undefined4 param_1,uint param_2,undefined4 param_3,undefined4 param_4,short *param_5)

{
  short sVar1;
  short sVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar3 = zb_zcl_attr_gets16(param_4);
  if (param_2 < 4) {
    if (param_2 == 3) {
      iVar5 = zb_zcl_attr_get16(param_4);
      if (iVar5 == 0xffff) {
        uVar4 = 0;
      }
      else if (iVar3 < (int)(uint)(ushort)param_5[2]) {
        uVar4 = 0xffffffff;
      }
      else if ((int)(uint)(ushort)param_5[3] < iVar3) {
        uVar4 = 0xffffffff;
      }
      else {
        uVar4 = 0;
      }
    }
    else if (iVar3 == -0x8000) {
      uVar4 = 0;
    }
    else {
      sVar1 = *param_5;
      sVar2 = param_5[1];
      iVar5 = (int)sVar1;
      if ((param_2 == 0) || (param_2 == 2)) {
        iVar6 = zb_zcl_get_attr_desc_a(param_3,param_1,1,1);
        if (**(short **)(iVar6 + 6) != -0x8000) {
          iVar5 = (int)**(short **)(iVar6 + 6);
        }
      }
      iVar6 = (int)sVar2;
      if (param_2 < 2) {
        iVar7 = zb_zcl_get_attr_desc_a(param_3,param_1,1,2);
        if (**(short **)(iVar7 + 6) != -0x8000) {
          iVar6 = (int)**(short **)(iVar7 + 6);
        }
      }
      if (iVar3 < iVar5) {
        uVar4 = 0xffffffff;
      }
      else if (iVar6 < iVar3) {
        uVar4 = 0xffffffff;
      }
      else {
        uVar4 = 0;
      }
    }
  }
  else {
    uVar4 = 0;
  }
  return uVar4;
}

