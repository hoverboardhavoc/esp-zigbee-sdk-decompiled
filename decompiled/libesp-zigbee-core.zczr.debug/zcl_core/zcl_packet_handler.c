/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_core.o -> zcl_packet_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_packet_handler(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    uVar2 = 0x87;
  }
  else {
    iVar1 = zcl_packet_is_general();
    if (iVar1 == 0) {
      iVar1 = zcl_packet_is_manuf_spec(param_1);
      if (iVar1 == 0) {
        uVar2 = zcl_cluster_cmd_handler(param_1);
      }
      else {
        uVar2 = zcl_message_notify_manuf_spec_cmd(param_1);
      }
    }
    else {
      uVar2 = zcl_general_cmd_handler(param_1);
    }
  }
  return uVar2;
}

