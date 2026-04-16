/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> color_control.o -> color_control_srv_set_attr_value
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t color_control_srv_set_attr_value(uint8_t ep_id,uint16_t attr_id,uint8_t *value)

{
  ezb_zcl_status_t eVar1;
  undefined2 in_register_0000202e;
  
  eVar1 = ezb_zcl_set_attr_value(0x300,1,CONCAT22(in_register_0000202e,attr_id),0,value,0);
  return eVar1;
}

