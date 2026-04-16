/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> scenes_desc.o -> ezb_zcl_scenes_cluster_desc_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t ezb_zcl_scenes_cluster_desc_add_attr
                    (ezb_zcl_cluster_desc_t cluster_desc,uint16_t attr_id,void *value)

{
  undefined2 in_register_0000202e;
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  ezb_err_t eVar5;
  uint uVar6;
  
  uVar1 = CONCAT22(in_register_0000202e,attr_id);
  if (cluster_desc == (ezb_zcl_cluster_desc_t)0x0) {
    eVar5 = 2;
  }
  else {
                    /* WARNING: Load size is inaccurate */
    uVar6 = (uint)*cluster_desc;
    eVar5 = 2;
    if (uVar6 == 5) {
      uVar4 = (uint)*(byte *)((int)cluster_desc + 2);
      uVar2 = 1;
      if (1 < (uVar4 - 1 & 0xffff)) {
        uVar4 = 0;
        uVar2 = 0;
        uVar1 = __assert_func(0,0,value);
      }
      eVar5 = 6;
      if (uVar4 == uVar2) {
        if (uVar1 == 4) {
          uVar3 = 0x18;
        }
        else {
          if (uVar1 < 5) {
            uVar3 = 0x21;
            if ((uVar1 == 2) || (uVar3 = 0x10, uVar1 == 3)) goto _L0;
          }
          else if (uVar1 != 0xeff0) {
            if (uVar1 == 0xeff1) {
              uVar3 = 0;
            }
            else {
              uVar3 = 0xf0;
              if (uVar1 != uVar6) {
                return 6;
              }
            }
            goto _L0;
          }
          uVar3 = 0x20;
        }
_L0:
        eVar5 = ezb_zcl_cluster_desc_add_manuf_attr(uVar3,0);
        return eVar5;
      }
    }
  }
  return eVar5;
}

