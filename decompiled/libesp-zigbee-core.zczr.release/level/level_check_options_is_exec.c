/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> level.o -> level_check_options_is_exec
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool level_check_options_is_exec
                (uint8_t ep_id,uint8_t cmd_id,uint8_t options_mask,uint8_t options_override)

{
  byte bVar1;
  undefined3 in_register_00002029;
  zcl_attr_desc_t *pzVar2;
  int iVar3;
  undefined3 in_register_0000202d;
  
  pzVar2 = level_srv_get_attr_desc(ep_id,0xf);
  if (pzVar2 != (zcl_attr_desc_t *)0x0) {
                    /* WARNING: Load size is inaccurate */
    bVar1 = *pzVar2->data_p;
    if ((options_mask & 1) != 0) {
      if ((options_override & 1) == 0) {
        bVar1 = 0;
      }
      else {
        bVar1 = bVar1 | 1;
      }
    }
    if (((CONCAT31(in_register_0000202d,cmd_id) < 4) &&
        (iVar3 = ezb_zcl_get_cluster_desc(CONCAT31(in_register_00002029,ep_id),6,1), iVar3 != 0)) &&
       (iVar3 = ezb_zcl_get_attr_desc(CONCAT31(in_register_00002029,ep_id),6,1,0,0), iVar3 != 0)) {
      return (_Bool)(**(char **)(iVar3 + 8) != '\0' | bVar1 & 1);
    }
  }
  return true;
}

