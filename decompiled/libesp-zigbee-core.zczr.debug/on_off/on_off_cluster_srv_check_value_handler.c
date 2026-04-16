/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> on_off.o -> on_off_cluster_srv_check_value_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t
on_off_cluster_srv_check_value_handler(uint16_t attr_id,uint8_t endpoint,void *value)

{
  undefined2 in_register_0000202a;
  int iVar1;
  
  iVar1 = CONCAT22(in_register_0000202a,attr_id);
  if (iVar1 != 0x4000) {
    if (iVar1 == 0x4003) {
                    /* WARNING: Load size is inaccurate */
      if (0xfb < (byte)(*value - 3U)) {
        return '\0';
      }
      return 0x87;
    }
    if (iVar1 != 0) {
      return '\0';
    }
  }
                    /* WARNING: Load size is inaccurate */
  if (*value < 2) {
    return '\0';
  }
  return 0x87;
}

