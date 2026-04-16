/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> color_control.o -> stop_cvc_color
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void stop_cvc_color(uint8_t ep_id,uint8_t mode)

{
  undefined3 in_register_00002029;
  zcl_attr_desc_t *pzVar1;
  zcl_attr_desc_t *pzVar2;
  undefined3 in_register_0000202d;
  zcl_attr_desc_s **ppzVar3;
  
  ppzVar3 = (zcl_attr_desc_s **)CONCAT31(in_register_0000202d,mode);
  pzVar1 = color_control_srv_get_attr_desc(ep_id,0xeff0);
  pzVar2 = color_control_srv_get_attr_desc(ep_id,0x4001);
  if ((pzVar1 == (zcl_attr_desc_t *)0x0) || (pzVar2 == (zcl_attr_desc_t *)0x0)) {
    __assert_func("//build/esp-zigbee/src/core/api/zcl/cluster/color_control.c",0x18e,
                  "stop_cvc_color","cvc_ctx_attr_desc && color_mode_attr_desc");
  }
  else {
                    /* WARNING: Load size is inaccurate */
    if (((zcl_attr_desc_s **)(uint)*pzVar2->data_p != ppzVar3) &&
       (ppzVar3 != (zcl_attr_desc_s **)0xff)) {
      return;
    }
    pzVar1 = (zcl_attr_desc_t *)pzVar1->data_p;
    ppzVar3 = &pzVar1[3].next;
    if ((uint)(byte)pzVar1->id != CONCAT31(in_register_00002029,ep_id)) goto _L0;
  }
  zcl_cvc_stop(pzVar1);
_L0:
  if ((uint)*(byte *)&pzVar1[3].next == CONCAT31(in_register_00002029,ep_id)) {
    zcl_cvc_stop(ppzVar3);
  }
  color_control_set_remaining_time(ep_id,0);
  return;
}

