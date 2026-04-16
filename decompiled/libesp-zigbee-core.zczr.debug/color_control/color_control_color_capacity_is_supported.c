/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> color_control.o -> color_control_color_capacity_is_supported
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool color_control_color_capacity_is_supported(uint8_t ep_id,uint8_t cmd_id)

{
  ushort uVar1;
  zcl_attr_desc_t *pzVar2;
  undefined3 in_register_0000202d;
  uint uVar3;
  
  uVar3 = CONCAT31(in_register_0000202d,cmd_id);
  pzVar2 = color_control_srv_get_attr_desc(ep_id,0x400a);
  if (pzVar2 == (zcl_attr_desc_t *)0x0) {
    return false;
  }
                    /* WARNING: Load size is inaccurate */
  uVar1 = *pzVar2->data_p;
  if (uVar3 < 0x44) {
    if (0x3f < uVar3) {
      return (_Bool)((byte)(uVar1 >> 1) & 1);
    }
    if (uVar3 < 10) {
      if (6 < uVar3) {
        return (_Bool)((byte)(uVar1 >> 3) & 1);
      }
      if (uVar3 < 7) {
        return (_Bool)((byte)uVar1 & 1);
      }
      return false;
    }
    if (uVar3 != 10) {
      return false;
    }
  }
  else {
    if (uVar3 == 0x47) {
      return true;
    }
    if (uVar3 < 0x48) {
      if (uVar3 == 0x44) {
        return (_Bool)((byte)(uVar1 >> 2) & 1);
      }
      return false;
    }
    if (1 < (uVar3 - 0x4b & 0xff)) {
      return false;
    }
  }
  return (_Bool)((byte)(uVar1 >> 4) & 1);
}

