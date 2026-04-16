/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_nlme.o -> nwk_build_leave
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_build_leave(zmsg_t *msg,ezb_shortaddr_t dst_addr,_Bool rejoin,_Bool remove_children)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined2 in_register_0000202e;
  undefined3 in_register_00002031;
  undefined3 in_register_00002035;
  byte abStack_21 [13];
  
  iVar2 = CONCAT31(in_register_00002031,rejoin);
  uVar3 = nwk_get_short_address();
  nwk_frame_write_hdr(msg,uVar3,CONCAT22(in_register_0000202e,dst_addr),1,1,0);
  iVar4 = core_globals_get();
  abStack_21[0] = *(byte *)(iVar4 + 0x9d9);
  *(byte *)(iVar4 + 0x9d9) = abStack_21[0] + 1;
  zmsg_write_bytes(msg,7,1,abStack_21);
  if (iVar2 != 0) {
    iVar2 = 0x20;
  }
  bVar1 = (byte)iVar2;
  if (CONCAT31(in_register_00002035,remove_children) != 0) {
    bVar1 = bVar1 | 0x80;
  }
  if (CONCAT22(in_register_0000202e,dst_addr) < 0xfff8) {
    bVar1 = bVar1 & 0x7f | 0x40;
  }
  abStack_21[0] = 4;
  zmsg_append_bytes(msg,1,abStack_21);
  abStack_21[0] = bVar1;
  zmsg_append_bytes(msg,1,abStack_21);
  return;
}

