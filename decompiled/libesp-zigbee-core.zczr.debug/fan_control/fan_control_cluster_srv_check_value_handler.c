/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.debug -> fan_control.o -> fan_control_cluster_srv_check_value_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t
fan_control_cluster_srv_check_value_handler(uint16_t attr_id,uint8_t endpoint,void *value)

{
  undefined2 in_register_0000202a;
  
  if (CONCAT22(in_register_0000202a,attr_id) == 0) {
                    /* WARNING: Load size is inaccurate */
    if (*value < 7) {
      return '\0';
    }
    return 0x87;
  }
  if (CONCAT22(in_register_0000202a,attr_id) != 1) {
    return '\0';
  }
                    /* WARNING: Load size is inaccurate */
  if (*value < 5) {
    return '\0';
  }
  return 0x87;
}

