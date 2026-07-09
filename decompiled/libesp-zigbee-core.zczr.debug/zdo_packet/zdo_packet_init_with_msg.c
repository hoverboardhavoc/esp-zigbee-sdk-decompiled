/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_packet.o -> zdo_packet_init_with_msg
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zdo_packet_init_with_msg(undefined1 *param_1,undefined2 *param_2)

{
  undefined4 uVar1;
  undefined1 auStack_11 [5];
  
  auStack_11[0] = 0;
  if (param_1 == (undefined1 *)0x0) {
    uVar1 = 0x80;
  }
  else if (param_2 == (undefined2 *)0x0) {
    uVar1 = 0x80;
  }
  else if (*(uint *)(param_2 + 2) < 0x10000) {
    zmsg_read_bytes(*(undefined4 *)(param_2 + 8),0,1,auStack_11);
    zmsg_remove_header(*(undefined4 *)(param_2 + 8),1);
    *param_1 = auStack_11[0];
    *(undefined2 *)(param_1 + 4) = *param_2;
    *(undefined2 *)(param_1 + 2) = param_2[1];
    *(undefined2 *)(param_1 + 6) = param_2[4];
    *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(param_2 + 8);
    uVar1 = 0;
  }
  else {
    uVar1 = 0x82;
  }
  return uVar1;
}

