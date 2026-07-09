/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> basic.o -> basic_cluster_reset_to_factory_default_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 basic_cluster_reset_to_factory_default_cmd_handler(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0xfe;
  }
  else if (param_2 == 0) {
    uVar1 = 0xfe;
  }
  else {
    uVar1 = zcl_message_basic_reset_to_factory_default();
    uVar1 = zcl_packet_setup_default_response(param_2,param_1,uVar1);
  }
  return uVar1;
}

