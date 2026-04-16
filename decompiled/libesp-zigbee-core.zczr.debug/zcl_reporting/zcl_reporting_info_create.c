/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_reporting.o -> zcl_reporting_info_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zcl_reporting_info_t *
zcl_reporting_info_create
          (uint8_t ep_id,uint16_t profile_id,_Bool direction,uint16_t cluster_id,uint8_t role,
          uint16_t attr_id,uint16_t manuf_code)

{
  zcl_reporting_info_t *pzVar1;
  undefined3 in_register_00002031;
  
  pzVar1 = (zcl_reporting_info_t *)calloc(1,0x38);
  if (pzVar1 != (zcl_reporting_info_t *)0x0) {
    pzVar1->ep_id = ep_id;
    pzVar1->direction = direction;
    pzVar1->cluster_id = cluster_id;
    pzVar1->cluster_role = role;
    pzVar1->attr_id = attr_id;
    pzVar1->profile_id = profile_id;
    pzVar1->manuf_code = manuf_code;
    (pzVar1->next_fire).val = 0x7fffffff;
    pzVar1->field_0x9 = pzVar1->field_0x9 & 0xf;
    pzVar1->field_0x9 = 0;
    pzVar1->next = (zcl_reporting_info_s *)0x0;
    if (CONCAT31(in_register_00002031,direction) == 0) {
      (pzVar1->u).send_info.def_min_interval = 5;
      (pzVar1->u).send_info.def_max_interval = 0;
      (pzVar1->u).send_info.min_interval = 5;
      (pzVar1->u).send_info.max_interval = 0;
    }
    else {
      (pzVar1->u).send_info.min_interval = 0;
    }
  }
  return pzVar1;
}

