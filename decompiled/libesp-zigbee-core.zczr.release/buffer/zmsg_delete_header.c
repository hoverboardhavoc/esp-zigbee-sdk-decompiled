/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> buffer.o -> zmsg_delete_header
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void zmsg_delete_header(zmsg_t *msg,uint16_t offset,uint16_t length)

{
  short sVar1;
  zmsg_t *extraout_a0;
  uint extraout_a1;
  uint uVar2;
  undefined2 in_register_00002032;
  uint16_t uVar3;
  ushort uVar4;
  uint uVar5;
  
  uVar2 = CONCAT22(in_register_00002032,length);
  zmsg_write_bytes_from_msg(msg,length,msg,0,offset);
  uVar4 = msg->length;
  uVar5 = (uint)uVar4;
  if (uVar5 < uVar2) {
    zmsg_remove_header(msg,length);
    uVar4 = (ushort)uVar5;
    msg = extraout_a0;
    uVar2 = extraout_a1;
  }
  sVar1 = (short)uVar2;
  msg->length = uVar4 - sVar1;
  msg->header = msg->header + sVar1;
  uVar3 = 0;
  if (uVar2 < msg->offset) {
    uVar3 = msg->offset - sVar1;
  }
  msg->offset = uVar3;
  return;
}

