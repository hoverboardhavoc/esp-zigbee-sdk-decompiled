/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> color_control.o -> color_control_get_color_temperature_range
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool color_control_get_color_temperature_range(uint8_t ep_id,uint16_t *min,uint16_t *max)

{
  _Bool _Var1;
  zcl_attr_desc_t *pzVar2;
  zcl_attr_desc_t *pzVar3;
  uint16_t uVar4;
  
  if (min == (uint16_t *)0x0) {
    _Var1 = false;
  }
  else if (max == (uint16_t *)0x0) {
    _Var1 = false;
  }
  else {
    pzVar2 = color_control_srv_get_attr_desc(ep_id,0x400b);
    pzVar3 = color_control_srv_get_attr_desc(ep_id,0x400c);
    if (pzVar2 == (zcl_attr_desc_t *)0x0) {
      uVar4 = 0;
    }
    else {
                    /* WARNING: Load size is inaccurate */
      uVar4 = *pzVar2->data_p;
    }
    *min = uVar4;
    if (pzVar3 == (zcl_attr_desc_t *)0x0) {
      uVar4 = 0xfeff;
    }
    else {
                    /* WARNING: Load size is inaccurate */
      uVar4 = *pzVar3->data_p;
    }
    *max = uVar4;
    _Var1 = true;
  }
  return _Var1;
}

