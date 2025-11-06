/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_simple_meas.o -> check_value_simple_u16_meas_server
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int check_value_simple_u16_meas_server
              (undefined4 param_1,uint param_2,undefined4 param_3,undefined4 param_4,ushort *param_5
              )

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  uVar3 = zb_zcl_attr_get16(param_4);
  if (3 < param_2) {
    return 0;
  }
  if (uVar3 == 0xffff) {
    return 0;
  }
  if (param_2 == 3) {
    uVar5 = (uint)param_5[2];
    uVar2 = (uint)param_5[3];
  }
  else {
    uVar5 = (uint)*param_5;
    uVar1 = param_5[1];
    uVar2 = (uint)uVar1;
    if ((param_2 & 0xfffffffd) == 0) {
      iVar4 = zb_zcl_get_attr_desc_a(param_3,param_1,1);
      if (**(ushort **)(iVar4 + 6) != 0xffff) {
        uVar5 = (uint)**(ushort **)(iVar4 + 6);
      }
      if (param_2 == 2) goto _L0;
    }
    iVar4 = zb_zcl_get_attr_desc_a(param_3,param_1,1,2);
    if (**(ushort **)(iVar4 + 6) != 0xffff) {
      uVar2 = (uint)**(ushort **)(iVar4 + 6);
    }
  }
_L0:
  iVar4 = -1;
  if (uVar5 <= uVar3) {
    iVar4 = -(uint)(uVar2 < uVar3);
  }
  return iVar4;
}

