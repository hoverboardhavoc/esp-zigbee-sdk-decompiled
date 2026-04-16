/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> door_lock_desc.o -> ezb_zcl_door_lock_cluster_desc_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t ezb_zcl_door_lock_cluster_desc_add_attr
                    (ezb_zcl_cluster_desc_t cluster_desc,uint16_t attr_id,void *value)

{
  ezb_err_t eVar1;
  undefined2 in_register_0000202e;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  
  uVar2 = CONCAT22(in_register_0000202e,attr_id);
  if (cluster_desc == (ezb_zcl_cluster_desc_t)0x0) {
    return 2;
  }
                    /* WARNING: Load size is inaccurate */
  if (*cluster_desc != 0x101) {
    return 2;
  }
  uVar5 = (uint)*(byte *)((int)cluster_desc + 2);
  uVar3 = 1;
  if (1 < (uVar5 - 1 & 0xffff)) {
    uVar5 = 0;
    uVar3 = 0;
    uVar2 = __assert_func(0,0,value);
  }
  if (uVar5 != uVar3) {
    return 6;
  }
  uVar4 = 0x21;
  if (uVar2 == 0x21) {
    uVar4 = 0x42;
    goto _L0;
  }
  if (uVar2 < 0x22) {
    if (uVar2 < 6) {
      if (3 < uVar2) {
_L0:
        uVar4 = 0x23;
        goto _L0;
      }
      if (uVar2 != 2) goto _L0;
    }
    else {
      if (uVar2 < 0x14) {
        if ((uVar2 < 0x10) && (uVar2 != 6)) {
          return 6;
        }
        goto _L0;
      }
      uVar4 = 0x20;
      if (uVar2 < 0x1b) goto _L0;
      if (uVar2 != 0x20) {
        return 6;
      }
    }
    goto _L0;
  }
  if (uVar2 != 0x26) {
    if (uVar2 < 0x27) {
      if (uVar2 != 0x24) {
        if (uVar2 == 0x25) goto _L0;
        if (uVar2 != 0x22) goto _L0;
      }
_L0:
      uVar4 = 0x20;
      goto _L0;
    }
    if (uVar2 < 0x34) {
      if (uVar2 < 0x32) {
        if (uVar2 == 0x27) goto _L0;
        if (0x2b < uVar2) {
          if (1 < (uVar2 - 0x30 & 0xffff)) {
            return 6;
          }
          goto _L0;
        }
      }
_L0:
      uVar4 = 0x10;
      goto _L0;
    }
    if (uVar2 == 0x34) {
_L0:
      uVar4 = 0x30;
      goto _L0;
    }
    if (7 < (uVar2 - 0x40 & 0xffff)) {
      return 6;
    }
  }
_L0:
  uVar4 = 0x19;
_L0:
  eVar1 = ezb_zcl_cluster_desc_add_manuf_attr(uVar4,0);
  return eVar1;
}

