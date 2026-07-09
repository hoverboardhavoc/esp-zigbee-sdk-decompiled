/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_reporting.o -> zcl_reporting_mark_attr_change
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_reporting_mark_attr_change(void)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  byte bVar4;
  
  iVar2 = zcl_reporting_info_find();
  if ((iVar2 != 0) && (iVar3 = check_attr_delta(), iVar3 != 0)) {
    bVar1 = *(byte *)(iVar2 + 9);
    bVar4 = bVar1 & 0xf;
    *(byte *)(iVar2 + 9) = (byte)((*(uint *)(iVar2 + 8) >> 0xc & 0xf | 2) << 4) | bVar4;
    if (((bVar1 & 0xf) == 0) || (bVar4 == 3)) {
      *(byte *)(iVar2 + 9) = *(byte *)(iVar2 + 9) & 0xf0 | 3;
      process_attr_report(iVar2);
    }
  }
  return 0;
}

