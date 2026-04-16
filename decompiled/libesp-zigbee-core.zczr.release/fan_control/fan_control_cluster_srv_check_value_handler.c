/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> fan_control.o -> fan_control_cluster_srv_check_value_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t
fan_control_cluster_srv_check_value_handler(uint16_t attr_id,uint8_t endpoint,void *value)

{
  byte bVar1;
  undefined2 in_register_0000202a;
  byte bVar2;
  
  if (CONCAT22(in_register_0000202a,attr_id) == 0) {
                    /* WARNING: Load size is inaccurate */
    bVar1 = *value;
    bVar2 = 6;
  }
  else {
    if (CONCAT22(in_register_0000202a,attr_id) != 1) {
      return 0x86;
    }
                    /* WARNING: Load size is inaccurate */
    bVar1 = *value;
    bVar2 = 4;
  }
  return -(bVar2 < bVar1) & 0x87;
}

