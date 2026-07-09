/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> identify.o -> identify_cluster_trigger_effect_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void identify_cluster_trigger_effect_cmd_handler(int param_1,int param_2)

{
  uint uVar1;
  undefined4 uVar2;
  ushort uStack_14;
  undefined1 local_12;
  undefined1 uStack_11;
  
  uStack_11 = 0;
  local_12 = 0;
  uStack_14 = 0;
  if (param_1 == 0) {
    uVar2 = 0xfe;
  }
  else if (param_2 == 0) {
    uVar2 = 0xfe;
  }
  else {
    af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_14,&uStack_11);
    af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_14,&local_12);
    uVar1 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
    if (uVar1 < uStack_14) {
      uVar2 = 0x80;
    }
    else {
      uVar2 = zcl_message_identify_trigger_effect(param_1,uStack_11,local_12);
    }
  }
  zcl_packet_setup_default_response(param_2,param_1,uVar2);
  return;
}

