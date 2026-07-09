/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_reporting.o -> zcl_report_attr_now
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zcl_report_attr_now(int param_1)

{
  int iVar1;
  undefined4 local_30;
  undefined4 uStack_2c;
  int iStack_28;
  undefined2 uStack_24;
  short sStack_22;
  uint uStack_20;
  code *pcStack_1c;
  undefined4 uStack_18;
  uint uStack_14;
  
  if (param_1 != 0) {
    local_30 = 0;
    uStack_2c = 0;
    uStack_18 = 0;
    iStack_28 = (uint)*(byte *)(param_1 + 1) << 0x18;
    _uStack_24 = CONCAT22(*(short *)(param_1 + 0x30),*(undefined2 *)(param_1 + 4));
    uStack_20 = (uint)(byte)(*(short *)(param_1 + 0x30) != 0 |
                            (*(char *)(param_1 + 8) == '\x01') << 1);
    pcStack_1c = zcl_reporting_packet_confirm_handler;
    uStack_14 = (uint)*(ushort *)(param_1 + 6);
    iVar1 = zdo_dev_joined();
    if ((iVar1 == 0) || (iVar1 = zcl_report_attr_cmd_req(&local_30), iVar1 != 0)) {
      *(byte *)(param_1 + 9) = *(byte *)(param_1 + 9) & 0xf0 | 1;
      process_attr_report(param_1);
    }
  }
  return;
}

