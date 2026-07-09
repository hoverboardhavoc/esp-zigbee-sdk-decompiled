/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zcl_packet.o -> zcl_packet_send_default_response
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zcl_packet_send_default_response(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined1 auStack_38 [36];
  int iStack_14;
  
  iVar1 = 0x87;
  memset(auStack_38,0,0x28);
  if (param_1 != 0) {
    iVar1 = zcl_packet_init(auStack_38,*(ushort *)(param_1 + 0x1a) >> 2 & 1);
    if ((iVar1 == 0) &&
       (iVar1 = zcl_packet_setup_default_response(auStack_38,param_1,param_2), iVar1 == 0)) {
      zcl_packet_send(auStack_38,0);
    }
    else if (iStack_14 != 0) {
      zmsg_free();
    }
  }
  return iVar1;
}

