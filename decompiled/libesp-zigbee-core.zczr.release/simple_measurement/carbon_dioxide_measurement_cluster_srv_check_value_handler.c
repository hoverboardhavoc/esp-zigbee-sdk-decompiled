/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> simple_measurement.o -> carbon_dioxide_measurement_cluster_srv_check_value_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t
carbon_dioxide_measurement_cluster_srv_check_value_handler
          (uint16_t attr_id,uint8_t endpoint,void *value)

{
  bool bVar1;
  zcl_attr_desc_t *pzVar2;
  int iVar3;
  undefined2 in_register_0000202a;
  uint uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 auStack_24 [3];
  
  uVar4 = CONCAT22(in_register_0000202a,attr_id);
  if (3 < uVar4) {
    return '\0';
  }
                    /* WARNING: Load size is inaccurate */
  uVar5 = *value;
  uVar6 = 0;
  if ((uVar4 & 0xfffffffd) != 0) goto _L0;
  pzVar2 = simple_measurement_srv_get_attr_desc(endpoint,0x40d,1);
  if (pzVar2 != (zcl_attr_desc_t *)0x0) goto _L0;
  while( true ) {
    do {
      pzVar2 = (zcl_attr_desc_t *)__assert_func(0,0,0,0);
_L0:
    } while (pzVar2->data_p == (void *)0x0);
    memcpy(auStack_24,pzVar2->data_p,4);
    uVar6 = auStack_24[0];
_L0:
    if (1 < uVar4) break;
    pzVar2 = simple_measurement_srv_get_attr_desc(endpoint,0x40d,2);
    if ((pzVar2 != (zcl_attr_desc_t *)0x0) && (pzVar2->data_p != (void *)0x0)) {
      memcpy(auStack_24,pzVar2->data_p,4);
_L0:
      iVar3 = __lesf2(uVar6,uVar5);
      if (iVar3 < 1) {
        iVar3 = __gesf2(auStack_24[0],uVar5);
        bVar1 = iVar3 < 0;
      }
      else {
        bVar1 = true;
      }
      return bVar1;
    }
  }
  auStack_24[0] = 0x3f800000;
  goto _L0;
}

