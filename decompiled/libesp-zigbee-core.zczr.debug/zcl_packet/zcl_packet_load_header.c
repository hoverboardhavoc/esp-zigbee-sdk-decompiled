/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_packet.o -> zcl_packet_load_header
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_packet_load_header(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  ushort local_12 [3];
  
  local_12[0] = 0;
  af_read_le8(*(undefined4 *)(param_1 + 0x24),local_12,param_1 + 0x1a);
  if ((*(byte *)(param_1 + 0x1a) & 4) == 0) {
    *(undefined2 *)(param_1 + 0x1c) = 0;
  }
  else {
    af_read_le16(*(undefined4 *)(param_1 + 0x24),local_12,param_1 + 0x1c);
  }
  af_read_le8(*(undefined4 *)(param_1 + 0x24),local_12,param_1 + 0x1e);
  af_read_le8(*(undefined4 *)(param_1 + 0x24),local_12,param_1 + 0x20);
  uVar1 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
  if (uVar1 < local_12[0]) {
    uVar2 = 0x80;
  }
  else {
    zmsg_remove_header(*(undefined4 *)(param_1 + 0x24));
    uVar2 = 0;
  }
  return uVar2;
}

