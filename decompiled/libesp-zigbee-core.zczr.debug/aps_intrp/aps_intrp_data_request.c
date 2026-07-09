/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_intrp.o -> aps_intrp_data_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_intrp_data_request(int param_1)

{
  int iVar1;
  undefined1 *puVar2;
  undefined1 auStack_2c [2];
  undefined1 uStack_2a;
  undefined1 uStack_29;
  undefined1 uStack_28;
  undefined1 uStack_27;
  undefined1 uStack_26;
  undefined1 uStack_25;
  undefined1 uStack_24;
  undefined1 uStack_23;
  undefined2 uStack_22;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined2 uStack_18;
  undefined4 uStack_14;
  
  iVar1 = aps_intrp_prepend_header(*(undefined4 *)(param_1 + 0x14),param_1);
  if (iVar1 == 0) {
    auStack_2c[0] = 3;
    puVar2 = (undefined1 *)nwk_get_extended_address();
    uStack_2a = *puVar2;
    uStack_29 = puVar2[1];
    uStack_28 = puVar2[2];
    uStack_27 = puVar2[3];
    uStack_26 = puVar2[4];
    uStack_25 = puVar2[5];
    uStack_24 = puVar2[6];
    uStack_23 = puVar2[7];
    uStack_22 = *(undefined2 *)(param_1 + 2);
    uStack_20 = *(undefined4 *)(param_1 + 4);
    uStack_1c = *(undefined4 *)(param_1 + 8);
    uStack_18 = *(undefined2 *)(param_1 + 0xc);
    uStack_14 = *(undefined4 *)(param_1 + 0x14);
    iVar1 = zmsg_add_footer(param_1,0x18);
    if (iVar1 == 0) {
      nwk_intrp_data_request(auStack_2c);
    }
  }
  return;
}

