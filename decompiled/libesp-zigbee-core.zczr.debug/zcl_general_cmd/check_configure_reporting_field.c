/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_general_cmd.o -> check_configure_reporting_field
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined1 check_configure_reporting_field(char *param_1,int param_2)

{
  uint uVar1;
  
  if (param_1 == (char *)0x0) {
    return 1;
  }
  if (*param_1 == '\0') {
    if (param_2 == 0) {
      return 0x86;
    }
    if (*(int *)(param_2 + 8) == 0) {
      return 0x86;
    }
    uVar1 = *(byte *)(param_2 + 2) - 0x48;
    if (((uVar1 & 0xff) < 10) && ((0x317U >> (uVar1 & 0x1f) & 1) != 0)) {
      return 0x8c;
    }
    if ((*(byte *)(param_2 + 3) & 4) == 0) {
      return 0x8c;
    }
    if ((uint)*(byte *)(param_2 + 2) != (uint)(byte)param_1[4]) {
      return 0x8d;
    }
    if ((*(ushort *)(param_1 + 8) != 0) && (*(ushort *)(param_1 + 8) < *(ushort *)(param_1 + 6))) {
      return 0x87;
    }
  }
  else if (param_2 == 0) {
    return 0x8c;
  }
  return 0;
}

