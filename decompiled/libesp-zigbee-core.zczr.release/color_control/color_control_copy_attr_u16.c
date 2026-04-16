/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> color_control.o -> color_control_copy_attr_u16
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void color_control_copy_attr_u16(uint8_t ep_id,uint16_t dst_attr_id,uint16_t src_attr_id)

{
  zcl_attr_desc_t *pzVar1;
  zcl_attr_desc_t *pzVar2;
  
  pzVar1 = color_control_srv_get_attr_desc(ep_id,src_attr_id);
  pzVar2 = color_control_srv_get_attr_desc(ep_id,dst_attr_id);
  if ((pzVar1 != (zcl_attr_desc_t *)0x0) && (pzVar2 != (zcl_attr_desc_t *)0x0)) {
                    /* WARNING: Load size is inaccurate */
    *(undefined2 *)pzVar2->data_p = *pzVar1->data_p;
  }
  return;
}

