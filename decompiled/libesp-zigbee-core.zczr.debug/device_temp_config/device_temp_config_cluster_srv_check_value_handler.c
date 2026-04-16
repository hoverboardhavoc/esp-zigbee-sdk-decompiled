/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> device_temp_config.o -> device_temp_config_cluster_srv_check_value_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t
device_temp_config_cluster_srv_check_value_handler(uint16_t attr_id,uint8_t endpoint,void *value)

{
  undefined2 in_register_0000202a;
  uint uVar1;
  
  uVar1 = CONCAT22(in_register_0000202a,attr_id);
  if (uVar1 == 0x10) {
                    /* WARNING: Load size is inaccurate */
    if (*value < 3) {
      return '\0';
    }
    return 0x87;
  }
  if (0x10 < uVar1) {
    if (uVar1 == 0x11) {
                    /* WARNING: Load size is inaccurate */
      if (*value == -0x8000) {
        return '\0';
      }
      if (((int)*value + 200U & 0xffff) < 0x191) {
        return '\0';
      }
      return 0x87;
    }
    if (uVar1 != 0x12) {
      return '\0';
    }
                    /* WARNING: Load size is inaccurate */
    if (*value != -0x8000) {
      if (((int)*value + 200U & 0xffff) < 0x191) {
        return '\0';
      }
      return 0x87;
    }
    return '\0';
  }
  if (uVar1 == 1) {
                    /* WARNING: Load size is inaccurate */
    if (*value == -0x8000) {
      return '\0';
    }
    if (((int)*value + 200U & 0xffff) < 0x191) {
      return '\0';
    }
    return 0x87;
  }
  if (uVar1 != 2) {
    if (uVar1 != 0) {
      return '\0';
    }
                    /* WARNING: Load size is inaccurate */
    if (*value != -0x8000) {
      if (((int)*value + 200U & 0xffff) < 0x191) {
        return '\0';
      }
      return 0x87;
    }
    return '\0';
  }
                    /* WARNING: Load size is inaccurate */
  if (*value == -0x8000) {
    return '\0';
  }
  if (((int)*value + 200U & 0xffff) < 0x191) {
    return '\0';
  }
  return 0x87;
}

