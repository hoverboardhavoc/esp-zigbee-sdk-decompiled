/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_reporting.o -> zcl_reporting_mark_recv_attr_report
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zcl_reporting_mark_recv_attr_report(void)

{
  char *pcVar1;
  
  pcVar1 = (char *)zcl_reporting_info_find();
  if (((pcVar1 != (char *)0x0) && (*pcVar1 == '\x01')) && (*(short *)(pcVar1 + 0x10) != 0)) {
    process_attr_report();
  }
  return;
}

