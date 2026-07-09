/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_intrp.o -> nwk_intrp_data_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_intrp_data_request(undefined4 *param_1)

{
  int iVar1;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined2 uStack_20;
  undefined2 uStack_1e;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  uint uStack_14;
  
  iVar1 = nwk_intrp_prepend_header(param_1[6]);
  if (iVar1 == 0) {
    uStack_2c = param_1[6];
    uStack_28 = *param_1;
    uStack_24 = param_1[1];
    uStack_1c = *(undefined4 *)((int)param_1 + 0xe);
    uStack_18 = *(undefined4 *)((int)param_1 + 0x12);
    _uStack_20 = CONCAT22(*(undefined2 *)(param_1 + 3),*(undefined2 *)(param_1 + 2));
    uStack_14 = (uint)*(ushort *)((int)param_1 + 10);
    nwk_mm_data_request(&uStack_2c);
  }
  return;
}

