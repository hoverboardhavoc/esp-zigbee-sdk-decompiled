/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zcl_reporting.o -> zcl_report_attr_now
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zcl_report_attr_now(int param_1)

{
  int iVar1;
  undefined1 auStack_30 [11];
  undefined1 uStack_25;
  undefined2 uStack_24;
  short sStack_22;
  byte bStack_20;
  code *pcStack_1c;
  undefined2 uStack_14;
  
  if (param_1 == 0) {
    return;
  }
  memset(auStack_30,0,0x20);
  uStack_25 = *(undefined1 *)(param_1 + 1);
  sStack_22 = *(short *)(param_1 + 0x30);
  uStack_24 = *(undefined2 *)(param_1 + 4);
  bStack_20 = sStack_22 != 0 | (*(char *)(param_1 + 8) == '\x01') << 1;
  pcStack_1c = zcl_reporting_packet_confirm_handler;
  uStack_14 = *(undefined2 *)(param_1 + 6);
  iVar1 = zdo_dev_joined();
  if ((iVar1 == 0) || (iVar1 = zcl_report_attr_cmd_req(auStack_30), iVar1 != 0)) {
    *(byte *)(param_1 + 9) = *(byte *)(param_1 + 9) & 0xf0 | 1;
    process_attr_report(param_1);
  }
  return;
}

