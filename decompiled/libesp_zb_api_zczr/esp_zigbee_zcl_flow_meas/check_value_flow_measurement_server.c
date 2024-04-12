/*
 * Last changed at upstream commit e28462af08968da8dbda59a317df742f0109ee5f
 * https://github.com/espressif/esp-zigbee-sdk/commit/e28462af08968da8dbda59a317df742f0109ee5f
 * Upstream date: 2024-04-12 14:44:19 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.3(042315bf)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_flow_meas.o -> check_value_flow_measurement_server
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int check_value_flow_measurement_server(uint param_1,undefined4 param_2,undefined4 param_3)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  
  uVar2 = zb_zcl_attr_get16(param_3);
  if (param_1 == 2) {
    return -(uint)(uVar2 == 0);
  }
  if (param_1 < 3) {
    if (param_1 != 0) {
      bVar1 = uVar2 == 0xfffe;
_L0:
      return -(uint)bVar1;
    }
    param_1 = 0xffff;
    if (uVar2 == 0xffff) {
      return 0;
    }
    iVar3 = zb_zcl_get_attr_desc_a(param_2,0x404,1,1);
    uVar4 = 0x40;
    if (iVar3 != 0) {
      if (**(ushort **)(iVar3 + 6) == 0xffff) {
        return 0;
      }
      if (**(ushort **)(iVar3 + 6) <= uVar2) {
        return 0;
      }
      iVar3 = zb_zcl_get_attr_desc_a(param_2,0x404,1,2);
      if (iVar3 != 0) {
        bVar1 = **(ushort **)(iVar3 + 6) < uVar2;
        goto _L0;
      }
      uVar4 = 0x4c;
    }
    uVar2 = zb_assert(0x10000,uVar4);
  }
  if (param_1 != 3) {
    return 0;
  }
  return (uVar2 < 0x801) - 1;
}

