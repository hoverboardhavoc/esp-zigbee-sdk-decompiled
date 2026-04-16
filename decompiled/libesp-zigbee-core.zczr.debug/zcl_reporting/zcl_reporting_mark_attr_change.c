/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_reporting.o -> zcl_reporting_mark_attr_change
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t zcl_reporting_mark_attr_change
                    (uint8_t ep_id,uint16_t cluster_id,uint8_t role,uint16_t attr_id,
                    uint16_t manuf_code)

{
  _Bool _Var1;
  zcl_reporting_info_t *info;
  undefined3 extraout_var;
  byte bVar2;
  
  info = zcl_reporting_info_find(ep_id,cluster_id,role,attr_id,manuf_code);
  if ((info != (zcl_reporting_info_t *)0x0) &&
     (_Var1 = check_attr_delta(info), CONCAT31(extraout_var,_Var1) != 0)) {
    bVar2 = info->field_0x9 & 0xf;
    info->field_0x9 = (byte)((*(uint *)&info->cluster_role >> 0xc & 0xf | 2) << 4) | bVar2;
    if ((bVar2 == 0) || (bVar2 == 3)) {
      info->field_0x9 = info->field_0x9 & 0xf0 | 3;
      process_attr_report(info);
    }
  }
  return 0;
}

