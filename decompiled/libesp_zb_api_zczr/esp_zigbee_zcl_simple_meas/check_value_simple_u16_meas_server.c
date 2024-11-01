/*
 * Last changed at upstream commit b16fd900dd0b442e8e677ff001b10a2e9e95729b
 * https://github.com/espressif/esp-zigbee-sdk/commit/b16fd900dd0b442e8e677ff001b10a2e9e95729b
 * Upstream date: 2024-11-01 15:37:53 +0800
 * Upstream subject: esp-zigbee-lib:(4f5d21fb)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_simple_meas.o -> check_value_simple_u16_meas_server
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
      iVar4 = zb_zcl_get_attr_desc_a(param_3,param_1,1,1);
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

