/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> zcl_reporting.o -> zcl_reporting_operate_attr_report
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t zcl_reporting_operate_attr_report(_Bool is_start,zcl_reporting_info_t *info)

{
  undefined3 in_register_00002029;
  
  if (info != (zcl_reporting_info_t *)0x0) {
    zcl_reporting_stop();
    info->field_0x9 =
         info->field_0x9 & 0xf0 | (CONCAT31(in_register_00002029,is_start) == 0) * '\x04' + 1U;
    zcl_reporting_start();
    return 0;
  }
  return 2;
}

