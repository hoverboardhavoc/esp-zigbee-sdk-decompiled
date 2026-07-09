/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zcl_reporting.o -> zcl_reporting_remove_stored_reporting_info
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zcl_reporting_remove_stored_reporting_info(int param_1)

{
  undefined1 uStack_30;
  char cStack_2f;
  short sStack_2c;
  char cStack_2a;
  byte bStack_29;
  uint uStack_28;
  short sStack_14;
  char cStack_12;
  
  sStack_14 = 0;
  cStack_12 = '\0';
  while( true ) {
    ds_zcl_reporting_info_itor_read(&uStack_30);
    if (cStack_12 != '\0') {
      return;
    }
    if ((((cStack_2f == *(char *)(param_1 + 1)) && (sStack_2c == *(short *)(param_1 + 4))) &&
        (cStack_2a == *(char *)(param_1 + 8))) &&
       (((uint)*(ushort *)(param_1 + 6) == ((uStack_28 & 0xff) << 8 | (uint)bStack_29) &&
        ((uint)*(ushort *)(param_1 + 0x30) == (uStack_28 >> 8 & 0xffff))))) break;
    sStack_14 = sStack_14 + 1;
  }
  ds_internal_remove_entry(10,&uStack_30);
  return;
}

