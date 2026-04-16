/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> color_control.o -> color_control_cluster_srv_check_value_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t
color_control_cluster_srv_check_value_handler(uint16_t attr_id,uint8_t ep_id,void *value)

{
  bool bVar1;
  undefined2 in_register_0000202a;
  uint uVar2;
  ushort uStack_14;
  ushort uStack_12;
  uint16_t min_color_temperature;
  uint16_t max_color_temperature;
  
  uVar2 = CONCAT22(in_register_0000202a,attr_id);
  if (uVar2 < 5) {
    if (uVar2 < 3) {
      bVar1 = false;
      if (uVar2 != 2) {
                    /* WARNING: Load size is inaccurate */
        bVar1 = *value == -1;
      }
    }
    else {
                    /* WARNING: Load size is inaccurate */
      bVar1 = 0xfeff < *value;
    }
  }
  else {
    if (uVar2 == 8) {
                    /* WARNING: Load size is inaccurate */
      bVar1 = *value < 3;
    }
    else {
      if (uVar2 != 0x400a) {
        if (uVar2 != 7) {
          return '\0';
        }
        color_control_get_color_temperature_range(ep_id,&uStack_14,&uStack_12);
                    /* WARNING: Load size is inaccurate */
        if (*value < uStack_14) {
          return '\x01';
        }
        return uStack_12 < *value;
      }
                    /* WARNING: Load size is inaccurate */
      bVar1 = *value < 0x20;
    }
    bVar1 = (bool)(bVar1 ^ 1);
  }
  return bVar1;
}

