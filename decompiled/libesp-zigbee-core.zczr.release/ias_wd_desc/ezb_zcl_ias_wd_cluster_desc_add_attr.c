/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> ias_wd_desc.o -> ezb_zcl_ias_wd_cluster_desc_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t ezb_zcl_ias_wd_cluster_desc_add_attr
                    (ezb_zcl_cluster_desc_t cluster_desc,uint16_t attr_id,void *value)

{
  undefined2 in_register_0000202e;
  int iVar1;
  uint uVar2;
  ezb_err_t eVar3;
  uint uVar4;
  
  iVar1 = CONCAT22(in_register_0000202e,attr_id);
  if (cluster_desc == (ezb_zcl_cluster_desc_t)0x0) {
    eVar3 = 2;
  }
  else {
                    /* WARNING: Load size is inaccurate */
    eVar3 = 2;
    if (*cluster_desc == 0x502) {
      uVar4 = (uint)*(byte *)((int)cluster_desc + 2);
      uVar2 = 1;
      if (1 < (uVar4 - 1 & 0xffff)) {
        uVar2 = 0;
        iVar1 = __assert_func(0,0,0,value);
      }
      eVar3 = 6;
      if ((uVar4 == uVar2) && (iVar1 == 0)) {
        eVar3 = ezb_zcl_cluster_desc_add_manuf_attr(0x21,3,0);
        return eVar3;
      }
    }
  }
  return eVar3;
}

