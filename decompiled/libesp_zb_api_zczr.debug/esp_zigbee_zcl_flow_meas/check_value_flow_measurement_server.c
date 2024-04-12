/*
 * Last changed at upstream commit e28462af08968da8dbda59a317df742f0109ee5f
 * https://github.com/espressif/esp-zigbee-sdk/commit/e28462af08968da8dbda59a317df742f0109ee5f
 * Upstream date: 2024-04-12 14:44:19 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.3(042315bf)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_zcl_flow_meas.o -> check_value_flow_measurement_server
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 check_value_flow_measurement_server(uint param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = zb_zcl_attr_get16(param_3);
  if ((g_trace_level != '\0') && ((_g_trace_mask & 0x100) != 0)) {
    esp_zb_trace_msg_port
              (0x100,1,"> check_value_flow_measurement, attr_id %d, val %d",0x10000,0x34,8,param_1,
               uVar2);
  }
  if (param_1 != 2) {
    if (2 < param_1) {
      if (param_1 == 3) {
        if (uVar2 < 0x801) {
          uVar1 = 0;
        }
        else {
          uVar1 = 0xffffffff;
        }
      }
      else {
        uVar1 = 0;
      }
      goto _L0;
    }
    if (param_1 != 0) {
      if (param_1 == 1) {
        if (uVar2 == 0xfffe) {
          uVar1 = 0xffffffff;
        }
        else {
          uVar1 = 0;
        }
      }
      else {
        uVar1 = 0;
      }
      goto _L0;
    }
    if (uVar2 == 0xffff) {
      uVar1 = 0;
      goto _L0;
    }
    iVar3 = zb_zcl_get_attr_desc_a(param_2,0x404,1,1);
    if (iVar3 == 0) {
      zb_assert(0x10000,0x40);
    }
    else {
      if (**(ushort **)(iVar3 + 6) == 0xffff) {
        uVar1 = 0;
        goto _L0;
      }
      if (**(ushort **)(iVar3 + 6) <= uVar2) {
        uVar1 = 0;
        goto _L0;
      }
    }
    iVar3 = zb_zcl_get_attr_desc_a(param_2,0x404,1,2);
    if (iVar3 != 0) {
      if (**(ushort **)(iVar3 + 6) == 0xffff) {
        uVar1 = 0;
      }
      else if (**(ushort **)(iVar3 + 6) < uVar2) {
        uVar1 = 0xffffffff;
      }
      else {
        uVar1 = 0;
      }
      goto _L0;
    }
    zb_assert(0x10000,0x4c);
  }
  if (uVar2 == 0) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = 0;
  }
_L0:
  if ((g_trace_level != '\0') && ((_g_trace_mask & 0x100) != 0)) {
    esp_zb_trace_msg_port(0x100,1,"< check_value_flow_measurement ret %hd",0x10000,0x6d,4,uVar1);
  }
  return uVar1;
}

