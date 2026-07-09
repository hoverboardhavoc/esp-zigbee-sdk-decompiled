/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> ias_zone.o -> ias_zone_status_change_notification_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void ias_zone_status_change_notification_cmd_handler(int param_1,int param_2)

{
  uint uVar1;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  int iStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  uint uStack_18;
  ushort uStack_12;
  
  uStack_12 = 0;
  uStack_2c = 0;
  uStack_28 = 0;
  iStack_24 = 0;
  uStack_20 = 0;
  uStack_1c = 0;
  uStack_18 = 0;
  if ((param_1 == 0) || (param_2 == 0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/ias_zone.c",0x127,
                  "ias_zone_status_change_notification_cmd_handler","packet && rsp");
  }
  else {
    af_read_le16(*(undefined4 *)(param_1 + 0x24),&uStack_12,&uStack_20);
    af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_12,(int)&uStack_20 + 2);
    af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_12,(int)&uStack_20 + 3);
    af_read_le16(*(undefined4 *)(param_1 + 0x24),&uStack_12,&uStack_1c);
    uVar1 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
    if (uVar1 < uStack_12) {
      uVar1 = 0x80;
      goto _L0;
    }
  }
  uVar1 = zcl_packet_to_message(&uStack_2c,param_1);
  if (uVar1 == 0) {
    uStack_18 = CONCAT31(uStack_18._1_3_,0xfe);
    iStack_24 = param_1;
    zcl_core_action_schedule(0x33,&uStack_2c);
    uVar1 = uStack_18 & 0xff;
    if (uVar1 == 0xfe) {
      uVar1 = 1;
    }
  }
_L0:
  zcl_packet_setup_default_response(param_2,param_1,uVar1);
  return;
}

