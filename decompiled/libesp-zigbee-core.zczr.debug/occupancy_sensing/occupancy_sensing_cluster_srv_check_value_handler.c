/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> occupancy_sensing.o -> occupancy_sensing_cluster_srv_check_value_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t
occupancy_sensing_cluster_srv_check_value_handler(uint16_t attr_id,uint8_t endpoint,void *value)

{
  byte bVar1;
  undefined2 in_register_0000202a;
  uint uVar2;
  
  uVar2 = CONCAT22(in_register_0000202a,attr_id);
  if (uVar2 == 0x22) {
    bVar1 = 0xfe;
  }
  else if (uVar2 < 0x23) {
    if (uVar2 == 0x12) {
      bVar1 = 0xfe;
    }
    else if (uVar2 < 0x13) {
      if ((uVar2 - 0x10 & 0xffff) < 2) {
_L0:
                    /* WARNING: Load size is inaccurate */
        return *value == -1;
      }
      bVar1 = 0;
    }
    else {
      if ((uVar2 - 0x20 & 0xffff) < 2) goto _L0;
      bVar1 = 0;
    }
  }
  else if (uVar2 < 0x32) {
    if (0x2f < uVar2) goto _L0;
    bVar1 = 0;
  }
  else if (uVar2 == 0x32) {
    bVar1 = 0xfe;
  }
  else {
    bVar1 = 0;
  }
  if (bVar1 != 0) {
                    /* WARNING: Load size is inaccurate */
    if (*value == 0) {
      bVar1 = 1;
    }
    else if (bVar1 < *value) {
      bVar1 = 1;
    }
    else {
      bVar1 = 0;
    }
  }
  return bVar1;
}

