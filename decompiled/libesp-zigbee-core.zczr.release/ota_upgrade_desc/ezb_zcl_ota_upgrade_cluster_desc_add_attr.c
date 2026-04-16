/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> ota_upgrade_desc.o -> ezb_zcl_ota_upgrade_cluster_desc_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t ezb_zcl_ota_upgrade_cluster_desc_add_attr
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
  if (*cluster_desc != 0x19) {
    return 2;
  }
  uVar3 = (uint)*(byte *)((int)cluster_desc + 2);
  uVar5 = 1;
  if (1 < (uVar3 - 1 & 0xffff)) {
    uVar5 = 0;
    uVar3 = 0;
    uVar2 = __assert_func(0,0,value);
  }
  if (uVar3 == uVar5) {
    if (uVar2 == 0xeff0) {
      uVar4 = 0x20;
      goto _L0;
    }
    uVar3 = 0xeff1;
  }
  else {
    if (uVar2 < 0xd) {
      if (uVar2 == 0) {
        uVar4 = 0xf0;
      }
      else {
        uVar5 = uVar5 << (uVar2 & 0x1f);
        if ((uVar5 & 0x3a8) == 0) {
          if ((uVar5 & 0x416) == 0) {
            if ((uVar5 >> 6 & 0x61) == 0) {
              return 6;
            }
            uVar4 = 0x30;
          }
          else {
            uVar4 = 0x23;
          }
        }
        else {
          uVar4 = 0x21;
        }
      }
      goto _L0;
    }
    uVar3 = 0xeff0;
  }
  if (uVar2 != uVar3) {
    return 6;
  }
  uVar4 = 0;
_L0:
  eVar1 = ezb_zcl_cluster_desc_add_manuf_attr(uVar4,0);
  return eVar1;
}

