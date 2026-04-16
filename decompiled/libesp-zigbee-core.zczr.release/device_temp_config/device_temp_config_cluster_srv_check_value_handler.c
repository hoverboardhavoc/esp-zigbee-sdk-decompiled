/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> device_temp_config.o -> device_temp_config_cluster_srv_check_value_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t
device_temp_config_cluster_srv_check_value_handler(uint16_t attr_id,uint8_t endpoint,void *value)

{
  ezb_zcl_status_t eVar1;
  undefined2 in_register_0000202a;
  uint uVar2;
  
  uVar2 = CONCAT22(in_register_0000202a,attr_id);
  if (uVar2 == 0x10) {
                    /* WARNING: Load size is inaccurate */
    return -(2 < *value) & 0x87;
  }
  if (uVar2 < 0x11) {
    if ((uVar2 == 1) || ((uVar2 == 2 || (uVar2 == 0)))) {
_L0:
                    /* WARNING: Load size is inaccurate */
      eVar1 = '\0';
      if ((*value != -0x8000) && (400 < ((int)*value + 200U & 0xffff))) {
        eVar1 = 0x87;
      }
      return eVar1;
    }
  }
  else if ((uVar2 == 0x11) || (uVar2 == 0x12)) goto _L0;
  return '\0';
}

