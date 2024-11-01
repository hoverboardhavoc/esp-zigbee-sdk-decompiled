/*
 * Last changed at upstream commit b16fd900dd0b442e8e677ff001b10a2e9e95729b
 * https://github.com/espressif/esp-zigbee-sdk/commit/b16fd900dd0b442e8e677ff001b10a2e9e95729b
 * Upstream date: 2024-11-01 15:37:53 +0800
 * Upstream subject: esp-zigbee-lib:(4f5d21fb)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_simple_meas.o -> check_value_temp_measurement_server
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int check_value_temp_measurement_server(uint param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = zb_zcl_attr_gets16(param_3);
  if (3 < param_1) {
    return 0;
  }
  if (param_1 == 3) {
    iVar2 = zb_zcl_attr_get16(param_3);
    if (iVar2 == 0xffff) {
      return 0;
    }
    if (iVar1 < 0) {
      return -1;
    }
    return -(uint)(0x800 < iVar1);
  }
  if (iVar1 == -0x8000) {
    return 0;
  }
  iVar2 = -0x6ab3;
  if ((param_1 & 0xfffffffd) == 0) {
    iVar2 = zb_zcl_get_attr_desc_a(param_2,0x402,1,1);
    iVar2 = (int)**(short **)(iVar2 + 6);
    if (iVar2 == -0x8000) {
      iVar2 = -0x6ab3;
    }
    if (param_1 != 2) goto _L0;
  }
  else {
_L0:
    iVar3 = zb_zcl_get_attr_desc_a(param_2,0x402,1,2);
    iVar3 = (int)**(short **)(iVar3 + 6);
    if (iVar3 != -0x8000) goto _L0;
  }
  iVar3 = 0x7fff;
_L0:
  if (iVar1 < iVar2) {
    return -1;
  }
  return -(uint)(iVar3 < iVar1);
}

