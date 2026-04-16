/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> wind_speed_measurement_desc.o -> ezb_zcl_wind_speed_measurement_cluster_desc_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t ezb_zcl_wind_speed_measurement_cluster_desc_add_attr
                    (ezb_zcl_cluster_desc_t cluster_desc,uint16_t attr_id,void *value)

{
  undefined2 in_register_0000202e;
  int iVar1;
  uint uVar2;
  uint uVar3;
  ezb_err_t eVar4;
  
  iVar1 = CONCAT22(in_register_0000202e,attr_id);
  if (cluster_desc == (ezb_zcl_cluster_desc_t)0x0) {
    eVar4 = 2;
  }
  else {
                    /* WARNING: Load size is inaccurate */
    eVar4 = 2;
    if (*cluster_desc == 0x40b) {
      uVar3 = (uint)*(byte *)((int)cluster_desc + 2);
      uVar2 = 1;
      if (1 < (uVar3 - 1 & 0xffff)) {
        uVar3 = 0;
        uVar2 = 0;
        iVar1 = __assert_func(0,0,value);
      }
      eVar4 = 6;
      if ((uVar3 == uVar2) && ((iVar1 == 0 || ((iVar1 - 1U & 0xffff) < 3)))) {
        eVar4 = ezb_zcl_cluster_desc_add_manuf_attr(0x21,0);
        return eVar4;
      }
    }
  }
  return eVar4;
}

