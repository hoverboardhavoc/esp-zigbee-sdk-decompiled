/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> price.o -> price_cluster_price_ack_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void price_cluster_price_ack_cmd_handler(int param_1,int param_2)

{
  uint uVar1;
  ushort uStack_32;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  int iStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  uint uStack_14;
  
  uStack_30 = 0;
  uStack_2c = 0;
  iStack_28 = 0;
  uStack_24 = 0;
  uStack_20 = 0;
  uStack_1c = 0;
  uStack_18 = 0;
  uStack_14 = 0;
  uStack_32 = 0;
  if ((param_1 == 0) || (param_2 == 0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/price.c",0xb6,
                  "price_cluster_price_ack_cmd_handler","packet && rsp");
  }
  else {
    af_read_le32(*(undefined4 *)(param_1 + 0x24),&uStack_32,&uStack_24);
    af_read_le32(*(undefined4 *)(param_1 + 0x24),&uStack_32,&uStack_20);
    af_read_le32(*(undefined4 *)(param_1 + 0x24),&uStack_32,&uStack_1c);
    af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_32,&uStack_18);
    uVar1 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
    if (uVar1 < uStack_32) {
      uVar1 = 0x80;
      goto _L0;
    }
  }
  uVar1 = zcl_packet_to_message(&uStack_30,param_1);
  if (uVar1 == 0) {
    uStack_14 = CONCAT31(uStack_14._1_3_,0xfe);
    iStack_28 = param_1;
    zcl_core_action_schedule(0x4e,&uStack_30);
    if ((uStack_14 & 0xff) != 0xfe) {
      uVar1 = uStack_14 & 0xff;
    }
  }
_L0:
  zcl_packet_setup_default_response(param_2,param_1,uVar1);
  return;
}

