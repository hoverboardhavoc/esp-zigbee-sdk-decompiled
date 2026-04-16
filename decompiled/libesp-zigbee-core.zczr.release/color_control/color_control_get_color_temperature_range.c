/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> color_control.o -> color_control_get_color_temperature_range
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool color_control_get_color_temperature_range(uint8_t ep_id,uint16_t *min,uint16_t *max)

{
  zcl_attr_desc_t *pzVar1;
  zcl_attr_desc_t *pzVar2;
  uint16_t uVar3;
  
  pzVar1 = color_control_srv_get_attr_desc(ep_id,0x400b);
  pzVar2 = color_control_srv_get_attr_desc(ep_id,0x400c);
  uVar3 = 0;
  if (pzVar1 != (zcl_attr_desc_t *)0x0) {
                    /* WARNING: Load size is inaccurate */
    uVar3 = *pzVar1->data_p;
  }
  *min = uVar3;
  uVar3 = 0xfeff;
  if (pzVar2 != (zcl_attr_desc_t *)0x0) {
                    /* WARNING: Load size is inaccurate */
    uVar3 = *pzVar2->data_p;
  }
  *max = uVar3;
  return true;
}

