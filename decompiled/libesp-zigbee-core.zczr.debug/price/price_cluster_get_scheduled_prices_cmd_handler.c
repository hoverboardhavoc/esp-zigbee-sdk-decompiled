/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> price.o -> price_cluster_get_scheduled_prices_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Type propagation algorithm not settling */

uint price_cluster_get_scheduled_prices_cmd_handler(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  ushort uStack_2a;
  undefined4 uStack_28;
  undefined4 uStack_24;
  int iStack_20;
  int aiStack_1c [2];
  uint uStack_14;
  
  uStack_28 = 0;
  uStack_24 = 0;
  iStack_20 = 0;
  aiStack_1c[0] = 0;
  aiStack_1c[1] = 0;
  uStack_14 = 0;
  uStack_2a = 0;
  if ((param_1 == 0) || (param_2 == 0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/price.c",0x6e,
                  "price_cluster_get_scheduled_prices_cmd_handler","packet && rsp");
_L0:
    iVar2 = zcl_time_get_utc_time(*(undefined1 *)(param_1 + 0x15));
    if (iVar2 != -1) {
      aiStack_1c[0] = iVar2;
    }
  }
  else {
    af_read_le32(*(undefined4 *)(param_1 + 0x24),&uStack_2a,aiStack_1c);
    af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_2a,aiStack_1c + 1);
    uVar1 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
    if (uVar1 < uStack_2a) {
      uVar1 = 0x80;
      goto _L0;
    }
    if (aiStack_1c[0] == 0) goto _L0;
  }
  uVar1 = zcl_packet_to_message(&uStack_28,param_1);
  if (uVar1 == 0) {
    uStack_14 = CONCAT31(uStack_14._1_3_,0xfe);
    iStack_20 = param_1;
    zcl_core_action_schedule(0x4c,&uStack_28);
    uVar1 = uStack_14 & 0xff;
    if (uVar1 == 0xfe) {
      uVar1 = 0x8b;
    }
    else if (uVar1 == 0) {
      return 0;
    }
  }
_L0:
  uVar1 = zcl_packet_setup_default_response(param_2,param_1,uVar1);
  return uVar1;
}

