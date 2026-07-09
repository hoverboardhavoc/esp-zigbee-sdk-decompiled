/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> identify.o -> identify_cluster_identify_query_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 identify_cluster_identify_query_rsp_handler(int param_1,int param_2)

{
  uint uVar1;
  undefined4 uVar2;
  ushort uStack_14;
  undefined2 auStack_12 [3];
  
  auStack_12[0] = 0;
  uStack_14 = 0;
  if ((param_1 == 0) || (param_2 == 0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/identify.c",0x159,
                  "identify_cluster_identify_query_rsp_handler","packet && rsp");
  }
  else {
    af_read_le16(*(undefined4 *)(param_1 + 0x24),&uStack_14,auStack_12);
    uVar1 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
    if (uStack_14 <= uVar1) {
      uVar2 = zcl_message_identify_query_rsp(param_1,auStack_12[0]);
      uVar2 = zcl_packet_setup_default_response(param_2,param_1,uVar2);
      return uVar2;
    }
  }
  return 0x80;
}

