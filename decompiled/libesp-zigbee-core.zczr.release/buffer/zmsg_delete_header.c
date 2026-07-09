/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> buffer.o -> zmsg_delete_header
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zmsg_delete_header(int param_1,undefined4 param_2,uint param_3)

{
  short sVar1;
  uint extraout_a1;
  short sVar2;
  ushort uVar3;
  uint uVar4;
  
  zmsg_write_bytes_from_msg(param_1,0,param_2);
  uVar3 = *(ushort *)(param_1 + 0xe);
  uVar4 = (uint)uVar3;
  if (uVar4 < param_3) {
    param_1 = zmsg_get_next_chunk_part_0();
    uVar3 = (ushort)uVar4;
    param_3 = extraout_a1;
  }
  sVar1 = (short)param_3;
  *(ushort *)(param_1 + 0xe) = uVar3 - sVar1;
  *(short *)(param_1 + 0xc) = *(short *)(param_1 + 0xc) + sVar1;
  sVar2 = 0;
  if (param_3 < *(ushort *)(param_1 + 0x12)) {
    sVar2 = *(ushort *)(param_1 + 0x12) - sVar1;
  }
  *(short *)(param_1 + 0x12) = sVar2;
  return;
}

