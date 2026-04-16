/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> occupancy_sensing.o -> occupancy_sensing_cluster_srv_check_value_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t
occupancy_sensing_cluster_srv_check_value_handler(uint16_t attr_id,uint8_t endpoint,void *value)

{
  undefined2 in_register_0000202a;
  uint uVar1;
  
  uVar1 = CONCAT22(in_register_0000202a,attr_id);
  if (uVar1 != 0x22) {
    if (0x22 < uVar1) {
      if (uVar1 < 0x32) {
        if (0x2f < uVar1) goto _L0;
      }
      else if (uVar1 == 0x32) goto _L0;
      return '\0';
    }
    if (uVar1 != 0x12) {
      if (uVar1 < 0x13) {
        if (1 < (uVar1 - 0x10 & 0xffff)) {
          return '\0';
        }
      }
      else if (1 < (uVar1 - 0x20 & 0xffff)) {
        return '\0';
      }
_L0:
                    /* WARNING: Load size is inaccurate */
      return *value == -1;
    }
  }
_L0:
                    /* WARNING: Load size is inaccurate */
  return 0xfd < (byte)(*value - 1U);
}

