/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_packet.o -> zdo_packet_response_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zdo_packet_response_init(undefined1 *param_1,undefined1 *param_2,undefined2 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 == (undefined1 *)0x0) {
    uVar2 = 0x80;
  }
  else if (param_2 == (undefined1 *)0x0) {
    uVar2 = 0x80;
  }
  else {
    *(undefined2 *)(param_1 + 6) = param_3;
    *(undefined2 *)(param_1 + 2) = *(undefined2 *)(param_2 + 4);
    *(undefined2 *)(param_1 + 4) = *(undefined2 *)(param_2 + 2);
    *param_1 = *param_2;
    param_1[8] = 0;
    *(undefined4 *)(param_1 + 0xc) = 0;
    *(undefined4 *)(param_1 + 0x10) = 0;
    iVar1 = zmsg_alloc(1);
    *(int *)(param_1 + 0x14) = iVar1;
    if (iVar1 == 0) {
      uVar2 = 0x8a;
    }
    else {
      uVar2 = 0;
    }
  }
  return uVar2;
}

