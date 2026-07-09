/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> ota_upgrade_cli.o -> zcl_message_ota_upgrade_query_next_image
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint zcl_message_ota_upgrade_query_next_image(int param_1,undefined1 *param_2)

{
  uint uVar1;
  undefined1 auStack_38 [8];
  int iStack_30;
  undefined1 uStack_2c;
  undefined1 auStack_2b [8];
  undefined1 uStack_23;
  undefined2 uStack_22;
  undefined2 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  byte bStack_14;
  
  memset(auStack_38,0,0x28);
  uVar1 = zcl_packet_to_message(auStack_38,param_1);
  if (uVar1 == 0) {
    uStack_2c = *param_2;
    uStack_23 = *(undefined1 *)(param_1 + 0x14);
    uStack_22 = *(undefined2 *)(param_2 + 2);
    uStack_20 = *(undefined2 *)(param_2 + 4);
    uStack_1c = *(undefined4 *)(param_2 + 8);
    uStack_18 = *(undefined4 *)(param_2 + 0xc);
    iStack_30 = param_1;
    nwk_address_extended_by_short(*(undefined2 *)(param_1 + 2),auStack_2b);
    bStack_14 = 0xfe;
    zcl_core_action_schedule(0x3c,auStack_38);
    if (bStack_14 != 0xfe) {
      uVar1 = (uint)bStack_14;
    }
  }
  return uVar1;
}

