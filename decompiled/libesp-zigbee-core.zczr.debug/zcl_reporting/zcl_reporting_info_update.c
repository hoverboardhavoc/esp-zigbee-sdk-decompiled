/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_reporting.o -> zcl_reporting_info_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t zcl_reporting_info_update(zcl_reporting_info_t *info)

{
  zcl_reporting_info_t *info_00;
  ezb_err_t eVar1;
  byte bVar2;
  
  info_00 = zcl_reporting_info_find
                      (info->ep_id,info->cluster_id,info->cluster_role,info->attr_id,
                       info->manuf_code);
  if (info_00 == (zcl_reporting_info_t *)0x0) {
    eVar1 = 5;
  }
  else {
    if (info_00->direction == '\0') {
      memcpy(info_00,info,0x34);
      if (*(int *)&info->u == 0xffff) {
        (info_00->u).send_info.min_interval = (info_00->u).send_info.def_min_interval;
        (info_00->u).send_info.max_interval = (info_00->u).send_info.def_max_interval;
        *(undefined1 *)((int)&info_00->u + 8) = 0;
        *(undefined1 *)((int)&info_00->u + 9) = 0;
        *(undefined1 *)((int)&info_00->u + 10) = 0;
        *(undefined1 *)((int)&info_00->u + 0xb) = 0;
        *(undefined1 *)((int)&info_00->u + 0xc) = 0;
        *(undefined1 *)((int)&info_00->u + 0xd) = 0;
        *(undefined1 *)((int)&info_00->u + 0xe) = 0;
        *(undefined1 *)((int)&info_00->u + 0xf) = 0;
      }
      bVar2 = info_00->field_0x9 & 0xf;
      info_00->field_0x9 = (byte)((*(uint *)&info_00->cluster_role >> 0xc & 0xf | 4) << 4) | bVar2;
      if (bVar2 != 4) {
        info_00->field_0x9 = info_00->field_0x9 & 0xf0 | 3;
      }
      process_attr_report(info_00);
    }
    else {
      (info_00->u).send_info.min_interval = (info->u).send_info.min_interval;
      process_attr_report(info_00);
    }
    eVar1 = zcl_reporting_store_reporting_info(info_00);
  }
  return eVar1;
}

