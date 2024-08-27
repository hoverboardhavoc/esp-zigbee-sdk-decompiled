/*
 * Last changed at upstream commit eec5098a388a0960da2662a0145e34c21f0838a0
 * https://github.com/espressif/esp-zigbee-sdk/commit/eec5098a388a0960da2662a0145e34c21f0838a0
 * Upstream date: 2024-08-27 08:46:30 +0000
 * Upstream subject: esp-zigbee-lib:(6bd34178)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_zcl_simple_meas.o -> check_value_simple_u16_meas_server
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4
check_value_simple_u16_meas_server
          (undefined4 param_1,uint param_2,undefined4 param_3,undefined4 param_4,ushort *param_5)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  
  uVar3 = zb_zcl_attr_get16(param_4);
  if (param_2 < 4) {
    if (uVar3 == 0xffff) {
      uVar4 = 0;
    }
    else {
      if (param_2 == 3) {
        uVar7 = (uint)param_5[2];
        uVar6 = (uint)param_5[3];
      }
      else {
        uVar1 = *param_5;
        uVar2 = param_5[1];
        uVar7 = (uint)uVar1;
        if ((param_2 == 0) || (param_2 == 2)) {
          iVar5 = zb_zcl_get_attr_desc_a(param_3,param_1,1,1);
          if (**(ushort **)(iVar5 + 6) != 0xffff) {
            uVar7 = (uint)**(ushort **)(iVar5 + 6);
          }
        }
        uVar6 = (uint)uVar2;
        if (param_2 < 2) {
          iVar5 = zb_zcl_get_attr_desc_a(param_3,param_1,1,2);
          if (**(ushort **)(iVar5 + 6) != 0xffff) {
            uVar6 = (uint)**(ushort **)(iVar5 + 6);
          }
        }
      }
      if (uVar3 < uVar7) {
        uVar4 = 0xffffffff;
      }
      else if (uVar6 < uVar3) {
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

