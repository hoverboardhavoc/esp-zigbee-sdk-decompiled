/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> on_off_desc.o -> ezb_zcl_on_off_cluster_desc_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t ezb_zcl_on_off_cluster_desc_add_attr
                    (ezb_zcl_cluster_desc_t cluster_desc,uint16_t attr_id,void *value)

{
  ezb_err_t eVar1;
  undefined2 in_register_0000202e;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  uVar2 = CONCAT22(in_register_0000202e,attr_id);
  if (cluster_desc == (ezb_zcl_cluster_desc_t)0x0) {
    uVar6 = 2;
  }
  else {
                    /* WARNING: Load size is inaccurate */
    uVar7 = (uint)*cluster_desc;
    uVar6 = 2;
    if (uVar7 == 6) {
      uVar5 = (uint)*(byte *)((int)cluster_desc + 2);
      uVar3 = 1;
      uVar6 = uVar7;
      if (1 < (uVar5 - 1 & 0xffff)) {
        uVar5 = 0;
        uVar3 = 0;
        uVar2 = __assert_func(0,0,value);
        uVar6 = uVar7;
      }
      if (uVar5 == uVar3) {
        if (uVar2 < 0x4003) {
          if (uVar2 < 0x4001) {
            if ((uVar2 != 0) && (uVar2 != 0x4000)) {
              return uVar6;
            }
            uVar4 = 0x10;
          }
          else {
            uVar4 = 0x21;
          }
        }
        else if (uVar2 == 0x4003) {
          uVar4 = 0x30;
        }
        else {
          if (uVar2 != 0xeff0) {
            return uVar6;
          }
          uVar4 = 0;
        }
        eVar1 = ezb_zcl_cluster_desc_add_manuf_attr(uVar4,0);
        return eVar1;
      }
    }
  }
  return uVar6;
}

