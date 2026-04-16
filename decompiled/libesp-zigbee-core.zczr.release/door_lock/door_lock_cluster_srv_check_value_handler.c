/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> door_lock.o -> door_lock_cluster_srv_check_value_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t
door_lock_cluster_srv_check_value_handler(uint16_t attr_id,uint8_t endpoint,void *value)

{
  bool bVar1;
  ezb_zcl_status_t eVar2;
  undefined2 in_register_0000202a;
  uint uVar3;
  
  uVar3 = CONCAT22(in_register_0000202a,attr_id);
  if (uVar3 == 2) {
                    /* WARNING: Load size is inaccurate */
    bVar1 = 1 < *value;
_L19:
    return -bVar1 & 0x87;
  }
  if (uVar3 < 3) {
                    /* WARNING: Load size is inaccurate */
    if (uVar3 != 0) {
      bVar1 = 10 < *value;
      goto _L19;
    }
    if ((byte)(*value - 3) < 0xfc) {
      return 0x87;
    }
  }
  else if (uVar3 == 0x34) {
    eVar2 = zdo_dev_joined();
    return eVar2;
  }
  return '\0';
}

