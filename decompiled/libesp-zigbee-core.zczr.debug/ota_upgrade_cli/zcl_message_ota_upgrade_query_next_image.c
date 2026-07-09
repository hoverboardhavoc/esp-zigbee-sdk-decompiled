/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> ota_upgrade_cli.o -> zcl_message_ota_upgrade_query_next_image
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint zcl_message_ota_upgrade_query_next_image(int param_1,undefined1 *param_2)

{
  uint uVar1;
  undefined4 uStack_38;
  undefined4 uStack_34;
  int iStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  uint uStack_14;
  
  uStack_38 = 0;
  uStack_34 = 0;
  iStack_30 = 0;
  uStack_2c = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  uStack_20 = 0;
  uStack_1c = 0;
  uStack_18 = 0;
  uStack_14 = 0;
  uVar1 = zcl_packet_to_message(&uStack_38,param_1);
  if (uVar1 == 0) {
    uStack_2c = CONCAT31(uStack_2c._1_3_,*param_2);
    uStack_24 = CONCAT22(*(undefined2 *)(param_2 + 2),
                         CONCAT11(*(undefined1 *)(param_1 + 0x14),(undefined1)uStack_24));
    uStack_20 = CONCAT22(uStack_20._2_2_,*(undefined2 *)(param_2 + 4));
    uStack_1c = *(undefined4 *)(param_2 + 8);
    uStack_18 = *(undefined4 *)(param_2 + 0xc);
    iStack_30 = param_1;
    nwk_address_extended_by_short(*(undefined2 *)(param_1 + 2),(int)&uStack_2c + 1);
    uStack_14 = CONCAT31(uStack_14._1_3_,0xfe);
    zcl_core_action_schedule(0x3c,&uStack_38);
    if ((uStack_14 & 0xff) != 0xfe) {
      uVar1 = uStack_14 & 0xff;
    }
  }
  return uVar1;
}

