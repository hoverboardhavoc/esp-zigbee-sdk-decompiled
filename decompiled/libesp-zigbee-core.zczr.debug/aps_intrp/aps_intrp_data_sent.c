/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_intrp.o -> aps_intrp_data_sent
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_intrp_data_sent(int param_1,byte param_2)

{
  int iStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  uint uStack_38;
  undefined4 uStack_34;
  uint uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  uStack_28 = 0;
  uStack_24 = 0;
  uStack_20 = 0;
  uStack_1c = 0;
  uStack_18 = 0;
  uStack_14 = 0;
  iStack_44 = param_1;
  zmsg_get_footer(&uStack_28,0x18);
  zmsg_remove_footer(iStack_44,0x18);
  uStack_2c = 0;
  uStack_40 = uStack_24;
  uStack_3c = uStack_20;
  uStack_38 = uStack_1c & 0xffff;
  uStack_34 = CONCAT22(uStack_1c._2_2_,(short)uStack_18);
  uStack_30 = (uint)param_2;
  uStack_2c = aps_intrp_msg_transfer_ownership(&iStack_44);
  aps_intrp_data_confirm(&uStack_40);
  if (iStack_44 != 0) {
    zmsg_free();
  }
  return;
}

