/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> thermostat.o -> thermostat_set_heat_cool_value
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void thermostat_set_heat_cool_value
               (uint8_t ep_id,uint8_t setpoint_mode,int16_t heat_value,int16_t cool_value)

{
  _Bool _Var1;
  undefined3 extraout_var;
  uint16_t attr_id;
  undefined3 in_register_0000202d;
  int iVar2;
  int16_t *value;
  int16_t iStack_14;
  int16_t aiStack_12 [3];
  
  iVar2 = CONCAT31(in_register_0000202d,setpoint_mode);
  iStack_14 = cool_value;
  aiStack_12[0] = heat_value;
  _Var1 = thermostat_is_occupied(ep_id);
  if (CONCAT31(extraout_var,_Var1) == 0) {
    if (iVar2 == 0) {
      value = aiStack_12;
      attr_id = 0x14;
    }
    else {
      if (iVar2 != 1) {
        thermostat_srv_set_attr_value(ep_id,0x14,aiStack_12);
      }
      value = &iStack_14;
      attr_id = 0x13;
    }
  }
  else if (iVar2 == 0) {
    value = aiStack_12;
    attr_id = 0x12;
  }
  else {
    if (iVar2 != 1) {
      thermostat_srv_set_attr_value(ep_id,0x12,aiStack_12);
    }
    value = &iStack_14;
    attr_id = 0x11;
  }
  thermostat_srv_set_attr_value(ep_id,attr_id,value);
  return;
}

