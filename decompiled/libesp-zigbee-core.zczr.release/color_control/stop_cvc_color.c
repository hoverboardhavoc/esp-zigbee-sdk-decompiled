/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> color_control.o -> stop_cvc_color
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void stop_cvc_color(uint8_t ep_id,uint8_t mode)

{
  byte *pbVar1;
  undefined3 in_register_00002029;
  zcl_attr_desc_t *pzVar2;
  zcl_attr_desc_t *pzVar3;
  undefined3 in_register_0000202d;
  uint uVar4;
  
  uVar4 = CONCAT31(in_register_0000202d,mode);
  pzVar2 = color_control_srv_get_attr_desc(ep_id,(uint16_t)uVar4);
  pzVar3 = color_control_srv_get_attr_desc(ep_id,0x4001);
  if ((pzVar2 == (zcl_attr_desc_t *)0x0) || (pzVar3 == (zcl_attr_desc_t *)0x0)) {
    pzVar3 = (zcl_attr_desc_t *)__assert_func(0,0,0,0);
  }
                    /* WARNING: Load size is inaccurate */
  if ((*pzVar3->data_p != uVar4) && (uVar4 != 0xff)) {
    return;
  }
  pbVar1 = (byte *)pzVar2->data_p;
  if ((uint)*pbVar1 == CONCAT31(in_register_00002029,ep_id)) {
    zcl_cvc_stop(pbVar1);
  }
  if ((uint)pbVar1[0x40] == CONCAT31(in_register_00002029,ep_id)) {
    zcl_cvc_stop(pbVar1 + 0x40);
  }
  pzVar2 = color_control_srv_get_attr_desc(ep_id,2);
  if (pzVar2 != (zcl_attr_desc_t *)0x0) {
    *(undefined2 *)pzVar2->data_p = 0;
  }
  return;
}

