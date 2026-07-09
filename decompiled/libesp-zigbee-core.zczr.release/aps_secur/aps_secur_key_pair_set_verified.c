/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aps_secur.o -> aps_secur_key_pair_set_verified
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_secur_key_pair_set_verified(undefined4 *param_1,ushort param_2)

{
  undefined4 *unaff_s0;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined1 auStack_38 [16];
  undefined1 auStack_28 [16];
  int iStack_18;
  undefined2 uStack_14;
  undefined2 uStack_12;
  
  if ((param_1 == (undefined4 *)0x0) ||
     (param_2 = *(ushort *)(param_1 + 0xd), unaff_s0 = param_1, (param_2 & 6) != 2)) {
    param_1 = (undefined4 *)__assert_func(0,0,0,0);
  }
  *(ushort *)(param_1 + 0xd) = param_2 & 0xfff9 | 4;
  param_1[3] = 0;
  *(undefined2 *)(param_1 + 4) = 0xffff;
  time_ticker_register_receiver(3);
  memset(&uStack_40,0,0x30);
  aps_secur_remove_stored_key_pair(unaff_s0);
  uStack_40 = *unaff_s0;
  uStack_3c = unaff_s0[1];
  secur_key_copy(auStack_38,(int)unaff_s0 + 0x12);
  secur_key_copy(auStack_28,(int)unaff_s0 + 0x22);
  uStack_14 = *(undefined2 *)((int)unaff_s0 + 0x32);
  iStack_18 = unaff_s0[2] + 0x400;
  uStack_12 = *(undefined2 *)(unaff_s0 + 0xd);
  ds_internal_add_entry(9,&uStack_40,0x30);
  return;
}

