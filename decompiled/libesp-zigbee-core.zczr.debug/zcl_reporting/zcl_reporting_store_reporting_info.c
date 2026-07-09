/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_reporting.o -> zcl_reporting_store_reporting_info
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zcl_reporting_store_reporting_info(char *param_1)

{
  undefined1 uVar1;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined2 uStack_14;
  char cStack_12;
  
  uStack_2c = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  uStack_20 = 0;
  uStack_1c = 0;
  uStack_18 = 0;
  uStack_14 = 0;
  cStack_12 = '\0';
  zcl_reporting_remove_stored_reporting_info();
  uStack_2c = *(undefined4 *)param_1;
  uStack_28 = CONCAT13((char)*(undefined2 *)(param_1 + 6),
                       CONCAT12(param_1[8],*(undefined2 *)(param_1 + 4)));
  if (*param_1 == '\0') {
    uVar1 = (undefined1)*(undefined2 *)(param_1 + 0x10);
    uStack_20 = CONCAT13((char)*(undefined2 *)(param_1 + 0x28),
                         CONCAT12((char)((ushort)*(undefined2 *)(param_1 + 0x12) >> 8),
                                  CONCAT11((char)*(undefined2 *)(param_1 + 0x12),
                                           (char)((ushort)*(undefined2 *)(param_1 + 0x10) >> 8))));
    uStack_18 = *(undefined4 *)(param_1 + 0x19);
    uStack_14 = *(undefined2 *)(param_1 + 0x1d);
    cStack_12 = param_1[0x1f];
    uStack_1c = CONCAT13(param_1[0x18],
                         CONCAT12((char)((ushort)*(undefined2 *)(param_1 + 0x2a) >> 8),
                                  CONCAT11((char)*(undefined2 *)(param_1 + 0x2a),
                                           (char)((ushort)*(undefined2 *)(param_1 + 0x28) >> 8))));
  }
  else {
    uVar1 = (undefined1)*(undefined2 *)(param_1 + 0x10);
    uStack_20 = CONCAT31(uStack_20._1_3_,(char)((ushort)*(undefined2 *)(param_1 + 0x10) >> 8));
  }
  uStack_24 = CONCAT13(uVar1,CONCAT12((char)((ushort)*(undefined2 *)(param_1 + 0x30) >> 8),
                                      CONCAT11((char)*(undefined2 *)(param_1 + 0x30),
                                               (char)((ushort)*(undefined2 *)(param_1 + 6) >> 8))));
  ds_internal_add_entry(10,&uStack_2c,0x1b);
  return;
}

