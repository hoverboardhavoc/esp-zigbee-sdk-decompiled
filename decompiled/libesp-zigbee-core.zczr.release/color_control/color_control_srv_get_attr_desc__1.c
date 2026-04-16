/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> color_control.o -> color_control_srv_get_attr_desc__1
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zcl_attr_desc_t * color_control_srv_get_attr_desc(uint8_t ep_id,uint16_t attr_id)

{
  undefined3 in_register_00002029;
  zcl_attr_desc_t *pzVar1;
  undefined2 in_register_0000202e;
  
  if (CONCAT22(in_register_0000202e,attr_id) == 0xeff0) {
    pzVar1 = (zcl_attr_desc_t *)
             ezb_zcl_get_attr_desc(CONCAT31(in_register_00002029,ep_id),0x300,1,0xeff0,0x131b);
    return pzVar1;
  }
  pzVar1 = (zcl_attr_desc_t *)
           ezb_zcl_get_attr_desc(0x300,1,CONCAT22(in_register_0000202e,attr_id),0);
  return pzVar1;
}

