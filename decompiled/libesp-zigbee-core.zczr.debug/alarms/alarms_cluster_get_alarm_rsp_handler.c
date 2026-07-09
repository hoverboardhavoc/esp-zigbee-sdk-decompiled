/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> alarms.o -> alarms_cluster_get_alarm_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void alarms_cluster_get_alarm_rsp_handler(int param_1,int param_2)

{
  uint uVar1;
  ushort uStack_2a;
  undefined4 uStack_28;
  undefined4 uStack_24;
  int iStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  uint uStack_14;
  
  uStack_28 = 0;
  uStack_24 = 0;
  iStack_20 = 0;
  uStack_1c = 0;
  uStack_18 = 0;
  uStack_14 = 0;
  uStack_2a = 0;
  if ((param_1 == 0) || (param_2 == 0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/alarms.c",0x1ff,
                  "alarms_cluster_get_alarm_rsp_handler","packet && rsp");
  }
  else {
    af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_2a,&uStack_1c);
    if ((char)uStack_1c != '\0') goto _L0;
  }
  af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_2a,(int)&uStack_1c + 1);
  af_read_le16(*(undefined4 *)(param_1 + 0x24),&uStack_2a,(int)&uStack_1c + 2);
  af_read_le32(*(undefined4 *)(param_1 + 0x24),&uStack_2a,&uStack_18);
_L0:
  uVar1 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
  if (uVar1 < uStack_2a) {
    uVar1 = 0x80;
  }
  else {
    uVar1 = zcl_packet_to_message(&uStack_28,param_1);
    if (uVar1 == 0) {
      uStack_14 = CONCAT31(uStack_14._1_3_,0xfe);
      iStack_20 = param_1;
      zcl_core_action_schedule(0x35,&uStack_28);
      if ((uStack_14 & 0xff) != 0xfe) {
        uVar1 = uStack_14 & 0xff;
      }
    }
  }
  zcl_packet_setup_default_response(param_2,param_1,uVar1);
  return;
}

