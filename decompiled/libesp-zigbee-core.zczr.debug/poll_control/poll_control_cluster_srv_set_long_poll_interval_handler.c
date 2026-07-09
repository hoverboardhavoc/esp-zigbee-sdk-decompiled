/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> poll_control.o -> poll_control_cluster_srv_set_long_poll_interval_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void poll_control_cluster_srv_set_long_poll_interval_handler(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  undefined4 uStack_18;
  ushort uStack_12;
  
  uStack_12 = 0;
  uStack_18 = 0;
  if (param_1 == 0) {
    uVar2 = 0xfe;
  }
  else if (param_2 == 0) {
    uVar2 = 0xfe;
  }
  else {
    uVar1 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
    uVar2 = af_read_le32(*(undefined4 *)(param_1 + 0x24),&uStack_12,&uStack_18);
    uVar2 = uVar2 & 0xff;
    if (uVar2 == 0) {
      if (uVar1 < uStack_12) {
        uVar2 = 0x80;
      }
      else {
        uVar2 = zcl_message_poll_control_notify(*(undefined1 *)(param_1 + 0x15),1,&uStack_18);
      }
    }
  }
  zcl_packet_setup_default_response(param_2,param_1,uVar2);
  return;
}

